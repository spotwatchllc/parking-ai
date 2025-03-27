# /*---------------------------------------------------------------------------------------------
#  * Copyright (c) 2022 STMicroelectronics.
#  * All rights reserved.
#  *
#  * This software is licensed under terms that can be found in the LICENSE file in
#  * the root directory of this software component.
#  * If no LICENSE file comes with this software, it is provided AS-IS.
#  *--------------------------------------------------------------------------------------------*/

from typing import Iterable, Tuple, Optional
import os
import sys
import warnings
import mlflow
from hydra.core.hydra_config import HydraConfig
from omegaconf import DictConfig
import numpy as np
import tensorflow as tf
import tqdm
from pathlib import Path
import onnxruntime

warnings.filterwarnings("ignore")
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '3'

from preprocess import preprocess_image, preprocess_input, postprocess_output_values
from logs_utils import log_to_file
from utils import tf_segmentation_dataset_to_np_array
from onnx_evaluation import predict_onnx, model_is_quantized
from models_utils import count_h5_parameters, ai_runner_interp, ai_interp_input_quant, ai_interp_outputs_dequant
from models_mgt import ai_runner_invoke


def prediction_accuracy_on_batch(pred_mask: np.ndarray = None, true_mask: np.ndarray = None) -> float:
    """
        Evaluation of the prediction accuracy on a batch of network outputs.

        Parameters:
        pred_mask (np.array): batch of network outputs, containing on each pixel the detected class id
        true_mask (np.array): batch of corresponding ground truth

        Returns:
        accuracy_on_batch (float): estimated accuracy on batch.
    """
    accuracy_on_batch = np.mean((pred_mask == true_mask).astype(np.float32))

    return accuracy_on_batch


def iou_per_class(pred_mask: np.ndarray = None, true_mask: np.ndarray = None, num_classes: int = None) -> list:
    """
        Evaluation of IOU per class on a batch of network outputs.

        Parameters:
        pred_mask (np.array): batch of network outputs, containing on each pixel the detected class id
        true_mask (np.array): batch of corresponding ground truth
        num_classes (int): number of classes in the dataset

        Returns:
        ious_on_batch_class (list): estimated accuracy on batch.
    """

    ious_on_batch_class = []

    # Calculate IoU for each class
    for class_id in range(num_classes):
        true_class = true_mask == class_id
        pred_class = pred_mask == class_id
        intersection = np.logical_and(true_class, pred_class)
        union = np.logical_or(true_class, pred_class)
        union_sum = np.sum(union)

        iou_class = np.sum(intersection) / union_sum if union_sum > 0 else 0.
        # IoU makes only sense if there actually are occurrences of class_id in the image
        if np.sum(true_class) != 0:
            ious_on_batch_class.append(iou_class)

    return ious_on_batch_class


def evaluate_tflite_model(cfg: DictConfig = None, 
                          model_path: str = None, eval_ds: tf.data.Dataset = None, class_names: list = None,
                          output_dir: str = None, name_ds: Optional[str] = 'test_set',
                          num_threads: Optional[int] = 1) -> tuple:
    """
    Evaluates a tflite model saved in .tflite format on the provided test data.

    Args:
        cfg (config): The configuration file.
        model_path (str): The file path to the .tflite model.
        eval_ds (tf.data.Dataset): The data to evaluate the model on.
        class_names (list): A list of class names for output metrics evaluation
        output_dir (str): The directory where to save the image.
        name_ds (str): The name of the chosen eval_ds to be mentioned in the prints and figures.
        num_threads (int): number of threads for the tflite interpreter
    Returns:
        tuple: avg_accuracy, avg_iou on the evaluation dataset.
    """

    if cfg.evaluation and cfg.evaluation.target:
        target = cfg.evaluation.target
    else:
        target = "host"

    name_model = os.path.basename(model_path)

    # Load TFLite model and allocate tensors
    interpreter = tf.lite.Interpreter(model_path=model_path, num_threads=num_threads)
    interpreter.allocate_tensors()
    input_details = interpreter.get_input_details()[0]
    input_index = input_details["index"]
    output_details = interpreter.get_output_details()[0]
    output_index = output_details["index"]

    ai_runner_interpreter = ai_runner_interp(target,name_model)

    accuracy_list = []
    iou_global_window = []
    num_classes = len(class_names)
    images_full = []
    predictions_all = []
    for (images, mask) in tqdm.tqdm(eval_ds, total=len(eval_ds)):
        for img, msk in zip(images, mask):
            if target == "host":
                # Preprocess the image for applying quantization parameters
                img = preprocess_input(img, input_details=input_details)
                
                if "evaluation" in cfg and cfg.evaluation:
                    if "gen_npy_input" in cfg.evaluation and cfg.evaluation.gen_npy_input == True:
                        images_full.append(img)

                # Run inference
                interpreter.set_tensor(input_index, img)
                interpreter.invoke()
                out = interpreter.get_tensor(output_index)[0]
                out = postprocess_output_values(output=out, output_details=output_details)
            elif target == 'stedgeai_host' or target == 'stedgeai_n6':
                data = ai_interp_input_quant(ai_runner_interpreter,img.numpy()[None],
                                             cfg.preprocessing.rescaling.scale,
                                             cfg.preprocessing.rescaling.offset,
                                             '.tflite')
                out  = ai_runner_invoke(data, ai_runner_interpreter)
                out  = ai_interp_outputs_dequant(ai_runner_interpreter, out)[0][0]

            if "evaluation" in cfg and cfg.evaluation:
                if "gen_npy_output" in cfg.evaluation and cfg.evaluation.gen_npy_output == True:
                    predictions_all.append(out)

            pred_mask = np.argmax(out, axis=-1)
            true_mask = tf.squeeze(msk, axis=-1).numpy()
            accuracy = prediction_accuracy_on_batch(pred_mask, true_mask)
            accuracy_list.append(accuracy)

            ious_per_image = iou_per_class(pred_mask, true_mask, num_classes)
            if ious_per_image:
                for iou in ious_per_image:
                    iou_global_window.append(iou)

    # Saves evaluation dataset in a .npy
    if "evaluation" in cfg and cfg.evaluation:
        if "gen_npy_input" in cfg.evaluation and cfg.evaluation.gen_npy_input == True:
            if "npy_in_name" in cfg.evaluation and cfg.evaluation.npy_in_name:
                npy_in_name = cfg.evaluation.npy_in_name
            else:
                npy_in_name = "unknown_npy_in_name"
            images_full = np.concatenate(images_full, axis=0)
            print("[INFO] : Shape of npy input dataset = {}".format(images_full.shape))
            np.save(os.path.join(output_dir, f"{npy_in_name}.npy"), images_full)

    # Saves model output in a .npy
    if "evaluation" in cfg and cfg.evaluation:
        if "gen_npy_output" in cfg.evaluation and cfg.evaluation.gen_npy_output == True:
            if "npy_out_name" in cfg.evaluation and cfg.evaluation.npy_out_name:
                npy_out_name = cfg.evaluation.npy_out_name
            else:
                npy_out_name = "unknown_npy_out_name"
            predictions_all = np.concatenate(predictions_all, axis=0)
            np.save(os.path.join(output_dir, f"{npy_out_name}.npy"), predictions_all)

    avg_accuracy = np.mean(accuracy_list)
    avg_iou = np.mean(iou_global_window) if iou_global_window else 0  # Handle case with no IoU scores

    print(f"[INFO] : Quantized model accuracy on {name_ds} = {round(avg_accuracy * 100, 2)}%")
    print(f"[INFO] : Quantized model average IoU on all classes on {name_ds} = {round(avg_iou * 100, 2)}%")
    mlflow.log_metric(f"quantized_acc_{name_ds}", round(avg_accuracy * 100, 2))
    mlflow.log_metric(f"quantized_avg_iou_{name_ds}", round(avg_iou * 100, 2))
    log_to_file(output_dir, f"Tflite quantized model {name_ds}:")
    log_to_file(output_dir, f"Quantized model accuracy : {round(avg_accuracy * 100, 2)}%")
    log_to_file(output_dir, f"Quantized model average IoU on all classes : {round(avg_iou * 100, 2)}% ")

    return avg_accuracy, avg_iou


def evaluate_h5_model(model_path: str = None, eval_ds: tf.data.Dataset = None, class_names: list = None,
                      output_dir: str = None, name_ds: Optional[str] = 'test_set') -> tuple:
    """
    Evaluates a trained Keras model saved in .h5 format on the provided test data.

    Args:
        model_path (str): The file path to the .h5 model.
        eval_ds (tf.data.Dataset): The data to evaluate the model on.
        class_names (list): A list of class names for the confusion matrix.
        output_dir (str): The directory where to save the image.
        name_ds (str): The name of the chosen eval_ds to be mentioned in the prints and figures.
    Returns:
        tuple: avg_accuracy, avg_iou on the evaluation dataset
    """
    accuracy_batch = []
    iou_global_window = []
    num_classes = len(class_names)
    # Load the .h5 model
    model = tf.keras.models.load_model(model_path, compile=False)

    for (image, mask) in tqdm.tqdm(eval_ds, total=len(eval_ds)):
        # Run inference, image/mask are already preprocessed in tf.dataset
        out = model.predict(image)

        pred_mask = np.argmax(out, axis=-1)
        if mask.shape[-1] == 1:
            true_mask = tf.squeeze(mask, axis=-1).numpy()
        else:
            # If the last dimension is not 1, do not squeeze or handle accordingly
            true_mask = mask.numpy()
        accuracy_on_batch = prediction_accuracy_on_batch(pred_mask, true_mask)
        accuracy_batch.append(accuracy_on_batch)

        # Calculate IoU for each class and per image
        for p_msk, t_msk in zip(pred_mask, true_mask):
            ious_per_image = iou_per_class(p_msk, t_msk, num_classes)
            # Calculate mean IoU for this sample all class for which we have an IoU included
            if ious_per_image:
                for iou in ious_per_image:
                    iou_global_window.append(iou)

    avg_accuracy = np.mean(accuracy_batch)
    avg_iou = np.mean(iou_global_window) if iou_global_window else 0  # Handle case with no IoU scores

    print(f"[INFO] : Accuracy of float model on {name_ds} = {round(avg_accuracy*100, 2)}%")
    print(f"[INFO] : Average IoU of float model (all classes) on {name_ds} = {round(avg_iou*100, 2)}%")
    mlflow.log_metric(f"float_acc_{name_ds}", round(avg_accuracy*100, 2))
    mlflow.log_metric(f"float_avg_iou_{name_ds}", round(avg_iou*100, 2))
    log_to_file(output_dir, f"TF/Keras Float model {name_ds}:")
    log_to_file(output_dir, f"Accuracy of float model : {round(avg_accuracy*100, 2)}%")
    log_to_file(output_dir, f"Average IoU of float model (all classes) : {round(avg_iou*100, 2)}% ")

    return avg_accuracy, avg_iou


def evaluate_onnx_model(cfg: DictConfig = None, model_path: str = None, eval_ds: tf.data.Dataset = None,
                        class_names: list = None, output_dir: str = None, name_ds: Optional[str] = 'test_set') -> float:
    """
    Evaluates a trained model saved in .onnx format on the provided test data.
    We consider channel first models only.

    Args:
        cfg (DictConfig): dictionary containing yaml parameters
        model_path (str): The file path to the .h5 model.
        eval_ds (tf.data.Dataset): The data to evaluate the model on.
        class_names (list): A list of class names for the confusion matrix.
        output_dir (str): The directory where to save the image.
        name_ds (str): The name of the chosen eval_ds to be mentioned in the prints and figures.
    Returns:
        tuple: avg_accuracy, avg_iou on the evaluation dataset
    """
    accuracy_list = []
    iou_global_window = []
    num_classes = len(class_names)

    if cfg.evaluation and cfg.evaluation.target:
        target = cfg.evaluation.target
    else:
        target = "host"
    
    name_model = os.path.basename(model_path)

    images, masks = tf_segmentation_dataset_to_np_array(eval_ds, nchw=True)
    sess = onnxruntime.InferenceSession(model_path)

    ai_runner_interpreter = ai_runner_interp(target, name_model)

    for img, msk in zip(images, masks):
        img = np.expand_dims(img, axis=0)
        if target == "host":
            out = predict_onnx(sess, img)
        elif target == 'stedgeai_host' or target == 'stedgeai_n6':
            data = ai_interp_input_quant(ai_runner_interpreter, img, cfg.preprocessing.rescaling.scale,
                                         cfg.preprocessing.rescaling.offset, '.onnx')
            out  = ai_runner_invoke(data, ai_runner_interpreter)
            out  = ai_interp_outputs_dequant(ai_runner_interpreter, out)[0]
            out  = np.transpose(out, [0, 3, 1, 2])
        pred_mask = np.argmax(out, axis=1)
        true_mask = msk
        accuracy = prediction_accuracy_on_batch(pred_mask, true_mask)
        accuracy_list.append(accuracy)

        ious_per_image = iou_per_class(pred_mask, true_mask, num_classes)
        if ious_per_image:
            for iou in ious_per_image:
                iou_global_window.append(iou)

    avg_accuracy = np.mean(accuracy_list)
    avg_iou = np.mean(iou_global_window) if iou_global_window else 0  # Handle case with no IoU scores

    model_type = 'Quantized' if model_is_quantized(model_path) else 'Float'
    print(f"[INFO] : {model_type} model accuracy on {name_ds} = {round(avg_accuracy*100, 2)}%")
    print(f"[INFO] : {model_type} model average IoU (all classes) on {name_ds} = {round(avg_iou*100, 2)}%")
    mlflow.log_metric(f"{model_type.lower()}_acc_{name_ds}", round(avg_accuracy*100, 2))
    mlflow.log_metric(f"{model_type.lower()}_avg_iou_{name_ds}", round(avg_iou*100, 2))
    log_to_file(output_dir, f"ONNX {model_type} model {name_ds}:")
    log_to_file(output_dir, f"{model_type} model accuracy : {round(avg_accuracy*100, 2)}%")
    log_to_file(output_dir, f"{model_type} model average IoU (all classes) : {round(avg_iou*100, 2)}% ")

    return avg_accuracy, avg_iou


def evaluate(cfg: DictConfig = None, eval_ds: tf.data.Dataset = None,
             model_path_to_evaluate: Optional[str] = None, name_ds: Optional[str] = 'test_set'):
    """
        Main function for evalution. Detects whether the model is saved in h5, .tflite or .onnx format and evaluates on
        a dataset of inputs.

        Args:
            cfg (dict): dictionary of input parameters
            eval_ds (tf.data.Dataset): The data to evaluate the model on.
            model_path_to_evaluate (str): The file path to the .h5 model.
            name_ds (str): The name of the chosen eval_ds to be mentioned in the prints and figures.
        Returns:

        """

    output_dir = HydraConfig.get().runtime.output_dir
    class_names = cfg.dataset.class_names
    model_path = model_path_to_evaluate if model_path_to_evaluate else cfg.general.model_path

    try:
        # Check if the model is a TensorFlow Lite model
        file_extension = Path(model_path).suffix
        if file_extension == '.h5':
            count_h5_parameters(output_dir=output_dir, model_path=model_path)
            # Evaluate Keras model
            evaluate_h5_model(model_path=model_path, eval_ds=eval_ds, class_names=class_names, output_dir=output_dir,
                              name_ds=name_ds)
        elif file_extension == '.tflite':
            # Evaluate TensorFlow Lite model
            evaluate_tflite_model(cfg=cfg, model_path=model_path, eval_ds=eval_ds, class_names=class_names,
                                  output_dir=output_dir, name_ds=name_ds, num_threads=cfg.general.num_threads_tflite)
        elif file_extension == '.onnx':
            # Evaluate onnx model
            evaluate_onnx_model(cfg=cfg, model_path=model_path, eval_ds=eval_ds, class_names=class_names,
                                output_dir=output_dir, name_ds=name_ds)
    except Exception:
        raise ValueError(f"Model accuracy evaluation failed\nReceived model path: {model_path}")
