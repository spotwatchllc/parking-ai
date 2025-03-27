# /*---------------------------------------------------------------------------------------------
#  * Copyright (c) 2024 STMicroelectronics.
#  * All rights reserved.
#  *
#  * This software is licensed under terms that can be found in the LICENSE file in
#  * the root directory of this software component.
#  * If no LICENSE file comes with this software, it is provided AS-IS.
#  *--------------------------------------------------------------------------------------------*/

'''Utility file with functions to load a dataset from the user_config cfg'''

from dataset_utils import Valentini, CustomValentiniLike

def _load_valentini(cfg,
                    set,
                    n_clips,
                    val_split,
                    input_pipeline,
                    target_pipeline=None,
                    return_only_noisy=False):
    
    ds = Valentini(dataset_folder=cfg.dataset.root_folder,
                   set=set,
                   n_speakers=cfg.dataset.n_speakers,
                   sample_rate=cfg.preprocessing.sample_rate,
                   input_pipeline=input_pipeline,
                   target_pipeline=target_pipeline,
                   return_transcript=False, # These next few params can be exposed in cfg later
                   time_data_aug=None,
                   freq_data_aug=None,
                   preproc_lib='librosa', # Can also be exposed in cfg later
                   device='cpu',
                   n_clips=n_clips,
                   random_seed=cfg.dataset.random_seed,
                   val_split=val_split,
                   return_only_noisy=return_only_noisy) 
    return ds

def _load_custom_valentini_like(cfg,
                                set,
                                n_clips,
                                val_split,
                                input_pipeline,
                                target_pipeline=None,
                                quantization=False):
    
    if quantization and cfg.quantization.noisy_quantization_files_path:
        noisy_files_path = cfg.quantization.noisy_quantization_files_path
        clean_files_path = None
    
    elif quantization:
        noisy_files_path = cfg.dataset.noisy_train_files_path
        clean_files_path = None

    elif set in ["train", "valid"]:
        noisy_files_path = cfg.dataset.noisy_train_files_path
        clean_files_path = cfg.dataset.clean_train_files_path

    else:
        noisy_files_path = cfg.dataset.noisy_test_files_path
        clean_files_path = cfg.dataset.clean_test_files_path

    ds = CustomValentiniLike(noisy_files_path=noisy_files_path,
                             set=set,
                             clean_files_path=clean_files_path,
                             input_pipeline=input_pipeline,
                             target_pipeline=target_pipeline,
                             file_extension=cfg.dataset.file_extension,
                             return_transcript=False,
                             txt_folder=None,
                             time_data_aug=None,
                             freq_data_aug=None,
                             preproc_lib="librosa",
                             device='cpu',
                             n_clips=n_clips,
                             val_split=val_split,
                             random_seed=cfg.dataset.random_seed)
    return ds

def load_dataset_from_cfg(cfg,
                          set,
                          n_clips,
                          input_pipeline,
                          target_pipeline,
                          quantization=False,
                          val_split=None):
    if quantization and cfg.quantization.noisy_quantization_files_path:
        # If it's a request for a quantization dataset, and specific files are provided
        # Load them as a custom dataset regardless of what dataset type it is
        return _load_custom_valentini_like(cfg,
                                           set,
                                           n_clips,
                                           val_split,
                                           input_pipeline,
                                           target_pipeline,
                                           quantization=quantization)

    if cfg.dataset.name == "valentini":
        if set =="valid":
            print("[INFO] The Valentini training set has 2.5 dB lower base SNR than the test set. \n"
                  "Therefore, validation performance will be worse than test performance.")
        return _load_valentini(cfg,
                               set,
                               n_clips,
                               val_split,
                               input_pipeline,
                               target_pipeline,
                               return_only_noisy=quantization)
    
    elif cfg.dataset.name == "custom":
        return _load_custom_valentini_like(cfg,
                                           set,
                                           n_clips,
                                           val_split,
                                           input_pipeline,
                                           target_pipeline,
                                           quantization=quantization)
    else:
        raise ValueError("Invalid dataset name." 
                         f"Must be one of 'valentini', 'custom', was {cfg.dataset.name}")
                         
    
