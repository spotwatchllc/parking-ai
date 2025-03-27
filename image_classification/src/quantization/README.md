# Image Classification STM32 Model Quantization

Post-training quantization is a good way to optimize your neural network models before deploying them on a target. This makes the deployment process more efficient on your embedded devices by reducing the required memory usage (Flash/RAM) and reducing the inference time, all with little-to-no degradation in model accuracy. We support ONNX quantizer (QDQ format) and TensorFlow Lite converter quantization.

This tutorial shows how to quantize a floating-point model with real data. As an example, we will demonstrate the workflow on the [tf_flowers](https://storage.googleapis.com/download.tensorflow.org/example_images/flower_photos.tgz) classification dataset.



<details open>
<summary><a href="#1"><b>1. Configure the YAML file</b></a></summary><a id="1"></a>

All the sections of the YAML file must be set as described in the **[README.md](../README.md)** with the `operation_mode` set to quantization. Alternatively, you can specify the `operation_mode` later when running the experience by using `python stm32ai_main.py operation_mode=quantization`.

<ul>
<details open><summary><a href="#1-1">1.1 Prepare the dataset</a></summary><a id="1-1"></a>

Information about the dataset you want to use for activations calibration is provided in the `dataset` section of the configuration file, as shown in the YAML code below.

```yaml
dataset:
  name: flowers 
  class_names: [daisy, dandelion, roses, sunflowers, tulips]
  test_path:
  quantization_path: ../datasets/flower_photos
  quantization_split: 0.4
  seed: 0
```

In this example, the only provided path is the `quantization_path`. It could be the full training set or a specific set dedicated to activations calibration. If you only want to quantize the model on a random part of your quantization set, simply set the percentage value in the `quantization_split` parameter.

State machine below describes the rules to follow when handling dataset path for the quantization.
<div align="center" style="width:50%; margin: auto;">

![plot](../../../common/doc/img/state_machine_quantization.JPG)
</div>

Most of the time, it is not necessary to take thousands of images to calibrate your activations. It would take much more time and in the end does not necessarily bring an accuracy improvement. Although it is impossible to have a general rule, we have found that tens to hundreds of representative input samples are enough in most cases.

</details>

<details open><summary><a href="#1-2">1.2 Apply preprocessing</a></summary><a id="1-2"></a>

The images from the dataset need to be preprocessed before they are presented to the network for quantization. This includes rescaling and resizing. In particular, they need to be rescaled exactly as they were at the training step. This is illustrated in the YAML code below:

```yaml
preprocessing:
   rescaling: { scale: 1/127.5, offset: -1 }
   resizing: 
     aspect_ratio: "fit"
     interpolation: nearest
   color_mode: rgb
```

In this example, the pixels of the input images read in the dataset are in the interval [0, 255], that is UINT8. If you set `scale` to 1./255 and `offset` to 0, they will be rescaled to the interval [0.0, 1.0]. If you set `scale` to 1/127.5 and `offset` to -1, they will be rescaled to the interval [-1.0, 1.0].

The `resizing` attribute specifies the image resizing methods you want to use:
- The value of `interpolation` must be one of *{"bilinear", "nearest", "bicubic", "area", "lanczos3", "lanczos5", "gaussian", "mitchellcubic"}*.
- The value of `aspect_ratio` must be either *"fit"* or *"crop"*. If you set it to *"fit"*, the resized images will be distorted if their original aspect ratio is not the same as the resizing size. If you set it to *"crop"*, images will be cropped as necessary to preserve the aspect ratio.

The `color_mode` attribute must be one of "*grayscale*", "*rgb*" or "*rgba*".

</details>

<details open><summary><a href="#1-3">1.3 Set the model and quantization parameters</a></summary><a id="1-3"></a>

As mentioned previously, all the sections of the YAML file must be set in accordance with this **[README.md](../README.md)**. In particular, `operation_mode` should be set to quantization and the `quantization` section should be filled as in the following example:

```yaml
general:
   model_path: ../../../model_zoo/image_classification/mobilenetv2/ST_pretrainedmodel_public_dataset/flowers/mobilenet_v2_0.35_128_fft/mobilenet_v2_0.35_128_fft.h5
   
quantization:
  quantizer: TFlite_converter
  quantization_type: PTQ
  quantization_input_type: uint8
  quantization_output_type: float
  granularity: per_channel  # Optional, defaults to "per_channel".
  optimize: False           # Optional, defaults to False.
  target_opset: 17          # Optional, defaults to 17 if not provided. Only used for when using Onnx_quantizer
  export_dir: quantized_models
  extra_options: calib_moving_average # Optional, only applies to Onnx_quantizer
```

**where**:

- `model_path` - *String*, specifies the path of the model to be quantized.
- `quantizer` - *String*, only options are "TFlite_converter" or "Onnx_quantizer" which will convert model trained weights from float to integer values. The quantized model will be saved in TensorFlow Lite or QDQ Onnx formats respectively.
- `quantization_type` - *String*, only option is "PTQ", i.e., "Post-Training Quantization".
- `quantization_input_type` - *String*, can be "int8", "uint8" or "float", represents the quantization type for the model input.
- `quantization_output_type` - *String*, can be "int8", "uint8" or "float", represents the quantization type for the model output.
- `granularity` - *String*, can be "per_tensor" or "per_channel", defines the quantization granularity.
- `optimize` - *Boolean*, can be either True or False, controls whether the user wants to optimize the model before attempting to quantize it. Only used when "TFlite_converter" is used.
- `target_opset` - *Integer*, the target opset for the ONNX models, only used when "Onnx_quantizer" is used.
- `export_dir` - *String*, refers to the directory name to save the quantized model.
- `extra_options` - *String*, only option supported for now is "calib_moving_average" and only applies to ONNX quantization. This field is optional.

Please note that whatever the values set in `quantization_input_type` and `quantization_output_type`, the ONNX QDQ model generated at this stage has always a floating-point input and output.

</details>

<details open><summary><a href="#1-4">1.4 Random quantization</a></summary><a id="1-4"></a>

When no path is specified in `quantization_path` or `training_path`, the model is quantized after calibration on random data. There is no interest in evaluating the accuracy in this case. However, this random quantization can be useful to quickly estimate the model footprints on a target after quantization. We will see how to proceed in the next section.

</details>

<details open><summary><a href="#1-5">1.5 Hydra and MLflow settings</a></summary><a id="1-5"></a>

The `mlflow` and `hydra` sections must always be present in the YAML configuration file. The `hydra` section can be used to specify the name of the directory where experiment directories are saved and/or the pattern used to name experiment directories. With the YAML code below, every time you run the Model Zoo, an experiment directory is created that contains all the directories and files created during the run. The names of experiment directories are all unique as they are based on the date and time of the run.

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

</details>
</ul>
</details>

<details open>
<summary><a href="#2"><b>2. Quantize your model</b></a></summary><a id="2"></a>

To launch your model quantization using a real dataset, run the following command from the **src/** folder:

```bash
python stm32ai_main.py --config-path ./config_file_examples/ --config-name quantization_config.yaml
```
The quantized TensorFlow Lite model can be found in the corresponding **experiments_outputs/** folder.



In case you want to evaluate the accuracy of the quantized model, you can either launch the evaluation operation mode on the generated quantized model (please refer to the evaluation **[README.md](../evaluation/README.md)** that describes in detail how to proceed) or you can use chained services like launching the [chain_eqe](../config_file_examples/chain_eqe_config.yaml) example with the command below:

```bash
python stm32ai_main.py --config-path ./config_file_examples/ --config-name chain_eqe_config.yaml
```

In case you want to evaluate your quantized model footprints, you can either launch the benchmark operation mode on the generated quantized model (please refer to the benchmarking **[README.md](../benchmarking/README.md)** that describes in detail how to proceed) or you can use chained services like launching the [chain_qb](../config_file_examples/chain_qb_config.yaml) example with the command below:

```bash
python stm32ai_main.py --config-path ./config_file_examples/ --config-name chain_qb_config.yaml
```
Chained services work whether you specify a quantization dataset or not (random quantization).

</details>
