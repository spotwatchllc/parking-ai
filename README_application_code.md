# __Getting Started Application Code__

This package provides STM32 real-time applications to execute [STEdgeAI](https://www.st.com/en/development-tools/stedgeai-core.html) generated models targeting different use cases.
Applications are made to be used in a standalone way. But can be as well used in the [ModelZoo](https://github.com/STMicroelectronics/stm32ai-modelzoo-services).

The provided applications are:

- [Image classification](image_classification/STM32N6/README.md)
- [Object detection](object_detection/STM32N6/README.md)
- [Pose estimation](pose_estimation/STM32N6/README.md)
- [Instance segmentation](instance_segmentation/STM32N6/README.md)
- [Semantic segmentation](semantic_segmentation/STM32N6/README.md)
- [Audio](audio/STM32N6/README.md)

You can use the [ST ModelZoo repo](https://github.com/STMicroelectronics/stm32ai-modelzoo-services) to deploy the use cases on STM32N6. This package is needed by the ModelZoo for STM32N6 Target. The ModelZoo allows you to train, evaluate and deploy automatically any supported model. If you wish to use it as part of the ModelZoo, please refer to the [ModelZoo README](https://github.com/STMicroelectronics/stm32ai-modelzoo-services/blob/main/README.md) on how to use it.
