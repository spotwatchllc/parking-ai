# /*---------------------------------------------------------------------------------------------
#  * Copyright (c) 2022-2023 STMicroelectronics.
#  * All rights reserved.
#  *
#  * This software is licensed under terms that can be found in the LICENSE file in
#  * the root directory of this software component.
#  * If no LICENSE file comes with this software, it is provided AS-IS.
#  *--------------------------------------------------------------------------------------------*/

import os
import sys
from pathlib import Path
import argparse
from omegaconf import OmegaConf
from munch import DefaultMunch
import matplotlib.pyplot as plt
import numpy as np
import tensorflow as tf

sys.path.append(os.path.join(os.path.dirname(__file__), '../../../../common/utils'))
sys.path.append(os.path.join(os.path.dirname(__file__), '../../../../common/data_augmentation'))
sys.path.append(os.path.abspath('../../utils'))
sys.path.append(os.path.abspath('../../preprocessing'))
sys.path.append(os.path.abspath('../../data_augmentation'))
sys.path.append(os.path.abspath('../../models'))

from cfg_utils import postprocess_config_dict
from parse_config import parse_dataset_section, parse_preprocessing_section, parse_data_augmentation_section
from random_utils import remap_pixel_values_range
from data_loader import get_ds
from data_augmentation import data_augmentation


def plot_images_and_labels(image: np.array, label: np.array,
                           image_aug: np.array, label_aug: np.array) -> None:
    """
    Displays side by side the original and augmented image
    with their groundtruth bounding boxes.

    Arguments:
        images:
            Original image.
            A numpy array with shape [width, height, channels]
        labels:
            Groundtruth labels of the original image.
            A numpy array with shape [num_labels, 5]
        images_aug:
            Augmented images.
            A numpy rray with shape [width, height, channels]
        images_aug:
            Groundtruth labels of the augmented images.
            A numpy array with shape [num_labels, 5]
        class_names:
            A list of strings, the class names.
            
    Returns:
        None
    """

    # Calculate the dimensions of the displayed images
    image_width, image_height = np.shape(image)[:2]
    display_size = 9
    if image_width >= image_height:
        x_size = display_size
        y_size = round((image_width / image_height) * display_size)
    else:
        y_size = display_size
        x_size = round((image_height / image_width) * display_size)

    fig, axes = plt.subplots(2, 2, figsize=(x_size, y_size))
    (ax1, ax2), (ax3, ax4) = axes

    ax1.imshow(image)
    ax1.title.set_text("Original")
    ax2.imshow(image_aug)
    ax2.title.set_text("Augmented")
    ax3.imshow(label)
    ax4.imshow(label_aug)

    plt.show()
    plt.close()
    

def test_data_augmentation(config_file_path: str, seed_arg: str = None) -> None:
    """
    Samples a batch of images with their groundtruth labels from 
    the training set, applies to them the data augmentation functions
    specified in the YAML configuration file, and displays side by side 
    the original images and augmented images with their groundtruth
    bounding boxes.

    Arguments:
        config_file_path:
            A string, specifies the path to the YAML configuration file.
        seed_args:
            An integer, the optional `seed` argument passed to the script.
            Set to None if the argument was not used.

    Returns:
        None
    """
    
    # If the `seed` argument of the script was not used,
    # random generators are not seeded.
    if seed_arg:
        tf.keras.utils.set_random_seed(seed_arg)

    # Load and postprocess the configuration file
    config_data = OmegaConf.load(config_file_path)
    config_dict = OmegaConf.to_container(config_data)
    postprocess_config_dict(config_dict, replace_none_string=True)
    cfg = DefaultMunch.fromDict(config_dict)

    # Check that there is a data augmentation section
    # and that the operation mode is set to 'training'
    if not cfg.data_augmentation and not cfg.custom_data_augmentation:
        raise ValueError("\nCould not find any data augmentation section.\n"
                         "Please check your configuration file.")
    if cfg.operation_mode != "training":
        raise ValueError("\nPlease set `operation_mode` to 'training' to run this script.")

    # Parse the needed config file sections
    mode_groups = DefaultMunch.fromDict({
                            "training": ["training"],
                            "evaluation": ["evaluation"],
                            "quantization": ["quantization"]
                  })
    parse_dataset_section(cfg.dataset, "training", mode_groups)
    parse_preprocessing_section(cfg.preprocessing, mode="training")
    parse_data_augmentation_section(cfg)
    
    if not os.path.isabs(cfg.dataset.training_path):
        cfg.dataset.training_path = os.path.join("../../", cfg.dataset.training_path)

    cpp = cfg.preprocessing.rescaling
    pixels_range = (cpp.offset, 255*cpp.scale + cpp.offset)

    # If the `seed` argument of the script was not used,
    # different images will be sampled every time
    # the script is run.
    seed = seed_arg if seed_arg else None
        
    # Create a data loader to get examples from the training set
    print("Dataset:", cfg.dataset.training_path)    
    print("Sampling seed:", seed)
    data_loader= get_ds(cfg.dataset.training_path,
                        cfg.dataset.training_masks_path,
                        cfg.dataset.training_files_path,
                        cfg=cfg,
                        image_size=cfg.training.model.input_shape[:2],
                        batch_size=4,
                        seed=seed,
                        shuffle=True,
                        to_cache=False)
						
    augmentation_functions = list(cfg.data_augmentation.config.keys())
    if len(augmentation_functions) == 0:
        print("No data augmentation functions to test. Exiting script...")
        exit()

    print("Use ctrl+c to exit the script")

    for data in data_loader:
        images = tf.cast(data[0], tf.float32)
        labels = tf.cast(data[1], tf.float32)
        
        batch_size = tf.shape(images)[0]

        # Apply the data augmentation functions to the images and labels
        images_aug, labels_aug = data_augmentation(
                                images, labels,
                                cfg.data_augmentation.config,
                                pixels_range=pixels_range)

        # Map pixels values to the [0, 1] interval 
        # to get correct displays in matplotlib
        images = remap_pixel_values_range(images, pixels_range, (0, 1))
        images_aug = remap_pixel_values_range(images_aug, pixels_range, (0, 1))

        # Plot the images and their groundtruth labels
        for i in range(batch_size):
            plot_images_and_labels(images[i].numpy(), labels[i].numpy(), 
                                  images_aug[i].numpy(), labels_aug[i].numpy())


def main():

    parser = argparse.ArgumentParser()
    parser.add_argument("--config_file", type=str, default="../../user_config.yaml",
                        help="Path to the YAML configuration file starting from the directory " + \
                        "above this script. Default: ../user_config.yaml")
    parser.add_argument("--seed", type=str, default="",
                        help="Seed for the random generators used to sample the dataset. " + \
                        "By default, samples will be different every time the script is run.")
    
    args = parser.parse_args()

    if not os.path.isfile(Path(args.config_file)):
        raise ValueError(f"\nCould not find configuration file {args.config_file}")

    if args.seed:
        try:
            seed = int(args.seed)
        except:
            raise ValueError(f"\nThe `seed` argument should be an integer. Received {args.seed}")
    else:
        seed = None

    test_data_augmentation(Path(args.config_file), seed_arg=seed)

if __name__ == '__main__':
    main()

