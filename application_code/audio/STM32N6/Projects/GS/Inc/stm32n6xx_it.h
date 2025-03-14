/**
  ******************************************************************************
  * @file    HAL/Inc/hal_generic_valid_it.h 
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    25-November-2024
  * @brief   This file contains the headers of the interrupt handlers.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef HAL_GENERIC_VALID_IT_H
#define HAL_GENERIC_VALID_IT_H

#ifdef __cplusplus
 extern "C" {
#endif 

/* Includes ------------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

void NMI_Handler(void);
void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
void SecureFault_Handler(void);
void SVC_Handler(void);
void DebugMon_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);
void GPDMA1_Channel2_IRQHandler(void);
void GPDMA1_Channel0_IRQHandler(void);
void EXTI13_IRQHandler(void);

#ifdef __cplusplus
}
#endif

#endif /* HAL_GENERIC_VALID_IT_H */

