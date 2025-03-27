# /*---------------------------------------------------------------------------------------------
#  * Copyright (c) 2024 STMicroelectronics.
#  * All rights reserved.
#  *
#  * This software is licensed under terms that can be found in the LICENSE file in
#  * the root directory of this software component.
#  * If no LICENSE file comes with this software, it is provided AS-IS.
#  *--------------------------------------------------------------------------------------------*/

import sys
import os
import tqdm
import mlflow
import numpy as np
from pathlib import Path
import tensorflow as tf
import tensorflow.keras.backend as K
import onnx
import onnxruntime
from hydra.core.hydra_config import HydraConfig
from omegaconf import DictConfig
from typing import Optional

from postprocess import spe_postprocess, heatmaps_spe_postprocess, yolo_mpe_postprocess
from preprocess import apply_rescaling
from metrics import single_pose_oks, multi_pose_oks_mAP, compute_ap
from models_utils import count_h5_parameters, ai_runner_interp, ai_interp_input_quant, ai_interp_outputs_dequant
from models_mgt   import ai_runner_invoke
from logs_utils import log_to_file


def evaluate(cfg: DictConfig = None, eval_ds: tf.data.Dataset = None,
             model_path_to_evaluate: Optional[str] = None,
             name_ds: Optional[str] = 'test_set') -> None:
    """
    Evaluates and benchmarks a TensorFlow Lite or Keras model, and generates a Config header file if specified.

    Args:
        cfg (config): The configuration file.
        eval_ds (tf.data.Dataset): The validation dataset.
        model_path_to_evaluate (str, optional): Model path to evaluate
        name_ds (str): The name of the chosen test_data to be mentioned in the prints and figures.

    Returns:
        None
    """
    output_dir  = HydraConfig.get().runtime.output_dir
    model_path  = model_path_to_evaluate if model_path_to_evaluate else cfg.general.model_path
    name_model  = os.path.basename(model_path)
    model_type  = cfg.general.model_type
    num_threads = cfg.general.num_threads_tflite
    if cfg.evaluation and cfg.evaluation.target:
        target = cfg.evaluation.target
    else:
        target = "host"
    file_extension = Path(model_path).suffix

    # Pre-process test dataset
    eval_ds = apply_rescaling(dataset=eval_ds, scale=cfg.preprocessing.rescaling.scale,
                              offset=cfg.preprocessing.rescaling.offset)
    
    try:
        # Keras model
        if file_extension == '.h5':
            count_h5_parameters(output_dir=output_dir,
                                model_path=model_path)
            model = tf.keras.models.load_model(model_path)
        # TFlite model
        elif file_extension == '.tflite':
            interpreter_quant = tf.lite.Interpreter(model_path=model_path,num_threads=num_threads)
            interpreter_quant.allocate_tensors()
            input_details   = interpreter_quant.get_input_details()
            outputs_details = interpreter_quant.get_output_details()
            shape_to_resize = list(eval_ds.take(1).as_numpy_iterator())[0][0].shape
            interpreter_quant.resize_tensor_input(input_details[0]['index'], shape_to_resize)
            interpreter_quant.allocate_tensors()
        elif file_extension == '.onnx':
            sess = onnxruntime.InferenceSession(model_path)
            inputs  = sess.get_inputs()
            outputs = sess.get_outputs()
    except Exception:
        raise ValueError(f"Model accuracy evaluation failed\nReceived model path: {model_path}")

    ai_runner_interpreter = ai_runner_interp(target,name_model)

    metric = 0
    nb_batches = len(eval_ds)
    tp, conf, nb_gt, maskpad = None, None, None, None
    predictions_all = []
    images_full = []
    for images,labels in tqdm.tqdm(eval_ds, total=nb_batches):
        if Path(model_path).suffix == '.h5':
            predictions = model.predict_on_batch(images)
        elif Path(model_path).suffix == '.tflite':

            image_processed = images.numpy()

            if input_details[0]['dtype'] == np.uint8:
                image_processed = (image_processed - cfg.preprocessing.rescaling.offset) / cfg.preprocessing.rescaling.scale
                image_processed = np.clip(np.round(image_processed), np.iinfo(input_details[0]['dtype']).min, np.iinfo(input_details[0]['dtype']).max)
            elif input_details[0]['dtype'] == np.int8:
                image_processed = (image_processed - cfg.preprocessing.rescaling.offset) / cfg.preprocessing.rescaling.scale
                image_processed -= 128
                image_processed = np.clip(np.round(image_processed), np.iinfo(input_details[0]['dtype']).min, np.iinfo(input_details[0]['dtype']).max)
            elif input_details[0]['dtype'] == np.float32:
                image_processed = image_processed
            else:
                print('[ERROR] : input dtype not recognized -> ',input_details[0]['dtype'])

            imags = image_processed.astype(input_details[0]['dtype'])

            if "evaluation" in cfg and cfg.evaluation:
                if "gen_npy_input" in cfg.evaluation and cfg.evaluation.gen_npy_input==True: 
                    images_full.append(imags)
            if target == 'host':
                interpreter_quant.set_tensor(input_details[0]['index'], imags)
                interpreter_quant.invoke()
                predictions = [interpreter_quant.get_tensor(outputs_details[j]["index"]) for j in range(len(outputs_details))][0]
            elif target == 'stedgeai_host' or target == 'stedgeai_n6':
                data        = ai_interp_input_quant(ai_runner_interpreter,images.numpy(),cfg.preprocessing.rescaling.scale, cfg.preprocessing.rescaling.offset,'.tflite')
                predictions = ai_runner_invoke(data,ai_runner_interpreter)
                predictions = ai_interp_outputs_dequant(ai_runner_interpreter,predictions)[0]
            if "evaluation" in cfg and cfg.evaluation:
                if "gen_npy_output" in cfg.evaluation and cfg.evaluation.gen_npy_output==True: 
                        predictions_all.append(predictions)

        elif Path(model_path).suffix == '.onnx':
            t_images = tf.transpose(images,[0,3,1,2]).numpy()
            if target == 'host':
                predictions = sess.run([o.name for o in outputs], {inputs[0].name: t_images.astype('float32')})[0]
            elif target == 'stedgeai_host' or target == 'stedgeai_n6':
                data        = ai_interp_input_quant(ai_runner_interpreter,t_images,cfg.preprocessing.rescaling.scale, cfg.preprocessing.rescaling.offset,'.onnx')
                predictions = ai_runner_invoke(data,ai_runner_interpreter)
                predictions = ai_interp_outputs_dequant(ai_runner_interpreter,predictions)[0]

        predictions = tf.cast(predictions,tf.float32)

        if model_type=='heatmaps_spe':
            poses = heatmaps_spe_postprocess(predictions)
            oks   = single_pose_oks(labels,poses)
            metric += tf.reduce_mean(oks)
        elif model_type=='spe':
            poses = spe_postprocess(predictions)
            oks   = single_pose_oks(labels,poses)
            metric += tf.reduce_mean(oks)
        elif model_type=='yolo_mpe':
            poses = yolo_mpe_postprocess(predictions,
                                         max_output_size=cfg.postprocessing.max_detection_boxes,
                                         iou_threshold=cfg.postprocessing.NMS_thresh,
                                         score_threshold=cfg.postprocessing.confidence_thresh)
            if Path(model_path).suffix == '.onnx':
                mask_s = tf.constant([images.shape[2]]*4 + [1.] + [images.shape[2],images.shape[2],1.]*17)
                poses /= mask_s[None,None]

            oks   = multi_pose_oks_mAP(labels,poses) # (batch*M,thresh), (batch*M,), (1,), (batch*M,)

            tdet_ind = tf.where(oks[1]>0)[:,0]    # (true_detections,)
            #print(tdet_ind)
            ttp      = tf.gather(oks[0],tdet_ind) # (true_detections,thresh)
            tconf    = tf.gather(oks[1],tdet_ind) # (true_detections,)
            tnb_gt   = oks[2]                     # (1,)
            tmaskpad = tf.gather(oks[3],tdet_ind) # (true_detections,)

            if tp==None:
                tp      = ttp
                conf    = tconf
                nb_gt   = tnb_gt
                maskpad = tmaskpad

            else:
                tp      = tf.concat([tp,ttp],0)
                conf    = tf.concat([conf,tconf],0)
                nb_gt  += tnb_gt
                maskpad = tf.concat([maskpad,tmaskpad],0)
        else:
            print('No post-processing found for the model type : '+model_type)

    # Saves evaluation dataset in a .npy
    if "evaluation" in cfg and cfg.evaluation:
        if "gen_npy_input" in cfg.evaluation and cfg.evaluation.gen_npy_input==True: 
            if "npy_in_name" in cfg.evaluation and cfg.evaluation.npy_in_name:
                npy_in_name = cfg.evaluation.npy_in_name
            else:
                npy_in_name = "unknown_npy_in_name"
            images_full = np.concatenate(images_full, axis=0)
            print("[INFO] : Shape of npy input dataset = {}".format(images_full.shape))
            np.save(os.path.join(output_dir, f"{npy_in_name}.npy"), images_full)

    # Saves model output in a .npy
    if "evaluation" in cfg and cfg.evaluation:
        if "gen_npy_output" in cfg.evaluation and cfg.evaluation.gen_npy_output==True: 
            if "npy_out_name" in cfg.evaluation and cfg.evaluation.npy_out_name:
                npy_out_name = cfg.evaluation.npy_out_name
            else:
                npy_out_name = "unknown_npy_out_name"
            predictions_all = np.concatenate(predictions_all, axis=0)
            np.save(os.path.join(output_dir, f"{npy_out_name}.npy"), predictions_all)

    if model_type in ['heatmaps_spe','spe']:
        metric /= nb_batches
        print("The mean OKS is : {:.2f}%".format(metric.numpy()*100))
        # logging the OKS in the stm32ai_main.log file
        if file_extension == '.h5':
            mlflow.log_metric("float_OKS", metric.numpy()*100)
            log_to_file(output_dir, "float_model_OKS : {:.2f}%".format(metric.numpy()*100)) 
        elif file_extension == '.tflite':
          mlflow.log_metric("quantized_OKS", metric.numpy()*100)
          log_to_file(output_dir, "quantized_model_OKS : {:.2f}%".format(metric.numpy()*100))
        else:
          mlflow.log_metric("OKS", metric.numpy()*100)
          log_to_file(output_dir, "model_OKS : {:.2f}%".format(metric.numpy()*100))
    elif model_type=='yolo_mpe':
        metric = compute_ap(tp, conf, nb_gt, maskpad, cfg.postprocessing.plot_metrics)
        print('mAP@0.5        -> {:.2f}%'.format(metric[0]*100))
        print('mAP@[0.5:0.95] -> {:.2f}%'.format(np.mean(metric)*100))
        # logging the mAP@0.5 and mAP@[0.5:0.95] in the stm32ai_main.log file
        if file_extension == '.h5':
            mlflow.log_metric("float_mAP_0.5", metric[0]*100)
            mlflow.log_metric("float_mAP_0.5_0.95", np.mean(metric)*100)
            log_to_file(output_dir, "float_model_mAP@0.5        -> {:.2f}%".format(metric[0]*100))
            log_to_file(output_dir, "float_model_mAP@[0.5:0.95] -> {:.2f}%".format(np.mean(metric)*100))
        elif file_extension == '.tflite':
            mlflow.log_metric("quantized_mAP_0.5", metric[0]*100)
            mlflow.log_metric("quantized_mAP_0.5_0.95", np.mean(metric)*100)
            log_to_file(output_dir, "quantized_model_mAP@0.5        -> {:.2f}%".format(metric[0]*100))
            log_to_file(output_dir, "quantized_model_mAP@[0.5:0.95] -> {:.2f}%".format(np.mean(metric)*100))
        else:
            mlflow.log_metric("mAP_0.5", metric[0]*100)
            mlflow.log_metric("mAP_0.5_0.95", np.mean(metric)*100)
            log_to_file(output_dir, "model_mAP@0.5        -> {:.2f}%".format(metric[0]*100))
            log_to_file(output_dir, "model_mAP@[0.5:0.95] -> {:.2f}%".format(np.mean(metric)*100))
    else:
        print('No metric found for the model type : '+model_type)

