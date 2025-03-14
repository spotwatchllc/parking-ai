/**
  ******************************************************************************
  * @file    pm_dvfs.h 
  * @author  GPM/AIS Application Team
  * @version V1.0.0
  * @date    25-November-2024
  * @brief   dvfs implementation
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

#ifndef __PM_DVFS_H__
#define __PM_DVFS_H__

#ifndef APP_BARE_METAL  
#include "tx_api.h"
#endif

#ifdef APP_DVFS 
typedef enum _opp_t {
  OPP_MIN = 0,
  OPP_MAX
} opp_t;

typedef struct _dvfs_ctx_t
{
#ifndef APP_BARE_METAL  
  TX_MUTEX lock;
#endif /* APP_BARE_METAL */
  opp_t opp;
  uint32_t cpu_freq;
  int32_t cnt;
}dvfs_ctx_t;
extern void pm_init_dvfs(void);
extern void pm_set_opp_min(opp_t opp); 
#endif /* APP_DVFS */

#endif /* __PM_DVFS_H__*/
