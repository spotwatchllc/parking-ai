# /*---------------------------------------------------------------------------------------------
#  * Copyright (c) 2022 STMicroelectronics.
#  * All rights reserved.
#  *
#  * This software is licensed under terms that can be found in the LICENSE file in
#  * the root directory of this software component.
#  * If no LICENSE file comes with this software, it is provided AS-IS.
#  *--------------------------------------------------------------------------------------------*/

import os
import sys
from pathlib import Path
from omegaconf import DictConfig
from tabulate import tabulate
import numpy as np
import tensorflow as tf
import onnxruntime
import warnings
warnings.filterwarnings("ignore")
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '3'

from preprocess import preprocess_input
from data_loader import _load_audio_sample
from evaluate import _aggregate_predictions
from onnx_evaluation import predict_onnx, model_is_quantized
from models_utils import ai_runner_interp

def predict(cfg: DictConfig = None) -> None:
    """
    Predicts a class for all the audio files that are inside a given directory.
    The model used for the predictions can be either a .h5 or .tflite file.

    Args:
        cfg (dict): A dictionary containing the entire configuration file.

    Returns:
        None
    
    Errors:
        The directory containing the files cannot be found.
        The directory does not contain any file.
        No audio files can be loaded.
    """
    
    model_path = cfg.general.model_path
    class_names = cfg.dataset.class_names
    test_files_dir = cfg.prediction.test_files_path
    
    # Preproc and feature extraction parameters
    patch_length = cfg.feature_extraction.patch_length
    n_mels = cfg.feature_extraction.n_mels
    target_rate = cfg.preprocessing.target_rate
    overlap = cfg.feature_extraction.overlap
    n_fft = cfg.feature_extraction.n_fft
    spec_hop_length = cfg.feature_extraction.hop_length
    min_length = cfg.preprocessing.min_length
    max_length = cfg.preprocessing.max_length
    top_db = cfg.preprocessing.top_db
    frame_length = cfg.preprocessing.frame_length
    hop_length = cfg.preprocessing.hop_length
    trim_last_second = cfg.preprocessing.trim_last_second
    include_last_patch = cfg.feature_extraction.include_last_patch
    win_length = cfg.feature_extraction.window_length
    window = cfg.feature_extraction.window
    center = cfg.feature_extraction.center
    pad_mode = cfg.feature_extraction.pad_mode
    power = cfg.feature_extraction.power
    fmin = cfg.feature_extraction.fmin
    fmax = cfg.feature_extraction.fmax
    power_to_db_ref = np.max
    norm = cfg.feature_extraction.norm
    if norm == "None":
        norm = None
    htk = cfg.feature_extraction.htk
    to_db = cfg.feature_extraction.to_db

    expand_last_dim = cfg.dataset.expand_last_dim
    multi_label = cfg.dataset.multi_label

    print("[INFO] : Making predictions using:")
    print("  model:", model_path)
    print("  files directory:", test_files_dir)
    # Sort classes alphabetically
    class_names = sorted(class_names)
    print("[INFO] : Class names sorted alphabetically. \n \
           If the model you are using has been trained using the model zoo, \n \
           there will be no issue. Otherwise, the predicted class' name might not correspond to the \n \
           predicted one-hot vector.")
    print(f"Class names : {class_names}")
    # Load the test images
    filenames = []
    X = []
    clip_labels = []
    for i, fn in enumerate(os.listdir(test_files_dir)):
        filepath = os.path.join(test_files_dir, fn)
        # Skip subdirectories if any
        if os.path.isdir(filepath): continue
        filenames.append(fn)
        # Load the audio sample and split into patches
        patches = _load_audio_sample(
            filepath=filepath,
            patch_length=patch_length,
            n_mels=n_mels,
            target_rate=target_rate,
            overlap=overlap,
            n_fft=n_fft,
            spec_hop_length=spec_hop_length,
            min_length=min_length,
            max_length=max_length,
            top_db=top_db,
            frame_length=frame_length,
            hop_length=hop_length,
            trim_last_second=trim_last_second,
            include_last_patch=include_last_patch,
            win_length=win_length,
            window=window,
            center=center,
            pad_mode=pad_mode,
            power=power,
            fmin=fmin,
            fmax=fmax,
            power_to_db_ref=power_to_db_ref,
            norm=norm,
            htk=htk,
            to_db=to_db)
    
        X.extend(patches)
        clip_labels.extend([i] * len(patches))
    
    if not filenames:
        raise ValueError("Unable to make predictions, could not find any audio file in the "
                         f"files directory.\nReceived directory path {test_files_dir}")
    # Concatenate X into a single array
    X = np.stack(X, axis=0)
    if expand_last_dim:
        X = np.expand_dims(X, axis=-1)
    # Convert clip labels into array this is critical
    clip_labels = np.array(clip_labels)


    results_table = []
    file_extension = Path(model_path).suffix
    model_name = os.path.basename(model_path)

    if cfg.evaluation and cfg.evaluation.target:
        target = cfg.evaluation.target
    else:
        target = "host"

    if target in ["stedgeai_host", "stedgeai_n6"]:
        if file_extension == ".h5" or (file_extension == ".onnx" and not model_is_quantized(model_path)):
            raise TypeError("Cannot run float models on targets stedgeai_host or stedgeai_n6")
        
        interpreter = ai_runner_interp(target=target,
                                       name_model=model_name)
    
        # Get ai runner input details and mangle it back into 
        # the tf input detail dict format to pass to preprocess_input
    
        ai_runner_input_details = interpreter.get_inputs()
        input_details = {}
        input_details["dtype"] = ai_runner_input_details[0].dtype
        input_details["quantization"] = [ai_runner_input_details[0].scale, ai_runner_input_details[0].zero_point]
        X = preprocess_input(X, input_details)

        preds, _ = interpreter.invoke(X)
        preds = preds[0]
        # Yes it HAS to be a tuple
        dims_to_squeeze = tuple(np.arange(1, preds.ndim - 1))

        preds = np.squeeze(preds, axis=dims_to_squeeze)

    elif file_extension == ".h5":
        # Load the .h5 model
        model = tf.keras.models.load_model(model_path)
        
        # Get results
        preds = model.predict(X)

    elif file_extension == ".tflite":
        # Load the Tflite model and allocate tensors
        interpreter_quant = tf.lite.Interpreter(model_path=model_path)
        input_details = interpreter_quant.get_input_details()[0]
        input_index_quant = input_details["index"]
        output_index_quant = interpreter_quant.get_output_details()[0]["index"]

        interpreter_quant.resize_tensor_input(input_index_quant, X.shape)
        interpreter_quant.allocate_tensors()

        patches_processed = preprocess_input(X, input_details)
        interpreter_quant.set_tensor(input_index_quant, patches_processed)
        interpreter_quant.invoke()
        preds = interpreter_quant.get_tensor(output_index_quant)
            
    elif file_extension == '.onnx':
        # We assume ONNX models need (BCHW) or (BCL) format input
        # But X is in (BHWC) or (BLC) format
        # Note : since we switched to channels-last by default for AED ONNX, this should not be necessary
        # anymore
        # if X.ndim == 4:
        #     axes_order = (0, 3, 1, 2)
        # elif X.ndim == 3:
        #     axes_order = (0, 2, 1)
        # else:
        #     raise ValueError(f"The input array must have either 3 or 4 dimensions but had {X.ndim} dimensions")
        # X = np.transpose(X, axes_order)
        
        sess = onnxruntime.InferenceSession(model_path)
        preds =  predict_onnx(sess, X)

    else:
        raise TypeError(f"Unknown or unsupported model type. Received path {model_path}")

    aggregated_probas = _aggregate_predictions(preds,
                                                clip_labels=clip_labels,
                                                multi_label=multi_label,
                                                is_truth=False,
                                                return_proba=True)
    aggregated_preds = _aggregate_predictions(preds,
                                                clip_labels=clip_labels,
                                                multi_label=multi_label,
                                                is_truth=False,
                                                return_proba=False)
    # Add result to the table
    for i in range(aggregated_preds.shape[0]):
        results_table.append([class_names[np.argmax(aggregated_preds[i])],
                                aggregated_preds[i],
                                aggregated_probas[i].round(decimals=2),
                                filenames[i]])


    # Display the results table
    print(tabulate(results_table, headers=["Prediction", "One-hot prediction", "Score", "Audio file"]))
