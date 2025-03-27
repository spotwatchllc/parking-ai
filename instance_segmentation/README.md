# Instance segmentation STM32 model zoo

## Directory Components:
* [datasets](datasets/README.md) placeholder for the instance segmentation datasets.
* [deployment](deployment/README_STM32N6.md) contains the necessary files for the deployment service.
* [pretrained_models ](pretrained_models/README.md) points on a collection of optimized pretrained models
  detection use cases.
* [src](src/README.md) contains tools to do predictions or benchmark your model on your STM32 target.

## Quick & easy examples:
The `operation_mode` top-level attribute specifies the operations or the service you want to execute. This may be single operation or a set of chained operations.

You can refer to readme links below that provide typical examples of operation modes, and tutorials on specific services:

   - [benchmarking](./src/benchmarking/README.md)
   - [prediction](./src/prediction/README.md)
   - [deployment](./deployment/README_STM32N6.md)

All .yaml configuration examples are located in [config_file_examples](./src/config_file_examples/) folder.

The different values of the `operation_mode` attribute and the corresponding operations are described in the table below:

| operation_mode attribute | Operations |
|:---------------------------|:-----------|
| `prediction`   | Predict the classes some images belong to using a float or quantized model |
| `benchmarking` | Benchmark a float or quantized model on an STM32 board |
| `deployment`   | Deploy a model on an STM32 board |

The `model_type` attributes currently supported for the instance segmentation are:
- `yolo_v8_seg` : is an advanced instance segmentation model from Ultralytics that builds upon the strengths of its predecessors in the YOLO series. It is designed for real-time segmentation, offering high IoU and speed. It incorporates state-of-the-art techniques such as improved backbone networks, better feature pyramid networks, and advanced anchor-free detection heads, making it highly efficient for various computer vision tasks.


## You don't know where to start? You feel lost?
Don't forget to follow our tuto below for a quick ramp up : 
* [How can I deploy an Ultralytics Yolov8 instance segmentation model?](../instance_segmentation/deployment/doc/tuto/How_to_deploy_yolov8_instance_segmentation.md)

Remember that minimalistic yaml files are available [here](./src/config_file_examples/) to play with specific services, and that all pre-trained models in the [STM32 model zoo](https://github.com/STMicroelectronics/stm32ai-modelzoo/) are provided with their configuration .yaml file used to generate them. These are very good starting points to start playing with!

