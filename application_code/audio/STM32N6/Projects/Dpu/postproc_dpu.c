/**
  ******************************************************************************
  * @file    postproc_dpu.c
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    25-November-2024
  * @brief   This file is implementing post-processing functions that are making
  *          use of Audio post-processing libraries
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

/* Includes ------------------------------------------------------------------*/


#include "preproc_dpu.h"
#include "postproc_dpu.h"
#include "user_mel_tables.h"
#include "logging.h"
#include "mcu_cache.h"

/* Private define ------------------------------------------------------------*/
#define CPLX_SPECTRUM_LEN ((CTRL_X_CUBE_AI_SPECTROGRAM_NFFT/2 + 1) * 2 * CTRL_X_CUBE_AI_SPECTROGRAM_COL)
#define SPECTRUM_MASK_LEN ((CTRL_X_CUBE_AI_SPECTROGRAM_NFFT/2 + 1) * CTRL_X_CUBE_AI_SPECTROGRAM_COL)
/* Private variables ---------------------------------------------------------*/

/**
  * @brief  Initializes the post processing DPU
  * @param  pCtx pointer to post processing context
  * @retval 0 if success
  */
int PostProc_DPUInit(AudioPostProcCtx_t *pCtx)
{
#if (CTRL_X_CUBE_AI_POSTPROC==CTRL_AI_ISTFT)
	  assert_param(CTRL_X_CUBE_AI_SPECTROGRAM_NFFT >= CTRL_X_CUBE_AI_SPECTROGRAM_WINDOW_LENGTH );
	  uint32_t pad = CTRL_X_CUBE_AI_SPECTROGRAM_NFFT - CTRL_X_CUBE_AI_SPECTROGRAM_WINDOW_LENGTH;

	  PostProc_rfft_init(&pCtx->S_iRfft, CTRL_X_CUBE_AI_SPECTROGRAM_NFFT);

	  /* Init FFT */
	  pCtx->S_iSTFT.pRfft                       = &pCtx->S_iRfft;
	  pCtx->S_iSTFT.FFTLen                      = CTRL_X_CUBE_AI_SPECTROGRAM_NFFT;
	  pCtx->S_iSTFT.pScratch                    = pCtx->pSpectrScratchBuffer1;
	  pCtx->S_iSTFT.pWindow                     = (POSTPROC_FLOAT_T *) CTRL_X_CUBE_AI_SPECTROGRAM_WIN;
	  pCtx->S_iSTFT.sDin.FrameLen               = CTRL_X_CUBE_AI_SPECTROGRAM_WINDOW_LENGTH;
	  pCtx->S_iSTFT.sDin.pad_left               = pad/2;
	  pCtx->S_iSTFT.sDin.pad_right              = (pad+1)/2;

	  pCtx->S_iSTFT_b.pFFT                      = &pCtx->S_iSTFT ;
 	  pCtx->S_iSTFT_b.pScratch                  = pCtx->pSpectrScratchBuffer2;
	  pCtx->S_iSTFT_b.pWeightsWindow            = pCtx->pSpectrScratchBuffer3;
	  pCtx->S_iSTFT_b.pScratchOut               = pCtx->pSpectrScratchBuffer4;
	  pCtx->S_iSTFT_b.hop_length                = CTRL_X_CUBE_AI_SPECTROGRAM_HOP_LENGTH;
	  pCtx->S_iSTFT_b.nb_frames                 = CTRL_X_CUBE_AI_SPECTROGRAM_COL;
	  pCtx->S_iSTFT_b.idxPos                    = 0;
	  pCtx->S_iSTFT_b.transposeMask             = E_SPECTROGRAM_TRANSPOSE; // or E_SPECTROGRAM_TRANSPOSE_NO
	  pCtx->S_iSTFT_b.transposeSigIn            = E_SPECTROGRAM_CPLX_FFT_TRANSPOSE; // or E_SPECTROGRAM_CPLX_FFT
#endif
  return 0;
}

/**
  * @brief  run post processing DPU
  * @param  pxCtx pointer to post processing context
  * @param  pDataIn pointer to complex spectrum of audio samples patch
  * @param  pSpecMask pointer to complex spectrum mask to apply
  * @param  pAudioOut pointer output audio samples
  * @retval 0 if success
  */
int PostProc_DPU(AudioPostProcCtx_t *pxCtx, PREPROC_FLOAT_T *pDataIn, float32_t *pSpecMask, int16_t *pAudioOut)
{
  assert_param(pxCtx != NULL);
  assert_param (pDataIn != NULL);
  assert_param (pSpecMask != NULL);
  assert_param (pAudioOut != NULL);

#if (CTRL_X_CUBE_AI_POSTPROC==CTRL_AI_ISTFT)
  POSTPROC_FLOAT_T * pMaskPostIn = (POSTPROC_FLOAT_T *) pSpecMask;

  ARM_PMU_CYCCNT_Reset();

  for (int i = 0 ; i < SPECTRUM_MASK_LEN; i ++ )
  {
    pMaskPostIn[i] = (POSTPROC_FLOAT_T) pSpecMask[i];
  }

  audio_iCplxFFTos16(pDataIn, pMaskPostIn, &pxCtx->S_iSTFT_b, &pAudioOut);

  mcu_cache_clean_invalidate_range((uint32_t)pSpecMask,(uint32_t)(pSpecMask+\
                                                          SPECTRUM_MASK_LEN )) ;
  uint64_t cycles = ARM_PMU_Get_CCNTR();
  uint32_t t_us = (cycles * 1000 * 1000) / HAL_RCC_GetCpuClockFreq();
  LogDebug("F16 postproc %d us (%d cycles)\r\n", t_us,(uint32_t)cycles);
#endif /* (CTRL_X_CUBE_AI_POSTPROC==CTRL_AI_ISTFT) */

  return 0;
}
