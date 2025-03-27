# Semantic Segmentation Model Quantization

Post training quantization is a good way to optimize your neural network models before deploying them on a target. This enables the deployment process to be more efficient on your embedded devices by reducing the required memory usage for weights/activations and reducing the inference time, all with limited degradation in model accuracy.

This tutorial shows how to quantize a floating-point model with real data. As an example, we will demonstrate the workflow on the Deeplab_v3 model and PASCAL VOC 2012 segmentation dataset.

## <a id="">Table of contents</a>

<details open><summary><a href="#1"><b>1. Configure the yaml file</b></a></summary><a id="1"></a>

All the sections of the YAML file must be set as described in the **[README.md](../README.md)** with the `operation_mode` set to quantization. Otherwise, you can specify the `operation_mode` later when running the experiment by:

```bash
python stm32ai_main.py operation_mode=quantization
```

<ul><details open><summary><a href="#1-1">1.1 Prepare the dataset</a></summary><a id="1-1"></a>

Information about the dataset you want to use for activations calibration is provided in the `dataset` section of the configuration file, as shown in the YAML code below.

The state machine below describes the rules to follow when handling the dataset path for quantization.
<div align="center" style="width:50%; margin: auto;">

![plot](../../../common/doc/img/state_machine_quantization.JPG)
</div>

```yaml
dataset:
  name: pascal_voc
  class_names: ["background", "aeroplane", "bicycle", "bird", "boat", "bottle", "bus",
                "car", "cat", "chair", "cow", "dining table", "dog", "horse", "motorbike",
                "person", "potted plant", "sheep", "sofa", "train", "tv/monitor"]
  quantization_path: ../datasets/VOC2012_train_val/JPEGImages
  quantization_masks_path: ../datasets/VOC2012_train_val/SegmentationClassAug
  quantization_files_path: ../datasets/VOC2012_train_val/ImageSets/Segmentation/quantization.txt
```

In the example above, we provide the 3 parameters to properly specify the quantization set: `quantization_path`, `quantization_masks_path`, and `quantization_files_path`. However, we could also use the full training set or a random part of it for activations calibration. The size of the random subset is defined by the percentage value in the `quantization_split` parameter. In this case, we could have set the parameters like this:

```yaml
dataset:
  name: pascal_voc
  class_names: ["background", "aeroplane", "bicycle", "bird", "boat", "bottle", "bus",
                "car", "cat", "chair", "cow", "dining table", "dog", "horse", "motorbike",
                "person", "potted plant", "sheep", "sofa", "train", "tv/monitor"]
  training_path: ../datasets/VOC2012_train_val/JPEGImages
  training_masks_path: ../datasets/VOC2012_train_val/SegmentationClassAug
  training_files_path: ../datasets/VOC2012_train_val/ImageSets/Segmentation/trainaug.txt
  quantization_split: 0.4
```


</details></ul>
<ul><details open><summary><a href="#1-2">1.2 Apply preprocessing</a></summary><a id="1-2"></a>

The images from the dataset need to be preprocessed before they are presented to the network for quantization. This includes rescaling and resizing. In particular, they need to be rescaled exactly as they were during the training step. This is illustrated in the YAML code below:

```yaml
preprocessing:
   rescaling: { scale: 1/127.5, offset: -1 }
   resizing: 
     aspect_ratio: "fit"
     interpolation: bilinear
   color_mode: rgb
```

In this example, the pixels of the input images read from the dataset are in the interval [0, 255], which is UINT8. If you set `scale` to 1./255 and `offset` to 0, they will be rescaled to the interval [0.0, 1.0]. If you set `scale` to 1/127.5 and `offset` to -1, they will be rescaled to the interval [-1.0, 1.0].

The `resizing` attribute specifies the image resizing methods you want to use:
- The value of `interpolation` must be one of *{"bilinear", "nearest", "bicubic", "area", "lanczos3", "lanczos5", "gaussian", "mitchellcubic"}*.
- The value of `aspect_ratio` must be either *"fit"* or *"crop"*. If you set it to *"fit"*, the resized images will be distorted if their original aspect ratio is not the same as the resizing size. If you set it to *"crop"*, images will be cropped as necessary to preserve the aspect ratio.

The `color_mode` attribute must be one of "*grayscale*", "*rgb*" or "*rgba*".

</details></ul>
<ul><details open><summary><a href="#1-3">1.3 Set the model and quantization parameters</a></summary><a id="1-3"></a>

As mentioned previously, all the sections of the YAML file must be set in accordance with this **[README.md](../README.md)**.
In particular, `operation_mode` should be set to quantization and the `quantization` section should be filled as in the following example: 

```yaml
general:
   model_path: <path-to-a-Keras-or-TFlite-model-or-ONNX-file> 
   
quantization:
  quantizer: TFlite_converter # Or, Onnx_quantizer.
  quantization_type: PTQ
  quantization_input_type: uint8
  quantization_output_type: float
  granularity: per_channel  # Optional, defaults to "per_channel".
  optimize: False           # Optional, defaults to False. Only used when using Onnx_quantizer
  target_opset: 17          # Optional, defaults to 17 if not provided. Only used when using Onnx_quantizer
  extra_options: calib_moving_average #Optional, defaults to None. Only used when using Onnx_quantizer
  export_dir: quantized_models
```

**where**:

- `model_path` - *String*, specifies the path of the model to be quantized.
- `quantizer` - *String*, only options are "TFlite_converter" for (.h5 models) and Onnx_quantizer for (.h5 or .onnx models) which will convert model trained weights from float to integer values. The quantized model will be saved in TensorFlow Lite and QDQ Onnx formats respectively.
- `quantization_type` - *String*, only option is "PTQ", i.e. "Post-Training Quantization". 
- `quantization_input_type` - *String*, can be "int8", "uint8" or "float", represents the quantization type for the model input.
- `quantization_output_type` - *String*, can be "int8", "uint8" or "float", represents the quantization type for the model output.
- `granularity` - *String*, can be "per_tensor" (default) or "per_channel", defines the quantization granularity.
- `optimize` - *Boolean*, can be either True or False, controls whether the user wants to optimize the model before attempting to quantize it "per_tensor". Only used when "TFlite_converter" is used.
- `target_opset` - *Integer*, the target opset for the ONNX models, only used when "Onnx_quantizer" is used.
- `extra_options` - *String*, can be `calib_moving_average`, only used when "Onnx_quantizer" is used.
- `export_dir` - *String*, refers to the directory name to save the quantized model.

'Per_tensor' quantization is particularly well suited to fully exploit STM32MP2 platforms HW design. Setting `optimize` to True will cause the model to be slightly optimized in terms of topology and weights in order to facilitate its conversion to 'per_tensor' without losing too much accuracy. However, the optimize feature only works on .h5 models with Tflite converter. In addition, there is no guarantee that 'per_tensor' quantization will preserve the float model accuracy for all the topologies, even if `optimize` is set to True. The benefits of these optimizations need to be assessed for each network and each use case. In the case where eventually the 'per_tensor' accuracy is not satisfying for a given application, we suggest working with 'per_channel' quantization even if this will cause an increase in the network inference time. A reduction of the input size can be considered to compensate at least partially for this, without significant degradation of the accuracy.

The 'extra_options' expects `calib_moving_average` when using `Onnx_quantizer`. When it is set to True, the calibration process for quantizing the model will compute the moving average of the minimum and maximum values observed during the calibration phase. This helps in smoothing out fluctuations and providing a more stable calibration result. If set to False, the calibration will use the raw minimum and maximum values without averaging.

</details></ul>
<ul><details open><summary><a href="#1-4">1.4 Random quantization</a></summary><a id="1-4"></a>

If no quantization set is specified in `quantization_path`, `quantization_masks_path`, and `quantization_files_path` and no training set is specified in `training_path`, `training_masks_path`, and `training_files_path`, then the model is quantized after calibration on random data. There is no interest in evaluating the accuracy in this case. However, this random quantization can be useful to quickly estimate the model footprints on a target after quantization. We will see how to proceed in the next section.

</details></ul>
<ul><details open><summary><a href="#1-5">1.5 Hydra and MLflow settings</a></summary><a id="1-5"></a>

The `mlflow` and `hydra` sections must always be present in the YAML configuration file. The `hydra` section can be used to specify the name of the directory where experiment directories are saved and/or the 
pattern used to name experiment directories. With the YAML code below, every time you run the Model Zoo, an experiment directory is created that contains all the directories and files created during the run. 
The names of experiment directories are all unique as they are based on the date and time of the run.

```yaml
hydra:
   run:
      dir: ./experiments_outputs/${now:%Y_%m_%d_%H_%M_%S}
```

The `mlflow` section is used to specify the location and name of the directory where MLflow files are saved, as shown below:

```yaml
mlflow:
   uri: ./experiments_outputs/mlruns
```

</details></ul>
</details>
<details open><summary><a href="#2"><b>2. Quantize your model</b></a></summary><a id="2"></a>

To launch your model quantization using a real dataset, run the following command from the **src/** folder:

```bash
python stm32ai_main.py --config-path ./config_file_examples/ --config-name quantization_config.yaml
```

The quantized model can be found in the corresponding **experiments_outputs/** folder.


In case you want to evaluate the accuracy of the quantized model, you can either launch the evaluation operation mode on the generated quantized model (please refer to the evaluation **[README.md](../evaluation/README.md)** that describes in detail how to proceed) or you can use chained services like launching [chain_eqe](../config_file_examples/chain_eqe_config.yaml) example with the command below:

```bash
python stm32ai_main.py --config-path ./config_file_examples/ --config-name chain_eqe_config.yaml
```

In case you want to evaluate your quantized model footprints, you can either launch the benchmark operation mode on the generated quantized model (please refer to the benchmarking **[README.md](../benchmarking/README.md)** that describes in detail how to proceed) or you can use chained services like launching [chain_qb](../config_file_examples/chain_qb_config.yaml) example with the command below:

```bash
python stm32ai_main.py --config-path ./config_file_examples/ --config-name chain_qb_config.yaml
```

Chained services work whether you specify a quantization dataset or not (random quantization).

</details>
