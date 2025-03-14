 /**
 ******************************************************************************
 * @file    main.h
 * @author  GPM Application Team
 *
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
#ifndef MAIN_H
#define MAIN_H

/* Includes ------------------------------------------------------------------*/
#include "stm32n6xx_hal.h"
#include "stm32_lcd.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
#define CIRCLE_RADIUS 5
/* Must be odd */
#define BINDING_WIDTH 3
#define COLOR_HEAD UTIL_LCD_COLOR_GREEN
#define COLOR_ARMS UTIL_LCD_COLOR_BLUE
#define COLOR_TRUNK UTIL_LCD_COLOR_MAGENTA
#define COLOR_LEGS UTIL_LCD_COLOR_ORANGE
#define COLOR_BOX UTIL_LCD_COLOR_RED

/* Exported functions ------------------------------------------------------- */

#endif /* MAIN_H */
