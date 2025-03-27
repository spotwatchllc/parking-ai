# Benchmarking of Instance Segmentation Model

The instance segmentation Model Benchmarking service is a powerful tool that enables users to evaluate the performance of their instance segmentation models built with TensorFlow Lite (.tflite), Keras (.h5), or ONNX (.onnx). With this service, users can easily upload their model and configure the settings to benchmark it and generate various metrics, including memory footprints and inference time. This can be achieved by utilizing the [STM32Cube.AI Developer Cloud](https://stedgeai-dc.st.com/home) to benchmark on different STM32 target devices or by using [STM32Cube.AI](https://www.st.com/en/embedded-software/x-cube-ai.html) to estimate the memory footprints.



<details open><summary><a href="#1"><b>1. Configure the YAML file</b></a></summary><a id="1"></a>

To use this service and achieve your goals, you can use the [user_config.yaml](../user_config.yaml) or directly update the [benchmarking_config.yaml](../config_file_examples/benchmarking_config.yaml) file and use it. This file provides an example of how to configure the benchmarking service to meet your specific needs.

Alternatively, you can follow the tutorial below, which shows how to benchmark your pre-trained instance segmentation model using our evaluation service.

<ul><details open><summary><a href="#1-1">1.1 Set the model and the operation mode</a></summary><a id="1-1"></a>

As mentioned previously, all the sections of the YAML file must be set in accordance with this **[README.md](../config_file_examples/benchmarking_config.yaml)**.
In particular, `operation_mode` should be set to evaluation and the `benchmarking` section should be filled as in the following example: 

```yaml
general:
  project_name: coco_instance_seg
  model_type: yolo_v8_seg
  model_path: https://github.com/stm32-hotspot/ultralytics/raw/refs/heads/main/examples/YOLOv8-STEdgeAI/stedgeai_models/segmentation/yolov8n_256_quant_pc_uf_seg_coco-st.tflite

operation_mode: benchmarking
```

</details></ul>
<ul><details open><summary><a href="#1-2">1.2 Set benchmarking tools and parameters</a></summary><a id="1-2"></a>

The [STM32Cube.AI Developer Cloud](https://stedgeai-dc.st.com/home) allows you to benchmark your model and estimate its footprints and inference time for different STM32 target devices. To use this feature, set the `on_cloud` attribute to True. Alternatively, you can use [STM32Cube.AI](https://www.st.com/en/embedded-software/x-cube-ai.html) to benchmark your model and estimate its footprints for STM32 target devices locally. To do this, make sure to add the path to the `stedgeai` executable under the `path_to_stedgeai` attribute and set the `on_cloud` attribute to False.

The `version` attribute specifies the **STM32Cube.AI** version used to benchmark the model, e.g., 10.0.0, and the `optimization` defines the optimization used to generate the C model, options: "balanced", "time", "ram".

The `board` attribute is used to provide the name of the STM32 board to benchmark the model on. The available boards are 'STM32N6570-DK', 'STM32H747I-DISCO', 'STM32H7B3I-DK', 'STM32F469I-DISCO', 'B-U585I-IOT02A', 'STM32L4R9I-DISCO', 'NUCLEO-H743ZI2', 'STM32H735G-DK', 'STM32F769I-DISCO', 'NUCLEO-G474RE', 'NUCLEO-F401RE', and 'STM32F746G-DISCO'.

```yaml
tools:
  stedgeai:
    version: 10.0.0
    optimization: balanced
    on_cloud: True
    path_to_stedgeai: C:/Users/<XXXXX>/STM32Cube/Repository/Packs/STMicroelectronics/X-CUBE-AI/<*.*.*>/Utilities/windows/stedgeai.exe
  path_to_cubeIDE: C:/ST/STM32CubeIDE_<*.*.*>/STM32CubeIDE/stm32cubeide.exe

benchmarking:
   board:   STM32MP257F-EV1    # Name of the STM32 board to benchmark the model on
```

</details></ul>
<ul><details open><summary><a href="#1-3">1.3 Hydra and MLflow settings</a></summary><a id="1-3"></a>

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

</details></ul>
</details>
<details open><summary><a href="#2"><b>2. Benchmark your model</b></a></summary><a id="2"></a>

If you chose to modify the [user_config.yaml](../user_config.yaml) you can evaluate the model by running the following command from the **src/** folder:

```bash
python stm32ai_main.py
```
If you chose to update the [benchmarking_config.yaml](../config_file_examples/benchmarking_config.yaml) and use it then run the following command from the **src/** folder: 

```bash
python stm32ai_main.py --config-path ./config_file_examples/ --config-name benchmarking_config.yaml
```
Note that you can provide YAML attributes as arguments in the command, as shown below:

```bash
python stm32ai_main.py operation_mode='benchmarking'
```

</details>
<details open><summary><a href="#3"><b>3. Visualize benchmark results</b></a></summary><a id="3"></a>

To view the detailed benchmarking results, you can access the log file `stm32ai_main.log` located in the directory `experiments_outputs/<date-and-time>`. Additionally, you can navigate to the `experiments_outputs` directory and use the MLflow Webapp to view the metrics saved for each trial or launch. To access the MLflow Webapp, run the following command:

```bash
mlflow ui
``` 

This will open a browser window where you can view the metrics and results of your benchmarking trials.

</details>
