#  /*---------------------------------------------------------------------------------------------
#  * Copyright (c) 2022-2023 STMicroelectronics.
#  * All rights reserved.
#  *
#  * This software is licensed under terms that can be found in the LICENSE file in
#  * the root directory of this software component.
#  * If no LICENSE file comes with this software, it is provided AS-IS.
#  *--------------------------------------------------------------------------------------------*/

import os
from pathlib import Path
import re
from hydra.core.hydra_config import HydraConfig
from cfg_utils import aspect_ratio_dict, check_attributes, postprocess_config_dict, check_config_attributes, \
                      parse_tools_section, parse_benchmarking_section, parse_mlflow_section, parse_quantization_section, \
                      parse_general_section, parse_top_level, parse_training_section, parse_prediction_section, \
                      parse_deployment_section, check_hardware_type, parse_evaluation_section
from omegaconf import OmegaConf, DictConfig
from munch import DefaultMunch
import tensorflow as tf
from data_loader import check_dataset_integrity
from typing import Dict, List


def check_dataset_paths_and_contents(cfg, mode: str = None, mode_groups: DictConfig = None) -> None:
    """
            This function checks that the paths available in the config file are valid, depending on the operation mode
            considered.
            args:
                cfg (DictConfig): dictionary containing the configuration file section to check
                mode (str): operation mode: 'quantization', 'training'...as well as chained operation modes: 'chain_tqe',
                'chain_eqe'...
                mode_groups (dictionary): each operation mode belongs to one or more mode_groups which induces some
                specific requirements on dataset availability
        """

    # Check the datasets
    for name in ["training_path", "validation_path", "test_path", "quantization_path"]:
        path = cfg[name]
        if path:
            if not os.path.isdir(path):
                raise FileNotFoundError(f"\nUnable to find the root directory of the {name[:-5]} set\n"
                                        f"Received path: {path}\n"
                                        "Please check the 'dataset' section of your configuration file.")
            if cfg.check_image_files:
                print(f"[INFO] : Checking {path} dataset")
            check_dataset_integrity(path, check_image_files=cfg.check_image_files)


def parse_dataset_section(cfg: DictConfig, mode: str = None, mode_groups: DictConfig = None, hardware_type: str = None) -> None:
    """
                This function checks the preprocessing section of the config file.

                Arguments:
                    cfg (DictConfig): The dataset configuration parameters as a DefaultMunch dictionary.
                    mode (str): the operation mode for example: 'quantization', 'evaluation', 'chain_tqe'...
                    mode_groups (dict): the operation mode group. Each mode, including chained mode belongs to one or more
                    mode_groups like 'quantization', 'evaluation'...which induces some specific requirements on dataset
                    availability.

                Returns:
                    None
            """

    legal = ["name", "class_names", "training_path", "validation_path", "validation_split", "test_path",
             "quantization_path", "quantization_split", "check_image_files", "seed"]

    required = []
    one_or_more = []
    if mode in mode_groups.training:
        required += ["training_path",]
    elif mode in mode_groups.evaluation:
        one_or_more += ["training_path", "test_path", "validation_path"]
    elif mode in mode_groups.deployment:
        if hardware_type == "MCU":
            required += ["class_names",]
    elif mode == "prediction":
         required += ["class_names",]

    check_config_attributes(cfg, specs={"legal": legal, "all": required, "one_or_more": one_or_more},
                            section="dataset")

    # Set default values of missing optional attributes
    if not cfg.name:
        cfg.name = "<unnamed>"
    if not cfg.validation_split:
        cfg.validation_split = 0.2
    cfg.check_image_files = cfg.check_image_files if cfg.check_image_files is not None else False
    cfg.seed = cfg.seed if cfg.seed else 123

    # Sort the class names if they were provided
    if cfg.class_names:
        cfg.class_names = sorted(cfg.class_names)
    elif cfg.name in ("cifar10", "cifar100", "emnist"):
        cfg.class_names = get_class_names(cfg.name)

    # Check the value of validation_split if it is set
    if cfg.validation_split:
        split = cfg.validation_split
        if split <= 0.0 or split >= 1.0:
            raise ValueError(f"\nThe value of `validation_split` should be > 0 and < 1. Received {split}\n"
                                "Please check the 'dataset' section of your configuration file.")

    # Check the value of quantization_split if it is set
    if cfg.quantization_split:
        split = cfg.quantization_split
        if split <= 0.0 or split >= 1.0:
            raise ValueError(f"\nThe value of `quantization_split` should be > 0 and < 1. Received {split}\n"
                             "Please check the 'dataset' section of your configuration file.")

    if cfg.name not in ("emnist", "cifar10", "cifar100"):
        check_dataset_paths_and_contents(cfg, mode=mode, mode_groups=mode_groups)


def parse_preprocessing_section(cfg: DictConfig,
                                mode: str = None) -> None:
    """
            This function checks the preprocessing section of the config file.

            Arguments:
                cfg (DictConfig): The entire configuration file as a DefaultMunch dictionary.
                mode (str): the operation mode for example: 'quantization', 'evaluation'...

            Returns:
                None
        """

    legal = ["rescaling", "resizing", "color_mode"]
    if mode == 'deployment':
        # removing the obligation to have rescaling for the 'deployment' mode
        required = ["resizing", "color_mode"]
        check_config_attributes(cfg, specs={"legal": legal, "all": required}, section="preprocessing")
    else:
        required = legal
        check_config_attributes(cfg, specs={"legal": legal, "all": required}, section="preprocessing")
        legal = ["scale", "offset"]
        check_config_attributes(cfg.rescaling, specs={"legal": legal, "all": legal}, section="preprocessing.rescaling")

    legal = ["interpolation", "aspect_ratio"]
    if cfg.resizing.aspect_ratio == "fit":
        required = ["interpolation", "aspect_ratio"]
    else:
        required = ["aspect_ratio"]

    check_config_attributes(cfg.resizing, specs={"legal": legal, "all": required}, section="preprocessing.resizing")

    # Check the of aspect ratio value
    aspect_ratio = cfg.resizing.aspect_ratio
    if aspect_ratio not in aspect_ratio_dict:
        raise ValueError(f"\nUnknown or unsupported value for `aspect_ratio` attribute. Received {aspect_ratio}\n"
                         f"Supported values: {list(aspect_ratio_dict.keys())}.\n"
                         "Please check the 'preprocessing.resizing' section of your configuration file.")

    if aspect_ratio == "fit":
        # Check resizing interpolation value
        check_config_attributes(cfg.resizing, specs={"all": ["interpolation"]}, section="preprocessing.resizing")
        interpolation_methods = ["bilinear", "nearest", "area", "lanczos3", "lanczos5", "bicubic", "gaussian",
                                 "mitchellcubic"]
        if cfg.resizing.interpolation not in interpolation_methods:
            raise ValueError(f"\nUnknown value for `interpolation` attribute. Received {cfg.resizing.interpolation}\n"
                             f"Supported values: {interpolation_methods}\n"
                             "Please check the 'preprocessing.resizing' section of your configuration file.")

    # Check color mode value
    color_modes = ["grayscale", "rgb", "rgba"]
    if cfg.color_mode not in color_modes:
        raise ValueError(f"\nUnknown value for `color_mode` attribute. Received {cfg.color_mode}\n"
                         f"Supported values: {color_modes}\n"
                         "Please check the 'preprocessing' section of your configuration file.")


def parse_data_augmentation_section(cfg: DictConfig, config_dict: Dict) -> None:
    """
    This function checks the data augmentation section of the config file.
    The attribute that introduces the section is either `data_augmentation`
    or `custom_data_augmentation`. If it is `custom_data_augmentation`,
    the name of the data augmentation function that is provided must be
    different from `data_augmentation` as this is a reserved name.

    Arguments:
        cfg (DictConfig): The entire configuration file as a DefaultMunch dictionary.
        config_dict (Dict): The entire configuration file as a regular Python dictionary.

    Returns:
        None
    """

    if cfg.data_augmentation and cfg.custom_data_augmentation:
        raise ValueError("\nThe `data_augmentation` and `custom_data_augmentation` attributes "
                         "are mutually exclusive.\nPlease check your configuration file.")

    if cfg.data_augmentation:
        cfg.data_augmentation = DefaultMunch.fromDict({})
        # The name of the Model Zoo data augmentation function is 'data_augmentation'.
        cfg.data_augmentation.function_name = "data_augmentation"
        cfg.data_augmentation.config = config_dict['data_augmentation'].copy()

    if cfg.custom_data_augmentation:
        check_attributes(cfg.custom_data_augmentation,
                         expected=["function_name"],
                         optional=["config"],
                         section="custom_data_augmentation")
        cfg.data_augmentation = DefaultMunch.fromDict({})
        if cfg.custom_data_augmentation["function_name"] == "data_augmentation":
            raise ValueError("\nThe function name `data_augmentation` is reserved.\n"
                             "Please use another name (attribute `function_name` in "
                             "the 'custom_data_augmentation' section).")
        cfg.data_augmentation.function_name = cfg.custom_data_augmentation.function_name
        if cfg.custom_data_augmentation.config:
            cfg.data_augmentation.config = config_dict['custom_data_augmentation']['config'].copy()
        del cfg.custom_data_augmentation


def get_class_names_from_file(cfg: DictConfig) -> List[str]:
    """
    Reads class names from a file specified in the configuration and returns them as a list.
    Args:
        cfg (DictConfig): Configuration object containing the path to the label file.
    Returns:
        List[str]: A list of class names read from the file.
    Raises:
        FileNotFoundError: If the file specified in the configuration does not exist.
        IOError: If there is an error reading the file.
    """
    if cfg.deployment.label_file_path:
        with open(cfg.deployment.label_file_path, 'r') as file:
            class_names = [line.strip() for line in file]
    return class_names


def get_class_names(dataset_name: str = None, dataset_root_dir: str = None) -> List:
    """
    This function returns the class names of the dataset.
      - If the dataset is cifar10, cifar100 or emnist, the class names
        are returned by functions associated to the dataset.
      - Otherwise the class names are inferred from the dataset. These are
        the names of the subdirectories under the dataset root directory.

    Args:
        dataset_name (str): The name of the dataset.
        dataset_root_dir (str): The path to the root directory of the dataset
                if the dataset is not cifar10, cifar100 or emnist.

    Returns:
        string (List): A list of strings.
    """

    if dataset_name:
        if dataset_name == "cifar10":
            class_names = ["airplane", "automobile", "bird", "cat", "deer", "dog", "frog", "horse", "ship", "truck"]
        elif dataset_name == "cifar100":
            class_names = sorted([
                "beaver", "dolphin", "otter", "seal", "whale", "aquarium fish", "flatfish", "ray", "shark", "trout",
                "orchids", "poppies", "roses", "sunflowers", "tulips", "bottles", "bowls", "cans", "cups", "plates",
                "apples", "mushrooms", "oranges", "pears", "sweet peppers", "clock", "computer keyboard", "lamp",
                "telephone", "television", "bed", "chair", "couch", "table", "wardrobe", "bee", "beetle", "butterfly",
                "caterpillar", "cockroach", "bear", "leopard", "lion", "tiger", "wolf", "bridge", "castle", "house",
                "road", "skyscraper", "cloud", "forest", "mountain", "plain", "sea", "camel", "cattle", "chimpanzee",
                "elephant", "kangaroo", "fox", "porcupine", "possum", "raccoon", "skunk", "crab", "lobster", "snail",
                "spider", "worm", "baby", "boy", "girl", "man", "woman", "crocodile", "dinosaur", "lizard", "snake",
                "turtle", "hamster", "mouse", "rabbit", "shrew", "squirrel", "maple", "oak", "palm", "pine", "willow",
                "bicycle", "bus", "motorcycle", "pickup truck", "train", "lawn-mower", "rocket", "streetcar", "tank",
                "tractor"])
        elif dataset_name == "emnist":
            class_names = [i for i in range(10)] + list(string.ascii_uppercase)
    else:
        # Get the list of subdirectories. These are the class names.
        class_names = sorted([x for x in os.listdir(dataset_root_dir)
                                    if os.path.isdir(os.path.join(dataset_root_dir, x))])

    return class_names


def get_config(config_data: DictConfig) -> DefaultMunch:
    """
    Converts the configuration data, performs some checks and reformats
    some sections so that they are easier to use later on.

    Args:
        config_data (DictConfig): dictionary containing the entire configuration file.

    Returns:
        DefaultMunch: The configuration object.
    """

    config_dict = OmegaConf.to_container(config_data)

    # Restore booleans, numerical expressions and tuples
    # Expand environment variables
    postprocess_config_dict(config_dict)

    # Top level section parsing
    cfg = DefaultMunch.fromDict(config_dict)
    mode_groups = DefaultMunch.fromDict({
        "training": ["training", "chain_tqeb", "chain_tqe"],
        "evaluation": ["evaluation", "chain_tqeb", "chain_tqe", "chain_eqe", "chain_eqeb"],
        "quantization": ["quantization", "chain_tqeb", "chain_tqe", "chain_eqe",
                         "chain_qb", "chain_eqeb", "chain_qd"],
        "benchmarking": ["benchmarking", "chain_tqeb", "chain_qb", "chain_eqeb"],
        "deployment": ["deployment", "chain_qd"]
    })

    mode_choices = ["training", "evaluation", "prediction", "deployment", "quantization", "benchmarking", "chain_tqeb",
                    "chain_tqe", "chain_eqe", "chain_qb", "chain_eqeb", "chain_qd"]
    legal = ["general", "operation_mode", "dataset", "preprocessing", "data_augmentation", "custom_data_augmentation",
             "training", "quantization", "evaluation", "prediction", "tools", "benchmarking", "deployment", "mlflow",
             "hydra"]

    parse_top_level(cfg,
                    mode_groups=mode_groups,
                    mode_choices=mode_choices,
                    legal=legal)
    print(f"[INFO] : Running `{cfg.operation_mode}` operation mode")

    # General section parsing
    if not cfg.general:
        cfg.general = DefaultMunch.fromDict({"project_name": "<unnamed>"})
    legal = ["project_name", "model_path", "logs_dir", "saved_models_dir", "deterministic_ops",
             "display_figures", "global_seed", "gpu_memory_limit", "num_threads_tflite"]
    required = []
    parse_general_section(cfg.general,
                          mode=cfg.operation_mode,
                          mode_groups=mode_groups,
                          legal=legal,
                          required=required,
                          output_dir=HydraConfig.get().runtime.output_dir)

    # Select hardware_type from yaml information
    check_hardware_type(cfg,
                        mode_groups)

    # Dataset section parsing
    if not cfg.dataset:
        cfg.dataset = DefaultMunch.fromDict({})
    parse_dataset_section(cfg.dataset,
                          mode=cfg.operation_mode,
                          mode_groups=mode_groups,
                          hardware_type=cfg.hardware_type)

    # Preprocessing section parsing
    parse_preprocessing_section(cfg.preprocessing, mode=cfg.operation_mode)

    # Training section parsing
    if cfg.operation_mode in mode_groups.training:
        if cfg.data_augmentation or cfg.custom_data_augmentation:
            parse_data_augmentation_section(cfg, config_dict)
        model_path_used = bool(cfg.general.model_path)
        model_type_used = bool(cfg.general.model_type)
        legal = ["model", "batch_size", "epochs", "optimizer", "dropout", "frozen_layers",
                 "callbacks", "resume_training_from", "trained_model_path"]
        parse_training_section(cfg.training,
                               model_path_used=model_path_used,
                               model_type_used=model_type_used,
                               legal=legal)

    # Quantization section parsing
    if cfg.operation_mode in mode_groups.quantization:
        legal = ["quantizer", "quantization_type", "quantization_input_type", "quantization_output_type",
                 "export_dir", "granularity", "target_opset", "optimize", "extra_options"]
        parse_quantization_section(cfg.quantization,
                                   legal=legal)

    # Evaluation section parsing
    if cfg.operation_mode in mode_groups.evaluation and "evaluation" in cfg:
        legal = ["gen_npy_input", "gen_npy_output", "npy_in_name", "npy_out_name", "target"]
        parse_evaluation_section(cfg.evaluation,
                                 legal=legal)

    # Prediction section parsing
    if cfg.operation_mode == "prediction":
        parse_prediction_section(cfg.prediction)

    # Tools section parsing
    if cfg.operation_mode in (mode_groups.benchmarking + mode_groups.deployment):
        parse_tools_section(cfg.tools,
                            cfg.operation_mode,
                            cfg.hardware_type)

    # For MPU, check if online benchmarking is activated
    if cfg.operation_mode in mode_groups.benchmarking:
        if cfg.hardware_type == "MPU":
            if cfg.operation_mode == "benchmarking" and not cfg.tools.stm32ai.on_cloud:
                print("Target selected for benchmark :", cfg.benchmarking.board)
                print("Offline benchmarking for MPU is not yet available please use online benchmarking")
                exit(1)

    # Benchmarking section parsing
    if cfg.operation_mode in mode_groups.benchmarking:
        parse_benchmarking_section(cfg.benchmarking)
        if cfg.hardware_type == "MPU":
            if not cfg.tools.stm32ai.on_cloud:
                print("Target selected for benchmark :", cfg.benchmarking.board)
                print("Offline benchmarking for MPU is not yet available please use online benchmarking")
                exit(1)

    # Deployment section parsing
    if cfg.operation_mode in mode_groups.deployment:
        if cfg.hardware_type == "MCU":
            legal = ["c_project_path", "IDE", "verbosity", "hardware_setup"]
            legal_hw = ["serie", "board", "stlink_serial_number"]
            # Append additional items if hardware_type is "MCU_H7"
            if cfg.deployment.hardware_setup.serie == "STM32H7":
                legal_hw += ["input", "output"]
        else:
            legal = ["c_project_path", "label_file_path","board_deploy_path", "verbosity", "hardware_setup"]
            legal_hw = ["serie", "board", "ip_address"]
            if cfg.preprocessing.color_mode != "rgb":
                raise ValueError("\n Color mode used is not supported for deployment on MPU target \n Please use RGB format")
            if cfg.preprocessing.resizing.aspect_ratio != "fit":
                raise ValueError("\n Aspect ratio used is not supported for deployment on MPU target \n Please use FIT aspect ratio")
        parse_deployment_section(cfg.deployment,
                                 legal=legal,
                                 legal_hw=legal_hw)

    # MLFlow section parsing
    parse_mlflow_section(cfg.mlflow)

    # Check that all datasets have the required directory structure
    cds = cfg.dataset
    if not cds.class_names and cfg.operation_mode not in "benchmarking":
        # Infer the class names from a dataset
        for path in [cds.training_path, cds.validation_path, cds.test_path, cds.quantization_path]:
            if path:
                cds.class_names = get_class_names(dataset_root_dir=path)
                print("[INFO] : Found {} classes in dataset {}".format(len(cds.class_names), path))
                break

        if not cds.class_names and cfg.operation_mode in ("deployment", "chain_qd") and cfg.hardware_type == "MPU":
            cds.class_names = get_class_names_from_file(cfg)
            print("[INFO] : Found {} classes in label file {}".format(len(cds.class_names), cfg.deployment.label_file_path))
    return cfg
