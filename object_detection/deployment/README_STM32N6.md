# Object Detection STM32N6 Model Deployment

This tutorial demonstrates how to deploy a pre-trained object detection model built with quantized tflite or ONNX QDQ on an STM32N6 board using STEdgeAI.

## Table of contents

<details open><summary><a href="#1"><b>1. Before you start</b></a></summary><a id="1"></a>

<ul><details open><summary><a href="#1-1">1.1 Hardware Setup</a></summary><a id="1-1"></a>

The [application code](../../application_code/object_detection/STM32N6/README_ModelZoo.md) runs with:

- [STM32N6570-DK](https://www.st.com/en/evaluation-tools/stm32n6570-dk.html) discovery board

- And one of the following camera modules:
  - MB1854 IMX335 camera module (provided with STM32N6570-DK board)
  - [STEVAL-55G1MBI](https://www.st.com/en/evaluation-tools/steval-55g1mbi.html)
  - [STEVAL-66GYMAI1](https://www.st.com/en/evaluation-tools/steval-66gymai.html)

__Note__: Camera detected automatically by the firmware, no config required.

</details></ul>
<ul><details open><summary><a href="#1-2">1.2 Software requirements</a></summary><a id="1-2"></a>

1. [STEdgeAI](https://www.st.com/en/development-tools/stedgeai-core.html) to generate network C code from tflite/onnx model.
2. [STM32CubeIDE](https://www.st.com/en/development-tools/stm32cubeide.html) to build the embedded project.
3. [STM32N6 Getting Started V1.0.0](https://www.st.com/en/development-tools/stm32n6-ai.html) the C firmware source code.

__Warning__: The [STM32 developer cloud](https://stedgeai-dc.st.com/home) to access the STM32Cube.AI functionalities is not usable through the ModelZoo on STM32N6 yet. You need to install Cube.AI on your computer to deploy the model on STM32N6.

</details></ul>
<ul><details open><summary><a href="#1-3">1.3 How to extract STM32N6 Getting Started into Model Zoo</a></summary><a id="1-3"></a>

1. Download the STM32N6_GettingStarted software package from the [ST website](https://www.st.com/en/development-tools/stm32n6-ai.html).
2. Unzip it.
3. Copy/Paste `STM32N6_GettingStarted_V1.0.0/application_code` folder into `model_zoo_services/` (Model Zoo root directory).

</details></ul>
</details>
<details open><summary><a href="#2"><b>2. Configuration file</b></a></summary><a id="2"></a>

To deploy your model, you need to fill a YAML configuration file with your tools and model info, and then launch `stm32ai_main.py`.

As an example, we will show how to deploy [ssd_mobilenet_v2_fpnlite_035_192_int8.tflite](https://github.com/STMicroelectronics/stm32ai-modelzoo/tree/master/object_detection/ssd_mobilenet_v2_fpnlite/ST_pretrainedmodel_public_dataset/coco_2017_person/ssd_mobilenet_v2_fpnlite_035_192) pre-trained on the COCO 2017 person dataset using the necessary parameters provided in [ssd_mobilenet_v2_fpnlite_035_192_config.yaml](https://github.com/STMicroelectronics/stm32ai-modelzoo/blob/master/object_detection/ssd_mobilenet_v2_fpnlite/ST_pretrainedmodel_public_dataset/coco_2017_person/ssd_mobilenet_v2_fpnlite_035_192/ssd_mobilenet_v2_fpnlite_035_192_config.yaml). To get this model, clone the [ModelZoo repo](https://github.com/STMicroelectronics/stm32ai-modelzoo/) in the same folder you cloned the [STM32 ModelZoo services repo](https://github.com/STMicroelectronics/stm32ai-modelzoo-services/).

To configure the deployment, edit [`../src/config_file_examples/deployment_n6_ssd_mobilenet_v2_fpnlite_config.yaml`](../src/config_file_examples/deployment_n6_ssd_mobilenet_v2_fpnlite_config.yaml).

<ul><details open><summary><a href="#2-1">2.1 Setting the Model and the Operation Mode</a></summary><a id="2-1"></a>

```yaml
general:
  model_type: ssd_mobilenet_v2_fpnlite # 'st_ssd_mobilenet_v1', 'ssd_mobilenet_v2_fpnlite', 'tiny_yolo_v2', 'st_yolo_lc_v1', 'st_yolo_x', 'yolo_v8'
  # path to a `.tflite` or `.onnx` file.
  model_path: ../../../stm32ai-modelzoo/object_detection/ssd_mobilenet_v2_fpnlite/ST_pretrainedmodel_public_dataset/coco_2017_person/ssd_mobilenet_v2_fpnlite_035_192/ssd_mobilenet_v2_fpnlite_035_192_int8.tflite
```

Configure the __operation_mode__ section as follow:

```yaml
operation_mode: deployment
```

</details></ul>
<ul><details open><summary><a href="#2-2">2.2 Dataset configuration</a></summary><a id="2-2"></a>

<ul><details open><summary><a href="#2-2-1">2.2.1 Dataset info</a></summary><a id="2-2-1"></a>

Configure the __dataset__ section in the YAML file as follows:

```yaml
dataset:
  name: coco_2017_person
  class_names: [person]
```

</details></ul>
<ul><details open><summary><a href="#2-2-2">2.2.2 Preprocessing info</a></summary><a id="2-2-2"></a>

```yaml
preprocessing:
  resizing:
    interpolation: bilinear
    aspect_ratio: crop
  color_mode: rgb # rgb, bgr
```

- `aspect_ratio`:
  - `crop`: Crop both pipes to nn input aspect ratio; Original aspect ratio kept
  - `full_screen` Resize camera image to NN input size and display a fullscreen image
  - `fit`: Resize both pipe to NN input aspect ratio; Original aspect ratio not kept
- `color_mode`:
  - `rgb`
  - `bgr`

</details></ul>
<ul><details open><summary><a href="#2-2-3">2.2.3 Post processing info</a></summary><a id="2-2-3"></a>

The --use case--- models usually have a post processing to be applied to filter the model output and show final results on an image.
Post processing parameters can be configured.

```yaml
postprocessing:
  confidence_thresh: 0.6
  NMS_thresh: 0.5
  IoU_eval_thresh: 0.4
  yolo_anchors: # Only applicable for YoloV2
  max_detection_boxes: 10
```

- `confidence_thresh` - A *float* between 0.0 and 1.0, the score thresh to filter detections.
- `NMS_thresh` - A *float* between 0.0 and 1.0, NMS thresh to filter and reduce overlapped boxes.
- `max_detection_boxes` - An *int* to filter the number of bounding boxes. __Warning__: The higher the number, the more memory is used. Our models are validated with 10 boxes.

</details></ul>
</details></ul>
<ul><details open><summary><a href="#2-3">2.3 Deployment parameters</a></summary><a id="2-3"></a>

To deploy the model in __STM32N6570-DK__ board, you will use:

1. *STEdgeAI* to convert the model into optimized C code
2. *STM32CubeIDE* to build the C application and flash the board.

These steps will be done automatically by configuring the __tools__ and __deployment__ sections in the YAML file as the following:

```yaml
tools:
  stedgeai:
    version: 10.0.0
    optimization: balanced
    on_cloud: False # Not Available For STM32N6
    path_to_stedgeai: C:/Users/<XXXXX>/STM32Cube/Repository/Packs/STMicroelectronics/X-CUBE-AI/<*.*.*>/Utilities/windows/stedgeai.exe
  path_to_cubeIDE: C:/ST/STM32CubeIDE_<*.*.*>/STM32CubeIDE/stm32cubeide.exe

deployment:
  c_project_path: ../../application_code/object_detection/STM32N6/
  IDE: GCC
  verbosity: 1
  hardware_setup:
    serie: STM32N6
    board: STM32N6570-DK
```

- `tools/stedgeai`
  - `version` - Specify the __STM32Cube.AI__ version used to benchmark the model, e.g. __10.0.0__.
  - `optimization` - *String*, define the optimization used to generate the C model, options: "*balanced*", "*time*", "*ram*".
  - `on_cloud` - *Boolean*, False. Not Available on STM32N6
  - `path_to_stedgeai` - *Path* to stedgeai executable file to use local download, else __False__.
- `tools/path_to_cubeIDE` - *Path* to stm32cubeide executable file.
- `deployment`
  - `c_project_path` - *Path* to [application C code](../../application_code/object_detection/STM32N6/README.md) project.
  - `IDE` -__GCC__, only supported option for *stm32ai application code*.
  - `verbosity` - *0* or *1*. Mode 0 is silent, and mode 1 displays messages when building and flashing C application on STM32 target.
  - `serie` - __STM32N6__
  - `board` - __STM32N6570-DK__, see the [README](../../application_code/object_detection/STM32N6/README.md) for more details.

</details></ul>
<ul><details open><summary><a href="#2-4">2.4 Hydra and MLflow settings</a></summary><a id="2-4"></a>

The `mlflow` and `hydra` sections must always be present in the YAML configuration file. The `hydra` section can be used to specify the name of the directory where experiment directories are saved. This pattern allows creating a new experiment directory for each run.

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
<details open><summary><a href="#3"><b>3. Deployment</b></a></summary><a id="3"></a>

__1.__ Connect the CSI camera module to the *STM32N6570-DK* discovery board with a flat cable.

![plot](./doc/img/STM32N6570-DK_Camera.JPG)

__2.__ Connect the discovery board from the STLINK-V3EC USB-C port to your computer using an __USB-C to USB-C cable__.

__Warning__: using USB-A to USB-C cable may not work because of possible lack of power delivery.

![plot](./doc/img/STM32N6570-DK_USB.JPG)

__3.__ Set the switch BOOT0 to the right (dev mode) and disconnect/reconnect the power cable of your board.

__4.__ Once [`deployment_n6_ssd_mobilenet_v2_fpnlite_config.yaml`](../src/config_file_examples/deployment_n6_ssd_mobilenet_v2_fpnlite_config.yaml) filled, launch:

```bash
cd ../src/
python stm32ai_main.py --config-path ./config_file_examples/ --config-name deployment_n6_ssd_mobilenet_v2_fpnlite_config.yaml
```

__5.__ Once the application deployment complete, set both BOOT switches to the left (boot from flash) and disconnect/reconnect the power cable of your board.

__6.__ When the application is running on the *STM32N6570-DK* board, the LCD displays the following information:

- Data stream from camera board
- The inference time
- Bounding boxes with confidence score between 0 and 1
- The number of detected object

__Note__:
If you have a Keras model that has not been quantized and you want to quantize it before deploying it, you can use the `chain_qd` tool to quantize and deploy the model sequentially. To do this, update the [chain_qd_config.yaml](../src/config_file_examples/chain_qd_n6_config.yaml) file and then run the following command from the `src/` folder to build and flash the application on your board:

```bash
python stm32ai_main.py --config-path ./config_file_examples/ --config-name chain_qd_config.yaml
```


</details>
