#!/bin/bash

stedgeai generate --model st_movenet_lightning_heatmaps_192_int8_pc.tflite --target stm32n6 --st-neural-art default@user_neuralart.json
cp st_ai_output/network.c .
cp st_ai_output/network_ecblobs.h .
cp st_ai_output/network_atonbuf.xSPI2.raw network_data.xSPI2.bin
arm-none-eabi-objcopy -I binary network_data.xSPI2.bin --change-addresses 0x70380000 -O ihex network_data.hex