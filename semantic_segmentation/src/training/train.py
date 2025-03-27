# /*---------------------------------------------------------------------------------------------
#  * Copyright (c) 2022-2023 STMicroelectronics.
#  * All rights reserved.
#  *
#  * This software is licensed under terms that can be found in the LICENSE file in
#  * the root directory of this software component.
#  * If no LICENSE file comes with this software, it is provided AS-IS.
#  *--------------------------------------------------------------------------------------------*/

import os
from datetime import timedelta
from pathlib import Path
from timeit import default_timer as timer
from hydra.core.hydra_config import HydraConfig
from munch import DefaultMunch
from omegaconf import DictConfig
from typing import Dict, List, Optional, Tuple
import tensorflow as tf

# Suppress Tensorflow warnings
import logging
logging.getLogger('mlflow.tensorflow').setLevel(logging.ERROR)
logging.getLogger('tensorflow').setLevel(logging.ERROR)

from models_mgt import load_model_for_training
from models_utils import model_summary
from train_model import SegmentationTrainingModel
from common_training import set_frozen_layers, get_optimizer
from cfg_utils import collect_callback_args
from logs_utils import LRTensorBoard, log_to_file, log_last_epoch_history
import lr_schedulers 
from evaluate import evaluate_h5_model


def get_callbacks(callbacks_dict: DictConfig, output_dir: str = None, logs_dir: str = None,
                  saved_models_dir: str = None) -> List[tf.keras.callbacks.Callback]:
    """
    This function creates the list of Keras callbacks to be passed to 
    the fit() function including:
      - the Model Zoo built-in callbacks that can't be redefined by the
        user (ModelCheckpoint, TensorBoard, CSVLogger).
      - the callbacks specified in the config file that can be either Keras
        callbacks or custom callbacks (learning rate schedulers).

    For each callback, the attributes and their values used in the config
    file are used to create a string that is the callback instantiation as
    it would be written in a Python script. Then, the string is evaluated.
    If the evaluation succeeds, the callback object is returned. If it fails,
    an error is thrown with a message saying that the name and/or arguments
    of the callback are incorrect.

    The function also checks that there is only one learning rate scheduler
    in the list of callbacks.

    Args:
        callbacks_dict (DictConfig): dictionary containing the 'training.callbacks'
                                     section of the configuration.
        output_dir (str): directory root of the tree where the output files are saved.
        logs_dir (str): directory the TensorBoard logs and training metrics are saved.
        saved_models_dir (str): directory where the trained models are saved.

    Returns:
        List[tf.keras.callbacks.Callback]: A list of Keras callbacks to pass
                                           to the fit() function.
    """

    message = "\nPlease check the 'training.callbacks' section of your configuration file."
    lr_scheduler_names = lr_schedulers.get_scheduler_names()
    num_lr_schedulers = 0

    # Generate the callbacks used in the config file (there may be none)
    callback_list = []
    if callbacks_dict is not None:
        if type(callbacks_dict) != DefaultMunch:
            raise ValueError(f"\nInvalid callbacks syntax{message}")
        for name in callbacks_dict.keys():
            if name in ("ModelCheckpoint", "TensorBoard", "CSVLogger"):
                raise ValueError(f"\nThe `{name}` callback is built-in and can't be redefined.{message}")
            if name in lr_scheduler_names:
                text = f"lr_schedulers.{name}"
            else:
                text = f"tf.keras.callbacks.{name}"

            # Add the arguments to the callback string
            # and evaluate it to get the callback object
            text += collect_callback_args(name, args=callbacks_dict[name], message=message)
            try:
                callback = eval(text)
            except ValueError as error:
                raise ValueError(f"\nThe callback name `{name}` is unknown, or its arguments are incomplete "
                                 f"or invalid\nReceived: {text}{message}") from error
            callback_list.append(callback)

            if name in lr_scheduler_names + ["ReduceLROnPlateau", "LearningRateScheduler"]:
                num_lr_schedulers += 1

    # Check that there is only one scheduler
    if num_lr_schedulers > 1:
        raise ValueError(f"\nFound more than one learning rate scheduler{message}")

    # Add the Keras callback that saves the best model obtained so far
    callback = tf.keras.callbacks.ModelCheckpoint(
                        filepath=os.path.join(output_dir, saved_models_dir, "best_weights.h5"),
                        save_best_only=True,save_weights_only=True,monitor="val_loss", mode="min")
    callback_list.append(callback)

    # Add the Keras callback that saves the model at the end of the epoch
    callback = tf.keras.callbacks.ModelCheckpoint(
                        filepath=os.path.join(output_dir, saved_models_dir, "last_weights.h5"),
                        save_best_only=False,save_weights_only=True,monitor="val_loss",mode="min")
    callback_list.append(callback)

    # Add the TensorBoard callback
    callback = LRTensorBoard(log_dir=os.path.join(output_dir, logs_dir))
    callback_list.append(callback)

    # Add the CVSLogger callback (must be last in the list 
    # of callbacks to make sure it records the learning rate)
    callback = tf.keras.callbacks.CSVLogger(os.path.join(output_dir, logs_dir, "metrics", "train_metrics.csv"))
    callback_list.append(callback)
    return callback_list


def train(cfg: DictConfig = None, train_ds: tf.data.Dataset = None,
          valid_ds: tf.data.Dataset = None, test_ds: Optional[tf.data.Dataset] = None) -> str:
    """
    Trains a model using the provided datasets and configuration settings.

    This function handles the training process of a segmentation model with the
    given training, validation, and optional test datasets. It sets up the model
    according to the configuration provided, compiles it, applies any specified
    data preprocessing, and then trains the model using Keras' `fit` method.
    Callbacks are used for various training aspects like checkpointing and logging.
    After training, the function evaluates the model on the validation set and,
    if provided, on the test set as well.

    Args:
        cfg: A Hydra DictConfig object containing the training configuration.
        train_ds: A tf.data.Dataset object for the training data.
        valid_ds: A tf.data.Dataset object for the validation data.
        test_ds: An optional tf.data.Dataset object for the test data.

    Returns:
        A string representing the file path to the saved best model after training.

    Raises:
        ValueError: If there are issues with the configuration or the training process.
    """
    
    output_dir = Path(HydraConfig.get().runtime.output_dir)
    saved_models_dir = os.path.join(output_dir, cfg.general.saved_models_dir)

    # Logging model and dataset information
    if cfg.general.model_path:
        log_to_file(cfg.output_dir, f"Model file : {cfg.general.model_path}")
    if cfg.dataset.name: 
        log_to_file(output_dir, f"Dataset : {cfg.dataset.name}")
        
    # Load the model to train (Model Zoo model,
    # user model or training resume model)
    model, input_shape = load_model_for_training(cfg)

    # Create and save the base model (compile it
    # to avoid warnings when reloading it)
    base_model = tf.keras.models.clone_model(model)
    base_model.compile()
    base_model_path = os.path.join(saved_models_dir, "base_model.h5")
    base_model.save(base_model_path)

    # Set frozen layers if specified and summarize the model
    if cfg.training.frozen_layers:
        set_frozen_layers(model, frozen_layers=cfg.training.frozen_layers)
    model_summary(model)
    
    class_names = cfg.dataset.class_names
    scale = cfg.preprocessing.rescaling.scale
    offset = cfg.preprocessing.rescaling.offset
    pixels_range = (offset, scale * 255 + offset)

    train_model = SegmentationTrainingModel(
                        model,
                        num_classes=len(class_names),
                        image_size=input_shape[:2],
                        data_augmentation_cfg=cfg.data_augmentation.config,
                        loss_weights=None,
                        pixels_range=pixels_range)
    
    train_model.compile(optimizer=get_optimizer(cfg.training.optimizer))
    
    # Set up callbacks
    callbacks = get_callbacks(callbacks_dict=cfg.training.callbacks, output_dir=output_dir, 
                              logs_dir=cfg.general.logs_dir, saved_models_dir=saved_models_dir)

    print("[INFO] : Starting training")
    start_time = timer()
    history = train_model.fit(train_ds, validation_data=valid_ds, epochs=cfg.training.epochs, callbacks=callbacks)
    end_time = timer()

    # save the last epoch history in the log file
    last_epoch=log_last_epoch_history(cfg, output_dir)
    end_time = timer()
    
    # calculate and log the runtime in the log file
    fit_run_time = int(end_time - start_time)
    average_time_per_epoch = round(fit_run_time / (int(last_epoch) + 1),2)
    print("Training runtime: " + str(timedelta(seconds=fit_run_time)))
    log_to_file(cfg.output_dir, (f"Training runtime : {fit_run_time} s\n" + f"Average time per epoch : {average_time_per_epoch} s"))

    # Set weights and models paths
    best_weights_path = os.path.join(saved_models_dir, "best_weights.h5")
    best_model_path = os.path.join(saved_models_dir, "best_model.h5")
    last_weights_path = os.path.join(saved_models_dir, "last_weights.h5")
    last_model_path = os.path.join(saved_models_dir, "last_model.h5")

    print("[INFO] Saved trained models:")
    print("  best model:", best_model_path)
    print("  last model:", last_model_path)

    # Save the best model
    base_model.load_weights(best_weights_path)
    base_model.save(best_model_path)
    
    # Save the last model    
    base_model.load_weights(last_weights_path)
    base_model.save(last_model_path)

    if cfg.general.display_figures:
        vis_training_curves(history=history, output_dir=output_dir)

    if valid_ds:
        # Evaluate h5 best model on the val set 
        evaluate_h5_model(model_path=best_model_path, eval_ds=valid_ds, class_names=class_names, output_dir=output_dir,
                          name_ds="validation_set")

    if test_ds:
        # Evaluate h5 best model on the test set
        evaluate_h5_model(model_path=best_model_path, eval_ds=test_ds, class_names=class_names, output_dir=output_dir,
                          name_ds="test_set")
    
    return best_model_path

    