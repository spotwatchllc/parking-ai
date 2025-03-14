#ifndef ATON_H
#define ATON_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdint.h>
#include <string.h>


/* ********************************************************************************************************************************************************** */
/*                                                                                                                                                            */
/*                                                                       HELPER MACROS                                                                        */
/*                                                                                                                                                            */
/* ********************************************************************************************************************************************************** */

/** Mask for retrieving the content of a field of a register. */
#define ATON_FIELD_MASK(OFFSET, SIZE)  ((uint32_t)(((1ULL << (SIZE)) - 1ULL) << (OFFSET)))

/** Get the content of a field of a register. */
#define ATON_GET_FIELD(REG, OFFSET, SIZE)  (((REG) & ATON_FIELD_MASK((OFFSET), (SIZE))) >> (OFFSET))

/** Set the content of a field of a register. */
#define ATON_SET_FIELD(REG, OFFSET, SIZE, DATA)  (((REG) & (~ATON_FIELD_MASK((OFFSET), (SIZE)))) | (((DATA) << (OFFSET)) & ATON_FIELD_MASK((OFFSET), (SIZE))))


/* ********************************************************************************************************************************************************** */
/*                                                                                                                                                            */
/*                                                                     ENUMERATED VALUES                                                                      */
/*                                                                                                                                                            */
/* ********************************************************************************************************************************************************** */

/* ---------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                                                                                                                            */
/*                                                             ACTIVTYPE set of enumerated values                                                             */
/*                                                                                                                                                            */
/* ---------------------------------------------------------------------------------------------------------------------------------------------------------- */

/** Activation type: ReLU. */
#define ATON_ACTIVTYPE_RELU (0x0UL)

/** Activation type: Parametric ReLU. */
#define ATON_ACTIVTYPE_PRELU (0x1UL)

/** Activation type: Thresholded ReLU. */
#define ATON_ACTIVTYPE_TRELU (0x2UL)

/** Activation type: Function evaluator. */
#define ATON_ACTIVTYPE_FUNCTION (0x3UL)


/** Get the name of one of the values of the ACTIVTYPE set of enumerated values. */
#define ATON_ACTIVTYPE_GET_NAME(VALUE) \
  (((VALUE) == 0UL) ? "RELU" : \
  (((VALUE) == 1UL) ? "PRELU" : \
  (((VALUE) == 2UL) ? "TRELU" : \
  (((VALUE) == 3UL) ? "FUNCTION" :  ""))))


/**
 * Check if a value of the ACTIVTYPE set of enumerated values is valid.
 *
 * \param[in] val is the numeric value that must be checked
 *
 * \retval \e true  if \e val is a valid value of the ACTIVTYPE set of enumerated values is valid
 * \retval \e false otherwise
 */

static inline bool ATON_ACTIVTYPE_IsValid(uint8_t val)
{
  bool retval = false;

  switch (val)
  {
    case ATON_ACTIVTYPE_RELU:
    case ATON_ACTIVTYPE_PRELU:
    case ATON_ACTIVTYPE_TRELU:
    case ATON_ACTIVTYPE_FUNCTION:
      retval = true;
      break;

    default:
      break;
  }

  return retval;
}


/**
 * Get the name of one of the values of the ACTIVTYPE set of enumerated values.
 *
 * \param[in] val is the numeric value whose name must be returned
 *
 * \return the name of value \e val of the ACTIVTYPE set of enumerated values
 */

static inline const int8_t *ATON_ACTIVTYPE_GetName(uint8_t val)
{
  const int8_t *str = NULL;

  switch (val)
  {
    case ATON_ACTIVTYPE_RELU:
      str = (const int8_t *)"RELU";
      break;

    case ATON_ACTIVTYPE_PRELU:
      str = (const int8_t *)"PRELU";
      break;

    case ATON_ACTIVTYPE_TRELU:
      str = (const int8_t *)"TRELU";
      break;

    case ATON_ACTIVTYPE_FUNCTION:
      str = (const int8_t *)"FUNCTION";
      break;

    default:
      break;
  }

  return str;
}


/**
 * Get the description of one of the values of the ACTIVTYPE set of enumerated values.
 *
 * \param[in] val is the numeric value whose description must be returned
 *
 * \return the description of value \e val of the ACTIVTYPE set of enumerated values
 */

static inline const int8_t *ATON_ACTIVTYPE_GetDesc(uint8_t val)
{
  const int8_t *str = NULL;

  switch (val)
  {
    case ATON_ACTIVTYPE_RELU:
      str = (const int8_t *)"ReLU";
      break;

    case ATON_ACTIVTYPE_PRELU:
      str = (const int8_t *)"Parametric ReLU";
      break;

    case ATON_ACTIVTYPE_TRELU:
      str = (const int8_t *)"Thresholded ReLU";
      break;

    case ATON_ACTIVTYPE_FUNCTION:
      str = (const int8_t *)"Function evaluator";
      break;

    default:
      break;
  }

  return str;
}


/* ---------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                                                                                                                            */
/*                                                             ACTIV_ROM set of enumerated values                                                             */
/*                                                                                                                                                            */
/* ---------------------------------------------------------------------------------------------------------------------------------------------------------- */

/** Activation unit ROM offsets: Activation unit ROM 0 offset. */
#define ATON_ACTIV_ROM_OFFSET_0 (0x400UL)

/** Activation unit ROM offsets: Activation unit ROM 1 offset. */
#define ATON_ACTIV_ROM_OFFSET_1 (0x800UL)


/** Get the name of one of the values of the ACTIV_ROM set of enumerated values. */
#define ATON_ACTIV_ROM_GET_NAME(VALUE) \
  (((VALUE) == 1024UL) ? "OFFSET_0" : \
  (((VALUE) == 2048UL) ? "OFFSET_1" :  ""))


/**
 * Check if a value of the ACTIV_ROM set of enumerated values is valid.
 *
 * \param[in] val is the numeric value that must be checked
 *
 * \retval \e true  if \e val is a valid value of the ACTIV_ROM set of enumerated values is valid
 * \retval \e false otherwise
 */

static inline bool ATON_ACTIV_ROM_IsValid(uint32_t val)
{
  bool retval = false;

  switch (val)
  {
    case ATON_ACTIV_ROM_OFFSET_0:
    case ATON_ACTIV_ROM_OFFSET_1:
      retval = true;
      break;

    default:
      break;
  }

  return retval;
}


/**
 * Get the name of one of the values of the ACTIV_ROM set of enumerated values.
 *
 * \param[in] val is the numeric value whose name must be returned
 *
 * \return the name of value \e val of the ACTIV_ROM set of enumerated values
 */

static inline const int8_t *ATON_ACTIV_ROM_GetName(uint32_t val)
{
  const int8_t *str = NULL;

  switch (val)
  {
    case ATON_ACTIV_ROM_OFFSET_0:
      str = (const int8_t *)"OFFSET_0";
      break;

    case ATON_ACTIV_ROM_OFFSET_1:
      str = (const int8_t *)"OFFSET_1";
      break;

    default:
      break;
  }

  return str;
}


/**
 * Get the description of one of the values of the ACTIV_ROM set of enumerated values.
 *
 * \param[in] val is the numeric value whose description must be returned
 *
 * \return the description of value \e val of the ACTIV_ROM set of enumerated values
 */

static inline const int8_t *ATON_ACTIV_ROM_GetDesc(uint32_t val)
{
  const int8_t *str = NULL;

  switch (val)
  {
    case ATON_ACTIV_ROM_OFFSET_0:
      str = (const int8_t *)"Activation unit ROM 0 offset";
      break;

    case ATON_ACTIV_ROM_OFFSET_1:
      str = (const int8_t *)"Activation unit ROM 1 offset";
      break;

    default:
      break;
  }

  return str;
}


/* ---------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                                                                                                                            */
/*                                                              ARITHOP set of enumerated values                                                              */
/*                                                                                                                                                            */
/* ---------------------------------------------------------------------------------------------------------------------------------------------------------- */

/** Arithmetic operation: Ax + By + C. */
#define ATON_ARITHOP_AX_BY_C (0x0UL)

/** Arithmetic operation: min(X,Y). */
#define ATON_ARITHOP_MIN_X_Y (0x1UL)

/** Arithmetic operation: max(X,Y). */
#define ATON_ARITHOP_MAX_X_Y (0x2UL)

/** Arithmetic operation: X*Y. */
#define ATON_ARITHOP_XY (0x7UL)

/** Arithmetic operation: X&Y. */
#define ATON_ARITHOP_X_AND_Y (0xbUL)

/** Arithmetic operation: X|Y. */
#define ATON_ARITHOP_X_OR_Y (0xfUL)

/** Arithmetic operation: !X. */
#define ATON_ARITHOP_NOT_X (0x13UL)

/** Arithmetic operation: X^Y. */
#define ATON_ARITHOP_X_XOR_Y (0x17UL)

/** Arithmetic operation: X==Y. */
#define ATON_ARITHOP_X_EQ_Y (0x1bUL)

/** Arithmetic operation: X<Y. */
#define ATON_ARITHOP_X_LT_Y (0x1fUL)

/** Arithmetic operation: X<=Y. */
#define ATON_ARITHOP_X_LE_Y (0x23UL)

/** Arithmetic operation: X>Y. */
#define ATON_ARITHOP_X_GT_Y (0x27UL)

/** Arithmetic operation: X>=Y. */
#define ATON_ARITHOP_X_GE_Y (0x2bUL)

/** Arithmetic operation: ABS(X). */
#define ATON_ARITHOP_ABS_X (0x2fUL)

/** Arithmetic operation: SIGN(X). */
#define ATON_ARITHOP_SIGN_X (0x33UL)

/** Arithmetic operation: CLIP. */
#define ATON_ARITHOP_CLIP (0x37UL)


/** Get the name of one of the values of the ARITHOP set of enumerated values. */
#define ATON_ARITHOP_GET_NAME(VALUE) \
  (((VALUE) == 0UL) ? "AX_BY_C" : \
  (((VALUE) == 1UL) ? "MIN_X_Y" : \
  (((VALUE) == 2UL) ? "MAX_X_Y" : \
  (((VALUE) == 7UL) ? "XY" : \
  (((VALUE) == 11UL) ? "X_AND_Y" : \
  (((VALUE) == 15UL) ? "X_OR_Y" : \
  (((VALUE) == 19UL) ? "NOT_X" : \
  (((VALUE) == 23UL) ? "X_XOR_Y" : \
  (((VALUE) == 27UL) ? "X_EQ_Y" : \
  (((VALUE) == 31UL) ? "X_LT_Y" : \
  (((VALUE) == 35UL) ? "X_LE_Y" : \
  (((VALUE) == 39UL) ? "X_GT_Y" : \
  (((VALUE) == 43UL) ? "X_GE_Y" : \
  (((VALUE) == 47UL) ? "ABS_X" : \
  (((VALUE) == 51UL) ? "SIGN_X" : \
  (((VALUE) == 55UL) ? "CLIP" :  ""))))))))))))))))


/**
 * Check if a value of the ARITHOP set of enumerated values is valid.
 *
 * \param[in] val is the numeric value that must be checked
 *
 * \retval \e true  if \e val is a valid value of the ARITHOP set of enumerated values is valid
 * \retval \e false otherwise
 */

static inline bool ATON_ARITHOP_IsValid(uint8_t val)
{
  bool retval = false;

  switch (val)
  {
    case ATON_ARITHOP_AX_BY_C:
    case ATON_ARITHOP_MIN_X_Y:
    case ATON_ARITHOP_MAX_X_Y:
    case ATON_ARITHOP_XY:
    case ATON_ARITHOP_X_AND_Y:
    case ATON_ARITHOP_X_OR_Y:
    case ATON_ARITHOP_NOT_X:
    case ATON_ARITHOP_X_XOR_Y:
    case ATON_ARITHOP_X_EQ_Y:
    case ATON_ARITHOP_X_LT_Y:
    case ATON_ARITHOP_X_LE_Y:
    case ATON_ARITHOP_X_GT_Y:
    case ATON_ARITHOP_X_GE_Y:
    case ATON_ARITHOP_ABS_X:
    case ATON_ARITHOP_SIGN_X:
    case ATON_ARITHOP_CLIP:
      retval = true;
      break;

    default:
      break;
  }

  return retval;
}


/**
 * Get the name of one of the values of the ARITHOP set of enumerated values.
 *
 * \param[in] val is the numeric value whose name must be returned
 *
 * \return the name of value \e val of the ARITHOP set of enumerated values
 */

static inline const int8_t *ATON_ARITHOP_GetName(uint8_t val)
{
  const int8_t *str = NULL;

  switch (val)
  {
    case ATON_ARITHOP_AX_BY_C:
      str = (const int8_t *)"AX_BY_C";
      break;

    case ATON_ARITHOP_MIN_X_Y:
      str = (const int8_t *)"MIN_X_Y";
      break;

    case ATON_ARITHOP_MAX_X_Y:
      str = (const int8_t *)"MAX_X_Y";
      break;

    case ATON_ARITHOP_XY:
      str = (const int8_t *)"XY";
      break;

    case ATON_ARITHOP_X_AND_Y:
      str = (const int8_t *)"X_AND_Y";
      break;

    case ATON_ARITHOP_X_OR_Y:
      str = (const int8_t *)"X_OR_Y";
      break;

    case ATON_ARITHOP_NOT_X:
      str = (const int8_t *)"NOT_X";
      break;

    case ATON_ARITHOP_X_XOR_Y:
      str = (const int8_t *)"X_XOR_Y";
      break;

    case ATON_ARITHOP_X_EQ_Y:
      str = (const int8_t *)"X_EQ_Y";
      break;

    case ATON_ARITHOP_X_LT_Y:
      str = (const int8_t *)"X_LT_Y";
      break;

    case ATON_ARITHOP_X_LE_Y:
      str = (const int8_t *)"X_LE_Y";
      break;

    case ATON_ARITHOP_X_GT_Y:
      str = (const int8_t *)"X_GT_Y";
      break;

    case ATON_ARITHOP_X_GE_Y:
      str = (const int8_t *)"X_GE_Y";
      break;

    case ATON_ARITHOP_ABS_X:
      str = (const int8_t *)"ABS_X";
      break;

    case ATON_ARITHOP_SIGN_X:
      str = (const int8_t *)"SIGN_X";
      break;

    case ATON_ARITHOP_CLIP:
      str = (const int8_t *)"CLIP";
      break;

    default:
      break;
  }

  return str;
}


/**
 * Get the description of one of the values of the ARITHOP set of enumerated values.
 *
 * \param[in] val is the numeric value whose description must be returned
 *
 * \return the description of value \e val of the ARITHOP set of enumerated values
 */

static inline const int8_t *ATON_ARITHOP_GetDesc(uint8_t val)
{
  const int8_t *str = NULL;

  switch (val)
  {
    case ATON_ARITHOP_AX_BY_C:
      str = (const int8_t *)"Ax + By + C";
      break;

    case ATON_ARITHOP_MIN_X_Y:
      str = (const int8_t *)"min(X,Y)";
      break;

    case ATON_ARITHOP_MAX_X_Y:
      str = (const int8_t *)"max(X,Y)";
      break;

    case ATON_ARITHOP_XY:
      str = (const int8_t *)"X*Y";
      break;

    case ATON_ARITHOP_X_AND_Y:
      str = (const int8_t *)"X&Y";
      break;

    case ATON_ARITHOP_X_OR_Y:
      str = (const int8_t *)"X|Y";
      break;

    case ATON_ARITHOP_NOT_X:
      str = (const int8_t *)"!X";
      break;

    case ATON_ARITHOP_X_XOR_Y:
      str = (const int8_t *)"X^Y";
      break;

    case ATON_ARITHOP_X_EQ_Y:
      str = (const int8_t *)"X==Y";
      break;

    case ATON_ARITHOP_X_LT_Y:
      str = (const int8_t *)"X<Y";
      break;

    case ATON_ARITHOP_X_LE_Y:
      str = (const int8_t *)"X<=Y";
      break;

    case ATON_ARITHOP_X_GT_Y:
      str = (const int8_t *)"X>Y";
      break;

    case ATON_ARITHOP_X_GE_Y:
      str = (const int8_t *)"X>=Y";
      break;

    case ATON_ARITHOP_ABS_X:
      str = (const int8_t *)"ABS(X)";
      break;

    case ATON_ARITHOP_SIGN_X:
      str = (const int8_t *)"SIGN(X)";
      break;

    case ATON_ARITHOP_CLIP:
      str = (const int8_t *)"CLIP";
      break;

    default:
      break;
  }

  return str;
}


/* ---------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                                                                                                                            */
/*                                                             ARITH_MEM set of enumerated values                                                             */
/*                                                                                                                                                            */
/* ---------------------------------------------------------------------------------------------------------------------------------------------------------- */

/** Arithmethic unit MEM offset: Total 4K addressable. 3K starting from 0x000 to 0xbff addressable by setting translate_addr_en=1, top 1K addressable (0xc00-0xfff) by setting translate_addr_en=0. */
#define ATON_ARITH_MEM_OFFSET (0x400UL)


/** Get the name of one of the values of the ARITH_MEM set of enumerated values. */
#define ATON_ARITH_MEM_GET_NAME(VALUE) \
  (((VALUE) == 1024UL) ? "OFFSET" :  "")


/**
 * Check if a value of the ARITH_MEM set of enumerated values is valid.
 *
 * \param[in] val is the numeric value that must be checked
 *
 * \retval \e true  if \e val is a valid value of the ARITH_MEM set of enumerated values is valid
 * \retval \e false otherwise
 */

static inline bool ATON_ARITH_MEM_IsValid(uint32_t val)
{
  bool retval = false;

  switch (val)
  {
    case ATON_ARITH_MEM_OFFSET:
      retval = true;
      break;

    default:
      break;
  }

  return retval;
}


/**
 * Get the name of one of the values of the ARITH_MEM set of enumerated values.
 *
 * \param[in] val is the numeric value whose name must be returned
 *
 * \return the name of value \e val of the ARITH_MEM set of enumerated values
 */

static inline const int8_t *ATON_ARITH_MEM_GetName(uint32_t val)
{
  const int8_t *str = NULL;

  switch (val)
  {
    case ATON_ARITH_MEM_OFFSET:
      str = (const int8_t *)"OFFSET";
      break;

    default:
      break;
  }

  return str;
}


/**
 * Get the description of one of the values of the ARITH_MEM set of enumerated values.
 *
 * \param[in] val is the numeric value whose description must be returned
 *
 * \return the description of value \e val of the ARITH_MEM set of enumerated values
 */

static inline const int8_t *ATON_ARITH_MEM_GetDesc(uint32_t val)
{
  const int8_t *str = NULL;

  switch (val)
  {
    case ATON_ARITH_MEM_OFFSET:
      str = (const int8_t *)"Total 4K addressable. 3K starting from 0x000 to 0xbff addressable by setting translate_addr_en=1, top 1K addressable (0xc00-0xfff) by setting translate_addr_en=0";
      break;

    default:
      break;
  }

  return str;
}


/* ---------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                                                                                                                            */
/*                                                             BLOCKTYPE set of enumerated values                                                             */
/*                                                                                                                                                            */
/* ---------------------------------------------------------------------------------------------------------------------------------------------------------- */

/** Block type: Stream Switch. */
#define ATON_BLOCKTYPE_STRSWITCH (0x0UL)

/** Block type: Stream Engine. */
#define ATON_BLOCKTYPE_STRENG (0x1UL)

/** Block type: Sensor Interface. */
#define ATON_BLOCKTYPE_SENSOR_IF (0x2UL)

/** Block type: Video Output. */
#define ATON_BLOCKTYPE_VIDEO_OUT (0x3UL)

/** Block type: IPU Interface. */
#define ATON_BLOCKTYPE_IPU_IF (0x4UL)

/** Block type: ISP Interface. */
#define ATON_BLOCKTYPE_ISP_IF (0x5UL)

/** Block type: Morph Filter. */
#define ATON_BLOCKTYPE_MORPH (0x6UL)

/** Block type: Background Remove. */
#define ATON_BLOCKTYPE_BACKREMOVE (0x7UL)

/** Block type: Reference Frame Update. */
#define ATON_BLOCKTYPE_REFUPDATE (0x8UL)

/** Block type: ???. */
#define ATON_BLOCKTYPE_CONV (0x9UL)

/** Block type: Cropper. */
#define ATON_BLOCKTYPE_CROP (0xaUL)

/** Block type: Corner Detector. */
#define ATON_BLOCKTYPE_CORNER_DETECT (0xbUL)

/** Block type: Census. */
#define ATON_BLOCKTYPE_CENSUS (0xcUL)

/** Block type: Rect. */
#define ATON_BLOCKTYPE_RECT (0xeUL)

/** Block type: JPEG Encoder. */
#define ATON_BLOCKTYPE_JPEG_ENC (0xfUL)

/** Block type: JPEG Decoder. */
#define ATON_BLOCKTYPE_JPEG_DEC (0x10UL)

/** Block type: Debug Controller. */
#define ATON_BLOCKTYPE_DEBUG_CTRL (0x11UL)

/** Block type: GP Controller. */
#define ATON_BLOCKTYPE_GP_CTRL (0x12UL)

/** Block type: SBDOG. */
#define ATON_BLOCKTYPE_SBDOG (0x13UL)

/** Block type: H264 Decoder. */
#define ATON_BLOCKTYPE_H264 (0x14UL)

/** Block type: ????. */
#define ATON_BLOCKTYPE_MATCH (0x15UL)

/** Block type: ISP. */
#define ATON_BLOCKTYPE_ISP (0x16UL)

/** Block type: Convolution Accelerator. */
#define ATON_BLOCKTYPE_CONVACC (0x17UL)

/** Block type: I2C. */
#define ATON_BLOCKTYPE_I2C (0x18UL)

/** Block type: Decompression Unit. */
#define ATON_BLOCKTYPE_DECUN (0x19UL)

/** Block type: Arithmetic Unit. */
#define ATON_BLOCKTYPE_ARITH (0x1aUL)

/** Block type: Activation Unit. */
#define ATON_BLOCKTYPE_ACTIV (0x1bUL)

/** Block type: Pooling Accelerator. */
#define ATON_BLOCKTYPE_POOL (0x1cUL)

/** Block type: Bus Interface. */
#define ATON_BLOCKTYPE_BUSIF (0x1dUL)

/** Block type: Interrupt Controller. */
#define ATON_BLOCKTYPE_INTCTRL (0x1eUL)

/** Block type: Clock Controller. */
#define ATON_BLOCKTYPE_CLKCTRL (0x1fUL)

/** Block type: Reconfigurable Buffer. */
#define ATON_BLOCKTYPE_RECBUF (0x20UL)

/** Block type: Epoch Controller. */
#define ATON_BLOCKTYPE_EPOCHCTRL (0x21UL)

/** Block type: Debug Trace. */
#define ATON_BLOCKTYPE_DEBUG_TRACE (0x22UL)


/** Get the name of one of the values of the BLOCKTYPE set of enumerated values. */
#define ATON_BLOCKTYPE_GET_NAME(VALUE) \
  (((VALUE) == 0UL) ? "STRSWITCH" : \
  (((VALUE) == 1UL) ? "STRENG" : \
  (((VALUE) == 2UL) ? "SENSOR_IF" : \
  (((VALUE) == 3UL) ? "VIDEO_OUT" : \
  (((VALUE) == 4UL) ? "IPU_IF" : \
  (((VALUE) == 5UL) ? "ISP_IF" : \
  (((VALUE) == 6UL) ? "MORPH" : \
  (((VALUE) == 7UL) ? "BACKREMOVE" : \
  (((VALUE) == 8UL) ? "REFUPDATE" : \
  (((VALUE) == 9UL) ? "CONV" : \
  (((VALUE) == 10UL) ? "CROP" : \
  (((VALUE) == 11UL) ? "CORNER_DETECT" : \
  (((VALUE) == 12UL) ? "CENSUS" : \
  (((VALUE) == 14UL) ? "RECT" : \
  (((VALUE) == 15UL) ? "JPEG_ENC" : \
  (((VALUE) == 16UL) ? "JPEG_DEC" : \
  (((VALUE) == 17UL) ? "DEBUG_CTRL" : \
  (((VALUE) == 18UL) ? "GP_CTRL" : \
  (((VALUE) == 19UL) ? "SBDOG" : \
  (((VALUE) == 20UL) ? "H264" : \
  (((VALUE) == 21UL) ? "MATCH" : \
  (((VALUE) == 22UL) ? "ISP" : \
  (((VALUE) == 23UL) ? "CONVACC" : \
  (((VALUE) == 24UL) ? "I2C" : \
  (((VALUE) == 25UL) ? "DECUN" : \
  (((VALUE) == 26UL) ? "ARITH" : \
  (((VALUE) == 27UL) ? "ACTIV" : \
  (((VALUE) == 28UL) ? "POOL" : \
  (((VALUE) == 29UL) ? "BUSIF" : \
  (((VALUE) == 30UL) ? "INTCTRL" : \
  (((VALUE) == 31UL) ? "CLKCTRL" : \
  (((VALUE) == 32UL) ? "RECBUF" : \
  (((VALUE) == 33UL) ? "EPOCHCTRL" : \
  (((VALUE) == 34UL) ? "DEBUG_TRACE" :  ""))))))))))))))))))))))))))))))))))


/**
 * Check if a value of the BLOCKTYPE set of enumerated values is valid.
 *
 * \param[in] val is the numeric value that must be checked
 *
 * \retval \e true  if \e val is a valid value of the BLOCKTYPE set of enumerated values is valid
 * \retval \e false otherwise
 */

static inline bool ATON_BLOCKTYPE_IsValid(uint8_t val)
{
  bool retval = false;

  switch (val)
  {
    case ATON_BLOCKTYPE_STRSWITCH:
    case ATON_BLOCKTYPE_STRENG:
    case ATON_BLOCKTYPE_SENSOR_IF:
    case ATON_BLOCKTYPE_VIDEO_OUT:
    case ATON_BLOCKTYPE_IPU_IF:
    case ATON_BLOCKTYPE_ISP_IF:
    case ATON_BLOCKTYPE_MORPH:
    case ATON_BLOCKTYPE_BACKREMOVE:
    case ATON_BLOCKTYPE_REFUPDATE:
    case ATON_BLOCKTYPE_CONV:
    case ATON_BLOCKTYPE_CROP:
    case ATON_BLOCKTYPE_CORNER_DETECT:
    case ATON_BLOCKTYPE_CENSUS:
    case ATON_BLOCKTYPE_RECT:
    case ATON_BLOCKTYPE_JPEG_ENC:
    case ATON_BLOCKTYPE_JPEG_DEC:
    case ATON_BLOCKTYPE_DEBUG_CTRL:
    case ATON_BLOCKTYPE_GP_CTRL:
    case ATON_BLOCKTYPE_SBDOG:
    case ATON_BLOCKTYPE_H264:
    case ATON_BLOCKTYPE_MATCH:
    case ATON_BLOCKTYPE_ISP:
    case ATON_BLOCKTYPE_CONVACC:
    case ATON_BLOCKTYPE_I2C:
    case ATON_BLOCKTYPE_DECUN:
    case ATON_BLOCKTYPE_ARITH:
    case ATON_BLOCKTYPE_ACTIV:
    case ATON_BLOCKTYPE_POOL:
    case ATON_BLOCKTYPE_BUSIF:
    case ATON_BLOCKTYPE_INTCTRL:
    case ATON_BLOCKTYPE_CLKCTRL:
    case ATON_BLOCKTYPE_RECBUF:
    case ATON_BLOCKTYPE_EPOCHCTRL:
    case ATON_BLOCKTYPE_DEBUG_TRACE:
      retval = true;
      break;

    default:
      break;
  }

  return retval;
}


/**
 * Get the name of one of the values of the BLOCKTYPE set of enumerated values.
 *
 * \param[in] val is the numeric value whose name must be returned
 *
 * \return the name of value \e val of the BLOCKTYPE set of enumerated values
 */

static inline const int8_t *ATON_BLOCKTYPE_GetName(uint8_t val)
{
  const int8_t *str = NULL;

  switch (val)
  {
    case ATON_BLOCKTYPE_STRSWITCH:
      str = (const int8_t *)"STRSWITCH";
      break;

    case ATON_BLOCKTYPE_STRENG:
      str = (const int8_t *)"STRENG";
      break;

    case ATON_BLOCKTYPE_SENSOR_IF:
      str = (const int8_t *)"SENSOR_IF";
      break;

    case ATON_BLOCKTYPE_VIDEO_OUT:
      str = (const int8_t *)"VIDEO_OUT";
      break;

    case ATON_BLOCKTYPE_IPU_IF:
      str = (const int8_t *)"IPU_IF";
      break;

    case ATON_BLOCKTYPE_ISP_IF:
      str = (const int8_t *)"ISP_IF";
      break;

    case ATON_BLOCKTYPE_MORPH:
      str = (const int8_t *)"MORPH";
      break;

    case ATON_BLOCKTYPE_BACKREMOVE:
      str = (const int8_t *)"BACKREMOVE";
      break;

    case ATON_BLOCKTYPE_REFUPDATE:
      str = (const int8_t *)"REFUPDATE";
      break;

    case ATON_BLOCKTYPE_CONV:
      str = (const int8_t *)"CONV";
      break;

    case ATON_BLOCKTYPE_CROP:
      str = (const int8_t *)"CROP";
      break;

    case ATON_BLOCKTYPE_CORNER_DETECT:
      str = (const int8_t *)"CORNER_DETECT";
      break;

    case ATON_BLOCKTYPE_CENSUS:
      str = (const int8_t *)"CENSUS";
      break;

    case ATON_BLOCKTYPE_RECT:
      str = (const int8_t *)"RECT";
      break;

    case ATON_BLOCKTYPE_JPEG_ENC:
      str = (const int8_t *)"JPEG_ENC";
      break;

    case ATON_BLOCKTYPE_JPEG_DEC:
      str = (const int8_t *)"JPEG_DEC";
      break;

    case ATON_BLOCKTYPE_DEBUG_CTRL:
      str = (const int8_t *)"DEBUG_CTRL";
      break;

    case ATON_BLOCKTYPE_GP_CTRL:
      str = (const int8_t *)"GP_CTRL";
      break;

    case ATON_BLOCKTYPE_SBDOG:
      str = (const int8_t *)"SBDOG";
      break;

    case ATON_BLOCKTYPE_H264:
      str = (const int8_t *)"H264";
      break;

    case ATON_BLOCKTYPE_MATCH:
      str = (const int8_t *)"MATCH";
      break;

    case ATON_BLOCKTYPE_ISP:
      str = (const int8_t *)"ISP";
      break;

    case ATON_BLOCKTYPE_CONVACC:
      str = (const int8_t *)"CONVACC";
      break;

    case ATON_BLOCKTYPE_I2C:
      str = (const int8_t *)"I2C";
      break;

    case ATON_BLOCKTYPE_DECUN:
      str = (const int8_t *)"DECUN";
      break;

    case ATON_BLOCKTYPE_ARITH:
      str = (const int8_t *)"ARITH";
      break;

    case ATON_BLOCKTYPE_ACTIV:
      str = (const int8_t *)"ACTIV";
      break;

    case ATON_BLOCKTYPE_POOL:
      str = (const int8_t *)"POOL";
      break;

    case ATON_BLOCKTYPE_BUSIF:
      str = (const int8_t *)"BUSIF";
      break;

    case ATON_BLOCKTYPE_INTCTRL:
      str = (const int8_t *)"INTCTRL";
      break;

    case ATON_BLOCKTYPE_CLKCTRL:
      str = (const int8_t *)"CLKCTRL";
      break;

    case ATON_BLOCKTYPE_RECBUF:
      str = (const int8_t *)"RECBUF";
      break;

    case ATON_BLOCKTYPE_EPOCHCTRL:
      str = (const int8_t *)"EPOCHCTRL";
      break;

    case ATON_BLOCKTYPE_DEBUG_TRACE:
      str = (const int8_t *)"DEBUG_TRACE";
      break;

    default:
      break;
  }

  return str;
}


/**
 * Get the description of one of the values of the BLOCKTYPE set of enumerated values.
 *
 * \param[in] val is the numeric value whose description must be returned
 *
 * \return the description of value \e val of the BLOCKTYPE set of enumerated values
 */

static inline const int8_t *ATON_BLOCKTYPE_GetDesc(uint8_t val)
{
  const int8_t *str = NULL;

  switch (val)
  {
    case ATON_BLOCKTYPE_STRSWITCH:
      str = (const int8_t *)"Stream Switch";
      break;

    case ATON_BLOCKTYPE_STRENG:
      str = (const int8_t *)"Stream Engine";
      break;

    case ATON_BLOCKTYPE_SENSOR_IF:
      str = (const int8_t *)"Sensor Interface";
      break;

    case ATON_BLOCKTYPE_VIDEO_OUT:
      str = (const int8_t *)"Video Output";
      break;

    case ATON_BLOCKTYPE_IPU_IF:
      str = (const int8_t *)"IPU Interface";
      break;

    case ATON_BLOCKTYPE_ISP_IF:
      str = (const int8_t *)"ISP Interface";
      break;

    case ATON_BLOCKTYPE_MORPH:
      str = (const int8_t *)"Morph Filter";
      break;

    case ATON_BLOCKTYPE_BACKREMOVE:
      str = (const int8_t *)"Background Remove";
      break;

    case ATON_BLOCKTYPE_REFUPDATE:
      str = (const int8_t *)"Reference Frame Update";
      break;

    case ATON_BLOCKTYPE_CONV:
      str = (const int8_t *)"???";
      break;

    case ATON_BLOCKTYPE_CROP:
      str = (const int8_t *)"Cropper";
      break;

    case ATON_BLOCKTYPE_CORNER_DETECT:
      str = (const int8_t *)"Corner Detector";
      break;

    case ATON_BLOCKTYPE_CENSUS:
      str = (const int8_t *)"Census";
      break;

    case ATON_BLOCKTYPE_RECT:
      str = (const int8_t *)"Rect";
      break;

    case ATON_BLOCKTYPE_JPEG_ENC:
      str = (const int8_t *)"JPEG Encoder";
      break;

    case ATON_BLOCKTYPE_JPEG_DEC:
      str = (const int8_t *)"JPEG Decoder";
      break;

    case ATON_BLOCKTYPE_DEBUG_CTRL:
      str = (const int8_t *)"Debug Controller";
      break;

    case ATON_BLOCKTYPE_GP_CTRL:
      str = (const int8_t *)"GP Controller";
      break;

    case ATON_BLOCKTYPE_SBDOG:
      str = (const int8_t *)"SBDOG";
      break;

    case ATON_BLOCKTYPE_H264:
      str = (const int8_t *)"H264 Decoder";
      break;

    case ATON_BLOCKTYPE_MATCH:
      str = (const int8_t *)"????";
      break;

    case ATON_BLOCKTYPE_ISP:
      str = (const int8_t *)"ISP";
      break;

    case ATON_BLOCKTYPE_CONVACC:
      str = (const int8_t *)"Convolution Accelerator";
      break;

    case ATON_BLOCKTYPE_I2C:
      str = (const int8_t *)"I2C";
      break;

    case ATON_BLOCKTYPE_DECUN:
      str = (const int8_t *)"Decompression Unit";
      break;

    case ATON_BLOCKTYPE_ARITH:
      str = (const int8_t *)"Arithmetic Unit";
      break;

    case ATON_BLOCKTYPE_ACTIV:
      str = (const int8_t *)"Activation Unit";
      break;

    case ATON_BLOCKTYPE_POOL:
      str = (const int8_t *)"Pooling Accelerator";
      break;

    case ATON_BLOCKTYPE_BUSIF:
      str = (const int8_t *)"Bus Interface";
      break;

    case ATON_BLOCKTYPE_INTCTRL:
      str = (const int8_t *)"Interrupt Controller";
      break;

    case ATON_BLOCKTYPE_CLKCTRL:
      str = (const int8_t *)"Clock Controller";
      break;

    case ATON_BLOCKTYPE_RECBUF:
      str = (const int8_t *)"Reconfigurable Buffer";
      break;

    case ATON_BLOCKTYPE_EPOCHCTRL:
      str = (const int8_t *)"Epoch Controller";
      break;

    case ATON_BLOCKTYPE_DEBUG_TRACE:
      str = (const int8_t *)"Debug Trace";
      break;

    default:
      break;
  }

  return str;
}


/* ---------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                                                                                                                            */
/*                                                                CHS set of enumerated values                                                                */
/*                                                                                                                                                            */
/* ---------------------------------------------------------------------------------------------------------------------------------------------------------- */

/** Channels: CH0 / Red / Y. */
#define ATON_CHS_RY (0x0UL)

/** Channels: CH1 / Green / Cb. */
#define ATON_CHS_GCB (0x1UL)

/** Channels: CH2 / Blue / Cr. */
#define ATON_CHS_BCR (0x2UL)

/** Channels: Reserved / do not use. */
#define ATON_CHS_RES (0x3UL)


/** Get the name of one of the values of the CHS set of enumerated values. */
#define ATON_CHS_GET_NAME(VALUE) \
  (((VALUE) == 0UL) ? "RY" : \
  (((VALUE) == 1UL) ? "GCB" : \
  (((VALUE) == 2UL) ? "BCR" : \
  (((VALUE) == 3UL) ? "RES" :  ""))))


/**
 * Check if a value of the CHS set of enumerated values is valid.
 *
 * \param[in] val is the numeric value that must be checked
 *
 * \retval \e true  if \e val is a valid value of the CHS set of enumerated values is valid
 * \retval \e false otherwise
 */

static inline bool ATON_CHS_IsValid(uint8_t val)
{
  bool retval = false;

  switch (val)
  {
    case ATON_CHS_RY:
    case ATON_CHS_GCB:
    case ATON_CHS_BCR:
    case ATON_CHS_RES:
      retval = true;
      break;

    default:
      break;
  }

  return retval;
}


/**
 * Get the name of one of the values of the CHS set of enumerated values.
 *
 * \param[in] val is the numeric value whose name must be returned
 *
 * \return the name of value \e val of the CHS set of enumerated values
 */

static inline const int8_t *ATON_CHS_GetName(uint8_t val)
{
  const int8_t *str = NULL;

  switch (val)
  {
    case ATON_CHS_RY:
      str = (const int8_t *)"RY";
      break;

    case ATON_CHS_GCB:
      str = (const int8_t *)"GCB";
      break;

    case ATON_CHS_BCR:
      str = (const int8_t *)"BCR";
      break;

    case ATON_CHS_RES:
      str = (const int8_t *)"RES";
      break;

    default:
      break;
  }

  return str;
}


/**
 * Get the description of one of the values of the CHS set of enumerated values.
 *
 * \param[in] val is the numeric value whose description must be returned
 *
 * \return the description of value \e val of the CHS set of enumerated values
 */

static inline const int8_t *ATON_CHS_GetDesc(uint8_t val)
{
  const int8_t *str = NULL;

  switch (val)
  {
    case ATON_CHS_RY:
      str = (const int8_t *)"CH0 / Red / Y";
      break;

    case ATON_CHS_GCB:
      str = (const int8_t *)"CH1 / Green / Cb";
      break;

    case ATON_CHS_BCR:
      str = (const int8_t *)"CH2 / Blue / Cr";
      break;

    case ATON_CHS_RES:
      str = (const int8_t *)"Reserved / do not use";
      break;

    default:
      break;
  }

  return str;
}


/* ---------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                                                                                                                            */
/*                                                             COEFFTYPE set of enumerated values                                                             */
/*                                                                                                                                                            */
/* ---------------------------------------------------------------------------------------------------------------------------------------------------------- */

/** Coefficient type: Scalar coefficient type. */
#define ATON_COEFFTYPE_SCALAR (0x0UL)

/** Coefficient type: Vector coefficient type. */
#define ATON_COEFFTYPE_VECTOR (0x1UL)


/** Get the name of one of the values of the COEFFTYPE set of enumerated values. */
#define ATON_COEFFTYPE_GET_NAME(VALUE) \
  (((VALUE) == 0UL) ? "SCALAR" : \
  (((VALUE) == 1UL) ? "VECTOR" :  ""))


/**
 * Check if a value of the COEFFTYPE set of enumerated values is valid.
 *
 * \param[in] val is the numeric value that must be checked
 *
 * \retval \e true  if \e val is a valid value of the COEFFTYPE set of enumerated values is valid
 * \retval \e false otherwise
 */

static inline bool ATON_COEFFTYPE_IsValid(uint8_t val)
{
  bool retval = false;

  switch (val)
  {
    case ATON_COEFFTYPE_SCALAR:
    case ATON_COEFFTYPE_VECTOR:
      retval = true;
      break;

    default:
      break;
  }

  return retval;
}


/**
 * Get the name of one of the values of the COEFFTYPE set of enumerated values.
 *
 * \param[in] val is the numeric value whose name must be returned
 *
 * \return the name of value \e val of the COEFFTYPE set of enumerated values
 */

static inline const int8_t *ATON_COEFFTYPE_GetName(uint8_t val)
{
  const int8_t *str = NULL;

  switch (val)
  {
    case ATON_COEFFTYPE_SCALAR:
      str = (const int8_t *)"SCALAR";
      break;

    case ATON_COEFFTYPE_VECTOR:
      str = (const int8_t *)"VECTOR";
      break;

    default:
      break;
  }

  return str;
}


/**
 * Get the description of one of the values of the COEFFTYPE set of enumerated values.
 *
 * \param[in] val is the numeric value whose description must be returned
 *
 * \return the description of value \e val of the COEFFTYPE set of enumerated values
 */

static inline const int8_t *ATON_COEFFTYPE_GetDesc(uint8_t val)
{
  const int8_t *str = NULL;

  switch (val)
  {
    case ATON_COEFFTYPE_SCALAR:
      str = (const int8_t *)"Scalar coefficient type";
      break;

    case ATON_COEFFTYPE_VECTOR:
      str = (const int8_t *)"Vector coefficient type";
      break;

    default:
      break;
  }

  return str;
}


/* ---------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                                                                                                                            */
/*                                                            DECUN_BFMT set of enumerated values                                                             */
/*                                                                                                                                                            */
/* ---------------------------------------------------------------------------------------------------------------------------------------------------------- */

/** BFORMAT values: CV1CW1LAST0. */
#define ATON_DECUN_BFMT_CV1CW1LAST0 (0x0UL)

/** BFORMAT values: CV1CW2LAST0. */
#define ATON_DECUN_BFMT_CV1CW2LAST0 (0x100UL)

/** BFORMAT values: CV1CW3LAST0. */
#define ATON_DECUN_BFMT_CV1CW3LAST0 (0x200UL)

/** BFORMAT values: CV1CW4LAST0. */
#define ATON_DECUN_BFMT_CV1CW4LAST0 (0x300UL)

/** BFORMAT values: CV1CW5LAST0. */
#define ATON_DECUN_BFMT_CV1CW5LAST0 (0x400UL)

/** BFORMAT values: CV1CW6LAST0. */
#define ATON_DECUN_BFMT_CV1CW6LAST0 (0x500UL)

/** BFORMAT values: CV1CW7LAST0. */
#define ATON_DECUN_BFMT_CV1CW7LAST0 (0x600UL)

/** BFORMAT values: CV1CW8LAST0. */
#define ATON_DECUN_BFMT_CV1CW8LAST0 (0x700UL)

/** BFORMAT values: CV1CW2LAST1. */
#define ATON_DECUN_BFMT_CV1CW2LAST1 (0x1100UL)

/** BFORMAT values: CV1CW3LAST1. */
#define ATON_DECUN_BFMT_CV1CW3LAST1 (0x1200UL)

/** BFORMAT values: CV1CW4LAST1. */
#define ATON_DECUN_BFMT_CV1CW4LAST1 (0x1300UL)

/** BFORMAT values: CV1CW5LAST1. */
#define ATON_DECUN_BFMT_CV1CW5LAST1 (0x1400UL)

/** BFORMAT values: CV1CW6LAST1. */
#define ATON_DECUN_BFMT_CV1CW6LAST1 (0x1500UL)

/** BFORMAT values: CV1CW7LAST1. */
#define ATON_DECUN_BFMT_CV1CW7LAST1 (0x1600UL)

/** BFORMAT values: CV1CW8LAST1. */
#define ATON_DECUN_BFMT_CV1CW8LAST1 (0x1700UL)

/** BFORMAT values: CV1CW3LAST2. */
#define ATON_DECUN_BFMT_CV1CW3LAST2 (0x2200UL)

/** BFORMAT values: CV1CW4LAST2. */
#define ATON_DECUN_BFMT_CV1CW4LAST2 (0x2300UL)

/** BFORMAT values: CV1CW5LAST2. */
#define ATON_DECUN_BFMT_CV1CW5LAST2 (0x2400UL)

/** BFORMAT values: CV1CW6LAST2. */
#define ATON_DECUN_BFMT_CV1CW6LAST2 (0x2500UL)

/** BFORMAT values: CV1CW7LAST2. */
#define ATON_DECUN_BFMT_CV1CW7LAST2 (0x2600UL)

/** BFORMAT values: CV1CW8LAST2. */
#define ATON_DECUN_BFMT_CV1CW8LAST2 (0x2700UL)

/** BFORMAT values: CV1CW4LAST3. */
#define ATON_DECUN_BFMT_CV1CW4LAST3 (0x3300UL)

/** BFORMAT values: CV1CW5LAST3. */
#define ATON_DECUN_BFMT_CV1CW5LAST3 (0x3400UL)

/** BFORMAT values: CV1CW6LAST3. */
#define ATON_DECUN_BFMT_CV1CW6LAST3 (0x3500UL)

/** BFORMAT values: CV1CW7LAST3. */
#define ATON_DECUN_BFMT_CV1CW7LAST3 (0x3600UL)

/** BFORMAT values: CV1CW8LAST3. */
#define ATON_DECUN_BFMT_CV1CW8LAST3 (0x3700UL)

/** BFORMAT values: CV1CW5LAST4. */
#define ATON_DECUN_BFMT_CV1CW5LAST4 (0x4400UL)

/** BFORMAT values: CV1CW6LAST4. */
#define ATON_DECUN_BFMT_CV1CW6LAST4 (0x4500UL)

/** BFORMAT values: CV1CW7LAST4. */
#define ATON_DECUN_BFMT_CV1CW7LAST4 (0x4600UL)

/** BFORMAT values: CV1CW8LAST4. */
#define ATON_DECUN_BFMT_CV1CW8LAST4 (0x4700UL)

/** BFORMAT values: CV1CW6LAST5. */
#define ATON_DECUN_BFMT_CV1CW6LAST5 (0x5500UL)

/** BFORMAT values: CV1CW7LAST5. */
#define ATON_DECUN_BFMT_CV1CW7LAST5 (0x5600UL)

/** BFORMAT values: CV1CW8LAST5. */
#define ATON_DECUN_BFMT_CV1CW8LAST5 (0x5700UL)

/** BFORMAT values: CV1CW7LAST6. */
#define ATON_DECUN_BFMT_CV1CW7LAST6 (0x6600UL)

/** BFORMAT values: CV1CW8LAST6. */
#define ATON_DECUN_BFMT_CV1CW8LAST6 (0x6700UL)

/** BFORMAT values: CV1CW8LAST7. */
#define ATON_DECUN_BFMT_CV1CW8LAST7 (0x7700UL)

/** BFORMAT values: CV2CW1LAST0. */
#define ATON_DECUN_BFMT_CV2CW1LAST0 (0x1UL)

/** BFORMAT values: CV2CW2LAST0. */
#define ATON_DECUN_BFMT_CV2CW2LAST0 (0x101UL)

/** BFORMAT values: CV2CW3LAST0. */
#define ATON_DECUN_BFMT_CV2CW3LAST0 (0x201UL)

/** BFORMAT values: CV2CW4LAST0. */
#define ATON_DECUN_BFMT_CV2CW4LAST0 (0x301UL)

/** BFORMAT values: CV2CW5LAST0. */
#define ATON_DECUN_BFMT_CV2CW5LAST0 (0x401UL)

/** BFORMAT values: CV2CW6LAST0. */
#define ATON_DECUN_BFMT_CV2CW6LAST0 (0x501UL)

/** BFORMAT values: CV2CW7LAST0. */
#define ATON_DECUN_BFMT_CV2CW7LAST0 (0x601UL)

/** BFORMAT values: CV2CW8LAST0. */
#define ATON_DECUN_BFMT_CV2CW8LAST0 (0x701UL)

/** BFORMAT values: CV2CW2LAST1. */
#define ATON_DECUN_BFMT_CV2CW2LAST1 (0x1101UL)

/** BFORMAT values: CV2CW3LAST1. */
#define ATON_DECUN_BFMT_CV2CW3LAST1 (0x1201UL)

/** BFORMAT values: CV2CW4LAST1. */
#define ATON_DECUN_BFMT_CV2CW4LAST1 (0x1301UL)

/** BFORMAT values: CV2CW5LAST1. */
#define ATON_DECUN_BFMT_CV2CW5LAST1 (0x1401UL)

/** BFORMAT values: CV2CW6LAST1. */
#define ATON_DECUN_BFMT_CV2CW6LAST1 (0x1501UL)

/** BFORMAT values: CV2CW7LAST1. */
#define ATON_DECUN_BFMT_CV2CW7LAST1 (0x1601UL)

/** BFORMAT values: CV2CW8LAST1. */
#define ATON_DECUN_BFMT_CV2CW8LAST1 (0x1701UL)

/** BFORMAT values: CV2CW3LAST2. */
#define ATON_DECUN_BFMT_CV2CW3LAST2 (0x2201UL)

/** BFORMAT values: CV2CW4LAST2. */
#define ATON_DECUN_BFMT_CV2CW4LAST2 (0x2301UL)

/** BFORMAT values: CV2CW5LAST2. */
#define ATON_DECUN_BFMT_CV2CW5LAST2 (0x2401UL)

/** BFORMAT values: CV2CW6LAST2. */
#define ATON_DECUN_BFMT_CV2CW6LAST2 (0x2501UL)

/** BFORMAT values: CV2CW7LAST2. */
#define ATON_DECUN_BFMT_CV2CW7LAST2 (0x2601UL)

/** BFORMAT values: CV2CW8LAST2. */
#define ATON_DECUN_BFMT_CV2CW8LAST2 (0x2701UL)

/** BFORMAT values: CV2CW4LAST3. */
#define ATON_DECUN_BFMT_CV2CW4LAST3 (0x3301UL)

/** BFORMAT values: CV2CW5LAST3. */
#define ATON_DECUN_BFMT_CV2CW5LAST3 (0x3401UL)

/** BFORMAT values: CV2CW6LAST3. */
#define ATON_DECUN_BFMT_CV2CW6LAST3 (0x3501UL)

/** BFORMAT values: CV2CW7LAST3. */
#define ATON_DECUN_BFMT_CV2CW7LAST3 (0x3601UL)

/** BFORMAT values: CV2CW8LAST3. */
#define ATON_DECUN_BFMT_CV2CW8LAST3 (0x3701UL)

/** BFORMAT values: CV2CW5LAST4. */
#define ATON_DECUN_BFMT_CV2CW5LAST4 (0x4401UL)

/** BFORMAT values: CV2CW6LAST4. */
#define ATON_DECUN_BFMT_CV2CW6LAST4 (0x4501UL)

/** BFORMAT values: CV2CW7LAST4. */
#define ATON_DECUN_BFMT_CV2CW7LAST4 (0x4601UL)

/** BFORMAT values: CV2CW8LAST4. */
#define ATON_DECUN_BFMT_CV2CW8LAST4 (0x4701UL)

/** BFORMAT values: CV2CW6LAST5. */
#define ATON_DECUN_BFMT_CV2CW6LAST5 (0x5501UL)

/** BFORMAT values: CV2CW7LAST5. */
#define ATON_DECUN_BFMT_CV2CW7LAST5 (0x5601UL)

/** BFORMAT values: CV2CW8LAST5. */
#define ATON_DECUN_BFMT_CV2CW8LAST5 (0x5701UL)

/** BFORMAT values: CV2CW7LAST6. */
#define ATON_DECUN_BFMT_CV2CW7LAST6 (0x6601UL)

/** BFORMAT values: CV2CW8LAST6. */
#define ATON_DECUN_BFMT_CV2CW8LAST6 (0x6701UL)

/** BFORMAT values: CV2CW8LAST7. */
#define ATON_DECUN_BFMT_CV2CW8LAST7 (0x7701UL)

/** BFORMAT values: CV4CW1LAST0. */
#define ATON_DECUN_BFMT_CV4CW1LAST0 (0x3UL)

/** BFORMAT values: CV4CW2LAST0. */
#define ATON_DECUN_BFMT_CV4CW2LAST0 (0x103UL)

/** BFORMAT values: CV4CW3LAST0. */
#define ATON_DECUN_BFMT_CV4CW3LAST0 (0x203UL)

/** BFORMAT values: CV4CW4LAST0. */
#define ATON_DECUN_BFMT_CV4CW4LAST0 (0x303UL)

/** BFORMAT values: CV4CW5LAST0. */
#define ATON_DECUN_BFMT_CV4CW5LAST0 (0x403UL)

/** BFORMAT values: CV4CW6LAST0. */
#define ATON_DECUN_BFMT_CV4CW6LAST0 (0x503UL)

/** BFORMAT values: CV4CW7LAST0. */
#define ATON_DECUN_BFMT_CV4CW7LAST0 (0x603UL)

/** BFORMAT values: CV4CW8LAST0. */
#define ATON_DECUN_BFMT_CV4CW8LAST0 (0x703UL)

/** BFORMAT values: CV4CW2LAST1. */
#define ATON_DECUN_BFMT_CV4CW2LAST1 (0x1103UL)

/** BFORMAT values: CV4CW3LAST1. */
#define ATON_DECUN_BFMT_CV4CW3LAST1 (0x1203UL)

/** BFORMAT values: CV4CW4LAST1. */
#define ATON_DECUN_BFMT_CV4CW4LAST1 (0x1303UL)

/** BFORMAT values: CV4CW5LAST1. */
#define ATON_DECUN_BFMT_CV4CW5LAST1 (0x1403UL)

/** BFORMAT values: CV4CW6LAST1. */
#define ATON_DECUN_BFMT_CV4CW6LAST1 (0x1503UL)

/** BFORMAT values: CV4CW7LAST1. */
#define ATON_DECUN_BFMT_CV4CW7LAST1 (0x1603UL)

/** BFORMAT values: CV4CW8LAST1. */
#define ATON_DECUN_BFMT_CV4CW8LAST1 (0x1703UL)

/** BFORMAT values: CV4CW3LAST2. */
#define ATON_DECUN_BFMT_CV4CW3LAST2 (0x2203UL)

/** BFORMAT values: CV4CW4LAST2. */
#define ATON_DECUN_BFMT_CV4CW4LAST2 (0x2303UL)

/** BFORMAT values: CV4CW5LAST2. */
#define ATON_DECUN_BFMT_CV4CW5LAST2 (0x2403UL)

/** BFORMAT values: CV4CW6LAST2. */
#define ATON_DECUN_BFMT_CV4CW6LAST2 (0x2503UL)

/** BFORMAT values: CV4CW7LAST2. */
#define ATON_DECUN_BFMT_CV4CW7LAST2 (0x2603UL)

/** BFORMAT values: CV4CW8LAST2. */
#define ATON_DECUN_BFMT_CV4CW8LAST2 (0x2703UL)

/** BFORMAT values: CV4CW4LAST3. */
#define ATON_DECUN_BFMT_CV4CW4LAST3 (0x3303UL)

/** BFORMAT values: CV4CW5LAST3. */
#define ATON_DECUN_BFMT_CV4CW5LAST3 (0x3403UL)

/** BFORMAT values: CV4CW6LAST3. */
#define ATON_DECUN_BFMT_CV4CW6LAST3 (0x3503UL)

/** BFORMAT values: CV4CW7LAST3. */
#define ATON_DECUN_BFMT_CV4CW7LAST3 (0x3603UL)

/** BFORMAT values: CV4CW8LAST3. */
#define ATON_DECUN_BFMT_CV4CW8LAST3 (0x3703UL)

/** BFORMAT values: CV4CW5LAST4. */
#define ATON_DECUN_BFMT_CV4CW5LAST4 (0x4403UL)

/** BFORMAT values: CV4CW6LAST4. */
#define ATON_DECUN_BFMT_CV4CW6LAST4 (0x4503UL)

/** BFORMAT values: CV4CW7LAST4. */
#define ATON_DECUN_BFMT_CV4CW7LAST4 (0x4603UL)

/** BFORMAT values: CV4CW8LAST4. */
#define ATON_DECUN_BFMT_CV4CW8LAST4 (0x4703UL)

/** BFORMAT values: CV4CW6LAST5. */
#define ATON_DECUN_BFMT_CV4CW6LAST5 (0x5503UL)

/** BFORMAT values: CV4CW7LAST5. */
#define ATON_DECUN_BFMT_CV4CW7LAST5 (0x5603UL)

/** BFORMAT values: CV4CW8LAST5. */
#define ATON_DECUN_BFMT_CV4CW8LAST5 (0x5703UL)

/** BFORMAT values: CV4CW7LAST6. */
#define ATON_DECUN_BFMT_CV4CW7LAST6 (0x6603UL)

/** BFORMAT values: CV4CW8LAST6. */
#define ATON_DECUN_BFMT_CV4CW8LAST6 (0x6703UL)

/** BFORMAT values: CV4CW8LAST7. */
#define ATON_DECUN_BFMT_CV4CW8LAST7 (0x7703UL)

/** BFORMAT values: CV8CW1LAST0. */
#define ATON_DECUN_BFMT_CV8CW1LAST0 (0x7UL)

/** BFORMAT values: CV8CW2LAST0. */
#define ATON_DECUN_BFMT_CV8CW2LAST0 (0x107UL)

/** BFORMAT values: CV8CW3LAST0. */
#define ATON_DECUN_BFMT_CV8CW3LAST0 (0x207UL)

/** BFORMAT values: CV8CW4LAST0. */
#define ATON_DECUN_BFMT_CV8CW4LAST0 (0x307UL)

/** BFORMAT values: CV8CW5LAST0. */
#define ATON_DECUN_BFMT_CV8CW5LAST0 (0x407UL)

/** BFORMAT values: CV8CW6LAST0. */
#define ATON_DECUN_BFMT_CV8CW6LAST0 (0x507UL)

/** BFORMAT values: CV8CW7LAST0. */
#define ATON_DECUN_BFMT_CV8CW7LAST0 (0x607UL)

/** BFORMAT values: CV8CW8LAST0. */
#define ATON_DECUN_BFMT_CV8CW8LAST0 (0x707UL)

/** BFORMAT values: CV8CW2LAST1. */
#define ATON_DECUN_BFMT_CV8CW2LAST1 (0x1107UL)

/** BFORMAT values: CV8CW3LAST1. */
#define ATON_DECUN_BFMT_CV8CW3LAST1 (0x1207UL)

/** BFORMAT values: CV8CW4LAST1. */
#define ATON_DECUN_BFMT_CV8CW4LAST1 (0x1307UL)

/** BFORMAT values: CV8CW5LAST1. */
#define ATON_DECUN_BFMT_CV8CW5LAST1 (0x1407UL)

/** BFORMAT values: CV8CW6LAST1. */
#define ATON_DECUN_BFMT_CV8CW6LAST1 (0x1507UL)

/** BFORMAT values: CV8CW7LAST1. */
#define ATON_DECUN_BFMT_CV8CW7LAST1 (0x1607UL)

/** BFORMAT values: CV8CW8LAST1. */
#define ATON_DECUN_BFMT_CV8CW8LAST1 (0x1707UL)

/** BFORMAT values: CV8CW3LAST2. */
#define ATON_DECUN_BFMT_CV8CW3LAST2 (0x2207UL)

/** BFORMAT values: CV8CW4LAST2. */
#define ATON_DECUN_BFMT_CV8CW4LAST2 (0x2307UL)

/** BFORMAT values: CV8CW5LAST2. */
#define ATON_DECUN_BFMT_CV8CW5LAST2 (0x2407UL)

/** BFORMAT values: CV8CW6LAST2. */
#define ATON_DECUN_BFMT_CV8CW6LAST2 (0x2507UL)

/** BFORMAT values: CV8CW7LAST2. */
#define ATON_DECUN_BFMT_CV8CW7LAST2 (0x2607UL)

/** BFORMAT values: CV8CW8LAST2. */
#define ATON_DECUN_BFMT_CV8CW8LAST2 (0x2707UL)

/** BFORMAT values: CV8CW4LAST3. */
#define ATON_DECUN_BFMT_CV8CW4LAST3 (0x3307UL)

/** BFORMAT values: CV8CW5LAST3. */
#define ATON_DECUN_BFMT_CV8CW5LAST3 (0x3407UL)

/** BFORMAT values: CV8CW6LAST3. */
#define ATON_DECUN_BFMT_CV8CW6LAST3 (0x3507UL)

/** BFORMAT values: CV8CW7LAST3. */
#define ATON_DECUN_BFMT_CV8CW7LAST3 (0x3607UL)

/** BFORMAT values: CV8CW8LAST3. */
#define ATON_DECUN_BFMT_CV8CW8LAST3 (0x3707UL)

/** BFORMAT values: CV8CW5LAST4. */
#define ATON_DECUN_BFMT_CV8CW5LAST4 (0x4407UL)

/** BFORMAT values: CV8CW6LAST4. */
#define ATON_DECUN_BFMT_CV8CW6LAST4 (0x4507UL)

/** BFORMAT values: CV8CW7LAST4. */
#define ATON_DECUN_BFMT_CV8CW7LAST4 (0x4607UL)

/** BFORMAT values: CV8CW8LAST4. */
#define ATON_DECUN_BFMT_CV8CW8LAST4 (0x4707UL)

/** BFORMAT values: CV8CW6LAST5. */
#define ATON_DECUN_BFMT_CV8CW6LAST5 (0x5507UL)

/** BFORMAT values: CV8CW7LAST5. */
#define ATON_DECUN_BFMT_CV8CW7LAST5 (0x5607UL)

/** BFORMAT values: CV8CW8LAST5. */
#define ATON_DECUN_BFMT_CV8CW8LAST5 (0x5707UL)

/** BFORMAT values: CV8CW7LAST6. */
#define ATON_DECUN_BFMT_CV8CW7LAST6 (0x6607UL)

/** BFORMAT values: CV8CW8LAST6. */
#define ATON_DECUN_BFMT_CV8CW8LAST6 (0x6707UL)

/** BFORMAT values: CV8CW8LAST7. */
#define ATON_DECUN_BFMT_CV8CW8LAST7 (0x7707UL)

/** BFORMAT values: CV16CW1LAST0. */
#define ATON_DECUN_BFMT_CV16CW1LAST0 (0xfUL)

/** BFORMAT values: CV16CW2LAST0. */
#define ATON_DECUN_BFMT_CV16CW2LAST0 (0x10fUL)

/** BFORMAT values: CV16CW3LAST0. */
#define ATON_DECUN_BFMT_CV16CW3LAST0 (0x20fUL)

/** BFORMAT values: CV16CW4LAST0. */
#define ATON_DECUN_BFMT_CV16CW4LAST0 (0x30fUL)

/** BFORMAT values: CV16CW5LAST0. */
#define ATON_DECUN_BFMT_CV16CW5LAST0 (0x40fUL)

/** BFORMAT values: CV16CW6LAST0. */
#define ATON_DECUN_BFMT_CV16CW6LAST0 (0x50fUL)

/** BFORMAT values: CV16CW7LAST0. */
#define ATON_DECUN_BFMT_CV16CW7LAST0 (0x60fUL)

/** BFORMAT values: CV16CW8LAST0. */
#define ATON_DECUN_BFMT_CV16CW8LAST0 (0x70fUL)

/** BFORMAT values: CV32CW1LAST0. */
#define ATON_DECUN_BFMT_CV32CW1LAST0 (0x1fUL)

/** BFORMAT values: CV32CW2LAST0. */
#define ATON_DECUN_BFMT_CV32CW2LAST0 (0x11fUL)

/** BFORMAT values: CV32CW3LAST0. */
#define ATON_DECUN_BFMT_CV32CW3LAST0 (0x21fUL)

/** BFORMAT values: CV32CW4LAST0. */
#define ATON_DECUN_BFMT_CV32CW4LAST0 (0x31fUL)

/** BFORMAT values: CV32CW5LAST0. */
#define ATON_DECUN_BFMT_CV32CW5LAST0 (0x41fUL)

/** BFORMAT values: CV32CW6LAST0. */
#define ATON_DECUN_BFMT_CV32CW6LAST0 (0x51fUL)

/** BFORMAT values: CV32CW7LAST0. */
#define ATON_DECUN_BFMT_CV32CW7LAST0 (0x61fUL)

/** BFORMAT values: CV32CW8LAST0. */
#define ATON_DECUN_BFMT_CV32CW8LAST0 (0x71fUL)

/** BFORMAT values: CV64CW1LAST0. */
#define ATON_DECUN_BFMT_CV64CW1LAST0 (0x3fUL)

/** BFORMAT values: CV64CW2LAST0. */
#define ATON_DECUN_BFMT_CV64CW2LAST0 (0x13fUL)

/** BFORMAT values: CV64CW3LAST0. */
#define ATON_DECUN_BFMT_CV64CW3LAST0 (0x23fUL)

/** BFORMAT values: CV64CW4LAST0. */
#define ATON_DECUN_BFMT_CV64CW4LAST0 (0x33fUL)

/** BFORMAT values: CV64CW5LAST0. */
#define ATON_DECUN_BFMT_CV64CW5LAST0 (0x43fUL)

/** BFORMAT values: CV64CW6LAST0. */
#define ATON_DECUN_BFMT_CV64CW6LAST0 (0x53fUL)

/** BFORMAT values: CV64CW7LAST0. */
#define ATON_DECUN_BFMT_CV64CW7LAST0 (0x63fUL)

/** BFORMAT values: CV64CW8LAST0. */
#define ATON_DECUN_BFMT_CV64CW8LAST0 (0x73fUL)

/** BFORMAT values: CV128CW1LAST0. */
#define ATON_DECUN_BFMT_CV128CW1LAST0 (0x7fUL)

/** BFORMAT values: CV128CW2LAST0. */
#define ATON_DECUN_BFMT_CV128CW2LAST0 (0x17fUL)

/** BFORMAT values: CV128CW3LAST0. */
#define ATON_DECUN_BFMT_CV128CW3LAST0 (0x27fUL)

/** BFORMAT values: CV128CW4LAST0. */
#define ATON_DECUN_BFMT_CV128CW4LAST0 (0x37fUL)

/** BFORMAT values: CV128CW5LAST0. */
#define ATON_DECUN_BFMT_CV128CW5LAST0 (0x47fUL)

/** BFORMAT values: CV128CW6LAST0. */
#define ATON_DECUN_BFMT_CV128CW6LAST0 (0x57fUL)

/** BFORMAT values: CV128CW7LAST0. */
#define ATON_DECUN_BFMT_CV128CW7LAST0 (0x67fUL)

/** BFORMAT values: CV128CW8LAST0. */
#define ATON_DECUN_BFMT_CV128CW8LAST0 (0x77fUL)

/** BFORMAT values: CV256CW1LAST0. */
#define ATON_DECUN_BFMT_CV256CW1LAST0 (0xffUL)

/** BFORMAT values: CV256CW2LAST0. */
#define ATON_DECUN_BFMT_CV256CW2LAST0 (0x1ffUL)

/** BFORMAT values: CV256CW3LAST0. */
#define ATON_DECUN_BFMT_CV256CW3LAST0 (0x2ffUL)

/** BFORMAT values: CV256CW4LAST0. */
#define ATON_DECUN_BFMT_CV256CW4LAST0 (0x3ffUL)

/** BFORMAT values: CV256CW5LAST0. */
#define ATON_DECUN_BFMT_CV256CW5LAST0 (0x4ffUL)

/** BFORMAT values: CV256CW6LAST0. */
#define ATON_DECUN_BFMT_CV256CW6LAST0 (0x5ffUL)

/** BFORMAT values: CV256CW7LAST0. */
#define ATON_DECUN_BFMT_CV256CW7LAST0 (0x6ffUL)

/** BFORMAT values: CV256CW8LAST0. */
#define ATON_DECUN_BFMT_CV256CW8LAST0 (0x7ffUL)

/** BFORMAT values: CV16CW2LAST1. */
#define ATON_DECUN_BFMT_CV16CW2LAST1 (0x110fUL)

/** BFORMAT values: CV16CW3LAST1. */
#define ATON_DECUN_BFMT_CV16CW3LAST1 (0x120fUL)

/** BFORMAT values: CV16CW3LAST2. */
#define ATON_DECUN_BFMT_CV16CW3LAST2 (0x220fUL)

/** BFORMAT values: CV16CW4LAST1. */
#define ATON_DECUN_BFMT_CV16CW4LAST1 (0x130fUL)

/** BFORMAT values: CV16CW4LAST2. */
#define ATON_DECUN_BFMT_CV16CW4LAST2 (0x230fUL)

/** BFORMAT values: CV16CW4LAST3. */
#define ATON_DECUN_BFMT_CV16CW4LAST3 (0x330fUL)

/** BFORMAT values: CV16CW5LAST1. */
#define ATON_DECUN_BFMT_CV16CW5LAST1 (0x140fUL)

/** BFORMAT values: CV16CW5LAST2. */
#define ATON_DECUN_BFMT_CV16CW5LAST2 (0x240fUL)

/** BFORMAT values: CV16CW5LAST3. */
#define ATON_DECUN_BFMT_CV16CW5LAST3 (0x340fUL)

/** BFORMAT values: CV16CW5LAST4. */
#define ATON_DECUN_BFMT_CV16CW5LAST4 (0x440fUL)

/** BFORMAT values: CV16CW6LAST1. */
#define ATON_DECUN_BFMT_CV16CW6LAST1 (0x150fUL)

/** BFORMAT values: CV16CW6LAST2. */
#define ATON_DECUN_BFMT_CV16CW6LAST2 (0x250fUL)

/** BFORMAT values: CV16CW6LAST3. */
#define ATON_DECUN_BFMT_CV16CW6LAST3 (0x350fUL)

/** BFORMAT values: CV16CW6LAST4. */
#define ATON_DECUN_BFMT_CV16CW6LAST4 (0x450fUL)

/** BFORMAT values: CV16CW6LAST5. */
#define ATON_DECUN_BFMT_CV16CW6LAST5 (0x550fUL)

/** BFORMAT values: CV16CW7LAST1. */
#define ATON_DECUN_BFMT_CV16CW7LAST1 (0x160fUL)

/** BFORMAT values: CV16CW7LAST2. */
#define ATON_DECUN_BFMT_CV16CW7LAST2 (0x260fUL)

/** BFORMAT values: CV16CW7LAST3. */
#define ATON_DECUN_BFMT_CV16CW7LAST3 (0x360fUL)

/** BFORMAT values: CV16CW7LAST4. */
#define ATON_DECUN_BFMT_CV16CW7LAST4 (0x460fUL)

/** BFORMAT values: CV16CW7LAST5. */
#define ATON_DECUN_BFMT_CV16CW7LAST5 (0x560fUL)

/** BFORMAT values: CV16CW7LAST6. */
#define ATON_DECUN_BFMT_CV16CW7LAST6 (0x660fUL)

/** BFORMAT values: CV16CW8LAST1. */
#define ATON_DECUN_BFMT_CV16CW8LAST1 (0x170fUL)

/** BFORMAT values: CV16CW8LAST2. */
#define ATON_DECUN_BFMT_CV16CW8LAST2 (0x270fUL)

/** BFORMAT values: CV16CW8LAST3. */
#define ATON_DECUN_BFMT_CV16CW8LAST3 (0x370fUL)

/** BFORMAT values: CV16CW8LAST4. */
#define ATON_DECUN_BFMT_CV16CW8LAST4 (0x470fUL)

/** BFORMAT values: CV16CW8LAST5. */
#define ATON_DECUN_BFMT_CV16CW8LAST5 (0x570fUL)

/** BFORMAT values: CV16CW8LAST6. */
#define ATON_DECUN_BFMT_CV16CW8LAST6 (0x670fUL)

/** BFORMAT values: CV16CW8LAST7. */
#define ATON_DECUN_BFMT_CV16CW8LAST7 (0x770fUL)

/** BFORMAT values: CV32CW2LAST1. */
#define ATON_DECUN_BFMT_CV32CW2LAST1 (0x111fUL)

/** BFORMAT values: CV32CW3LAST1. */
#define ATON_DECUN_BFMT_CV32CW3LAST1 (0x121fUL)

/** BFORMAT values: CV32CW3LAST2. */
#define ATON_DECUN_BFMT_CV32CW3LAST2 (0x221fUL)

/** BFORMAT values: CV32CW4LAST1. */
#define ATON_DECUN_BFMT_CV32CW4LAST1 (0x131fUL)

/** BFORMAT values: CV32CW4LAST2. */
#define ATON_DECUN_BFMT_CV32CW4LAST2 (0x231fUL)

/** BFORMAT values: CV32CW4LAST3. */
#define ATON_DECUN_BFMT_CV32CW4LAST3 (0x331fUL)

/** BFORMAT values: CV32CW5LAST1. */
#define ATON_DECUN_BFMT_CV32CW5LAST1 (0x141fUL)

/** BFORMAT values: CV32CW5LAST2. */
#define ATON_DECUN_BFMT_CV32CW5LAST2 (0x241fUL)

/** BFORMAT values: CV32CW5LAST3. */
#define ATON_DECUN_BFMT_CV32CW5LAST3 (0x341fUL)

/** BFORMAT values: CV32CW5LAST4. */
#define ATON_DECUN_BFMT_CV32CW5LAST4 (0x441fUL)

/** BFORMAT values: CV32CW6LAST1. */
#define ATON_DECUN_BFMT_CV32CW6LAST1 (0x151fUL)

/** BFORMAT values: CV32CW6LAST2. */
#define ATON_DECUN_BFMT_CV32CW6LAST2 (0x251fUL)

/** BFORMAT values: CV32CW6LAST3. */
#define ATON_DECUN_BFMT_CV32CW6LAST3 (0x351fUL)

/** BFORMAT values: CV32CW6LAST4. */
#define ATON_DECUN_BFMT_CV32CW6LAST4 (0x451fUL)

/** BFORMAT values: CV32CW6LAST5. */
#define ATON_DECUN_BFMT_CV32CW6LAST5 (0x551fUL)

/** BFORMAT values: CV32CW7LAST1. */
#define ATON_DECUN_BFMT_CV32CW7LAST1 (0x161fUL)

/** BFORMAT values: CV32CW7LAST2. */
#define ATON_DECUN_BFMT_CV32CW7LAST2 (0x261fUL)

/** BFORMAT values: CV32CW7LAST3. */
#define ATON_DECUN_BFMT_CV32CW7LAST3 (0x361fUL)

/** BFORMAT values: CV32CW7LAST4. */
#define ATON_DECUN_BFMT_CV32CW7LAST4 (0x461fUL)

/** BFORMAT values: CV32CW7LAST5. */
#define ATON_DECUN_BFMT_CV32CW7LAST5 (0x561fUL)

/** BFORMAT values: CV32CW7LAST6. */
#define ATON_DECUN_BFMT_CV32CW7LAST6 (0x661fUL)

/** BFORMAT values: CV32CW8LAST1. */
#define ATON_DECUN_BFMT_CV32CW8LAST1 (0x171fUL)

/** BFORMAT values: CV32CW8LAST2. */
#define ATON_DECUN_BFMT_CV32CW8LAST2 (0x271fUL)

/** BFORMAT values: CV32CW8LAST3. */
#define ATON_DECUN_BFMT_CV32CW8LAST3 (0x371fUL)

/** BFORMAT values: CV32CW8LAST4. */
#define ATON_DECUN_BFMT_CV32CW8LAST4 (0x471fUL)

/** BFORMAT values: CV32CW8LAST5. */
#define ATON_DECUN_BFMT_CV32CW8LAST5 (0x571fUL)

/** BFORMAT values: CV32CW8LAST6. */
#define ATON_DECUN_BFMT_CV32CW8LAST6 (0x671fUL)

/** BFORMAT values: CV32CW8LAST7. */
#define ATON_DECUN_BFMT_CV32CW8LAST7 (0x771fUL)

/** BFORMAT values: CV64CW2LAST1. */
#define ATON_DECUN_BFMT_CV64CW2LAST1 (0x113fUL)

/** BFORMAT values: CV64CW3LAST1. */
#define ATON_DECUN_BFMT_CV64CW3LAST1 (0x123fUL)

/** BFORMAT values: CV64CW3LAST2. */
#define ATON_DECUN_BFMT_CV64CW3LAST2 (0x223fUL)

/** BFORMAT values: CV64CW4LAST1. */
#define ATON_DECUN_BFMT_CV64CW4LAST1 (0x133fUL)

/** BFORMAT values: CV64CW4LAST2. */
#define ATON_DECUN_BFMT_CV64CW4LAST2 (0x233fUL)

/** BFORMAT values: CV64CW4LAST3. */
#define ATON_DECUN_BFMT_CV64CW4LAST3 (0x333fUL)

/** BFORMAT values: CV64CW5LAST1. */
#define ATON_DECUN_BFMT_CV64CW5LAST1 (0x143fUL)

/** BFORMAT values: CV64CW5LAST2. */
#define ATON_DECUN_BFMT_CV64CW5LAST2 (0x243fUL)

/** BFORMAT values: CV64CW5LAST3. */
#define ATON_DECUN_BFMT_CV64CW5LAST3 (0x343fUL)

/** BFORMAT values: CV64CW5LAST4. */
#define ATON_DECUN_BFMT_CV64CW5LAST4 (0x443fUL)

/** BFORMAT values: CV64CW6LAST1. */
#define ATON_DECUN_BFMT_CV64CW6LAST1 (0x153fUL)

/** BFORMAT values: CV64CW6LAST2. */
#define ATON_DECUN_BFMT_CV64CW6LAST2 (0x253fUL)

/** BFORMAT values: CV64CW6LAST3. */
#define ATON_DECUN_BFMT_CV64CW6LAST3 (0x353fUL)

/** BFORMAT values: CV64CW6LAST4. */
#define ATON_DECUN_BFMT_CV64CW6LAST4 (0x453fUL)

/** BFORMAT values: CV64CW6LAST5. */
#define ATON_DECUN_BFMT_CV64CW6LAST5 (0x553fUL)

/** BFORMAT values: CV64CW7LAST1. */
#define ATON_DECUN_BFMT_CV64CW7LAST1 (0x163fUL)

/** BFORMAT values: CV64CW7LAST2. */
#define ATON_DECUN_BFMT_CV64CW7LAST2 (0x263fUL)

/** BFORMAT values: CV64CW7LAST3. */
#define ATON_DECUN_BFMT_CV64CW7LAST3 (0x363fUL)

/** BFORMAT values: CV64CW7LAST4. */
#define ATON_DECUN_BFMT_CV64CW7LAST4 (0x463fUL)

/** BFORMAT values: CV64CW7LAST5. */
#define ATON_DECUN_BFMT_CV64CW7LAST5 (0x563fUL)

/** BFORMAT values: CV64CW7LAST6. */
#define ATON_DECUN_BFMT_CV64CW7LAST6 (0x663fUL)

/** BFORMAT values: CV64CW8LAST1. */
#define ATON_DECUN_BFMT_CV64CW8LAST1 (0x173fUL)

/** BFORMAT values: CV64CW8LAST2. */
#define ATON_DECUN_BFMT_CV64CW8LAST2 (0x273fUL)

/** BFORMAT values: CV64CW8LAST3. */
#define ATON_DECUN_BFMT_CV64CW8LAST3 (0x373fUL)

/** BFORMAT values: CV64CW8LAST4. */
#define ATON_DECUN_BFMT_CV64CW8LAST4 (0x473fUL)

/** BFORMAT values: CV64CW8LAST5. */
#define ATON_DECUN_BFMT_CV64CW8LAST5 (0x573fUL)

/** BFORMAT values: CV64CW8LAST6. */
#define ATON_DECUN_BFMT_CV64CW8LAST6 (0x673fUL)

/** BFORMAT values: CV64CW8LAST7. */
#define ATON_DECUN_BFMT_CV64CW8LAST7 (0x773fUL)

/** BFORMAT values: CV128CW2LAST1. */
#define ATON_DECUN_BFMT_CV128CW2LAST1 (0x117fUL)

/** BFORMAT values: CV128CW3LAST1. */
#define ATON_DECUN_BFMT_CV128CW3LAST1 (0x127fUL)

/** BFORMAT values: CV128CW3LAST2. */
#define ATON_DECUN_BFMT_CV128CW3LAST2 (0x227fUL)

/** BFORMAT values: CV128CW4LAST1. */
#define ATON_DECUN_BFMT_CV128CW4LAST1 (0x137fUL)

/** BFORMAT values: CV128CW4LAST2. */
#define ATON_DECUN_BFMT_CV128CW4LAST2 (0x237fUL)

/** BFORMAT values: CV128CW4LAST3. */
#define ATON_DECUN_BFMT_CV128CW4LAST3 (0x337fUL)

/** BFORMAT values: CV128CW5LAST1. */
#define ATON_DECUN_BFMT_CV128CW5LAST1 (0x147fUL)

/** BFORMAT values: CV128CW5LAST2. */
#define ATON_DECUN_BFMT_CV128CW5LAST2 (0x247fUL)

/** BFORMAT values: CV128CW5LAST3. */
#define ATON_DECUN_BFMT_CV128CW5LAST3 (0x347fUL)

/** BFORMAT values: CV128CW5LAST4. */
#define ATON_DECUN_BFMT_CV128CW5LAST4 (0x447fUL)

/** BFORMAT values: CV128CW6LAST1. */
#define ATON_DECUN_BFMT_CV128CW6LAST1 (0x157fUL)

/** BFORMAT values: CV128CW6LAST2. */
#define ATON_DECUN_BFMT_CV128CW6LAST2 (0x257fUL)

/** BFORMAT values: CV128CW6LAST3. */
#define ATON_DECUN_BFMT_CV128CW6LAST3 (0x357fUL)

/** BFORMAT values: CV128CW6LAST4. */
#define ATON_DECUN_BFMT_CV128CW6LAST4 (0x457fUL)

/** BFORMAT values: CV128CW6LAST5. */
#define ATON_DECUN_BFMT_CV128CW6LAST5 (0x557fUL)

/** BFORMAT values: CV128CW7LAST1. */
#define ATON_DECUN_BFMT_CV128CW7LAST1 (0x167fUL)

/** BFORMAT values: CV128CW7LAST2. */
#define ATON_DECUN_BFMT_CV128CW7LAST2 (0x267fUL)

/** BFORMAT values: CV128CW7LAST3. */
#define ATON_DECUN_BFMT_CV128CW7LAST3 (0x367fUL)

/** BFORMAT values: CV128CW7LAST4. */
#define ATON_DECUN_BFMT_CV128CW7LAST4 (0x467fUL)

/** BFORMAT values: CV128CW7LAST5. */
#define ATON_DECUN_BFMT_CV128CW7LAST5 (0x567fUL)

/** BFORMAT values: CV128CW7LAST6. */
#define ATON_DECUN_BFMT_CV128CW7LAST6 (0x667fUL)

/** BFORMAT values: CV128CW8LAST1. */
#define ATON_DECUN_BFMT_CV128CW8LAST1 (0x177fUL)

/** BFORMAT values: CV128CW8LAST2. */
#define ATON_DECUN_BFMT_CV128CW8LAST2 (0x277fUL)

/** BFORMAT values: CV128CW8LAST3. */
#define ATON_DECUN_BFMT_CV128CW8LAST3 (0x377fUL)

/** BFORMAT values: CV128CW8LAST4. */
#define ATON_DECUN_BFMT_CV128CW8LAST4 (0x477fUL)

/** BFORMAT values: CV128CW8LAST5. */
#define ATON_DECUN_BFMT_CV128CW8LAST5 (0x577fUL)

/** BFORMAT values: CV128CW8LAST6. */
#define ATON_DECUN_BFMT_CV128CW8LAST6 (0x677fUL)

/** BFORMAT values: CV128CW8LAST7. */
#define ATON_DECUN_BFMT_CV128CW8LAST7 (0x777fUL)

/** BFORMAT values: CV256CW2LAST1. */
#define ATON_DECUN_BFMT_CV256CW2LAST1 (0x11ffUL)

/** BFORMAT values: CV256CW3LAST1. */
#define ATON_DECUN_BFMT_CV256CW3LAST1 (0x12ffUL)

/** BFORMAT values: CV256CW3LAST2. */
#define ATON_DECUN_BFMT_CV256CW3LAST2 (0x22ffUL)

/** BFORMAT values: CV256CW4LAST1. */
#define ATON_DECUN_BFMT_CV256CW4LAST1 (0x13ffUL)

/** BFORMAT values: CV256CW4LAST2. */
#define ATON_DECUN_BFMT_CV256CW4LAST2 (0x23ffUL)

/** BFORMAT values: CV256CW4LAST3. */
#define ATON_DECUN_BFMT_CV256CW4LAST3 (0x33ffUL)

/** BFORMAT values: CV256CW5LAST1. */
#define ATON_DECUN_BFMT_CV256CW5LAST1 (0x14ffUL)

/** BFORMAT values: CV256CW5LAST2. */
#define ATON_DECUN_BFMT_CV256CW5LAST2 (0x24ffUL)

/** BFORMAT values: CV256CW5LAST3. */
#define ATON_DECUN_BFMT_CV256CW5LAST3 (0x34ffUL)

/** BFORMAT values: CV256CW5LAST4. */
#define ATON_DECUN_BFMT_CV256CW5LAST4 (0x44ffUL)

/** BFORMAT values: CV256CW6LAST1. */
#define ATON_DECUN_BFMT_CV256CW6LAST1 (0x15ffUL)

/** BFORMAT values: CV256CW6LAST2. */
#define ATON_DECUN_BFMT_CV256CW6LAST2 (0x25ffUL)

/** BFORMAT values: CV256CW6LAST3. */
#define ATON_DECUN_BFMT_CV256CW6LAST3 (0x35ffUL)

/** BFORMAT values: CV256CW6LAST4. */
#define ATON_DECUN_BFMT_CV256CW6LAST4 (0x45ffUL)

/** BFORMAT values: CV256CW6LAST5. */
#define ATON_DECUN_BFMT_CV256CW6LAST5 (0x55ffUL)

/** BFORMAT values: CV256CW7LAST1. */
#define ATON_DECUN_BFMT_CV256CW7LAST1 (0x16ffUL)

/** BFORMAT values: CV256CW7LAST2. */
#define ATON_DECUN_BFMT_CV256CW7LAST2 (0x26ffUL)

/** BFORMAT values: CV256CW7LAST3. */
#define ATON_DECUN_BFMT_CV256CW7LAST3 (0x36ffUL)

/** BFORMAT values: CV256CW7LAST4. */
#define ATON_DECUN_BFMT_CV256CW7LAST4 (0x46ffUL)

/** BFORMAT values: CV256CW7LAST5. */
#define ATON_DECUN_BFMT_CV256CW7LAST5 (0x56ffUL)

/** BFORMAT values: CV256CW7LAST6. */
#define ATON_DECUN_BFMT_CV256CW7LAST6 (0x66ffUL)

/** BFORMAT values: CV256CW8LAST1. */
#define ATON_DECUN_BFMT_CV256CW8LAST1 (0x17ffUL)

/** BFORMAT values: CV256CW8LAST2. */
#define ATON_DECUN_BFMT_CV256CW8LAST2 (0x27ffUL)

/** BFORMAT values: CV256CW8LAST3. */
#define ATON_DECUN_BFMT_CV256CW8LAST3 (0x37ffUL)

/** BFORMAT values: CV256CW8LAST4. */
#define ATON_DECUN_BFMT_CV256CW8LAST4 (0x47ffUL)

/** BFORMAT values: CV256CW8LAST5. */
#define ATON_DECUN_BFMT_CV256CW8LAST5 (0x57ffUL)

/** BFORMAT values: CV256CW8LAST6. */
#define ATON_DECUN_BFMT_CV256CW8LAST6 (0x67ffUL)

/** BFORMAT values: CV256CW8LAST7. */
#define ATON_DECUN_BFMT_CV256CW8LAST7 (0x77ffUL)


/** Get the name of one of the values of the DECUN_BFMT set of enumerated values. */
#define ATON_DECUN_BFMT_GET_NAME(VALUE) \
  (((VALUE) == 0UL) ? "CV1CW1LAST0" : \
  (((VALUE) == 256UL) ? "CV1CW2LAST0" : \
  (((VALUE) == 512UL) ? "CV1CW3LAST0" : \
  (((VALUE) == 768UL) ? "CV1CW4LAST0" : \
  (((VALUE) == 1024UL) ? "CV1CW5LAST0" : \
  (((VALUE) == 1280UL) ? "CV1CW6LAST0" : \
  (((VALUE) == 1536UL) ? "CV1CW7LAST0" : \
  (((VALUE) == 1792UL) ? "CV1CW8LAST0" : \
  (((VALUE) == 4352UL) ? "CV1CW2LAST1" : \
  (((VALUE) == 4608UL) ? "CV1CW3LAST1" : \
  (((VALUE) == 4864UL) ? "CV1CW4LAST1" : \
  (((VALUE) == 5120UL) ? "CV1CW5LAST1" : \
  (((VALUE) == 5376UL) ? "CV1CW6LAST1" : \
  (((VALUE) == 5632UL) ? "CV1CW7LAST1" : \
  (((VALUE) == 5888UL) ? "CV1CW8LAST1" : \
  (((VALUE) == 8704UL) ? "CV1CW3LAST2" : \
  (((VALUE) == 8960UL) ? "CV1CW4LAST2" : \
  (((VALUE) == 9216UL) ? "CV1CW5LAST2" : \
  (((VALUE) == 9472UL) ? "CV1CW6LAST2" : \
  (((VALUE) == 9728UL) ? "CV1CW7LAST2" : \
  (((VALUE) == 9984UL) ? "CV1CW8LAST2" : \
  (((VALUE) == 13056UL) ? "CV1CW4LAST3" : \
  (((VALUE) == 13312UL) ? "CV1CW5LAST3" : \
  (((VALUE) == 13568UL) ? "CV1CW6LAST3" : \
  (((VALUE) == 13824UL) ? "CV1CW7LAST3" : \
  (((VALUE) == 14080UL) ? "CV1CW8LAST3" : \
  (((VALUE) == 17408UL) ? "CV1CW5LAST4" : \
  (((VALUE) == 17664UL) ? "CV1CW6LAST4" : \
  (((VALUE) == 17920UL) ? "CV1CW7LAST4" : \
  (((VALUE) == 18176UL) ? "CV1CW8LAST4" : \
  (((VALUE) == 21760UL) ? "CV1CW6LAST5" : \
  (((VALUE) == 22016UL) ? "CV1CW7LAST5" : \
  (((VALUE) == 22272UL) ? "CV1CW8LAST5" : \
  (((VALUE) == 26112UL) ? "CV1CW7LAST6" : \
  (((VALUE) == 26368UL) ? "CV1CW8LAST6" : \
  (((VALUE) == 30464UL) ? "CV1CW8LAST7" : \
  (((VALUE) == 1UL) ? "CV2CW1LAST0" : \
  (((VALUE) == 257UL) ? "CV2CW2LAST0" : \
  (((VALUE) == 513UL) ? "CV2CW3LAST0" : \
  (((VALUE) == 769UL) ? "CV2CW4LAST0" : \
  (((VALUE) == 1025UL) ? "CV2CW5LAST0" : \
  (((VALUE) == 1281UL) ? "CV2CW6LAST0" : \
  (((VALUE) == 1537UL) ? "CV2CW7LAST0" : \
  (((VALUE) == 1793UL) ? "CV2CW8LAST0" : \
  (((VALUE) == 4353UL) ? "CV2CW2LAST1" : \
  (((VALUE) == 4609UL) ? "CV2CW3LAST1" : \
  (((VALUE) == 4865UL) ? "CV2CW4LAST1" : \
  (((VALUE) == 5121UL) ? "CV2CW5LAST1" : \
  (((VALUE) == 5377UL) ? "CV2CW6LAST1" : \
  (((VALUE) == 5633UL) ? "CV2CW7LAST1" : \
  (((VALUE) == 5889UL) ? "CV2CW8LAST1" : \
  (((VALUE) == 8705UL) ? "CV2CW3LAST2" : \
  (((VALUE) == 8961UL) ? "CV2CW4LAST2" : \
  (((VALUE) == 9217UL) ? "CV2CW5LAST2" : \
  (((VALUE) == 9473UL) ? "CV2CW6LAST2" : \
  (((VALUE) == 9729UL) ? "CV2CW7LAST2" : \
  (((VALUE) == 9985UL) ? "CV2CW8LAST2" : \
  (((VALUE) == 13057UL) ? "CV2CW4LAST3" : \
  (((VALUE) == 13313UL) ? "CV2CW5LAST3" : \
  (((VALUE) == 13569UL) ? "CV2CW6LAST3" : \
  (((VALUE) == 13825UL) ? "CV2CW7LAST3" : \
  (((VALUE) == 14081UL) ? "CV2CW8LAST3" : \
  (((VALUE) == 17409UL) ? "CV2CW5LAST4" : \
  (((VALUE) == 17665UL) ? "CV2CW6LAST4" : \
  (((VALUE) == 17921UL) ? "CV2CW7LAST4" : \
  (((VALUE) == 18177UL) ? "CV2CW8LAST4" : \
  (((VALUE) == 21761UL) ? "CV2CW6LAST5" : \
  (((VALUE) == 22017UL) ? "CV2CW7LAST5" : \
  (((VALUE) == 22273UL) ? "CV2CW8LAST5" : \
  (((VALUE) == 26113UL) ? "CV2CW7LAST6" : \
  (((VALUE) == 26369UL) ? "CV2CW8LAST6" : \
  (((VALUE) == 30465UL) ? "CV2CW8LAST7" : \
  (((VALUE) == 3UL) ? "CV4CW1LAST0" : \
  (((VALUE) == 259UL) ? "CV4CW2LAST0" : \
  (((VALUE) == 515UL) ? "CV4CW3LAST0" : \
  (((VALUE) == 771UL) ? "CV4CW4LAST0" : \
  (((VALUE) == 1027UL) ? "CV4CW5LAST0" : \
  (((VALUE) == 1283UL) ? "CV4CW6LAST0" : \
  (((VALUE) == 1539UL) ? "CV4CW7LAST0" : \
  (((VALUE) == 1795UL) ? "CV4CW8LAST0" : \
  (((VALUE) == 4355UL) ? "CV4CW2LAST1" : \
  (((VALUE) == 4611UL) ? "CV4CW3LAST1" : \
  (((VALUE) == 4867UL) ? "CV4CW4LAST1" : \
  (((VALUE) == 5123UL) ? "CV4CW5LAST1" : \
  (((VALUE) == 5379UL) ? "CV4CW6LAST1" : \
  (((VALUE) == 5635UL) ? "CV4CW7LAST1" : \
  (((VALUE) == 5891UL) ? "CV4CW8LAST1" : \
  (((VALUE) == 8707UL) ? "CV4CW3LAST2" : \
  (((VALUE) == 8963UL) ? "CV4CW4LAST2" : \
  (((VALUE) == 9219UL) ? "CV4CW5LAST2" : \
  (((VALUE) == 9475UL) ? "CV4CW6LAST2" : \
  (((VALUE) == 9731UL) ? "CV4CW7LAST2" : \
  (((VALUE) == 9987UL) ? "CV4CW8LAST2" : \
  (((VALUE) == 13059UL) ? "CV4CW4LAST3" : \
  (((VALUE) == 13315UL) ? "CV4CW5LAST3" : \
  (((VALUE) == 13571UL) ? "CV4CW6LAST3" : \
  (((VALUE) == 13827UL) ? "CV4CW7LAST3" : \
  (((VALUE) == 14083UL) ? "CV4CW8LAST3" : \
  (((VALUE) == 17411UL) ? "CV4CW5LAST4" : \
  (((VALUE) == 17667UL) ? "CV4CW6LAST4" : \
  (((VALUE) == 17923UL) ? "CV4CW7LAST4" : \
  (((VALUE) == 18179UL) ? "CV4CW8LAST4" : \
  (((VALUE) == 21763UL) ? "CV4CW6LAST5" : \
  (((VALUE) == 22019UL) ? "CV4CW7LAST5" : \
  (((VALUE) == 22275UL) ? "CV4CW8LAST5" : \
  (((VALUE) == 26115UL) ? "CV4CW7LAST6" : \
  (((VALUE) == 26371UL) ? "CV4CW8LAST6" : \
  (((VALUE) == 30467UL) ? "CV4CW8LAST7" : \
  (((VALUE) == 7UL) ? "CV8CW1LAST0" : \
  (((VALUE) == 263UL) ? "CV8CW2LAST0" : \
  (((VALUE) == 519UL) ? "CV8CW3LAST0" : \
  (((VALUE) == 775UL) ? "CV8CW4LAST0" : \
  (((VALUE) == 1031UL) ? "CV8CW5LAST0" : \
  (((VALUE) == 1287UL) ? "CV8CW6LAST0" : \
  (((VALUE) == 1543UL) ? "CV8CW7LAST0" : \
  (((VALUE) == 1799UL) ? "CV8CW8LAST0" : \
  (((VALUE) == 4359UL) ? "CV8CW2LAST1" : \
  (((VALUE) == 4615UL) ? "CV8CW3LAST1" : \
  (((VALUE) == 4871UL) ? "CV8CW4LAST1" : \
  (((VALUE) == 5127UL) ? "CV8CW5LAST1" : \
  (((VALUE) == 5383UL) ? "CV8CW6LAST1" : \
  (((VALUE) == 5639UL) ? "CV8CW7LAST1" : \
  (((VALUE) == 5895UL) ? "CV8CW8LAST1" : \
  (((VALUE) == 8711UL) ? "CV8CW3LAST2" : \
  (((VALUE) == 8967UL) ? "CV8CW4LAST2" : \
  (((VALUE) == 9223UL) ? "CV8CW5LAST2" : \
  (((VALUE) == 9479UL) ? "CV8CW6LAST2" : \
  (((VALUE) == 9735UL) ? "CV8CW7LAST2" : \
  (((VALUE) == 9991UL) ? "CV8CW8LAST2" : \
  (((VALUE) == 13063UL) ? "CV8CW4LAST3" : \
  (((VALUE) == 13319UL) ? "CV8CW5LAST3" : \
  (((VALUE) == 13575UL) ? "CV8CW6LAST3" : \
  (((VALUE) == 13831UL) ? "CV8CW7LAST3" : \
  (((VALUE) == 14087UL) ? "CV8CW8LAST3" : \
  (((VALUE) == 17415UL) ? "CV8CW5LAST4" : \
  (((VALUE) == 17671UL) ? "CV8CW6LAST4" : \
  (((VALUE) == 17927UL) ? "CV8CW7LAST4" : \
  (((VALUE) == 18183UL) ? "CV8CW8LAST4" : \
  (((VALUE) == 21767UL) ? "CV8CW6LAST5" : \
  (((VALUE) == 22023UL) ? "CV8CW7LAST5" : \
  (((VALUE) == 22279UL) ? "CV8CW8LAST5" : \
  (((VALUE) == 26119UL) ? "CV8CW7LAST6" : \
  (((VALUE) == 26375UL) ? "CV8CW8LAST6" : \
  (((VALUE) == 30471UL) ? "CV8CW8LAST7" : \
  (((VALUE) == 15UL) ? "CV16CW1LAST0" : \
  (((VALUE) == 271UL) ? "CV16CW2LAST0" : \
  (((VALUE) == 527UL) ? "CV16CW3LAST0" : \
  (((VALUE) == 783UL) ? "CV16CW4LAST0" : \
  (((VALUE) == 1039UL) ? "CV16CW5LAST0" : \
  (((VALUE) == 1295UL) ? "CV16CW6LAST0" : \
  (((VALUE) == 1551UL) ? "CV16CW7LAST0" : \
  (((VALUE) == 1807UL) ? "CV16CW8LAST0" : \
  (((VALUE) == 31UL) ? "CV32CW1LAST0" : \
  (((VALUE) == 287UL) ? "CV32CW2LAST0" : \
  (((VALUE) == 543UL) ? "CV32CW3LAST0" : \
  (((VALUE) == 799UL) ? "CV32CW4LAST0" : \
  (((VALUE) == 1055UL) ? "CV32CW5LAST0" : \
  (((VALUE) == 1311UL) ? "CV32CW6LAST0" : \
  (((VALUE) == 1567UL) ? "CV32CW7LAST0" : \
  (((VALUE) == 1823UL) ? "CV32CW8LAST0" : \
  (((VALUE) == 63UL) ? "CV64CW1LAST0" : \
  (((VALUE) == 319UL) ? "CV64CW2LAST0" : \
  (((VALUE) == 575UL) ? "CV64CW3LAST0" : \
  (((VALUE) == 831UL) ? "CV64CW4LAST0" : \
  (((VALUE) == 1087UL) ? "CV64CW5LAST0" : \
  (((VALUE) == 1343UL) ? "CV64CW6LAST0" : \
  (((VALUE) == 1599UL) ? "CV64CW7LAST0" : \
  (((VALUE) == 1855UL) ? "CV64CW8LAST0" : \
  (((VALUE) == 127UL) ? "CV128CW1LAST0" : \
  (((VALUE) == 383UL) ? "CV128CW2LAST0" : \
  (((VALUE) == 639UL) ? "CV128CW3LAST0" : \
  (((VALUE) == 895UL) ? "CV128CW4LAST0" : \
  (((VALUE) == 1151UL) ? "CV128CW5LAST0" : \
  (((VALUE) == 1407UL) ? "CV128CW6LAST0" : \
  (((VALUE) == 1663UL) ? "CV128CW7LAST0" : \
  (((VALUE) == 1919UL) ? "CV128CW8LAST0" : \
  (((VALUE) == 255UL) ? "CV256CW1LAST0" : \
  (((VALUE) == 511UL) ? "CV256CW2LAST0" : \
  (((VALUE) == 767UL) ? "CV256CW3LAST0" : \
  (((VALUE) == 1023UL) ? "CV256CW4LAST0" : \
  (((VALUE) == 1279UL) ? "CV256CW5LAST0" : \
  (((VALUE) == 1535UL) ? "CV256CW6LAST0" : \
  (((VALUE) == 1791UL) ? "CV256CW7LAST0" : \
  (((VALUE) == 2047UL) ? "CV256CW8LAST0" : \
  (((VALUE) == 4367UL) ? "CV16CW2LAST1" : \
  (((VALUE) == 4623UL) ? "CV16CW3LAST1" : \
  (((VALUE) == 8719UL) ? "CV16CW3LAST2" : \
  (((VALUE) == 4879UL) ? "CV16CW4LAST1" : \
  (((VALUE) == 8975UL) ? "CV16CW4LAST2" : \
  (((VALUE) == 13071UL) ? "CV16CW4LAST3" : \
  (((VALUE) == 5135UL) ? "CV16CW5LAST1" : \
  (((VALUE) == 9231UL) ? "CV16CW5LAST2" : \
  (((VALUE) == 13327UL) ? "CV16CW5LAST3" : \
  (((VALUE) == 17423UL) ? "CV16CW5LAST4" : \
  (((VALUE) == 5391UL) ? "CV16CW6LAST1" : \
  (((VALUE) == 9487UL) ? "CV16CW6LAST2" : \
  (((VALUE) == 13583UL) ? "CV16CW6LAST3" : \
  (((VALUE) == 17679UL) ? "CV16CW6LAST4" : \
  (((VALUE) == 21775UL) ? "CV16CW6LAST5" : \
  (((VALUE) == 5647UL) ? "CV16CW7LAST1" : \
  (((VALUE) == 9743UL) ? "CV16CW7LAST2" : \
  (((VALUE) == 13839UL) ? "CV16CW7LAST3" : \
  (((VALUE) == 17935UL) ? "CV16CW7LAST4" : \
  (((VALUE) == 22031UL) ? "CV16CW7LAST5" : \
  (((VALUE) == 26127UL) ? "CV16CW7LAST6" : \
  (((VALUE) == 5903UL) ? "CV16CW8LAST1" : \
  (((VALUE) == 9999UL) ? "CV16CW8LAST2" : \
  (((VALUE) == 14095UL) ? "CV16CW8LAST3" : \
  (((VALUE) == 18191UL) ? "CV16CW8LAST4" : \
  (((VALUE) == 22287UL) ? "CV16CW8LAST5" : \
  (((VALUE) == 26383UL) ? "CV16CW8LAST6" : \
  (((VALUE) == 30479UL) ? "CV16CW8LAST7" : \
  (((VALUE) == 4383UL) ? "CV32CW2LAST1" : \
  (((VALUE) == 4639UL) ? "CV32CW3LAST1" : \
  (((VALUE) == 8735UL) ? "CV32CW3LAST2" : \
  (((VALUE) == 4895UL) ? "CV32CW4LAST1" : \
  (((VALUE) == 8991UL) ? "CV32CW4LAST2" : \
  (((VALUE) == 13087UL) ? "CV32CW4LAST3" : \
  (((VALUE) == 5151UL) ? "CV32CW5LAST1" : \
  (((VALUE) == 9247UL) ? "CV32CW5LAST2" : \
  (((VALUE) == 13343UL) ? "CV32CW5LAST3" : \
  (((VALUE) == 17439UL) ? "CV32CW5LAST4" : \
  (((VALUE) == 5407UL) ? "CV32CW6LAST1" : \
  (((VALUE) == 9503UL) ? "CV32CW6LAST2" : \
  (((VALUE) == 13599UL) ? "CV32CW6LAST3" : \
  (((VALUE) == 17695UL) ? "CV32CW6LAST4" : \
  (((VALUE) == 21791UL) ? "CV32CW6LAST5" : \
  (((VALUE) == 5663UL) ? "CV32CW7LAST1" : \
  (((VALUE) == 9759UL) ? "CV32CW7LAST2" : \
  (((VALUE) == 13855UL) ? "CV32CW7LAST3" : \
  (((VALUE) == 17951UL) ? "CV32CW7LAST4" : \
  (((VALUE) == 22047UL) ? "CV32CW7LAST5" : \
  (((VALUE) == 26143UL) ? "CV32CW7LAST6" : \
  (((VALUE) == 5919UL) ? "CV32CW8LAST1" : \
  (((VALUE) == 10015UL) ? "CV32CW8LAST2" : \
  (((VALUE) == 14111UL) ? "CV32CW8LAST3" : \
  (((VALUE) == 18207UL) ? "CV32CW8LAST4" : \
  (((VALUE) == 22303UL) ? "CV32CW8LAST5" : \
  (((VALUE) == 26399UL) ? "CV32CW8LAST6" : \
  (((VALUE) == 30495UL) ? "CV32CW8LAST7" : \
  (((VALUE) == 4415UL) ? "CV64CW2LAST1" : \
  (((VALUE) == 4671UL) ? "CV64CW3LAST1" : \
  (((VALUE) == 8767UL) ? "CV64CW3LAST2" : \
  (((VALUE) == 4927UL) ? "CV64CW4LAST1" : \
  (((VALUE) == 9023UL) ? "CV64CW4LAST2" : \
  (((VALUE) == 13119UL) ? "CV64CW4LAST3" : \
  (((VALUE) == 5183UL) ? "CV64CW5LAST1" : \
  (((VALUE) == 9279UL) ? "CV64CW5LAST2" : \
  (((VALUE) == 13375UL) ? "CV64CW5LAST3" : \
  (((VALUE) == 17471UL) ? "CV64CW5LAST4" : \
  (((VALUE) == 5439UL) ? "CV64CW6LAST1" : \
  (((VALUE) == 9535UL) ? "CV64CW6LAST2" : \
  (((VALUE) == 13631UL) ? "CV64CW6LAST3" : \
  (((VALUE) == 17727UL) ? "CV64CW6LAST4" : \
  (((VALUE) == 21823UL) ? "CV64CW6LAST5" : \
  (((VALUE) == 5695UL) ? "CV64CW7LAST1" : \
  (((VALUE) == 9791UL) ? "CV64CW7LAST2" : \
  (((VALUE) == 13887UL) ? "CV64CW7LAST3" : \
  (((VALUE) == 17983UL) ? "CV64CW7LAST4" : \
  (((VALUE) == 22079UL) ? "CV64CW7LAST5" : \
  (((VALUE) == 26175UL) ? "CV64CW7LAST6" : \
  (((VALUE) == 5951UL) ? "CV64CW8LAST1" : \
  (((VALUE) == 10047UL) ? "CV64CW8LAST2" : \
  (((VALUE) == 14143UL) ? "CV64CW8LAST3" : \
  (((VALUE) == 18239UL) ? "CV64CW8LAST4" : \
  (((VALUE) == 22335UL) ? "CV64CW8LAST5" : \
  (((VALUE) == 26431UL) ? "CV64CW8LAST6" : \
  (((VALUE) == 30527UL) ? "CV64CW8LAST7" : \
  (((VALUE) == 4479UL) ? "CV128CW2LAST1" : \
  (((VALUE) == 4735UL) ? "CV128CW3LAST1" : \
  (((VALUE) == 8831UL) ? "CV128CW3LAST2" : \
  (((VALUE) == 4991UL) ? "CV128CW4LAST1" : \
  (((VALUE) == 9087UL) ? "CV128CW4LAST2" : \
  (((VALUE) == 13183UL) ? "CV128CW4LAST3" : \
  (((VALUE) == 5247UL) ? "CV128CW5LAST1" : \
  (((VALUE) == 9343UL) ? "CV128CW5LAST2" : \
  (((VALUE) == 13439UL) ? "CV128CW5LAST3" : \
  (((VALUE) == 17535UL) ? "CV128CW5LAST4" : \
  (((VALUE) == 5503UL) ? "CV128CW6LAST1" : \
  (((VALUE) == 9599UL) ? "CV128CW6LAST2" : \
  (((VALUE) == 13695UL) ? "CV128CW6LAST3" : \
  (((VALUE) == 17791UL) ? "CV128CW6LAST4" : \
  (((VALUE) == 21887UL) ? "CV128CW6LAST5" : \
  (((VALUE) == 5759UL) ? "CV128CW7LAST1" : \
  (((VALUE) == 9855UL) ? "CV128CW7LAST2" : \
  (((VALUE) == 13951UL) ? "CV128CW7LAST3" : \
  (((VALUE) == 18047UL) ? "CV128CW7LAST4" : \
  (((VALUE) == 22143UL) ? "CV128CW7LAST5" : \
  (((VALUE) == 26239UL) ? "CV128CW7LAST6" : \
  (((VALUE) == 6015UL) ? "CV128CW8LAST1" : \
  (((VALUE) == 10111UL) ? "CV128CW8LAST2" : \
  (((VALUE) == 14207UL) ? "CV128CW8LAST3" : \
  (((VALUE) == 18303UL) ? "CV128CW8LAST4" : \
  (((VALUE) == 22399UL) ? "CV128CW8LAST5" : \
  (((VALUE) == 26495UL) ? "CV128CW8LAST6" : \
  (((VALUE) == 30591UL) ? "CV128CW8LAST7" : \
  (((VALUE) == 4607UL) ? "CV256CW2LAST1" : \
  (((VALUE) == 4863UL) ? "CV256CW3LAST1" : \
  (((VALUE) == 8959UL) ? "CV256CW3LAST2" : \
  (((VALUE) == 5119UL) ? "CV256CW4LAST1" : \
  (((VALUE) == 9215UL) ? "CV256CW4LAST2" : \
  (((VALUE) == 13311UL) ? "CV256CW4LAST3" : \
  (((VALUE) == 5375UL) ? "CV256CW5LAST1" : \
  (((VALUE) == 9471UL) ? "CV256CW5LAST2" : \
  (((VALUE) == 13567UL) ? "CV256CW5LAST3" : \
  (((VALUE) == 17663UL) ? "CV256CW5LAST4" : \
  (((VALUE) == 5631UL) ? "CV256CW6LAST1" : \
  (((VALUE) == 9727UL) ? "CV256CW6LAST2" : \
  (((VALUE) == 13823UL) ? "CV256CW6LAST3" : \
  (((VALUE) == 17919UL) ? "CV256CW6LAST4" : \
  (((VALUE) == 22015UL) ? "CV256CW6LAST5" : \
  (((VALUE) == 5887UL) ? "CV256CW7LAST1" : \
  (((VALUE) == 9983UL) ? "CV256CW7LAST2" : \
  (((VALUE) == 14079UL) ? "CV256CW7LAST3" : \
  (((VALUE) == 18175UL) ? "CV256CW7LAST4" : \
  (((VALUE) == 22271UL) ? "CV256CW7LAST5" : \
  (((VALUE) == 26367UL) ? "CV256CW7LAST6" : \
  (((VALUE) == 6143UL) ? "CV256CW8LAST1" : \
  (((VALUE) == 10239UL) ? "CV256CW8LAST2" : \
  (((VALUE) == 14335UL) ? "CV256CW8LAST3" : \
  (((VALUE) == 18431UL) ? "CV256CW8LAST4" : \
  (((VALUE) == 22527UL) ? "CV256CW8LAST5" : \
  (((VALUE) == 26623UL) ? "CV256CW8LAST6" : \
  (((VALUE) == 30719UL) ? "CV256CW8LAST7" :  ""))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))


/**
 * Check if a value of the DECUN_BFMT set of enumerated values is valid.
 *
 * \param[in] val is the numeric value that must be checked
 *
 * \retval \e true  if \e val is a valid value of the DECUN_BFMT set of enumerated values is valid
 * \retval \e false otherwise
 */

static inline bool ATON_DECUN_BFMT_IsValid(uint32_t val)
{
  bool retval = false;

  switch (val)
  {
    case ATON_DECUN_BFMT_CV1CW1LAST0:
    case ATON_DECUN_BFMT_CV1CW2LAST0:
    case ATON_DECUN_BFMT_CV1CW3LAST0:
    case ATON_DECUN_BFMT_CV1CW4LAST0:
    case ATON_DECUN_BFMT_CV1CW5LAST0:
    case ATON_DECUN_BFMT_CV1CW6LAST0:
    case ATON_DECUN_BFMT_CV1CW7LAST0:
    case ATON_DECUN_BFMT_CV1CW8LAST0:
    case ATON_DECUN_BFMT_CV1CW2LAST1:
    case ATON_DECUN_BFMT_CV1CW3LAST1:
    case ATON_DECUN_BFMT_CV1CW4LAST1:
    case ATON_DECUN_BFMT_CV1CW5LAST1:
    case ATON_DECUN_BFMT_CV1CW6LAST1:
    case ATON_DECUN_BFMT_CV1CW7LAST1:
    case ATON_DECUN_BFMT_CV1CW8LAST1:
    case ATON_DECUN_BFMT_CV1CW3LAST2:
    case ATON_DECUN_BFMT_CV1CW4LAST2:
    case ATON_DECUN_BFMT_CV1CW5LAST2:
    case ATON_DECUN_BFMT_CV1CW6LAST2:
    case ATON_DECUN_BFMT_CV1CW7LAST2:
    case ATON_DECUN_BFMT_CV1CW8LAST2:
    case ATON_DECUN_BFMT_CV1CW4LAST3:
    case ATON_DECUN_BFMT_CV1CW5LAST3:
    case ATON_DECUN_BFMT_CV1CW6LAST3:
    case ATON_DECUN_BFMT_CV1CW7LAST3:
    case ATON_DECUN_BFMT_CV1CW8LAST3:
    case ATON_DECUN_BFMT_CV1CW5LAST4:
    case ATON_DECUN_BFMT_CV1CW6LAST4:
    case ATON_DECUN_BFMT_CV1CW7LAST4:
    case ATON_DECUN_BFMT_CV1CW8LAST4:
    case ATON_DECUN_BFMT_CV1CW6LAST5:
    case ATON_DECUN_BFMT_CV1CW7LAST5:
    case ATON_DECUN_BFMT_CV1CW8LAST5:
    case ATON_DECUN_BFMT_CV1CW7LAST6:
    case ATON_DECUN_BFMT_CV1CW8LAST6:
    case ATON_DECUN_BFMT_CV1CW8LAST7:
    case ATON_DECUN_BFMT_CV2CW1LAST0:
    case ATON_DECUN_BFMT_CV2CW2LAST0:
    case ATON_DECUN_BFMT_CV2CW3LAST0:
    case ATON_DECUN_BFMT_CV2CW4LAST0:
    case ATON_DECUN_BFMT_CV2CW5LAST0:
    case ATON_DECUN_BFMT_CV2CW6LAST0:
    case ATON_DECUN_BFMT_CV2CW7LAST0:
    case ATON_DECUN_BFMT_CV2CW8LAST0:
    case ATON_DECUN_BFMT_CV2CW2LAST1:
    case ATON_DECUN_BFMT_CV2CW3LAST1:
    case ATON_DECUN_BFMT_CV2CW4LAST1:
    case ATON_DECUN_BFMT_CV2CW5LAST1:
    case ATON_DECUN_BFMT_CV2CW6LAST1:
    case ATON_DECUN_BFMT_CV2CW7LAST1:
    case ATON_DECUN_BFMT_CV2CW8LAST1:
    case ATON_DECUN_BFMT_CV2CW3LAST2:
    case ATON_DECUN_BFMT_CV2CW4LAST2:
    case ATON_DECUN_BFMT_CV2CW5LAST2:
    case ATON_DECUN_BFMT_CV2CW6LAST2:
    case ATON_DECUN_BFMT_CV2CW7LAST2:
    case ATON_DECUN_BFMT_CV2CW8LAST2:
    case ATON_DECUN_BFMT_CV2CW4LAST3:
    case ATON_DECUN_BFMT_CV2CW5LAST3:
    case ATON_DECUN_BFMT_CV2CW6LAST3:
    case ATON_DECUN_BFMT_CV2CW7LAST3:
    case ATON_DECUN_BFMT_CV2CW8LAST3:
    case ATON_DECUN_BFMT_CV2CW5LAST4:
    case ATON_DECUN_BFMT_CV2CW6LAST4:
    case ATON_DECUN_BFMT_CV2CW7LAST4:
    case ATON_DECUN_BFMT_CV2CW8LAST4:
    case ATON_DECUN_BFMT_CV2CW6LAST5:
    case ATON_DECUN_BFMT_CV2CW7LAST5:
    case ATON_DECUN_BFMT_CV2CW8LAST5:
    case ATON_DECUN_BFMT_CV2CW7LAST6:
    case ATON_DECUN_BFMT_CV2CW8LAST6:
    case ATON_DECUN_BFMT_CV2CW8LAST7:
    case ATON_DECUN_BFMT_CV4CW1LAST0:
    case ATON_DECUN_BFMT_CV4CW2LAST0:
    case ATON_DECUN_BFMT_CV4CW3LAST0:
    case ATON_DECUN_BFMT_CV4CW4LAST0:
    case ATON_DECUN_BFMT_CV4CW5LAST0:
    case ATON_DECUN_BFMT_CV4CW6LAST0:
    case ATON_DECUN_BFMT_CV4CW7LAST0:
    case ATON_DECUN_BFMT_CV4CW8LAST0:
    case ATON_DECUN_BFMT_CV4CW2LAST1:
    case ATON_DECUN_BFMT_CV4CW3LAST1:
    case ATON_DECUN_BFMT_CV4CW4LAST1:
    case ATON_DECUN_BFMT_CV4CW5LAST1:
    case ATON_DECUN_BFMT_CV4CW6LAST1:
    case ATON_DECUN_BFMT_CV4CW7LAST1:
    case ATON_DECUN_BFMT_CV4CW8LAST1:
    case ATON_DECUN_BFMT_CV4CW3LAST2:
    case ATON_DECUN_BFMT_CV4CW4LAST2:
    case ATON_DECUN_BFMT_CV4CW5LAST2:
    case ATON_DECUN_BFMT_CV4CW6LAST2:
    case ATON_DECUN_BFMT_CV4CW7LAST2:
    case ATON_DECUN_BFMT_CV4CW8LAST2:
    case ATON_DECUN_BFMT_CV4CW4LAST3:
    case ATON_DECUN_BFMT_CV4CW5LAST3:
    case ATON_DECUN_BFMT_CV4CW6LAST3:
    case ATON_DECUN_BFMT_CV4CW7LAST3:
    case ATON_DECUN_BFMT_CV4CW8LAST3:
    case ATON_DECUN_BFMT_CV4CW5LAST4:
    case ATON_DECUN_BFMT_CV4CW6LAST4:
    case ATON_DECUN_BFMT_CV4CW7LAST4:
    case ATON_DECUN_BFMT_CV4CW8LAST4:
    case ATON_DECUN_BFMT_CV4CW6LAST5:
    case ATON_DECUN_BFMT_CV4CW7LAST5:
    case ATON_DECUN_BFMT_CV4CW8LAST5:
    case ATON_DECUN_BFMT_CV4CW7LAST6:
    case ATON_DECUN_BFMT_CV4CW8LAST6:
    case ATON_DECUN_BFMT_CV4CW8LAST7:
    case ATON_DECUN_BFMT_CV8CW1LAST0:
    case ATON_DECUN_BFMT_CV8CW2LAST0:
    case ATON_DECUN_BFMT_CV8CW3LAST0:
    case ATON_DECUN_BFMT_CV8CW4LAST0:
    case ATON_DECUN_BFMT_CV8CW5LAST0:
    case ATON_DECUN_BFMT_CV8CW6LAST0:
    case ATON_DECUN_BFMT_CV8CW7LAST0:
    case ATON_DECUN_BFMT_CV8CW8LAST0:
    case ATON_DECUN_BFMT_CV8CW2LAST1:
    case ATON_DECUN_BFMT_CV8CW3LAST1:
    case ATON_DECUN_BFMT_CV8CW4LAST1:
    case ATON_DECUN_BFMT_CV8CW5LAST1:
    case ATON_DECUN_BFMT_CV8CW6LAST1:
    case ATON_DECUN_BFMT_CV8CW7LAST1:
    case ATON_DECUN_BFMT_CV8CW8LAST1:
    case ATON_DECUN_BFMT_CV8CW3LAST2:
    case ATON_DECUN_BFMT_CV8CW4LAST2:
    case ATON_DECUN_BFMT_CV8CW5LAST2:
    case ATON_DECUN_BFMT_CV8CW6LAST2:
    case ATON_DECUN_BFMT_CV8CW7LAST2:
    case ATON_DECUN_BFMT_CV8CW8LAST2:
    case ATON_DECUN_BFMT_CV8CW4LAST3:
    case ATON_DECUN_BFMT_CV8CW5LAST3:
    case ATON_DECUN_BFMT_CV8CW6LAST3:
    case ATON_DECUN_BFMT_CV8CW7LAST3:
    case ATON_DECUN_BFMT_CV8CW8LAST3:
    case ATON_DECUN_BFMT_CV8CW5LAST4:
    case ATON_DECUN_BFMT_CV8CW6LAST4:
    case ATON_DECUN_BFMT_CV8CW7LAST4:
    case ATON_DECUN_BFMT_CV8CW8LAST4:
    case ATON_DECUN_BFMT_CV8CW6LAST5:
    case ATON_DECUN_BFMT_CV8CW7LAST5:
    case ATON_DECUN_BFMT_CV8CW8LAST5:
    case ATON_DECUN_BFMT_CV8CW7LAST6:
    case ATON_DECUN_BFMT_CV8CW8LAST6:
    case ATON_DECUN_BFMT_CV8CW8LAST7:
    case ATON_DECUN_BFMT_CV16CW1LAST0:
    case ATON_DECUN_BFMT_CV16CW2LAST0:
    case ATON_DECUN_BFMT_CV16CW3LAST0:
    case ATON_DECUN_BFMT_CV16CW4LAST0:
    case ATON_DECUN_BFMT_CV16CW5LAST0:
    case ATON_DECUN_BFMT_CV16CW6LAST0:
    case ATON_DECUN_BFMT_CV16CW7LAST0:
    case ATON_DECUN_BFMT_CV16CW8LAST0:
    case ATON_DECUN_BFMT_CV32CW1LAST0:
    case ATON_DECUN_BFMT_CV32CW2LAST0:
    case ATON_DECUN_BFMT_CV32CW3LAST0:
    case ATON_DECUN_BFMT_CV32CW4LAST0:
    case ATON_DECUN_BFMT_CV32CW5LAST0:
    case ATON_DECUN_BFMT_CV32CW6LAST0:
    case ATON_DECUN_BFMT_CV32CW7LAST0:
    case ATON_DECUN_BFMT_CV32CW8LAST0:
    case ATON_DECUN_BFMT_CV64CW1LAST0:
    case ATON_DECUN_BFMT_CV64CW2LAST0:
    case ATON_DECUN_BFMT_CV64CW3LAST0:
    case ATON_DECUN_BFMT_CV64CW4LAST0:
    case ATON_DECUN_BFMT_CV64CW5LAST0:
    case ATON_DECUN_BFMT_CV64CW6LAST0:
    case ATON_DECUN_BFMT_CV64CW7LAST0:
    case ATON_DECUN_BFMT_CV64CW8LAST0:
    case ATON_DECUN_BFMT_CV128CW1LAST0:
    case ATON_DECUN_BFMT_CV128CW2LAST0:
    case ATON_DECUN_BFMT_CV128CW3LAST0:
    case ATON_DECUN_BFMT_CV128CW4LAST0:
    case ATON_DECUN_BFMT_CV128CW5LAST0:
    case ATON_DECUN_BFMT_CV128CW6LAST0:
    case ATON_DECUN_BFMT_CV128CW7LAST0:
    case ATON_DECUN_BFMT_CV128CW8LAST0:
    case ATON_DECUN_BFMT_CV256CW1LAST0:
    case ATON_DECUN_BFMT_CV256CW2LAST0:
    case ATON_DECUN_BFMT_CV256CW3LAST0:
    case ATON_DECUN_BFMT_CV256CW4LAST0:
    case ATON_DECUN_BFMT_CV256CW5LAST0:
    case ATON_DECUN_BFMT_CV256CW6LAST0:
    case ATON_DECUN_BFMT_CV256CW7LAST0:
    case ATON_DECUN_BFMT_CV256CW8LAST0:
    case ATON_DECUN_BFMT_CV16CW2LAST1:
    case ATON_DECUN_BFMT_CV16CW3LAST1:
    case ATON_DECUN_BFMT_CV16CW3LAST2:
    case ATON_DECUN_BFMT_CV16CW4LAST1:
    case ATON_DECUN_BFMT_CV16CW4LAST2:
    case ATON_DECUN_BFMT_CV16CW4LAST3:
    case ATON_DECUN_BFMT_CV16CW5LAST1:
    case ATON_DECUN_BFMT_CV16CW5LAST2:
    case ATON_DECUN_BFMT_CV16CW5LAST3:
    case ATON_DECUN_BFMT_CV16CW5LAST4:
    case ATON_DECUN_BFMT_CV16CW6LAST1:
    case ATON_DECUN_BFMT_CV16CW6LAST2:
    case ATON_DECUN_BFMT_CV16CW6LAST3:
    case ATON_DECUN_BFMT_CV16CW6LAST4:
    case ATON_DECUN_BFMT_CV16CW6LAST5:
    case ATON_DECUN_BFMT_CV16CW7LAST1:
    case ATON_DECUN_BFMT_CV16CW7LAST2:
    case ATON_DECUN_BFMT_CV16CW7LAST3:
    case ATON_DECUN_BFMT_CV16CW7LAST4:
    case ATON_DECUN_BFMT_CV16CW7LAST5:
    case ATON_DECUN_BFMT_CV16CW7LAST6:
    case ATON_DECUN_BFMT_CV16CW8LAST1:
    case ATON_DECUN_BFMT_CV16CW8LAST2:
    case ATON_DECUN_BFMT_CV16CW8LAST3:
    case ATON_DECUN_BFMT_CV16CW8LAST4:
    case ATON_DECUN_BFMT_CV16CW8LAST5:
    case ATON_DECUN_BFMT_CV16CW8LAST6:
    case ATON_DECUN_BFMT_CV16CW8LAST7:
    case ATON_DECUN_BFMT_CV32CW2LAST1:
    case ATON_DECUN_BFMT_CV32CW3LAST1:
    case ATON_DECUN_BFMT_CV32CW3LAST2:
    case ATON_DECUN_BFMT_CV32CW4LAST1:
    case ATON_DECUN_BFMT_CV32CW4LAST2:
    case ATON_DECUN_BFMT_CV32CW4LAST3:
    case ATON_DECUN_BFMT_CV32CW5LAST1:
    case ATON_DECUN_BFMT_CV32CW5LAST2:
    case ATON_DECUN_BFMT_CV32CW5LAST3:
    case ATON_DECUN_BFMT_CV32CW5LAST4:
    case ATON_DECUN_BFMT_CV32CW6LAST1:
    case ATON_DECUN_BFMT_CV32CW6LAST2:
    case ATON_DECUN_BFMT_CV32CW6LAST3:
    case ATON_DECUN_BFMT_CV32CW6LAST4:
    case ATON_DECUN_BFMT_CV32CW6LAST5:
    case ATON_DECUN_BFMT_CV32CW7LAST1:
    case ATON_DECUN_BFMT_CV32CW7LAST2:
    case ATON_DECUN_BFMT_CV32CW7LAST3:
    case ATON_DECUN_BFMT_CV32CW7LAST4:
    case ATON_DECUN_BFMT_CV32CW7LAST5:
    case ATON_DECUN_BFMT_CV32CW7LAST6:
    case ATON_DECUN_BFMT_CV32CW8LAST1:
    case ATON_DECUN_BFMT_CV32CW8LAST2:
    case ATON_DECUN_BFMT_CV32CW8LAST3:
    case ATON_DECUN_BFMT_CV32CW8LAST4:
    case ATON_DECUN_BFMT_CV32CW8LAST5:
    case ATON_DECUN_BFMT_CV32CW8LAST6:
    case ATON_DECUN_BFMT_CV32CW8LAST7:
    case ATON_DECUN_BFMT_CV64CW2LAST1:
    case ATON_DECUN_BFMT_CV64CW3LAST1:
    case ATON_DECUN_BFMT_CV64CW3LAST2:
    case ATON_DECUN_BFMT_CV64CW4LAST1:
    case ATON_DECUN_BFMT_CV64CW4LAST2:
    case ATON_DECUN_BFMT_CV64CW4LAST3:
    case ATON_DECUN_BFMT_CV64CW5LAST1:
    case ATON_DECUN_BFMT_CV64CW5LAST2:
    case ATON_DECUN_BFMT_CV64CW5LAST3:
    case ATON_DECUN_BFMT_CV64CW5LAST4:
    case ATON_DECUN_BFMT_CV64CW6LAST1:
    case ATON_DECUN_BFMT_CV64CW6LAST2:
    case ATON_DECUN_BFMT_CV64CW6LAST3:
    case ATON_DECUN_BFMT_CV64CW6LAST4:
    case ATON_DECUN_BFMT_CV64CW6LAST5:
    case ATON_DECUN_BFMT_CV64CW7LAST1:
    case ATON_DECUN_BFMT_CV64CW7LAST2:
    case ATON_DECUN_BFMT_CV64CW7LAST3:
    case ATON_DECUN_BFMT_CV64CW7LAST4:
    case ATON_DECUN_BFMT_CV64CW7LAST5:
    case ATON_DECUN_BFMT_CV64CW7LAST6:
    case ATON_DECUN_BFMT_CV64CW8LAST1:
    case ATON_DECUN_BFMT_CV64CW8LAST2:
    case ATON_DECUN_BFMT_CV64CW8LAST3:
    case ATON_DECUN_BFMT_CV64CW8LAST4:
    case ATON_DECUN_BFMT_CV64CW8LAST5:
    case ATON_DECUN_BFMT_CV64CW8LAST6:
    case ATON_DECUN_BFMT_CV64CW8LAST7:
    case ATON_DECUN_BFMT_CV128CW2LAST1:
    case ATON_DECUN_BFMT_CV128CW3LAST1:
    case ATON_DECUN_BFMT_CV128CW3LAST2:
    case ATON_DECUN_BFMT_CV128CW4LAST1:
    case ATON_DECUN_BFMT_CV128CW4LAST2:
    case ATON_DECUN_BFMT_CV128CW4LAST3:
    case ATON_DECUN_BFMT_CV128CW5LAST1:
    case ATON_DECUN_BFMT_CV128CW5LAST2:
    case ATON_DECUN_BFMT_CV128CW5LAST3:
    case ATON_DECUN_BFMT_CV128CW5LAST4:
    case ATON_DECUN_BFMT_CV128CW6LAST1:
    case ATON_DECUN_BFMT_CV128CW6LAST2:
    case ATON_DECUN_BFMT_CV128CW6LAST3:
    case ATON_DECUN_BFMT_CV128CW6LAST4:
    case ATON_DECUN_BFMT_CV128CW6LAST5:
    case ATON_DECUN_BFMT_CV128CW7LAST1:
    case ATON_DECUN_BFMT_CV128CW7LAST2:
    case ATON_DECUN_BFMT_CV128CW7LAST3:
    case ATON_DECUN_BFMT_CV128CW7LAST4:
    case ATON_DECUN_BFMT_CV128CW7LAST5:
    case ATON_DECUN_BFMT_CV128CW7LAST6:
    case ATON_DECUN_BFMT_CV128CW8LAST1:
    case ATON_DECUN_BFMT_CV128CW8LAST2:
    case ATON_DECUN_BFMT_CV128CW8LAST3:
    case ATON_DECUN_BFMT_CV128CW8LAST4:
    case ATON_DECUN_BFMT_CV128CW8LAST5:
    case ATON_DECUN_BFMT_CV128CW8LAST6:
    case ATON_DECUN_BFMT_CV128CW8LAST7:
    case ATON_DECUN_BFMT_CV256CW2LAST1:
    case ATON_DECUN_BFMT_CV256CW3LAST1:
    case ATON_DECUN_BFMT_CV256CW3LAST2:
    case ATON_DECUN_BFMT_CV256CW4LAST1:
    case ATON_DECUN_BFMT_CV256CW4LAST2:
    case ATON_DECUN_BFMT_CV256CW4LAST3:
    case ATON_DECUN_BFMT_CV256CW5LAST1:
    case ATON_DECUN_BFMT_CV256CW5LAST2:
    case ATON_DECUN_BFMT_CV256CW5LAST3:
    case ATON_DECUN_BFMT_CV256CW5LAST4:
    case ATON_DECUN_BFMT_CV256CW6LAST1:
    case ATON_DECUN_BFMT_CV256CW6LAST2:
    case ATON_DECUN_BFMT_CV256CW6LAST3:
    case ATON_DECUN_BFMT_CV256CW6LAST4:
    case ATON_DECUN_BFMT_CV256CW6LAST5:
    case ATON_DECUN_BFMT_CV256CW7LAST1:
    case ATON_DECUN_BFMT_CV256CW7LAST2:
    case ATON_DECUN_BFMT_CV256CW7LAST3:
    case ATON_DECUN_BFMT_CV256CW7LAST4:
    case ATON_DECUN_BFMT_CV256CW7LAST5:
    case ATON_DECUN_BFMT_CV256CW7LAST6:
    case ATON_DECUN_BFMT_CV256CW8LAST1:
    case ATON_DECUN_BFMT_CV256CW8LAST2:
    case ATON_DECUN_BFMT_CV256CW8LAST3:
    case ATON_DECUN_BFMT_CV256CW8LAST4:
    case ATON_DECUN_BFMT_CV256CW8LAST5:
    case ATON_DECUN_BFMT_CV256CW8LAST6:
    case ATON_DECUN_BFMT_CV256CW8LAST7:
      retval = true;
      break;

    default:
      break;
  }

  return retval;
}


/**
 * Get the name of one of the values of the DECUN_BFMT set of enumerated values.
 *
 * \param[in] val is the numeric value whose name must be returned
 *
 * \return the name of value \e val of the DECUN_BFMT set of enumerated values
 */

static inline const int8_t *ATON_DECUN_BFMT_GetName(uint32_t val)
{
  const int8_t *str = NULL;

  switch (val)
  {
    case ATON_DECUN_BFMT_CV1CW1LAST0:
      str = (const int8_t *)"CV1CW1LAST0";
      break;

    case ATON_DECUN_BFMT_CV1CW2LAST0:
      str = (const int8_t *)"CV1CW2LAST0";
      break;

    case ATON_DECUN_BFMT_CV1CW3LAST0:
      str = (const int8_t *)"CV1CW3LAST0";
      break;

    case ATON_DECUN_BFMT_CV1CW4LAST0:
      str = (const int8_t *)"CV1CW4LAST0";
      break;

    case ATON_DECUN_BFMT_CV1CW5LAST0:
      str = (const int8_t *)"CV1CW5LAST0";
      break;

    case ATON_DECUN_BFMT_CV1CW6LAST0:
      str = (const int8_t *)"CV1CW6LAST0";
      break;

    case ATON_DECUN_BFMT_CV1CW7LAST0:
      str = (const int8_t *)"CV1CW7LAST0";
      break;

    case ATON_DECUN_BFMT_CV1CW8LAST0:
      str = (const int8_t *)"CV1CW8LAST0";
      break;

    case ATON_DECUN_BFMT_CV1CW2LAST1:
      str = (const int8_t *)"CV1CW2LAST1";
      break;

    case ATON_DECUN_BFMT_CV1CW3LAST1:
      str = (const int8_t *)"CV1CW3LAST1";
      break;

    case ATON_DECUN_BFMT_CV1CW4LAST1:
      str = (const int8_t *)"CV1CW4LAST1";
      break;

    case ATON_DECUN_BFMT_CV1CW5LAST1:
      str = (const int8_t *)"CV1CW5LAST1";
      break;

    case ATON_DECUN_BFMT_CV1CW6LAST1:
      str = (const int8_t *)"CV1CW6LAST1";
      break;

    case ATON_DECUN_BFMT_CV1CW7LAST1:
      str = (const int8_t *)"CV1CW7LAST1";
      break;

    case ATON_DECUN_BFMT_CV1CW8LAST1:
      str = (const int8_t *)"CV1CW8LAST1";
      break;

    case ATON_DECUN_BFMT_CV1CW3LAST2:
      str = (const int8_t *)"CV1CW3LAST2";
      break;

    case ATON_DECUN_BFMT_CV1CW4LAST2:
      str = (const int8_t *)"CV1CW4LAST2";
      break;

    case ATON_DECUN_BFMT_CV1CW5LAST2:
      str = (const int8_t *)"CV1CW5LAST2";
      break;

    case ATON_DECUN_BFMT_CV1CW6LAST2:
      str = (const int8_t *)"CV1CW6LAST2";
      break;

    case ATON_DECUN_BFMT_CV1CW7LAST2:
      str = (const int8_t *)"CV1CW7LAST2";
      break;

    case ATON_DECUN_BFMT_CV1CW8LAST2:
      str = (const int8_t *)"CV1CW8LAST2";
      break;

    case ATON_DECUN_BFMT_CV1CW4LAST3:
      str = (const int8_t *)"CV1CW4LAST3";
      break;

    case ATON_DECUN_BFMT_CV1CW5LAST3:
      str = (const int8_t *)"CV1CW5LAST3";
      break;

    case ATON_DECUN_BFMT_CV1CW6LAST3:
      str = (const int8_t *)"CV1CW6LAST3";
      break;

    case ATON_DECUN_BFMT_CV1CW7LAST3:
      str = (const int8_t *)"CV1CW7LAST3";
      break;

    case ATON_DECUN_BFMT_CV1CW8LAST3:
      str = (const int8_t *)"CV1CW8LAST3";
      break;

    case ATON_DECUN_BFMT_CV1CW5LAST4:
      str = (const int8_t *)"CV1CW5LAST4";
      break;

    case ATON_DECUN_BFMT_CV1CW6LAST4:
      str = (const int8_t *)"CV1CW6LAST4";
      break;

    case ATON_DECUN_BFMT_CV1CW7LAST4:
      str = (const int8_t *)"CV1CW7LAST4";
      break;

    case ATON_DECUN_BFMT_CV1CW8LAST4:
      str = (const int8_t *)"CV1CW8LAST4";
      break;

    case ATON_DECUN_BFMT_CV1CW6LAST5:
      str = (const int8_t *)"CV1CW6LAST5";
      break;

    case ATON_DECUN_BFMT_CV1CW7LAST5:
      str = (const int8_t *)"CV1CW7LAST5";
      break;

    case ATON_DECUN_BFMT_CV1CW8LAST5:
      str = (const int8_t *)"CV1CW8LAST5";
      break;

    case ATON_DECUN_BFMT_CV1CW7LAST6:
      str = (const int8_t *)"CV1CW7LAST6";
      break;

    case ATON_DECUN_BFMT_CV1CW8LAST6:
      str = (const int8_t *)"CV1CW8LAST6";
      break;

    case ATON_DECUN_BFMT_CV1CW8LAST7:
      str = (const int8_t *)"CV1CW8LAST7";
      break;

    case ATON_DECUN_BFMT_CV2CW1LAST0:
      str = (const int8_t *)"CV2CW1LAST0";
      break;

    case ATON_DECUN_BFMT_CV2CW2LAST0:
      str = (const int8_t *)"CV2CW2LAST0";
      break;

    case ATON_DECUN_BFMT_CV2CW3LAST0:
      str = (const int8_t *)"CV2CW3LAST0";
      break;

    case ATON_DECUN_BFMT_CV2CW4LAST0:
      str = (const int8_t *)"CV2CW4LAST0";
      break;

    case ATON_DECUN_BFMT_CV2CW5LAST0:
      str = (const int8_t *)"CV2CW5LAST0";
      break;

    case ATON_DECUN_BFMT_CV2CW6LAST0:
      str = (const int8_t *)"CV2CW6LAST0";
      break;

    case ATON_DECUN_BFMT_CV2CW7LAST0:
      str = (const int8_t *)"CV2CW7LAST0";
      break;

    case ATON_DECUN_BFMT_CV2CW8LAST0:
      str = (const int8_t *)"CV2CW8LAST0";
      break;

    case ATON_DECUN_BFMT_CV2CW2LAST1:
      str = (const int8_t *)"CV2CW2LAST1";
      break;

    case ATON_DECUN_BFMT_CV2CW3LAST1:
      str = (const int8_t *)"CV2CW3LAST1";
      break;

    case ATON_DECUN_BFMT_CV2CW4LAST1:
      str = (const int8_t *)"CV2CW4LAST1";
      break;

    case ATON_DECUN_BFMT_CV2CW5LAST1:
      str = (const int8_t *)"CV2CW5LAST1";
      break;

    case ATON_DECUN_BFMT_CV2CW6LAST1:
      str = (const int8_t *)"CV2CW6LAST1";
      break;

    case ATON_DECUN_BFMT_CV2CW7LAST1:
      str = (const int8_t *)"CV2CW7LAST1";
      break;

    case ATON_DECUN_BFMT_CV2CW8LAST1:
      str = (const int8_t *)"CV2CW8LAST1";
      break;

    case ATON_DECUN_BFMT_CV2CW3LAST2:
      str = (const int8_t *)"CV2CW3LAST2";
      break;

    case ATON_DECUN_BFMT_CV2CW4LAST2:
      str = (const int8_t *)"CV2CW4LAST2";
      break;

    case ATON_DECUN_BFMT_CV2CW5LAST2:
      str = (const int8_t *)"CV2CW5LAST2";
      break;

    case ATON_DECUN_BFMT_CV2CW6LAST2:
      str = (const int8_t *)"CV2CW6LAST2";
      break;

    case ATON_DECUN_BFMT_CV2CW7LAST2:
      str = (const int8_t *)"CV2CW7LAST2";
      break;

    case ATON_DECUN_BFMT_CV2CW8LAST2:
      str = (const int8_t *)"CV2CW8LAST2";
      break;

    case ATON_DECUN_BFMT_CV2CW4LAST3:
      str = (const int8_t *)"CV2CW4LAST3";
      break;

    case ATON_DECUN_BFMT_CV2CW5LAST3:
      str = (const int8_t *)"CV2CW5LAST3";
      break;

    case ATON_DECUN_BFMT_CV2CW6LAST3:
      str = (const int8_t *)"CV2CW6LAST3";
      break;

    case ATON_DECUN_BFMT_CV2CW7LAST3:
      str = (const int8_t *)"CV2CW7LAST3";
      break;

    case ATON_DECUN_BFMT_CV2CW8LAST3:
      str = (const int8_t *)"CV2CW8LAST3";
      break;

    case ATON_DECUN_BFMT_CV2CW5LAST4:
      str = (const int8_t *)"CV2CW5LAST4";
      break;

    case ATON_DECUN_BFMT_CV2CW6LAST4:
      str = (const int8_t *)"CV2CW6LAST4";
      break;

    case ATON_DECUN_BFMT_CV2CW7LAST4:
      str = (const int8_t *)"CV2CW7LAST4";
      break;

    case ATON_DECUN_BFMT_CV2CW8LAST4:
      str = (const int8_t *)"CV2CW8LAST4";
      break;

    case ATON_DECUN_BFMT_CV2CW6LAST5:
      str = (const int8_t *)"CV2CW6LAST5";
      break;

    case ATON_DECUN_BFMT_CV2CW7LAST5:
      str = (const int8_t *)"CV2CW7LAST5";
      break;

    case ATON_DECUN_BFMT_CV2CW8LAST5:
      str = (const int8_t *)"CV2CW8LAST5";
      break;

    case ATON_DECUN_BFMT_CV2CW7LAST6:
      str = (const int8_t *)"CV2CW7LAST6";
      break;

    case ATON_DECUN_BFMT_CV2CW8LAST6:
      str = (const int8_t *)"CV2CW8LAST6";
      break;

    case ATON_DECUN_BFMT_CV2CW8LAST7:
      str = (const int8_t *)"CV2CW8LAST7";
      break;

    case ATON_DECUN_BFMT_CV4CW1LAST0:
      str = (const int8_t *)"CV4CW1LAST0";
      break;

    case ATON_DECUN_BFMT_CV4CW2LAST0:
      str = (const int8_t *)"CV4CW2LAST0";
      break;

    case ATON_DECUN_BFMT_CV4CW3LAST0:
      str = (const int8_t *)"CV4CW3LAST0";
      break;

    case ATON_DECUN_BFMT_CV4CW4LAST0:
      str = (const int8_t *)"CV4CW4LAST0";
      break;

    case ATON_DECUN_BFMT_CV4CW5LAST0:
      str = (const int8_t *)"CV4CW5LAST0";
      break;

    case ATON_DECUN_BFMT_CV4CW6LAST0:
      str = (const int8_t *)"CV4CW6LAST0";
      break;

    case ATON_DECUN_BFMT_CV4CW7LAST0:
      str = (const int8_t *)"CV4CW7LAST0";
      break;

    case ATON_DECUN_BFMT_CV4CW8LAST0:
      str = (const int8_t *)"CV4CW8LAST0";
      break;

    case ATON_DECUN_BFMT_CV4CW2LAST1:
      str = (const int8_t *)"CV4CW2LAST1";
      break;

    case ATON_DECUN_BFMT_CV4CW3LAST1:
      str = (const int8_t *)"CV4CW3LAST1";
      break;

    case ATON_DECUN_BFMT_CV4CW4LAST1:
      str = (const int8_t *)"CV4CW4LAST1";
      break;

    case ATON_DECUN_BFMT_CV4CW5LAST1:
      str = (const int8_t *)"CV4CW5LAST1";
      break;

    case ATON_DECUN_BFMT_CV4CW6LAST1:
      str = (const int8_t *)"CV4CW6LAST1";
      break;

    case ATON_DECUN_BFMT_CV4CW7LAST1:
      str = (const int8_t *)"CV4CW7LAST1";
      break;

    case ATON_DECUN_BFMT_CV4CW8LAST1:
      str = (const int8_t *)"CV4CW8LAST1";
      break;

    case ATON_DECUN_BFMT_CV4CW3LAST2:
      str = (const int8_t *)"CV4CW3LAST2";
      break;

    case ATON_DECUN_BFMT_CV4CW4LAST2:
      str = (const int8_t *)"CV4CW4LAST2";
      break;

    case ATON_DECUN_BFMT_CV4CW5LAST2:
      str = (const int8_t *)"CV4CW5LAST2";
      break;

    case ATON_DECUN_BFMT_CV4CW6LAST2:
      str = (const int8_t *)"CV4CW6LAST2";
      break;

    case ATON_DECUN_BFMT_CV4CW7LAST2:
      str = (const int8_t *)"CV4CW7LAST2";
      break;

    case ATON_DECUN_BFMT_CV4CW8LAST2:
      str = (const int8_t *)"CV4CW8LAST2";
      break;

    case ATON_DECUN_BFMT_CV4CW4LAST3:
      str = (const int8_t *)"CV4CW4LAST3";
      break;

    case ATON_DECUN_BFMT_CV4CW5LAST3:
      str = (const int8_t *)"CV4CW5LAST3";
      break;

    case ATON_DECUN_BFMT_CV4CW6LAST3:
      str = (const int8_t *)"CV4CW6LAST3";
      break;

    case ATON_DECUN_BFMT_CV4CW7LAST3:
      str = (const int8_t *)"CV4CW7LAST3";
      break;

    case ATON_DECUN_BFMT_CV4CW8LAST3:
      str = (const int8_t *)"CV4CW8LAST3";
      break;

    case ATON_DECUN_BFMT_CV4CW5LAST4:
      str = (const int8_t *)"CV4CW5LAST4";
      break;

    case ATON_DECUN_BFMT_CV4CW6LAST4:
      str = (const int8_t *)"CV4CW6LAST4";
      break;

    case ATON_DECUN_BFMT_CV4CW7LAST4:
      str = (const int8_t *)"CV4CW7LAST4";
      break;

    case ATON_DECUN_BFMT_CV4CW8LAST4:
      str = (const int8_t *)"CV4CW8LAST4";
      break;

    case ATON_DECUN_BFMT_CV4CW6LAST5:
      str = (const int8_t *)"CV4CW6LAST5";
      break;

    case ATON_DECUN_BFMT_CV4CW7LAST5:
      str = (const int8_t *)"CV4CW7LAST5";
      break;

    case ATON_DECUN_BFMT_CV4CW8LAST5:
      str = (const int8_t *)"CV4CW8LAST5";
      break;

    case ATON_DECUN_BFMT_CV4CW7LAST6:
      str = (const int8_t *)"CV4CW7LAST6";
      break;

    case ATON_DECUN_BFMT_CV4CW8LAST6:
      str = (const int8_t *)"CV4CW8LAST6";
      break;

    case ATON_DECUN_BFMT_CV4CW8LAST7:
      str = (const int8_t *)"CV4CW8LAST7";
      break;

    case ATON_DECUN_BFMT_CV8CW1LAST0:
      str = (const int8_t *)"CV8CW1LAST0";
      break;

    case ATON_DECUN_BFMT_CV8CW2LAST0:
      str = (const int8_t *)"CV8CW2LAST0";
      break;

    case ATON_DECUN_BFMT_CV8CW3LAST0:
      str = (const int8_t *)"CV8CW3LAST0";
      break;

    case ATON_DECUN_BFMT_CV8CW4LAST0:
      str = (const int8_t *)"CV8CW4LAST0";
      break;

    case ATON_DECUN_BFMT_CV8CW5LAST0:
      str = (const int8_t *)"CV8CW5LAST0";
      break;

    case ATON_DECUN_BFMT_CV8CW6LAST0:
      str = (const int8_t *)"CV8CW6LAST0";
      break;

    case ATON_DECUN_BFMT_CV8CW7LAST0:
      str = (const int8_t *)"CV8CW7LAST0";
      break;

    case ATON_DECUN_BFMT_CV8CW8LAST0:
      str = (const int8_t *)"CV8CW8LAST0";
      break;

    case ATON_DECUN_BFMT_CV8CW2LAST1:
      str = (const int8_t *)"CV8CW2LAST1";
      break;

    case ATON_DECUN_BFMT_CV8CW3LAST1:
      str = (const int8_t *)"CV8CW3LAST1";
      break;

    case ATON_DECUN_BFMT_CV8CW4LAST1:
      str = (const int8_t *)"CV8CW4LAST1";
      break;

    case ATON_DECUN_BFMT_CV8CW5LAST1:
      str = (const int8_t *)"CV8CW5LAST1";
      break;

    case ATON_DECUN_BFMT_CV8CW6LAST1:
      str = (const int8_t *)"CV8CW6LAST1";
      break;

    case ATON_DECUN_BFMT_CV8CW7LAST1:
      str = (const int8_t *)"CV8CW7LAST1";
      break;

    case ATON_DECUN_BFMT_CV8CW8LAST1:
      str = (const int8_t *)"CV8CW8LAST1";
      break;

    case ATON_DECUN_BFMT_CV8CW3LAST2:
      str = (const int8_t *)"CV8CW3LAST2";
      break;

    case ATON_DECUN_BFMT_CV8CW4LAST2:
      str = (const int8_t *)"CV8CW4LAST2";
      break;

    case ATON_DECUN_BFMT_CV8CW5LAST2:
      str = (const int8_t *)"CV8CW5LAST2";
      break;

    case ATON_DECUN_BFMT_CV8CW6LAST2:
      str = (const int8_t *)"CV8CW6LAST2";
      break;

    case ATON_DECUN_BFMT_CV8CW7LAST2:
      str = (const int8_t *)"CV8CW7LAST2";
      break;

    case ATON_DECUN_BFMT_CV8CW8LAST2:
      str = (const int8_t *)"CV8CW8LAST2";
      break;

    case ATON_DECUN_BFMT_CV8CW4LAST3:
      str = (const int8_t *)"CV8CW4LAST3";
      break;

    case ATON_DECUN_BFMT_CV8CW5LAST3:
      str = (const int8_t *)"CV8CW5LAST3";
      break;

    case ATON_DECUN_BFMT_CV8CW6LAST3:
      str = (const int8_t *)"CV8CW6LAST3";
      break;

    case ATON_DECUN_BFMT_CV8CW7LAST3:
      str = (const int8_t *)"CV8CW7LAST3";
      break;

    case ATON_DECUN_BFMT_CV8CW8LAST3:
      str = (const int8_t *)"CV8CW8LAST3";
      break;

    case ATON_DECUN_BFMT_CV8CW5LAST4:
      str = (const int8_t *)"CV8CW5LAST4";
      break;

    case ATON_DECUN_BFMT_CV8CW6LAST4:
      str = (const int8_t *)"CV8CW6LAST4";
      break;

    case ATON_DECUN_BFMT_CV8CW7LAST4:
      str = (const int8_t *)"CV8CW7LAST4";
      break;

    case ATON_DECUN_BFMT_CV8CW8LAST4:
      str = (const int8_t *)"CV8CW8LAST4";
      break;

    case ATON_DECUN_BFMT_CV8CW6LAST5:
      str = (const int8_t *)"CV8CW6LAST5";
      break;

    case ATON_DECUN_BFMT_CV8CW7LAST5:
      str = (const int8_t *)"CV8CW7LAST5";
      break;

    case ATON_DECUN_BFMT_CV8CW8LAST5:
      str = (const int8_t *)"CV8CW8LAST5";
      break;

    case ATON_DECUN_BFMT_CV8CW7LAST6:
      str = (const int8_t *)"CV8CW7LAST6";
      break;

    case ATON_DECUN_BFMT_CV8CW8LAST6:
      str = (const int8_t *)"CV8CW8LAST6";
      break;

    case ATON_DECUN_BFMT_CV8CW8LAST7:
      str = (const int8_t *)"CV8CW8LAST7";
      break;

    case ATON_DECUN_BFMT_CV16CW1LAST0:
      str = (const int8_t *)"CV16CW1LAST0";
      break;

    case ATON_DECUN_BFMT_CV16CW2LAST0:
      str = (const int8_t *)"CV16CW2LAST0";
      break;

    case ATON_DECUN_BFMT_CV16CW3LAST0:
      str = (const int8_t *)"CV16CW3LAST0";
      break;

    case ATON_DECUN_BFMT_CV16CW4LAST0:
      str = (const int8_t *)"CV16CW4LAST0";
      break;

    case ATON_DECUN_BFMT_CV16CW5LAST0:
      str = (const int8_t *)"CV16CW5LAST0";
      break;

    case ATON_DECUN_BFMT_CV16CW6LAST0:
      str = (const int8_t *)"CV16CW6LAST0";
      break;

    case ATON_DECUN_BFMT_CV16CW7LAST0:
      str = (const int8_t *)"CV16CW7LAST0";
      break;

    case ATON_DECUN_BFMT_CV16CW8LAST0:
      str = (const int8_t *)"CV16CW8LAST0";
      break;

    case ATON_DECUN_BFMT_CV32CW1LAST0:
      str = (const int8_t *)"CV32CW1LAST0";
      break;

    case ATON_DECUN_BFMT_CV32CW2LAST0:
      str = (const int8_t *)"CV32CW2LAST0";
      break;

    case ATON_DECUN_BFMT_CV32CW3LAST0:
      str = (const int8_t *)"CV32CW3LAST0";
      break;

    case ATON_DECUN_BFMT_CV32CW4LAST0:
      str = (const int8_t *)"CV32CW4LAST0";
      break;

    case ATON_DECUN_BFMT_CV32CW5LAST0:
      str = (const int8_t *)"CV32CW5LAST0";
      break;

    case ATON_DECUN_BFMT_CV32CW6LAST0:
      str = (const int8_t *)"CV32CW6LAST0";
      break;

    case ATON_DECUN_BFMT_CV32CW7LAST0:
      str = (const int8_t *)"CV32CW7LAST0";
      break;

    case ATON_DECUN_BFMT_CV32CW8LAST0:
      str = (const int8_t *)"CV32CW8LAST0";
      break;

    case ATON_DECUN_BFMT_CV64CW1LAST0:
      str = (const int8_t *)"CV64CW1LAST0";
      break;

    case ATON_DECUN_BFMT_CV64CW2LAST0:
      str = (const int8_t *)"CV64CW2LAST0";
      break;

    case ATON_DECUN_BFMT_CV64CW3LAST0:
      str = (const int8_t *)"CV64CW3LAST0";
      break;

    case ATON_DECUN_BFMT_CV64CW4LAST0:
      str = (const int8_t *)"CV64CW4LAST0";
      break;

    case ATON_DECUN_BFMT_CV64CW5LAST0:
      str = (const int8_t *)"CV64CW5LAST0";
      break;

    case ATON_DECUN_BFMT_CV64CW6LAST0:
      str = (const int8_t *)"CV64CW6LAST0";
      break;

    case ATON_DECUN_BFMT_CV64CW7LAST0:
      str = (const int8_t *)"CV64CW7LAST0";
      break;

    case ATON_DECUN_BFMT_CV64CW8LAST0:
      str = (const int8_t *)"CV64CW8LAST0";
      break;

    case ATON_DECUN_BFMT_CV128CW1LAST0:
      str = (const int8_t *)"CV128CW1LAST0";
      break;

    case ATON_DECUN_BFMT_CV128CW2LAST0:
      str = (const int8_t *)"CV128CW2LAST0";
      break;

    case ATON_DECUN_BFMT_CV128CW3LAST0:
      str = (const int8_t *)"CV128CW3LAST0";
      break;

    case ATON_DECUN_BFMT_CV128CW4LAST0:
      str = (const int8_t *)"CV128CW4LAST0";
      break;

    case ATON_DECUN_BFMT_CV128CW5LAST0:
      str = (const int8_t *)"CV128CW5LAST0";
      break;

    case ATON_DECUN_BFMT_CV128CW6LAST0:
      str = (const int8_t *)"CV128CW6LAST0";
      break;

    case ATON_DECUN_BFMT_CV128CW7LAST0:
      str = (const int8_t *)"CV128CW7LAST0";
      break;

    case ATON_DECUN_BFMT_CV128CW8LAST0:
      str = (const int8_t *)"CV128CW8LAST0";
      break;

    case ATON_DECUN_BFMT_CV256CW1LAST0:
      str = (const int8_t *)"CV256CW1LAST0";
      break;

    case ATON_DECUN_BFMT_CV256CW2LAST0:
      str = (const int8_t *)"CV256CW2LAST0";
      break;

    case ATON_DECUN_BFMT_CV256CW3LAST0:
      str = (const int8_t *)"CV256CW3LAST0";
      break;

    case ATON_DECUN_BFMT_CV256CW4LAST0:
      str = (const int8_t *)"CV256CW4LAST0";
      break;

    case ATON_DECUN_BFMT_CV256CW5LAST0:
      str = (const int8_t *)"CV256CW5LAST0";
      break;

    case ATON_DECUN_BFMT_CV256CW6LAST0:
      str = (const int8_t *)"CV256CW6LAST0";
      break;

    case ATON_DECUN_BFMT_CV256CW7LAST0:
      str = (const int8_t *)"CV256CW7LAST0";
      break;

    case ATON_DECUN_BFMT_CV256CW8LAST0:
      str = (const int8_t *)"CV256CW8LAST0";
      break;

    case ATON_DECUN_BFMT_CV16CW2LAST1:
      str = (const int8_t *)"CV16CW2LAST1";
      break;

    case ATON_DECUN_BFMT_CV16CW3LAST1:
      str = (const int8_t *)"CV16CW3LAST1";
      break;

    case ATON_DECUN_BFMT_CV16CW3LAST2:
      str = (const int8_t *)"CV16CW3LAST2";
      break;

    case ATON_DECUN_BFMT_CV16CW4LAST1:
      str = (const int8_t *)"CV16CW4LAST1";
      break;

    case ATON_DECUN_BFMT_CV16CW4LAST2:
      str = (const int8_t *)"CV16CW4LAST2";
      break;

    case ATON_DECUN_BFMT_CV16CW4LAST3:
      str = (const int8_t *)"CV16CW4LAST3";
      break;

    case ATON_DECUN_BFMT_CV16CW5LAST1:
      str = (const int8_t *)"CV16CW5LAST1";
      break;

    case ATON_DECUN_BFMT_CV16CW5LAST2:
      str = (const int8_t *)"CV16CW5LAST2";
      break;

    case ATON_DECUN_BFMT_CV16CW5LAST3:
      str = (const int8_t *)"CV16CW5LAST3";
      break;

    case ATON_DECUN_BFMT_CV16CW5LAST4:
      str = (const int8_t *)"CV16CW5LAST4";
      break;

    case ATON_DECUN_BFMT_CV16CW6LAST1:
      str = (const int8_t *)"CV16CW6LAST1";
      break;

    case ATON_DECUN_BFMT_CV16CW6LAST2:
      str = (const int8_t *)"CV16CW6LAST2";
      break;

    case ATON_DECUN_BFMT_CV16CW6LAST3:
      str = (const int8_t *)"CV16CW6LAST3";
      break;

    case ATON_DECUN_BFMT_CV16CW6LAST4:
      str = (const int8_t *)"CV16CW6LAST4";
      break;

    case ATON_DECUN_BFMT_CV16CW6LAST5:
      str = (const int8_t *)"CV16CW6LAST5";
      break;

    case ATON_DECUN_BFMT_CV16CW7LAST1:
      str = (const int8_t *)"CV16CW7LAST1";
      break;

    case ATON_DECUN_BFMT_CV16CW7LAST2:
      str = (const int8_t *)"CV16CW7LAST2";
      break;

    case ATON_DECUN_BFMT_CV16CW7LAST3:
      str = (const int8_t *)"CV16CW7LAST3";
      break;

    case ATON_DECUN_BFMT_CV16CW7LAST4:
      str = (const int8_t *)"CV16CW7LAST4";
      break;

    case ATON_DECUN_BFMT_CV16CW7LAST5:
      str = (const int8_t *)"CV16CW7LAST5";
      break;

    case ATON_DECUN_BFMT_CV16CW7LAST6:
      str = (const int8_t *)"CV16CW7LAST6";
      break;

    case ATON_DECUN_BFMT_CV16CW8LAST1:
      str = (const int8_t *)"CV16CW8LAST1";
      break;

    case ATON_DECUN_BFMT_CV16CW8LAST2:
      str = (const int8_t *)"CV16CW8LAST2";
      break;

    case ATON_DECUN_BFMT_CV16CW8LAST3:
      str = (const int8_t *)"CV16CW8LAST3";
      break;

    case ATON_DECUN_BFMT_CV16CW8LAST4:
      str = (const int8_t *)"CV16CW8LAST4";
      break;

    case ATON_DECUN_BFMT_CV16CW8LAST5:
      str = (const int8_t *)"CV16CW8LAST5";
      break;

    case ATON_DECUN_BFMT_CV16CW8LAST6:
      str = (const int8_t *)"CV16CW8LAST6";
      break;

    case ATON_DECUN_BFMT_CV16CW8LAST7:
      str = (const int8_t *)"CV16CW8LAST7";
      break;

    case ATON_DECUN_BFMT_CV32CW2LAST1:
      str = (const int8_t *)"CV32CW2LAST1";
      break;

    case ATON_DECUN_BFMT_CV32CW3LAST1:
      str = (const int8_t *)"CV32CW3LAST1";
      break;

    case ATON_DECUN_BFMT_CV32CW3LAST2:
      str = (const int8_t *)"CV32CW3LAST2";
      break;

    case ATON_DECUN_BFMT_CV32CW4LAST1:
      str = (const int8_t *)"CV32CW4LAST1";
      break;

    case ATON_DECUN_BFMT_CV32CW4LAST2:
      str = (const int8_t *)"CV32CW4LAST2";
      break;

    case ATON_DECUN_BFMT_CV32CW4LAST3:
      str = (const int8_t *)"CV32CW4LAST3";
      break;

    case ATON_DECUN_BFMT_CV32CW5LAST1:
      str = (const int8_t *)"CV32CW5LAST1";
      break;

    case ATON_DECUN_BFMT_CV32CW5LAST2:
      str = (const int8_t *)"CV32CW5LAST2";
      break;

    case ATON_DECUN_BFMT_CV32CW5LAST3:
      str = (const int8_t *)"CV32CW5LAST3";
      break;

    case ATON_DECUN_BFMT_CV32CW5LAST4:
      str = (const int8_t *)"CV32CW5LAST4";
      break;

    case ATON_DECUN_BFMT_CV32CW6LAST1:
      str = (const int8_t *)"CV32CW6LAST1";
      break;

    case ATON_DECUN_BFMT_CV32CW6LAST2:
      str = (const int8_t *)"CV32CW6LAST2";
      break;

    case ATON_DECUN_BFMT_CV32CW6LAST3:
      str = (const int8_t *)"CV32CW6LAST3";
      break;

    case ATON_DECUN_BFMT_CV32CW6LAST4:
      str = (const int8_t *)"CV32CW6LAST4";
      break;

    case ATON_DECUN_BFMT_CV32CW6LAST5:
      str = (const int8_t *)"CV32CW6LAST5";
      break;

    case ATON_DECUN_BFMT_CV32CW7LAST1:
      str = (const int8_t *)"CV32CW7LAST1";
      break;

    case ATON_DECUN_BFMT_CV32CW7LAST2:
      str = (const int8_t *)"CV32CW7LAST2";
      break;

    case ATON_DECUN_BFMT_CV32CW7LAST3:
      str = (const int8_t *)"CV32CW7LAST3";
      break;

    case ATON_DECUN_BFMT_CV32CW7LAST4:
      str = (const int8_t *)"CV32CW7LAST4";
      break;

    case ATON_DECUN_BFMT_CV32CW7LAST5:
      str = (const int8_t *)"CV32CW7LAST5";
      break;

    case ATON_DECUN_BFMT_CV32CW7LAST6:
      str = (const int8_t *)"CV32CW7LAST6";
      break;

    case ATON_DECUN_BFMT_CV32CW8LAST1:
      str = (const int8_t *)"CV32CW8LAST1";
      break;

    case ATON_DECUN_BFMT_CV32CW8LAST2:
      str = (const int8_t *)"CV32CW8LAST2";
      break;

    case ATON_DECUN_BFMT_CV32CW8LAST3:
      str = (const int8_t *)"CV32CW8LAST3";
      break;

    case ATON_DECUN_BFMT_CV32CW8LAST4:
      str = (const int8_t *)"CV32CW8LAST4";
      break;

    case ATON_DECUN_BFMT_CV32CW8LAST5:
      str = (const int8_t *)"CV32CW8LAST5";
      break;

    case ATON_DECUN_BFMT_CV32CW8LAST6:
      str = (const int8_t *)"CV32CW8LAST6";
      break;

    case ATON_DECUN_BFMT_CV32CW8LAST7:
      str = (const int8_t *)"CV32CW8LAST7";
      break;

    case ATON_DECUN_BFMT_CV64CW2LAST1:
      str = (const int8_t *)"CV64CW2LAST1";
      break;

    case ATON_DECUN_BFMT_CV64CW3LAST1:
      str = (const int8_t *)"CV64CW3LAST1";
      break;

    case ATON_DECUN_BFMT_CV64CW3LAST2:
      str = (const int8_t *)"CV64CW3LAST2";
      break;

    case ATON_DECUN_BFMT_CV64CW4LAST1:
      str = (const int8_t *)"CV64CW4LAST1";
      break;

    case ATON_DECUN_BFMT_CV64CW4LAST2:
      str = (const int8_t *)"CV64CW4LAST2";
      break;

    case ATON_DECUN_BFMT_CV64CW4LAST3:
      str = (const int8_t *)"CV64CW4LAST3";
      break;

    case ATON_DECUN_BFMT_CV64CW5LAST1:
      str = (const int8_t *)"CV64CW5LAST1";
      break;

    case ATON_DECUN_BFMT_CV64CW5LAST2:
      str = (const int8_t *)"CV64CW5LAST2";
      break;

    case ATON_DECUN_BFMT_CV64CW5LAST3:
      str = (const int8_t *)"CV64CW5LAST3";
      break;

    case ATON_DECUN_BFMT_CV64CW5LAST4:
      str = (const int8_t *)"CV64CW5LAST4";
      break;

    case ATON_DECUN_BFMT_CV64CW6LAST1:
      str = (const int8_t *)"CV64CW6LAST1";
      break;

    case ATON_DECUN_BFMT_CV64CW6LAST2:
      str = (const int8_t *)"CV64CW6LAST2";
      break;

    case ATON_DECUN_BFMT_CV64CW6LAST3:
      str = (const int8_t *)"CV64CW6LAST3";
      break;

    case ATON_DECUN_BFMT_CV64CW6LAST4:
      str = (const int8_t *)"CV64CW6LAST4";
      break;

    case ATON_DECUN_BFMT_CV64CW6LAST5:
      str = (const int8_t *)"CV64CW6LAST5";
      break;

    case ATON_DECUN_BFMT_CV64CW7LAST1:
      str = (const int8_t *)"CV64CW7LAST1";
      break;

    case ATON_DECUN_BFMT_CV64CW7LAST2:
      str = (const int8_t *)"CV64CW7LAST2";
      break;

    case ATON_DECUN_BFMT_CV64CW7LAST3:
      str = (const int8_t *)"CV64CW7LAST3";
      break;

    case ATON_DECUN_BFMT_CV64CW7LAST4:
      str = (const int8_t *)"CV64CW7LAST4";
      break;

    case ATON_DECUN_BFMT_CV64CW7LAST5:
      str = (const int8_t *)"CV64CW7LAST5";
      break;

    case ATON_DECUN_BFMT_CV64CW7LAST6:
      str = (const int8_t *)"CV64CW7LAST6";
      break;

    case ATON_DECUN_BFMT_CV64CW8LAST1:
      str = (const int8_t *)"CV64CW8LAST1";
      break;

    case ATON_DECUN_BFMT_CV64CW8LAST2:
      str = (const int8_t *)"CV64CW8LAST2";
      break;

    case ATON_DECUN_BFMT_CV64CW8LAST3:
      str = (const int8_t *)"CV64CW8LAST3";
      break;

    case ATON_DECUN_BFMT_CV64CW8LAST4:
      str = (const int8_t *)"CV64CW8LAST4";
      break;

    case ATON_DECUN_BFMT_CV64CW8LAST5:
      str = (const int8_t *)"CV64CW8LAST5";
      break;

    case ATON_DECUN_BFMT_CV64CW8LAST6:
      str = (const int8_t *)"CV64CW8LAST6";
      break;

    case ATON_DECUN_BFMT_CV64CW8LAST7:
      str = (const int8_t *)"CV64CW8LAST7";
      break;

    case ATON_DECUN_BFMT_CV128CW2LAST1:
      str = (const int8_t *)"CV128CW2LAST1";
      break;

    case ATON_DECUN_BFMT_CV128CW3LAST1:
      str = (const int8_t *)"CV128CW3LAST1";
      break;

    case ATON_DECUN_BFMT_CV128CW3LAST2:
      str = (const int8_t *)"CV128CW3LAST2";
      break;

    case ATON_DECUN_BFMT_CV128CW4LAST1:
      str = (const int8_t *)"CV128CW4LAST1";
      break;

    case ATON_DECUN_BFMT_CV128CW4LAST2:
      str = (const int8_t *)"CV128CW4LAST2";
      break;

    case ATON_DECUN_BFMT_CV128CW4LAST3:
      str = (const int8_t *)"CV128CW4LAST3";
      break;

    case ATON_DECUN_BFMT_CV128CW5LAST1:
      str = (const int8_t *)"CV128CW5LAST1";
      break;

    case ATON_DECUN_BFMT_CV128CW5LAST2:
      str = (const int8_t *)"CV128CW5LAST2";
      break;

    case ATON_DECUN_BFMT_CV128CW5LAST3:
      str = (const int8_t *)"CV128CW5LAST3";
      break;

    case ATON_DECUN_BFMT_CV128CW5LAST4:
      str = (const int8_t *)"CV128CW5LAST4";
      break;

    case ATON_DECUN_BFMT_CV128CW6LAST1:
      str = (const int8_t *)"CV128CW6LAST1";
      break;

    case ATON_DECUN_BFMT_CV128CW6LAST2:
      str = (const int8_t *)"CV128CW6LAST2";
      break;

    case ATON_DECUN_BFMT_CV128CW6LAST3:
      str = (const int8_t *)"CV128CW6LAST3";
      break;

    case ATON_DECUN_BFMT_CV128CW6LAST4:
      str = (const int8_t *)"CV128CW6LAST4";
      break;

    case ATON_DECUN_BFMT_CV128CW6LAST5:
      str = (const int8_t *)"CV128CW6LAST5";
      break;

    case ATON_DECUN_BFMT_CV128CW7LAST1:
      str = (const int8_t *)"CV128CW7LAST1";
      break;

    case ATON_DECUN_BFMT_CV128CW7LAST2:
      str = (const int8_t *)"CV128CW7LAST2";
      break;

    case ATON_DECUN_BFMT_CV128CW7LAST3:
      str = (const int8_t *)"CV128CW7LAST3";
      break;

    case ATON_DECUN_BFMT_CV128CW7LAST4:
      str = (const int8_t *)"CV128CW7LAST4";
      break;

    case ATON_DECUN_BFMT_CV128CW7LAST5:
      str = (const int8_t *)"CV128CW7LAST5";
      break;

    case ATON_DECUN_BFMT_CV128CW7LAST6:
      str = (const int8_t *)"CV128CW7LAST6";
      break;

    case ATON_DECUN_BFMT_CV128CW8LAST1:
      str = (const int8_t *)"CV128CW8LAST1";
      break;

    case ATON_DECUN_BFMT_CV128CW8LAST2:
      str = (const int8_t *)"CV128CW8LAST2";
      break;

    case ATON_DECUN_BFMT_CV128CW8LAST3:
      str = (const int8_t *)"CV128CW8LAST3";
      break;

    case ATON_DECUN_BFMT_CV128CW8LAST4:
      str = (const int8_t *)"CV128CW8LAST4";
      break;

    case ATON_DECUN_BFMT_CV128CW8LAST5:
      str = (const int8_t *)"CV128CW8LAST5";
      break;

    case ATON_DECUN_BFMT_CV128CW8LAST6:
      str = (const int8_t *)"CV128CW8LAST6";
      break;

    case ATON_DECUN_BFMT_CV128CW8LAST7:
      str = (const int8_t *)"CV128CW8LAST7";
      break;

    case ATON_DECUN_BFMT_CV256CW2LAST1:
      str = (const int8_t *)"CV256CW2LAST1";
      break;

    case ATON_DECUN_BFMT_CV256CW3LAST1:
      str = (const int8_t *)"CV256CW3LAST1";
      break;

    case ATON_DECUN_BFMT_CV256CW3LAST2:
      str = (const int8_t *)"CV256CW3LAST2";
      break;

    case ATON_DECUN_BFMT_CV256CW4LAST1:
      str = (const int8_t *)"CV256CW4LAST1";
      break;

    case ATON_DECUN_BFMT_CV256CW4LAST2:
      str = (const int8_t *)"CV256CW4LAST2";
      break;

    case ATON_DECUN_BFMT_CV256CW4LAST3:
      str = (const int8_t *)"CV256CW4LAST3";
      break;

    case ATON_DECUN_BFMT_CV256CW5LAST1:
      str = (const int8_t *)"CV256CW5LAST1";
      break;

    case ATON_DECUN_BFMT_CV256CW5LAST2:
      str = (const int8_t *)"CV256CW5LAST2";
      break;

    case ATON_DECUN_BFMT_CV256CW5LAST3:
      str = (const int8_t *)"CV256CW5LAST3";
      break;

    case ATON_DECUN_BFMT_CV256CW5LAST4:
      str = (const int8_t *)"CV256CW5LAST4";
      break;

    case ATON_DECUN_BFMT_CV256CW6LAST1:
      str = (const int8_t *)"CV256CW6LAST1";
      break;

    case ATON_DECUN_BFMT_CV256CW6LAST2:
      str = (const int8_t *)"CV256CW6LAST2";
      break;

    case ATON_DECUN_BFMT_CV256CW6LAST3:
      str = (const int8_t *)"CV256CW6LAST3";
      break;

    case ATON_DECUN_BFMT_CV256CW6LAST4:
      str = (const int8_t *)"CV256CW6LAST4";
      break;

    case ATON_DECUN_BFMT_CV256CW6LAST5:
      str = (const int8_t *)"CV256CW6LAST5";
      break;

    case ATON_DECUN_BFMT_CV256CW7LAST1:
      str = (const int8_t *)"CV256CW7LAST1";
      break;

    case ATON_DECUN_BFMT_CV256CW7LAST2:
      str = (const int8_t *)"CV256CW7LAST2";
      break;

    case ATON_DECUN_BFMT_CV256CW7LAST3:
      str = (const int8_t *)"CV256CW7LAST3";
      break;

    case ATON_DECUN_BFMT_CV256CW7LAST4:
      str = (const int8_t *)"CV256CW7LAST4";
      break;

    case ATON_DECUN_BFMT_CV256CW7LAST5:
      str = (const int8_t *)"CV256CW7LAST5";
      break;

    case ATON_DECUN_BFMT_CV256CW7LAST6:
      str = (const int8_t *)"CV256CW7LAST6";
      break;

    case ATON_DECUN_BFMT_CV256CW8LAST1:
      str = (const int8_t *)"CV256CW8LAST1";
      break;

    case ATON_DECUN_BFMT_CV256CW8LAST2:
      str = (const int8_t *)"CV256CW8LAST2";
      break;

    case ATON_DECUN_BFMT_CV256CW8LAST3:
      str = (const int8_t *)"CV256CW8LAST3";
      break;

    case ATON_DECUN_BFMT_CV256CW8LAST4:
      str = (const int8_t *)"CV256CW8LAST4";
      break;

    case ATON_DECUN_BFMT_CV256CW8LAST5:
      str = (const int8_t *)"CV256CW8LAST5";
      break;

    case ATON_DECUN_BFMT_CV256CW8LAST6:
      str = (const int8_t *)"CV256CW8LAST6";
      break;

    case ATON_DECUN_BFMT_CV256CW8LAST7:
      str = (const int8_t *)"CV256CW8LAST7";
      break;

    default:
      break;
  }

  return str;
}


/**
 * Get the description of one of the values of the DECUN_BFMT set of enumerated values.
 *
 * \param[in] val is the numeric value whose description must be returned
 *
 * \return the description of value \e val of the DECUN_BFMT set of enumerated values
 */

static inline const int8_t *ATON_DECUN_BFMT_GetDesc(uint32_t val)
{
  const int8_t *str = NULL;

  switch (val)
  {
    case ATON_DECUN_BFMT_CV1CW1LAST0:
      str = (const int8_t *)"CV1CW1LAST0";
      break;

    case ATON_DECUN_BFMT_CV1CW2LAST0:
      str = (const int8_t *)"CV1CW2LAST0";
      break;

    case ATON_DECUN_BFMT_CV1CW3LAST0:
      str = (const int8_t *)"CV1CW3LAST0";
      break;

    case ATON_DECUN_BFMT_CV1CW4LAST0:
      str = (const int8_t *)"CV1CW4LAST0";
      break;

    case ATON_DECUN_BFMT_CV1CW5LAST0:
      str = (const int8_t *)"CV1CW5LAST0";
      break;

    case ATON_DECUN_BFMT_CV1CW6LAST0:
      str = (const int8_t *)"CV1CW6LAST0";
      break;

    case ATON_DECUN_BFMT_CV1CW7LAST0:
      str = (const int8_t *)"CV1CW7LAST0";
      break;

    case ATON_DECUN_BFMT_CV1CW8LAST0:
      str = (const int8_t *)"CV1CW8LAST0";
      break;

    case ATON_DECUN_BFMT_CV1CW2LAST1:
      str = (const int8_t *)"CV1CW2LAST1";
      break;

    case ATON_DECUN_BFMT_CV1CW3LAST1:
      str = (const int8_t *)"CV1CW3LAST1";
      break;

    case ATON_DECUN_BFMT_CV1CW4LAST1:
      str = (const int8_t *)"CV1CW4LAST1";
      break;

    case ATON_DECUN_BFMT_CV1CW5LAST1:
      str = (const int8_t *)"CV1CW5LAST1";
      break;

    case ATON_DECUN_BFMT_CV1CW6LAST1:
      str = (const int8_t *)"CV1CW6LAST1";
      break;

    case ATON_DECUN_BFMT_CV1CW7LAST1:
      str = (const int8_t *)"CV1CW7LAST1";
      break;

    case ATON_DECUN_BFMT_CV1CW8LAST1:
      str = (const int8_t *)"CV1CW8LAST1";
      break;

    case ATON_DECUN_BFMT_CV1CW3LAST2:
      str = (const int8_t *)"CV1CW3LAST2";
      break;

    case ATON_DECUN_BFMT_CV1CW4LAST2:
      str = (const int8_t *)"CV1CW4LAST2";
      break;

    case ATON_DECUN_BFMT_CV1CW5LAST2:
      str = (const int8_t *)"CV1CW5LAST2";
      break;

    case ATON_DECUN_BFMT_CV1CW6LAST2:
      str = (const int8_t *)"CV1CW6LAST2";
      break;

    case ATON_DECUN_BFMT_CV1CW7LAST2:
      str = (const int8_t *)"CV1CW7LAST2";
      break;

    case ATON_DECUN_BFMT_CV1CW8LAST2:
      str = (const int8_t *)"CV1CW8LAST2";
      break;

    case ATON_DECUN_BFMT_CV1CW4LAST3:
      str = (const int8_t *)"CV1CW4LAST3";
      break;

    case ATON_DECUN_BFMT_CV1CW5LAST3:
      str = (const int8_t *)"CV1CW5LAST3";
      break;

    case ATON_DECUN_BFMT_CV1CW6LAST3:
      str = (const int8_t *)"CV1CW6LAST3";
      break;

    case ATON_DECUN_BFMT_CV1CW7LAST3:
      str = (const int8_t *)"CV1CW7LAST3";
      break;

    case ATON_DECUN_BFMT_CV1CW8LAST3:
      str = (const int8_t *)"CV1CW8LAST3";
      break;

    case ATON_DECUN_BFMT_CV1CW5LAST4:
      str = (const int8_t *)"CV1CW5LAST4";
      break;

    case ATON_DECUN_BFMT_CV1CW6LAST4:
      str = (const int8_t *)"CV1CW6LAST4";
      break;

    case ATON_DECUN_BFMT_CV1CW7LAST4:
      str = (const int8_t *)"CV1CW7LAST4";
      break;

    case ATON_DECUN_BFMT_CV1CW8LAST4:
      str = (const int8_t *)"CV1CW8LAST4";
      break;

    case ATON_DECUN_BFMT_CV1CW6LAST5:
      str = (const int8_t *)"CV1CW6LAST5";
      break;

    case ATON_DECUN_BFMT_CV1CW7LAST5:
      str = (const int8_t *)"CV1CW7LAST5";
      break;

    case ATON_DECUN_BFMT_CV1CW8LAST5:
      str = (const int8_t *)"CV1CW8LAST5";
      break;

    case ATON_DECUN_BFMT_CV1CW7LAST6:
      str = (const int8_t *)"CV1CW7LAST6";
      break;

    case ATON_DECUN_BFMT_CV1CW8LAST6:
      str = (const int8_t *)"CV1CW8LAST6";
      break;

    case ATON_DECUN_BFMT_CV1CW8LAST7:
      str = (const int8_t *)"CV1CW8LAST7";
      break;

    case ATON_DECUN_BFMT_CV2CW1LAST0:
      str = (const int8_t *)"CV2CW1LAST0";
      break;

    case ATON_DECUN_BFMT_CV2CW2LAST0:
      str = (const int8_t *)"CV2CW2LAST0";
      break;

    case ATON_DECUN_BFMT_CV2CW3LAST0:
      str = (const int8_t *)"CV2CW3LAST0";
      break;

    case ATON_DECUN_BFMT_CV2CW4LAST0:
      str = (const int8_t *)"CV2CW4LAST0";
      break;

    case ATON_DECUN_BFMT_CV2CW5LAST0:
      str = (const int8_t *)"CV2CW5LAST0";
      break;

    case ATON_DECUN_BFMT_CV2CW6LAST0:
      str = (const int8_t *)"CV2CW6LAST0";
      break;

    case ATON_DECUN_BFMT_CV2CW7LAST0:
      str = (const int8_t *)"CV2CW7LAST0";
      break;

    case ATON_DECUN_BFMT_CV2CW8LAST0:
      str = (const int8_t *)"CV2CW8LAST0";
      break;

    case ATON_DECUN_BFMT_CV2CW2LAST1:
      str = (const int8_t *)"CV2CW2LAST1";
      break;

    case ATON_DECUN_BFMT_CV2CW3LAST1:
      str = (const int8_t *)"CV2CW3LAST1";
      break;

    case ATON_DECUN_BFMT_CV2CW4LAST1:
      str = (const int8_t *)"CV2CW4LAST1";
      break;

    case ATON_DECUN_BFMT_CV2CW5LAST1:
      str = (const int8_t *)"CV2CW5LAST1";
      break;

    case ATON_DECUN_BFMT_CV2CW6LAST1:
      str = (const int8_t *)"CV2CW6LAST1";
      break;

    case ATON_DECUN_BFMT_CV2CW7LAST1:
      str = (const int8_t *)"CV2CW7LAST1";
      break;

    case ATON_DECUN_BFMT_CV2CW8LAST1:
      str = (const int8_t *)"CV2CW8LAST1";
      break;

    case ATON_DECUN_BFMT_CV2CW3LAST2:
      str = (const int8_t *)"CV2CW3LAST2";
      break;

    case ATON_DECUN_BFMT_CV2CW4LAST2:
      str = (const int8_t *)"CV2CW4LAST2";
      break;

    case ATON_DECUN_BFMT_CV2CW5LAST2:
      str = (const int8_t *)"CV2CW5LAST2";
      break;

    case ATON_DECUN_BFMT_CV2CW6LAST2:
      str = (const int8_t *)"CV2CW6LAST2";
      break;

    case ATON_DECUN_BFMT_CV2CW7LAST2:
      str = (const int8_t *)"CV2CW7LAST2";
      break;

    case ATON_DECUN_BFMT_CV2CW8LAST2:
      str = (const int8_t *)"CV2CW8LAST2";
      break;

    case ATON_DECUN_BFMT_CV2CW4LAST3:
      str = (const int8_t *)"CV2CW4LAST3";
      break;

    case ATON_DECUN_BFMT_CV2CW5LAST3:
      str = (const int8_t *)"CV2CW5LAST3";
      break;

    case ATON_DECUN_BFMT_CV2CW6LAST3:
      str = (const int8_t *)"CV2CW6LAST3";
      break;

    case ATON_DECUN_BFMT_CV2CW7LAST3:
      str = (const int8_t *)"CV2CW7LAST3";
      break;

    case ATON_DECUN_BFMT_CV2CW8LAST3:
      str = (const int8_t *)"CV2CW8LAST3";
      break;

    case ATON_DECUN_BFMT_CV2CW5LAST4:
      str = (const int8_t *)"CV2CW5LAST4";
      break;

    case ATON_DECUN_BFMT_CV2CW6LAST4:
      str = (const int8_t *)"CV2CW6LAST4";
      break;

    case ATON_DECUN_BFMT_CV2CW7LAST4:
      str = (const int8_t *)"CV2CW7LAST4";
      break;

    case ATON_DECUN_BFMT_CV2CW8LAST4:
      str = (const int8_t *)"CV2CW8LAST4";
      break;

    case ATON_DECUN_BFMT_CV2CW6LAST5:
      str = (const int8_t *)"CV2CW6LAST5";
      break;

    case ATON_DECUN_BFMT_CV2CW7LAST5:
      str = (const int8_t *)"CV2CW7LAST5";
      break;

    case ATON_DECUN_BFMT_CV2CW8LAST5:
      str = (const int8_t *)"CV2CW8LAST5";
      break;

    case ATON_DECUN_BFMT_CV2CW7LAST6:
      str = (const int8_t *)"CV2CW7LAST6";
      break;

    case ATON_DECUN_BFMT_CV2CW8LAST6:
      str = (const int8_t *)"CV2CW8LAST6";
      break;

    case ATON_DECUN_BFMT_CV2CW8LAST7:
      str = (const int8_t *)"CV2CW8LAST7";
      break;

    case ATON_DECUN_BFMT_CV4CW1LAST0:
      str = (const int8_t *)"CV4CW1LAST0";
      break;

    case ATON_DECUN_BFMT_CV4CW2LAST0:
      str = (const int8_t *)"CV4CW2LAST0";
      break;

    case ATON_DECUN_BFMT_CV4CW3LAST0:
      str = (const int8_t *)"CV4CW3LAST0";
      break;

    case ATON_DECUN_BFMT_CV4CW4LAST0:
      str = (const int8_t *)"CV4CW4LAST0";
      break;

    case ATON_DECUN_BFMT_CV4CW5LAST0:
      str = (const int8_t *)"CV4CW5LAST0";
      break;

    case ATON_DECUN_BFMT_CV4CW6LAST0:
      str = (const int8_t *)"CV4CW6LAST0";
      break;

    case ATON_DECUN_BFMT_CV4CW7LAST0:
      str = (const int8_t *)"CV4CW7LAST0";
      break;

    case ATON_DECUN_BFMT_CV4CW8LAST0:
      str = (const int8_t *)"CV4CW8LAST0";
      break;

    case ATON_DECUN_BFMT_CV4CW2LAST1:
      str = (const int8_t *)"CV4CW2LAST1";
      break;

    case ATON_DECUN_BFMT_CV4CW3LAST1:
      str = (const int8_t *)"CV4CW3LAST1";
      break;

    case ATON_DECUN_BFMT_CV4CW4LAST1:
      str = (const int8_t *)"CV4CW4LAST1";
      break;

    case ATON_DECUN_BFMT_CV4CW5LAST1:
      str = (const int8_t *)"CV4CW5LAST1";
      break;

    case ATON_DECUN_BFMT_CV4CW6LAST1:
      str = (const int8_t *)"CV4CW6LAST1";
      break;

    case ATON_DECUN_BFMT_CV4CW7LAST1:
      str = (const int8_t *)"CV4CW7LAST1";
      break;

    case ATON_DECUN_BFMT_CV4CW8LAST1:
      str = (const int8_t *)"CV4CW8LAST1";
      break;

    case ATON_DECUN_BFMT_CV4CW3LAST2:
      str = (const int8_t *)"CV4CW3LAST2";
      break;

    case ATON_DECUN_BFMT_CV4CW4LAST2:
      str = (const int8_t *)"CV4CW4LAST2";
      break;

    case ATON_DECUN_BFMT_CV4CW5LAST2:
      str = (const int8_t *)"CV4CW5LAST2";
      break;

    case ATON_DECUN_BFMT_CV4CW6LAST2:
      str = (const int8_t *)"CV4CW6LAST2";
      break;

    case ATON_DECUN_BFMT_CV4CW7LAST2:
      str = (const int8_t *)"CV4CW7LAST2";
      break;

    case ATON_DECUN_BFMT_CV4CW8LAST2:
      str = (const int8_t *)"CV4CW8LAST2";
      break;

    case ATON_DECUN_BFMT_CV4CW4LAST3:
      str = (const int8_t *)"CV4CW4LAST3";
      break;

    case ATON_DECUN_BFMT_CV4CW5LAST3:
      str = (const int8_t *)"CV4CW5LAST3";
      break;

    case ATON_DECUN_BFMT_CV4CW6LAST3:
      str = (const int8_t *)"CV4CW6LAST3";
      break;

    case ATON_DECUN_BFMT_CV4CW7LAST3:
      str = (const int8_t *)"CV4CW7LAST3";
      break;

    case ATON_DECUN_BFMT_CV4CW8LAST3:
      str = (const int8_t *)"CV4CW8LAST3";
      break;

    case ATON_DECUN_BFMT_CV4CW5LAST4:
      str = (const int8_t *)"CV4CW5LAST4";
      break;

    case ATON_DECUN_BFMT_CV4CW6LAST4:
      str = (const int8_t *)"CV4CW6LAST4";
      break;

    case ATON_DECUN_BFMT_CV4CW7LAST4:
      str = (const int8_t *)"CV4CW7LAST4";
      break;

    case ATON_DECUN_BFMT_CV4CW8LAST4:
      str = (const int8_t *)"CV4CW8LAST4";
      break;

    case ATON_DECUN_BFMT_CV4CW6LAST5:
      str = (const int8_t *)"CV4CW6LAST5";
      break;

    case ATON_DECUN_BFMT_CV4CW7LAST5:
      str = (const int8_t *)"CV4CW7LAST5";
      break;

    case ATON_DECUN_BFMT_CV4CW8LAST5:
      str = (const int8_t *)"CV4CW8LAST5";
      break;

    case ATON_DECUN_BFMT_CV4CW7LAST6:
      str = (const int8_t *)"CV4CW7LAST6";
      break;

    case ATON_DECUN_BFMT_CV4CW8LAST6:
      str = (const int8_t *)"CV4CW8LAST6";
      break;

    case ATON_DECUN_BFMT_CV4CW8LAST7:
      str = (const int8_t *)"CV4CW8LAST7";
      break;

    case ATON_DECUN_BFMT_CV8CW1LAST0:
      str = (const int8_t *)"CV8CW1LAST0";
      break;

    case ATON_DECUN_BFMT_CV8CW2LAST0:
      str = (const int8_t *)"CV8CW2LAST0";
      break;

    case ATON_DECUN_BFMT_CV8CW3LAST0:
      str = (const int8_t *)"CV8CW3LAST0";
      break;

    case ATON_DECUN_BFMT_CV8CW4LAST0:
      str = (const int8_t *)"CV8CW4LAST0";
      break;

    case ATON_DECUN_BFMT_CV8CW5LAST0:
      str = (const int8_t *)"CV8CW5LAST0";
      break;

    case ATON_DECUN_BFMT_CV8CW6LAST0:
      str = (const int8_t *)"CV8CW6LAST0";
      break;

    case ATON_DECUN_BFMT_CV8CW7LAST0:
      str = (const int8_t *)"CV8CW7LAST0";
      break;

    case ATON_DECUN_BFMT_CV8CW8LAST0:
      str = (const int8_t *)"CV8CW8LAST0";
      break;

    case ATON_DECUN_BFMT_CV8CW2LAST1:
      str = (const int8_t *)"CV8CW2LAST1";
      break;

    case ATON_DECUN_BFMT_CV8CW3LAST1:
      str = (const int8_t *)"CV8CW3LAST1";
      break;

    case ATON_DECUN_BFMT_CV8CW4LAST1:
      str = (const int8_t *)"CV8CW4LAST1";
      break;

    case ATON_DECUN_BFMT_CV8CW5LAST1:
      str = (const int8_t *)"CV8CW5LAST1";
      break;

    case ATON_DECUN_BFMT_CV8CW6LAST1:
      str = (const int8_t *)"CV8CW6LAST1";
      break;

    case ATON_DECUN_BFMT_CV8CW7LAST1:
      str = (const int8_t *)"CV8CW7LAST1";
      break;

    case ATON_DECUN_BFMT_CV8CW8LAST1:
      str = (const int8_t *)"CV8CW8LAST1";
      break;

    case ATON_DECUN_BFMT_CV8CW3LAST2:
      str = (const int8_t *)"CV8CW3LAST2";
      break;

    case ATON_DECUN_BFMT_CV8CW4LAST2:
      str = (const int8_t *)"CV8CW4LAST2";
      break;

    case ATON_DECUN_BFMT_CV8CW5LAST2:
      str = (const int8_t *)"CV8CW5LAST2";
      break;

    case ATON_DECUN_BFMT_CV8CW6LAST2:
      str = (const int8_t *)"CV8CW6LAST2";
      break;

    case ATON_DECUN_BFMT_CV8CW7LAST2:
      str = (const int8_t *)"CV8CW7LAST2";
      break;

    case ATON_DECUN_BFMT_CV8CW8LAST2:
      str = (const int8_t *)"CV8CW8LAST2";
      break;

    case ATON_DECUN_BFMT_CV8CW4LAST3:
      str = (const int8_t *)"CV8CW4LAST3";
      break;

    case ATON_DECUN_BFMT_CV8CW5LAST3:
      str = (const int8_t *)"CV8CW5LAST3";
      break;

    case ATON_DECUN_BFMT_CV8CW6LAST3:
      str = (const int8_t *)"CV8CW6LAST3";
      break;

    case ATON_DECUN_BFMT_CV8CW7LAST3:
      str = (const int8_t *)"CV8CW7LAST3";
      break;

    case ATON_DECUN_BFMT_CV8CW8LAST3:
      str = (const int8_t *)"CV8CW8LAST3";
      break;

    case ATON_DECUN_BFMT_CV8CW5LAST4:
      str = (const int8_t *)"CV8CW5LAST4";
      break;

    case ATON_DECUN_BFMT_CV8CW6LAST4:
      str = (const int8_t *)"CV8CW6LAST4";
      break;

    case ATON_DECUN_BFMT_CV8CW7LAST4:
      str = (const int8_t *)"CV8CW7LAST4";
      break;

    case ATON_DECUN_BFMT_CV8CW8LAST4:
      str = (const int8_t *)"CV8CW8LAST4";
      break;

    case ATON_DECUN_BFMT_CV8CW6LAST5:
      str = (const int8_t *)"CV8CW6LAST5";
      break;

    case ATON_DECUN_BFMT_CV8CW7LAST5:
      str = (const int8_t *)"CV8CW7LAST5";
      break;

    case ATON_DECUN_BFMT_CV8CW8LAST5:
      str = (const int8_t *)"CV8CW8LAST5";
      break;

    case ATON_DECUN_BFMT_CV8CW7LAST6:
      str = (const int8_t *)"CV8CW7LAST6";
      break;

    case ATON_DECUN_BFMT_CV8CW8LAST6:
      str = (const int8_t *)"CV8CW8LAST6";
      break;

    case ATON_DECUN_BFMT_CV8CW8LAST7:
      str = (const int8_t *)"CV8CW8LAST7";
      break;

    case ATON_DECUN_BFMT_CV16CW1LAST0:
      str = (const int8_t *)"CV16CW1LAST0";
      break;

    case ATON_DECUN_BFMT_CV16CW2LAST0:
      str = (const int8_t *)"CV16CW2LAST0";
      break;

    case ATON_DECUN_BFMT_CV16CW3LAST0:
      str = (const int8_t *)"CV16CW3LAST0";
      break;

    case ATON_DECUN_BFMT_CV16CW4LAST0:
      str = (const int8_t *)"CV16CW4LAST0";
      break;

    case ATON_DECUN_BFMT_CV16CW5LAST0:
      str = (const int8_t *)"CV16CW5LAST0";
      break;

    case ATON_DECUN_BFMT_CV16CW6LAST0:
      str = (const int8_t *)"CV16CW6LAST0";
      break;

    case ATON_DECUN_BFMT_CV16CW7LAST0:
      str = (const int8_t *)"CV16CW7LAST0";
      break;

    case ATON_DECUN_BFMT_CV16CW8LAST0:
      str = (const int8_t *)"CV16CW8LAST0";
      break;

    case ATON_DECUN_BFMT_CV32CW1LAST0:
      str = (const int8_t *)"CV32CW1LAST0";
      break;

    case ATON_DECUN_BFMT_CV32CW2LAST0:
      str = (const int8_t *)"CV32CW2LAST0";
      break;

    case ATON_DECUN_BFMT_CV32CW3LAST0:
      str = (const int8_t *)"CV32CW3LAST0";
      break;

    case ATON_DECUN_BFMT_CV32CW4LAST0:
      str = (const int8_t *)"CV32CW4LAST0";
      break;

    case ATON_DECUN_BFMT_CV32CW5LAST0:
      str = (const int8_t *)"CV32CW5LAST0";
      break;

    case ATON_DECUN_BFMT_CV32CW6LAST0:
      str = (const int8_t *)"CV32CW6LAST0";
      break;

    case ATON_DECUN_BFMT_CV32CW7LAST0:
      str = (const int8_t *)"CV32CW7LAST0";
      break;

    case ATON_DECUN_BFMT_CV32CW8LAST0:
      str = (const int8_t *)"CV32CW8LAST0";
      break;

    case ATON_DECUN_BFMT_CV64CW1LAST0:
      str = (const int8_t *)"CV64CW1LAST0";
      break;

    case ATON_DECUN_BFMT_CV64CW2LAST0:
      str = (const int8_t *)"CV64CW2LAST0";
      break;

    case ATON_DECUN_BFMT_CV64CW3LAST0:
      str = (const int8_t *)"CV64CW3LAST0";
      break;

    case ATON_DECUN_BFMT_CV64CW4LAST0:
      str = (const int8_t *)"CV64CW4LAST0";
      break;

    case ATON_DECUN_BFMT_CV64CW5LAST0:
      str = (const int8_t *)"CV64CW5LAST0";
      break;

    case ATON_DECUN_BFMT_CV64CW6LAST0:
      str = (const int8_t *)"CV64CW6LAST0";
      break;

    case ATON_DECUN_BFMT_CV64CW7LAST0:
      str = (const int8_t *)"CV64CW7LAST0";
      break;

    case ATON_DECUN_BFMT_CV64CW8LAST0:
      str = (const int8_t *)"CV64CW8LAST0";
      break;

    case ATON_DECUN_BFMT_CV128CW1LAST0:
      str = (const int8_t *)"CV128CW1LAST0";
      break;

    case ATON_DECUN_BFMT_CV128CW2LAST0:
      str = (const int8_t *)"CV128CW2LAST0";
      break;

    case ATON_DECUN_BFMT_CV128CW3LAST0:
      str = (const int8_t *)"CV128CW3LAST0";
      break;

    case ATON_DECUN_BFMT_CV128CW4LAST0:
      str = (const int8_t *)"CV128CW4LAST0";
      break;

    case ATON_DECUN_BFMT_CV128CW5LAST0:
      str = (const int8_t *)"CV128CW5LAST0";
      break;

    case ATON_DECUN_BFMT_CV128CW6LAST0:
      str = (const int8_t *)"CV128CW6LAST0";
      break;

    case ATON_DECUN_BFMT_CV128CW7LAST0:
      str = (const int8_t *)"CV128CW7LAST0";
      break;

    case ATON_DECUN_BFMT_CV128CW8LAST0:
      str = (const int8_t *)"CV128CW8LAST0";
      break;

    case ATON_DECUN_BFMT_CV256CW1LAST0:
      str = (const int8_t *)"CV256CW1LAST0";
      break;

    case ATON_DECUN_BFMT_CV256CW2LAST0:
      str = (const int8_t *)"CV256CW2LAST0";
      break;

    case ATON_DECUN_BFMT_CV256CW3LAST0:
      str = (const int8_t *)"CV256CW3LAST0";
      break;

    case ATON_DECUN_BFMT_CV256CW4LAST0:
      str = (const int8_t *)"CV256CW4LAST0";
      break;

    case ATON_DECUN_BFMT_CV256CW5LAST0:
      str = (const int8_t *)"CV256CW5LAST0";
      break;

    case ATON_DECUN_BFMT_CV256CW6LAST0:
      str = (const int8_t *)"CV256CW6LAST0";
      break;

    case ATON_DECUN_BFMT_CV256CW7LAST0:
      str = (const int8_t *)"CV256CW7LAST0";
      break;

    case ATON_DECUN_BFMT_CV256CW8LAST0:
      str = (const int8_t *)"CV256CW8LAST0";
      break;

    case ATON_DECUN_BFMT_CV16CW2LAST1:
      str = (const int8_t *)"CV16CW2LAST1";
      break;

    case ATON_DECUN_BFMT_CV16CW3LAST1:
      str = (const int8_t *)"CV16CW3LAST1";
      break;

    case ATON_DECUN_BFMT_CV16CW3LAST2:
      str = (const int8_t *)"CV16CW3LAST2";
      break;

    case ATON_DECUN_BFMT_CV16CW4LAST1:
      str = (const int8_t *)"CV16CW4LAST1";
      break;

    case ATON_DECUN_BFMT_CV16CW4LAST2:
      str = (const int8_t *)"CV16CW4LAST2";
      break;

    case ATON_DECUN_BFMT_CV16CW4LAST3:
      str = (const int8_t *)"CV16CW4LAST3";
      break;

    case ATON_DECUN_BFMT_CV16CW5LAST1:
      str = (const int8_t *)"CV16CW5LAST1";
      break;

    case ATON_DECUN_BFMT_CV16CW5LAST2:
      str = (const int8_t *)"CV16CW5LAST2";
      break;

    case ATON_DECUN_BFMT_CV16CW5LAST3:
      str = (const int8_t *)"CV16CW5LAST3";
      break;

    case ATON_DECUN_BFMT_CV16CW5LAST4:
      str = (const int8_t *)"CV16CW5LAST4";
      break;

    case ATON_DECUN_BFMT_CV16CW6LAST1:
      str = (const int8_t *)"CV16CW6LAST1";
      break;

    case ATON_DECUN_BFMT_CV16CW6LAST2:
      str = (const int8_t *)"CV16CW6LAST2";
      break;

    case ATON_DECUN_BFMT_CV16CW6LAST3:
      str = (const int8_t *)"CV16CW6LAST3";
      break;

    case ATON_DECUN_BFMT_CV16CW6LAST4:
      str = (const int8_t *)"CV16CW6LAST4";
      break;

    case ATON_DECUN_BFMT_CV16CW6LAST5:
      str = (const int8_t *)"CV16CW6LAST5";
      break;

    case ATON_DECUN_BFMT_CV16CW7LAST1:
      str = (const int8_t *)"CV16CW7LAST1";
      break;

    case ATON_DECUN_BFMT_CV16CW7LAST2:
      str = (const int8_t *)"CV16CW7LAST2";
      break;

    case ATON_DECUN_BFMT_CV16CW7LAST3:
      str = (const int8_t *)"CV16CW7LAST3";
      break;

    case ATON_DECUN_BFMT_CV16CW7LAST4:
      str = (const int8_t *)"CV16CW7LAST4";
      break;

    case ATON_DECUN_BFMT_CV16CW7LAST5:
      str = (const int8_t *)"CV16CW7LAST5";
      break;

    case ATON_DECUN_BFMT_CV16CW7LAST6:
      str = (const int8_t *)"CV16CW7LAST6";
      break;

    case ATON_DECUN_BFMT_CV16CW8LAST1:
      str = (const int8_t *)"CV16CW8LAST1";
      break;

    case ATON_DECUN_BFMT_CV16CW8LAST2:
      str = (const int8_t *)"CV16CW8LAST2";
      break;

    case ATON_DECUN_BFMT_CV16CW8LAST3:
      str = (const int8_t *)"CV16CW8LAST3";
      break;

    case ATON_DECUN_BFMT_CV16CW8LAST4:
      str = (const int8_t *)"CV16CW8LAST4";
      break;

    case ATON_DECUN_BFMT_CV16CW8LAST5:
      str = (const int8_t *)"CV16CW8LAST5";
      break;

    case ATON_DECUN_BFMT_CV16CW8LAST6:
      str = (const int8_t *)"CV16CW8LAST6";
      break;

    case ATON_DECUN_BFMT_CV16CW8LAST7:
      str = (const int8_t *)"CV16CW8LAST7";
      break;

    case ATON_DECUN_BFMT_CV32CW2LAST1:
      str = (const int8_t *)"CV32CW2LAST1";
      break;

    case ATON_DECUN_BFMT_CV32CW3LAST1:
      str = (const int8_t *)"CV32CW3LAST1";
      break;

    case ATON_DECUN_BFMT_CV32CW3LAST2:
      str = (const int8_t *)"CV32CW3LAST2";
      break;

    case ATON_DECUN_BFMT_CV32CW4LAST1:
      str = (const int8_t *)"CV32CW4LAST1";
      break;

    case ATON_DECUN_BFMT_CV32CW4LAST2:
      str = (const int8_t *)"CV32CW4LAST2";
      break;

    case ATON_DECUN_BFMT_CV32CW4LAST3:
      str = (const int8_t *)"CV32CW4LAST3";
      break;

    case ATON_DECUN_BFMT_CV32CW5LAST1:
      str = (const int8_t *)"CV32CW5LAST1";
      break;

    case ATON_DECUN_BFMT_CV32CW5LAST2:
      str = (const int8_t *)"CV32CW5LAST2";
      break;

    case ATON_DECUN_BFMT_CV32CW5LAST3:
      str = (const int8_t *)"CV32CW5LAST3";
      break;

    case ATON_DECUN_BFMT_CV32CW5LAST4:
      str = (const int8_t *)"CV32CW5LAST4";
      break;

    case ATON_DECUN_BFMT_CV32CW6LAST1:
      str = (const int8_t *)"CV32CW6LAST1";
      break;

    case ATON_DECUN_BFMT_CV32CW6LAST2:
      str = (const int8_t *)"CV32CW6LAST2";
      break;

    case ATON_DECUN_BFMT_CV32CW6LAST3:
      str = (const int8_t *)"CV32CW6LAST3";
      break;

    case ATON_DECUN_BFMT_CV32CW6LAST4:
      str = (const int8_t *)"CV32CW6LAST4";
      break;

    case ATON_DECUN_BFMT_CV32CW6LAST5:
      str = (const int8_t *)"CV32CW6LAST5";
      break;

    case ATON_DECUN_BFMT_CV32CW7LAST1:
      str = (const int8_t *)"CV32CW7LAST1";
      break;

    case ATON_DECUN_BFMT_CV32CW7LAST2:
      str = (const int8_t *)"CV32CW7LAST2";
      break;

    case ATON_DECUN_BFMT_CV32CW7LAST3:
      str = (const int8_t *)"CV32CW7LAST3";
      break;

    case ATON_DECUN_BFMT_CV32CW7LAST4:
      str = (const int8_t *)"CV32CW7LAST4";
      break;

    case ATON_DECUN_BFMT_CV32CW7LAST5:
      str = (const int8_t *)"CV32CW7LAST5";
      break;

    case ATON_DECUN_BFMT_CV32CW7LAST6:
      str = (const int8_t *)"CV32CW7LAST6";
      break;

    case ATON_DECUN_BFMT_CV32CW8LAST1:
      str = (const int8_t *)"CV32CW8LAST1";
      break;

    case ATON_DECUN_BFMT_CV32CW8LAST2:
      str = (const int8_t *)"CV32CW8LAST2";
      break;

    case ATON_DECUN_BFMT_CV32CW8LAST3:
      str = (const int8_t *)"CV32CW8LAST3";
      break;

    case ATON_DECUN_BFMT_CV32CW8LAST4:
      str = (const int8_t *)"CV32CW8LAST4";
      break;

    case ATON_DECUN_BFMT_CV32CW8LAST5:
      str = (const int8_t *)"CV32CW8LAST5";
      break;

    case ATON_DECUN_BFMT_CV32CW8LAST6:
      str = (const int8_t *)"CV32CW8LAST6";
      break;

    case ATON_DECUN_BFMT_CV32CW8LAST7:
      str = (const int8_t *)"CV32CW8LAST7";
      break;

    case ATON_DECUN_BFMT_CV64CW2LAST1:
      str = (const int8_t *)"CV64CW2LAST1";
      break;

    case ATON_DECUN_BFMT_CV64CW3LAST1:
      str = (const int8_t *)"CV64CW3LAST1";
      break;

    case ATON_DECUN_BFMT_CV64CW3LAST2:
      str = (const int8_t *)"CV64CW3LAST2";
      break;

    case ATON_DECUN_BFMT_CV64CW4LAST1:
      str = (const int8_t *)"CV64CW4LAST1";
      break;

    case ATON_DECUN_BFMT_CV64CW4LAST2:
      str = (const int8_t *)"CV64CW4LAST2";
      break;

    case ATON_DECUN_BFMT_CV64CW4LAST3:
      str = (const int8_t *)"CV64CW4LAST3";
      break;

    case ATON_DECUN_BFMT_CV64CW5LAST1:
      str = (const int8_t *)"CV64CW5LAST1";
      break;

    case ATON_DECUN_BFMT_CV64CW5LAST2:
      str = (const int8_t *)"CV64CW5LAST2";
      break;

    case ATON_DECUN_BFMT_CV64CW5LAST3:
      str = (const int8_t *)"CV64CW5LAST3";
      break;

    case ATON_DECUN_BFMT_CV64CW5LAST4:
      str = (const int8_t *)"CV64CW5LAST4";
      break;

    case ATON_DECUN_BFMT_CV64CW6LAST1:
      str = (const int8_t *)"CV64CW6LAST1";
      break;

    case ATON_DECUN_BFMT_CV64CW6LAST2:
      str = (const int8_t *)"CV64CW6LAST2";
      break;

    case ATON_DECUN_BFMT_CV64CW6LAST3:
      str = (const int8_t *)"CV64CW6LAST3";
      break;

    case ATON_DECUN_BFMT_CV64CW6LAST4:
      str = (const int8_t *)"CV64CW6LAST4";
      break;

    case ATON_DECUN_BFMT_CV64CW6LAST5:
      str = (const int8_t *)"CV64CW6LAST5";
      break;

    case ATON_DECUN_BFMT_CV64CW7LAST1:
      str = (const int8_t *)"CV64CW7LAST1";
      break;

    case ATON_DECUN_BFMT_CV64CW7LAST2:
      str = (const int8_t *)"CV64CW7LAST2";
      break;

    case ATON_DECUN_BFMT_CV64CW7LAST3:
      str = (const int8_t *)"CV64CW7LAST3";
      break;

    case ATON_DECUN_BFMT_CV64CW7LAST4:
      str = (const int8_t *)"CV64CW7LAST4";
      break;

    case ATON_DECUN_BFMT_CV64CW7LAST5:
      str = (const int8_t *)"CV64CW7LAST5";
      break;

    case ATON_DECUN_BFMT_CV64CW7LAST6:
      str = (const int8_t *)"CV64CW7LAST6";
      break;

    case ATON_DECUN_BFMT_CV64CW8LAST1:
      str = (const int8_t *)"CV64CW8LAST1";
      break;

    case ATON_DECUN_BFMT_CV64CW8LAST2:
      str = (const int8_t *)"CV64CW8LAST2";
      break;

    case ATON_DECUN_BFMT_CV64CW8LAST3:
      str = (const int8_t *)"CV64CW8LAST3";
      break;

    case ATON_DECUN_BFMT_CV64CW8LAST4:
      str = (const int8_t *)"CV64CW8LAST4";
      break;

    case ATON_DECUN_BFMT_CV64CW8LAST5:
      str = (const int8_t *)"CV64CW8LAST5";
      break;

    case ATON_DECUN_BFMT_CV64CW8LAST6:
      str = (const int8_t *)"CV64CW8LAST6";
      break;

    case ATON_DECUN_BFMT_CV64CW8LAST7:
      str = (const int8_t *)"CV64CW8LAST7";
      break;

    case ATON_DECUN_BFMT_CV128CW2LAST1:
      str = (const int8_t *)"CV128CW2LAST1";
      break;

    case ATON_DECUN_BFMT_CV128CW3LAST1:
      str = (const int8_t *)"CV128CW3LAST1";
      break;

    case ATON_DECUN_BFMT_CV128CW3LAST2:
      str = (const int8_t *)"CV128CW3LAST2";
      break;

    case ATON_DECUN_BFMT_CV128CW4LAST1:
      str = (const int8_t *)"CV128CW4LAST1";
      break;

    case ATON_DECUN_BFMT_CV128CW4LAST2:
      str = (const int8_t *)"CV128CW4LAST2";
      break;

    case ATON_DECUN_BFMT_CV128CW4LAST3:
      str = (const int8_t *)"CV128CW4LAST3";
      break;

    case ATON_DECUN_BFMT_CV128CW5LAST1:
      str = (const int8_t *)"CV128CW5LAST1";
      break;

    case ATON_DECUN_BFMT_CV128CW5LAST2:
      str = (const int8_t *)"CV128CW5LAST2";
      break;

    case ATON_DECUN_BFMT_CV128CW5LAST3:
      str = (const int8_t *)"CV128CW5LAST3";
      break;

    case ATON_DECUN_BFMT_CV128CW5LAST4:
      str = (const int8_t *)"CV128CW5LAST4";
      break;

    case ATON_DECUN_BFMT_CV128CW6LAST1:
      str = (const int8_t *)"CV128CW6LAST1";
      break;

    case ATON_DECUN_BFMT_CV128CW6LAST2:
      str = (const int8_t *)"CV128CW6LAST2";
      break;

    case ATON_DECUN_BFMT_CV128CW6LAST3:
      str = (const int8_t *)"CV128CW6LAST3";
      break;

    case ATON_DECUN_BFMT_CV128CW6LAST4:
      str = (const int8_t *)"CV128CW6LAST4";
      break;

    case ATON_DECUN_BFMT_CV128CW6LAST5:
      str = (const int8_t *)"CV128CW6LAST5";
      break;

    case ATON_DECUN_BFMT_CV128CW7LAST1:
      str = (const int8_t *)"CV128CW7LAST1";
      break;

    case ATON_DECUN_BFMT_CV128CW7LAST2:
      str = (const int8_t *)"CV128CW7LAST2";
      break;

    case ATON_DECUN_BFMT_CV128CW7LAST3:
      str = (const int8_t *)"CV128CW7LAST3";
      break;

    case ATON_DECUN_BFMT_CV128CW7LAST4:
      str = (const int8_t *)"CV128CW7LAST4";
      break;

    case ATON_DECUN_BFMT_CV128CW7LAST5:
      str = (const int8_t *)"CV128CW7LAST5";
      break;

    case ATON_DECUN_BFMT_CV128CW7LAST6:
      str = (const int8_t *)"CV128CW7LAST6";
      break;

    case ATON_DECUN_BFMT_CV128CW8LAST1:
      str = (const int8_t *)"CV128CW8LAST1";
      break;

    case ATON_DECUN_BFMT_CV128CW8LAST2:
      str = (const int8_t *)"CV128CW8LAST2";
      break;

    case ATON_DECUN_BFMT_CV128CW8LAST3:
      str = (const int8_t *)"CV128CW8LAST3";
      break;

    case ATON_DECUN_BFMT_CV128CW8LAST4:
      str = (const int8_t *)"CV128CW8LAST4";
      break;

    case ATON_DECUN_BFMT_CV128CW8LAST5:
      str = (const int8_t *)"CV128CW8LAST5";
      break;

    case ATON_DECUN_BFMT_CV128CW8LAST6:
      str = (const int8_t *)"CV128CW8LAST6";
      break;

    case ATON_DECUN_BFMT_CV128CW8LAST7:
      str = (const int8_t *)"CV128CW8LAST7";
      break;

    case ATON_DECUN_BFMT_CV256CW2LAST1:
      str = (const int8_t *)"CV256CW2LAST1";
      break;

    case ATON_DECUN_BFMT_CV256CW3LAST1:
      str = (const int8_t *)"CV256CW3LAST1";
      break;

    case ATON_DECUN_BFMT_CV256CW3LAST2:
      str = (const int8_t *)"CV256CW3LAST2";
      break;

    case ATON_DECUN_BFMT_CV256CW4LAST1:
      str = (const int8_t *)"CV256CW4LAST1";
      break;

    case ATON_DECUN_BFMT_CV256CW4LAST2:
      str = (const int8_t *)"CV256CW4LAST2";
      break;

    case ATON_DECUN_BFMT_CV256CW4LAST3:
      str = (const int8_t *)"CV256CW4LAST3";
      break;

    case ATON_DECUN_BFMT_CV256CW5LAST1:
      str = (const int8_t *)"CV256CW5LAST1";
      break;

    case ATON_DECUN_BFMT_CV256CW5LAST2:
      str = (const int8_t *)"CV256CW5LAST2";
      break;

    case ATON_DECUN_BFMT_CV256CW5LAST3:
      str = (const int8_t *)"CV256CW5LAST3";
      break;

    case ATON_DECUN_BFMT_CV256CW5LAST4:
      str = (const int8_t *)"CV256CW5LAST4";
      break;

    case ATON_DECUN_BFMT_CV256CW6LAST1:
      str = (const int8_t *)"CV256CW6LAST1";
      break;

    case ATON_DECUN_BFMT_CV256CW6LAST2:
      str = (const int8_t *)"CV256CW6LAST2";
      break;

    case ATON_DECUN_BFMT_CV256CW6LAST3:
      str = (const int8_t *)"CV256CW6LAST3";
      break;

    case ATON_DECUN_BFMT_CV256CW6LAST4:
      str = (const int8_t *)"CV256CW6LAST4";
      break;

    case ATON_DECUN_BFMT_CV256CW6LAST5:
      str = (const int8_t *)"CV256CW6LAST5";
      break;

    case ATON_DECUN_BFMT_CV256CW7LAST1:
      str = (const int8_t *)"CV256CW7LAST1";
      break;

    case ATON_DECUN_BFMT_CV256CW7LAST2:
      str = (const int8_t *)"CV256CW7LAST2";
      break;

    case ATON_DECUN_BFMT_CV256CW7LAST3:
      str = (const int8_t *)"CV256CW7LAST3";
      break;

    case ATON_DECUN_BFMT_CV256CW7LAST4:
      str = (const int8_t *)"CV256CW7LAST4";
      break;

    case ATON_DECUN_BFMT_CV256CW7LAST5:
      str = (const int8_t *)"CV256CW7LAST5";
      break;

    case ATON_DECUN_BFMT_CV256CW7LAST6:
      str = (const int8_t *)"CV256CW7LAST6";
      break;

    case ATON_DECUN_BFMT_CV256CW8LAST1:
      str = (const int8_t *)"CV256CW8LAST1";
      break;

    case ATON_DECUN_BFMT_CV256CW8LAST2:
      str = (const int8_t *)"CV256CW8LAST2";
      break;

    case ATON_DECUN_BFMT_CV256CW8LAST3:
      str = (const int8_t *)"CV256CW8LAST3";
      break;

    case ATON_DECUN_BFMT_CV256CW8LAST4:
      str = (const int8_t *)"CV256CW8LAST4";
      break;

    case ATON_DECUN_BFMT_CV256CW8LAST5:
      str = (const int8_t *)"CV256CW8LAST5";
      break;

    case ATON_DECUN_BFMT_CV256CW8LAST6:
      str = (const int8_t *)"CV256CW8LAST6";
      break;

    case ATON_DECUN_BFMT_CV256CW8LAST7:
      str = (const int8_t *)"CV256CW8LAST7";
      break;

    default:
      break;
  }

  return str;
}


/* ---------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                                                                                                                            */
/*                                                            DECUN_DFMT set of enumerated values                                                             */
/*                                                                                                                                                            */
/* ---------------------------------------------------------------------------------------------------------------------------------------------------------- */

/** DFORMAT values: DATA16. */
#define ATON_DECUN_DFMT_DATA16 (0x0UL)

/** DFORMAT values: DATA8. */
#define ATON_DECUN_DFMT_DATA8 (0x1UL)


/** Get the name of one of the values of the DECUN_DFMT set of enumerated values. */
#define ATON_DECUN_DFMT_GET_NAME(VALUE) \
  (((VALUE) == 0UL) ? "DATA16" : \
  (((VALUE) == 1UL) ? "DATA8" :  ""))


/**
 * Check if a value of the DECUN_DFMT set of enumerated values is valid.
 *
 * \param[in] val is the numeric value that must be checked
 *
 * \retval \e true  if \e val is a valid value of the DECUN_DFMT set of enumerated values is valid
 * \retval \e false otherwise
 */

static inline bool ATON_DECUN_DFMT_IsValid(uint32_t val)
{
  bool retval = false;

  switch (val)
  {
    case ATON_DECUN_DFMT_DATA16:
    case ATON_DECUN_DFMT_DATA8:
      retval = true;
      break;

    default:
      break;
  }

  return retval;
}


/**
 * Get the name of one of the values of the DECUN_DFMT set of enumerated values.
 *
 * \param[in] val is the numeric value whose name must be returned
 *
 * \return the name of value \e val of the DECUN_DFMT set of enumerated values
 */

static inline const int8_t *ATON_DECUN_DFMT_GetName(uint32_t val)
{
  const int8_t *str = NULL;

  switch (val)
  {
    case ATON_DECUN_DFMT_DATA16:
      str = (const int8_t *)"DATA16";
      break;

    case ATON_DECUN_DFMT_DATA8:
      str = (const int8_t *)"DATA8";
      break;

    default:
      break;
  }

  return str;
}


/**
 * Get the description of one of the values of the DECUN_DFMT set of enumerated values.
 *
 * \param[in] val is the numeric value whose description must be returned
 *
 * \return the description of value \e val of the DECUN_DFMT set of enumerated values
 */

static inline const int8_t *ATON_DECUN_DFMT_GetDesc(uint32_t val)
{
  const int8_t *str = NULL;

  switch (val)
  {
    case ATON_DECUN_DFMT_DATA16:
      str = (const int8_t *)"DATA16";
      break;

    case ATON_DECUN_DFMT_DATA8:
      str = (const int8_t *)"DATA8";
      break;

    default:
      break;
  }

  return str;
}


/* ---------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                                                                                                                            */
/*                                                             EVENTTYPE set of enumerated values                                                             */
/*                                                                                                                                                            */
/* ---------------------------------------------------------------------------------------------------------------------------------------------------------- */

/** Event type: Pixels. */
#define ATON_EVENTTYPE_PIXELS (0x0UL)

/** Event type: Lines. */
#define ATON_EVENTTYPE_LINES (0x1UL)

/** Event type: Frames. */
#define ATON_EVENTTYPE_FRAMES (0x2UL)


/** Get the name of one of the values of the EVENTTYPE set of enumerated values. */
#define ATON_EVENTTYPE_GET_NAME(VALUE) \
  (((VALUE) == 0UL) ? "PIXELS" : \
  (((VALUE) == 1UL) ? "LINES" : \
  (((VALUE) == 2UL) ? "FRAMES" :  "")))


/**
 * Check if a value of the EVENTTYPE set of enumerated values is valid.
 *
 * \param[in] val is the numeric value that must be checked
 *
 * \retval \e true  if \e val is a valid value of the EVENTTYPE set of enumerated values is valid
 * \retval \e false otherwise
 */

static inline bool ATON_EVENTTYPE_IsValid(uint8_t val)
{
  bool retval = false;

  switch (val)
  {
    case ATON_EVENTTYPE_PIXELS:
    case ATON_EVENTTYPE_LINES:
    case ATON_EVENTTYPE_FRAMES:
      retval = true;
      break;

    default:
      break;
  }

  return retval;
}


/**
 * Get the name of one of the values of the EVENTTYPE set of enumerated values.
 *
 * \param[in] val is the numeric value whose name must be returned
 *
 * \return the name of value \e val of the EVENTTYPE set of enumerated values
 */

static inline const int8_t *ATON_EVENTTYPE_GetName(uint8_t val)
{
  const int8_t *str = NULL;

  switch (val)
  {
    case ATON_EVENTTYPE_PIXELS:
      str = (const int8_t *)"PIXELS";
      break;

    case ATON_EVENTTYPE_LINES:
      str = (const int8_t *)"LINES";
      break;

    case ATON_EVENTTYPE_FRAMES:
      str = (const int8_t *)"FRAMES";
      break;

    default:
      break;
  }

  return str;
}


/**
 * Get the description of one of the values of the EVENTTYPE set of enumerated values.
 *
 * \param[in] val is the numeric value whose description must be returned
 *
 * \return the description of value \e val of the EVENTTYPE set of enumerated values
 */

static inline const int8_t *ATON_EVENTTYPE_GetDesc(uint8_t val)
{
  const int8_t *str = NULL;

  switch (val)
  {
    case ATON_EVENTTYPE_PIXELS:
      str = (const int8_t *)"Pixels";
      break;

    case ATON_EVENTTYPE_LINES:
      str = (const int8_t *)"Lines";
      break;

    case ATON_EVENTTYPE_FRAMES:
      str = (const int8_t *)"Frames";
      break;

    default:
      break;
  }

  return str;
}


/* ---------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                                                                                                                            */
/*                                                               LINK set of enumerated values                                                                */
/*                                                                                                                                                            */
/* ---------------------------------------------------------------------------------------------------------------------------------------------------------- */

/** Source port: Stream Engine 0. */
#define ATON_LINK_STRENG0 (0x0UL)

/** Source port: Stream Engine 1. */
#define ATON_LINK_STRENG1 (0x1UL)

/** Source port: Stream Engine 2. */
#define ATON_LINK_STRENG2 (0x2UL)

/** Source port: Stream Engine 3. */
#define ATON_LINK_STRENG3 (0x3UL)

/** Source port: Stream Engine 4. */
#define ATON_LINK_STRENG4 (0x4UL)

/** Source port: Stream Engine 5. */
#define ATON_LINK_STRENG5 (0x5UL)

/** Source port: Stream Engine 6. */
#define ATON_LINK_STRENG6 (0x6UL)

/** Source port: Stream Engine 7. */
#define ATON_LINK_STRENG7 (0x7UL)

/** Source port: Stream Engine 8. */
#define ATON_LINK_STRENG8 (0x8UL)

/** Source port: Stream Engine 9. */
#define ATON_LINK_STRENG9 (0x9UL)

/** Source port: Convolutional Accelerator 0. */
#define ATON_LINK_CONVACC0 (0xaUL)

/** Source port: Convolutional Accelerator 1. */
#define ATON_LINK_CONVACC1 (0xbUL)

/** Source port: Convolutional Accelerator 2. */
#define ATON_LINK_CONVACC2 (0xcUL)

/** Source port: Convolutional Accelerator 3. */
#define ATON_LINK_CONVACC3 (0xdUL)

/** Source port: Decompression Unit 0. */
#define ATON_LINK_DECUN0 (0xeUL)

/** Source port: Decompression Unit 1. */
#define ATON_LINK_DECUN1 (0xfUL)

/** Source port: Activation Accelerator 0. */
#define ATON_LINK_ACTIV0 (0x10UL)

/** Source port: Activation Accelerator 1. */
#define ATON_LINK_ACTIV1 (0x11UL)

/** Source port: Arithmetic Accelerator 0. */
#define ATON_LINK_ARITH0 (0x12UL)

/** Source port: Arithmetic Accelerator 1. */
#define ATON_LINK_ARITH1 (0x13UL)

/** Source port: Arithmetic Accelerator 2. */
#define ATON_LINK_ARITH2 (0x14UL)

/** Source port: Arithmetic Accelerator 3. */
#define ATON_LINK_ARITH3 (0x15UL)

/** Source port: Pooling Accelerator 0. */
#define ATON_LINK_POOL0 (0x16UL)

/** Source port: Pooling Accelerator 1. */
#define ATON_LINK_POOL1 (0x17UL)

/** Source port: Reconfigurable Buffer 0 port 0. */
#define ATON_LINK_RECBUF00 (0x18UL)

/** Source port: Reconfigurable Buffer 0 port 1. */
#define ATON_LINK_RECBUF01 (0x19UL)

/** Source port: Reconfigurable Buffer 0 port 2. */
#define ATON_LINK_RECBUF02 (0x1aUL)


/** Get the name of one of the values of the LINK set of enumerated values. */
#define ATON_LINK_GET_NAME(VALUE) \
  (((VALUE) == 0UL) ? "STRENG0" : \
  (((VALUE) == 1UL) ? "STRENG1" : \
  (((VALUE) == 2UL) ? "STRENG2" : \
  (((VALUE) == 3UL) ? "STRENG3" : \
  (((VALUE) == 4UL) ? "STRENG4" : \
  (((VALUE) == 5UL) ? "STRENG5" : \
  (((VALUE) == 6UL) ? "STRENG6" : \
  (((VALUE) == 7UL) ? "STRENG7" : \
  (((VALUE) == 8UL) ? "STRENG8" : \
  (((VALUE) == 9UL) ? "STRENG9" : \
  (((VALUE) == 10UL) ? "CONVACC0" : \
  (((VALUE) == 11UL) ? "CONVACC1" : \
  (((VALUE) == 12UL) ? "CONVACC2" : \
  (((VALUE) == 13UL) ? "CONVACC3" : \
  (((VALUE) == 14UL) ? "DECUN0" : \
  (((VALUE) == 15UL) ? "DECUN1" : \
  (((VALUE) == 16UL) ? "ACTIV0" : \
  (((VALUE) == 17UL) ? "ACTIV1" : \
  (((VALUE) == 18UL) ? "ARITH0" : \
  (((VALUE) == 19UL) ? "ARITH1" : \
  (((VALUE) == 20UL) ? "ARITH2" : \
  (((VALUE) == 21UL) ? "ARITH3" : \
  (((VALUE) == 22UL) ? "POOL0" : \
  (((VALUE) == 23UL) ? "POOL1" : \
  (((VALUE) == 24UL) ? "RECBUF00" : \
  (((VALUE) == 25UL) ? "RECBUF01" : \
  (((VALUE) == 26UL) ? "RECBUF02" :  "")))))))))))))))))))))))))))


/**
 * Check if a value of the LINK set of enumerated values is valid.
 *
 * \param[in] val is the numeric value that must be checked
 *
 * \retval \e true  if \e val is a valid value of the LINK set of enumerated values is valid
 * \retval \e false otherwise
 */

static inline bool ATON_LINK_IsValid(uint8_t val)
{
  bool retval = false;

  switch (val)
  {
    case ATON_LINK_STRENG0:
    case ATON_LINK_STRENG1:
    case ATON_LINK_STRENG2:
    case ATON_LINK_STRENG3:
    case ATON_LINK_STRENG4:
    case ATON_LINK_STRENG5:
    case ATON_LINK_STRENG6:
    case ATON_LINK_STRENG7:
    case ATON_LINK_STRENG8:
    case ATON_LINK_STRENG9:
    case ATON_LINK_CONVACC0:
    case ATON_LINK_CONVACC1:
    case ATON_LINK_CONVACC2:
    case ATON_LINK_CONVACC3:
    case ATON_LINK_DECUN0:
    case ATON_LINK_DECUN1:
    case ATON_LINK_ACTIV0:
    case ATON_LINK_ACTIV1:
    case ATON_LINK_ARITH0:
    case ATON_LINK_ARITH1:
    case ATON_LINK_ARITH2:
    case ATON_LINK_ARITH3:
    case ATON_LINK_POOL0:
    case ATON_LINK_POOL1:
    case ATON_LINK_RECBUF00:
    case ATON_LINK_RECBUF01:
    case ATON_LINK_RECBUF02:
      retval = true;
      break;

    default:
      break;
  }

  return retval;
}


/**
 * Get the name of one of the values of the LINK set of enumerated values.
 *
 * \param[in] val is the numeric value whose name must be returned
 *
 * \return the name of value \e val of the LINK set of enumerated values
 */

static inline const int8_t *ATON_LINK_GetName(uint8_t val)
{
  const int8_t *str = NULL;

  switch (val)
  {
    case ATON_LINK_STRENG0:
      str = (const int8_t *)"STRENG0";
      break;

    case ATON_LINK_STRENG1:
      str = (const int8_t *)"STRENG1";
      break;

    case ATON_LINK_STRENG2:
      str = (const int8_t *)"STRENG2";
      break;

    case ATON_LINK_STRENG3:
      str = (const int8_t *)"STRENG3";
      break;

    case ATON_LINK_STRENG4:
      str = (const int8_t *)"STRENG4";
      break;

    case ATON_LINK_STRENG5:
      str = (const int8_t *)"STRENG5";
      break;

    case ATON_LINK_STRENG6:
      str = (const int8_t *)"STRENG6";
      break;

    case ATON_LINK_STRENG7:
      str = (const int8_t *)"STRENG7";
      break;

    case ATON_LINK_STRENG8:
      str = (const int8_t *)"STRENG8";
      break;

    case ATON_LINK_STRENG9:
      str = (const int8_t *)"STRENG9";
      break;

    case ATON_LINK_CONVACC0:
      str = (const int8_t *)"CONVACC0";
      break;

    case ATON_LINK_CONVACC1:
      str = (const int8_t *)"CONVACC1";
      break;

    case ATON_LINK_CONVACC2:
      str = (const int8_t *)"CONVACC2";
      break;

    case ATON_LINK_CONVACC3:
      str = (const int8_t *)"CONVACC3";
      break;

    case ATON_LINK_DECUN0:
      str = (const int8_t *)"DECUN0";
      break;

    case ATON_LINK_DECUN1:
      str = (const int8_t *)"DECUN1";
      break;

    case ATON_LINK_ACTIV0:
      str = (const int8_t *)"ACTIV0";
      break;

    case ATON_LINK_ACTIV1:
      str = (const int8_t *)"ACTIV1";
      break;

    case ATON_LINK_ARITH0:
      str = (const int8_t *)"ARITH0";
      break;

    case ATON_LINK_ARITH1:
      str = (const int8_t *)"ARITH1";
      break;

    case ATON_LINK_ARITH2:
      str = (const int8_t *)"ARITH2";
      break;

    case ATON_LINK_ARITH3:
      str = (const int8_t *)"ARITH3";
      break;

    case ATON_LINK_POOL0:
      str = (const int8_t *)"POOL0";
      break;

    case ATON_LINK_POOL1:
      str = (const int8_t *)"POOL1";
      break;

    case ATON_LINK_RECBUF00:
      str = (const int8_t *)"RECBUF00";
      break;

    case ATON_LINK_RECBUF01:
      str = (const int8_t *)"RECBUF01";
      break;

    case ATON_LINK_RECBUF02:
      str = (const int8_t *)"RECBUF02";
      break;

    default:
      break;
  }

  return str;
}


/**
 * Get the description of one of the values of the LINK set of enumerated values.
 *
 * \param[in] val is the numeric value whose description must be returned
 *
 * \return the description of value \e val of the LINK set of enumerated values
 */

static inline const int8_t *ATON_LINK_GetDesc(uint8_t val)
{
  const int8_t *str = NULL;

  switch (val)
  {
    case ATON_LINK_STRENG0:
      str = (const int8_t *)"Stream Engine 0";
      break;

    case ATON_LINK_STRENG1:
      str = (const int8_t *)"Stream Engine 1";
      break;

    case ATON_LINK_STRENG2:
      str = (const int8_t *)"Stream Engine 2";
      break;

    case ATON_LINK_STRENG3:
      str = (const int8_t *)"Stream Engine 3";
      break;

    case ATON_LINK_STRENG4:
      str = (const int8_t *)"Stream Engine 4";
      break;

    case ATON_LINK_STRENG5:
      str = (const int8_t *)"Stream Engine 5";
      break;

    case ATON_LINK_STRENG6:
      str = (const int8_t *)"Stream Engine 6";
      break;

    case ATON_LINK_STRENG7:
      str = (const int8_t *)"Stream Engine 7";
      break;

    case ATON_LINK_STRENG8:
      str = (const int8_t *)"Stream Engine 8";
      break;

    case ATON_LINK_STRENG9:
      str = (const int8_t *)"Stream Engine 9";
      break;

    case ATON_LINK_CONVACC0:
      str = (const int8_t *)"Convolutional Accelerator 0";
      break;

    case ATON_LINK_CONVACC1:
      str = (const int8_t *)"Convolutional Accelerator 1";
      break;

    case ATON_LINK_CONVACC2:
      str = (const int8_t *)"Convolutional Accelerator 2";
      break;

    case ATON_LINK_CONVACC3:
      str = (const int8_t *)"Convolutional Accelerator 3";
      break;

    case ATON_LINK_DECUN0:
      str = (const int8_t *)"Decompression Unit 0";
      break;

    case ATON_LINK_DECUN1:
      str = (const int8_t *)"Decompression Unit 1";
      break;

    case ATON_LINK_ACTIV0:
      str = (const int8_t *)"Activation Accelerator 0";
      break;

    case ATON_LINK_ACTIV1:
      str = (const int8_t *)"Activation Accelerator 1";
      break;

    case ATON_LINK_ARITH0:
      str = (const int8_t *)"Arithmetic Accelerator 0";
      break;

    case ATON_LINK_ARITH1:
      str = (const int8_t *)"Arithmetic Accelerator 1";
      break;

    case ATON_LINK_ARITH2:
      str = (const int8_t *)"Arithmetic Accelerator 2";
      break;

    case ATON_LINK_ARITH3:
      str = (const int8_t *)"Arithmetic Accelerator 3";
      break;

    case ATON_LINK_POOL0:
      str = (const int8_t *)"Pooling Accelerator 0";
      break;

    case ATON_LINK_POOL1:
      str = (const int8_t *)"Pooling Accelerator 1";
      break;

    case ATON_LINK_RECBUF00:
      str = (const int8_t *)"Reconfigurable Buffer 0 port 0";
      break;

    case ATON_LINK_RECBUF01:
      str = (const int8_t *)"Reconfigurable Buffer 0 port 1";
      break;

    case ATON_LINK_RECBUF02:
      str = (const int8_t *)"Reconfigurable Buffer 0 port 2";
      break;

    default:
      break;
  }

  return str;
}


/* ---------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                                                                                                                            */
/*                                                             POOLTYPE set of enumerated values                                                              */
/*                                                                                                                                                            */
/* ---------------------------------------------------------------------------------------------------------------------------------------------------------- */

/** Pool operation type: Max pooling. */
#define ATON_POOLTYPE_MAX_POOLING (0x0UL)

/** Pool operation type: Min pooling. */
#define ATON_POOLTYPE_MIN_POOLING (0x1UL)

/** Pool operation type: Average pooling. */
#define ATON_POOLTYPE_AVG_POOLING (0x2UL)

/** Pool operation type: Global max pooling. */
#define ATON_POOLTYPE_GMAX_POOLING (0x8UL)

/** Pool operation type: Global min pooling. */
#define ATON_POOLTYPE_GMIN_POOLING (0x9UL)

/** Pool operation type: Global average pooling. */
#define ATON_POOLTYPE_GAVG_POOLING (0xaUL)


/** Get the name of one of the values of the POOLTYPE set of enumerated values. */
#define ATON_POOLTYPE_GET_NAME(VALUE) \
  (((VALUE) == 0UL) ? "MAX_POOLING" : \
  (((VALUE) == 1UL) ? "MIN_POOLING" : \
  (((VALUE) == 2UL) ? "AVG_POOLING" : \
  (((VALUE) == 8UL) ? "GMAX_POOLING" : \
  (((VALUE) == 9UL) ? "GMIN_POOLING" : \
  (((VALUE) == 10UL) ? "GAVG_POOLING" :  ""))))))


/**
 * Check if a value of the POOLTYPE set of enumerated values is valid.
 *
 * \param[in] val is the numeric value that must be checked
 *
 * \retval \e true  if \e val is a valid value of the POOLTYPE set of enumerated values is valid
 * \retval \e false otherwise
 */

static inline bool ATON_POOLTYPE_IsValid(uint8_t val)
{
  bool retval = false;

  switch (val)
  {
    case ATON_POOLTYPE_MAX_POOLING:
    case ATON_POOLTYPE_MIN_POOLING:
    case ATON_POOLTYPE_AVG_POOLING:
    case ATON_POOLTYPE_GMAX_POOLING:
    case ATON_POOLTYPE_GMIN_POOLING:
    case ATON_POOLTYPE_GAVG_POOLING:
      retval = true;
      break;

    default:
      break;
  }

  return retval;
}


/**
 * Get the name of one of the values of the POOLTYPE set of enumerated values.
 *
 * \param[in] val is the numeric value whose name must be returned
 *
 * \return the name of value \e val of the POOLTYPE set of enumerated values
 */

static inline const int8_t *ATON_POOLTYPE_GetName(uint8_t val)
{
  const int8_t *str = NULL;

  switch (val)
  {
    case ATON_POOLTYPE_MAX_POOLING:
      str = (const int8_t *)"MAX_POOLING";
      break;

    case ATON_POOLTYPE_MIN_POOLING:
      str = (const int8_t *)"MIN_POOLING";
      break;

    case ATON_POOLTYPE_AVG_POOLING:
      str = (const int8_t *)"AVG_POOLING";
      break;

    case ATON_POOLTYPE_GMAX_POOLING:
      str = (const int8_t *)"GMAX_POOLING";
      break;

    case ATON_POOLTYPE_GMIN_POOLING:
      str = (const int8_t *)"GMIN_POOLING";
      break;

    case ATON_POOLTYPE_GAVG_POOLING:
      str = (const int8_t *)"GAVG_POOLING";
      break;

    default:
      break;
  }

  return str;
}


/**
 * Get the description of one of the values of the POOLTYPE set of enumerated values.
 *
 * \param[in] val is the numeric value whose description must be returned
 *
 * \return the description of value \e val of the POOLTYPE set of enumerated values
 */

static inline const int8_t *ATON_POOLTYPE_GetDesc(uint8_t val)
{
  const int8_t *str = NULL;

  switch (val)
  {
    case ATON_POOLTYPE_MAX_POOLING:
      str = (const int8_t *)"Max pooling";
      break;

    case ATON_POOLTYPE_MIN_POOLING:
      str = (const int8_t *)"Min pooling";
      break;

    case ATON_POOLTYPE_AVG_POOLING:
      str = (const int8_t *)"Average pooling";
      break;

    case ATON_POOLTYPE_GMAX_POOLING:
      str = (const int8_t *)"Global max pooling";
      break;

    case ATON_POOLTYPE_GMIN_POOLING:
      str = (const int8_t *)"Global min pooling";
      break;

    case ATON_POOLTYPE_GAVG_POOLING:
      str = (const int8_t *)"Global average pooling";
      break;

    default:
      break;
  }

  return str;
}


/* ---------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                                                                                                                            */
/*                                                               SIGN set of enumerated values                                                                */
/*                                                                                                                                                            */
/* ---------------------------------------------------------------------------------------------------------------------------------------------------------- */

/** Signed/unsigned activations: unsigned activations. */
#define ATON_SIGN_UNSIGNED (0x0UL)

/** Signed/unsigned activations: signed activations. */
#define ATON_SIGN_SIGNED (0x1UL)


/** Get the name of one of the values of the SIGN set of enumerated values. */
#define ATON_SIGN_GET_NAME(VALUE) \
  (((VALUE) == 0UL) ? "UNSIGNED" : \
  (((VALUE) == 1UL) ? "SIGNED" :  ""))


/**
 * Check if a value of the SIGN set of enumerated values is valid.
 *
 * \param[in] val is the numeric value that must be checked
 *
 * \retval \e true  if \e val is a valid value of the SIGN set of enumerated values is valid
 * \retval \e false otherwise
 */

static inline bool ATON_SIGN_IsValid(uint8_t val)
{
  bool retval = false;

  switch (val)
  {
    case ATON_SIGN_UNSIGNED:
    case ATON_SIGN_SIGNED:
      retval = true;
      break;

    default:
      break;
  }

  return retval;
}


/**
 * Get the name of one of the values of the SIGN set of enumerated values.
 *
 * \param[in] val is the numeric value whose name must be returned
 *
 * \return the name of value \e val of the SIGN set of enumerated values
 */

static inline const int8_t *ATON_SIGN_GetName(uint8_t val)
{
  const int8_t *str = NULL;

  switch (val)
  {
    case ATON_SIGN_UNSIGNED:
      str = (const int8_t *)"UNSIGNED";
      break;

    case ATON_SIGN_SIGNED:
      str = (const int8_t *)"SIGNED";
      break;

    default:
      break;
  }

  return str;
}


/**
 * Get the description of one of the values of the SIGN set of enumerated values.
 *
 * \param[in] val is the numeric value whose description must be returned
 *
 * \return the description of value \e val of the SIGN set of enumerated values
 */

static inline const int8_t *ATON_SIGN_GetDesc(uint8_t val)
{
  const int8_t *str = NULL;

  switch (val)
  {
    case ATON_SIGN_UNSIGNED:
      str = (const int8_t *)"unsigned activations";
      break;

    case ATON_SIGN_SIGNED:
      str = (const int8_t *)"signed activations";
      break;

    default:
      break;
  }

  return str;
}


/* ---------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                                                                                                                            */
/*                                                             STRENGDIR set of enumerated values                                                             */
/*                                                                                                                                                            */
/* ---------------------------------------------------------------------------------------------------------------------------------------------------------- */

/** Direction: Bus to Stream Engine direction. */
#define ATON_STRENGDIR_BUS2STR (0x0UL)

/** Direction: Stream Engine to bus direction. */
#define ATON_STRENGDIR_STR2BUS (0x1UL)


/** Get the name of one of the values of the STRENGDIR set of enumerated values. */
#define ATON_STRENGDIR_GET_NAME(VALUE) \
  (((VALUE) == 0UL) ? "BUS2STR" : \
  (((VALUE) == 1UL) ? "STR2BUS" :  ""))


/**
 * Check if a value of the STRENGDIR set of enumerated values is valid.
 *
 * \param[in] val is the numeric value that must be checked
 *
 * \retval \e true  if \e val is a valid value of the STRENGDIR set of enumerated values is valid
 * \retval \e false otherwise
 */

static inline bool ATON_STRENGDIR_IsValid(uint8_t val)
{
  bool retval = false;

  switch (val)
  {
    case ATON_STRENGDIR_BUS2STR:
    case ATON_STRENGDIR_STR2BUS:
      retval = true;
      break;

    default:
      break;
  }

  return retval;
}


/**
 * Get the name of one of the values of the STRENGDIR set of enumerated values.
 *
 * \param[in] val is the numeric value whose name must be returned
 *
 * \return the name of value \e val of the STRENGDIR set of enumerated values
 */

static inline const int8_t *ATON_STRENGDIR_GetName(uint8_t val)
{
  const int8_t *str = NULL;

  switch (val)
  {
    case ATON_STRENGDIR_BUS2STR:
      str = (const int8_t *)"BUS2STR";
      break;

    case ATON_STRENGDIR_STR2BUS:
      str = (const int8_t *)"STR2BUS";
      break;

    default:
      break;
  }

  return str;
}


/**
 * Get the description of one of the values of the STRENGDIR set of enumerated values.
 *
 * \param[in] val is the numeric value whose description must be returned
 *
 * \return the description of value \e val of the STRENGDIR set of enumerated values
 */

static inline const int8_t *ATON_STRENGDIR_GetDesc(uint8_t val)
{
  const int8_t *str = NULL;

  switch (val)
  {
    case ATON_STRENGDIR_BUS2STR:
      str = (const int8_t *)"Bus to Stream Engine direction";
      break;

    case ATON_STRENGDIR_STR2BUS:
      str = (const int8_t *)"Stream Engine to bus direction";
      break;

    default:
      break;
  }

  return str;
}


/* ********************************************************************************************************************************************************** */
/*                                                                                                                                                            */
/*                                                                            ATON                                                                            */
/*                                                                                                                                                            */
/* ********************************************************************************************************************************************************** */

#ifndef ATON_BASE

#warning "Using default value of ATON_BASE"


/** Base address of the ATON address space (this will not be redefined if already defined). */
#define ATON_BASE  0x00010000UL

#endif


/** Size in bytes of the ATON address space. */
#define ATON_SIZE  0x20000UL


/**
 * Get the base address of the ATON address space.
 */

static inline uint32_t ATON_GetBase(void)
{
  return ATON_BASE;
}


/**
 * Get the size in bytes of the ATON address space.
 */

static inline uint32_t ATON_GetSize(void)
{
  return ATON_SIZE;
}


/* ---------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                                                                                                                            */
/*                                                                           CLOCKS                                                                           */
/*                                                                                                                                                            */
/* ---------------------------------------------------------------------------------------------------------------------------------------------------------- */

/**
 * \name Clocks
 */

/*@{*/

#define ATON_CLK_CLKA_NR 4

#define ATON_INTCTRL_CLK_CLKA    0
#define ATON_BUSIF0_CLK_CLKA     1
#define ATON_BUSIF1_CLK_CLKA     2
#define ATON_STRSWITCH_CLK_CLKA  3

#define ATON_CLK_CLKB_NR 27

#define ATON_STRENG0_CLK_CLKB       0
#define ATON_STRENG1_CLK_CLKB       1
#define ATON_STRENG2_CLK_CLKB       2
#define ATON_STRENG3_CLK_CLKB       3
#define ATON_STRENG4_CLK_CLKB       4
#define ATON_STRENG5_CLK_CLKB       5
#define ATON_STRENG6_CLK_CLKB       6
#define ATON_STRENG7_CLK_CLKB       7
#define ATON_STRENG8_CLK_CLKB       8
#define ATON_STRENG9_CLK_CLKB       9
#define ATON_CONVACC0_CLK_CLKB     10
#define ATON_CONVACC1_CLK_CLKB     11
#define ATON_CONVACC2_CLK_CLKB     12
#define ATON_CONVACC3_CLK_CLKB     13
#define ATON_DECUN0_CLK_CLKB       14
#define ATON_DECUN1_CLK_CLKB       15
#define ATON_ACTIV0_CLK_CLKB       16
#define ATON_ACTIV1_CLK_CLKB       17
#define ATON_ARITH0_CLK_CLKB       18
#define ATON_ARITH1_CLK_CLKB       19
#define ATON_ARITH2_CLK_CLKB       20
#define ATON_ARITH3_CLK_CLKB       21
#define ATON_POOL0_CLK_CLKB        22
#define ATON_POOL1_CLK_CLKB        23
#define ATON_RECBUF0_CLK_CLKB      24
#define ATON_EPOCHCTRL0_CLK_CLKB   25
#define ATON_DEBUG_TRACE0_CLK_CLKB 26


/**
 * Return the mask of the CLKA clock of a CLKCTRL Unit.
 *
 * \param[in] UNIT    if smaller than #ATON_CLKCTRL_NUM is the CLKCTRL instance index, otherwise if this value is equal to #ATON_CLKCTRL_NUM it indicates
 *                    that all instances will be considered
 * \param[in] REG_IDX is the clock register index; its value must be smaller than 1
 *
 * \retval the mask of CLKA clock of a single CLKCTRL instance if \e UNIT is smaller than #ATON_CLKCTRL_NUM
 * \retval the mask of CLKA clock of all CLKCTRL instances if \e UNIT is equal to #ATON_CLKCTRL_NUM
 * \retval \e 0 if the values of \e UNIT or \e REG_IDX are not allowed
 */

#define ATON_CLKCTRL_CLK_CLKA_GET_MASK(UNIT, REG_IDX) \
    0x00000000UL


/**
 * Return the mask of the CLKB clock of a CLKCTRL Unit.
 *
 * \param[in] UNIT    if smaller than #ATON_CLKCTRL_NUM is the CLKCTRL instance index, otherwise if this value is equal to #ATON_CLKCTRL_NUM it indicates
 *                    that all instances will be considered
 * \param[in] REG_IDX is the clock register index; its value must be smaller than 1
 *
 * \retval the mask of CLKB clock of a single CLKCTRL instance if \e UNIT is smaller than #ATON_CLKCTRL_NUM
 * \retval the mask of CLKB clock of all CLKCTRL instances if \e UNIT is equal to #ATON_CLKCTRL_NUM
 * \retval \e 0 if the values of \e UNIT or \e REG_IDX are not allowed
 */

#define ATON_CLKCTRL_CLK_CLKB_GET_MASK(UNIT, REG_IDX) \
    0x00000000UL


/**
 * Return the mask of the CLKA clock of a INTCTRL Unit.
 *
 * \param[in] UNIT    if smaller than #ATON_INTCTRL_NUM is the INTCTRL instance index, otherwise if this value is equal to #ATON_INTCTRL_NUM it indicates
 *                    that all instances will be considered
 * \param[in] REG_IDX is the clock register index; its value must be smaller than 1
 *
 * \retval the mask of CLKA clock of a single INTCTRL instance if \e UNIT is smaller than #ATON_INTCTRL_NUM
 * \retval the mask of CLKA clock of all INTCTRL instances if \e UNIT is equal to #ATON_INTCTRL_NUM
 * \retval \e 0 if the values of \e UNIT or \e REG_IDX are not allowed
 */

#define ATON_INTCTRL_CLK_CLKA_GET_MASK(UNIT, REG_IDX) \
  (((REG_IDX == 0) && (UNIT == 0)) ? 0x00000001UL : \
                                     0x00000000UL)


/**
 * Return the mask of the CLKB clock of a INTCTRL Unit.
 *
 * \param[in] UNIT    if smaller than #ATON_INTCTRL_NUM is the INTCTRL instance index, otherwise if this value is equal to #ATON_INTCTRL_NUM it indicates
 *                    that all instances will be considered
 * \param[in] REG_IDX is the clock register index; its value must be smaller than 1
 *
 * \retval the mask of CLKB clock of a single INTCTRL instance if \e UNIT is smaller than #ATON_INTCTRL_NUM
 * \retval the mask of CLKB clock of all INTCTRL instances if \e UNIT is equal to #ATON_INTCTRL_NUM
 * \retval \e 0 if the values of \e UNIT or \e REG_IDX are not allowed
 */

#define ATON_INTCTRL_CLK_CLKB_GET_MASK(UNIT, REG_IDX) \
    0x00000000UL


/**
 * Return the mask of the CLKA clock of a ACTIV Unit.
 *
 * \param[in] UNIT    if smaller than #ATON_ACTIV_NUM is the ACTIV instance index, otherwise if this value is equal to #ATON_ACTIV_NUM it indicates
 *                    that all instances will be considered
 * \param[in] REG_IDX is the clock register index; its value must be smaller than 1
 *
 * \retval the mask of CLKA clock of a single ACTIV instance if \e UNIT is smaller than #ATON_ACTIV_NUM
 * \retval the mask of CLKA clock of all ACTIV instances if \e UNIT is equal to #ATON_ACTIV_NUM
 * \retval \e 0 if the values of \e UNIT or \e REG_IDX are not allowed
 */

#define ATON_ACTIV_CLK_CLKA_GET_MASK(UNIT, REG_IDX) \
    0x00000000UL


/**
 * Return the mask of the CLKB clock of a ACTIV Unit.
 *
 * \param[in] UNIT    if smaller than #ATON_ACTIV_NUM is the ACTIV instance index, otherwise if this value is equal to #ATON_ACTIV_NUM it indicates
 *                    that all instances will be considered
 * \param[in] REG_IDX is the clock register index; its value must be smaller than 1
 *
 * \retval the mask of CLKB clock of a single ACTIV instance if \e UNIT is smaller than #ATON_ACTIV_NUM
 * \retval the mask of CLKB clock of all ACTIV instances if \e UNIT is equal to #ATON_ACTIV_NUM
 * \retval \e 0 if the values of \e UNIT or \e REG_IDX are not allowed
 */

#define ATON_ACTIV_CLK_CLKB_GET_MASK(UNIT, REG_IDX) \
  (((REG_IDX == 0) && (UNIT == 0)) ? 0x00010000UL : \
  (((REG_IDX == 0) && (UNIT == 1)) ? 0x00020000UL : \
                                     0x00000000UL))


/**
 * Return the mask of the CLKA clock of a ARITH Unit.
 *
 * \param[in] UNIT    if smaller than #ATON_ARITH_NUM is the ARITH instance index, otherwise if this value is equal to #ATON_ARITH_NUM it indicates
 *                    that all instances will be considered
 * \param[in] REG_IDX is the clock register index; its value must be smaller than 1
 *
 * \retval the mask of CLKA clock of a single ARITH instance if \e UNIT is smaller than #ATON_ARITH_NUM
 * \retval the mask of CLKA clock of all ARITH instances if \e UNIT is equal to #ATON_ARITH_NUM
 * \retval \e 0 if the values of \e UNIT or \e REG_IDX are not allowed
 */

#define ATON_ARITH_CLK_CLKA_GET_MASK(UNIT, REG_IDX) \
    0x00000000UL


/**
 * Return the mask of the CLKB clock of a ARITH Unit.
 *
 * \param[in] UNIT    if smaller than #ATON_ARITH_NUM is the ARITH instance index, otherwise if this value is equal to #ATON_ARITH_NUM it indicates
 *                    that all instances will be considered
 * \param[in] REG_IDX is the clock register index; its value must be smaller than 1
 *
 * \retval the mask of CLKB clock of a single ARITH instance if \e UNIT is smaller than #ATON_ARITH_NUM
 * \retval the mask of CLKB clock of all ARITH instances if \e UNIT is equal to #ATON_ARITH_NUM
 * \retval \e 0 if the values of \e UNIT or \e REG_IDX are not allowed
 */

#define ATON_ARITH_CLK_CLKB_GET_MASK(UNIT, REG_IDX) \
  (((REG_IDX == 0) && (UNIT == 0)) ? 0x00040000UL : \
  (((REG_IDX == 0) && (UNIT == 1)) ? 0x00080000UL : \
  (((REG_IDX == 0) && (UNIT == 2)) ? 0x00100000UL : \
  (((REG_IDX == 0) && (UNIT == 3)) ? 0x00200000UL : \
                                     0x00000000UL))))


/**
 * Return the mask of the CLKA clock of a POOL Unit.
 *
 * \param[in] UNIT    if smaller than #ATON_POOL_NUM is the POOL instance index, otherwise if this value is equal to #ATON_POOL_NUM it indicates
 *                    that all instances will be considered
 * \param[in] REG_IDX is the clock register index; its value must be smaller than 1
 *
 * \retval the mask of CLKA clock of a single POOL instance if \e UNIT is smaller than #ATON_POOL_NUM
 * \retval the mask of CLKA clock of all POOL instances if \e UNIT is equal to #ATON_POOL_NUM
 * \retval \e 0 if the values of \e UNIT or \e REG_IDX are not allowed
 */

#define ATON_POOL_CLK_CLKA_GET_MASK(UNIT, REG_IDX) \
    0x00000000UL


/**
 * Return the mask of the CLKB clock of a POOL Unit.
 *
 * \param[in] UNIT    if smaller than #ATON_POOL_NUM is the POOL instance index, otherwise if this value is equal to #ATON_POOL_NUM it indicates
 *                    that all instances will be considered
 * \param[in] REG_IDX is the clock register index; its value must be smaller than 1
 *
 * \retval the mask of CLKB clock of a single POOL instance if \e UNIT is smaller than #ATON_POOL_NUM
 * \retval the mask of CLKB clock of all POOL instances if \e UNIT is equal to #ATON_POOL_NUM
 * \retval \e 0 if the values of \e UNIT or \e REG_IDX are not allowed
 */

#define ATON_POOL_CLK_CLKB_GET_MASK(UNIT, REG_IDX) \
  (((REG_IDX == 0) && (UNIT == 0)) ? 0x00400000UL : \
  (((REG_IDX == 0) && (UNIT == 1)) ? 0x00800000UL : \
                                     0x00000000UL))


/**
 * Return the mask of the CLKA clock of a BUSIF Unit.
 *
 * \param[in] UNIT    if smaller than #ATON_BUSIF_NUM is the BUSIF instance index, otherwise if this value is equal to #ATON_BUSIF_NUM it indicates
 *                    that all instances will be considered
 * \param[in] REG_IDX is the clock register index; its value must be smaller than 1
 *
 * \retval the mask of CLKA clock of a single BUSIF instance if \e UNIT is smaller than #ATON_BUSIF_NUM
 * \retval the mask of CLKA clock of all BUSIF instances if \e UNIT is equal to #ATON_BUSIF_NUM
 * \retval \e 0 if the values of \e UNIT or \e REG_IDX are not allowed
 */

#define ATON_BUSIF_CLK_CLKA_GET_MASK(UNIT, REG_IDX) \
  (((REG_IDX == 0) && (UNIT == 0)) ? 0x00000002UL : \
  (((REG_IDX == 0) && (UNIT == 1)) ? 0x00000004UL : \
                                     0x00000000UL))


/**
 * Return the mask of the CLKB clock of a BUSIF Unit.
 *
 * \param[in] UNIT    if smaller than #ATON_BUSIF_NUM is the BUSIF instance index, otherwise if this value is equal to #ATON_BUSIF_NUM it indicates
 *                    that all instances will be considered
 * \param[in] REG_IDX is the clock register index; its value must be smaller than 1
 *
 * \retval the mask of CLKB clock of a single BUSIF instance if \e UNIT is smaller than #ATON_BUSIF_NUM
 * \retval the mask of CLKB clock of all BUSIF instances if \e UNIT is equal to #ATON_BUSIF_NUM
 * \retval \e 0 if the values of \e UNIT or \e REG_IDX are not allowed
 */

#define ATON_BUSIF_CLK_CLKB_GET_MASK(UNIT, REG_IDX) \
    0x00000000UL


/**
 * Return the mask of the CLKA clock of a STRENG Unit.
 *
 * \param[in] UNIT    if smaller than #ATON_STRENG_NUM is the STRENG instance index, otherwise if this value is equal to #ATON_STRENG_NUM it indicates
 *                    that all instances will be considered
 * \param[in] REG_IDX is the clock register index; its value must be smaller than 1
 *
 * \retval the mask of CLKA clock of a single STRENG instance if \e UNIT is smaller than #ATON_STRENG_NUM
 * \retval the mask of CLKA clock of all STRENG instances if \e UNIT is equal to #ATON_STRENG_NUM
 * \retval \e 0 if the values of \e UNIT or \e REG_IDX are not allowed
 */

#define ATON_STRENG_CLK_CLKA_GET_MASK(UNIT, REG_IDX) \
    0x00000000UL


/**
 * Return the mask of the CLKB clock of a STRENG Unit.
 *
 * \param[in] UNIT    if smaller than #ATON_STRENG_NUM is the STRENG instance index, otherwise if this value is equal to #ATON_STRENG_NUM it indicates
 *                    that all instances will be considered
 * \param[in] REG_IDX is the clock register index; its value must be smaller than 1
 *
 * \retval the mask of CLKB clock of a single STRENG instance if \e UNIT is smaller than #ATON_STRENG_NUM
 * \retval the mask of CLKB clock of all STRENG instances if \e UNIT is equal to #ATON_STRENG_NUM
 * \retval \e 0 if the values of \e UNIT or \e REG_IDX are not allowed
 */

#define ATON_STRENG_CLK_CLKB_GET_MASK(UNIT, REG_IDX) \
  (((REG_IDX == 0) && (UNIT == 0)) ? 0x00000001UL : \
  (((REG_IDX == 0) && (UNIT == 1)) ? 0x00000002UL : \
  (((REG_IDX == 0) && (UNIT == 2)) ? 0x00000004UL : \
  (((REG_IDX == 0) && (UNIT == 3)) ? 0x00000008UL : \
  (((REG_IDX == 0) && (UNIT == 4)) ? 0x00000010UL : \
  (((REG_IDX == 0) && (UNIT == 5)) ? 0x00000020UL : \
  (((REG_IDX == 0) && (UNIT == 6)) ? 0x00000040UL : \
  (((REG_IDX == 0) && (UNIT == 7)) ? 0x00000080UL : \
  (((REG_IDX == 0) && (UNIT == 8)) ? 0x00000100UL : \
  (((REG_IDX == 0) && (UNIT == 9)) ? 0x00000200UL : \
                                     0x00000000UL))))))))))


/**
 * Return the mask of the CLKA clock of a STRSWITCH Unit.
 *
 * \param[in] UNIT    if smaller than #ATON_STRSWITCH_NUM is the STRSWITCH instance index, otherwise if this value is equal to #ATON_STRSWITCH_NUM it indicates
 *                    that all instances will be considered
 * \param[in] REG_IDX is the clock register index; its value must be smaller than 1
 *
 * \retval the mask of CLKA clock of a single STRSWITCH instance if \e UNIT is smaller than #ATON_STRSWITCH_NUM
 * \retval the mask of CLKA clock of all STRSWITCH instances if \e UNIT is equal to #ATON_STRSWITCH_NUM
 * \retval \e 0 if the values of \e UNIT or \e REG_IDX are not allowed
 */

#define ATON_STRSWITCH_CLK_CLKA_GET_MASK(UNIT, REG_IDX) \
  (((REG_IDX == 0) && (UNIT == 0)) ? 0x00000008UL : \
                                     0x00000000UL)


/**
 * Return the mask of the CLKB clock of a STRSWITCH Unit.
 *
 * \param[in] UNIT    if smaller than #ATON_STRSWITCH_NUM is the STRSWITCH instance index, otherwise if this value is equal to #ATON_STRSWITCH_NUM it indicates
 *                    that all instances will be considered
 * \param[in] REG_IDX is the clock register index; its value must be smaller than 1
 *
 * \retval the mask of CLKB clock of a single STRSWITCH instance if \e UNIT is smaller than #ATON_STRSWITCH_NUM
 * \retval the mask of CLKB clock of all STRSWITCH instances if \e UNIT is equal to #ATON_STRSWITCH_NUM
 * \retval \e 0 if the values of \e UNIT or \e REG_IDX are not allowed
 */

#define ATON_STRSWITCH_CLK_CLKB_GET_MASK(UNIT, REG_IDX) \
    0x00000000UL


/**
 * Return the mask of the CLKA clock of a CONVACC Unit.
 *
 * \param[in] UNIT    if smaller than #ATON_CONVACC_NUM is the CONVACC instance index, otherwise if this value is equal to #ATON_CONVACC_NUM it indicates
 *                    that all instances will be considered
 * \param[in] REG_IDX is the clock register index; its value must be smaller than 1
 *
 * \retval the mask of CLKA clock of a single CONVACC instance if \e UNIT is smaller than #ATON_CONVACC_NUM
 * \retval the mask of CLKA clock of all CONVACC instances if \e UNIT is equal to #ATON_CONVACC_NUM
 * \retval \e 0 if the values of \e UNIT or \e REG_IDX are not allowed
 */

#define ATON_CONVACC_CLK_CLKA_GET_MASK(UNIT, REG_IDX) \
    0x00000000UL


/**
 * Return the mask of the CLKB clock of a CONVACC Unit.
 *
 * \param[in] UNIT    if smaller than #ATON_CONVACC_NUM is the CONVACC instance index, otherwise if this value is equal to #ATON_CONVACC_NUM it indicates
 *                    that all instances will be considered
 * \param[in] REG_IDX is the clock register index; its value must be smaller than 1
 *
 * \retval the mask of CLKB clock of a single CONVACC instance if \e UNIT is smaller than #ATON_CONVACC_NUM
 * \retval the mask of CLKB clock of all CONVACC instances if \e UNIT is equal to #ATON_CONVACC_NUM
 * \retval \e 0 if the values of \e UNIT or \e REG_IDX are not allowed
 */

#define ATON_CONVACC_CLK_CLKB_GET_MASK(UNIT, REG_IDX) \
  (((REG_IDX == 0) && (UNIT == 0)) ? 0x00000400UL : \
  (((REG_IDX == 0) && (UNIT == 1)) ? 0x00000800UL : \
  (((REG_IDX == 0) && (UNIT == 2)) ? 0x00001000UL : \
  (((REG_IDX == 0) && (UNIT == 3)) ? 0x00002000UL : \
                                     0x00000000UL))))


/**
 * Return the mask of the CLKA clock of a DECUN Unit.
 *
 * \param[in] UNIT    if smaller than #ATON_DECUN_NUM is the DECUN instance index, otherwise if this value is equal to #ATON_DECUN_NUM it indicates
 *                    that all instances will be considered
 * \param[in] REG_IDX is the clock register index; its value must be smaller than 1
 *
 * \retval the mask of CLKA clock of a single DECUN instance if \e UNIT is smaller than #ATON_DECUN_NUM
 * \retval the mask of CLKA clock of all DECUN instances if \e UNIT is equal to #ATON_DECUN_NUM
 * \retval \e 0 if the values of \e UNIT or \e REG_IDX are not allowed
 */

#define ATON_DECUN_CLK_CLKA_GET_MASK(UNIT, REG_IDX) \
    0x00000000UL


/**
 * Return the mask of the CLKB clock of a DECUN Unit.
 *
 * \param[in] UNIT    if smaller than #ATON_DECUN_NUM is the DECUN instance index, otherwise if this value is equal to #ATON_DECUN_NUM it indicates
 *                    that all instances will be considered
 * \param[in] REG_IDX is the clock register index; its value must be smaller than 1
 *
 * \retval the mask of CLKB clock of a single DECUN instance if \e UNIT is smaller than #ATON_DECUN_NUM
 * \retval the mask of CLKB clock of all DECUN instances if \e UNIT is equal to #ATON_DECUN_NUM
 * \retval \e 0 if the values of \e UNIT or \e REG_IDX are not allowed
 */

#define ATON_DECUN_CLK_CLKB_GET_MASK(UNIT, REG_IDX) \
  (((REG_IDX == 0) && (UNIT == 0)) ? 0x00004000UL : \
  (((REG_IDX == 0) && (UNIT == 1)) ? 0x00008000UL : \
                                     0x00000000UL))


/**
 * Return the mask of the CLKA clock of a RECBUF Unit.
 *
 * \param[in] UNIT    if smaller than #ATON_RECBUF_NUM is the RECBUF instance index, otherwise if this value is equal to #ATON_RECBUF_NUM it indicates
 *                    that all instances will be considered
 * \param[in] REG_IDX is the clock register index; its value must be smaller than 1
 *
 * \retval the mask of CLKA clock of a single RECBUF instance if \e UNIT is smaller than #ATON_RECBUF_NUM
 * \retval the mask of CLKA clock of all RECBUF instances if \e UNIT is equal to #ATON_RECBUF_NUM
 * \retval \e 0 if the values of \e UNIT or \e REG_IDX are not allowed
 */

#define ATON_RECBUF_CLK_CLKA_GET_MASK(UNIT, REG_IDX) \
    0x00000000UL


/**
 * Return the mask of the CLKB clock of a RECBUF Unit.
 *
 * \param[in] UNIT    if smaller than #ATON_RECBUF_NUM is the RECBUF instance index, otherwise if this value is equal to #ATON_RECBUF_NUM it indicates
 *                    that all instances will be considered
 * \param[in] REG_IDX is the clock register index; its value must be smaller than 1
 *
 * \retval the mask of CLKB clock of a single RECBUF instance if \e UNIT is smaller than #ATON_RECBUF_NUM
 * \retval the mask of CLKB clock of all RECBUF instances if \e UNIT is equal to #ATON_RECBUF_NUM
 * \retval \e 0 if the values of \e UNIT or \e REG_IDX are not allowed
 */

#define ATON_RECBUF_CLK_CLKB_GET_MASK(UNIT, REG_IDX) \
  (((REG_IDX == 0) && (UNIT == 0)) ? 0x01000000UL : \
                                     0x00000000UL)


/**
 * Return the mask of the CLKA clock of a EPOCHCTRL Unit.
 *
 * \param[in] UNIT    if smaller than #ATON_EPOCHCTRL_NUM is the EPOCHCTRL instance index, otherwise if this value is equal to #ATON_EPOCHCTRL_NUM it indicates
 *                    that all instances will be considered
 * \param[in] REG_IDX is the clock register index; its value must be smaller than 1
 *
 * \retval the mask of CLKA clock of a single EPOCHCTRL instance if \e UNIT is smaller than #ATON_EPOCHCTRL_NUM
 * \retval the mask of CLKA clock of all EPOCHCTRL instances if \e UNIT is equal to #ATON_EPOCHCTRL_NUM
 * \retval \e 0 if the values of \e UNIT or \e REG_IDX are not allowed
 */

#define ATON_EPOCHCTRL_CLK_CLKA_GET_MASK(UNIT, REG_IDX) \
    0x00000000UL


/**
 * Return the mask of the CLKB clock of a EPOCHCTRL Unit.
 *
 * \param[in] UNIT    if smaller than #ATON_EPOCHCTRL_NUM is the EPOCHCTRL instance index, otherwise if this value is equal to #ATON_EPOCHCTRL_NUM it indicates
 *                    that all instances will be considered
 * \param[in] REG_IDX is the clock register index; its value must be smaller than 1
 *
 * \retval the mask of CLKB clock of a single EPOCHCTRL instance if \e UNIT is smaller than #ATON_EPOCHCTRL_NUM
 * \retval the mask of CLKB clock of all EPOCHCTRL instances if \e UNIT is equal to #ATON_EPOCHCTRL_NUM
 * \retval \e 0 if the values of \e UNIT or \e REG_IDX are not allowed
 */

#define ATON_EPOCHCTRL_CLK_CLKB_GET_MASK(UNIT, REG_IDX) \
  (((REG_IDX == 0) && (UNIT == 0)) ? 0x02000000UL : \
                                     0x00000000UL)


/**
 * Return the mask of the CLKA clock of a DEBUG_TRACE Unit.
 *
 * \param[in] UNIT    if smaller than #ATON_DEBUG_TRACE_NUM is the DEBUG_TRACE instance index, otherwise if this value is equal to #ATON_DEBUG_TRACE_NUM it indicates
 *                    that all instances will be considered
 * \param[in] REG_IDX is the clock register index; its value must be smaller than 1
 *
 * \retval the mask of CLKA clock of a single DEBUG_TRACE instance if \e UNIT is smaller than #ATON_DEBUG_TRACE_NUM
 * \retval the mask of CLKA clock of all DEBUG_TRACE instances if \e UNIT is equal to #ATON_DEBUG_TRACE_NUM
 * \retval \e 0 if the values of \e UNIT or \e REG_IDX are not allowed
 */

#define ATON_DEBUG_TRACE_CLK_CLKA_GET_MASK(UNIT, REG_IDX) \
    0x00000000UL


/**
 * Return the mask of the CLKB clock of a DEBUG_TRACE Unit.
 *
 * \param[in] UNIT    if smaller than #ATON_DEBUG_TRACE_NUM is the DEBUG_TRACE instance index, otherwise if this value is equal to #ATON_DEBUG_TRACE_NUM it indicates
 *                    that all instances will be considered
 * \param[in] REG_IDX is the clock register index; its value must be smaller than 1
 *
 * \retval the mask of CLKB clock of a single DEBUG_TRACE instance if \e UNIT is smaller than #ATON_DEBUG_TRACE_NUM
 * \retval the mask of CLKB clock of all DEBUG_TRACE instances if \e UNIT is equal to #ATON_DEBUG_TRACE_NUM
 * \retval \e 0 if the values of \e UNIT or \e REG_IDX are not allowed
 */

#define ATON_DEBUG_TRACE_CLK_CLKB_GET_MASK(UNIT, REG_IDX) \
  (((REG_IDX == 0) && (UNIT == 0)) ? 0x04000000UL : \
                                     0x00000000UL)

/*@}*/

/* ---------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                                                                                                                            */
/*                                                                         INTERRUPTS                                                                         */
/*                                                                                                                                                            */
/* ---------------------------------------------------------------------------------------------------------------------------------------------------------- */

/**
 * \name Interrupts
 */

/*@{*/

#define ATON_INT_NR 32

#define ATON_STRENG0_INT           0
#define ATON_STRENG1_INT           1
#define ATON_STRENG2_INT           2
#define ATON_STRENG3_INT           3
#define ATON_STRENG4_INT           4
#define ATON_STRENG5_INT           5
#define ATON_STRENG6_INT           6
#define ATON_STRENG7_INT           7
#define ATON_STRENG8_INT           8
#define ATON_STRENG9_INT           9
#define ATON_STRENG0_ERR_INT      10
#define ATON_STRENG1_ERR_INT      11
#define ATON_STRENG2_ERR_INT      12
#define ATON_STRENG3_ERR_INT      13
#define ATON_STRENG4_ERR_INT      14
#define ATON_STRENG5_ERR_INT      15
#define ATON_STRENG6_ERR_INT      16
#define ATON_STRENG7_ERR_INT      17
#define ATON_STRENG8_ERR_INT      18
#define ATON_STRENG9_ERR_INT      19
#define ATON_CONVACC0_INT         20
#define ATON_CONVACC1_INT         21
#define ATON_CONVACC2_INT         22
#define ATON_CONVACC3_INT         23
#define ATON_RECBUF0_INT          24
#define ATON_BUSIF0_INT           25
#define ATON_BUSIF1_INT           26
#define ATON_STRSWITCH_INT        27
#define ATON_EPOCHCTRL0_INT       28
#define ATON_EPOCHCTRL0_NOACK_INT 29
#define ATON_EPOCHCTRL0_ERR_INT   30
#define ATON_DEBUG_TRACE0_INT     31


/**
 * Return the interrupt mask of a BUSIF Unit.
 *
 * \param[in] UNIT    if smaller than #ATON_BUSIF_NUM is the BUSIF instance index, otherwise if this value is equal to #ATON_BUSIF_NUM it indicates
 *                    that all instances will be considered
 * \param[in] REG_IDX is the interrupt register index; its value must be smaller than 1
 *
 * \retval the interrupt mask of a single BUSIF instance if \e UNIT is smaller than #ATON_BUSIF_NUM
 * \retval the interrupt mask of all BUSIF instances if \e UNIT is equal to #ATON_BUSIF_NUM
 * \retval \e 0 if the values of \e UNIT or \e REG_IDX are not allowed
 */

#define ATON_BUSIF_INT_GET_MASK(UNIT, REG_IDX) \
  (((REG_IDX == 0) && (UNIT == 0)) ? 0x02000000UL : \
  (((REG_IDX == 0) && (UNIT == 1)) ? 0x04000000UL : \
  (((REG_IDX == 0) && (UNIT == 2)) ? 0x06000000UL : \
                                     0x00000000UL)))


/**
 * Return the interrupt mask of a STRENG Unit.
 *
 * \param[in] UNIT    if smaller than #ATON_STRENG_NUM is the STRENG instance index, otherwise if this value is equal to #ATON_STRENG_NUM it indicates
 *                    that all instances will be considered
 * \param[in] REG_IDX is the interrupt register index; its value must be smaller than 1
 *
 * \retval the interrupt mask of a single STRENG instance if \e UNIT is smaller than #ATON_STRENG_NUM
 * \retval the interrupt mask of all STRENG instances if \e UNIT is equal to #ATON_STRENG_NUM
 * \retval \e 0 if the values of \e UNIT or \e REG_IDX are not allowed
 */

#define ATON_STRENG_INT_GET_MASK(UNIT, REG_IDX) \
  (((REG_IDX == 0) && (UNIT == 0))  ? 0x00000001UL : \
  (((REG_IDX == 0) && (UNIT == 1))  ? 0x00000002UL : \
  (((REG_IDX == 0) && (UNIT == 2))  ? 0x00000004UL : \
  (((REG_IDX == 0) && (UNIT == 3))  ? 0x00000008UL : \
  (((REG_IDX == 0) && (UNIT == 4))  ? 0x00000010UL : \
  (((REG_IDX == 0) && (UNIT == 5))  ? 0x00000020UL : \
  (((REG_IDX == 0) && (UNIT == 6))  ? 0x00000040UL : \
  (((REG_IDX == 0) && (UNIT == 7))  ? 0x00000080UL : \
  (((REG_IDX == 0) && (UNIT == 8))  ? 0x00000100UL : \
  (((REG_IDX == 0) && (UNIT == 9))  ? 0x00000200UL : \
  (((REG_IDX == 0) && (UNIT == 10)) ? 0x000003ffUL : \
                                      0x00000000UL)))))))))))


/**
 * Return the interrupt mask of a STRENG Unit.
 *
 * \param[in] UNIT    if smaller than #ATON_STRENG_NUM is the STRENG instance index, otherwise if this value is equal to #ATON_STRENG_NUM it indicates
 *                    that all instances will be considered
 * \param[in] REG_IDX is the interrupt register index; its value must be smaller than 1
 *
 * \retval the interrupt mask of a single STRENG instance if \e UNIT is smaller than #ATON_STRENG_NUM
 * \retval the interrupt mask of all STRENG instances if \e UNIT is equal to #ATON_STRENG_NUM
 * \retval \e 0 if the values of \e UNIT or \e REG_IDX are not allowed
 */

#define ATON_STRENG_ERR_INT_GET_MASK(UNIT, REG_IDX) \
  (((REG_IDX == 0) && (UNIT == 0))  ? 0x00000400UL : \
  (((REG_IDX == 0) && (UNIT == 1))  ? 0x00000800UL : \
  (((REG_IDX == 0) && (UNIT == 2))  ? 0x00001000UL : \
  (((REG_IDX == 0) && (UNIT == 3))  ? 0x00002000UL : \
  (((REG_IDX == 0) && (UNIT == 4))  ? 0x00004000UL : \
  (((REG_IDX == 0) && (UNIT == 5))  ? 0x00008000UL : \
  (((REG_IDX == 0) && (UNIT == 6))  ? 0x00010000UL : \
  (((REG_IDX == 0) && (UNIT == 7))  ? 0x00020000UL : \
  (((REG_IDX == 0) && (UNIT == 8))  ? 0x00040000UL : \
  (((REG_IDX == 0) && (UNIT == 9))  ? 0x00080000UL : \
  (((REG_IDX == 0) && (UNIT == 10)) ? 0x000ffc00UL : \
                                      0x00000000UL)))))))))))


/**
 * Return the interrupt mask of a STRSWITCH Unit.
 *
 * \param[in] UNIT    if smaller than #ATON_STRSWITCH_NUM is the STRSWITCH instance index, otherwise if this value is equal to #ATON_STRSWITCH_NUM it indicates
 *                    that all instances will be considered
 * \param[in] REG_IDX is the interrupt register index; its value must be smaller than 1
 *
 * \retval the interrupt mask of a single STRSWITCH instance if \e UNIT is smaller than #ATON_STRSWITCH_NUM
 * \retval the interrupt mask of all STRSWITCH instances if \e UNIT is equal to #ATON_STRSWITCH_NUM
 * \retval \e 0 if the values of \e UNIT or \e REG_IDX are not allowed
 */

#define ATON_STRSWITCH_INT_GET_MASK(UNIT, REG_IDX) \
  (((REG_IDX == 0) && (UNIT == 0)) ? 0x08000000UL : \
  (((REG_IDX == 0) && (UNIT == 1)) ? 0x08000000UL : \
                                     0x00000000UL))


/**
 * Return the interrupt mask of a CONVACC Unit.
 *
 * \param[in] UNIT    if smaller than #ATON_CONVACC_NUM is the CONVACC instance index, otherwise if this value is equal to #ATON_CONVACC_NUM it indicates
 *                    that all instances will be considered
 * \param[in] REG_IDX is the interrupt register index; its value must be smaller than 1
 *
 * \retval the interrupt mask of a single CONVACC instance if \e UNIT is smaller than #ATON_CONVACC_NUM
 * \retval the interrupt mask of all CONVACC instances if \e UNIT is equal to #ATON_CONVACC_NUM
 * \retval \e 0 if the values of \e UNIT or \e REG_IDX are not allowed
 */

#define ATON_CONVACC_INT_GET_MASK(UNIT, REG_IDX) \
  (((REG_IDX == 0) && (UNIT == 0)) ? 0x00100000UL : \
  (((REG_IDX == 0) && (UNIT == 1)) ? 0x00200000UL : \
  (((REG_IDX == 0) && (UNIT == 2)) ? 0x00400000UL : \
  (((REG_IDX == 0) && (UNIT == 3)) ? 0x00800000UL : \
  (((REG_IDX == 0) && (UNIT == 4)) ? 0x00f00000UL : \
                                     0x00000000UL)))))


/**
 * Return the interrupt mask of a RECBUF Unit.
 *
 * \param[in] UNIT    if smaller than #ATON_RECBUF_NUM is the RECBUF instance index, otherwise if this value is equal to #ATON_RECBUF_NUM it indicates
 *                    that all instances will be considered
 * \param[in] REG_IDX is the interrupt register index; its value must be smaller than 1
 *
 * \retval the interrupt mask of a single RECBUF instance if \e UNIT is smaller than #ATON_RECBUF_NUM
 * \retval the interrupt mask of all RECBUF instances if \e UNIT is equal to #ATON_RECBUF_NUM
 * \retval \e 0 if the values of \e UNIT or \e REG_IDX are not allowed
 */

#define ATON_RECBUF_INT_GET_MASK(UNIT, REG_IDX) \
  (((REG_IDX == 0) && (UNIT == 0)) ? 0x01000000UL : \
  (((REG_IDX == 0) && (UNIT == 1)) ? 0x01000000UL : \
                                     0x00000000UL))


/**
 * Return the interrupt mask of a EPOCHCTRL Unit.
 *
 * \param[in] UNIT    if smaller than #ATON_EPOCHCTRL_NUM is the EPOCHCTRL instance index, otherwise if this value is equal to #ATON_EPOCHCTRL_NUM it indicates
 *                    that all instances will be considered
 * \param[in] REG_IDX is the interrupt register index; its value must be smaller than 1
 *
 * \retval the interrupt mask of a single EPOCHCTRL instance if \e UNIT is smaller than #ATON_EPOCHCTRL_NUM
 * \retval the interrupt mask of all EPOCHCTRL instances if \e UNIT is equal to #ATON_EPOCHCTRL_NUM
 * \retval \e 0 if the values of \e UNIT or \e REG_IDX are not allowed
 */

#define ATON_EPOCHCTRL_INT_GET_MASK(UNIT, REG_IDX) \
  (((REG_IDX == 0) && (UNIT == 0)) ? 0x10000000UL : \
  (((REG_IDX == 0) && (UNIT == 1)) ? 0x10000000UL : \
                                     0x00000000UL))


/**
 * Return the interrupt mask of a EPOCHCTRL Unit.
 *
 * \param[in] UNIT    if smaller than #ATON_EPOCHCTRL_NUM is the EPOCHCTRL instance index, otherwise if this value is equal to #ATON_EPOCHCTRL_NUM it indicates
 *                    that all instances will be considered
 * \param[in] REG_IDX is the interrupt register index; its value must be smaller than 1
 *
 * \retval the interrupt mask of a single EPOCHCTRL instance if \e UNIT is smaller than #ATON_EPOCHCTRL_NUM
 * \retval the interrupt mask of all EPOCHCTRL instances if \e UNIT is equal to #ATON_EPOCHCTRL_NUM
 * \retval \e 0 if the values of \e UNIT or \e REG_IDX are not allowed
 */

#define ATON_EPOCHCTRL_NOACK_INT_GET_MASK(UNIT, REG_IDX) \
  (((REG_IDX == 0) && (UNIT == 0)) ? 0x20000000UL : \
  (((REG_IDX == 0) && (UNIT == 1)) ? 0x20000000UL : \
                                     0x00000000UL))


/**
 * Return the interrupt mask of a EPOCHCTRL Unit.
 *
 * \param[in] UNIT    if smaller than #ATON_EPOCHCTRL_NUM is the EPOCHCTRL instance index, otherwise if this value is equal to #ATON_EPOCHCTRL_NUM it indicates
 *                    that all instances will be considered
 * \param[in] REG_IDX is the interrupt register index; its value must be smaller than 1
 *
 * \retval the interrupt mask of a single EPOCHCTRL instance if \e UNIT is smaller than #ATON_EPOCHCTRL_NUM
 * \retval the interrupt mask of all EPOCHCTRL instances if \e UNIT is equal to #ATON_EPOCHCTRL_NUM
 * \retval \e 0 if the values of \e UNIT or \e REG_IDX are not allowed
 */

#define ATON_EPOCHCTRL_ERR_INT_GET_MASK(UNIT, REG_IDX) \
  (((REG_IDX == 0) && (UNIT == 0)) ? 0x40000000UL : \
  (((REG_IDX == 0) && (UNIT == 1)) ? 0x40000000UL : \
                                     0x00000000UL))


/**
 * Return the interrupt mask of a DEBUG_TRACE Unit.
 *
 * \param[in] UNIT    if smaller than #ATON_DEBUG_TRACE_NUM is the DEBUG_TRACE instance index, otherwise if this value is equal to #ATON_DEBUG_TRACE_NUM it indicates
 *                    that all instances will be considered
 * \param[in] REG_IDX is the interrupt register index; its value must be smaller than 1
 *
 * \retval the interrupt mask of a single DEBUG_TRACE instance if \e UNIT is smaller than #ATON_DEBUG_TRACE_NUM
 * \retval the interrupt mask of all DEBUG_TRACE instances if \e UNIT is equal to #ATON_DEBUG_TRACE_NUM
 * \retval \e 0 if the values of \e UNIT or \e REG_IDX are not allowed
 */

#define ATON_DEBUG_TRACE_INT_GET_MASK(UNIT, REG_IDX) \
  (((REG_IDX == 0) && (UNIT == 0)) ? 0x80000000UL : \
  (((REG_IDX == 0) && (UNIT == 1)) ? 0x80000000UL : \
                                     0x00000000UL))

/*@}*/

/* ---------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                                                                                                                            */
/*                                                                       CLKCTRL Units                                                                        */
/*                                                                                                                                                            */
/* ---------------------------------------------------------------------------------------------------------------------------------------------------------- */

/** Number of CLKCTRL Unit instances. */
#define ATON_CLKCTRL_NUM 1

/**
 * \name Structures, macros and functions of the CLKCTRL Units
 */
/*@{*/

/**
 * Registers of the CLKCTRL Units
 */

typedef volatile struct
{
  /** \e CTRL register (Control register). */
  uint32_t CTRL;

  /** \e VERSION register (Version register). */
  uint32_t VERSION;

  /** \e AGATES0 register (Clock enable bits). */
  uint32_t AGATES0;

  /** \e AGATES1 register (Copy of AGATES0 register). */
  uint32_t AGATES1;

  /** \e BGATES register (Clock enable bits register for B clocks). */
  uint32_t BGATES;

} ATON_CLKCTRL_t;


/** Return the pointer to one of the CLKCTRL Units. */
#define ATON_CLKCTRL(UNIT) ((ATON_CLKCTRL_t *)(intptr_t)ATON_CLKCTRL_BASE(UNIT))


/** Name of one of the CLKCTRL Units. */
#define ATON_CLKCTRL_NAME(UNIT) \
  (((UNIT) == 0) ? "CLKCTRL" :  "")


/** Version of the CLKCTRL Units. */
#define ATON_CLKCTRL_VERSION "1.2"


/** Description of one of the CLKCTRL Units. */
#define ATON_CLKCTRL_DESC(UNIT) \
  (((UNIT) == 0) ? "Clock Controller" :  "")


/** Base address of one of the CLKCTRL Units. */
#define ATON_CLKCTRL_BASE(UNIT) \
  (ATON_BASE + 0x0UL + ((UNIT) * 0x0UL))

/** Size in bytes of the CLKCTRL Units. */
#define ATON_CLKCTRL_SIZE  0x1000UL


/**
 * Get the name of one of the CLKCTRL Units.
 *
 * \param[in] instance is the index of the Unit whose name must be returned (it must be <em>idx \< 1<\em>)
 *
 * \return the name of Unit having index \e instance among the CLKCTRL Units
 */

static inline const int8_t *ATON_CLKCTRL_GetName(uint32_t instance)
{
  const int8_t *str = NULL;

  switch (instance)
  {
    case 0:
      str = (const int8_t *)"CLKCTRL";
      break;

    default:
      break;
  }

  return str;
}


/**
 * Get the description of one of the CLKCTRL Units.
 *
 * \param[in] instance is the index of the Unit whose description must be returned (it must be <em>idx \< 1<\em>)
 *
 * \return the description of Unit having index \e instance among the CLKCTRL Units
 */

static inline const int8_t *ATON_CLKCTRL_GetDesc(uint32_t instance)
{
  const int8_t *str = NULL;

  switch (instance)
  {
    case 0:
      str = (const int8_t *)"Clock Controller";
      break;

    default:
      break;
  }

  return str;
}


/**
 * Get the version of the CLKCTRL Units.
 *
 * \return the version of the CLKCTRL Units
 */

static inline const int8_t *ATON_CLKCTRL_GetVersion(void)
{
  return (const int8_t *)ATON_CLKCTRL_VERSION;
}


/**
 * Get the base address of one of the CLKCTRL Units.
 *
 * \param[in] instance is the index of the Unit whose base address must be returned (it must be <em>idx \< 1<\em>)
 *
 * \return the base address of Unit having index \e instance among the CLKCTRL Units
 */

static inline uint32_t ATON_CLKCTRL_GetBase(uint32_t instance)
{
  return ATON_CLKCTRL_BASE(instance);
}


/**
 * Get the size in bytes of the CLKCTRL Units.
 *
 * \return the size in bytes of the CLKCTRL Units
 */

static inline uint32_t ATON_CLKCTRL_GetSize(void)
{
  return ATON_CLKCTRL_SIZE;
}


/* ******************************************************* CTRL register of one of the CLKCTRL Units ******************************************************** */

/** Offset of the CTRL register from the base address of the CLKCTRL Unit. */
#define ATON_CLKCTRL_CTRL_OFFSET  0x0UL

/** Reset value of the CTRL register of the CLKCTRL Unit. */
#define ATON_CLKCTRL_CTRL_DT \
  (ATON_CLKCTRL_CTRL_EN_DT        << ATON_CLKCTRL_CTRL_EN_LSB)        | \
  (ATON_CLKCTRL_CTRL_CLR_DT       << ATON_CLKCTRL_CTRL_CLR_LSB)       | \
  (ATON_CLKCTRL_CTRL_FREEZEREQ_DT << ATON_CLKCTRL_CTRL_FREEZEREQ_LSB) | \
  (ATON_CLKCTRL_CTRL_FREEZEGNT_DT << ATON_CLKCTRL_CTRL_FREEZEGNT_LSB) | \
  (ATON_CLKCTRL_CTRL_CONFCLR_DT   << ATON_CLKCTRL_CTRL_CONFCLR_LSB)



/** Description of the CTRL register. */
#define ATON_CLKCTRL_CTRL_DESC  "Control register"

/** Address of the CTRL register of one of the CLKCTRL Units. */
#define ATON_CLKCTRL_CTRL_ADDR(UNIT)  (ATON_CLKCTRL_BASE(UNIT) + ATON_CLKCTRL_CTRL_OFFSET)

/** Get the content of the CTRL register of one of the CLKCTRL Units. */
#define ATON_CLKCTRL_CTRL_GET(UNIT)  (*((volatile uint32_t *)(uintptr_t)ATON_CLKCTRL_CTRL_ADDR(UNIT)))

/** Set the content of the CTRL register of one of the CLKCTRL Units. */
#define ATON_CLKCTRL_CTRL_SET(UNIT, DATA)  do { *((volatile uint32_t *)(uintptr_t)ATON_CLKCTRL_CTRL_ADDR(UNIT)) = (DATA); } while (0);


/**
 * Get the description of CTRL register.
 *
 * \return the description of CTRL register
 */

static inline const int8_t *ATON_CLKCTRL_CTRL_GetDesc(void)
{
  return (const int8_t *)ATON_CLKCTRL_CTRL_DESC;
}


/**
 * Get the offset of the CTRL register.
 *
 * \return the offset of CTRL register
 */

static inline uint32_t ATON_CLKCTRL_CTRL_GetOffset(void)
{
  return ATON_CLKCTRL_CTRL_OFFSET;
}


/**
 * Get the address of the CTRL register.
 *
 * \param[in] instance is the index of the Unit (among the CLKCTRL Units) containing the CTRL register whose address must be returned
 *                     (it must be <em>instance \< 1<\em>)
 *
 * \return the address of CTRL register belonging to Unit having index \e instance among the CLKCTRL Units
 */

static inline uint32_t ATON_CLKCTRL_CTRL_GetAddr(uint32_t instance)
{
  return ATON_CLKCTRL_CTRL_ADDR(instance);
}


/**
 * Read the content of the CTRL register.
 *
 * \param[in] instance is the index of the Unit (among the CLKCTRL Units) containing the CTRL register whose content must be retrieved
 *                     (it must be <em>instance \< 1<\em>)
 *
 * \return the content of CTRL register belonging to Unit having index \e instance among the CLKCTRL Units
 */

static inline uint32_t ATON_CLKCTRL_CTRL_Get(uint32_t instance)
{
  return ATON_CLKCTRL_CTRL_GET(instance);
}


/**
 * Write the content of the CTRL register.
 *
 * \param[in] instance is the index of the Unit (among the CLKCTRL Units) containing the CTRL register whose content must be modified
 *                     (it must be <em>instance \< 1<\em>)
 * \param[in] data     is 32-bit value that must be written to the register
 */

static inline void ATON_CLKCTRL_CTRL_Set(uint32_t instance, uint32_t data)
{
  ATON_CLKCTRL_CTRL_SET(instance, data);
}


/* ------------------------------------------------------------- EN field of the CTRL register -------------------------------------------------------------- */

/** Description of the EN field of the CTRL register. */
#define ATON_CLKCTRL_CTRL_EN_DESC  "Enable the Clock Control Unit"

/** Offset of the EN field of the CTRL register. */
#define ATON_CLKCTRL_CTRL_EN_LSB  0UL

/** Size in bits of the EN field of the CTRL register. */
#define ATON_CLKCTRL_CTRL_EN_W  (1UL)

/** Mask for retrieving the EN field of the CTRL register. */
#define ATON_CLKCTRL_CTRL_EN_MASK  ATON_FIELD_MASK(0UL, 1UL)

/** Reset value of the EN field of the CTRL register. */
#define ATON_CLKCTRL_CTRL_EN_DT  0x0UL

/** Access rights of the EN field of the CTRL register. */
#define ATON_CLKCTRL_CTRL_EN_AC  "RW"

/** Check whether access to the EN field of the CTRL register is secured or not. */
#define ATON_CLKCTRL_CTRL_EN_S  0

/** Check whether access to the EN field of the CTRL register is privileged or not. */
#define ATON_CLKCTRL_CTRL_EN_P  0

/** Read the content of the EN field of the CTRL register. */
#define ATON_CLKCTRL_CTRL_GET_EN(REG)  ATON_GET_FIELD(REG, ATON_CLKCTRL_CTRL_EN_LSB, ATON_CLKCTRL_CTRL_EN_W)

/** Modify the content of the EN field of the CTRL register. */
#define ATON_CLKCTRL_CTRL_SET_EN(REG, DATA)  ATON_SET_FIELD(REG, ATON_CLKCTRL_CTRL_EN_LSB, ATON_CLKCTRL_CTRL_EN_W, DATA)


/**
 * Get the description of the EN field of CTRL register.
 *
 * \return the description of the EN field of CTRL register
 */

static inline const int8_t *ATON_CLKCTRL_CTRL_EN_GetdDesc(void)
{
  return (const int8_t *)ATON_CLKCTRL_CTRL_EN_DESC;
}


/**
 * Read the content of the EN field of the CTRL register.
 *
 * \param[in] reg is the value of the CTRL register
 *
 * \return the content of the EN field belonging to CTRL register
 */

static inline uint32_t ATON_CLKCTRL_CTRL_Get_EN(uint32_t reg)
{
  return ATON_CLKCTRL_CTRL_GET_EN(reg);
}


/**
 * Write the content of the EN field of the CTRL register.
 *
 * \param[in] reg  is the value of the CTRL register
 * \param[in] data is 1-bit value that must be written to the field
 *
 * \return the new content of the EN field belonging to CTRL register
 */

static inline uint32_t ATON_CLKCTRL_CTRL_Set_EN(uint32_t reg, uint32_t data)
{
  return ATON_CLKCTRL_CTRL_SET_EN(reg, data);
}


/* ------------------------------------------------------------- CLR field of the CTRL register ------------------------------------------------------------- */

/** Description of the CLR field of the CTRL register. */
#define ATON_CLKCTRL_CTRL_CLR_DESC  "Clear all pipeline registers"

/** Offset of the CLR field of the CTRL register. */
#define ATON_CLKCTRL_CTRL_CLR_LSB  1UL

/** Size in bits of the CLR field of the CTRL register. */
#define ATON_CLKCTRL_CTRL_CLR_W  (1UL)

/** Mask for retrieving the CLR field of the CTRL register. */
#define ATON_CLKCTRL_CTRL_CLR_MASK  ATON_FIELD_MASK(1UL, 1UL)

/** Reset value of the CLR field of the CTRL register. */
#define ATON_CLKCTRL_CTRL_CLR_DT  0x0UL

/** Access rights of the CLR field of the CTRL register. */
#define ATON_CLKCTRL_CTRL_CLR_AC  "RW"

/** Check whether access to the CLR field of the CTRL register is secured or not. */
#define ATON_CLKCTRL_CTRL_CLR_S  0

/** Check whether access to the CLR field of the CTRL register is privileged or not. */
#define ATON_CLKCTRL_CTRL_CLR_P  0

/** Read the content of the CLR field of the CTRL register. */
#define ATON_CLKCTRL_CTRL_GET_CLR(REG)  ATON_GET_FIELD(REG, ATON_CLKCTRL_CTRL_CLR_LSB, ATON_CLKCTRL_CTRL_CLR_W)

/** Modify the content of the CLR field of the CTRL register. */
#define ATON_CLKCTRL_CTRL_SET_CLR(REG, DATA)  ATON_SET_FIELD(REG, ATON_CLKCTRL_CTRL_CLR_LSB, ATON_CLKCTRL_CTRL_CLR_W, DATA)


/**
 * Get the description of the CLR field of CTRL register.
 *
 * \return the description of the CLR field of CTRL register
 */

static inline const int8_t *ATON_CLKCTRL_CTRL_CLR_GetdDesc(void)
{
  return (const int8_t *)ATON_CLKCTRL_CTRL_CLR_DESC;
}


/**
 * Read the content of the CLR field of the CTRL register.
 *
 * \param[in] reg is the value of the CTRL register
 *
 * \return the content of the CLR field belonging to CTRL register
 */

static inline uint32_t ATON_CLKCTRL_CTRL_Get_CLR(uint32_t reg)
{
  return ATON_CLKCTRL_CTRL_GET_CLR(reg);
}


/**
 * Write the content of the CLR field of the CTRL register.
 *
 * \param[in] reg  is the value of the CTRL register
 * \param[in] data is 1-bit value that must be written to the field
 *
 * \return the new content of the CLR field belonging to CTRL register
 */

static inline uint32_t ATON_CLKCTRL_CTRL_Set_CLR(uint32_t reg, uint32_t data)
{
  return ATON_CLKCTRL_CTRL_SET_CLR(reg, data);
}


/* ---------------------------------------------------------- FREEZEREQ field of the CTRL register ---------------------------------------------------------- */

/** Description of the FREEZEREQ field of the CTRL register. */
#define ATON_CLKCTRL_CTRL_FREEZEREQ_DESC  "Request bus access freeze"

/** Offset of the FREEZEREQ field of the CTRL register. */
#define ATON_CLKCTRL_CTRL_FREEZEREQ_LSB  2UL

/** Size in bits of the FREEZEREQ field of the CTRL register. */
#define ATON_CLKCTRL_CTRL_FREEZEREQ_W  (1UL)

/** Mask for retrieving the FREEZEREQ field of the CTRL register. */
#define ATON_CLKCTRL_CTRL_FREEZEREQ_MASK  ATON_FIELD_MASK(2UL, 1UL)

/** Reset value of the FREEZEREQ field of the CTRL register. */
#define ATON_CLKCTRL_CTRL_FREEZEREQ_DT  0x0UL

/** Access rights of the FREEZEREQ field of the CTRL register. */
#define ATON_CLKCTRL_CTRL_FREEZEREQ_AC  "RW"

/** Check whether access to the FREEZEREQ field of the CTRL register is secured or not. */
#define ATON_CLKCTRL_CTRL_FREEZEREQ_S  0

/** Check whether access to the FREEZEREQ field of the CTRL register is privileged or not. */
#define ATON_CLKCTRL_CTRL_FREEZEREQ_P  0

/** Read the content of the FREEZEREQ field of the CTRL register. */
#define ATON_CLKCTRL_CTRL_GET_FREEZEREQ(REG)  ATON_GET_FIELD(REG, ATON_CLKCTRL_CTRL_FREEZEREQ_LSB, ATON_CLKCTRL_CTRL_FREEZEREQ_W)

/** Modify the content of the FREEZEREQ field of the CTRL register. */
#define ATON_CLKCTRL_CTRL_SET_FREEZEREQ(REG, DATA)  ATON_SET_FIELD(REG, ATON_CLKCTRL_CTRL_FREEZEREQ_LSB, ATON_CLKCTRL_CTRL_FREEZEREQ_W, DATA)


/**
 * Get the description of the FREEZEREQ field of CTRL register.
 *
 * \return the description of the FREEZEREQ field of CTRL register
 */

static inline const int8_t *ATON_CLKCTRL_CTRL_FREEZEREQ_GetdDesc(void)
{
  return (const int8_t *)ATON_CLKCTRL_CTRL_FREEZEREQ_DESC;
}


/**
 * Read the content of the FREEZEREQ field of the CTRL register.
 *
 * \param[in] reg is the value of the CTRL register
 *
 * \return the content of the FREEZEREQ field belonging to CTRL register
 */

static inline uint32_t ATON_CLKCTRL_CTRL_Get_FREEZEREQ(uint32_t reg)
{
  return ATON_CLKCTRL_CTRL_GET_FREEZEREQ(reg);
}


/**
 * Write the content of the FREEZEREQ field of the CTRL register.
 *
 * \param[in] reg  is the value of the CTRL register
 * \param[in] data is 1-bit value that must be written to the field
 *
 * \return the new content of the FREEZEREQ field belonging to CTRL register
 */

static inline uint32_t ATON_CLKCTRL_CTRL_Set_FREEZEREQ(uint32_t reg, uint32_t data)
{
  return ATON_CLKCTRL_CTRL_SET_FREEZEREQ(reg, data);
}


/* ---------------------------------------------------------- FREEZEGNT field of the CTRL register ---------------------------------------------------------- */

/** Description of the FREEZEGNT field of the CTRL register. */
#define ATON_CLKCTRL_CTRL_FREEZEGNT_DESC  "Freeze request grant"

/** Offset of the FREEZEGNT field of the CTRL register. */
#define ATON_CLKCTRL_CTRL_FREEZEGNT_LSB  3UL

/** Size in bits of the FREEZEGNT field of the CTRL register. */
#define ATON_CLKCTRL_CTRL_FREEZEGNT_W  (1UL)

/** Mask for retrieving the FREEZEGNT field of the CTRL register. */
#define ATON_CLKCTRL_CTRL_FREEZEGNT_MASK  ATON_FIELD_MASK(3UL, 1UL)

/** Reset value of the FREEZEGNT field of the CTRL register. */
#define ATON_CLKCTRL_CTRL_FREEZEGNT_DT  0x0UL

/** Access rights of the FREEZEGNT field of the CTRL register. */
#define ATON_CLKCTRL_CTRL_FREEZEGNT_AC  "R"

/** Check whether access to the FREEZEGNT field of the CTRL register is secured or not. */
#define ATON_CLKCTRL_CTRL_FREEZEGNT_S  0

/** Check whether access to the FREEZEGNT field of the CTRL register is privileged or not. */
#define ATON_CLKCTRL_CTRL_FREEZEGNT_P  0

/** Read the content of the FREEZEGNT field of the CTRL register. */
#define ATON_CLKCTRL_CTRL_GET_FREEZEGNT(REG)  ATON_GET_FIELD(REG, ATON_CLKCTRL_CTRL_FREEZEGNT_LSB, ATON_CLKCTRL_CTRL_FREEZEGNT_W)


/**
 * Get the description of the FREEZEGNT field of CTRL register.
 *
 * \return the description of the FREEZEGNT field of CTRL register
 */

static inline const int8_t *ATON_CLKCTRL_CTRL_FREEZEGNT_GetdDesc(void)
{
  return (const int8_t *)ATON_CLKCTRL_CTRL_FREEZEGNT_DESC;
}


/**
 * Read the content of the FREEZEGNT field of the CTRL register.
 *
 * \param[in] reg is the value of the CTRL register
 *
 * \return the content of the FREEZEGNT field belonging to CTRL register
 */

static inline uint32_t ATON_CLKCTRL_CTRL_Get_FREEZEGNT(uint32_t reg)
{
  return ATON_CLKCTRL_CTRL_GET_FREEZEGNT(reg);
}


/* ----------------------------------------------------------- CONFCLR field of the CTRL register ----------------------------------------------------------- */

/** Description of the CONFCLR field of the CTRL register. */
#define ATON_CLKCTRL_CTRL_CONFCLR_DESC  "Clear Configuration registers (autocleared)"

/** Offset of the CONFCLR field of the CTRL register. */
#define ATON_CLKCTRL_CTRL_CONFCLR_LSB  30UL

/** Size in bits of the CONFCLR field of the CTRL register. */
#define ATON_CLKCTRL_CTRL_CONFCLR_W  (1UL)

/** Mask for retrieving the CONFCLR field of the CTRL register. */
#define ATON_CLKCTRL_CTRL_CONFCLR_MASK  ATON_FIELD_MASK(30UL, 1UL)

/** Reset value of the CONFCLR field of the CTRL register. */
#define ATON_CLKCTRL_CTRL_CONFCLR_DT  0x0UL

/** Access rights of the CONFCLR field of the CTRL register. */
#define ATON_CLKCTRL_CTRL_CONFCLR_AC  "RW"

/** Check whether access to the CONFCLR field of the CTRL register is secured or not. */
#define ATON_CLKCTRL_CTRL_CONFCLR_S  0

/** Check whether access to the CONFCLR field of the CTRL register is privileged or not. */
#define ATON_CLKCTRL_CTRL_CONFCLR_P  0

/** Read the content of the CONFCLR field of the CTRL register. */
#define ATON_CLKCTRL_CTRL_GET_CONFCLR(REG)  ATON_GET_FIELD(REG, ATON_CLKCTRL_CTRL_CONFCLR_LSB, ATON_CLKCTRL_CTRL_CONFCLR_W)

/** Modify the content of the CONFCLR field of the CTRL register. */
#define ATON_CLKCTRL_CTRL_SET_CONFCLR(REG, DATA)  ATON_SET_FIELD(REG, ATON_CLKCTRL_CTRL_CONFCLR_LSB, ATON_CLKCTRL_CTRL_CONFCLR_W, DATA)


/**
 * Get the description of the CONFCLR field of CTRL register.
 *
 * \return the description of the CONFCLR field of CTRL register
 */

static inline const int8_t *ATON_CLKCTRL_CTRL_CONFCLR_GetdDesc(void)
{
  return (const int8_t *)ATON_CLKCTRL_CTRL_CONFCLR_DESC;
}


/**
 * Read the content of the CONFCLR field of the CTRL register.
 *
 * \param[in] reg is the value of the CTRL register
 *
 * \return the content of the CONFCLR field belonging to CTRL register
 */

static inline uint32_t ATON_CLKCTRL_CTRL_Get_CONFCLR(uint32_t reg)
{
  return ATON_CLKCTRL_CTRL_GET_CONFCLR(reg);
}


/**
 * Write the content of the CONFCLR field of the CTRL register.
 *
 * \param[in] reg  is the value of the CTRL register
 * \param[in] data is 1-bit value that must be written to the field
 *
 * \return the new content of the CONFCLR field belonging to CTRL register
 */

static inline uint32_t ATON_CLKCTRL_CTRL_Set_CONFCLR(uint32_t reg, uint32_t data)
{
  return ATON_CLKCTRL_CTRL_SET_CONFCLR(reg, data);
}


/* ****************************************************** VERSION register of one of the CLKCTRL Units ****************************************************** */

/** Offset of the VERSION register from the base address of the CLKCTRL Unit. */
#define ATON_CLKCTRL_VERSION_OFFSET  0x4UL

/** Reset value of the VERSION register of the CLKCTRL Unit. */
#define ATON_CLKCTRL_VERSION_DT \
  (ATON_CLKCTRL_VERSION_TYPE_DT   << ATON_CLKCTRL_VERSION_TYPE_LSB)   | \
  (ATON_CLKCTRL_VERSION_MINOR_DT  << ATON_CLKCTRL_VERSION_MINOR_LSB)  | \
  (ATON_CLKCTRL_VERSION_MAJOR_DT  << ATON_CLKCTRL_VERSION_MAJOR_LSB)  | \
  (ATON_CLKCTRL_VERSION_AGATES_DT << ATON_CLKCTRL_VERSION_AGATES_LSB) | \
  (ATON_CLKCTRL_VERSION_BGATES_DT << ATON_CLKCTRL_VERSION_BGATES_LSB) | \
  (ATON_CLKCTRL_VERSION_CLKDIV_DT << ATON_CLKCTRL_VERSION_CLKDIV_LSB)



/** Description of the VERSION register. */
#define ATON_CLKCTRL_VERSION_DESC  "Version register"

/** Address of the VERSION register of one of the CLKCTRL Units. */
#define ATON_CLKCTRL_VERSION_ADDR(UNIT)  (ATON_CLKCTRL_BASE(UNIT) + ATON_CLKCTRL_VERSION_OFFSET)

/** Get the content of the VERSION register of one of the CLKCTRL Units. */
#define ATON_CLKCTRL_VERSION_GET(UNIT)  (*((volatile uint32_t *)(uintptr_t)ATON_CLKCTRL_VERSION_ADDR(UNIT)))


/**
 * Get the description of VERSION register.
 *
 * \return the description of VERSION register
 */

static inline const int8_t *ATON_CLKCTRL_VERSION_GetDesc(void)
{
  return (const int8_t *)ATON_CLKCTRL_VERSION_DESC;
}


/**
 * Get the offset of the VERSION register.
 *
 * \return the offset of VERSION register
 */

static inline uint32_t ATON_CLKCTRL_VERSION_GetOffset(void)
{
  return ATON_CLKCTRL_VERSION_OFFSET;
}


/**
 * Get the address of the VERSION register.
 *
 * \param[in] instance is the index of the Unit (among the CLKCTRL Units) containing the VERSION register whose address must be returned
 *                     (it must be <em>instance \< 1<\em>)
 *
 * \return the address of VERSION register belonging to Unit having index \e instance among the CLKCTRL Units
 */

static inline uint32_t ATON_CLKCTRL_VERSION_GetAddr(uint32_t instance)
{
  return ATON_CLKCTRL_VERSION_ADDR(instance);
}


/**
 * Read the content of the VERSION register.
 *
 * \param[in] instance is the index of the Unit (among the CLKCTRL Units) containing the VERSION register whose content must be retrieved
 *                     (it must be <em>instance \< 1<\em>)
 *
 * \return the content of VERSION register belonging to Unit having index \e instance among the CLKCTRL Units
 */

static inline uint32_t ATON_CLKCTRL_VERSION_Get(uint32_t instance)
{
  return ATON_CLKCTRL_VERSION_GET(instance);
}


/* ----------------------------------------------------------- TYPE field of the VERSION register ----------------------------------------------------------- */

/** Description of the TYPE field of the VERSION register. */
#define ATON_CLKCTRL_VERSION_TYPE_DESC  "Block type"

/** Offset of the TYPE field of the VERSION register. */
#define ATON_CLKCTRL_VERSION_TYPE_LSB  0UL

/** Size in bits of the TYPE field of the VERSION register. */
#define ATON_CLKCTRL_VERSION_TYPE_W  (8UL)

/** Mask for retrieving the TYPE field of the VERSION register. */
#define ATON_CLKCTRL_VERSION_TYPE_MASK  ATON_FIELD_MASK(0UL, 8UL)

/** Reset value of the TYPE field of the VERSION register. */
#define ATON_CLKCTRL_VERSION_TYPE_DT  0x1fUL

/** Access rights of the TYPE field of the VERSION register. */
#define ATON_CLKCTRL_VERSION_TYPE_AC  "R"

/** Check whether access to the TYPE field of the VERSION register is secured or not. */
#define ATON_CLKCTRL_VERSION_TYPE_S  0

/** Check whether access to the TYPE field of the VERSION register is privileged or not. */
#define ATON_CLKCTRL_VERSION_TYPE_P  0

/** Read the content of the TYPE field of the VERSION register. */
#define ATON_CLKCTRL_VERSION_GET_TYPE(REG)  ATON_GET_FIELD(REG, ATON_CLKCTRL_VERSION_TYPE_LSB, ATON_CLKCTRL_VERSION_TYPE_W)


/**
 * Get the description of the TYPE field of VERSION register.
 *
 * \return the description of the TYPE field of VERSION register
 */

static inline const int8_t *ATON_CLKCTRL_VERSION_TYPE_GetdDesc(void)
{
  return (const int8_t *)ATON_CLKCTRL_VERSION_TYPE_DESC;
}


/**
 * Read the content of the TYPE field of the VERSION register.
 *
 * \param[in] reg is the value of the VERSION register
 *
 * \return the content of the TYPE field belonging to VERSION register
 */

static inline uint32_t ATON_CLKCTRL_VERSION_Get_TYPE(uint32_t reg)
{
  return ATON_CLKCTRL_VERSION_GET_TYPE(reg);
}


/* ---------------------------------------------------------- MINOR field of the VERSION register ----------------------------------------------------------- */

/** Description of the MINOR field of the VERSION register. */
#define ATON_CLKCTRL_VERSION_MINOR_DESC  "Block minor version"

/** Offset of the MINOR field of the VERSION register. */
#define ATON_CLKCTRL_VERSION_MINOR_LSB  8UL

/** Size in bits of the MINOR field of the VERSION register. */
#define ATON_CLKCTRL_VERSION_MINOR_W  (4UL)

/** Mask for retrieving the MINOR field of the VERSION register. */
#define ATON_CLKCTRL_VERSION_MINOR_MASK  ATON_FIELD_MASK(8UL, 4UL)

/** Reset value of the MINOR field of the VERSION register. */
#define ATON_CLKCTRL_VERSION_MINOR_DT  0x2UL

/** Access rights of the MINOR field of the VERSION register. */
#define ATON_CLKCTRL_VERSION_MINOR_AC  "R"

/** Check whether access to the MINOR field of the VERSION register is secured or not. */
#define ATON_CLKCTRL_VERSION_MINOR_S  0

/** Check whether access to the MINOR field of the VERSION register is privileged or not. */
#define ATON_CLKCTRL_VERSION_MINOR_P  0

/** Read the content of the MINOR field of the VERSION register. */
#define ATON_CLKCTRL_VERSION_GET_MINOR(REG)  ATON_GET_FIELD(REG, ATON_CLKCTRL_VERSION_MINOR_LSB, ATON_CLKCTRL_VERSION_MINOR_W)


/**
 * Get the description of the MINOR field of VERSION register.
 *
 * \return the description of the MINOR field of VERSION register
 */

static inline const int8_t *ATON_CLKCTRL_VERSION_MINOR_GetdDesc(void)
{
  return (const int8_t *)ATON_CLKCTRL_VERSION_MINOR_DESC;
}


/**
 * Read the content of the MINOR field of the VERSION register.
 *
 * \param[in] reg is the value of the VERSION register
 *
 * \return the content of the MINOR field belonging to VERSION register
 */

static inline uint32_t ATON_CLKCTRL_VERSION_Get_MINOR(uint32_t reg)
{
  return ATON_CLKCTRL_VERSION_GET_MINOR(reg);
}


/* ---------------------------------------------------------- MAJOR field of the VERSION register ----------------------------------------------------------- */

/** Description of the MAJOR field of the VERSION register. */
#define ATON_CLKCTRL_VERSION_MAJOR_DESC  "Block major version"

/** Offset of the MAJOR field of the VERSION register. */
#define ATON_CLKCTRL_VERSION_MAJOR_LSB  12UL

/** Size in bits of the MAJOR field of the VERSION register. */
#define ATON_CLKCTRL_VERSION_MAJOR_W  (4UL)

/** Mask for retrieving the MAJOR field of the VERSION register. */
#define ATON_CLKCTRL_VERSION_MAJOR_MASK  ATON_FIELD_MASK(12UL, 4UL)

/** Reset value of the MAJOR field of the VERSION register. */
#define ATON_CLKCTRL_VERSION_MAJOR_DT  0x1UL

/** Access rights of the MAJOR field of the VERSION register. */
#define ATON_CLKCTRL_VERSION_MAJOR_AC  "R"

/** Check whether access to the MAJOR field of the VERSION register is secured or not. */
#define ATON_CLKCTRL_VERSION_MAJOR_S  0

/** Check whether access to the MAJOR field of the VERSION register is privileged or not. */
#define ATON_CLKCTRL_VERSION_MAJOR_P  0

/** Read the content of the MAJOR field of the VERSION register. */
#define ATON_CLKCTRL_VERSION_GET_MAJOR(REG)  ATON_GET_FIELD(REG, ATON_CLKCTRL_VERSION_MAJOR_LSB, ATON_CLKCTRL_VERSION_MAJOR_W)


/**
 * Get the description of the MAJOR field of VERSION register.
 *
 * \return the description of the MAJOR field of VERSION register
 */

static inline const int8_t *ATON_CLKCTRL_VERSION_MAJOR_GetdDesc(void)
{
  return (const int8_t *)ATON_CLKCTRL_VERSION_MAJOR_DESC;
}


/**
 * Read the content of the MAJOR field of the VERSION register.
 *
 * \param[in] reg is the value of the VERSION register
 *
 * \return the content of the MAJOR field belonging to VERSION register
 */

static inline uint32_t ATON_CLKCTRL_VERSION_Get_MAJOR(uint32_t reg)
{
  return ATON_CLKCTRL_VERSION_GET_MAJOR(reg);
}


/* ---------------------------------------------------------- AGATES field of the VERSION register ---------------------------------------------------------- */

/** Description of the AGATES field of the VERSION register. */
#define ATON_CLKCTRL_VERSION_AGATES_DESC  "Number of A Clock gates (for system blocks)"

/** Offset of the AGATES field of the VERSION register. */
#define ATON_CLKCTRL_VERSION_AGATES_LSB  16UL

/** Size in bits of the AGATES field of the VERSION register. */
#define ATON_CLKCTRL_VERSION_AGATES_W  (4UL)

/** Mask for retrieving the AGATES field of the VERSION register. */
#define ATON_CLKCTRL_VERSION_AGATES_MASK  ATON_FIELD_MASK(16UL, 4UL)

/** Reset value of the AGATES field of the VERSION register. */
#define ATON_CLKCTRL_VERSION_AGATES_DT  0x4UL

/** Access rights of the AGATES field of the VERSION register. */
#define ATON_CLKCTRL_VERSION_AGATES_AC  "R"

/** Check whether access to the AGATES field of the VERSION register is secured or not. */
#define ATON_CLKCTRL_VERSION_AGATES_S  0

/** Check whether access to the AGATES field of the VERSION register is privileged or not. */
#define ATON_CLKCTRL_VERSION_AGATES_P  0

/** Read the content of the AGATES field of the VERSION register. */
#define ATON_CLKCTRL_VERSION_GET_AGATES(REG)  ATON_GET_FIELD(REG, ATON_CLKCTRL_VERSION_AGATES_LSB, ATON_CLKCTRL_VERSION_AGATES_W)


/**
 * Get the description of the AGATES field of VERSION register.
 *
 * \return the description of the AGATES field of VERSION register
 */

static inline const int8_t *ATON_CLKCTRL_VERSION_AGATES_GetdDesc(void)
{
  return (const int8_t *)ATON_CLKCTRL_VERSION_AGATES_DESC;
}


/**
 * Read the content of the AGATES field of the VERSION register.
 *
 * \param[in] reg is the value of the VERSION register
 *
 * \return the content of the AGATES field belonging to VERSION register
 */

static inline uint32_t ATON_CLKCTRL_VERSION_Get_AGATES(uint32_t reg)
{
  return ATON_CLKCTRL_VERSION_GET_AGATES(reg);
}


/* ---------------------------------------------------------- BGATES field of the VERSION register ---------------------------------------------------------- */

/** Description of the BGATES field of the VERSION register. */
#define ATON_CLKCTRL_VERSION_BGATES_DESC  "Number of B Clock gates (for functional units)"

/** Offset of the BGATES field of the VERSION register. */
#define ATON_CLKCTRL_VERSION_BGATES_LSB  20UL

/** Size in bits of the BGATES field of the VERSION register. */
#define ATON_CLKCTRL_VERSION_BGATES_W  (8UL)

/** Mask for retrieving the BGATES field of the VERSION register. */
#define ATON_CLKCTRL_VERSION_BGATES_MASK  ATON_FIELD_MASK(20UL, 8UL)

/** Reset value of the BGATES field of the VERSION register. */
#define ATON_CLKCTRL_VERSION_BGATES_DT  0x1bUL

/** Access rights of the BGATES field of the VERSION register. */
#define ATON_CLKCTRL_VERSION_BGATES_AC  "R"

/** Check whether access to the BGATES field of the VERSION register is secured or not. */
#define ATON_CLKCTRL_VERSION_BGATES_S  0

/** Check whether access to the BGATES field of the VERSION register is privileged or not. */
#define ATON_CLKCTRL_VERSION_BGATES_P  0

/** Read the content of the BGATES field of the VERSION register. */
#define ATON_CLKCTRL_VERSION_GET_BGATES(REG)  ATON_GET_FIELD(REG, ATON_CLKCTRL_VERSION_BGATES_LSB, ATON_CLKCTRL_VERSION_BGATES_W)


/**
 * Get the description of the BGATES field of VERSION register.
 *
 * \return the description of the BGATES field of VERSION register
 */

static inline const int8_t *ATON_CLKCTRL_VERSION_BGATES_GetdDesc(void)
{
  return (const int8_t *)ATON_CLKCTRL_VERSION_BGATES_DESC;
}


/**
 * Read the content of the BGATES field of the VERSION register.
 *
 * \param[in] reg is the value of the VERSION register
 *
 * \return the content of the BGATES field belonging to VERSION register
 */

static inline uint32_t ATON_CLKCTRL_VERSION_Get_BGATES(uint32_t reg)
{
  return ATON_CLKCTRL_VERSION_GET_BGATES(reg);
}


/* ---------------------------------------------------------- CLKDIV field of the VERSION register ---------------------------------------------------------- */

/** Description of the CLKDIV field of the VERSION register. */
#define ATON_CLKCTRL_VERSION_CLKDIV_DESC  "Number of clock dividers"

/** Offset of the CLKDIV field of the VERSION register. */
#define ATON_CLKCTRL_VERSION_CLKDIV_LSB  28UL

/** Size in bits of the CLKDIV field of the VERSION register. */
#define ATON_CLKCTRL_VERSION_CLKDIV_W  (4UL)

/** Mask for retrieving the CLKDIV field of the VERSION register. */
#define ATON_CLKCTRL_VERSION_CLKDIV_MASK  ATON_FIELD_MASK(28UL, 4UL)

/** Reset value of the CLKDIV field of the VERSION register. */
#define ATON_CLKCTRL_VERSION_CLKDIV_DT  0x0UL

/** Access rights of the CLKDIV field of the VERSION register. */
#define ATON_CLKCTRL_VERSION_CLKDIV_AC  "R"

/** Check whether access to the CLKDIV field of the VERSION register is secured or not. */
#define ATON_CLKCTRL_VERSION_CLKDIV_S  0

/** Check whether access to the CLKDIV field of the VERSION register is privileged or not. */
#define ATON_CLKCTRL_VERSION_CLKDIV_P  0

/** Read the content of the CLKDIV field of the VERSION register. */
#define ATON_CLKCTRL_VERSION_GET_CLKDIV(REG)  ATON_GET_FIELD(REG, ATON_CLKCTRL_VERSION_CLKDIV_LSB, ATON_CLKCTRL_VERSION_CLKDIV_W)


/**
 * Get the description of the CLKDIV field of VERSION register.
 *
 * \return the description of the CLKDIV field of VERSION register
 */

static inline const int8_t *ATON_CLKCTRL_VERSION_CLKDIV_GetdDesc(void)
{
  return (const int8_t *)ATON_CLKCTRL_VERSION_CLKDIV_DESC;
}


/**
 * Read the content of the CLKDIV field of the VERSION register.
 *
 * \param[in] reg is the value of the VERSION register
 *
 * \return the content of the CLKDIV field belonging to VERSION register
 */

static inline uint32_t ATON_CLKCTRL_VERSION_Get_CLKDIV(uint32_t reg)
{
  return ATON_CLKCTRL_VERSION_GET_CLKDIV(reg);
}


/* ****************************************************** AGATES0 register of one of the CLKCTRL Units ****************************************************** */

/** Offset of the AGATES0 register from the base address of the CLKCTRL Unit. */
#define ATON_CLKCTRL_AGATES0_OFFSET  0x8UL

/** Reset value of the AGATES0 register of the CLKCTRL Unit. */
#define ATON_CLKCTRL_AGATES0_DT \
  (ATON_CLKCTRL_AGATES0_INTCTRL_DT   << ATON_CLKCTRL_AGATES0_INTCTRL_LSB)   | \
  (ATON_CLKCTRL_AGATES0_BUSIF0_DT    << ATON_CLKCTRL_AGATES0_BUSIF0_LSB)    | \
  (ATON_CLKCTRL_AGATES0_BUSIF1_DT    << ATON_CLKCTRL_AGATES0_BUSIF1_LSB)    | \
  (ATON_CLKCTRL_AGATES0_STRSWITCH_DT << ATON_CLKCTRL_AGATES0_STRSWITCH_LSB)



/** Description of the AGATES0 register. */
#define ATON_CLKCTRL_AGATES0_DESC  "Clock enable bits"

/** Address of the AGATES0 register of one of the CLKCTRL Units. */
#define ATON_CLKCTRL_AGATES0_ADDR(UNIT)  (ATON_CLKCTRL_BASE(UNIT) + ATON_CLKCTRL_AGATES0_OFFSET)

/** Get the content of the AGATES0 register of one of the CLKCTRL Units. */
#define ATON_CLKCTRL_AGATES0_GET(UNIT)  (*((volatile uint32_t *)(uintptr_t)ATON_CLKCTRL_AGATES0_ADDR(UNIT)))

/** Set the content of the AGATES0 register of one of the CLKCTRL Units. */
#define ATON_CLKCTRL_AGATES0_SET(UNIT, DATA)  do { *((volatile uint32_t *)(uintptr_t)ATON_CLKCTRL_AGATES0_ADDR(UNIT)) = (DATA); } while (0);


/**
 * Get the description of AGATES0 register.
 *
 * \return the description of AGATES0 register
 */

static inline const int8_t *ATON_CLKCTRL_AGATES0_GetDesc(void)
{
  return (const int8_t *)ATON_CLKCTRL_AGATES0_DESC;
}


/**
 * Get the offset of the AGATES0 register.
 *
 * \return the offset of AGATES0 register
 */

static inline uint32_t ATON_CLKCTRL_AGATES0_GetOffset(void)
{
  return ATON_CLKCTRL_AGATES0_OFFSET;
}


/**
 * Get the address of the AGATES0 register.
 *
 * \param[in] instance is the index of the Unit (among the CLKCTRL Units) containing the AGATES0 register whose address must be returned
 *                     (it must be <em>instance \< 1<\em>)
 *
 * \return the address of AGATES0 register belonging to Unit having index \e instance among the CLKCTRL Units
 */

static inline uint32_t ATON_CLKCTRL_AGATES0_GetAddr(uint32_t instance)
{
  return ATON_CLKCTRL_AGATES0_ADDR(instance);
}


/**
 * Read the content of the AGATES0 register.
 *
 * \param[in] instance is the index of the Unit (among the CLKCTRL Units) containing the AGATES0 register whose content must be retrieved
 *                     (it must be <em>instance \< 1<\em>)
 *
 * \return the content of AGATES0 register belonging to Unit having index \e instance among the CLKCTRL Units
 */

static inline uint32_t ATON_CLKCTRL_AGATES0_Get(uint32_t instance)
{
  return ATON_CLKCTRL_AGATES0_GET(instance);
}


/**
 * Write the content of the AGATES0 register.
 *
 * \param[in] instance is the index of the Unit (among the CLKCTRL Units) containing the AGATES0 register whose content must be modified
 *                     (it must be <em>instance \< 1<\em>)
 * \param[in] data     is 32-bit value that must be written to the register
 */

static inline void ATON_CLKCTRL_AGATES0_Set(uint32_t instance, uint32_t data)
{
  ATON_CLKCTRL_AGATES0_SET(instance, data);
}


/* --------------------------------------------------------- INTCTRL field of the AGATES0 register ---------------------------------------------------------- */

/** Description of the INTCTRL field of the AGATES0 register. */
#define ATON_CLKCTRL_AGATES0_INTCTRL_DESC  "Enable clock of Interrupt Controller"

/** Offset of the INTCTRL field of the AGATES0 register. */
#define ATON_CLKCTRL_AGATES0_INTCTRL_LSB  0UL

/** Size in bits of the INTCTRL field of the AGATES0 register. */
#define ATON_CLKCTRL_AGATES0_INTCTRL_W  (1UL)

/** Mask for retrieving the INTCTRL field of the AGATES0 register. */
#define ATON_CLKCTRL_AGATES0_INTCTRL_MASK  ATON_FIELD_MASK(0UL, 1UL)

/** Reset value of the INTCTRL field of the AGATES0 register. */
#define ATON_CLKCTRL_AGATES0_INTCTRL_DT  0x0UL

/** Access rights of the INTCTRL field of the AGATES0 register. */
#define ATON_CLKCTRL_AGATES0_INTCTRL_AC  "RW"

/** Check whether access to the INTCTRL field of the AGATES0 register is secured or not. */
#define ATON_CLKCTRL_AGATES0_INTCTRL_S  0

/** Check whether access to the INTCTRL field of the AGATES0 register is privileged or not. */
#define ATON_CLKCTRL_AGATES0_INTCTRL_P  0

/** Read the content of the INTCTRL field of the AGATES0 register. */
#define ATON_CLKCTRL_AGATES0_GET_INTCTRL(REG)  ATON_GET_FIELD(REG, ATON_CLKCTRL_AGATES0_INTCTRL_LSB, ATON_CLKCTRL_AGATES0_INTCTRL_W)

/** Modify the content of the INTCTRL field of the AGATES0 register. */
#define ATON_CLKCTRL_AGATES0_SET_INTCTRL(REG, DATA)  ATON_SET_FIELD(REG, ATON_CLKCTRL_AGATES0_INTCTRL_LSB, ATON_CLKCTRL_AGATES0_INTCTRL_W, DATA)


/**
 * Get the description of the INTCTRL field of AGATES0 register.
 *
 * \return the description of the INTCTRL field of AGATES0 register
 */

static inline const int8_t *ATON_CLKCTRL_AGATES0_INTCTRL_GetdDesc(void)
{
  return (const int8_t *)ATON_CLKCTRL_AGATES0_INTCTRL_DESC;
}


/**
 * Read the content of the INTCTRL field of the AGATES0 register.
 *
 * \param[in] reg is the value of the AGATES0 register
 *
 * \return the content of the INTCTRL field belonging to AGATES0 register
 */

static inline uint32_t ATON_CLKCTRL_AGATES0_Get_INTCTRL(uint32_t reg)
{
  return ATON_CLKCTRL_AGATES0_GET_INTCTRL(reg);
}


/**
 * Write the content of the INTCTRL field of the AGATES0 register.
 *
 * \param[in] reg  is the value of the AGATES0 register
 * \param[in] data is 1-bit value that must be written to the field
 *
 * \return the new content of the INTCTRL field belonging to AGATES0 register
 */

static inline uint32_t ATON_CLKCTRL_AGATES0_Set_INTCTRL(uint32_t reg, uint32_t data)
{
  return ATON_CLKCTRL_AGATES0_SET_INTCTRL(reg, data);
}


/* ---------------------------------------------------------- BUSIF0 field of the AGATES0 register ---------------------------------------------------------- */

/** Description of the BUSIF0 field of the AGATES0 register. */
#define ATON_CLKCTRL_AGATES0_BUSIF0_DESC  "Enable clock of Bus Interface 0"

/** Offset of the BUSIF0 field of the AGATES0 register. */
#define ATON_CLKCTRL_AGATES0_BUSIF0_LSB  1UL

/** Size in bits of the BUSIF0 field of the AGATES0 register. */
#define ATON_CLKCTRL_AGATES0_BUSIF0_W  (1UL)

/** Mask for retrieving the BUSIF0 field of the AGATES0 register. */
#define ATON_CLKCTRL_AGATES0_BUSIF0_MASK  ATON_FIELD_MASK(1UL, 1UL)

/** Reset value of the BUSIF0 field of the AGATES0 register. */
#define ATON_CLKCTRL_AGATES0_BUSIF0_DT  0x0UL

/** Access rights of the BUSIF0 field of the AGATES0 register. */
#define ATON_CLKCTRL_AGATES0_BUSIF0_AC  "RW"

/** Check whether access to the BUSIF0 field of the AGATES0 register is secured or not. */
#define ATON_CLKCTRL_AGATES0_BUSIF0_S  0

/** Check whether access to the BUSIF0 field of the AGATES0 register is privileged or not. */
#define ATON_CLKCTRL_AGATES0_BUSIF0_P  0

/** Read the content of the BUSIF0 field of the AGATES0 register. */
#define ATON_CLKCTRL_AGATES0_GET_BUSIF0(REG)  ATON_GET_FIELD(REG, ATON_CLKCTRL_AGATES0_BUSIF0_LSB, ATON_CLKCTRL_AGATES0_BUSIF0_W)

/** Modify the content of the BUSIF0 field of the AGATES0 register. */
#define ATON_CLKCTRL_AGATES0_SET_BUSIF0(REG, DATA)  ATON_SET_FIELD(REG, ATON_CLKCTRL_AGATES0_BUSIF0_LSB, ATON_CLKCTRL_AGATES0_BUSIF0_W, DATA)


/**
 * Get the description of the BUSIF0 field of AGATES0 register.
 *
 * \return the description of the BUSIF0 field of AGATES0 register
 */

static inline const int8_t *ATON_CLKCTRL_AGATES0_BUSIF0_GetdDesc(void)
{
  return (const int8_t *)ATON_CLKCTRL_AGATES0_BUSIF0_DESC;
}


/**
 * Read the content of the BUSIF0 field of the AGATES0 register.
 *
 * \param[in] reg is the value of the AGATES0 register
 *
 * \return the content of the BUSIF0 field belonging to AGATES0 register
 */

static inline uint32_t ATON_CLKCTRL_AGATES0_Get_BUSIF0(uint32_t reg)
{
  return ATON_CLKCTRL_AGATES0_GET_BUSIF0(reg);
}


/**
 * Write the content of the BUSIF0 field of the AGATES0 register.
 *
 * \param[in] reg  is the value of the AGATES0 register
 * \param[in] data is 1-bit value that must be written to the field
 *
 * \return the new content of the BUSIF0 field belonging to AGATES0 register
 */

static inline uint32_t ATON_CLKCTRL_AGATES0_Set_BUSIF0(uint32_t reg, uint32_t data)
{
  return ATON_CLKCTRL_AGATES0_SET_BUSIF0(reg, data);
}


/* ---------------------------------------------------------- BUSIF1 field of the AGATES0 register ---------------------------------------------------------- */

/** Description of the BUSIF1 field of the AGATES0 register. */
#define ATON_CLKCTRL_AGATES0_BUSIF1_DESC  "Enable clock of Bus Interface 1"

/** Offset of the BUSIF1 field of the AGATES0 register. */
#define ATON_CLKCTRL_AGATES0_BUSIF1_LSB  2UL

/** Size in bits of the BUSIF1 field of the AGATES0 register. */
#define ATON_CLKCTRL_AGATES0_BUSIF1_W  (1UL)

/** Mask for retrieving the BUSIF1 field of the AGATES0 register. */
#define ATON_CLKCTRL_AGATES0_BUSIF1_MASK  ATON_FIELD_MASK(2UL, 1UL)

/** Reset value of the BUSIF1 field of the AGATES0 register. */
#define ATON_CLKCTRL_AGATES0_BUSIF1_DT  0x0UL

/** Access rights of the BUSIF1 field of the AGATES0 register. */
#define ATON_CLKCTRL_AGATES0_BUSIF1_AC  "RW"

/** Check whether access to the BUSIF1 field of the AGATES0 register is secured or not. */
#define ATON_CLKCTRL_AGATES0_BUSIF1_S  0

/** Check whether access to the BUSIF1 field of the AGATES0 register is privileged or not. */
#define ATON_CLKCTRL_AGATES0_BUSIF1_P  0

/** Read the content of the BUSIF1 field of the AGATES0 register. */
#define ATON_CLKCTRL_AGATES0_GET_BUSIF1(REG)  ATON_GET_FIELD(REG, ATON_CLKCTRL_AGATES0_BUSIF1_LSB, ATON_CLKCTRL_AGATES0_BUSIF1_W)

/** Modify the content of the BUSIF1 field of the AGATES0 register. */
#define ATON_CLKCTRL_AGATES0_SET_BUSIF1(REG, DATA)  ATON_SET_FIELD(REG, ATON_CLKCTRL_AGATES0_BUSIF1_LSB, ATON_CLKCTRL_AGATES0_BUSIF1_W, DATA)


/**
 * Get the description of the BUSIF1 field of AGATES0 register.
 *
 * \return the description of the BUSIF1 field of AGATES0 register
 */

static inline const int8_t *ATON_CLKCTRL_AGATES0_BUSIF1_GetdDesc(void)
{
  return (const int8_t *)ATON_CLKCTRL_AGATES0_BUSIF1_DESC;
}


/**
 * Read the content of the BUSIF1 field of the AGATES0 register.
 *
 * \param[in] reg is the value of the AGATES0 register
 *
 * \return the content of the BUSIF1 field belonging to AGATES0 register
 */

static inline uint32_t ATON_CLKCTRL_AGATES0_Get_BUSIF1(uint32_t reg)
{
  return ATON_CLKCTRL_AGATES0_GET_BUSIF1(reg);
}


/**
 * Write the content of the BUSIF1 field of the AGATES0 register.
 *
 * \param[in] reg  is the value of the AGATES0 register
 * \param[in] data is 1-bit value that must be written to the field
 *
 * \return the new content of the BUSIF1 field belonging to AGATES0 register
 */

static inline uint32_t ATON_CLKCTRL_AGATES0_Set_BUSIF1(uint32_t reg, uint32_t data)
{
  return ATON_CLKCTRL_AGATES0_SET_BUSIF1(reg, data);
}


/* -------------------------------------------------------- STRSWITCH field of the AGATES0 register --------------------------------------------------------- */

/** Description of the STRSWITCH field of the AGATES0 register. */
#define ATON_CLKCTRL_AGATES0_STRSWITCH_DESC  "Enable clock of Stream Switch"

/** Offset of the STRSWITCH field of the AGATES0 register. */
#define ATON_CLKCTRL_AGATES0_STRSWITCH_LSB  3UL

/** Size in bits of the STRSWITCH field of the AGATES0 register. */
#define ATON_CLKCTRL_AGATES0_STRSWITCH_W  (1UL)

/** Mask for retrieving the STRSWITCH field of the AGATES0 register. */
#define ATON_CLKCTRL_AGATES0_STRSWITCH_MASK  ATON_FIELD_MASK(3UL, 1UL)

/** Reset value of the STRSWITCH field of the AGATES0 register. */
#define ATON_CLKCTRL_AGATES0_STRSWITCH_DT  0x0UL

/** Access rights of the STRSWITCH field of the AGATES0 register. */
#define ATON_CLKCTRL_AGATES0_STRSWITCH_AC  "RW"

/** Check whether access to the STRSWITCH field of the AGATES0 register is secured or not. */
#define ATON_CLKCTRL_AGATES0_STRSWITCH_S  0

/** Check whether access to the STRSWITCH field of the AGATES0 register is privileged or not. */
#define ATON_CLKCTRL_AGATES0_STRSWITCH_P  0

/** Read the content of the STRSWITCH field of the AGATES0 register. */
#define ATON_CLKCTRL_AGATES0_GET_STRSWITCH(REG)  ATON_GET_FIELD(REG, ATON_CLKCTRL_AGATES0_STRSWITCH_LSB, ATON_CLKCTRL_AGATES0_STRSWITCH_W)

/** Modify the content of the STRSWITCH field of the AGATES0 register. */
#define ATON_CLKCTRL_AGATES0_SET_STRSWITCH(REG, DATA)  ATON_SET_FIELD(REG, ATON_CLKCTRL_AGATES0_STRSWITCH_LSB, ATON_CLKCTRL_AGATES0_STRSWITCH_W, DATA)


/**
 * Get the description of the STRSWITCH field of AGATES0 register.
 *
 * \return the description of the STRSWITCH field of AGATES0 register
 */

static inline const int8_t *ATON_CLKCTRL_AGATES0_STRSWITCH_GetdDesc(void)
{
  return (const int8_t *)ATON_CLKCTRL_AGATES0_STRSWITCH_DESC;
}


/**
 * Read the content of the STRSWITCH field of the AGATES0 register.
 *
 * \param[in] reg is the value of the AGATES0 register
 *
 * \return the content of the STRSWITCH field belonging to AGATES0 register
 */

static inline uint32_t ATON_CLKCTRL_AGATES0_Get_STRSWITCH(uint32_t reg)
{
  return ATON_CLKCTRL_AGATES0_GET_STRSWITCH(reg);
}


/**
 * Write the content of the STRSWITCH field of the AGATES0 register.
 *
 * \param[in] reg  is the value of the AGATES0 register
 * \param[in] data is 1-bit value that must be written to the field
 *
 * \return the new content of the STRSWITCH field belonging to AGATES0 register
 */

static inline uint32_t ATON_CLKCTRL_AGATES0_Set_STRSWITCH(uint32_t reg, uint32_t data)
{
  return ATON_CLKCTRL_AGATES0_SET_STRSWITCH(reg, data);
}


/* ****************************************************** AGATES1 register of one of the CLKCTRL Units ****************************************************** */

/** Offset of the AGATES1 register from the base address of the CLKCTRL Unit. */
#define ATON_CLKCTRL_AGATES1_OFFSET  0xcUL

/** Reset value of the AGATES1 register of the CLKCTRL Unit. */
#define ATON_CLKCTRL_AGATES1_DT \
  (ATON_CLKCTRL_AGATES1_INTCTRL_DT   << ATON_CLKCTRL_AGATES1_INTCTRL_LSB)   | \
  (ATON_CLKCTRL_AGATES1_BUSIF0_DT    << ATON_CLKCTRL_AGATES1_BUSIF0_LSB)    | \
  (ATON_CLKCTRL_AGATES1_BUSIF1_DT    << ATON_CLKCTRL_AGATES1_BUSIF1_LSB)    | \
  (ATON_CLKCTRL_AGATES1_STRSWITCH_DT << ATON_CLKCTRL_AGATES1_STRSWITCH_LSB)



/** Description of the AGATES1 register. */
#define ATON_CLKCTRL_AGATES1_DESC  "Copy of AGATES0 register"

/** Address of the AGATES1 register of one of the CLKCTRL Units. */
#define ATON_CLKCTRL_AGATES1_ADDR(UNIT)  (ATON_CLKCTRL_BASE(UNIT) + ATON_CLKCTRL_AGATES1_OFFSET)

/** Get the content of the AGATES1 register of one of the CLKCTRL Units. */
#define ATON_CLKCTRL_AGATES1_GET(UNIT)  (*((volatile uint32_t *)(uintptr_t)ATON_CLKCTRL_AGATES1_ADDR(UNIT)))

/** Set the content of the AGATES1 register of one of the CLKCTRL Units. */
#define ATON_CLKCTRL_AGATES1_SET(UNIT, DATA)  do { *((volatile uint32_t *)(uintptr_t)ATON_CLKCTRL_AGATES1_ADDR(UNIT)) = (DATA); } while (0);


/**
 * Get the description of AGATES1 register.
 *
 * \return the description of AGATES1 register
 */

static inline const int8_t *ATON_CLKCTRL_AGATES1_GetDesc(void)
{
  return (const int8_t *)ATON_CLKCTRL_AGATES1_DESC;
}


/**
 * Get the offset of the AGATES1 register.
 *
 * \return the offset of AGATES1 register
 */

static inline uint32_t ATON_CLKCTRL_AGATES1_GetOffset(void)
{
  return ATON_CLKCTRL_AGATES1_OFFSET;
}


/**
 * Get the address of the AGATES1 register.
 *
 * \param[in] instance is the index of the Unit (among the CLKCTRL Units) containing the AGATES1 register whose address must be returned
 *                     (it must be <em>instance \< 1<\em>)
 *
 * \return the address of AGATES1 register belonging to Unit having index \e instance among the CLKCTRL Units
 */

static inline uint32_t ATON_CLKCTRL_AGATES1_GetAddr(uint32_t instance)
{
  return ATON_CLKCTRL_AGATES1_ADDR(instance);
}


/**
 * Read the content of the AGATES1 register.
 *
 * \param[in] instance is the index of the Unit (among the CLKCTRL Units) containing the AGATES1 register whose content must be retrieved
 *                     (it must be <em>instance \< 1<\em>)
 *
 * \return the content of AGATES1 register belonging to Unit having index \e instance among the CLKCTRL Units
 */

static inline uint32_t ATON_CLKCTRL_AGATES1_Get(uint32_t instance)
{
  return ATON_CLKCTRL_AGATES1_GET(instance);
}


/**
 * Write the content of the AGATES1 register.
 *
 * \param[in] instance is the index of the Unit (among the CLKCTRL Units) containing the AGATES1 register whose content must be modified
 *                     (it must be <em>instance \< 1<\em>)
 * \param[in] data     is 32-bit value that must be written to the register
 */

static inline void ATON_CLKCTRL_AGATES1_Set(uint32_t instance, uint32_t data)
{
  ATON_CLKCTRL_AGATES1_SET(instance, data);
}


/* --------------------------------------------------------- INTCTRL field of the AGATES1 register ---------------------------------------------------------- */

/** Description of the INTCTRL field of the AGATES1 register. */
#define ATON_CLKCTRL_AGATES1_INTCTRL_DESC  "Enable clock of Interrupt Controller"

/** Offset of the INTCTRL field of the AGATES1 register. */
#define ATON_CLKCTRL_AGATES1_INTCTRL_LSB  0UL

/** Size in bits of the INTCTRL field of the AGATES1 register. */
#define ATON_CLKCTRL_AGATES1_INTCTRL_W  (1UL)

/** Mask for retrieving the INTCTRL field of the AGATES1 register. */
#define ATON_CLKCTRL_AGATES1_INTCTRL_MASK  ATON_FIELD_MASK(0UL, 1UL)

/** Reset value of the INTCTRL field of the AGATES1 register. */
#define ATON_CLKCTRL_AGATES1_INTCTRL_DT  0x0UL

/** Access rights of the INTCTRL field of the AGATES1 register. */
#define ATON_CLKCTRL_AGATES1_INTCTRL_AC  "RW"

/** Check whether access to the INTCTRL field of the AGATES1 register is secured or not. */
#define ATON_CLKCTRL_AGATES1_INTCTRL_S  0

/** Check whether access to the INTCTRL field of the AGATES1 register is privileged or not. */
#define ATON_CLKCTRL_AGATES1_INTCTRL_P  0

/** Read the content of the INTCTRL field of the AGATES1 register. */
#define ATON_CLKCTRL_AGATES1_GET_INTCTRL(REG)  ATON_GET_FIELD(REG, ATON_CLKCTRL_AGATES1_INTCTRL_LSB, ATON_CLKCTRL_AGATES1_INTCTRL_W)

/** Modify the content of the INTCTRL field of the AGATES1 register. */
#define ATON_CLKCTRL_AGATES1_SET_INTCTRL(REG, DATA)  ATON_SET_FIELD(REG, ATON_CLKCTRL_AGATES1_INTCTRL_LSB, ATON_CLKCTRL_AGATES1_INTCTRL_W, DATA)


/**
 * Get the description of the INTCTRL field of AGATES1 register.
 *
 * \return the description of the INTCTRL field of AGATES1 register
 */

static inline const int8_t *ATON_CLKCTRL_AGATES1_INTCTRL_GetdDesc(void)
{
  return (const int8_t *)ATON_CLKCTRL_AGATES1_INTCTRL_DESC;
}


/**
 * Read the content of the INTCTRL field of the AGATES1 register.
 *
 * \param[in] reg is the value of the AGATES1 register
 *
 * \return the content of the INTCTRL field belonging to AGATES1 register
 */

static inline uint32_t ATON_CLKCTRL_AGATES1_Get_INTCTRL(uint32_t reg)
{
  return ATON_CLKCTRL_AGATES1_GET_INTCTRL(reg);
}


/**
 * Write the content of the INTCTRL field of the AGATES1 register.
 *
 * \param[in] reg  is the value of the AGATES1 register
 * \param[in] data is 1-bit value that must be written to the field
 *
 * \return the new content of the INTCTRL field belonging to AGATES1 register
 */

static inline uint32_t ATON_CLKCTRL_AGATES1_Set_INTCTRL(uint32_t reg, uint32_t data)
{
  return ATON_CLKCTRL_AGATES1_SET_INTCTRL(reg, data);
}


/* ---------------------------------------------------------- BUSIF0 field of the AGATES1 register ---------------------------------------------------------- */

/** Description of the BUSIF0 field of the AGATES1 register. */
#define ATON_CLKCTRL_AGATES1_BUSIF0_DESC  "Enable clock of Bus Interface 0"

/** Offset of the BUSIF0 field of the AGATES1 register. */
#define ATON_CLKCTRL_AGATES1_BUSIF0_LSB  1UL

/** Size in bits of the BUSIF0 field of the AGATES1 register. */
#define ATON_CLKCTRL_AGATES1_BUSIF0_W  (1UL)

/** Mask for retrieving the BUSIF0 field of the AGATES1 register. */
#define ATON_CLKCTRL_AGATES1_BUSIF0_MASK  ATON_FIELD_MASK(1UL, 1UL)

/** Reset value of the BUSIF0 field of the AGATES1 register. */
#define ATON_CLKCTRL_AGATES1_BUSIF0_DT  0x0UL

/** Access rights of the BUSIF0 field of the AGATES1 register. */
#define ATON_CLKCTRL_AGATES1_BUSIF0_AC  "RW"

/** Check whether access to the BUSIF0 field of the AGATES1 register is secured or not. */
#define ATON_CLKCTRL_AGATES1_BUSIF0_S  0

/** Check whether access to the BUSIF0 field of the AGATES1 register is privileged or not. */
#define ATON_CLKCTRL_AGATES1_BUSIF0_P  0

/** Read the content of the BUSIF0 field of the AGATES1 register. */
#define ATON_CLKCTRL_AGATES1_GET_BUSIF0(REG)  ATON_GET_FIELD(REG, ATON_CLKCTRL_AGATES1_BUSIF0_LSB, ATON_CLKCTRL_AGATES1_BUSIF0_W)

/** Modify the content of the BUSIF0 field of the AGATES1 register. */
#define ATON_CLKCTRL_AGATES1_SET_BUSIF0(REG, DATA)  ATON_SET_FIELD(REG, ATON_CLKCTRL_AGATES1_BUSIF0_LSB, ATON_CLKCTRL_AGATES1_BUSIF0_W, DATA)


/**
 * Get the description of the BUSIF0 field of AGATES1 register.
 *
 * \return the description of the BUSIF0 field of AGATES1 register
 */

static inline const int8_t *ATON_CLKCTRL_AGATES1_BUSIF0_GetdDesc(void)
{
  return (const int8_t *)ATON_CLKCTRL_AGATES1_BUSIF0_DESC;
}


/**
 * Read the content of the BUSIF0 field of the AGATES1 register.
 *
 * \param[in] reg is the value of the AGATES1 register
 *
 * \return the content of the BUSIF0 field belonging to AGATES1 register
 */

static inline uint32_t ATON_CLKCTRL_AGATES1_Get_BUSIF0(uint32_t reg)
{
  return ATON_CLKCTRL_AGATES1_GET_BUSIF0(reg);
}


/**
 * Write the content of the BUSIF0 field of the AGATES1 register.
 *
 * \param[in] reg  is the value of the AGATES1 register
 * \param[in] data is 1-bit value that must be written to the field
 *
 * \return the new content of the BUSIF0 field belonging to AGATES1 register
 */

static inline uint32_t ATON_CLKCTRL_AGATES1_Set_BUSIF0(uint32_t reg, uint32_t data)
{
  return ATON_CLKCTRL_AGATES1_SET_BUSIF0(reg, data);
}


/* ---------------------------------------------------------- BUSIF1 field of the AGATES1 register ---------------------------------------------------------- */

/** Description of the BUSIF1 field of the AGATES1 register. */
#define ATON_CLKCTRL_AGATES1_BUSIF1_DESC  "Enable clock of Bus Interface 1"

/** Offset of the BUSIF1 field of the AGATES1 register. */
#define ATON_CLKCTRL_AGATES1_BUSIF1_LSB  2UL

/** Size in bits of the BUSIF1 field of the AGATES1 register. */
#define ATON_CLKCTRL_AGATES1_BUSIF1_W  (1UL)

/** Mask for retrieving the BUSIF1 field of the AGATES1 register. */
#define ATON_CLKCTRL_AGATES1_BUSIF1_MASK  ATON_FIELD_MASK(2UL, 1UL)

/** Reset value of the BUSIF1 field of the AGATES1 register. */
#define ATON_CLKCTRL_AGATES1_BUSIF1_DT  0x0UL

/** Access rights of the BUSIF1 field of the AGATES1 register. */
#define ATON_CLKCTRL_AGATES1_BUSIF1_AC  "RW"

/** Check whether access to the BUSIF1 field of the AGATES1 register is secured or not. */
#define ATON_CLKCTRL_AGATES1_BUSIF1_S  0

/** Check whether access to the BUSIF1 field of the AGATES1 register is privileged or not. */
#define ATON_CLKCTRL_AGATES1_BUSIF1_P  0

/** Read the content of the BUSIF1 field of the AGATES1 register. */
#define ATON_CLKCTRL_AGATES1_GET_BUSIF1(REG)  ATON_GET_FIELD(REG, ATON_CLKCTRL_AGATES1_BUSIF1_LSB, ATON_CLKCTRL_AGATES1_BUSIF1_W)

/** Modify the content of the BUSIF1 field of the AGATES1 register. */
#define ATON_CLKCTRL_AGATES1_SET_BUSIF1(REG, DATA)  ATON_SET_FIELD(REG, ATON_CLKCTRL_AGATES1_BUSIF1_LSB, ATON_CLKCTRL_AGATES1_BUSIF1_W, DATA)


/**
 * Get the description of the BUSIF1 field of AGATES1 register.
 *
 * \return the description of the BUSIF1 field of AGATES1 register
 */

static inline const int8_t *ATON_CLKCTRL_AGATES1_BUSIF1_GetdDesc(void)
{
  return (const int8_t *)ATON_CLKCTRL_AGATES1_BUSIF1_DESC;
}


/**
 * Read the content of the BUSIF1 field of the AGATES1 register.
 *
 * \param[in] reg is the value of the AGATES1 register
 *
 * \return the content of the BUSIF1 field belonging to AGATES1 register
 */

static inline uint32_t ATON_CLKCTRL_AGATES1_Get_BUSIF1(uint32_t reg)
{
  return ATON_CLKCTRL_AGATES1_GET_BUSIF1(reg);
}


/**
 * Write the content of the BUSIF1 field of the AGATES1 register.
 *
 * \param[in] reg  is the value of the AGATES1 register
 * \param[in] data is 1-bit value that must be written to the field
 *
 * \return the new content of the BUSIF1 field belonging to AGATES1 register
 */

static inline uint32_t ATON_CLKCTRL_AGATES1_Set_BUSIF1(uint32_t reg, uint32_t data)
{
  return ATON_CLKCTRL_AGATES1_SET_BUSIF1(reg, data);
}


/* -------------------------------------------------------- STRSWITCH field of the AGATES1 register --------------------------------------------------------- */

/** Description of the STRSWITCH field of the AGATES1 register. */
#define ATON_CLKCTRL_AGATES1_STRSWITCH_DESC  "Enable clock of Stream Switch"

/** Offset of the STRSWITCH field of the AGATES1 register. */
#define ATON_CLKCTRL_AGATES1_STRSWITCH_LSB  3UL

/** Size in bits of the STRSWITCH field of the AGATES1 register. */
#define ATON_CLKCTRL_AGATES1_STRSWITCH_W  (1UL)

/** Mask for retrieving the STRSWITCH field of the AGATES1 register. */
#define ATON_CLKCTRL_AGATES1_STRSWITCH_MASK  ATON_FIELD_MASK(3UL, 1UL)

/** Reset value of the STRSWITCH field of the AGATES1 register. */
#define ATON_CLKCTRL_AGATES1_STRSWITCH_DT  0x0UL

/** Access rights of the STRSWITCH field of the AGATES1 register. */
#define ATON_CLKCTRL_AGATES1_STRSWITCH_AC  "RW"

/** Check whether access to the STRSWITCH field of the AGATES1 register is secured or not. */
#define ATON_CLKCTRL_AGATES1_STRSWITCH_S  0

/** Check whether access to the STRSWITCH field of the AGATES1 register is privileged or not. */
#define ATON_CLKCTRL_AGATES1_STRSWITCH_P  0

/** Read the content of the STRSWITCH field of the AGATES1 register. */
#define ATON_CLKCTRL_AGATES1_GET_STRSWITCH(REG)  ATON_GET_FIELD(REG, ATON_CLKCTRL_AGATES1_STRSWITCH_LSB, ATON_CLKCTRL_AGATES1_STRSWITCH_W)

/** Modify the content of the STRSWITCH field of the AGATES1 register. */
#define ATON_CLKCTRL_AGATES1_SET_STRSWITCH(REG, DATA)  ATON_SET_FIELD(REG, ATON_CLKCTRL_AGATES1_STRSWITCH_LSB, ATON_CLKCTRL_AGATES1_STRSWITCH_W, DATA)


/**
 * Get the description of the STRSWITCH field of AGATES1 register.
 *
 * \return the description of the STRSWITCH field of AGATES1 register
 */

static inline const int8_t *ATON_CLKCTRL_AGATES1_STRSWITCH_GetdDesc(void)
{
  return (const int8_t *)ATON_CLKCTRL_AGATES1_STRSWITCH_DESC;
}


/**
 * Read the content of the STRSWITCH field of the AGATES1 register.
 *
 * \param[in] reg is the value of the AGATES1 register
 *
 * \return the content of the STRSWITCH field belonging to AGATES1 register
 */

static inline uint32_t ATON_CLKCTRL_AGATES1_Get_STRSWITCH(uint32_t reg)
{
  return ATON_CLKCTRL_AGATES1_GET_STRSWITCH(reg);
}


/**
 * Write the content of the STRSWITCH field of the AGATES1 register.
 *
 * \param[in] reg  is the value of the AGATES1 register
 * \param[in] data is 1-bit value that must be written to the field
 *
 * \return the new content of the STRSWITCH field belonging to AGATES1 register
 */

static inline uint32_t ATON_CLKCTRL_AGATES1_Set_STRSWITCH(uint32_t reg, uint32_t data)
{
  return ATON_CLKCTRL_AGATES1_SET_STRSWITCH(reg, data);
}


/* ****************************************************** BGATES register of one of the CLKCTRL Units ******************************************************* */

/** Offset of the BGATES register from the base address of the CLKCTRL Unit. */
#define ATON_CLKCTRL_BGATES_OFFSET  0x10UL

/** Reset value of the BGATES register of the CLKCTRL Unit. */
#define ATON_CLKCTRL_BGATES_DT \
  (ATON_CLKCTRL_BGATES_STRENG0_DT      << ATON_CLKCTRL_BGATES_STRENG0_LSB)      | \
  (ATON_CLKCTRL_BGATES_STRENG1_DT      << ATON_CLKCTRL_BGATES_STRENG1_LSB)      | \
  (ATON_CLKCTRL_BGATES_STRENG2_DT      << ATON_CLKCTRL_BGATES_STRENG2_LSB)      | \
  (ATON_CLKCTRL_BGATES_STRENG3_DT      << ATON_CLKCTRL_BGATES_STRENG3_LSB)      | \
  (ATON_CLKCTRL_BGATES_STRENG4_DT      << ATON_CLKCTRL_BGATES_STRENG4_LSB)      | \
  (ATON_CLKCTRL_BGATES_STRENG5_DT      << ATON_CLKCTRL_BGATES_STRENG5_LSB)      | \
  (ATON_CLKCTRL_BGATES_STRENG6_DT      << ATON_CLKCTRL_BGATES_STRENG6_LSB)      | \
  (ATON_CLKCTRL_BGATES_STRENG7_DT      << ATON_CLKCTRL_BGATES_STRENG7_LSB)      | \
  (ATON_CLKCTRL_BGATES_STRENG8_DT      << ATON_CLKCTRL_BGATES_STRENG8_LSB)      | \
  (ATON_CLKCTRL_BGATES_STRENG9_DT      << ATON_CLKCTRL_BGATES_STRENG9_LSB)      | \
  (ATON_CLKCTRL_BGATES_CONVACC0_DT     << ATON_CLKCTRL_BGATES_CONVACC0_LSB)     | \
  (ATON_CLKCTRL_BGATES_CONVACC1_DT     << ATON_CLKCTRL_BGATES_CONVACC1_LSB)     | \
  (ATON_CLKCTRL_BGATES_CONVACC2_DT     << ATON_CLKCTRL_BGATES_CONVACC2_LSB)     | \
  (ATON_CLKCTRL_BGATES_CONVACC3_DT     << ATON_CLKCTRL_BGATES_CONVACC3_LSB)     | \
  (ATON_CLKCTRL_BGATES_DECUN0_DT       << ATON_CLKCTRL_BGATES_DECUN0_LSB)       | \
  (ATON_CLKCTRL_BGATES_DECUN1_DT       << ATON_CLKCTRL_BGATES_DECUN1_LSB)       | \
  (ATON_CLKCTRL_BGATES_ACTIV0_DT       << ATON_CLKCTRL_BGATES_ACTIV0_LSB)       | \
  (ATON_CLKCTRL_BGATES_ACTIV1_DT       << ATON_CLKCTRL_BGATES_ACTIV1_LSB)       | \
  (ATON_CLKCTRL_BGATES_ARITH0_DT       << ATON_CLKCTRL_BGATES_ARITH0_LSB)       | \
  (ATON_CLKCTRL_BGATES_ARITH1_DT       << ATON_CLKCTRL_BGATES_ARITH1_LSB)       | \
  (ATON_CLKCTRL_BGATES_ARITH2_DT       << ATON_CLKCTRL_BGATES_ARITH2_LSB)       | \
  (ATON_CLKCTRL_BGATES_ARITH3_DT       << ATON_CLKCTRL_BGATES_ARITH3_LSB)       | \
  (ATON_CLKCTRL_BGATES_POOL0_DT        << ATON_CLKCTRL_BGATES_POOL0_LSB)        | \
  (ATON_CLKCTRL_BGATES_POOL1_DT        << ATON_CLKCTRL_BGATES_POOL1_LSB)        | \
  (ATON_CLKCTRL_BGATES_RECBUF0_DT      << ATON_CLKCTRL_BGATES_RECBUF0_LSB)      | \
  (ATON_CLKCTRL_BGATES_EPOCHCTRL0_DT   << ATON_CLKCTRL_BGATES_EPOCHCTRL0_LSB)   | \
  (ATON_CLKCTRL_BGATES_DEBUG_TRACE0_DT << ATON_CLKCTRL_BGATES_DEBUG_TRACE0_LSB)



/** Description of the BGATES register. */
#define ATON_CLKCTRL_BGATES_DESC  "Clock enable bits register for B clocks"

/** Address of the BGATES register of one of the CLKCTRL Units. */
#define ATON_CLKCTRL_BGATES_ADDR(UNIT)  (ATON_CLKCTRL_BASE(UNIT) + ATON_CLKCTRL_BGATES_OFFSET)

/** Get the content of the BGATES register of one of the CLKCTRL Units. */
#define ATON_CLKCTRL_BGATES_GET(UNIT)  (*((volatile uint32_t *)(uintptr_t)ATON_CLKCTRL_BGATES_ADDR(UNIT)))

/** Set the content of the BGATES register of one of the CLKCTRL Units. */
#define ATON_CLKCTRL_BGATES_SET(UNIT, DATA)  do { *((volatile uint32_t *)(uintptr_t)ATON_CLKCTRL_BGATES_ADDR(UNIT)) = (DATA); } while (0);


/**
 * Get the description of BGATES register.
 *
 * \return the description of BGATES register
 */

static inline const int8_t *ATON_CLKCTRL_BGATES_GetDesc(void)
{
  return (const int8_t *)ATON_CLKCTRL_BGATES_DESC;
}


/**
 * Get the offset of the BGATES register.
 *
 * \return the offset of BGATES register
 */

static inline uint32_t ATON_CLKCTRL_BGATES_GetOffset(void)
{
  return ATON_CLKCTRL_BGATES_OFFSET;
}


/**
 * Get the address of the BGATES register.
 *
 * \param[in] instance is the index of the Unit (among the CLKCTRL Units) containing the BGATES register whose address must be returned
 *                     (it must be <em>instance \< 1<\em>)
 *
 * \return the address of BGATES register belonging to Unit having index \e instance among the CLKCTRL Units
 */

static inline uint32_t ATON_CLKCTRL_BGATES_GetAddr(uint32_t instance)
{
  return ATON_CLKCTRL_BGATES_ADDR(instance);
}


/**
 * Read the content of the BGATES register.
 *
 * \param[in] instance is the index of the Unit (among the CLKCTRL Units) containing the BGATES register whose content must be retrieved
 *                     (it must be <em>instance \< 1<\em>)
 *
 * \return the content of BGATES register belonging to Unit having index \e instance among the CLKCTRL Units
 */

static inline uint32_t ATON_CLKCTRL_BGATES_Get(uint32_t instance)
{
  return ATON_CLKCTRL_BGATES_GET(instance);
}


/**
 * Write the content of the BGATES register.
 *
 * \param[in] instance is the index of the Unit (among the CLKCTRL Units) containing the BGATES register whose content must be modified
 *                     (it must be <em>instance \< 1<\em>)
 * \param[in] data     is 32-bit value that must be written to the register
 */

static inline void ATON_CLKCTRL_BGATES_Set(uint32_t instance, uint32_t data)
{
  ATON_CLKCTRL_BGATES_SET(instance, data);
}


/* ---------------------------------------------------------- STRENG0 field of the BGATES register ---------------------------------------------------------- */

/** Description of the STRENG0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG0_DESC  "Enable clock of Stream Engine 0"

/** Offset of the STRENG0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG0_LSB  0UL

/** Size in bits of the STRENG0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG0_W  (1UL)

/** Mask for retrieving the STRENG0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG0_MASK  ATON_FIELD_MASK(0UL, 1UL)

/** Reset value of the STRENG0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG0_DT  0x0UL

/** Access rights of the STRENG0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG0_AC  "RW"

/** Check whether access to the STRENG0 field of the BGATES register is secured or not. */
#define ATON_CLKCTRL_BGATES_STRENG0_S  0

/** Check whether access to the STRENG0 field of the BGATES register is privileged or not. */
#define ATON_CLKCTRL_BGATES_STRENG0_P  0

/** Read the content of the STRENG0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_GET_STRENG0(REG)  ATON_GET_FIELD(REG, ATON_CLKCTRL_BGATES_STRENG0_LSB, ATON_CLKCTRL_BGATES_STRENG0_W)

/** Modify the content of the STRENG0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_SET_STRENG0(REG, DATA)  ATON_SET_FIELD(REG, ATON_CLKCTRL_BGATES_STRENG0_LSB, ATON_CLKCTRL_BGATES_STRENG0_W, DATA)


/**
 * Get the description of the STRENG0 field of BGATES register.
 *
 * \return the description of the STRENG0 field of BGATES register
 */

static inline const int8_t *ATON_CLKCTRL_BGATES_STRENG0_GetdDesc(void)
{
  return (const int8_t *)ATON_CLKCTRL_BGATES_STRENG0_DESC;
}


/**
 * Read the content of the STRENG0 field of the BGATES register.
 *
 * \param[in] reg is the value of the BGATES register
 *
 * \return the content of the STRENG0 field belonging to BGATES register
 */

static inline uint32_t ATON_CLKCTRL_BGATES_Get_STRENG0(uint32_t reg)
{
  return ATON_CLKCTRL_BGATES_GET_STRENG0(reg);
}


/**
 * Write the content of the STRENG0 field of the BGATES register.
 *
 * \param[in] reg  is the value of the BGATES register
 * \param[in] data is 1-bit value that must be written to the field
 *
 * \return the new content of the STRENG0 field belonging to BGATES register
 */

static inline uint32_t ATON_CLKCTRL_BGATES_Set_STRENG0(uint32_t reg, uint32_t data)
{
  return ATON_CLKCTRL_BGATES_SET_STRENG0(reg, data);
}


/* ---------------------------------------------------------- STRENG1 field of the BGATES register ---------------------------------------------------------- */

/** Description of the STRENG1 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG1_DESC  "Enable clock of Stream Engine 1"

/** Offset of the STRENG1 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG1_LSB  1UL

/** Size in bits of the STRENG1 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG1_W  (1UL)

/** Mask for retrieving the STRENG1 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG1_MASK  ATON_FIELD_MASK(1UL, 1UL)

/** Reset value of the STRENG1 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG1_DT  0x0UL

/** Access rights of the STRENG1 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG1_AC  "RW"

/** Check whether access to the STRENG1 field of the BGATES register is secured or not. */
#define ATON_CLKCTRL_BGATES_STRENG1_S  0

/** Check whether access to the STRENG1 field of the BGATES register is privileged or not. */
#define ATON_CLKCTRL_BGATES_STRENG1_P  0

/** Read the content of the STRENG1 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_GET_STRENG1(REG)  ATON_GET_FIELD(REG, ATON_CLKCTRL_BGATES_STRENG1_LSB, ATON_CLKCTRL_BGATES_STRENG1_W)

/** Modify the content of the STRENG1 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_SET_STRENG1(REG, DATA)  ATON_SET_FIELD(REG, ATON_CLKCTRL_BGATES_STRENG1_LSB, ATON_CLKCTRL_BGATES_STRENG1_W, DATA)


/**
 * Get the description of the STRENG1 field of BGATES register.
 *
 * \return the description of the STRENG1 field of BGATES register
 */

static inline const int8_t *ATON_CLKCTRL_BGATES_STRENG1_GetdDesc(void)
{
  return (const int8_t *)ATON_CLKCTRL_BGATES_STRENG1_DESC;
}


/**
 * Read the content of the STRENG1 field of the BGATES register.
 *
 * \param[in] reg is the value of the BGATES register
 *
 * \return the content of the STRENG1 field belonging to BGATES register
 */

static inline uint32_t ATON_CLKCTRL_BGATES_Get_STRENG1(uint32_t reg)
{
  return ATON_CLKCTRL_BGATES_GET_STRENG1(reg);
}


/**
 * Write the content of the STRENG1 field of the BGATES register.
 *
 * \param[in] reg  is the value of the BGATES register
 * \param[in] data is 1-bit value that must be written to the field
 *
 * \return the new content of the STRENG1 field belonging to BGATES register
 */

static inline uint32_t ATON_CLKCTRL_BGATES_Set_STRENG1(uint32_t reg, uint32_t data)
{
  return ATON_CLKCTRL_BGATES_SET_STRENG1(reg, data);
}


/* ---------------------------------------------------------- STRENG2 field of the BGATES register ---------------------------------------------------------- */

/** Description of the STRENG2 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG2_DESC  "Enable clock of Stream Engine 2"

/** Offset of the STRENG2 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG2_LSB  2UL

/** Size in bits of the STRENG2 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG2_W  (1UL)

/** Mask for retrieving the STRENG2 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG2_MASK  ATON_FIELD_MASK(2UL, 1UL)

/** Reset value of the STRENG2 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG2_DT  0x0UL

/** Access rights of the STRENG2 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG2_AC  "RW"

/** Check whether access to the STRENG2 field of the BGATES register is secured or not. */
#define ATON_CLKCTRL_BGATES_STRENG2_S  0

/** Check whether access to the STRENG2 field of the BGATES register is privileged or not. */
#define ATON_CLKCTRL_BGATES_STRENG2_P  0

/** Read the content of the STRENG2 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_GET_STRENG2(REG)  ATON_GET_FIELD(REG, ATON_CLKCTRL_BGATES_STRENG2_LSB, ATON_CLKCTRL_BGATES_STRENG2_W)

/** Modify the content of the STRENG2 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_SET_STRENG2(REG, DATA)  ATON_SET_FIELD(REG, ATON_CLKCTRL_BGATES_STRENG2_LSB, ATON_CLKCTRL_BGATES_STRENG2_W, DATA)


/**
 * Get the description of the STRENG2 field of BGATES register.
 *
 * \return the description of the STRENG2 field of BGATES register
 */

static inline const int8_t *ATON_CLKCTRL_BGATES_STRENG2_GetdDesc(void)
{
  return (const int8_t *)ATON_CLKCTRL_BGATES_STRENG2_DESC;
}


/**
 * Read the content of the STRENG2 field of the BGATES register.
 *
 * \param[in] reg is the value of the BGATES register
 *
 * \return the content of the STRENG2 field belonging to BGATES register
 */

static inline uint32_t ATON_CLKCTRL_BGATES_Get_STRENG2(uint32_t reg)
{
  return ATON_CLKCTRL_BGATES_GET_STRENG2(reg);
}


/**
 * Write the content of the STRENG2 field of the BGATES register.
 *
 * \param[in] reg  is the value of the BGATES register
 * \param[in] data is 1-bit value that must be written to the field
 *
 * \return the new content of the STRENG2 field belonging to BGATES register
 */

static inline uint32_t ATON_CLKCTRL_BGATES_Set_STRENG2(uint32_t reg, uint32_t data)
{
  return ATON_CLKCTRL_BGATES_SET_STRENG2(reg, data);
}


/* ---------------------------------------------------------- STRENG3 field of the BGATES register ---------------------------------------------------------- */

/** Description of the STRENG3 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG3_DESC  "Enable clock of Stream Engine 3"

/** Offset of the STRENG3 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG3_LSB  3UL

/** Size in bits of the STRENG3 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG3_W  (1UL)

/** Mask for retrieving the STRENG3 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG3_MASK  ATON_FIELD_MASK(3UL, 1UL)

/** Reset value of the STRENG3 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG3_DT  0x0UL

/** Access rights of the STRENG3 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG3_AC  "RW"

/** Check whether access to the STRENG3 field of the BGATES register is secured or not. */
#define ATON_CLKCTRL_BGATES_STRENG3_S  0

/** Check whether access to the STRENG3 field of the BGATES register is privileged or not. */
#define ATON_CLKCTRL_BGATES_STRENG3_P  0

/** Read the content of the STRENG3 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_GET_STRENG3(REG)  ATON_GET_FIELD(REG, ATON_CLKCTRL_BGATES_STRENG3_LSB, ATON_CLKCTRL_BGATES_STRENG3_W)

/** Modify the content of the STRENG3 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_SET_STRENG3(REG, DATA)  ATON_SET_FIELD(REG, ATON_CLKCTRL_BGATES_STRENG3_LSB, ATON_CLKCTRL_BGATES_STRENG3_W, DATA)


/**
 * Get the description of the STRENG3 field of BGATES register.
 *
 * \return the description of the STRENG3 field of BGATES register
 */

static inline const int8_t *ATON_CLKCTRL_BGATES_STRENG3_GetdDesc(void)
{
  return (const int8_t *)ATON_CLKCTRL_BGATES_STRENG3_DESC;
}


/**
 * Read the content of the STRENG3 field of the BGATES register.
 *
 * \param[in] reg is the value of the BGATES register
 *
 * \return the content of the STRENG3 field belonging to BGATES register
 */

static inline uint32_t ATON_CLKCTRL_BGATES_Get_STRENG3(uint32_t reg)
{
  return ATON_CLKCTRL_BGATES_GET_STRENG3(reg);
}


/**
 * Write the content of the STRENG3 field of the BGATES register.
 *
 * \param[in] reg  is the value of the BGATES register
 * \param[in] data is 1-bit value that must be written to the field
 *
 * \return the new content of the STRENG3 field belonging to BGATES register
 */

static inline uint32_t ATON_CLKCTRL_BGATES_Set_STRENG3(uint32_t reg, uint32_t data)
{
  return ATON_CLKCTRL_BGATES_SET_STRENG3(reg, data);
}


/* ---------------------------------------------------------- STRENG4 field of the BGATES register ---------------------------------------------------------- */

/** Description of the STRENG4 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG4_DESC  "Enable clock of Stream Engine 4"

/** Offset of the STRENG4 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG4_LSB  4UL

/** Size in bits of the STRENG4 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG4_W  (1UL)

/** Mask for retrieving the STRENG4 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG4_MASK  ATON_FIELD_MASK(4UL, 1UL)

/** Reset value of the STRENG4 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG4_DT  0x0UL

/** Access rights of the STRENG4 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG4_AC  "RW"

/** Check whether access to the STRENG4 field of the BGATES register is secured or not. */
#define ATON_CLKCTRL_BGATES_STRENG4_S  0

/** Check whether access to the STRENG4 field of the BGATES register is privileged or not. */
#define ATON_CLKCTRL_BGATES_STRENG4_P  0

/** Read the content of the STRENG4 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_GET_STRENG4(REG)  ATON_GET_FIELD(REG, ATON_CLKCTRL_BGATES_STRENG4_LSB, ATON_CLKCTRL_BGATES_STRENG4_W)

/** Modify the content of the STRENG4 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_SET_STRENG4(REG, DATA)  ATON_SET_FIELD(REG, ATON_CLKCTRL_BGATES_STRENG4_LSB, ATON_CLKCTRL_BGATES_STRENG4_W, DATA)


/**
 * Get the description of the STRENG4 field of BGATES register.
 *
 * \return the description of the STRENG4 field of BGATES register
 */

static inline const int8_t *ATON_CLKCTRL_BGATES_STRENG4_GetdDesc(void)
{
  return (const int8_t *)ATON_CLKCTRL_BGATES_STRENG4_DESC;
}


/**
 * Read the content of the STRENG4 field of the BGATES register.
 *
 * \param[in] reg is the value of the BGATES register
 *
 * \return the content of the STRENG4 field belonging to BGATES register
 */

static inline uint32_t ATON_CLKCTRL_BGATES_Get_STRENG4(uint32_t reg)
{
  return ATON_CLKCTRL_BGATES_GET_STRENG4(reg);
}


/**
 * Write the content of the STRENG4 field of the BGATES register.
 *
 * \param[in] reg  is the value of the BGATES register
 * \param[in] data is 1-bit value that must be written to the field
 *
 * \return the new content of the STRENG4 field belonging to BGATES register
 */

static inline uint32_t ATON_CLKCTRL_BGATES_Set_STRENG4(uint32_t reg, uint32_t data)
{
  return ATON_CLKCTRL_BGATES_SET_STRENG4(reg, data);
}


/* ---------------------------------------------------------- STRENG5 field of the BGATES register ---------------------------------------------------------- */

/** Description of the STRENG5 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG5_DESC  "Enable clock of Stream Engine 5"

/** Offset of the STRENG5 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG5_LSB  5UL

/** Size in bits of the STRENG5 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG5_W  (1UL)

/** Mask for retrieving the STRENG5 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG5_MASK  ATON_FIELD_MASK(5UL, 1UL)

/** Reset value of the STRENG5 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG5_DT  0x0UL

/** Access rights of the STRENG5 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG5_AC  "RW"

/** Check whether access to the STRENG5 field of the BGATES register is secured or not. */
#define ATON_CLKCTRL_BGATES_STRENG5_S  0

/** Check whether access to the STRENG5 field of the BGATES register is privileged or not. */
#define ATON_CLKCTRL_BGATES_STRENG5_P  0

/** Read the content of the STRENG5 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_GET_STRENG5(REG)  ATON_GET_FIELD(REG, ATON_CLKCTRL_BGATES_STRENG5_LSB, ATON_CLKCTRL_BGATES_STRENG5_W)

/** Modify the content of the STRENG5 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_SET_STRENG5(REG, DATA)  ATON_SET_FIELD(REG, ATON_CLKCTRL_BGATES_STRENG5_LSB, ATON_CLKCTRL_BGATES_STRENG5_W, DATA)


/**
 * Get the description of the STRENG5 field of BGATES register.
 *
 * \return the description of the STRENG5 field of BGATES register
 */

static inline const int8_t *ATON_CLKCTRL_BGATES_STRENG5_GetdDesc(void)
{
  return (const int8_t *)ATON_CLKCTRL_BGATES_STRENG5_DESC;
}


/**
 * Read the content of the STRENG5 field of the BGATES register.
 *
 * \param[in] reg is the value of the BGATES register
 *
 * \return the content of the STRENG5 field belonging to BGATES register
 */

static inline uint32_t ATON_CLKCTRL_BGATES_Get_STRENG5(uint32_t reg)
{
  return ATON_CLKCTRL_BGATES_GET_STRENG5(reg);
}


/**
 * Write the content of the STRENG5 field of the BGATES register.
 *
 * \param[in] reg  is the value of the BGATES register
 * \param[in] data is 1-bit value that must be written to the field
 *
 * \return the new content of the STRENG5 field belonging to BGATES register
 */

static inline uint32_t ATON_CLKCTRL_BGATES_Set_STRENG5(uint32_t reg, uint32_t data)
{
  return ATON_CLKCTRL_BGATES_SET_STRENG5(reg, data);
}


/* ---------------------------------------------------------- STRENG6 field of the BGATES register ---------------------------------------------------------- */

/** Description of the STRENG6 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG6_DESC  "Enable clock of Stream Engine 6"

/** Offset of the STRENG6 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG6_LSB  6UL

/** Size in bits of the STRENG6 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG6_W  (1UL)

/** Mask for retrieving the STRENG6 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG6_MASK  ATON_FIELD_MASK(6UL, 1UL)

/** Reset value of the STRENG6 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG6_DT  0x0UL

/** Access rights of the STRENG6 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG6_AC  "RW"

/** Check whether access to the STRENG6 field of the BGATES register is secured or not. */
#define ATON_CLKCTRL_BGATES_STRENG6_S  0

/** Check whether access to the STRENG6 field of the BGATES register is privileged or not. */
#define ATON_CLKCTRL_BGATES_STRENG6_P  0

/** Read the content of the STRENG6 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_GET_STRENG6(REG)  ATON_GET_FIELD(REG, ATON_CLKCTRL_BGATES_STRENG6_LSB, ATON_CLKCTRL_BGATES_STRENG6_W)

/** Modify the content of the STRENG6 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_SET_STRENG6(REG, DATA)  ATON_SET_FIELD(REG, ATON_CLKCTRL_BGATES_STRENG6_LSB, ATON_CLKCTRL_BGATES_STRENG6_W, DATA)


/**
 * Get the description of the STRENG6 field of BGATES register.
 *
 * \return the description of the STRENG6 field of BGATES register
 */

static inline const int8_t *ATON_CLKCTRL_BGATES_STRENG6_GetdDesc(void)
{
  return (const int8_t *)ATON_CLKCTRL_BGATES_STRENG6_DESC;
}


/**
 * Read the content of the STRENG6 field of the BGATES register.
 *
 * \param[in] reg is the value of the BGATES register
 *
 * \return the content of the STRENG6 field belonging to BGATES register
 */

static inline uint32_t ATON_CLKCTRL_BGATES_Get_STRENG6(uint32_t reg)
{
  return ATON_CLKCTRL_BGATES_GET_STRENG6(reg);
}


/**
 * Write the content of the STRENG6 field of the BGATES register.
 *
 * \param[in] reg  is the value of the BGATES register
 * \param[in] data is 1-bit value that must be written to the field
 *
 * \return the new content of the STRENG6 field belonging to BGATES register
 */

static inline uint32_t ATON_CLKCTRL_BGATES_Set_STRENG6(uint32_t reg, uint32_t data)
{
  return ATON_CLKCTRL_BGATES_SET_STRENG6(reg, data);
}


/* ---------------------------------------------------------- STRENG7 field of the BGATES register ---------------------------------------------------------- */

/** Description of the STRENG7 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG7_DESC  "Enable clock of Stream Engine 7"

/** Offset of the STRENG7 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG7_LSB  7UL

/** Size in bits of the STRENG7 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG7_W  (1UL)

/** Mask for retrieving the STRENG7 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG7_MASK  ATON_FIELD_MASK(7UL, 1UL)

/** Reset value of the STRENG7 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG7_DT  0x0UL

/** Access rights of the STRENG7 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG7_AC  "RW"

/** Check whether access to the STRENG7 field of the BGATES register is secured or not. */
#define ATON_CLKCTRL_BGATES_STRENG7_S  0

/** Check whether access to the STRENG7 field of the BGATES register is privileged or not. */
#define ATON_CLKCTRL_BGATES_STRENG7_P  0

/** Read the content of the STRENG7 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_GET_STRENG7(REG)  ATON_GET_FIELD(REG, ATON_CLKCTRL_BGATES_STRENG7_LSB, ATON_CLKCTRL_BGATES_STRENG7_W)

/** Modify the content of the STRENG7 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_SET_STRENG7(REG, DATA)  ATON_SET_FIELD(REG, ATON_CLKCTRL_BGATES_STRENG7_LSB, ATON_CLKCTRL_BGATES_STRENG7_W, DATA)


/**
 * Get the description of the STRENG7 field of BGATES register.
 *
 * \return the description of the STRENG7 field of BGATES register
 */

static inline const int8_t *ATON_CLKCTRL_BGATES_STRENG7_GetdDesc(void)
{
  return (const int8_t *)ATON_CLKCTRL_BGATES_STRENG7_DESC;
}


/**
 * Read the content of the STRENG7 field of the BGATES register.
 *
 * \param[in] reg is the value of the BGATES register
 *
 * \return the content of the STRENG7 field belonging to BGATES register
 */

static inline uint32_t ATON_CLKCTRL_BGATES_Get_STRENG7(uint32_t reg)
{
  return ATON_CLKCTRL_BGATES_GET_STRENG7(reg);
}


/**
 * Write the content of the STRENG7 field of the BGATES register.
 *
 * \param[in] reg  is the value of the BGATES register
 * \param[in] data is 1-bit value that must be written to the field
 *
 * \return the new content of the STRENG7 field belonging to BGATES register
 */

static inline uint32_t ATON_CLKCTRL_BGATES_Set_STRENG7(uint32_t reg, uint32_t data)
{
  return ATON_CLKCTRL_BGATES_SET_STRENG7(reg, data);
}


/* ---------------------------------------------------------- STRENG8 field of the BGATES register ---------------------------------------------------------- */

/** Description of the STRENG8 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG8_DESC  "Enable clock of Stream Engine 8"

/** Offset of the STRENG8 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG8_LSB  8UL

/** Size in bits of the STRENG8 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG8_W  (1UL)

/** Mask for retrieving the STRENG8 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG8_MASK  ATON_FIELD_MASK(8UL, 1UL)

/** Reset value of the STRENG8 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG8_DT  0x0UL

/** Access rights of the STRENG8 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG8_AC  "RW"

/** Check whether access to the STRENG8 field of the BGATES register is secured or not. */
#define ATON_CLKCTRL_BGATES_STRENG8_S  0

/** Check whether access to the STRENG8 field of the BGATES register is privileged or not. */
#define ATON_CLKCTRL_BGATES_STRENG8_P  0

/** Read the content of the STRENG8 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_GET_STRENG8(REG)  ATON_GET_FIELD(REG, ATON_CLKCTRL_BGATES_STRENG8_LSB, ATON_CLKCTRL_BGATES_STRENG8_W)

/** Modify the content of the STRENG8 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_SET_STRENG8(REG, DATA)  ATON_SET_FIELD(REG, ATON_CLKCTRL_BGATES_STRENG8_LSB, ATON_CLKCTRL_BGATES_STRENG8_W, DATA)


/**
 * Get the description of the STRENG8 field of BGATES register.
 *
 * \return the description of the STRENG8 field of BGATES register
 */

static inline const int8_t *ATON_CLKCTRL_BGATES_STRENG8_GetdDesc(void)
{
  return (const int8_t *)ATON_CLKCTRL_BGATES_STRENG8_DESC;
}


/**
 * Read the content of the STRENG8 field of the BGATES register.
 *
 * \param[in] reg is the value of the BGATES register
 *
 * \return the content of the STRENG8 field belonging to BGATES register
 */

static inline uint32_t ATON_CLKCTRL_BGATES_Get_STRENG8(uint32_t reg)
{
  return ATON_CLKCTRL_BGATES_GET_STRENG8(reg);
}


/**
 * Write the content of the STRENG8 field of the BGATES register.
 *
 * \param[in] reg  is the value of the BGATES register
 * \param[in] data is 1-bit value that must be written to the field
 *
 * \return the new content of the STRENG8 field belonging to BGATES register
 */

static inline uint32_t ATON_CLKCTRL_BGATES_Set_STRENG8(uint32_t reg, uint32_t data)
{
  return ATON_CLKCTRL_BGATES_SET_STRENG8(reg, data);
}


/* ---------------------------------------------------------- STRENG9 field of the BGATES register ---------------------------------------------------------- */

/** Description of the STRENG9 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG9_DESC  "Enable clock of Stream Engine 9"

/** Offset of the STRENG9 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG9_LSB  9UL

/** Size in bits of the STRENG9 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG9_W  (1UL)

/** Mask for retrieving the STRENG9 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG9_MASK  ATON_FIELD_MASK(9UL, 1UL)

/** Reset value of the STRENG9 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG9_DT  0x0UL

/** Access rights of the STRENG9 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_STRENG9_AC  "RW"

/** Check whether access to the STRENG9 field of the BGATES register is secured or not. */
#define ATON_CLKCTRL_BGATES_STRENG9_S  0

/** Check whether access to the STRENG9 field of the BGATES register is privileged or not. */
#define ATON_CLKCTRL_BGATES_STRENG9_P  0

/** Read the content of the STRENG9 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_GET_STRENG9(REG)  ATON_GET_FIELD(REG, ATON_CLKCTRL_BGATES_STRENG9_LSB, ATON_CLKCTRL_BGATES_STRENG9_W)

/** Modify the content of the STRENG9 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_SET_STRENG9(REG, DATA)  ATON_SET_FIELD(REG, ATON_CLKCTRL_BGATES_STRENG9_LSB, ATON_CLKCTRL_BGATES_STRENG9_W, DATA)


/**
 * Get the description of the STRENG9 field of BGATES register.
 *
 * \return the description of the STRENG9 field of BGATES register
 */

static inline const int8_t *ATON_CLKCTRL_BGATES_STRENG9_GetdDesc(void)
{
  return (const int8_t *)ATON_CLKCTRL_BGATES_STRENG9_DESC;
}


/**
 * Read the content of the STRENG9 field of the BGATES register.
 *
 * \param[in] reg is the value of the BGATES register
 *
 * \return the content of the STRENG9 field belonging to BGATES register
 */

static inline uint32_t ATON_CLKCTRL_BGATES_Get_STRENG9(uint32_t reg)
{
  return ATON_CLKCTRL_BGATES_GET_STRENG9(reg);
}


/**
 * Write the content of the STRENG9 field of the BGATES register.
 *
 * \param[in] reg  is the value of the BGATES register
 * \param[in] data is 1-bit value that must be written to the field
 *
 * \return the new content of the STRENG9 field belonging to BGATES register
 */

static inline uint32_t ATON_CLKCTRL_BGATES_Set_STRENG9(uint32_t reg, uint32_t data)
{
  return ATON_CLKCTRL_BGATES_SET_STRENG9(reg, data);
}


/* --------------------------------------------------------- CONVACC0 field of the BGATES register ---------------------------------------------------------- */

/** Description of the CONVACC0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_CONVACC0_DESC  "Enable clock of Convolutional Accelerator 0"

/** Offset of the CONVACC0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_CONVACC0_LSB  10UL

/** Size in bits of the CONVACC0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_CONVACC0_W  (1UL)

/** Mask for retrieving the CONVACC0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_CONVACC0_MASK  ATON_FIELD_MASK(10UL, 1UL)

/** Reset value of the CONVACC0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_CONVACC0_DT  0x0UL

/** Access rights of the CONVACC0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_CONVACC0_AC  "RW"

/** Check whether access to the CONVACC0 field of the BGATES register is secured or not. */
#define ATON_CLKCTRL_BGATES_CONVACC0_S  0

/** Check whether access to the CONVACC0 field of the BGATES register is privileged or not. */
#define ATON_CLKCTRL_BGATES_CONVACC0_P  0

/** Read the content of the CONVACC0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_GET_CONVACC0(REG)  ATON_GET_FIELD(REG, ATON_CLKCTRL_BGATES_CONVACC0_LSB, ATON_CLKCTRL_BGATES_CONVACC0_W)

/** Modify the content of the CONVACC0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_SET_CONVACC0(REG, DATA)  ATON_SET_FIELD(REG, ATON_CLKCTRL_BGATES_CONVACC0_LSB, ATON_CLKCTRL_BGATES_CONVACC0_W, DATA)


/**
 * Get the description of the CONVACC0 field of BGATES register.
 *
 * \return the description of the CONVACC0 field of BGATES register
 */

static inline const int8_t *ATON_CLKCTRL_BGATES_CONVACC0_GetdDesc(void)
{
  return (const int8_t *)ATON_CLKCTRL_BGATES_CONVACC0_DESC;
}


/**
 * Read the content of the CONVACC0 field of the BGATES register.
 *
 * \param[in] reg is the value of the BGATES register
 *
 * \return the content of the CONVACC0 field belonging to BGATES register
 */

static inline uint32_t ATON_CLKCTRL_BGATES_Get_CONVACC0(uint32_t reg)
{
  return ATON_CLKCTRL_BGATES_GET_CONVACC0(reg);
}


/**
 * Write the content of the CONVACC0 field of the BGATES register.
 *
 * \param[in] reg  is the value of the BGATES register
 * \param[in] data is 1-bit value that must be written to the field
 *
 * \return the new content of the CONVACC0 field belonging to BGATES register
 */

static inline uint32_t ATON_CLKCTRL_BGATES_Set_CONVACC0(uint32_t reg, uint32_t data)
{
  return ATON_CLKCTRL_BGATES_SET_CONVACC0(reg, data);
}


/* --------------------------------------------------------- CONVACC1 field of the BGATES register ---------------------------------------------------------- */

/** Description of the CONVACC1 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_CONVACC1_DESC  "Enable clock of Convolutional Accelerator 1"

/** Offset of the CONVACC1 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_CONVACC1_LSB  11UL

/** Size in bits of the CONVACC1 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_CONVACC1_W  (1UL)

/** Mask for retrieving the CONVACC1 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_CONVACC1_MASK  ATON_FIELD_MASK(11UL, 1UL)

/** Reset value of the CONVACC1 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_CONVACC1_DT  0x0UL

/** Access rights of the CONVACC1 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_CONVACC1_AC  "RW"

/** Check whether access to the CONVACC1 field of the BGATES register is secured or not. */
#define ATON_CLKCTRL_BGATES_CONVACC1_S  0

/** Check whether access to the CONVACC1 field of the BGATES register is privileged or not. */
#define ATON_CLKCTRL_BGATES_CONVACC1_P  0

/** Read the content of the CONVACC1 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_GET_CONVACC1(REG)  ATON_GET_FIELD(REG, ATON_CLKCTRL_BGATES_CONVACC1_LSB, ATON_CLKCTRL_BGATES_CONVACC1_W)

/** Modify the content of the CONVACC1 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_SET_CONVACC1(REG, DATA)  ATON_SET_FIELD(REG, ATON_CLKCTRL_BGATES_CONVACC1_LSB, ATON_CLKCTRL_BGATES_CONVACC1_W, DATA)


/**
 * Get the description of the CONVACC1 field of BGATES register.
 *
 * \return the description of the CONVACC1 field of BGATES register
 */

static inline const int8_t *ATON_CLKCTRL_BGATES_CONVACC1_GetdDesc(void)
{
  return (const int8_t *)ATON_CLKCTRL_BGATES_CONVACC1_DESC;
}


/**
 * Read the content of the CONVACC1 field of the BGATES register.
 *
 * \param[in] reg is the value of the BGATES register
 *
 * \return the content of the CONVACC1 field belonging to BGATES register
 */

static inline uint32_t ATON_CLKCTRL_BGATES_Get_CONVACC1(uint32_t reg)
{
  return ATON_CLKCTRL_BGATES_GET_CONVACC1(reg);
}


/**
 * Write the content of the CONVACC1 field of the BGATES register.
 *
 * \param[in] reg  is the value of the BGATES register
 * \param[in] data is 1-bit value that must be written to the field
 *
 * \return the new content of the CONVACC1 field belonging to BGATES register
 */

static inline uint32_t ATON_CLKCTRL_BGATES_Set_CONVACC1(uint32_t reg, uint32_t data)
{
  return ATON_CLKCTRL_BGATES_SET_CONVACC1(reg, data);
}


/* --------------------------------------------------------- CONVACC2 field of the BGATES register ---------------------------------------------------------- */

/** Description of the CONVACC2 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_CONVACC2_DESC  "Enable clock of Convolutional Accelerator 2"

/** Offset of the CONVACC2 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_CONVACC2_LSB  12UL

/** Size in bits of the CONVACC2 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_CONVACC2_W  (1UL)

/** Mask for retrieving the CONVACC2 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_CONVACC2_MASK  ATON_FIELD_MASK(12UL, 1UL)

/** Reset value of the CONVACC2 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_CONVACC2_DT  0x0UL

/** Access rights of the CONVACC2 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_CONVACC2_AC  "RW"

/** Check whether access to the CONVACC2 field of the BGATES register is secured or not. */
#define ATON_CLKCTRL_BGATES_CONVACC2_S  0

/** Check whether access to the CONVACC2 field of the BGATES register is privileged or not. */
#define ATON_CLKCTRL_BGATES_CONVACC2_P  0

/** Read the content of the CONVACC2 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_GET_CONVACC2(REG)  ATON_GET_FIELD(REG, ATON_CLKCTRL_BGATES_CONVACC2_LSB, ATON_CLKCTRL_BGATES_CONVACC2_W)

/** Modify the content of the CONVACC2 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_SET_CONVACC2(REG, DATA)  ATON_SET_FIELD(REG, ATON_CLKCTRL_BGATES_CONVACC2_LSB, ATON_CLKCTRL_BGATES_CONVACC2_W, DATA)


/**
 * Get the description of the CONVACC2 field of BGATES register.
 *
 * \return the description of the CONVACC2 field of BGATES register
 */

static inline const int8_t *ATON_CLKCTRL_BGATES_CONVACC2_GetdDesc(void)
{
  return (const int8_t *)ATON_CLKCTRL_BGATES_CONVACC2_DESC;
}


/**
 * Read the content of the CONVACC2 field of the BGATES register.
 *
 * \param[in] reg is the value of the BGATES register
 *
 * \return the content of the CONVACC2 field belonging to BGATES register
 */

static inline uint32_t ATON_CLKCTRL_BGATES_Get_CONVACC2(uint32_t reg)
{
  return ATON_CLKCTRL_BGATES_GET_CONVACC2(reg);
}


/**
 * Write the content of the CONVACC2 field of the BGATES register.
 *
 * \param[in] reg  is the value of the BGATES register
 * \param[in] data is 1-bit value that must be written to the field
 *
 * \return the new content of the CONVACC2 field belonging to BGATES register
 */

static inline uint32_t ATON_CLKCTRL_BGATES_Set_CONVACC2(uint32_t reg, uint32_t data)
{
  return ATON_CLKCTRL_BGATES_SET_CONVACC2(reg, data);
}


/* --------------------------------------------------------- CONVACC3 field of the BGATES register ---------------------------------------------------------- */

/** Description of the CONVACC3 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_CONVACC3_DESC  "Enable clock of Convolutional Accelerator 3"

/** Offset of the CONVACC3 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_CONVACC3_LSB  13UL

/** Size in bits of the CONVACC3 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_CONVACC3_W  (1UL)

/** Mask for retrieving the CONVACC3 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_CONVACC3_MASK  ATON_FIELD_MASK(13UL, 1UL)

/** Reset value of the CONVACC3 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_CONVACC3_DT  0x0UL

/** Access rights of the CONVACC3 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_CONVACC3_AC  "RW"

/** Check whether access to the CONVACC3 field of the BGATES register is secured or not. */
#define ATON_CLKCTRL_BGATES_CONVACC3_S  0

/** Check whether access to the CONVACC3 field of the BGATES register is privileged or not. */
#define ATON_CLKCTRL_BGATES_CONVACC3_P  0

/** Read the content of the CONVACC3 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_GET_CONVACC3(REG)  ATON_GET_FIELD(REG, ATON_CLKCTRL_BGATES_CONVACC3_LSB, ATON_CLKCTRL_BGATES_CONVACC3_W)

/** Modify the content of the CONVACC3 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_SET_CONVACC3(REG, DATA)  ATON_SET_FIELD(REG, ATON_CLKCTRL_BGATES_CONVACC3_LSB, ATON_CLKCTRL_BGATES_CONVACC3_W, DATA)


/**
 * Get the description of the CONVACC3 field of BGATES register.
 *
 * \return the description of the CONVACC3 field of BGATES register
 */

static inline const int8_t *ATON_CLKCTRL_BGATES_CONVACC3_GetdDesc(void)
{
  return (const int8_t *)ATON_CLKCTRL_BGATES_CONVACC3_DESC;
}


/**
 * Read the content of the CONVACC3 field of the BGATES register.
 *
 * \param[in] reg is the value of the BGATES register
 *
 * \return the content of the CONVACC3 field belonging to BGATES register
 */

static inline uint32_t ATON_CLKCTRL_BGATES_Get_CONVACC3(uint32_t reg)
{
  return ATON_CLKCTRL_BGATES_GET_CONVACC3(reg);
}


/**
 * Write the content of the CONVACC3 field of the BGATES register.
 *
 * \param[in] reg  is the value of the BGATES register
 * \param[in] data is 1-bit value that must be written to the field
 *
 * \return the new content of the CONVACC3 field belonging to BGATES register
 */

static inline uint32_t ATON_CLKCTRL_BGATES_Set_CONVACC3(uint32_t reg, uint32_t data)
{
  return ATON_CLKCTRL_BGATES_SET_CONVACC3(reg, data);
}


/* ---------------------------------------------------------- DECUN0 field of the BGATES register ----------------------------------------------------------- */

/** Description of the DECUN0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_DECUN0_DESC  "Enable clock of Decompression Unit 0"

/** Offset of the DECUN0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_DECUN0_LSB  14UL

/** Size in bits of the DECUN0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_DECUN0_W  (1UL)

/** Mask for retrieving the DECUN0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_DECUN0_MASK  ATON_FIELD_MASK(14UL, 1UL)

/** Reset value of the DECUN0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_DECUN0_DT  0x0UL

/** Access rights of the DECUN0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_DECUN0_AC  "RW"

/** Check whether access to the DECUN0 field of the BGATES register is secured or not. */
#define ATON_CLKCTRL_BGATES_DECUN0_S  0

/** Check whether access to the DECUN0 field of the BGATES register is privileged or not. */
#define ATON_CLKCTRL_BGATES_DECUN0_P  0

/** Read the content of the DECUN0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_GET_DECUN0(REG)  ATON_GET_FIELD(REG, ATON_CLKCTRL_BGATES_DECUN0_LSB, ATON_CLKCTRL_BGATES_DECUN0_W)

/** Modify the content of the DECUN0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_SET_DECUN0(REG, DATA)  ATON_SET_FIELD(REG, ATON_CLKCTRL_BGATES_DECUN0_LSB, ATON_CLKCTRL_BGATES_DECUN0_W, DATA)


/**
 * Get the description of the DECUN0 field of BGATES register.
 *
 * \return the description of the DECUN0 field of BGATES register
 */

static inline const int8_t *ATON_CLKCTRL_BGATES_DECUN0_GetdDesc(void)
{
  return (const int8_t *)ATON_CLKCTRL_BGATES_DECUN0_DESC;
}


/**
 * Read the content of the DECUN0 field of the BGATES register.
 *
 * \param[in] reg is the value of the BGATES register
 *
 * \return the content of the DECUN0 field belonging to BGATES register
 */

static inline uint32_t ATON_CLKCTRL_BGATES_Get_DECUN0(uint32_t reg)
{
  return ATON_CLKCTRL_BGATES_GET_DECUN0(reg);
}


/**
 * Write the content of the DECUN0 field of the BGATES register.
 *
 * \param[in] reg  is the value of the BGATES register
 * \param[in] data is 1-bit value that must be written to the field
 *
 * \return the new content of the DECUN0 field belonging to BGATES register
 */

static inline uint32_t ATON_CLKCTRL_BGATES_Set_DECUN0(uint32_t reg, uint32_t data)
{
  return ATON_CLKCTRL_BGATES_SET_DECUN0(reg, data);
}


/* ---------------------------------------------------------- DECUN1 field of the BGATES register ----------------------------------------------------------- */

/** Description of the DECUN1 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_DECUN1_DESC  "Enable clock of Decompression Unit 1"

/** Offset of the DECUN1 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_DECUN1_LSB  15UL

/** Size in bits of the DECUN1 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_DECUN1_W  (1UL)

/** Mask for retrieving the DECUN1 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_DECUN1_MASK  ATON_FIELD_MASK(15UL, 1UL)

/** Reset value of the DECUN1 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_DECUN1_DT  0x0UL

/** Access rights of the DECUN1 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_DECUN1_AC  "RW"

/** Check whether access to the DECUN1 field of the BGATES register is secured or not. */
#define ATON_CLKCTRL_BGATES_DECUN1_S  0

/** Check whether access to the DECUN1 field of the BGATES register is privileged or not. */
#define ATON_CLKCTRL_BGATES_DECUN1_P  0

/** Read the content of the DECUN1 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_GET_DECUN1(REG)  ATON_GET_FIELD(REG, ATON_CLKCTRL_BGATES_DECUN1_LSB, ATON_CLKCTRL_BGATES_DECUN1_W)

/** Modify the content of the DECUN1 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_SET_DECUN1(REG, DATA)  ATON_SET_FIELD(REG, ATON_CLKCTRL_BGATES_DECUN1_LSB, ATON_CLKCTRL_BGATES_DECUN1_W, DATA)


/**
 * Get the description of the DECUN1 field of BGATES register.
 *
 * \return the description of the DECUN1 field of BGATES register
 */

static inline const int8_t *ATON_CLKCTRL_BGATES_DECUN1_GetdDesc(void)
{
  return (const int8_t *)ATON_CLKCTRL_BGATES_DECUN1_DESC;
}


/**
 * Read the content of the DECUN1 field of the BGATES register.
 *
 * \param[in] reg is the value of the BGATES register
 *
 * \return the content of the DECUN1 field belonging to BGATES register
 */

static inline uint32_t ATON_CLKCTRL_BGATES_Get_DECUN1(uint32_t reg)
{
  return ATON_CLKCTRL_BGATES_GET_DECUN1(reg);
}


/**
 * Write the content of the DECUN1 field of the BGATES register.
 *
 * \param[in] reg  is the value of the BGATES register
 * \param[in] data is 1-bit value that must be written to the field
 *
 * \return the new content of the DECUN1 field belonging to BGATES register
 */

static inline uint32_t ATON_CLKCTRL_BGATES_Set_DECUN1(uint32_t reg, uint32_t data)
{
  return ATON_CLKCTRL_BGATES_SET_DECUN1(reg, data);
}


/* ---------------------------------------------------------- ACTIV0 field of the BGATES register ----------------------------------------------------------- */

/** Description of the ACTIV0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_ACTIV0_DESC  "Enable clock of Activation Accelerator 0"

/** Offset of the ACTIV0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_ACTIV0_LSB  16UL

/** Size in bits of the ACTIV0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_ACTIV0_W  (1UL)

/** Mask for retrieving the ACTIV0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_ACTIV0_MASK  ATON_FIELD_MASK(16UL, 1UL)

/** Reset value of the ACTIV0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_ACTIV0_DT  0x0UL

/** Access rights of the ACTIV0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_ACTIV0_AC  "RW"

/** Check whether access to the ACTIV0 field of the BGATES register is secured or not. */
#define ATON_CLKCTRL_BGATES_ACTIV0_S  0

/** Check whether access to the ACTIV0 field of the BGATES register is privileged or not. */
#define ATON_CLKCTRL_BGATES_ACTIV0_P  0

/** Read the content of the ACTIV0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_GET_ACTIV0(REG)  ATON_GET_FIELD(REG, ATON_CLKCTRL_BGATES_ACTIV0_LSB, ATON_CLKCTRL_BGATES_ACTIV0_W)

/** Modify the content of the ACTIV0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_SET_ACTIV0(REG, DATA)  ATON_SET_FIELD(REG, ATON_CLKCTRL_BGATES_ACTIV0_LSB, ATON_CLKCTRL_BGATES_ACTIV0_W, DATA)


/**
 * Get the description of the ACTIV0 field of BGATES register.
 *
 * \return the description of the ACTIV0 field of BGATES register
 */

static inline const int8_t *ATON_CLKCTRL_BGATES_ACTIV0_GetdDesc(void)
{
  return (const int8_t *)ATON_CLKCTRL_BGATES_ACTIV0_DESC;
}


/**
 * Read the content of the ACTIV0 field of the BGATES register.
 *
 * \param[in] reg is the value of the BGATES register
 *
 * \return the content of the ACTIV0 field belonging to BGATES register
 */

static inline uint32_t ATON_CLKCTRL_BGATES_Get_ACTIV0(uint32_t reg)
{
  return ATON_CLKCTRL_BGATES_GET_ACTIV0(reg);
}


/**
 * Write the content of the ACTIV0 field of the BGATES register.
 *
 * \param[in] reg  is the value of the BGATES register
 * \param[in] data is 1-bit value that must be written to the field
 *
 * \return the new content of the ACTIV0 field belonging to BGATES register
 */

static inline uint32_t ATON_CLKCTRL_BGATES_Set_ACTIV0(uint32_t reg, uint32_t data)
{
  return ATON_CLKCTRL_BGATES_SET_ACTIV0(reg, data);
}


/* ---------------------------------------------------------- ACTIV1 field of the BGATES register ----------------------------------------------------------- */

/** Description of the ACTIV1 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_ACTIV1_DESC  "Enable clock of Activation Accelerator 1"

/** Offset of the ACTIV1 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_ACTIV1_LSB  17UL

/** Size in bits of the ACTIV1 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_ACTIV1_W  (1UL)

/** Mask for retrieving the ACTIV1 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_ACTIV1_MASK  ATON_FIELD_MASK(17UL, 1UL)

/** Reset value of the ACTIV1 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_ACTIV1_DT  0x0UL

/** Access rights of the ACTIV1 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_ACTIV1_AC  "RW"

/** Check whether access to the ACTIV1 field of the BGATES register is secured or not. */
#define ATON_CLKCTRL_BGATES_ACTIV1_S  0

/** Check whether access to the ACTIV1 field of the BGATES register is privileged or not. */
#define ATON_CLKCTRL_BGATES_ACTIV1_P  0

/** Read the content of the ACTIV1 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_GET_ACTIV1(REG)  ATON_GET_FIELD(REG, ATON_CLKCTRL_BGATES_ACTIV1_LSB, ATON_CLKCTRL_BGATES_ACTIV1_W)

/** Modify the content of the ACTIV1 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_SET_ACTIV1(REG, DATA)  ATON_SET_FIELD(REG, ATON_CLKCTRL_BGATES_ACTIV1_LSB, ATON_CLKCTRL_BGATES_ACTIV1_W, DATA)


/**
 * Get the description of the ACTIV1 field of BGATES register.
 *
 * \return the description of the ACTIV1 field of BGATES register
 */

static inline const int8_t *ATON_CLKCTRL_BGATES_ACTIV1_GetdDesc(void)
{
  return (const int8_t *)ATON_CLKCTRL_BGATES_ACTIV1_DESC;
}


/**
 * Read the content of the ACTIV1 field of the BGATES register.
 *
 * \param[in] reg is the value of the BGATES register
 *
 * \return the content of the ACTIV1 field belonging to BGATES register
 */

static inline uint32_t ATON_CLKCTRL_BGATES_Get_ACTIV1(uint32_t reg)
{
  return ATON_CLKCTRL_BGATES_GET_ACTIV1(reg);
}


/**
 * Write the content of the ACTIV1 field of the BGATES register.
 *
 * \param[in] reg  is the value of the BGATES register
 * \param[in] data is 1-bit value that must be written to the field
 *
 * \return the new content of the ACTIV1 field belonging to BGATES register
 */

static inline uint32_t ATON_CLKCTRL_BGATES_Set_ACTIV1(uint32_t reg, uint32_t data)
{
  return ATON_CLKCTRL_BGATES_SET_ACTIV1(reg, data);
}


/* ---------------------------------------------------------- ARITH0 field of the BGATES register ----------------------------------------------------------- */

/** Description of the ARITH0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_ARITH0_DESC  "Enable clock of Arithmetic Accelerator 0"

/** Offset of the ARITH0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_ARITH0_LSB  18UL

/** Size in bits of the ARITH0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_ARITH0_W  (1UL)

/** Mask for retrieving the ARITH0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_ARITH0_MASK  ATON_FIELD_MASK(18UL, 1UL)

/** Reset value of the ARITH0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_ARITH0_DT  0x0UL

/** Access rights of the ARITH0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_ARITH0_AC  "RW"

/** Check whether access to the ARITH0 field of the BGATES register is secured or not. */
#define ATON_CLKCTRL_BGATES_ARITH0_S  0

/** Check whether access to the ARITH0 field of the BGATES register is privileged or not. */
#define ATON_CLKCTRL_BGATES_ARITH0_P  0

/** Read the content of the ARITH0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_GET_ARITH0(REG)  ATON_GET_FIELD(REG, ATON_CLKCTRL_BGATES_ARITH0_LSB, ATON_CLKCTRL_BGATES_ARITH0_W)

/** Modify the content of the ARITH0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_SET_ARITH0(REG, DATA)  ATON_SET_FIELD(REG, ATON_CLKCTRL_BGATES_ARITH0_LSB, ATON_CLKCTRL_BGATES_ARITH0_W, DATA)


/**
 * Get the description of the ARITH0 field of BGATES register.
 *
 * \return the description of the ARITH0 field of BGATES register
 */

static inline const int8_t *ATON_CLKCTRL_BGATES_ARITH0_GetdDesc(void)
{
  return (const int8_t *)ATON_CLKCTRL_BGATES_ARITH0_DESC;
}


/**
 * Read the content of the ARITH0 field of the BGATES register.
 *
 * \param[in] reg is the value of the BGATES register
 *
 * \return the content of the ARITH0 field belonging to BGATES register
 */

static inline uint32_t ATON_CLKCTRL_BGATES_Get_ARITH0(uint32_t reg)
{
  return ATON_CLKCTRL_BGATES_GET_ARITH0(reg);
}


/**
 * Write the content of the ARITH0 field of the BGATES register.
 *
 * \param[in] reg  is the value of the BGATES register
 * \param[in] data is 1-bit value that must be written to the field
 *
 * \return the new content of the ARITH0 field belonging to BGATES register
 */

static inline uint32_t ATON_CLKCTRL_BGATES_Set_ARITH0(uint32_t reg, uint32_t data)
{
  return ATON_CLKCTRL_BGATES_SET_ARITH0(reg, data);
}


/* ---------------------------------------------------------- ARITH1 field of the BGATES register ----------------------------------------------------------- */

/** Description of the ARITH1 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_ARITH1_DESC  "Enable clock of Arithmetic Accelerator 1"

/** Offset of the ARITH1 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_ARITH1_LSB  19UL

/** Size in bits of the ARITH1 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_ARITH1_W  (1UL)

/** Mask for retrieving the ARITH1 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_ARITH1_MASK  ATON_FIELD_MASK(19UL, 1UL)

/** Reset value of the ARITH1 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_ARITH1_DT  0x0UL

/** Access rights of the ARITH1 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_ARITH1_AC  "RW"

/** Check whether access to the ARITH1 field of the BGATES register is secured or not. */
#define ATON_CLKCTRL_BGATES_ARITH1_S  0

/** Check whether access to the ARITH1 field of the BGATES register is privileged or not. */
#define ATON_CLKCTRL_BGATES_ARITH1_P  0

/** Read the content of the ARITH1 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_GET_ARITH1(REG)  ATON_GET_FIELD(REG, ATON_CLKCTRL_BGATES_ARITH1_LSB, ATON_CLKCTRL_BGATES_ARITH1_W)

/** Modify the content of the ARITH1 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_SET_ARITH1(REG, DATA)  ATON_SET_FIELD(REG, ATON_CLKCTRL_BGATES_ARITH1_LSB, ATON_CLKCTRL_BGATES_ARITH1_W, DATA)


/**
 * Get the description of the ARITH1 field of BGATES register.
 *
 * \return the description of the ARITH1 field of BGATES register
 */

static inline const int8_t *ATON_CLKCTRL_BGATES_ARITH1_GetdDesc(void)
{
  return (const int8_t *)ATON_CLKCTRL_BGATES_ARITH1_DESC;
}


/**
 * Read the content of the ARITH1 field of the BGATES register.
 *
 * \param[in] reg is the value of the BGATES register
 *
 * \return the content of the ARITH1 field belonging to BGATES register
 */

static inline uint32_t ATON_CLKCTRL_BGATES_Get_ARITH1(uint32_t reg)
{
  return ATON_CLKCTRL_BGATES_GET_ARITH1(reg);
}


/**
 * Write the content of the ARITH1 field of the BGATES register.
 *
 * \param[in] reg  is the value of the BGATES register
 * \param[in] data is 1-bit value that must be written to the field
 *
 * \return the new content of the ARITH1 field belonging to BGATES register
 */

static inline uint32_t ATON_CLKCTRL_BGATES_Set_ARITH1(uint32_t reg, uint32_t data)
{
  return ATON_CLKCTRL_BGATES_SET_ARITH1(reg, data);
}


/* ---------------------------------------------------------- ARITH2 field of the BGATES register ----------------------------------------------------------- */

/** Description of the ARITH2 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_ARITH2_DESC  "Enable clock of Arithmetic Accelerator 2"

/** Offset of the ARITH2 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_ARITH2_LSB  20UL

/** Size in bits of the ARITH2 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_ARITH2_W  (1UL)

/** Mask for retrieving the ARITH2 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_ARITH2_MASK  ATON_FIELD_MASK(20UL, 1UL)

/** Reset value of the ARITH2 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_ARITH2_DT  0x0UL

/** Access rights of the ARITH2 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_ARITH2_AC  "RW"

/** Check whether access to the ARITH2 field of the BGATES register is secured or not. */
#define ATON_CLKCTRL_BGATES_ARITH2_S  0

/** Check whether access to the ARITH2 field of the BGATES register is privileged or not. */
#define ATON_CLKCTRL_BGATES_ARITH2_P  0

/** Read the content of the ARITH2 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_GET_ARITH2(REG)  ATON_GET_FIELD(REG, ATON_CLKCTRL_BGATES_ARITH2_LSB, ATON_CLKCTRL_BGATES_ARITH2_W)

/** Modify the content of the ARITH2 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_SET_ARITH2(REG, DATA)  ATON_SET_FIELD(REG, ATON_CLKCTRL_BGATES_ARITH2_LSB, ATON_CLKCTRL_BGATES_ARITH2_W, DATA)


/**
 * Get the description of the ARITH2 field of BGATES register.
 *
 * \return the description of the ARITH2 field of BGATES register
 */

static inline const int8_t *ATON_CLKCTRL_BGATES_ARITH2_GetdDesc(void)
{
  return (const int8_t *)ATON_CLKCTRL_BGATES_ARITH2_DESC;
}


/**
 * Read the content of the ARITH2 field of the BGATES register.
 *
 * \param[in] reg is the value of the BGATES register
 *
 * \return the content of the ARITH2 field belonging to BGATES register
 */

static inline uint32_t ATON_CLKCTRL_BGATES_Get_ARITH2(uint32_t reg)
{
  return ATON_CLKCTRL_BGATES_GET_ARITH2(reg);
}


/**
 * Write the content of the ARITH2 field of the BGATES register.
 *
 * \param[in] reg  is the value of the BGATES register
 * \param[in] data is 1-bit value that must be written to the field
 *
 * \return the new content of the ARITH2 field belonging to BGATES register
 */

static inline uint32_t ATON_CLKCTRL_BGATES_Set_ARITH2(uint32_t reg, uint32_t data)
{
  return ATON_CLKCTRL_BGATES_SET_ARITH2(reg, data);
}


/* ---------------------------------------------------------- ARITH3 field of the BGATES register ----------------------------------------------------------- */

/** Description of the ARITH3 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_ARITH3_DESC  "Enable clock of Arithmetic Accelerator 3"

/** Offset of the ARITH3 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_ARITH3_LSB  21UL

/** Size in bits of the ARITH3 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_ARITH3_W  (1UL)

/** Mask for retrieving the ARITH3 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_ARITH3_MASK  ATON_FIELD_MASK(21UL, 1UL)

/** Reset value of the ARITH3 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_ARITH3_DT  0x0UL

/** Access rights of the ARITH3 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_ARITH3_AC  "RW"

/** Check whether access to the ARITH3 field of the BGATES register is secured or not. */
#define ATON_CLKCTRL_BGATES_ARITH3_S  0

/** Check whether access to the ARITH3 field of the BGATES register is privileged or not. */
#define ATON_CLKCTRL_BGATES_ARITH3_P  0

/** Read the content of the ARITH3 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_GET_ARITH3(REG)  ATON_GET_FIELD(REG, ATON_CLKCTRL_BGATES_ARITH3_LSB, ATON_CLKCTRL_BGATES_ARITH3_W)

/** Modify the content of the ARITH3 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_SET_ARITH3(REG, DATA)  ATON_SET_FIELD(REG, ATON_CLKCTRL_BGATES_ARITH3_LSB, ATON_CLKCTRL_BGATES_ARITH3_W, DATA)


/**
 * Get the description of the ARITH3 field of BGATES register.
 *
 * \return the description of the ARITH3 field of BGATES register
 */

static inline const int8_t *ATON_CLKCTRL_BGATES_ARITH3_GetdDesc(void)
{
  return (const int8_t *)ATON_CLKCTRL_BGATES_ARITH3_DESC;
}


/**
 * Read the content of the ARITH3 field of the BGATES register.
 *
 * \param[in] reg is the value of the BGATES register
 *
 * \return the content of the ARITH3 field belonging to BGATES register
 */

static inline uint32_t ATON_CLKCTRL_BGATES_Get_ARITH3(uint32_t reg)
{
  return ATON_CLKCTRL_BGATES_GET_ARITH3(reg);
}


/**
 * Write the content of the ARITH3 field of the BGATES register.
 *
 * \param[in] reg  is the value of the BGATES register
 * \param[in] data is 1-bit value that must be written to the field
 *
 * \return the new content of the ARITH3 field belonging to BGATES register
 */

static inline uint32_t ATON_CLKCTRL_BGATES_Set_ARITH3(uint32_t reg, uint32_t data)
{
  return ATON_CLKCTRL_BGATES_SET_ARITH3(reg, data);
}


/* ----------------------------------------------------------- POOL0 field of the BGATES register ----------------------------------------------------------- */

/** Description of the POOL0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_POOL0_DESC  "Enable clock of Pooling Accelerator 0"

/** Offset of the POOL0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_POOL0_LSB  22UL

/** Size in bits of the POOL0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_POOL0_W  (1UL)

/** Mask for retrieving the POOL0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_POOL0_MASK  ATON_FIELD_MASK(22UL, 1UL)

/** Reset value of the POOL0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_POOL0_DT  0x0UL

/** Access rights of the POOL0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_POOL0_AC  "RW"

/** Check whether access to the POOL0 field of the BGATES register is secured or not. */
#define ATON_CLKCTRL_BGATES_POOL0_S  0

/** Check whether access to the POOL0 field of the BGATES register is privileged or not. */
#define ATON_CLKCTRL_BGATES_POOL0_P  0

/** Read the content of the POOL0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_GET_POOL0(REG)  ATON_GET_FIELD(REG, ATON_CLKCTRL_BGATES_POOL0_LSB, ATON_CLKCTRL_BGATES_POOL0_W)

/** Modify the content of the POOL0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_SET_POOL0(REG, DATA)  ATON_SET_FIELD(REG, ATON_CLKCTRL_BGATES_POOL0_LSB, ATON_CLKCTRL_BGATES_POOL0_W, DATA)


/**
 * Get the description of the POOL0 field of BGATES register.
 *
 * \return the description of the POOL0 field of BGATES register
 */

static inline const int8_t *ATON_CLKCTRL_BGATES_POOL0_GetdDesc(void)
{
  return (const int8_t *)ATON_CLKCTRL_BGATES_POOL0_DESC;
}


/**
 * Read the content of the POOL0 field of the BGATES register.
 *
 * \param[in] reg is the value of the BGATES register
 *
 * \return the content of the POOL0 field belonging to BGATES register
 */

static inline uint32_t ATON_CLKCTRL_BGATES_Get_POOL0(uint32_t reg)
{
  return ATON_CLKCTRL_BGATES_GET_POOL0(reg);
}


/**
 * Write the content of the POOL0 field of the BGATES register.
 *
 * \param[in] reg  is the value of the BGATES register
 * \param[in] data is 1-bit value that must be written to the field
 *
 * \return the new content of the POOL0 field belonging to BGATES register
 */

static inline uint32_t ATON_CLKCTRL_BGATES_Set_POOL0(uint32_t reg, uint32_t data)
{
  return ATON_CLKCTRL_BGATES_SET_POOL0(reg, data);
}


/* ----------------------------------------------------------- POOL1 field of the BGATES register ----------------------------------------------------------- */

/** Description of the POOL1 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_POOL1_DESC  "Enable clock of Pooling Accelerator 1"

/** Offset of the POOL1 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_POOL1_LSB  23UL

/** Size in bits of the POOL1 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_POOL1_W  (1UL)

/** Mask for retrieving the POOL1 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_POOL1_MASK  ATON_FIELD_MASK(23UL, 1UL)

/** Reset value of the POOL1 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_POOL1_DT  0x0UL

/** Access rights of the POOL1 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_POOL1_AC  "RW"

/** Check whether access to the POOL1 field of the BGATES register is secured or not. */
#define ATON_CLKCTRL_BGATES_POOL1_S  0

/** Check whether access to the POOL1 field of the BGATES register is privileged or not. */
#define ATON_CLKCTRL_BGATES_POOL1_P  0

/** Read the content of the POOL1 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_GET_POOL1(REG)  ATON_GET_FIELD(REG, ATON_CLKCTRL_BGATES_POOL1_LSB, ATON_CLKCTRL_BGATES_POOL1_W)

/** Modify the content of the POOL1 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_SET_POOL1(REG, DATA)  ATON_SET_FIELD(REG, ATON_CLKCTRL_BGATES_POOL1_LSB, ATON_CLKCTRL_BGATES_POOL1_W, DATA)


/**
 * Get the description of the POOL1 field of BGATES register.
 *
 * \return the description of the POOL1 field of BGATES register
 */

static inline const int8_t *ATON_CLKCTRL_BGATES_POOL1_GetdDesc(void)
{
  return (const int8_t *)ATON_CLKCTRL_BGATES_POOL1_DESC;
}


/**
 * Read the content of the POOL1 field of the BGATES register.
 *
 * \param[in] reg is the value of the BGATES register
 *
 * \return the content of the POOL1 field belonging to BGATES register
 */

static inline uint32_t ATON_CLKCTRL_BGATES_Get_POOL1(uint32_t reg)
{
  return ATON_CLKCTRL_BGATES_GET_POOL1(reg);
}


/**
 * Write the content of the POOL1 field of the BGATES register.
 *
 * \param[in] reg  is the value of the BGATES register
 * \param[in] data is 1-bit value that must be written to the field
 *
 * \return the new content of the POOL1 field belonging to BGATES register
 */

static inline uint32_t ATON_CLKCTRL_BGATES_Set_POOL1(uint32_t reg, uint32_t data)
{
  return ATON_CLKCTRL_BGATES_SET_POOL1(reg, data);
}


/* ---------------------------------------------------------- RECBUF0 field of the BGATES register ---------------------------------------------------------- */

/** Description of the RECBUF0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_RECBUF0_DESC  "Enable clock of Reconfigurable Buffer 0"

/** Offset of the RECBUF0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_RECBUF0_LSB  24UL

/** Size in bits of the RECBUF0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_RECBUF0_W  (1UL)

/** Mask for retrieving the RECBUF0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_RECBUF0_MASK  ATON_FIELD_MASK(24UL, 1UL)

/** Reset value of the RECBUF0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_RECBUF0_DT  0x0UL

/** Access rights of the RECBUF0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_RECBUF0_AC  "RW"

/** Check whether access to the RECBUF0 field of the BGATES register is secured or not. */
#define ATON_CLKCTRL_BGATES_RECBUF0_S  0

/** Check whether access to the RECBUF0 field of the BGATES register is privileged or not. */
#define ATON_CLKCTRL_BGATES_RECBUF0_P  0

/** Read the content of the RECBUF0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_GET_RECBUF0(REG)  ATON_GET_FIELD(REG, ATON_CLKCTRL_BGATES_RECBUF0_LSB, ATON_CLKCTRL_BGATES_RECBUF0_W)

/** Modify the content of the RECBUF0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_SET_RECBUF0(REG, DATA)  ATON_SET_FIELD(REG, ATON_CLKCTRL_BGATES_RECBUF0_LSB, ATON_CLKCTRL_BGATES_RECBUF0_W, DATA)


/**
 * Get the description of the RECBUF0 field of BGATES register.
 *
 * \return the description of the RECBUF0 field of BGATES register
 */

static inline const int8_t *ATON_CLKCTRL_BGATES_RECBUF0_GetdDesc(void)
{
  return (const int8_t *)ATON_CLKCTRL_BGATES_RECBUF0_DESC;
}


/**
 * Read the content of the RECBUF0 field of the BGATES register.
 *
 * \param[in] reg is the value of the BGATES register
 *
 * \return the content of the RECBUF0 field belonging to BGATES register
 */

static inline uint32_t ATON_CLKCTRL_BGATES_Get_RECBUF0(uint32_t reg)
{
  return ATON_CLKCTRL_BGATES_GET_RECBUF0(reg);
}


/**
 * Write the content of the RECBUF0 field of the BGATES register.
 *
 * \param[in] reg  is the value of the BGATES register
 * \param[in] data is 1-bit value that must be written to the field
 *
 * \return the new content of the RECBUF0 field belonging to BGATES register
 */

static inline uint32_t ATON_CLKCTRL_BGATES_Set_RECBUF0(uint32_t reg, uint32_t data)
{
  return ATON_CLKCTRL_BGATES_SET_RECBUF0(reg, data);
}


/* -------------------------------------------------------- EPOCHCTRL0 field of the BGATES register --------------------------------------------------------- */

/** Description of the EPOCHCTRL0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_EPOCHCTRL0_DESC  "Enable clock of Epoch Controller 0"

/** Offset of the EPOCHCTRL0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_EPOCHCTRL0_LSB  25UL

/** Size in bits of the EPOCHCTRL0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_EPOCHCTRL0_W  (1UL)

/** Mask for retrieving the EPOCHCTRL0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_EPOCHCTRL0_MASK  ATON_FIELD_MASK(25UL, 1UL)

/** Reset value of the EPOCHCTRL0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_EPOCHCTRL0_DT  0x0UL

/** Access rights of the EPOCHCTRL0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_EPOCHCTRL0_AC  "RW"

/** Check whether access to the EPOCHCTRL0 field of the BGATES register is secured or not. */
#define ATON_CLKCTRL_BGATES_EPOCHCTRL0_S  0

/** Check whether access to the EPOCHCTRL0 field of the BGATES register is privileged or not. */
#define ATON_CLKCTRL_BGATES_EPOCHCTRL0_P  0

/** Read the content of the EPOCHCTRL0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_GET_EPOCHCTRL0(REG)  ATON_GET_FIELD(REG, ATON_CLKCTRL_BGATES_EPOCHCTRL0_LSB, ATON_CLKCTRL_BGATES_EPOCHCTRL0_W)

/** Modify the content of the EPOCHCTRL0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_SET_EPOCHCTRL0(REG, DATA)  ATON_SET_FIELD(REG, ATON_CLKCTRL_BGATES_EPOCHCTRL0_LSB, ATON_CLKCTRL_BGATES_EPOCHCTRL0_W, DATA)


/**
 * Get the description of the EPOCHCTRL0 field of BGATES register.
 *
 * \return the description of the EPOCHCTRL0 field of BGATES register
 */

static inline const int8_t *ATON_CLKCTRL_BGATES_EPOCHCTRL0_GetdDesc(void)
{
  return (const int8_t *)ATON_CLKCTRL_BGATES_EPOCHCTRL0_DESC;
}


/**
 * Read the content of the EPOCHCTRL0 field of the BGATES register.
 *
 * \param[in] reg is the value of the BGATES register
 *
 * \return the content of the EPOCHCTRL0 field belonging to BGATES register
 */

static inline uint32_t ATON_CLKCTRL_BGATES_Get_EPOCHCTRL0(uint32_t reg)
{
  return ATON_CLKCTRL_BGATES_GET_EPOCHCTRL0(reg);
}


/**
 * Write the content of the EPOCHCTRL0 field of the BGATES register.
 *
 * \param[in] reg  is the value of the BGATES register
 * \param[in] data is 1-bit value that must be written to the field
 *
 * \return the new content of the EPOCHCTRL0 field belonging to BGATES register
 */

static inline uint32_t ATON_CLKCTRL_BGATES_Set_EPOCHCTRL0(uint32_t reg, uint32_t data)
{
  return ATON_CLKCTRL_BGATES_SET_EPOCHCTRL0(reg, data);
}


/* ------------------------------------------------------- DEBUG_TRACE0 field of the BGATES register -------------------------------------------------------- */

/** Description of the DEBUG_TRACE0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_DEBUG_TRACE0_DESC  "Enable clock of Debug Trace 0"

/** Offset of the DEBUG_TRACE0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_DEBUG_TRACE0_LSB  26UL

/** Size in bits of the DEBUG_TRACE0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_DEBUG_TRACE0_W  (1UL)

/** Mask for retrieving the DEBUG_TRACE0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_DEBUG_TRACE0_MASK  ATON_FIELD_MASK(26UL, 1UL)

/** Reset value of the DEBUG_TRACE0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_DEBUG_TRACE0_DT  0x0UL

/** Access rights of the DEBUG_TRACE0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_DEBUG_TRACE0_AC  "RW"

/** Check whether access to the DEBUG_TRACE0 field of the BGATES register is secured or not. */
#define ATON_CLKCTRL_BGATES_DEBUG_TRACE0_S  0

/** Check whether access to the DEBUG_TRACE0 field of the BGATES register is privileged or not. */
#define ATON_CLKCTRL_BGATES_DEBUG_TRACE0_P  0

/** Read the content of the DEBUG_TRACE0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_GET_DEBUG_TRACE0(REG)  ATON_GET_FIELD(REG, ATON_CLKCTRL_BGATES_DEBUG_TRACE0_LSB, ATON_CLKCTRL_BGATES_DEBUG_TRACE0_W)

/** Modify the content of the DEBUG_TRACE0 field of the BGATES register. */
#define ATON_CLKCTRL_BGATES_SET_DEBUG_TRACE0(REG, DATA)  ATON_SET_FIELD(REG, ATON_CLKCTRL_BGATES_DEBUG_TRACE0_LSB, ATON_CLKCTRL_BGATES_DEBUG_TRACE0_W, DATA)


/**
 * Get the description of the DEBUG_TRACE0 field of BGATES register.
 *
 * \return the description of the DEBUG_TRACE0 field of BGATES register
 */

static inline const int8_t *ATON_CLKCTRL_BGATES_DEBUG_TRACE0_GetdDesc(void)
{
  return (const int8_t *)ATON_CLKCTRL_BGATES_DEBUG_TRACE0_DESC;
}


/**
 * Read the content of the DEBUG_TRACE0 field of the BGATES register.
 *
 * \param[in] reg is the value of the BGATES register
 *
 * \return the content of the DEBUG_TRACE0 field belonging to BGATES register
 */

static inline uint32_t ATON_CLKCTRL_BGATES_Get_DEBUG_TRACE0(uint32_t reg)
{
  return ATON_CLKCTRL_BGATES_GET_DEBUG_TRACE0(reg);
}


/**
 * Write the content of the DEBUG_TRACE0 field of the BGATES register.
 *
 * \param[in] reg  is the value of the BGATES register
 * \param[in] data is 1-bit value that must be written to the field
 *
 * \return the new content of the DEBUG_TRACE0 field belonging to BGATES register
 */

static inline uint32_t ATON_CLKCTRL_BGATES_Set_DEBUG_TRACE0(uint32_t reg, uint32_t data)
{
  return ATON_CLKCTRL_BGATES_SET_DEBUG_TRACE0(reg, data);
}


/*@}*/


/* ---------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                                                                                                                            */
/*                                                                       INTCTRL Units                                                                        */
/*                                                                                                                                                            */
/* ---------------------------------------------------------------------------------------------------------------------------------------------------------- */

/** Number of INTCTRL Unit instances. */
#define ATON_INTCTRL_NUM 1

/**
 * \name Structures, macros and functions of the INTCTRL Units
 */
/*@{*/

/**
 * Registers of the INTCTRL Units
 */

typedef volatile struct
{
  /** \e CTRL register (Control register). */
  uint32_t CTRL;

  /** \e VERSION register (Version register). */
  uint32_t VERSION;

  /** \e INTREG register (Interrupt register). */
  uint32_t INTREG;

  /** \e INTSET register (Set interrupts). */
  uint32_t INTSET;

  /** \e INTCLR register (Clear interrupts). */
  uint32_t INTCLR;

  /** \e INTORMSK0 register (Interrupt OR mask 0). */
  uint32_t INTORMSK0;

  /** \e INTORMSK1 register (Interrupt OR mask 1). */
  uint32_t INTORMSK1;

  /** \e INTORMSK2 register (Interrupt OR mask 2). */
  uint32_t INTORMSK2;

  /** \e INTORMSK3 register (Interrupt OR mask 3). */
  uint32_t INTORMSK3;

  /** \e INTANDMSK0 register (Interrupt AND mask 0). */
  uint32_t INTANDMSK0;

  /** \e INTANDMSK1 register (Interrupt AND mask 1). */
  uint32_t INTANDMSK1;

  /** \e INTANDMSK2 register (Interrupt AND mask 2). */
  uint32_t INTANDMSK2;

  /** \e INTANDMSK3 register (Interrupt AND mask 3). */
  uint32_t INTANDMSK3;

} ATON_INTCTRL_t;


/** Return the pointer to one of the INTCTRL Units. */
#define ATON_INTCTRL(UNIT) ((ATON_INTCTRL_t *)(intptr_t)ATON_INTCTRL_BASE(UNIT))


/** Name of one of the INTCTRL Units. */
#define ATON_INTCTRL_NAME(UNIT) \
  (((UNIT) == 0) ? "INTCTRL" :  "")


/** Version of the INTCTRL Units. */
#define ATON_INTCTRL_VERSION "1.1"


/** Description of one of the INTCTRL Units. */
#define ATON_INTCTRL_DESC(UNIT) \
  (((UNIT) == 0) ? "Interrupt Controller" :  "")


/** Base address of one of the INTCTRL Units. */
#define ATON_INTCTRL_BASE(UNIT) \
  (ATON_BASE + 0x1000UL + ((UNIT) * 0x0UL))

/** Size in bytes of the INTCTRL Units. */
#define ATON_INTCTRL_SIZE  0x1000UL


/**
 * Get the name of one of the INTCTRL Units.
 *
 * \param[in] instance is the index of the Unit whose name must be returned (it must be <em>idx \< 1<\em>)
 *
 * \return the name of Unit having index \e instance among the INTCTRL Units
 */

static inline const int8_t *ATON_INTCTRL_GetName(uint32_t instance)
{
  const int8_t *str = NULL;

  switch (instance)
  {
    case 0:
      str = (const int8_t *)"INTCTRL";
      break;

    default:
      break;
  }

  return str;
}


/**
 * Get the description of one of the INTCTRL Units.
 *
 * \param[in] instance is the index of the Unit whose description must be returned (it must be <em>idx \< 1<\em>)
 *
 * \return the description of Unit having index \e instance among the INTCTRL Units
 */

static inline const int8_t *ATON_INTCTRL_GetDesc(uint32_t instance)
{
  const int8_t *str = NULL;

  switch (instance)
  {
    case 0:
      str = (const int8_t *)"Interrupt Controller";
      break;

    default:
      break;
  }

  return str;
}


/**
 * Get the version of the INTCTRL Units.
 *
 * \return the version of the INTCTRL Units
 */

static inline const int8_t *ATON_INTCTRL_GetVersion(void)
{
  return (const int8_t *)ATON_INTCTRL_VERSION;
}


/**
 * Get the base address of one of the INTCTRL Units.
 *
 * \param[in] instance is the index of the Unit whose base address must be returned (it must be <em>idx \< 1<\em>)
 *
 * \return the base address of Unit having index \e instance among the INTCTRL Units
 */

static inline uint32_t ATON_INTCTRL_GetBase(uint32_t instance)
{
  return ATON_INTCTRL_BASE(instance);
}


/**
 * Get the size in bytes of the INTCTRL Units.
 *
 * \return the size in bytes of the INTCTRL Units
 */

static inline uint32_t ATON_INTCTRL_GetSize(void)
{
  return ATON_INTCTRL_SIZE;
}


/* ******************************************************* CTRL register of one of the INTCTRL Units ******************************************************** */

/** Offset of the CTRL register from the base address of the INTCTRL Unit. */
#define ATON_INTCTRL_CTRL_OFFSET  0x0UL

/** Reset value of the CTRL register of the INTCTRL Unit. */
#define ATON_INTCTRL_CTRL_DT \
  (ATON_INTCTRL_CTRL_EN_DT      << ATON_INTCTRL_CTRL_EN_LSB)      | \
  (ATON_INTCTRL_CTRL_CLR_DT     << ATON_INTCTRL_CTRL_CLR_LSB)     | \
  (ATON_INTCTRL_CTRL_CONFCLR_DT << ATON_INTCTRL_CTRL_CONFCLR_LSB)



/** Description of the CTRL register. */
#define ATON_INTCTRL_CTRL_DESC  "Control register"

/** Address of the CTRL register of one of the INTCTRL Units. */
#define ATON_INTCTRL_CTRL_ADDR(UNIT)  (ATON_INTCTRL_BASE(UNIT) + ATON_INTCTRL_CTRL_OFFSET)

/** Get the content of the CTRL register of one of the INTCTRL Units. */
#define ATON_INTCTRL_CTRL_GET(UNIT)  (*((volatile uint32_t *)(uintptr_t)ATON_INTCTRL_CTRL_ADDR(UNIT)))

/** Set the content of the CTRL register of one of the INTCTRL Units. */
#define ATON_INTCTRL_CTRL_SET(UNIT, DATA)  do { *((volatile uint32_t *)(uintptr_t)ATON_INTCTRL_CTRL_ADDR(UNIT)) = (DATA); } while (0);


/**
 * Get the description of CTRL register.
 *
 * \return the description of CTRL register
 */

static inline const int8_t *ATON_INTCTRL_CTRL_GetDesc(void)
{
  return (const int8_t *)ATON_INTCTRL_CTRL_DESC;
}


/**
 * Get the offset of the CTRL register.
 *
 * \return the offset of CTRL register
 */

static inline uint32_t ATON_INTCTRL_CTRL_GetOffset(void)
{
  return ATON_INTCTRL_CTRL_OFFSET;
}


/**
 * Get the address of the CTRL register.
 *
 * \param[in] instance is the index of the Unit (among the INTCTRL Units) containing the CTRL register whose address must be returned
 *                     (it must be <em>instance \< 1<\em>)
 *
 * \return the address of CTRL register belonging to Unit having index \e instance among the INTCTRL Units
 */

static inline uint32_t ATON_INTCTRL_CTRL_GetAddr(uint32_t instance)
{
  return ATON_INTCTRL_CTRL_ADDR(instance);
}


/**
 * Read the content of the CTRL register.
 *
 * \param[in] instance is the index of the Unit (among the INTCTRL Units) containing the CTRL register whose content must be retrieved
 *                     (it must be <em>instance \< 1<\em>)
 *
 * \return the content of CTRL register belonging to Unit having index \e instance among the INTCTRL Units
 */

static inline uint32_t ATON_INTCTRL_CTRL_Get(uint32_t instance)
{
  return ATON_INTCTRL_CTRL_GET(instance);
}


/**
 * Write the content of the CTRL register.
 *
 * \param[in] instance is the index of the Unit (among the INTCTRL Units) containing the CTRL register whose content must be modified
 *                     (it must be <em>instance \< 1<\em>)
 * \param[in] data     is 32-bit value that must be written to the register
 */

static inline void ATON_INTCTRL_CTRL_Set(uint32_t instance, uint32_t data)
{
  ATON_INTCTRL_CTRL_SET(instance, data);
}


/* ------------------------------------------------------------- EN field of the CTRL register -------------------------------------------------------------- */

/** Description of the EN field of the CTRL register. */
#define ATON_INTCTRL_CTRL_EN_DESC  "Enable the Interrupt Controller"

/** Offset of the EN field of the CTRL register. */
#define ATON_INTCTRL_CTRL_EN_LSB  0UL

/** Size in bits of the EN field of the CTRL register. */
#define ATON_INTCTRL_CTRL_EN_W  (1UL)

/** Mask for retrieving the EN field of the CTRL register. */
#define ATON_INTCTRL_CTRL_EN_MASK  ATON_FIELD_MASK(0UL, 1UL)

/** Reset value of the EN field of the CTRL register. */
#define ATON_INTCTRL_CTRL_EN_DT  0x0UL

/** Access rights of the EN field of the CTRL register. */
#define ATON_INTCTRL_CTRL_EN_AC  "RW"

/** Check whether access to the EN field of the CTRL register is secured or not. */
#define ATON_INTCTRL_CTRL_EN_S  0

/** Check whether access to the EN field of the CTRL register is privileged or not. */
#define ATON_INTCTRL_CTRL_EN_P  0

/** Read the content of the EN field of the CTRL register. */
#define ATON_INTCTRL_CTRL_GET_EN(REG)  ATON_GET_FIELD(REG, ATON_INTCTRL_CTRL_EN_LSB, ATON_INTCTRL_CTRL_EN_W)

/** Modify the content of the EN field of the CTRL register. */
#define ATON_INTCTRL_CTRL_SET_EN(REG, DATA)  ATON_SET_FIELD(REG, ATON_INTCTRL_CTRL_EN_LSB, ATON_INTCTRL_CTRL_EN_W, DATA)


/**
 * Get the description of the EN field of CTRL register.
 *
 * \return the description of the EN field of CTRL register
 */

static inline const int8_t *ATON_INTCTRL_CTRL_EN_GetdDesc(void)
{
  return (const int8_t *)ATON_INTCTRL_CTRL_EN_DESC;
}


/**
 * Read the content of the EN field of the CTRL register.
 *
 * \param[in] reg is the value of the CTRL register
 *
 * \return the content of the EN field belonging to CTRL register
 */

static inline uint32_t ATON_INTCTRL_CTRL_Get_EN(uint32_t reg)
{
  return ATON_INTCTRL_CTRL_GET_EN(reg);
}


/**
 * Write the content of the EN field of the CTRL register.
 *
 * \param[in] reg  is the value of the CTRL register
 * \param[in] data is 1-bit value that must be written to the field
 *
 * \return the new content of the EN field belonging to CTRL register
 */

static inline uint32_t ATON_INTCTRL_CTRL_Set_EN(uint32_t reg, uint32_t data)
{
  return ATON_INTCTRL_CTRL_SET_EN(reg, data);
}


/* ------------------------------------------------------------- CLR field of the CTRL register ------------------------------------------------------------- */

/** Description of the CLR field of the CTRL register. */
#define ATON_INTCTRL_CTRL_CLR_DESC  "Clear interrupts"

/** Offset of the CLR field of the CTRL register. */
#define ATON_INTCTRL_CTRL_CLR_LSB  1UL

/** Size in bits of the CLR field of the CTRL register. */
#define ATON_INTCTRL_CTRL_CLR_W  (1UL)

/** Mask for retrieving the CLR field of the CTRL register. */
#define ATON_INTCTRL_CTRL_CLR_MASK  ATON_FIELD_MASK(1UL, 1UL)

/** Reset value of the CLR field of the CTRL register. */
#define ATON_INTCTRL_CTRL_CLR_DT  0x0UL

/** Access rights of the CLR field of the CTRL register. */
#define ATON_INTCTRL_CTRL_CLR_AC  "RW"

/** Check whether access to the CLR field of the CTRL register is secured or not. */
#define ATON_INTCTRL_CTRL_CLR_S  0

/** Check whether access to the CLR field of the CTRL register is privileged or not. */
#define ATON_INTCTRL_CTRL_CLR_P  0

/** Read the content of the CLR field of the CTRL register. */
#define ATON_INTCTRL_CTRL_GET_CLR(REG)  ATON_GET_FIELD(REG, ATON_INTCTRL_CTRL_CLR_LSB, ATON_INTCTRL_CTRL_CLR_W)

/** Modify the content of the CLR field of the CTRL register. */
#define ATON_INTCTRL_CTRL_SET_CLR(REG, DATA)  ATON_SET_FIELD(REG, ATON_INTCTRL_CTRL_CLR_LSB, ATON_INTCTRL_CTRL_CLR_W, DATA)


/**
 * Get the description of the CLR field of CTRL register.
 *
 * \return the description of the CLR field of CTRL register
 */

static inline const int8_t *ATON_INTCTRL_CTRL_CLR_GetdDesc(void)
{
  return (const int8_t *)ATON_INTCTRL_CTRL_CLR_DESC;
}


/**
 * Read the content of the CLR field of the CTRL register.
 *
 * \param[in] reg is the value of the CTRL register
 *
 * \return the content of the CLR field belonging to CTRL register
 */

static inline uint32_t ATON_INTCTRL_CTRL_Get_CLR(uint32_t reg)
{
  return ATON_INTCTRL_CTRL_GET_CLR(reg);
}


/**
 * Write the content of the CLR field of the CTRL register.
 *
 * \param[in] reg  is the value of the CTRL register
 * \param[in] data is 1-bit value that must be written to the field
 *
 * \return the new content of the CLR field belonging to CTRL register
 */

static inline uint32_t ATON_INTCTRL_CTRL_Set_CLR(uint32_t reg, uint32_t data)
{
  return ATON_INTCTRL_CTRL_SET_CLR(reg, data);
}


/* ----------------------------------------------------------- CONFCLR field of the CTRL register ----------------------------------------------------------- */

/** Description of the CONFCLR field of the CTRL register. */
#define ATON_INTCTRL_CTRL_CONFCLR_DESC  "Clear Configuration registers (autocleared)"

/** Offset of the CONFCLR field of the CTRL register. */
#define ATON_INTCTRL_CTRL_CONFCLR_LSB  30UL

/** Size in bits of the CONFCLR field of the CTRL register. */
#define ATON_INTCTRL_CTRL_CONFCLR_W  (1UL)

/** Mask for retrieving the CONFCLR field of the CTRL register. */
#define ATON_INTCTRL_CTRL_CONFCLR_MASK  ATON_FIELD_MASK(30UL, 1UL)

/** Reset value of the CONFCLR field of the CTRL register. */
#define ATON_INTCTRL_CTRL_CONFCLR_DT  0x0UL

/** Access rights of the CONFCLR field of the CTRL register. */
#define ATON_INTCTRL_CTRL_CONFCLR_AC  "RW"

/** Check whether access to the CONFCLR field of the CTRL register is secured or not. */
#define ATON_INTCTRL_CTRL_CONFCLR_S  0

/** Check whether access to the CONFCLR field of the CTRL register is privileged or not. */
#define ATON_INTCTRL_CTRL_CONFCLR_P  0

/** Read the content of the CONFCLR field of the CTRL register. */
#define ATON_INTCTRL_CTRL_GET_CONFCLR(REG)  ATON_GET_FIELD(REG, ATON_INTCTRL_CTRL_CONFCLR_LSB, ATON_INTCTRL_CTRL_CONFCLR_W)

/** Modify the content of the CONFCLR field of the CTRL register. */
#define ATON_INTCTRL_CTRL_SET_CONFCLR(REG, DATA)  ATON_SET_FIELD(REG, ATON_INTCTRL_CTRL_CONFCLR_LSB, ATON_INTCTRL_CTRL_CONFCLR_W, DATA)


/**
 * Get the description of the CONFCLR field of CTRL register.
 *
 * \return the description of the CONFCLR field of CTRL register
 */

static inline const int8_t *ATON_INTCTRL_CTRL_CONFCLR_GetdDesc(void)
{
  return (const int8_t *)ATON_INTCTRL_CTRL_CONFCLR_DESC;
}


/**
 * Read the content of the CONFCLR field of the CTRL register.
 *
 * \param[in] reg is the value of the CTRL register
 *
 * \return the content of the CONFCLR field belonging to CTRL register
 */

static inline uint32_t ATON_INTCTRL_CTRL_Get_CONFCLR(uint32_t reg)
{
  return ATON_INTCTRL_CTRL_GET_CONFCLR(reg);
}


/**
 * Write the content of the CONFCLR field of the CTRL register.
 *
 * \param[in] reg  is the value of the CTRL register
 * \param[in] data is 1-bit value that must be written to the field
 *
 * \return the new content of the CONFCLR field belonging to CTRL register
 */

static inline uint32_t ATON_INTCTRL_CTRL_Set_CONFCLR(uint32_t reg, uint32_t data)
{
  return ATON_INTCTRL_CTRL_SET_CONFCLR(reg, data);
}


/* ****************************************************** VERSION register of one of the INTCTRL Units ****************************************************** */

/** Offset of the VERSION register from the base address of the INTCTRL Unit. */
#define ATON_INTCTRL_VERSION_OFFSET  0x4UL

/** Reset value of the VERSION register of the INTCTRL Unit. */
#define ATON_INTCTRL_VERSION_DT \
  (ATON_INTCTRL_VERSION_TYPE_DT     << ATON_INTCTRL_VERSION_TYPE_LSB)     | \
  (ATON_INTCTRL_VERSION_MINOR_DT    << ATON_INTCTRL_VERSION_MINOR_LSB)    | \
  (ATON_INTCTRL_VERSION_MAJOR_DT    << ATON_INTCTRL_VERSION_MAJOR_LSB)    | \
  (ATON_INTCTRL_VERSION_NRINTS_DT   << ATON_INTCTRL_VERSION_NRINTS_LSB)   | \
  (ATON_INTCTRL_VERSION_HOSTINTS_DT << ATON_INTCTRL_VERSION_HOSTINTS_LSB)



/** Description of the VERSION register. */
#define ATON_INTCTRL_VERSION_DESC  "Version register"

/** Address of the VERSION register of one of the INTCTRL Units. */
#define ATON_INTCTRL_VERSION_ADDR(UNIT)  (ATON_INTCTRL_BASE(UNIT) + ATON_INTCTRL_VERSION_OFFSET)

/** Get the content of the VERSION register of one of the INTCTRL Units. */
#define ATON_INTCTRL_VERSION_GET(UNIT)  (*((volatile uint32_t *)(uintptr_t)ATON_INTCTRL_VERSION_ADDR(UNIT)))


/**
 * Get the description of VERSION register.
 *
 * \return the description of VERSION register
 */

static inline const int8_t *ATON_INTCTRL_VERSION_GetDesc(void)
{
  return (const int8_t *)ATON_INTCTRL_VERSION_DESC;
}


/**
 * Get the offset of the VERSION register.
 *
 * \return the offset of VERSION register
 */

static inline uint32_t ATON_INTCTRL_VERSION_GetOffset(void)
{
  return ATON_INTCTRL_VERSION_OFFSET;
}


/**
 * Get the address of the VERSION register.
 *
 * \param[in] instance is the index of the Unit (among the INTCTRL Units) containing the VERSION register whose address must be returned
 *                     (it must be <em>instance \< 1<\em>)
 *
 * \return the address of VERSION register belonging to Unit having index \e instance among the INTCTRL Units
 */

static inline uint32_t ATON_INTCTRL_VERSION_GetAddr(uint32_t instance)
{
  return ATON_INTCTRL_VERSION_ADDR(instance);
}


/**
 * Read the content of the VERSION register.
 *
 * \param[in] instance is the index of the Unit (among the INTCTRL Units) containing the VERSION register whose content must be retrieved
 *                     (it must be <em>instance \< 1<\em>)
 *
 * \return the content of VERSION register belonging to Unit having index \e instance among the INTCTRL Units
 */

static inline uint32_t ATON_INTCTRL_VERSION_Get(uint32_t instance)
{
  return ATON_INTCTRL_VERSION_GET(instance);
}


/* ----------------------------------------------------------- TYPE field of the VERSION register ----------------------------------------------------------- */

/** Description of the TYPE field of the VERSION register. */
#define ATON_INTCTRL_VERSION_TYPE_DESC  "Block type"

/** Offset of the TYPE field of the VERSION register. */
#define ATON_INTCTRL_VERSION_TYPE_LSB  0UL

/** Size in bits of the TYPE field of the VERSION register. */
#define ATON_INTCTRL_VERSION_TYPE_W  (8UL)

/** Mask for retrieving the TYPE field of the VERSION register. */
#define ATON_INTCTRL_VERSION_TYPE_MASK  ATON_FIELD_MASK(0UL, 8UL)

/** Reset value of the TYPE field of the VERSION register. */
#define ATON_INTCTRL_VERSION_TYPE_DT  0x1eUL

/** Access rights of the TYPE field of the VERSION register. */
#define ATON_INTCTRL_VERSION_TYPE_AC  "R"

/** Check whether access to the TYPE field of the VERSION register is secured or not. */
#define ATON_INTCTRL_VERSION_TYPE_S  0

/** Check whether access to the TYPE field of the VERSION register is privileged or not. */
#define ATON_INTCTRL_VERSION_TYPE_P  0

/** Read the content of the TYPE field of the VERSION register. */
#define ATON_INTCTRL_VERSION_GET_TYPE(REG)  ATON_GET_FIELD(REG, ATON_INTCTRL_VERSION_TYPE_LSB, ATON_INTCTRL_VERSION_TYPE_W)


/**
 * Get the description of the TYPE field of VERSION register.
 *
 * \return the description of the TYPE field of VERSION register
 */

static inline const int8_t *ATON_INTCTRL_VERSION_TYPE_GetdDesc(void)
{
  return (const int8_t *)ATON_INTCTRL_VERSION_TYPE_DESC;
}


/**
 * Read the content of the TYPE field of the VERSION register.
 *
 * \param[in] reg is the value of the VERSION register
 *
 * \return the content of the TYPE field belonging to VERSION register
 */

static inline uint32_t ATON_INTCTRL_VERSION_Get_TYPE(uint32_t reg)
{
  return ATON_INTCTRL_VERSION_GET_TYPE(reg);
}


/* ---------------------------------------------------------- MINOR field of the VERSION register ----------------------------------------------------------- */

/** Description of the MINOR field of the VERSION register. */
#define ATON_INTCTRL_VERSION_MINOR_DESC  "Block minor version"

/** Offset of the MINOR field of the VERSION register. */
#define ATON_INTCTRL_VERSION_MINOR_LSB  8UL

/** Size in bits of the MINOR field of the VERSION register. */
#define ATON_INTCTRL_VERSION_MINOR_W  (4UL)

/** Mask for retrieving the MINOR field of the VERSION register. */
#define ATON_INTCTRL_VERSION_MINOR_MASK  ATON_FIELD_MASK(8UL, 4UL)

/** Reset value of the MINOR field of the VERSION register. */
#define ATON_INTCTRL_VERSION_MINOR_DT  0x1UL

/** Access rights of the MINOR field of the VERSION register. */
#define ATON_INTCTRL_VERSION_MINOR_AC  "R"

/** Check whether access to the MINOR field of the VERSION register is secured or not. */
#define ATON_INTCTRL_VERSION_MINOR_S  0

/** Check whether access to the MINOR field of the VERSION register is privileged or not. */
#define ATON_INTCTRL_VERSION_MINOR_P  0

/** Read the content of the MINOR field of the VERSION register. */
#define ATON_INTCTRL_VERSION_GET_MINOR(REG)  ATON_GET_FIELD(REG, ATON_INTCTRL_VERSION_MINOR_LSB, ATON_INTCTRL_VERSION_MINOR_W)


/**
 * Get the description of the MINOR field of VERSION register.
 *
 * \return the description of the MINOR field of VERSION register
 */

static inline const int8_t *ATON_INTCTRL_VERSION_MINOR_GetdDesc(void)
{
  return (const int8_t *)ATON_INTCTRL_VERSION_MINOR_DESC;
}


/**
 * Read the content of the MINOR field of the VERSION register.
 *
 * \param[in] reg is the value of the VERSION register
 *
 * \return the content of the MINOR field belonging to VERSION register
 */

static inline uint32_t ATON_INTCTRL_VERSION_Get_MINOR(uint32_t reg)
{
  return ATON_INTCTRL_VERSION_GET_MINOR(reg);
}


/* ---------------------------------------------------------- MAJOR field of the VERSION register ----------------------------------------------------------- */

/** Description of the MAJOR field of the VERSION register. */
#define ATON_INTCTRL_VERSION_MAJOR_DESC  "Block major version"

/** Offset of the MAJOR field of the VERSION register. */
#define ATON_INTCTRL_VERSION_MAJOR_LSB  12UL

/** Size in bits of the MAJOR field of the VERSION register. */
#define ATON_INTCTRL_VERSION_MAJOR_W  (4UL)

/** Mask for retrieving the MAJOR field of the VERSION register. */
#define ATON_INTCTRL_VERSION_MAJOR_MASK  ATON_FIELD_MASK(12UL, 4UL)

/** Reset value of the MAJOR field of the VERSION register. */
#define ATON_INTCTRL_VERSION_MAJOR_DT  0x1UL

/** Access rights of the MAJOR field of the VERSION register. */
#define ATON_INTCTRL_VERSION_MAJOR_AC  "R"

/** Check whether access to the MAJOR field of the VERSION register is secured or not. */
#define ATON_INTCTRL_VERSION_MAJOR_S  0

/** Check whether access to the MAJOR field of the VERSION register is privileged or not. */
#define ATON_INTCTRL_VERSION_MAJOR_P  0

/** Read the content of the MAJOR field of the VERSION register. */
#define ATON_INTCTRL_VERSION_GET_MAJOR(REG)  ATON_GET_FIELD(REG, ATON_INTCTRL_VERSION_MAJOR_LSB, ATON_INTCTRL_VERSION_MAJOR_W)


/**
 * Get the description of the MAJOR field of VERSION register.
 *
 * \return the description of the MAJOR field of VERSION register
 */

static inline const int8_t *ATON_INTCTRL_VERSION_MAJOR_GetdDesc(void)
{
  return (const int8_t *)ATON_INTCTRL_VERSION_MAJOR_DESC;
}


/**
 * Read the content of the MAJOR field of the VERSION register.
 *
 * \param[in] reg is the value of the VERSION register
 *
 * \return the content of the MAJOR field belonging to VERSION register
 */

static inline uint32_t ATON_INTCTRL_VERSION_Get_MAJOR(uint32_t reg)
{
  return ATON_INTCTRL_VERSION_GET_MAJOR(reg);
}


/* ---------------------------------------------------------- NRINTS field of the VERSION register ---------------------------------------------------------- */

/** Description of the NRINTS field of the VERSION register. */
#define ATON_INTCTRL_VERSION_NRINTS_DESC  "Number of internal interrupts"

/** Offset of the NRINTS field of the VERSION register. */
#define ATON_INTCTRL_VERSION_NRINTS_LSB  16UL

/** Size in bits of the NRINTS field of the VERSION register. */
#define ATON_INTCTRL_VERSION_NRINTS_W  (8UL)

/** Mask for retrieving the NRINTS field of the VERSION register. */
#define ATON_INTCTRL_VERSION_NRINTS_MASK  ATON_FIELD_MASK(16UL, 8UL)

/** Reset value of the NRINTS field of the VERSION register. */
#define ATON_INTCTRL_VERSION_NRINTS_DT  0x20UL

/** Access rights of the NRINTS field of the VERSION register. */
#define ATON_INTCTRL_VERSION_NRINTS_AC  "R"

/** Check whether access to the NRINTS field of the VERSION register is secured or not. */
#define ATON_INTCTRL_VERSION_NRINTS_S  0

/** Check whether access to the NRINTS field of the VERSION register is privileged or not. */
#define ATON_INTCTRL_VERSION_NRINTS_P  0

/** Read the content of the NRINTS field of the VERSION register. */
#define ATON_INTCTRL_VERSION_GET_NRINTS(REG)  ATON_GET_FIELD(REG, ATON_INTCTRL_VERSION_NRINTS_LSB, ATON_INTCTRL_VERSION_NRINTS_W)


/**
 * Get the description of the NRINTS field of VERSION register.
 *
 * \return the description of the NRINTS field of VERSION register
 */

static inline const int8_t *ATON_INTCTRL_VERSION_NRINTS_GetdDesc(void)
{
  return (const int8_t *)ATON_INTCTRL_VERSION_NRINTS_DESC;
}


/**
 * Read the content of the NRINTS field of the VERSION register.
 *
 * \param[in] reg is the value of the VERSION register
 *
 * \return the content of the NRINTS field belonging to VERSION register
 */

static inline uint32_t ATON_INTCTRL_VERSION_Get_NRINTS(uint32_t reg)
{
  return ATON_INTCTRL_VERSION_GET_NRINTS(reg);
}


/* --------------------------------------------------------- HOSTINTS field of the VERSION register --------------------------------------------------------- */

/** Description of the HOSTINTS field of the VERSION register. */
#define ATON_INTCTRL_VERSION_HOSTINTS_DESC  "Number of host interrupt lines"

/** Offset of the HOSTINTS field of the VERSION register. */
#define ATON_INTCTRL_VERSION_HOSTINTS_LSB  24UL

/** Size in bits of the HOSTINTS field of the VERSION register. */
#define ATON_INTCTRL_VERSION_HOSTINTS_W  (8UL)

/** Mask for retrieving the HOSTINTS field of the VERSION register. */
#define ATON_INTCTRL_VERSION_HOSTINTS_MASK  ATON_FIELD_MASK(24UL, 8UL)

/** Reset value of the HOSTINTS field of the VERSION register. */
#define ATON_INTCTRL_VERSION_HOSTINTS_DT  0x4UL

/** Access rights of the HOSTINTS field of the VERSION register. */
#define ATON_INTCTRL_VERSION_HOSTINTS_AC  "R"

/** Check whether access to the HOSTINTS field of the VERSION register is secured or not. */
#define ATON_INTCTRL_VERSION_HOSTINTS_S  0

/** Check whether access to the HOSTINTS field of the VERSION register is privileged or not. */
#define ATON_INTCTRL_VERSION_HOSTINTS_P  0

/** Read the content of the HOSTINTS field of the VERSION register. */
#define ATON_INTCTRL_VERSION_GET_HOSTINTS(REG)  ATON_GET_FIELD(REG, ATON_INTCTRL_VERSION_HOSTINTS_LSB, ATON_INTCTRL_VERSION_HOSTINTS_W)


/**
 * Get the description of the HOSTINTS field of VERSION register.
 *
 * \return the description of the HOSTINTS field of VERSION register
 */

static inline const int8_t *ATON_INTCTRL_VERSION_HOSTINTS_GetdDesc(void)
{
  return (const int8_t *)ATON_INTCTRL_VERSION_HOSTINTS_DESC;
}


/**
 * Read the content of the HOSTINTS field of the VERSION register.
 *
 * \param[in] reg is the value of the VERSION register
 *
 * \return the content of the HOSTINTS field belonging to VERSION register
 */

static inline uint32_t ATON_INTCTRL_VERSION_Get_HOSTINTS(uint32_t reg)
{
  return ATON_INTCTRL_VERSION_GET_HOSTINTS(reg);
}


/* ****************************************************** INTREG register of one of the INTCTRL Units ******************************************************* */

/** Offset of the INTREG register from the base address of the INTCTRL Unit. */
#define ATON_INTCTRL_INTREG_OFFSET  0x8UL

/** Reset value of the INTREG register of the INTCTRL Unit. */
#define ATON_INTCTRL_INTREG_DT \
  (ATON_INTCTRL_INTREG_REG_DT << ATON_INTCTRL_INTREG_REG_LSB)



/** Description of the INTREG register. */
#define ATON_INTCTRL_INTREG_DESC  "Interrupt register"

/** Address of the INTREG register of one of the INTCTRL Units. */
#define ATON_INTCTRL_INTREG_ADDR(UNIT)  (ATON_INTCTRL_BASE(UNIT) + ATON_INTCTRL_INTREG_OFFSET)

/** Get the content of the INTREG register of one of the INTCTRL Units. */
#define ATON_INTCTRL_INTREG_GET(UNIT)  (*((volatile uint32_t *)(uintptr_t)ATON_INTCTRL_INTREG_ADDR(UNIT)))


/**
 * Get the description of INTREG register.
 *
 * \return the description of INTREG register
 */

static inline const int8_t *ATON_INTCTRL_INTREG_GetDesc(void)
{
  return (const int8_t *)ATON_INTCTRL_INTREG_DESC;
}


/**
 * Get the offset of the INTREG register.
 *
 * \return the offset of INTREG register
 */

static inline uint32_t ATON_INTCTRL_INTREG_GetOffset(void)
{
  return ATON_INTCTRL_INTREG_OFFSET;
}


/**
 * Get the address of the INTREG register.
 *
 * \param[in] instance is the index of the Unit (among the INTCTRL Units) containing the INTREG register whose address must be returned
 *                     (it must be <em>instance \< 1<\em>)
 *
 * \return the address of INTREG register belonging to Unit having index \e instance among the INTCTRL Units
 */

static inline uint32_t ATON_INTCTRL_INTREG_GetAddr(uint32_t instance)
{
  return ATON_INTCTRL_INTREG_ADDR(instance);
}


/**
 * Read the content of the INTREG register.
 *
 * \param[in] instance is the index of the Unit (among the INTCTRL Units) containing the INTREG register whose content must be retrieved
 *                     (it must be <em>instance \< 1<\em>)
 *
 * \return the content of INTREG register belonging to Unit having index \e instance among the INTCTRL Units
 */

static inline uint32_t ATON_INTCTRL_INTREG_Get(uint32_t instance)
{
  return ATON_INTCTRL_INTREG_GET(instance);
}


/* ------------------------------------------------------------ REG field of the INTREG register ------------------------------------------------------------ */

/** Description of the REG field of the INTREG register. */
#define ATON_INTCTRL_INTREG_REG_DESC  "If interrupt X is set, bit X is set"

/** Offset of the REG field of the INTREG register. */
#define ATON_INTCTRL_INTREG_REG_LSB  0UL

/** Size in bits of the REG field of the INTREG register. */
#define ATON_INTCTRL_INTREG_REG_W  (32UL)

/** Mask for retrieving the REG field of the INTREG register. */
#define ATON_INTCTRL_INTREG_REG_MASK  ATON_FIELD_MASK(0UL, 32UL)

/** Reset value of the REG field of the INTREG register. */
#define ATON_INTCTRL_INTREG_REG_DT  0x0UL

/** Access rights of the REG field of the INTREG register. */
#define ATON_INTCTRL_INTREG_REG_AC  "R"

/** Check whether access to the REG field of the INTREG register is secured or not. */
#define ATON_INTCTRL_INTREG_REG_S  0

/** Check whether access to the REG field of the INTREG register is privileged or not. */
#define ATON_INTCTRL_INTREG_REG_P  0

/** Read the content of the REG field of the INTREG register. */
#define ATON_INTCTRL_INTREG_GET_REG(REG)  ATON_GET_FIELD(REG, ATON_INTCTRL_INTREG_REG_LSB, ATON_INTCTRL_INTREG_REG_W)


/**
 * Get the description of the REG field of INTREG register.
 *
 * \return the description of the REG field of INTREG register
 */

static inline const int8_t *ATON_INTCTRL_INTREG_REG_GetdDesc(void)
{
  return (const int8_t *)ATON_INTCTRL_INTREG_REG_DESC;
}


/**
 * Read the content of the REG field of the INTREG register.
 *
 * \param[in] reg is the value of the INTREG register
 *
 * \return the content of the REG field belonging to INTREG register
 */

static inline uint32_t ATON_INTCTRL_INTREG_Get_REG(uint32_t reg)
{
  return ATON_INTCTRL_INTREG_GET_REG(reg);
}


/* ****************************************************** INTSET register of one of the INTCTRL Units ******************************************************* */

/** Offset of the INTSET register from the base address of the INTCTRL Unit. */
#define ATON_INTCTRL_INTSET_OFFSET  0xcUL

/** Reset value of the INTSET register of the INTCTRL Unit. */
#define ATON_INTCTRL_INTSET_DT \
  (ATON_INTCTRL_INTSET_REG_DT << ATON_INTCTRL_INTSET_REG_LSB)



/** Description of the INTSET register. */
#define ATON_INTCTRL_INTSET_DESC  "Set interrupts"

/** Address of the INTSET register of one of the INTCTRL Units. */
#define ATON_INTCTRL_INTSET_ADDR(UNIT)  (ATON_INTCTRL_BASE(UNIT) + ATON_INTCTRL_INTSET_OFFSET)

/** Get the content of the INTSET register of one of the INTCTRL Units. */
#define ATON_INTCTRL_INTSET_GET(UNIT)  (*((volatile uint32_t *)(uintptr_t)ATON_INTCTRL_INTSET_ADDR(UNIT)))

/** Set the content of the INTSET register of one of the INTCTRL Units. */
#define ATON_INTCTRL_INTSET_SET(UNIT, DATA)  do { *((volatile uint32_t *)(uintptr_t)ATON_INTCTRL_INTSET_ADDR(UNIT)) = (DATA); } while (0);


/**
 * Get the description of INTSET register.
 *
 * \return the description of INTSET register
 */

static inline const int8_t *ATON_INTCTRL_INTSET_GetDesc(void)
{
  return (const int8_t *)ATON_INTCTRL_INTSET_DESC;
}


/**
 * Get the offset of the INTSET register.
 *
 * \return the offset of INTSET register
 */

static inline uint32_t ATON_INTCTRL_INTSET_GetOffset(void)
{
  return ATON_INTCTRL_INTSET_OFFSET;
}


/**
 * Get the address of the INTSET register.
 *
 * \param[in] instance is the index of the Unit (among the INTCTRL Units) containing the INTSET register whose address must be returned
 *                     (it must be <em>instance \< 1<\em>)
 *
 * \return the address of INTSET register belonging to Unit having index \e instance among the INTCTRL Units
 */

static inline uint32_t ATON_INTCTRL_INTSET_GetAddr(uint32_t instance)
{
  return ATON_INTCTRL_INTSET_ADDR(instance);
}


/**
 * Read the content of the INTSET register.
 *
 * \param[in] instance is the index of the Unit (among the INTCTRL Units) containing the INTSET register whose content must be retrieved
 *                     (it must be <em>instance \< 1<\em>)
 *
 * \return the content of INTSET register belonging to Unit having index \e instance among the INTCTRL Units
 */

static inline uint32_t ATON_INTCTRL_INTSET_Get(uint32_t instance)
{
  return ATON_INTCTRL_INTSET_GET(instance);
}


/**
 * Write the content of the INTSET register.
 *
 * \param[in] instance is the index of the Unit (among the INTCTRL Units) containing the INTSET register whose content must be modified
 *                     (it must be <em>instance \< 1<\em>)
 * \param[in] data     is 32-bit value that must be written to the register
 */

static inline void ATON_INTCTRL_INTSET_Set(uint32_t instance, uint32_t data)
{
  ATON_INTCTRL_INTSET_SET(instance, data);
}


/* ------------------------------------------------------------ REG field of the INTSET register ------------------------------------------------------------ */

/** Description of the REG field of the INTSET register. */
#define ATON_INTCTRL_INTSET_REG_DESC  "If bit X is set, interrupt X is raised. Reading this register returns same content as INTREG"

/** Offset of the REG field of the INTSET register. */
#define ATON_INTCTRL_INTSET_REG_LSB  0UL

/** Size in bits of the REG field of the INTSET register. */
#define ATON_INTCTRL_INTSET_REG_W  (32UL)

/** Mask for retrieving the REG field of the INTSET register. */
#define ATON_INTCTRL_INTSET_REG_MASK  ATON_FIELD_MASK(0UL, 32UL)

/** Reset value of the REG field of the INTSET register. */
#define ATON_INTCTRL_INTSET_REG_DT  0x0UL

/** Access rights of the REG field of the INTSET register. */
#define ATON_INTCTRL_INTSET_REG_AC  "RW"

/** Check whether access to the REG field of the INTSET register is secured or not. */
#define ATON_INTCTRL_INTSET_REG_S  0

/** Check whether access to the REG field of the INTSET register is privileged or not. */
#define ATON_INTCTRL_INTSET_REG_P  0

/** Read the content of the REG field of the INTSET register. */
#define ATON_INTCTRL_INTSET_GET_REG(REG)  ATON_GET_FIELD(REG, ATON_INTCTRL_INTSET_REG_LSB, ATON_INTCTRL_INTSET_REG_W)

/** Modify the content of the REG field of the INTSET register. */
#define ATON_INTCTRL_INTSET_SET_REG(REG, DATA)  ATON_SET_FIELD(REG, ATON_INTCTRL_INTSET_REG_LSB, ATON_INTCTRL_INTSET_REG_W, DATA)


/**
 * Get the description of the REG field of INTSET register.
 *
 * \return the description of the REG field of INTSET register
 */

static inline const int8_t *ATON_INTCTRL_INTSET_REG_GetdDesc(void)
{
  return (const int8_t *)ATON_INTCTRL_INTSET_REG_DESC;
}


/**
 * Read the content of the REG field of the INTSET register.
 *
 * \param[in] reg is the value of the INTSET register
 *
 * \return the content of the REG field belonging to INTSET register
 */

static inline uint32_t ATON_INTCTRL_INTSET_Get_REG(uint32_t reg)
{
  return ATON_INTCTRL_INTSET_GET_REG(reg);
}


/**
 * Write the content of the REG field of the INTSET register.
 *
 * \param[in] reg  is the value of the INTSET register
 * \param[in] data is 32-bit value that must be written to the field
 *
 * \return the new content of the REG field belonging to INTSET register
 */

static inline uint32_t ATON_INTCTRL_INTSET_Set_REG(uint32_t reg, uint32_t data)
{
  return ATON_INTCTRL_INTSET_SET_REG(reg, data);
}


/* ****************************************************** INTCLR register of one of the INTCTRL Units ******************************************************* */

/** Offset of the INTCLR register from the base address of the INTCTRL Unit. */
#define ATON_INTCTRL_INTCLR_OFFSET  0x10UL

/** Reset value of the INTCLR register of the INTCTRL Unit. */
#define ATON_INTCTRL_INTCLR_DT \
  (ATON_INTCTRL_INTCLR_REG_DT << ATON_INTCTRL_INTCLR_REG_LSB)



/** Description of the INTCLR register. */
#define ATON_INTCTRL_INTCLR_DESC  "Clear interrupts"

/** Address of the INTCLR register of one of the INTCTRL Units. */
#define ATON_INTCTRL_INTCLR_ADDR(UNIT)  (ATON_INTCTRL_BASE(UNIT) + ATON_INTCTRL_INTCLR_OFFSET)

/** Get the content of the INTCLR register of one of the INTCTRL Units. */
#define ATON_INTCTRL_INTCLR_GET(UNIT)  (*((volatile uint32_t *)(uintptr_t)ATON_INTCTRL_INTCLR_ADDR(UNIT)))

/** Set the content of the INTCLR register of one of the INTCTRL Units. */
#define ATON_INTCTRL_INTCLR_SET(UNIT, DATA)  do { *((volatile uint32_t *)(uintptr_t)ATON_INTCTRL_INTCLR_ADDR(UNIT)) = (DATA); } while (0);


/**
 * Get the description of INTCLR register.
 *
 * \return the description of INTCLR register
 */

static inline const int8_t *ATON_INTCTRL_INTCLR_GetDesc(void)
{
  return (const int8_t *)ATON_INTCTRL_INTCLR_DESC;
}


/**
 * Get the offset of the INTCLR register.
 *
 * \return the offset of INTCLR register
 */

static inline uint32_t ATON_INTCTRL_INTCLR_GetOffset(void)
{
  return ATON_INTCTRL_INTCLR_OFFSET;
}


/**
 * Get the address of the INTCLR register.
 *
 * \param[in] instance is the index of the Unit (among the INTCTRL Units) containing the INTCLR register whose address must be returned
 *                     (it must be <em>instance \< 1<\em>)
 *
 * \return the address of INTCLR register belonging to Unit having index \e instance among the INTCTRL Units
 */

static inline uint32_t ATON_INTCTRL_INTCLR_GetAddr(uint32_t instance)
{
  return ATON_INTCTRL_INTCLR_ADDR(instance);
}


/**
 * Read the content of the INTCLR register.
 *
 * \param[in] instance is the index of the Unit (among the INTCTRL Units) containing the INTCLR register whose content must be retrieved
 *                     (it must be <em>instance \< 1<\em>)
 *
 * \return the content of INTCLR register belonging to Unit having index \e instance among the INTCTRL Units
 */

static inline uint32_t ATON_INTCTRL_INTCLR_Get(uint32_t instance)
{
  return ATON_INTCTRL_INTCLR_GET(instance);
}


/**
 * Write the content of the INTCLR register.
 *
 * \param[in] instance is the index of the Unit (among the INTCTRL Units) containing the INTCLR register whose content must be modified
 *                     (it must be <em>instance \< 1<\em>)
 * \param[in] data     is 32-bit value that must be written to the register
 */

static inline void ATON_INTCTRL_INTCLR_Set(uint32_t instance, uint32_t data)
{
  ATON_INTCTRL_INTCLR_SET(instance, data);
}


/* ------------------------------------------------------------ REG field of the INTCLR register ------------------------------------------------------------ */

/** Description of the REG field of the INTCLR register. */
#define ATON_INTCTRL_INTCLR_REG_DESC  "If bit X is set, interrupt X is cleared. Reading this register returns same content as INTREG"

/** Offset of the REG field of the INTCLR register. */
#define ATON_INTCTRL_INTCLR_REG_LSB  0UL

/** Size in bits of the REG field of the INTCLR register. */
#define ATON_INTCTRL_INTCLR_REG_W  (32UL)

/** Mask for retrieving the REG field of the INTCLR register. */
#define ATON_INTCTRL_INTCLR_REG_MASK  ATON_FIELD_MASK(0UL, 32UL)

/** Reset value of the REG field of the INTCLR register. */
#define ATON_INTCTRL_INTCLR_REG_DT  0x0UL

/** Access rights of the REG field of the INTCLR register. */
#define ATON_INTCTRL_INTCLR_REG_AC  "RW"

/** Check whether access to the REG field of the INTCLR register is secured or not. */
#define ATON_INTCTRL_INTCLR_REG_S  0

/** Check whether access to the REG field of the INTCLR register is privileged or not. */
#define ATON_INTCTRL_INTCLR_REG_P  0

/** Read the content of the REG field of the INTCLR register. */
#define ATON_INTCTRL_INTCLR_GET_REG(REG)  ATON_GET_FIELD(REG, ATON_INTCTRL_INTCLR_REG_LSB, ATON_INTCTRL_INTCLR_REG_W)

/** Modify the content of the REG field of the INTCLR register. */
#define ATON_INTCTRL_INTCLR_SET_REG(REG, DATA)  ATON_SET_FIELD(REG, ATON_INTCTRL_INTCLR_REG_LSB, ATON_INTCTRL_INTCLR_REG_W, DATA)


/**
 * Get the description of the REG field of INTCLR register.
 *
 * \return the description of the REG field of INTCLR register
 */

static inline const int8_t *ATON_INTCTRL_INTCLR_REG_GetdDesc(void)
{
  return (const int8_t *)ATON_INTCTRL_INTCLR_REG_DESC;
}


/**
 * Read the content of the REG field of the INTCLR register.
 *
 * \param[in] reg is the value of the INTCLR register
 *
 * \return the content of the REG field belonging to INTCLR register
 */

static inline uint32_t ATON_INTCTRL_INTCLR_Get_REG(uint32_t reg)
{
  return ATON_INTCTRL_INTCLR_GET_REG(reg);
}


/**
 * Write the content of the REG field of the INTCLR register.
 *
 * \param[in] reg  is the value of the INTCLR register
 * \param[in] data is 32-bit value that must be written to the field
 *
 * \return the new content of the REG field belonging to INTCLR register
 */

static inline uint32_t ATON_INTCTRL_INTCLR_Set_REG(uint32_t reg, uint32_t data)
{
  return ATON_INTCTRL_INTCLR_SET_REG(reg, data);
}


/* ***************************************************** INTORMSK0 register of one of the INTCTRL Units ***************************************************** */

/** Offset of the INTORMSK0 register from the base address of the INTCTRL Unit. */
#define ATON_INTCTRL_INTORMSK0_OFFSET  0x14UL

/** Reset value of the INTORMSK0 register of the INTCTRL Unit. */
#define ATON_INTCTRL_INTORMSK0_DT \
  (ATON_INTCTRL_INTORMSK0_REG_DT << ATON_INTCTRL_INTORMSK0_REG_LSB)



/** Description of the INTORMSK0 register. */
#define ATON_INTCTRL_INTORMSK0_DESC  "Interrupt OR mask 0"

/** Address of the INTORMSK0 register of one of the INTCTRL Units. */
#define ATON_INTCTRL_INTORMSK0_ADDR(UNIT)  (ATON_INTCTRL_BASE(UNIT) + ATON_INTCTRL_INTORMSK0_OFFSET)

/** Get the content of the INTORMSK0 register of one of the INTCTRL Units. */
#define ATON_INTCTRL_INTORMSK0_GET(UNIT)  (*((volatile uint32_t *)(uintptr_t)ATON_INTCTRL_INTORMSK0_ADDR(UNIT)))

/** Set the content of the INTORMSK0 register of one of the INTCTRL Units. */
#define ATON_INTCTRL_INTORMSK0_SET(UNIT, DATA)  do { *((volatile uint32_t *)(uintptr_t)ATON_INTCTRL_INTORMSK0_ADDR(UNIT)) = (DATA); } while (0);


/**
 * Get the description of INTORMSK0 register.
 *
 * \return the description of INTORMSK0 register
 */

static inline const int8_t *ATON_INTCTRL_INTORMSK0_GetDesc(void)
{
  return (const int8_t *)ATON_INTCTRL_INTORMSK0_DESC;
}


/**
 * Get the offset of the INTORMSK0 register.
 *
 * \return the offset of INTORMSK0 register
 */

static inline uint32_t ATON_INTCTRL_INTORMSK0_GetOffset(void)
{
  return ATON_INTCTRL_INTORMSK0_OFFSET;
}


/**
 * Get the address of the INTORMSK0 register.
 *
 * \param[in] instance is the index of the Unit (among the INTCTRL Units) containing the INTORMSK0 register whose address must be returned
 *                     (it must be <em>instance \< 1<\em>)
 *
 * \return the address of INTORMSK0 register belonging to Unit having index \e instance among the INTCTRL Units
 */

static inline uint32_t ATON_INTCTRL_INTORMSK0_GetAddr(uint32_t instance)
{
  return ATON_INTCTRL_INTORMSK0_ADDR(instance);
}


/**
 * Read the content of the INTORMSK0 register.
 *
 * \param[in] instance is the index of the Unit (among the INTCTRL Units) containing the INTORMSK0 register whose content must be retrieved
 *                     (it must be <em>instance \< 1<\em>)
 *
 * \return the content of INTORMSK0 register belonging to Unit having index \e instance among the INTCTRL Units
 */

static inline uint32_t ATON_INTCTRL_INTORMSK0_Get(uint32_t instance)
{
  return ATON_INTCTRL_INTORMSK0_GET(instance);
}


/**
 * Write the content of the INTORMSK0 register.
 *
 * \param[in] instance is the index of the Unit (among the INTCTRL Units) containing the INTORMSK0 register whose content must be modified
 *                     (it must be <em>instance \< 1<\em>)
 * \param[in] data     is 32-bit value that must be written to the register
 */

static inline void ATON_INTCTRL_INTORMSK0_Set(uint32_t instance, uint32_t data)
{
  ATON_INTCTRL_INTORMSK0_SET(instance, data);
}


/* ---------------------------------------------------------- REG field of the INTORMSK0 register ----------------------------------------------------------- */

/** Description of the REG field of the INTORMSK0 register. */
#define ATON_INTCTRL_INTORMSK0_REG_DESC  "If bit X is set, interrupt X on OR related interrupt line is masked for ARM host"

/** Offset of the REG field of the INTORMSK0 register. */
#define ATON_INTCTRL_INTORMSK0_REG_LSB  0UL

/** Size in bits of the REG field of the INTORMSK0 register. */
#define ATON_INTCTRL_INTORMSK0_REG_W  (32UL)

/** Mask for retrieving the REG field of the INTORMSK0 register. */
#define ATON_INTCTRL_INTORMSK0_REG_MASK  ATON_FIELD_MASK(0UL, 32UL)

/** Reset value of the REG field of the INTORMSK0 register. */
#define ATON_INTCTRL_INTORMSK0_REG_DT  0xffffffffUL

/** Access rights of the REG field of the INTORMSK0 register. */
#define ATON_INTCTRL_INTORMSK0_REG_AC  "RW"

/** Check whether access to the REG field of the INTORMSK0 register is secured or not. */
#define ATON_INTCTRL_INTORMSK0_REG_S  0

/** Check whether access to the REG field of the INTORMSK0 register is privileged or not. */
#define ATON_INTCTRL_INTORMSK0_REG_P  0

/** Read the content of the REG field of the INTORMSK0 register. */
#define ATON_INTCTRL_INTORMSK0_GET_REG(REG)  ATON_GET_FIELD(REG, ATON_INTCTRL_INTORMSK0_REG_LSB, ATON_INTCTRL_INTORMSK0_REG_W)

/** Modify the content of the REG field of the INTORMSK0 register. */
#define ATON_INTCTRL_INTORMSK0_SET_REG(REG, DATA)  ATON_SET_FIELD(REG, ATON_INTCTRL_INTORMSK0_REG_LSB, ATON_INTCTRL_INTORMSK0_REG_W, DATA)


/**
 * Get the description of the REG field of INTORMSK0 register.
 *
 * \return the description of the REG field of INTORMSK0 register
 */

static inline const int8_t *ATON_INTCTRL_INTORMSK0_REG_GetdDesc(void)
{
  return (const int8_t *)ATON_INTCTRL_INTORMSK0_REG_DESC;
}


/**
 * Read the content of the REG field of the INTORMSK0 register.
 *
 * \param[in] reg is the value of the INTORMSK0 register
 *
 * \return the content of the REG field belonging to INTORMSK0 register
 */

static inline uint32_t ATON_INTCTRL_INTORMSK0_Get_REG(uint32_t reg)
{
  return ATON_INTCTRL_INTORMSK0_GET_REG(reg);
}


/**
 * Write the content of the REG field of the INTORMSK0 register.
 *
 * \param[in] reg  is the value of the INTORMSK0 register
 * \param[in] data is 32-bit value that must be written to the field
 *
 * \return the new content of the REG field belonging to INTORMSK0 register
 */

static inline uint32_t ATON_INTCTRL_INTORMSK0_Set_REG(uint32_t reg, uint32_t data)
{
  return ATON_INTCTRL_INTORMSK0_SET_REG(reg, data);
}


/* ***************************************************** INTORMSK1 register of one of the INTCTRL Units ***************************************************** */

/** Offset of the INTORMSK1 register from the base address of the INTCTRL Unit. */
#define ATON_INTCTRL_INTORMSK1_OFFSET  0x18UL

/** Reset value of the INTORMSK1 register of the INTCTRL Unit. */
#define ATON_INTCTRL_INTORMSK1_DT \
  (ATON_INTCTRL_INTORMSK1_REG_DT << ATON_INTCTRL_INTORMSK1_REG_LSB)



/** Description of the INTORMSK1 register. */
#define ATON_INTCTRL_INTORMSK1_DESC  "Interrupt OR mask 1"

/** Address of the INTORMSK1 register of one of the INTCTRL Units. */
#define ATON_INTCTRL_INTORMSK1_ADDR(UNIT)  (ATON_INTCTRL_BASE(UNIT) + ATON_INTCTRL_INTORMSK1_OFFSET)

/** Get the content of the INTORMSK1 register of one of the INTCTRL Units. */
#define ATON_INTCTRL_INTORMSK1_GET(UNIT)  (*((volatile uint32_t *)(uintptr_t)ATON_INTCTRL_INTORMSK1_ADDR(UNIT)))

/** Set the content of the INTORMSK1 register of one of the INTCTRL Units. */
#define ATON_INTCTRL_INTORMSK1_SET(UNIT, DATA)  do { *((volatile uint32_t *)(uintptr_t)ATON_INTCTRL_INTORMSK1_ADDR(UNIT)) = (DATA); } while (0);


/**
 * Get the description of INTORMSK1 register.
 *
 * \return the description of INTORMSK1 register
 */

static inline const int8_t *ATON_INTCTRL_INTORMSK1_GetDesc(void)
{
  return (const int8_t *)ATON_INTCTRL_INTORMSK1_DESC;
}


/**
 * Get the offset of the INTORMSK1 register.
 *
 * \return the offset of INTORMSK1 register
 */

static inline uint32_t ATON_INTCTRL_INTORMSK1_GetOffset(void)
{
  return ATON_INTCTRL_INTORMSK1_OFFSET;
}


/**
 * Get the address of the INTORMSK1 register.
 *
 * \param[in] instance is the index of the Unit (among the INTCTRL Units) containing the INTORMSK1 register whose address must be returned
 *                     (it must be <em>instance \< 1<\em>)
 *
 * \return the address of INTORMSK1 register belonging to Unit having index \e instance among the INTCTRL Units
 */

static inline uint32_t ATON_INTCTRL_INTORMSK1_GetAddr(uint32_t instance)
{
  return ATON_INTCTRL_INTORMSK1_ADDR(instance);
}


/**
 * Read the content of the INTORMSK1 register.
 *
 * \param[in] instance is the index of the Unit (among the INTCTRL Units) containing the INTORMSK1 register whose content must be retrieved
 *                     (it must be <em>instance \< 1<\em>)
 *
 * \return the content of INTORMSK1 register belonging to Unit having index \e instance among the INTCTRL Units
 */

static inline uint32_t ATON_INTCTRL_INTORMSK1_Get(uint32_t instance)
{
  return ATON_INTCTRL_INTORMSK1_GET(instance);
}


/**
 * Write the content of the INTORMSK1 register.
 *
 * \param[in] instance is the index of the Unit (among the INTCTRL Units) containing the INTORMSK1 register whose content must be modified
 *                     (it must be <em>instance \< 1<\em>)
 * \param[in] data     is 32-bit value that must be written to the register
 */

static inline void ATON_INTCTRL_INTORMSK1_Set(uint32_t instance, uint32_t data)
{
  ATON_INTCTRL_INTORMSK1_SET(instance, data);
}


/* ---------------------------------------------------------- REG field of the INTORMSK1 register ----------------------------------------------------------- */

/** Description of the REG field of the INTORMSK1 register. */
#define ATON_INTCTRL_INTORMSK1_REG_DESC  "If bit X is set, interrupt X on OR related interrupt line is masked for ARM host"

/** Offset of the REG field of the INTORMSK1 register. */
#define ATON_INTCTRL_INTORMSK1_REG_LSB  0UL

/** Size in bits of the REG field of the INTORMSK1 register. */
#define ATON_INTCTRL_INTORMSK1_REG_W  (32UL)

/** Mask for retrieving the REG field of the INTORMSK1 register. */
#define ATON_INTCTRL_INTORMSK1_REG_MASK  ATON_FIELD_MASK(0UL, 32UL)

/** Reset value of the REG field of the INTORMSK1 register. */
#define ATON_INTCTRL_INTORMSK1_REG_DT  0xffffffffUL

/** Access rights of the REG field of the INTORMSK1 register. */
#define ATON_INTCTRL_INTORMSK1_REG_AC  "RW"

/** Check whether access to the REG field of the INTORMSK1 register is secured or not. */
#define ATON_INTCTRL_INTORMSK1_REG_S  0

/** Check whether access to the REG field of the INTORMSK1 register is privileged or not. */
#define ATON_INTCTRL_INTORMSK1_REG_P  0

/** Read the content of the REG field of the INTORMSK1 register. */
#define ATON_INTCTRL_INTORMSK1_GET_REG(REG)  ATON_GET_FIELD(REG, ATON_INTCTRL_INTORMSK1_REG_LSB, ATON_INTCTRL_INTORMSK1_REG_W)

/** Modify the content of the REG field of the INTORMSK1 register. */
#define ATON_INTCTRL_INTORMSK1_SET_REG(REG, DATA)  ATON_SET_FIELD(REG, ATON_INTCTRL_INTORMSK1_REG_LSB, ATON_INTCTRL_INTORMSK1_REG_W, DATA)


/**
 * Get the description of the REG field of INTORMSK1 register.
 *
 * \return the description of the REG field of INTORMSK1 register
 */

static inline const int8_t *ATON_INTCTRL_INTORMSK1_REG_GetdDesc(void)
{
  return (const int8_t *)ATON_INTCTRL_INTORMSK1_REG_DESC;
}


/**
 * Read the content of the REG field of the INTORMSK1 register.
 *
 * \param[in] reg is the value of the INTORMSK1 register
 *
 * \return the content of the REG field belonging to INTORMSK1 register
 */

static inline uint32_t ATON_INTCTRL_INTORMSK1_Get_REG(uint32_t reg)
{
  return ATON_INTCTRL_INTORMSK1_GET_REG(reg);
}


/**
 * Write the content of the REG field of the INTORMSK1 register.
 *
 * \param[in] reg  is the value of the INTORMSK1 register
 * \param[in] data is 32-bit value that must be written to the field
 *
 * \return the new content of the REG field belonging to INTORMSK1 register
 */

static inline uint32_t ATON_INTCTRL_INTORMSK1_Set_REG(uint32_t reg, uint32_t data)
{
  return ATON_INTCTRL_INTORMSK1_SET_REG(reg, data);
}


/* ***************************************************** INTORMSK2 register of one of the INTCTRL Units ***************************************************** */

/** Offset of the INTORMSK2 register from the base address of the INTCTRL Unit. */
#define ATON_INTCTRL_INTORMSK2_OFFSET  0x1cUL

/** Reset value of the INTORMSK2 register of the INTCTRL Unit. */
#define ATON_INTCTRL_INTORMSK2_DT \
  (ATON_INTCTRL_INTORMSK2_REG_DT << ATON_INTCTRL_INTORMSK2_REG_LSB)



/** Description of the INTORMSK2 register. */
#define ATON_INTCTRL_INTORMSK2_DESC  "Interrupt OR mask 2"

/** Address of the INTORMSK2 register of one of the INTCTRL Units. */
#define ATON_INTCTRL_INTORMSK2_ADDR(UNIT)  (ATON_INTCTRL_BASE(UNIT) + ATON_INTCTRL_INTORMSK2_OFFSET)

/** Get the content of the INTORMSK2 register of one of the INTCTRL Units. */
#define ATON_INTCTRL_INTORMSK2_GET(UNIT)  (*((volatile uint32_t *)(uintptr_t)ATON_INTCTRL_INTORMSK2_ADDR(UNIT)))

/** Set the content of the INTORMSK2 register of one of the INTCTRL Units. */
#define ATON_INTCTRL_INTORMSK2_SET(UNIT, DATA)  do { *((volatile uint32_t *)(uintptr_t)ATON_INTCTRL_INTORMSK2_ADDR(UNIT)) = (DATA); } while (0);


/**
 * Get the description of INTORMSK2 register.
 *
 * \return the description of INTORMSK2 register
 */

static inline const int8_t *ATON_INTCTRL_INTORMSK2_GetDesc(void)
{
  return (const int8_t *)ATON_INTCTRL_INTORMSK2_DESC;
}


/**
 * Get the offset of the INTORMSK2 register.
 *
 * \return the offset of INTORMSK2 register
 */

static inline uint32_t ATON_INTCTRL_INTORMSK2_GetOffset(void)
{
  return ATON_INTCTRL_INTORMSK2_OFFSET;
}


/**
 * Get the address of the INTORMSK2 register.
 *
 * \param[in] instance is the index of the Unit (among the INTCTRL Units) containing the INTORMSK2 register whose address must be returned
 *                     (it must be <em>instance \< 1<\em>)
 *
 * \return the address of INTORMSK2 register belonging to Unit having index \e instance among the INTCTRL Units
 */

static inline uint32_t ATON_INTCTRL_INTORMSK2_GetAddr(uint32_t instance)
{
  return ATON_INTCTRL_INTORMSK2_ADDR(instance);
}


/**
 * Read the content of the INTORMSK2 register.
 *
 * \param[in] instance is the index of the Unit (among the INTCTRL Units) containing the INTORMSK2 register whose content must be retrieved
 *                     (it must be <em>instance \< 1<\em>)
 *
 * \return the content of INTORMSK2 register belonging to Unit having index \e instance among the INTCTRL Units
 */

static inline uint32_t ATON_INTCTRL_INTORMSK2_Get(uint32_t instance)
{
  return ATON_INTCTRL_INTORMSK2_GET(instance);
}


/**
 * Write the content of the INTORMSK2 register.
 *
 * \param[in] instance is the index of the Unit (among the INTCTRL Units) containing the INTORMSK2 register whose content must be modified
 *                     (it must be <em>instance \< 1<\em>)
 * \param[in] data     is 32-bit value that must be written to the register
 */

static inline void ATON_INTCTRL_INTORMSK2_Set(uint32_t instance, uint32_t data)
{
  ATON_INTCTRL_INTORMSK2_SET(instance, data);
}


/* ---------------------------------------------------------- REG field of the INTORMSK2 register ----------------------------------------------------------- */

/** Description of the REG field of the INTORMSK2 register. */
#define ATON_INTCTRL_INTORMSK2_REG_DESC  "If bit X is set, interrupt X on OR related interrupt line is masked for ARM host"

/** Offset of the REG field of the INTORMSK2 register. */
#define ATON_INTCTRL_INTORMSK2_REG_LSB  0UL

/** Size in bits of the REG field of the INTORMSK2 register. */
#define ATON_INTCTRL_INTORMSK2_REG_W  (32UL)

/** Mask for retrieving the REG field of the INTORMSK2 register. */
#define ATON_INTCTRL_INTORMSK2_REG_MASK  ATON_FIELD_MASK(0UL, 32UL)

/** Reset value of the REG field of the INTORMSK2 register. */
#define ATON_INTCTRL_INTORMSK2_REG_DT  0xffffffffUL

/** Access rights of the REG field of the INTORMSK2 register. */
#define ATON_INTCTRL_INTORMSK2_REG_AC  "RW"

/** Check whether access to the REG field of the INTORMSK2 register is secured or not. */
#define ATON_INTCTRL_INTORMSK2_REG_S  0

/** Check whether access to the REG field of the INTORMSK2 register is privileged or not. */
#define ATON_INTCTRL_INTORMSK2_REG_P  0

/** Read the content of the REG field of the INTORMSK2 register. */
#define ATON_INTCTRL_INTORMSK2_GET_REG(REG)  ATON_GET_FIELD(REG, ATON_INTCTRL_INTORMSK2_REG_LSB, ATON_INTCTRL_INTORMSK2_REG_W)

/** Modify the content of the REG field of the INTORMSK2 register. */
#define ATON_INTCTRL_INTORMSK2_SET_REG(REG, DATA)  ATON_SET_FIELD(REG, ATON_INTCTRL_INTORMSK2_REG_LSB, ATON_INTCTRL_INTORMSK2_REG_W, DATA)


/**
 * Get the description of the REG field of INTORMSK2 register.
 *
 * \return the description of the REG field of INTORMSK2 register
 */

static inline const int8_t *ATON_INTCTRL_INTORMSK2_REG_GetdDesc(void)
{
  return (const int8_t *)ATON_INTCTRL_INTORMSK2_REG_DESC;
}


/**
 * Read the content of the REG field of the INTORMSK2 register.
 *
 * \param[in] reg is the value of the INTORMSK2 register
 *
 * \return the content of the REG field belonging to INTORMSK2 register
 */

static inline uint32_t ATON_INTCTRL_INTORMSK2_Get_REG(uint32_t reg)
{
  return ATON_INTCTRL_INTORMSK2_GET_REG(reg);
}


/**
 * Write the content of the REG field of the INTORMSK2 register.
 *
 * \param[in] reg  is the value of the INTORMSK2 register
 * \param[in] data is 32-bit value that must be written to the field
 *
 * \return the new content of the REG field belonging to INTORMSK2 register
 */

static inline uint32_t ATON_INTCTRL_INTORMSK2_Set_REG(uint32_t reg, uint32_t data)
{
  return ATON_INTCTRL_INTORMSK2_SET_REG(reg, data);
}


/* ***************************************************** INTORMSK3 register of one of the INTCTRL Units ***************************************************** */

/** Offset of the INTORMSK3 register from the base address of the INTCTRL Unit. */
#define ATON_INTCTRL_INTORMSK3_OFFSET  0x20UL

/** Reset value of the INTORMSK3 register of the INTCTRL Unit. */
#define ATON_INTCTRL_INTORMSK3_DT \
  (ATON_INTCTRL_INTORMSK3_REG_DT << ATON_INTCTRL_INTORMSK3_REG_LSB)



/** Description of the INTORMSK3 register. */
#define ATON_INTCTRL_INTORMSK3_DESC  "Interrupt OR mask 3"

/** Address of the INTORMSK3 register of one of the INTCTRL Units. */
#define ATON_INTCTRL_INTORMSK3_ADDR(UNIT)  (ATON_INTCTRL_BASE(UNIT) + ATON_INTCTRL_INTORMSK3_OFFSET)

/** Get the content of the INTORMSK3 register of one of the INTCTRL Units. */
#define ATON_INTCTRL_INTORMSK3_GET(UNIT)  (*((volatile uint32_t *)(uintptr_t)ATON_INTCTRL_INTORMSK3_ADDR(UNIT)))

/** Set the content of the INTORMSK3 register of one of the INTCTRL Units. */
#define ATON_INTCTRL_INTORMSK3_SET(UNIT, DATA)  do { *((volatile uint32_t *)(uintptr_t)ATON_INTCTRL_INTORMSK3_ADDR(UNIT)) = (DATA); } while (0);


/**
 * Get the description of INTORMSK3 register.
 *
 * \return the description of INTORMSK3 register
 */

static inline const int8_t *ATON_INTCTRL_INTORMSK3_GetDesc(void)
{
  return (const int8_t *)ATON_INTCTRL_INTORMSK3_DESC;
}


/**
 * Get the offset of the INTORMSK3 register.
 *
 * \return the offset of INTORMSK3 register
 */

static inline uint32_t ATON_INTCTRL_INTORMSK3_GetOffset(void)
{
  return ATON_INTCTRL_INTORMSK3_OFFSET;
}


/**
 * Get the address of the INTORMSK3 register.
 *
 * \param[in] instance is the index of the Unit (among the INTCTRL Units) containing the INTORMSK3 register whose address must be returned
 *                     (it must be <em>instance \< 1<\em>)
 *
 * \return the address of INTORMSK3 register belonging to Unit having index \e instance among the INTCTRL Units
 */

static inline uint32_t ATON_INTCTRL_INTORMSK3_GetAddr(uint32_t instance)
{
  return ATON_INTCTRL_INTORMSK3_ADDR(instance);
}


/**
 * Read the content of the INTORMSK3 register.
 *
 * \param[in] instance is the index of the Unit (among the INTCTRL Units) containing the INTORMSK3 register whose content must be retrieved
 *                     (it must be <em>instance \< 1<\em>)
 *
 * \return the content of INTORMSK3 register belonging to Unit having index \e instance among the INTCTRL Units
 */

static inline uint32_t ATON_INTCTRL_INTORMSK3_Get(uint32_t instance)
{
  return ATON_INTCTRL_INTORMSK3_GET(instance);
}


/**
 * Write the content of the INTORMSK3 register.
 *
 * \param[in] instance is the index of the Unit (among the INTCTRL Units) containing the INTORMSK3 register whose content must be modified
 *                     (it must be <em>instance \< 1<\em>)
 * \param[in] data     is 32-bit value that must be written to the register
 */

static inline void ATON_INTCTRL_INTORMSK3_Set(uint32_t instance, uint32_t data)
{
  ATON_INTCTRL_INTORMSK3_SET(instance, data);
}


/* ---------------------------------------------------------- REG field of the INTORMSK3 register ----------------------------------------------------------- */

/** Description of the REG field of the INTORMSK3 register. */
#define ATON_INTCTRL_INTORMSK3_REG_DESC  "If bit X is set, interrupt X on OR related interrupt line is masked for ARM host"

/** Offset of the REG field of the INTORMSK3 register. */
#define ATON_INTCTRL_INTORMSK3_REG_LSB  0UL

/** Size in bits of the REG field of the INTORMSK3 register. */
#define ATON_INTCTRL_INTORMSK3_REG_W  (32UL)

/** Mask for retrieving the REG field of the INTORMSK3 register. */
#define ATON_INTCTRL_INTORMSK3_REG_MASK  ATON_FIELD_MASK(0UL, 32UL)

/** Reset value of the REG field of the INTORMSK3 register. */
#define ATON_INTCTRL_INTORMSK3_REG_DT  0xffffffffUL

/** Access rights of the REG field of the INTORMSK3 register. */
#define ATON_INTCTRL_INTORMSK3_REG_AC  "RW"

/** Check whether access to the REG field of the INTORMSK3 register is secured or not. */
#define ATON_INTCTRL_INTORMSK3_REG_S  0

/** Check whether access to the REG field of the INTORMSK3 register is privileged or not. */
#define ATON_INTCTRL_INTORMSK3_REG_P  0

/** Read the content of the REG field of the INTORMSK3 register. */
#define ATON_INTCTRL_INTORMSK3_GET_REG(REG)  ATON_GET_FIELD(REG, ATON_INTCTRL_INTORMSK3_REG_LSB, ATON_INTCTRL_INTORMSK3_REG_W)

/** Modify the content of the REG field of the INTORMSK3 register. */
#define ATON_INTCTRL_INTORMSK3_SET_REG(REG, DATA)  ATON_SET_FIELD(REG, ATON_INTCTRL_INTORMSK3_REG_LSB, ATON_INTCTRL_INTORMSK3_REG_W, DATA)


/**
 * Get the description of the REG field of INTORMSK3 register.
 *
 * \return the description of the REG field of INTORMSK3 register
 */

static inline const int8_t *ATON_INTCTRL_INTORMSK3_REG_GetdDesc(void)
{
  return (const int8_t *)ATON_INTCTRL_INTORMSK3_REG_DESC;
}


/**
 * Read the content of the REG field of the INTORMSK3 register.
 *
 * \param[in] reg is the value of the INTORMSK3 register
 *
 * \return the content of the REG field belonging to INTORMSK3 register
 */

static inline uint32_t ATON_INTCTRL_INTORMSK3_Get_REG(uint32_t reg)
{
  return ATON_INTCTRL_INTORMSK3_GET_REG(reg);
}


/**
 * Write the content of the REG field of the INTORMSK3 register.
 *
 * \param[in] reg  is the value of the INTORMSK3 register
 * \param[in] data is 32-bit value that must be written to the field
 *
 * \return the new content of the REG field belonging to INTORMSK3 register
 */

static inline uint32_t ATON_INTCTRL_INTORMSK3_Set_REG(uint32_t reg, uint32_t data)
{
  return ATON_INTCTRL_INTORMSK3_SET_REG(reg, data);
}


/* **************************************************** INTANDMSK0 register of one of the INTCTRL Units ***************************************************** */

/** Offset of the INTANDMSK0 register from the base address of the INTCTRL Unit. */
#define ATON_INTCTRL_INTANDMSK0_OFFSET  0x24UL

/** Reset value of the INTANDMSK0 register of the INTCTRL Unit. */
#define ATON_INTCTRL_INTANDMSK0_DT \
  (ATON_INTCTRL_INTANDMSK0_REG_DT << ATON_INTCTRL_INTANDMSK0_REG_LSB)



/** Description of the INTANDMSK0 register. */
#define ATON_INTCTRL_INTANDMSK0_DESC  "Interrupt AND mask 0"

/** Address of the INTANDMSK0 register of one of the INTCTRL Units. */
#define ATON_INTCTRL_INTANDMSK0_ADDR(UNIT)  (ATON_INTCTRL_BASE(UNIT) + ATON_INTCTRL_INTANDMSK0_OFFSET)

/** Get the content of the INTANDMSK0 register of one of the INTCTRL Units. */
#define ATON_INTCTRL_INTANDMSK0_GET(UNIT)  (*((volatile uint32_t *)(uintptr_t)ATON_INTCTRL_INTANDMSK0_ADDR(UNIT)))

/** Set the content of the INTANDMSK0 register of one of the INTCTRL Units. */
#define ATON_INTCTRL_INTANDMSK0_SET(UNIT, DATA)  do { *((volatile uint32_t *)(uintptr_t)ATON_INTCTRL_INTANDMSK0_ADDR(UNIT)) = (DATA); } while (0);


/**
 * Get the description of INTANDMSK0 register.
 *
 * \return the description of INTANDMSK0 register
 */

static inline const int8_t *ATON_INTCTRL_INTANDMSK0_GetDesc(void)
{
  return (const int8_t *)ATON_INTCTRL_INTANDMSK0_DESC;
}


/**
 * Get the offset of the INTANDMSK0 register.
 *
 * \return the offset of INTANDMSK0 register
 */

static inline uint32_t ATON_INTCTRL_INTANDMSK0_GetOffset(void)
{
  return ATON_INTCTRL_INTANDMSK0_OFFSET;
}


/**
 * Get the address of the INTANDMSK0 register.
 *
 * \param[in] instance is the index of the Unit (among the INTCTRL Units) containing the INTANDMSK0 register whose address must be returned
 *                     (it must be <em>instance \< 1<\em>)
 *
 * \return the address of INTANDMSK0 register belonging to Unit having index \e instance among the INTCTRL Units
 */

static inline uint32_t ATON_INTCTRL_INTANDMSK0_GetAddr(uint32_t instance)
{
  return ATON_INTCTRL_INTANDMSK0_ADDR(instance);
}


/**
 * Read the content of the INTANDMSK0 register.
 *
 * \param[in] instance is the index of the Unit (among the INTCTRL Units) containing the INTANDMSK0 register whose content must be retrieved
 *                     (it must be <em>instance \< 1<\em>)
 *
 * \return the content of INTANDMSK0 register belonging to Unit having index \e instance among the INTCTRL Units
 */

static inline uint32_t ATON_INTCTRL_INTANDMSK0_Get(uint32_t instance)
{
  return ATON_INTCTRL_INTANDMSK0_GET(instance);
}


/**
 * Write the content of the INTANDMSK0 register.
 *
 * \param[in] instance is the index of the Unit (among the INTCTRL Units) containing the INTANDMSK0 register whose content must be modified
 *                     (it must be <em>instance \< 1<\em>)
 * \param[in] data     is 32-bit value that must be written to the register
 */

static inline void ATON_INTCTRL_INTANDMSK0_Set(uint32_t instance, uint32_t data)
{
  ATON_INTCTRL_INTANDMSK0_SET(instance, data);
}


/* ---------------------------------------------------------- REG field of the INTANDMSK0 register ---------------------------------------------------------- */

/** Description of the REG field of the INTANDMSK0 register. */
#define ATON_INTCTRL_INTANDMSK0_REG_DESC  "If bit X is set, interrupt X on AND related interrupt line is masked for ARM host"

/** Offset of the REG field of the INTANDMSK0 register. */
#define ATON_INTCTRL_INTANDMSK0_REG_LSB  0UL

/** Size in bits of the REG field of the INTANDMSK0 register. */
#define ATON_INTCTRL_INTANDMSK0_REG_W  (32UL)

/** Mask for retrieving the REG field of the INTANDMSK0 register. */
#define ATON_INTCTRL_INTANDMSK0_REG_MASK  ATON_FIELD_MASK(0UL, 32UL)

/** Reset value of the REG field of the INTANDMSK0 register. */
#define ATON_INTCTRL_INTANDMSK0_REG_DT  0xffffffffUL

/** Access rights of the REG field of the INTANDMSK0 register. */
#define ATON_INTCTRL_INTANDMSK0_REG_AC  "RW"

/** Check whether access to the REG field of the INTANDMSK0 register is secured or not. */
#define ATON_INTCTRL_INTANDMSK0_REG_S  0

/** Check whether access to the REG field of the INTANDMSK0 register is privileged or not. */
#define ATON_INTCTRL_INTANDMSK0_REG_P  0

/** Read the content of the REG field of the INTANDMSK0 register. */
#define ATON_INTCTRL_INTANDMSK0_GET_REG(REG)  ATON_GET_FIELD(REG, ATON_INTCTRL_INTANDMSK0_REG_LSB, ATON_INTCTRL_INTANDMSK0_REG_W)

/** Modify the content of the REG field of the INTANDMSK0 register. */
#define ATON_INTCTRL_INTANDMSK0_SET_REG(REG, DATA)  ATON_SET_FIELD(REG, ATON_INTCTRL_INTANDMSK0_REG_LSB, ATON_INTCTRL_INTANDMSK0_REG_W, DATA)


/**
 * Get the description of the REG field of INTANDMSK0 register.
 *
 * \return the description of the REG field of INTANDMSK0 register
 */

static inline const int8_t *ATON_INTCTRL_INTANDMSK0_REG_GetdDesc(void)
{
  return (const int8_t *)ATON_INTCTRL_INTANDMSK0_REG_DESC;
}


/**
 * Read the content of the REG field of the INTANDMSK0 register.
 *
 * \param[in] reg is the value of the INTANDMSK0 register
 *
 * \return the content of the REG field belonging to INTANDMSK0 register
 */

static inline uint32_t ATON_INTCTRL_INTANDMSK0_Get_REG(uint32_t reg)
{
  return ATON_INTCTRL_INTANDMSK0_GET_REG(reg);
}


/**
 * Write the content of the REG field of the INTANDMSK0 register.
 *
 * \param[in] reg  is the value of the INTANDMSK0 register
 * \param[in] data is 32-bit value that must be written to the field
 *
 * \return the new content of the REG field belonging to INTANDMSK0 register
 */

static inline uint32_t ATON_INTCTRL_INTANDMSK0_Set_REG(uint32_t reg, uint32_t data)
{
  return ATON_INTCTRL_INTANDMSK0_SET_REG(reg, data);
}


/* **************************************************** INTANDMSK1 register of one of the INTCTRL Units ***************************************************** */

/** Offset of the INTANDMSK1 register from the base address of the INTCTRL Unit. */
#define ATON_INTCTRL_INTANDMSK1_OFFSET  0x28UL

/** Reset value of the INTANDMSK1 register of the INTCTRL Unit. */
#define ATON_INTCTRL_INTANDMSK1_DT \
  (ATON_INTCTRL_INTANDMSK1_REG_DT << ATON_INTCTRL_INTANDMSK1_REG_LSB)



/** Description of the INTANDMSK1 register. */
#define ATON_INTCTRL_INTANDMSK1_DESC  "Interrupt AND mask 1"

/** Address of the INTANDMSK1 register of one of the INTCTRL Units. */
#define ATON_INTCTRL_INTANDMSK1_ADDR(UNIT)  (ATON_INTCTRL_BASE(UNIT) + ATON_INTCTRL_INTANDMSK1_OFFSET)

/** Get the content of the INTANDMSK1 register of one of the INTCTRL Units. */
#define ATON_INTCTRL_INTANDMSK1_GET(UNIT)  (*((volatile uint32_t *)(uintptr_t)ATON_INTCTRL_INTANDMSK1_ADDR(UNIT)))

/** Set the content of the INTANDMSK1 register of one of the INTCTRL Units. */
#define ATON_INTCTRL_INTANDMSK1_SET(UNIT, DATA)  do { *((volatile uint32_t *)(uintptr_t)ATON_INTCTRL_INTANDMSK1_ADDR(UNIT)) = (DATA); } while (0);


/**
 * Get the description of INTANDMSK1 register.
 *
 * \return the description of INTANDMSK1 register
 */

static inline const int8_t *ATON_INTCTRL_INTANDMSK1_GetDesc(void)
{
  return (const int8_t *)ATON_INTCTRL_INTANDMSK1_DESC;
}


/**
 * Get the offset of the INTANDMSK1 register.
 *
 * \return the offset of INTANDMSK1 register
 */

static inline uint32_t ATON_INTCTRL_INTANDMSK1_GetOffset(void)
{
  return ATON_INTCTRL_INTANDMSK1_OFFSET;
}


/**
 * Get the address of the INTANDMSK1 register.
 *
 * \param[in] instance is the index of the Unit (among the INTCTRL Units) containing the INTANDMSK1 register whose address must be returned
 *                     (it must be <em>instance \< 1<\em>)
 *
 * \return the address of INTANDMSK1 register belonging to Unit having index \e instance among the INTCTRL Units
 */

static inline uint32_t ATON_INTCTRL_INTANDMSK1_GetAddr(uint32_t instance)
{
  return ATON_INTCTRL_INTANDMSK1_ADDR(instance);
}


/**
 * Read the content of the INTANDMSK1 register.
 *
 * \param[in] instance is the index of the Unit (among the INTCTRL Units) containing the INTANDMSK1 register whose content must be retrieved
 *                     (it must be <em>instance \< 1<\em>)
 *
 * \return the content of INTANDMSK1 register belonging to Unit having index \e instance among the INTCTRL Units
 */

static inline uint32_t ATON_INTCTRL_INTANDMSK1_Get(uint32_t instance)
{
  return ATON_INTCTRL_INTANDMSK1_GET(instance);
}


/**
 * Write the content of the INTANDMSK1 register.
 *
 * \param[in] instance is the index of the Unit (among the INTCTRL Units) containing the INTANDMSK1 register whose content must be modified
 *                     (it must be <em>instance \< 1<\em>)
 * \param[in] data     is 32-bit value that must be written to the register
 */

static inline void ATON_INTCTRL_INTANDMSK1_Set(uint32_t instance, uint32_t data)
{
  ATON_INTCTRL_INTANDMSK1_SET(instance, data);
}


/* ---------------------------------------------------------- REG field of the INTANDMSK1 register ---------------------------------------------------------- */

/** Description of the REG field of the INTANDMSK1 register. */
#define ATON_INTCTRL_INTANDMSK1_REG_DESC  "If bit X is set, interrupt X on AND related interrupt line is masked for ARM host"

/** Offset of the REG field of the INTANDMSK1 register. */
#define ATON_INTCTRL_INTANDMSK1_REG_LSB  0UL

/** Size in bits of the REG field of the INTANDMSK1 register. */
#define ATON_INTCTRL_INTANDMSK1_REG_W  (32UL)

/** Mask for retrieving the REG field of the INTANDMSK1 register. */
#define ATON_INTCTRL_INTANDMSK1_REG_MASK  ATON_FIELD_MASK(0UL, 32UL)

/** Reset value of the REG field of the INTANDMSK1 register. */
#define ATON_INTCTRL_INTANDMSK1_REG_DT  0xffffffffUL

/** Access rights of the REG field of the INTANDMSK1 register. */
#define ATON_INTCTRL_INTANDMSK1_REG_AC  "RW"

/** Check whether access to the REG field of the INTANDMSK1 register is secured or not. */
#define ATON_INTCTRL_INTANDMSK1_REG_S  0

/** Check whether access to the REG field of the INTANDMSK1 register is privileged or not. */
#define ATON_INTCTRL_INTANDMSK1_REG_P  0

/** Read the content of the REG field of the INTANDMSK1 register. */
#define ATON_INTCTRL_INTANDMSK1_GET_REG(REG)  ATON_GET_FIELD(REG, ATON_INTCTRL_INTANDMSK1_REG_LSB, ATON_INTCTRL_INTANDMSK1_REG_W)

/** Modify the content of the REG field of the INTANDMSK1 register. */
#define ATON_INTCTRL_INTANDMSK1_SET_REG(REG, DATA)  ATON_SET_FIELD(REG, ATON_INTCTRL_INTANDMSK1_REG_LSB, ATON_INTCTRL_INTANDMSK1_REG_W, DATA)


/**
 * Get the description of the REG field of INTANDMSK1 register.
 *
 * \return the description of the REG field of INTANDMSK1 register
 */

static inline const int8_t *ATON_INTCTRL_INTANDMSK1_REG_GetdDesc(void)
{
  return (const int8_t *)ATON_INTCTRL_INTANDMSK1_REG_DESC;
}


/**
 * Read the content of the REG field of the INTANDMSK1 register.
 *
 * \param[in] reg is the value of the INTANDMSK1 register
 *
 * \return the content of the REG field belonging to INTANDMSK1 register
 */

static inline uint32_t ATON_INTCTRL_INTANDMSK1_Get_REG(uint32_t reg)
{
  return ATON_INTCTRL_INTANDMSK1_GET_REG(reg);
}


/**
 * Write the content of the REG field of the INTANDMSK1 register.
 *
 * \param[in] reg  is the value of the INTANDMSK1 register
 * \param[in] data is 32-bit value that must be written to the field
 *
 * \return the new content of the REG field belonging to INTANDMSK1 register
 */

static inline uint32_t ATON_INTCTRL_INTANDMSK1_Set_REG(uint32_t reg, uint32_t data)
{
  return ATON_INTCTRL_INTANDMSK1_SET_REG(reg, data);
}


/* **************************************************** INTANDMSK2 register of one of the INTCTRL Units ***************************************************** */

/** Offset of the INTANDMSK2 register from the base address of the INTCTRL Unit. */
#define ATON_INTCTRL_INTANDMSK2_OFFSET  0x2cUL

/** Reset value of the INTANDMSK2 register of the INTCTRL Unit. */
#define ATON_INTCTRL_INTANDMSK2_DT \
  (ATON_INTCTRL_INTANDMSK2_REG_DT << ATON_INTCTRL_INTANDMSK2_REG_LSB)



/** Description of the INTANDMSK2 register. */
#define ATON_INTCTRL_INTANDMSK2_DESC  "Interrupt AND mask 2"

/** Address of the INTANDMSK2 register of one of the INTCTRL Units. */
#define ATON_INTCTRL_INTANDMSK2_ADDR(UNIT)  (ATON_INTCTRL_BASE(UNIT) + ATON_INTCTRL_INTANDMSK2_OFFSET)

/** Get the content of the INTANDMSK2 register of one of the INTCTRL Units. */
#define ATON_INTCTRL_INTANDMSK2_GET(UNIT)  (*((volatile uint32_t *)(uintptr_t)ATON_INTCTRL_INTANDMSK2_ADDR(UNIT)))

/** Set the content of the INTANDMSK2 register of one of the INTCTRL Units. */
#define ATON_INTCTRL_INTANDMSK2_SET(UNIT, DATA)  do { *((volatile uint32_t *)(uintptr_t)ATON_INTCTRL_INTANDMSK2_ADDR(UNIT)) = (DATA); } while (0);


/**
 * Get the description of INTANDMSK2 register.
 *
 * \return the description of INTANDMSK2 register
 */

static inline const int8_t *ATON_INTCTRL_INTANDMSK2_GetDesc(void)
{
  return (const int8_t *)ATON_INTCTRL_INTANDMSK2_DESC;
}


/**
 * Get the offset of the INTANDMSK2 register.
 *
 * \return the offset of INTANDMSK2 register
 */

static inline uint32_t ATON_INTCTRL_INTANDMSK2_GetOffset(void)
{
  return ATON_INTCTRL_INTANDMSK2_OFFSET;
}


/**
 * Get the address of the INTANDMSK2 register.
 *
 * \param[in] instance is the index of the Unit (among the INTCTRL Units) containing the INTANDMSK2 register whose address must be returned
 *                     (it must be <em>instance \< 1<\em>)
 *
 * \return the address of INTANDMSK2 register belonging to Unit having index \e instance among the INTCTRL Units
 */

static inline uint32_t ATON_INTCTRL_INTANDMSK2_GetAddr(uint32_t instance)
{
  return ATON_INTCTRL_INTANDMSK2_ADDR(instance);
}


/**
 * Read the content of the INTANDMSK2 register.
 *
 * \param[in] instance is the index of the Unit (among the INTCTRL Units) containing the INTANDMSK2 register whose content must be retrieved
 *                     (it must be <em>instance \< 1<\em>)
 *
 * \return the content of INTANDMSK2 register belonging to Unit having index \e instance among the INTCTRL Units
 */

static inline uint32_t ATON_INTCTRL_INTANDMSK2_Get(uint32_t instance)
{
  return ATON_INTCTRL_INTANDMSK2_GET(instance);
}


/**
 * Write the content of the INTANDMSK2 register.
 *
 * \param[in] instance is the index of the Unit (among the INTCTRL Units) containing the INTANDMSK2 register whose content must be modified
 *                     (it must be <em>instance \< 1<\em>)
 * \param[in] data     is 32-bit value that must be written to the register
 */

static inline void ATON_INTCTRL_INTANDMSK2_Set(uint32_t instance, uint32_t data)
{
  ATON_INTCTRL_INTANDMSK2_SET(instance, data);
}


/* ---------------------------------------------------------- REG field of the INTANDMSK2 register ---------------------------------------------------------- */

/** Description of the REG field of the INTANDMSK2 register. */
#define ATON_INTCTRL_INTANDMSK2_REG_DESC  "If bit X is set, interrupt X on AND related interrupt line is masked for ARM host"

/** Offset of the REG field of the INTANDMSK2 register. */
#define ATON_INTCTRL_INTANDMSK2_REG_LSB  0UL

/** Size in bits of the REG field of the INTANDMSK2 register. */
#define ATON_INTCTRL_INTANDMSK2_REG_W  (32UL)

/** Mask for retrieving the REG field of the INTANDMSK2 register. */
#define ATON_INTCTRL_INTANDMSK2_REG_MASK  ATON_FIELD_MASK(0UL, 32UL)

/** Reset value of the REG field of the INTANDMSK2 register. */
#define ATON_INTCTRL_INTANDMSK2_REG_DT  0xffffffffUL

/** Access rights of the REG field of the INTANDMSK2 register. */
#define ATON_INTCTRL_INTANDMSK2_REG_AC  "RW"

/** Check whether access to the REG field of the INTANDMSK2 register is secured or not. */
#define ATON_INTCTRL_INTANDMSK2_REG_S  0

/** Check whether access to the REG field of the INTANDMSK2 register is privileged or not. */
#define ATON_INTCTRL_INTANDMSK2_REG_P  0

/** Read the content of the REG field of the INTANDMSK2 register. */
#define ATON_INTCTRL_INTANDMSK2_GET_REG(REG)  ATON_GET_FIELD(REG, ATON_INTCTRL_INTANDMSK2_REG_LSB, ATON_INTCTRL_INTANDMSK2_REG_W)

/** Modify the content of the REG field of the INTANDMSK2 register. */
#define ATON_INTCTRL_INTANDMSK2_SET_REG(REG, DATA)  ATON_SET_FIELD(REG, ATON_INTCTRL_INTANDMSK2_REG_LSB, ATON_INTCTRL_INTANDMSK2_REG_W, DATA)


/**
 * Get the description of the REG field of INTANDMSK2 register.
 *
 * \return the description of the REG field of INTANDMSK2 register
 */

static inline const int8_t *ATON_INTCTRL_INTANDMSK2_REG_GetdDesc(void)
{
  return (const int8_t *)ATON_INTCTRL_INTANDMSK2_REG_DESC;
}


/**
 * Read the content of the REG field of the INTANDMSK2 register.
 *
 * \param[in] reg is the value of the INTANDMSK2 register
 *
 * \return the content of the REG field belonging to INTANDMSK2 register
 */

static inline uint32_t ATON_INTCTRL_INTANDMSK2_Get_REG(uint32_t reg)
{
  return ATON_INTCTRL_INTANDMSK2_GET_REG(reg);
}


/**
 * Write the content of the REG field of the INTANDMSK2 register.
 *
 * \param[in] reg  is the value of the INTANDMSK2 register
 * \param[in] data is 32-bit value that must be written to the field
 *
 * \return the new content of the REG field belonging to INTANDMSK2 register
 */

static inline uint32_t ATON_INTCTRL_INTANDMSK2_Set_REG(uint32_t reg, uint32_t data)
{
  return ATON_INTCTRL_INTANDMSK2_SET_REG(reg, data);
}


/* **************************************************** INTANDMSK3 register of one of the INTCTRL Units ***************************************************** */

/** Offset of the INTANDMSK3 register from the base address of the INTCTRL Unit. */
#define ATON_INTCTRL_INTANDMSK3_OFFSET  0x30UL

/** Reset value of the INTANDMSK3 register of the INTCTRL Unit. */
#define ATON_INTCTRL_INTANDMSK3_DT \
  (ATON_INTCTRL_INTANDMSK3_REG_DT << ATON_INTCTRL_INTANDMSK3_REG_LSB)



/** Description of the INTANDMSK3 register. */
#define ATON_INTCTRL_INTANDMSK3_DESC  "Interrupt AND mask 3"

/** Address of the INTANDMSK3 register of one of the INTCTRL Units. */
#define ATON_INTCTRL_INTANDMSK3_ADDR(UNIT)  (ATON_INTCTRL_BASE(UNIT) + ATON_INTCTRL_INTANDMSK3_OFFSET)

/** Get the content of the INTANDMSK3 register of one of the INTCTRL Units. */
#define ATON_INTCTRL_INTANDMSK3_GET(UNIT)  (*((volatile uint32_t *)(uintptr_t)ATON_INTCTRL_INTANDMSK3_ADDR(UNIT)))

/** Set the content of the INTANDMSK3 register of one of the INTCTRL Units. */
#define ATON_INTCTRL_INTANDMSK3_SET(UNIT, DATA)  do { *((volatile uint32_t *)(uintptr_t)ATON_INTCTRL_INTANDMSK3_ADDR(UNIT)) = (DATA); } while (0);


/**
 * Get the description of INTANDMSK3 register.
 *
 * \return the description of INTANDMSK3 register
 */

static inline const int8_t *ATON_INTCTRL_INTANDMSK3_GetDesc(void)
{
  return (const int8_t *)ATON_INTCTRL_INTANDMSK3_DESC;
}


/**
 * Get the offset of the INTANDMSK3 register.
 *
 * \return the offset of INTANDMSK3 register
 */

static inline uint32_t ATON_INTCTRL_INTANDMSK3_GetOffset(void)
{
  return ATON_INTCTRL_INTANDMSK3_OFFSET;
}


/**
 * Get the address of the INTANDMSK3 register.
 *
 * \param[in] instance is the index of the Unit (among the INTCTRL Units) containing the INTANDMSK3 register whose address must be returned
 *                     (it must be <em>instance \< 1<\em>)
 *
 * \return the address of INTANDMSK3 register belonging to Unit having index \e instance among the INTCTRL Units
 */

static inline uint32_t ATON_INTCTRL_INTANDMSK3_GetAddr(uint32_t instance)
{
  return ATON_INTCTRL_INTANDMSK3_ADDR(instance);
}


/**
 * Read the content of the INTANDMSK3 register.
 *
 * \param[in] instance is the index of the Unit (among the INTCTRL Units) containing the INTANDMSK3 register whose content must be retrieved
 *                     (it must be <em>instance \< 1<\em>)
 *
 * \return the content of INTANDMSK3 register belonging to Unit having index \e instance among the INTCTRL Units
 */

static inline uint32_t ATON_INTCTRL_INTANDMSK3_Get(uint32_t instance)
{
  return ATON_INTCTRL_INTANDMSK3_GET(instance);
}


/**
 * Write the content of the INTANDMSK3 register.
 *
 * \param[in] instance is the index of the Unit (among the INTCTRL Units) containing the INTANDMSK3 register whose content must be modified
 *                     (it must be <em>instance \< 1<\em>)
 * \param[in] data     is 32-bit value that must be written to the register
 */

static inline void ATON_INTCTRL_INTANDMSK3_Set(uint32_t instance, uint32_t data)
{
  ATON_INTCTRL_INTANDMSK3_SET(instance, data);
}


/* ---------------------------------------------------------- REG field of the INTANDMSK3 register ---------------------------------------------------------- */

/** Description of the REG field of the INTANDMSK3 register. */
#define ATON_INTCTRL_INTANDMSK3_REG_DESC  "If bit X is set, interrupt X on AND related interrupt line is masked for ARM host"

/** Offset of the REG field of the INTANDMSK3 register. */
#define ATON_INTCTRL_INTANDMSK3_REG_LSB  0UL

/** Size in bits of the REG field of the INTANDMSK3 register. */
#define ATON_INTCTRL_INTANDMSK3_REG_W  (32UL)

/** Mask for retrieving the REG field of the INTANDMSK3 register. */
#define ATON_INTCTRL_INTANDMSK3_REG_MASK  ATON_FIELD_MASK(0UL, 32UL)

/** Reset value of the REG field of the INTANDMSK3 register. */
#define ATON_INTCTRL_INTANDMSK3_REG_DT  0xffffffffUL

/** Access rights of the REG field of the INTANDMSK3 register. */
#define ATON_INTCTRL_INTANDMSK3_REG_AC  "RW"

/** Check whether access to the REG field of the INTANDMSK3 register is secured or not. */
#define ATON_INTCTRL_INTANDMSK3_REG_S  0

/** Check whether access to the REG field of the INTANDMSK3 register is privileged or not. */
#define ATON_INTCTRL_INTANDMSK3_REG_P  0

/** Read the content of the REG field of the INTANDMSK3 register. */
#define ATON_INTCTRL_INTANDMSK3_GET_REG(REG)  ATON_GET_FIELD(REG, ATON_INTCTRL_INTANDMSK3_REG_LSB, ATON_INTCTRL_INTANDMSK3_REG_W)

/** Modify the content of the REG field of the INTANDMSK3 register. */
#define ATON_INTCTRL_INTANDMSK3_SET_REG(REG, DATA)  ATON_SET_FIELD(REG, ATON_INTCTRL_INTANDMSK3_REG_LSB, ATON_INTCTRL_INTANDMSK3_REG_W, DATA)


/**
 * Get the description of the REG field of INTANDMSK3 register.
 *
 * \return the description of the REG field of INTANDMSK3 register
 */

static inline const int8_t *ATON_INTCTRL_INTANDMSK3_REG_GetdDesc(void)
{
  return (const int8_t *)ATON_INTCTRL_INTANDMSK3_REG_DESC;
}


/**
 * Read the content of the REG field of the INTANDMSK3 register.
 *
 * \param[in] reg is the value of the INTANDMSK3 register
 *
 * \return the content of the REG field belonging to INTANDMSK3 register
 */

static inline uint32_t ATON_INTCTRL_INTANDMSK3_Get_REG(uint32_t reg)
{
  return ATON_INTCTRL_INTANDMSK3_GET_REG(reg);
}


/**
 * Write the content of the REG field of the INTANDMSK3 register.
 *
 * \param[in] reg  is the value of the INTANDMSK3 register
 * \param[in] data is 32-bit value that must be written to the field
 *
 * \return the new content of the REG field belonging to INTANDMSK3 register
 */

static inline uint32_t ATON_INTCTRL_INTANDMSK3_Set_REG(uint32_t reg, uint32_t data)
{
  return ATON_INTCTRL_INTANDMSK3_SET_REG(reg, data);
}


/*@}*/


/* ---------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                                                                                                                            */
/*                                                                        ACTIV Units                                                                         */
/*                                                                                                                                                            */
/* ---------------------------------------------------------------------------------------------------------------------------------------------------------- */

/** Number of ACTIV Unit instances. */
#define ATON_ACTIV_NUM 2

/**
 * \name Structures, macros and functions of the ACTIV Units
 */
/*@{*/

/**
 * Registers of the ACTIV Units
 */

typedef volatile struct
{
  /** \e CTRL register (Control register). */
  uint32_t CTRL;

  /** \e VERSION register (Version register). */
  uint32_t VERSION;

  /** \e ACTIVPARAM register (ReLU parameter for parametric ReLU or thresholded ReLU). */
  uint32_t ACTIVPARAM;

  /** \e FUNC register (Functional parameter). */
  uint32_t FUNC;

  /** \e ACTIVPARAM2 register (additional activation parameters). */
  uint32_t ACTIVPARAM2;

  /** \e FSUB register (Feature data subtract). */
  uint32_t FSUB;

} ATON_ACTIV_t;


/** Return the pointer to one of the ACTIV Units. */
#define ATON_ACTIV(UNIT) ((ATON_ACTIV_t *)(intptr_t)ATON_ACTIV_BASE(UNIT))


/** Name of one of the ACTIV Units. */
#define ATON_ACTIV_NAME(UNIT) \
  (((UNIT) == 0) ? "ACTIV0" : \
  (((UNIT) == 1) ? "ACTIV1" :  ""))


/** Version of the ACTIV Units. */
#define ATON_ACTIV_VERSION "1.1"


/** Description of one of the ACTIV Units. */
#define ATON_ACTIV_DESC(UNIT) \
  (((UNIT) == 0) ? "Activation Accelerator 0" : \
  (((UNIT) == 1) ? "Activation Accelerator 1" :  ""))


/** Base address of one of the ACTIV Units. */
#define ATON_ACTIV_BASE(UNIT) \
  (ATON_BASE + 0x15000UL + ((UNIT) * 0x1000UL))

/** Size in bytes of the ACTIV Units. */
#define ATON_ACTIV_SIZE  0x1000UL


/**
 * Get the name of one of the ACTIV Units.
 *
 * \param[in] instance is the index of the Unit whose name must be returned (it must be <em>idx \< 2<\em>)
 *
 * \return the name of Unit having index \e instance among the ACTIV Units
 */

static inline const int8_t *ATON_ACTIV_GetName(uint32_t instance)
{
  const int8_t *str = NULL;

  switch (instance)
  {
    case 0:
      str = (const int8_t *)"ACTIV0";
      break;

    case 1:
      str = (const int8_t *)"ACTIV1";
      break;

    default:
      break;
  }

  return str;
}


/**
 * Get the description of one of the ACTIV Units.
 *
 * \param[in] instance is the index of the Unit whose description must be returned (it must be <em>idx \< 2<\em>)
 *
 * \return the description of Unit having index \e instance among the ACTIV Units
 */

static inline const int8_t *ATON_ACTIV_GetDesc(uint32_t instance)
{
  const int8_t *str = NULL;

  switch (instance)
  {
    case 0:
      str = (const int8_t *)"Activation Accelerator 0";
      break;

    case 1:
      str = (const int8_t *)"Activation Accelerator 1";
      break;

    default:
      break;
  }

  return str;
}


/**
 * Get the version of the ACTIV Units.
 *
 * \return the version of the ACTIV Units
 */

static inline const int8_t *ATON_ACTIV_GetVersion(void)
{
  return (const int8_t *)ATON_ACTIV_VERSION;
}


/**
 * Get the base address of one of the ACTIV Units.
 *
 * \param[in] instance is the index of the Unit whose base address must be returned (it must be <em>idx \< 2<\em>)
 *
 * \return the base address of Unit having index \e instance among the ACTIV Units
 */

static inline uint32_t ATON_ACTIV_GetBase(uint32_t instance)
{
  return ATON_ACTIV_BASE(instance);
}


/**
 * Get the size in bytes of the ACTIV Units.
 *
 * \return the size in bytes of the ACTIV Units
 */

static inline uint32_t ATON_ACTIV_GetSize(void)
{
  return ATON_ACTIV_SIZE;
}


/* ******************************************************** CTRL register of one of the ACTIV Units ********************************************************* */

/** Offset of the CTRL register from the base address of the ACTIV Unit. */
#define ATON_ACTIV_CTRL_OFFSET  0x0UL

/** Reset value of the CTRL register of the ACTIV Unit. */
#define ATON_ACTIV_CTRL_DT \
  (ATON_ACTIV_CTRL_EN_DT       << ATON_ACTIV_CTRL_EN_LSB)       | \
  (ATON_ACTIV_CTRL_CLR_DT      << ATON_ACTIV_CTRL_CLR_LSB)      | \
  (ATON_ACTIV_CTRL_TYPE_DT     << ATON_ACTIV_CTRL_TYPE_LSB)     | \
  (ATON_ACTIV_CTRL_FBYTES_DT   << ATON_ACTIV_CTRL_FBYTES_LSB)   | \
  (ATON_ACTIV_CTRL_FSHIFT_DT   << ATON_ACTIV_CTRL_FSHIFT_LSB)   | \
  (ATON_ACTIV_CTRL_FROUND_DT   << ATON_ACTIV_CTRL_FROUND_LSB)   | \
  (ATON_ACTIV_CTRL_FSAT_DT     << ATON_ACTIV_CTRL_FSAT_LSB)     | \
  (ATON_ACTIV_CTRL_FRNDMODE_DT << ATON_ACTIV_CTRL_FRNDMODE_LSB) | \
  (ATON_ACTIV_CTRL_FOBYTES_DT  << ATON_ACTIV_CTRL_FOBYTES_LSB)  | \
  (ATON_ACTIV_CTRL_ROUND_DT    << ATON_ACTIV_CTRL_ROUND_LSB)    | \
  (ATON_ACTIV_CTRL_SAT_DT      << ATON_ACTIV_CTRL_SAT_LSB)      | \
  (ATON_ACTIV_CTRL_OBYTES_DT   << ATON_ACTIV_CTRL_OBYTES_LSB)   | \
  (ATON_ACTIV_CTRL_ORNDMODE_DT << ATON_ACTIV_CTRL_ORNDMODE_LSB) | \
  (ATON_ACTIV_CTRL_CONFCLR_DT  << ATON_ACTIV_CTRL_CONFCLR_LSB)



/** Description of the CTRL register. */
#define ATON_ACTIV_CTRL_DESC  "Control register"

/** Address of the CTRL register of one of the ACTIV Units. */
#define ATON_ACTIV_CTRL_ADDR(UNIT)  (ATON_ACTIV_BASE(UNIT) + ATON_ACTIV_CTRL_OFFSET)

/** Get the content of the CTRL register of one of the ACTIV Units. */
#define ATON_ACTIV_CTRL_GET(UNIT)  (*((volatile uint32_t *)(uintptr_t)ATON_ACTIV_CTRL_ADDR(UNIT)))

/** Set the content of the CTRL register of one of the ACTIV Units. */
#define ATON_ACTIV_CTRL_SET(UNIT, DATA)  do { *((volatile uint32_t *)(uintptr_t)ATON_ACTIV_CTRL_ADDR(UNIT)) = (DATA); } while (0);


/**
 * Get the description of CTRL register.
 *
 * \return the description of CTRL register
 */

static inline const int8_t *ATON_ACTIV_CTRL_GetDesc(void)
{
  return (const int8_t *)ATON_ACTIV_CTRL_DESC;
}


/**
 * Get the offset of the CTRL register.
 *
 * \return the offset of CTRL register
 */

static inline uint32_t ATON_ACTIV_CTRL_GetOffset(void)
{
  return ATON_ACTIV_CTRL_OFFSET;
}


/**
 * Get the address of the CTRL register.
 *
 * \param[in] instance is the index of the Unit (among the ACTIV Units) containing the CTRL register whose address must be returned
 *                     (it must be <em>instance \< 2<\em>)
 *
 * \return the address of CTRL register belonging to Unit having index \e instance among the ACTIV Units
 */

static inline uint32_t ATON_ACTIV_CTRL_GetAddr(uint32_t instance)
{
  return ATON_ACTIV_CTRL_ADDR(instance);
}


/**
 * Read the content of the CTRL register.
 *
 * \param[in] instance is the index of the Unit (among the ACTIV Units) containing the CTRL register whose content must be retrieved
 *                     (it must be <em>instance \< 2<\em>)
 *
 * \return the content of CTRL register belonging to Unit having index \e instance among the ACTIV Units
 */

static inline uint32_t ATON_ACTIV_CTRL_Get(uint32_t instance)
{
  return ATON_ACTIV_CTRL_GET(instance);
}


/**
 * Write the content of the CTRL register.
 *
 * \param[in] instance is the index of the Unit (among the ACTIV Units) containing the CTRL register whose content must be modified
 *                     (it must be <em>instance \< 2<\em>)
 * \param[in] data     is 32-bit value that must be written to the register
 */

static inline void ATON_ACTIV_CTRL_Set(uint32_t instance, uint32_t data)
{
  ATON_ACTIV_CTRL_SET(instance, data);
}


/* ------------------------------------------------------------- EN field of the CTRL register -------------------------------------------------------------- */

/** Description of the EN field of the CTRL register. */
#define ATON_ACTIV_CTRL_EN_DESC  "Enable the Activation Unit"

/** Offset of the EN field of the CTRL register. */
#define ATON_ACTIV_CTRL_EN_LSB  0UL

/** Size in bits of the EN field of the CTRL register. */
#define ATON_ACTIV_CTRL_EN_W  (1UL)

/** Mask for retrieving the EN field of the CTRL register. */
#define ATON_ACTIV_CTRL_EN_MASK  ATON_FIELD_MASK(0UL, 1UL)

/** Reset value of the EN field of the CTRL register. */
#define ATON_ACTIV_CTRL_EN_DT  0x0UL

/** Access rights of the EN field of the CTRL register. */
#define ATON_ACTIV_CTRL_EN_AC  "RW"

/** Check whether access to the EN field of the CTRL register is secured or not. */
#define ATON_ACTIV_CTRL_EN_S  0

/** Check whether access to the EN field of the CTRL register is privileged or not. */
#define ATON_ACTIV_CTRL_EN_P  0

/** Read the content of the EN field of the CTRL register. */
#define ATON_ACTIV_CTRL_GET_EN(REG)  ATON_GET_FIELD(REG, ATON_ACTIV_CTRL_EN_LSB, ATON_ACTIV_CTRL_EN_W)

/** Modify the content of the EN field of the CTRL register. */
#define ATON_ACTIV_CTRL_SET_EN(REG, DATA)  ATON_SET_FIELD(REG, ATON_ACTIV_CTRL_EN_LSB, ATON_ACTIV_CTRL_EN_W, DATA)


/**
 * Get the description of the EN field of CTRL register.
 *
 * \return the description of the EN field of CTRL register
 */

static inline const int8_t *ATON_ACTIV_CTRL_EN_GetdDesc(void)
{
  return (const int8_t *)ATON_ACTIV_CTRL_EN_DESC;
}


/**
 * Read the content of the EN field of the CTRL register.
 *
 * \param[in] reg is the value of the CTRL register
 *
 * \return the content of the EN field belonging to CTRL register
 */

static inline uint32_t ATON_ACTIV_CTRL_Get_EN(uint32_t reg)
{
  return ATON_ACTIV_CTRL_GET_EN(reg);
}


/**
 * Write the content of the EN field of the CTRL register.
 *
 * \param[in] reg  is the value of the CTRL register
 * \param[in] data is 1-bit value that must be written to the field
 *
 * \return the new content of the EN field belonging to CTRL register
 */

static inline uint32_t ATON_ACTIV_CTRL_Set_EN(uint32_t reg, uint32_t data)
{
  return ATON_ACTIV_CTRL_SET_EN(reg, data);
}


/* ------------------------------------------------------------- CLR field of the CTRL register ------------------------------------------------------------- */

/** Description of the CLR field of the CTRL register. */
#define ATON_ACTIV_CTRL_CLR_DESC  "Clear all pipeline registers"

/** Offset of the CLR field of the CTRL register. */
#define ATON_ACTIV_CTRL_CLR_LSB  1UL

/** Size in bits of the CLR field of the CTRL register. */
#define ATON_ACTIV_CTRL_CLR_W  (1UL)

/** Mask for retrieving the CLR field of the CTRL register. */
#define ATON_ACTIV_CTRL_CLR_MASK  ATON_FIELD_MASK(1UL, 1UL)

/** Reset value of the CLR field of the CTRL register. */
#define ATON_ACTIV_CTRL_CLR_DT  0x0UL

/** Access rights of the CLR field of the CTRL register. */
#define ATON_ACTIV_CTRL_CLR_AC  "RW"

/** Check whether access to the CLR field of the CTRL register is secured or not. */
#define ATON_ACTIV_CTRL_CLR_S  0

/** Check whether access to the CLR field of the CTRL register is privileged or not. */
#define ATON_ACTIV_CTRL_CLR_P  0

/** Read the content of the CLR field of the CTRL register. */
#define ATON_ACTIV_CTRL_GET_CLR(REG)  ATON_GET_FIELD(REG, ATON_ACTIV_CTRL_CLR_LSB, ATON_ACTIV_CTRL_CLR_W)

/** Modify the content of the CLR field of the CTRL register. */
#define ATON_ACTIV_CTRL_SET_CLR(REG, DATA)  ATON_SET_FIELD(REG, ATON_ACTIV_CTRL_CLR_LSB, ATON_ACTIV_CTRL_CLR_W, DATA)


/**
 * Get the description of the CLR field of CTRL register.
 *
 * \return the description of the CLR field of CTRL register
 */

static inline const int8_t *ATON_ACTIV_CTRL_CLR_GetdDesc(void)
{
  return (const int8_t *)ATON_ACTIV_CTRL_CLR_DESC;
}


/**
 * Read the content of the CLR field of the CTRL register.
 *
 * \param[in] reg is the value of the CTRL register
 *
 * \return the content of the CLR field belonging to CTRL register
 */

static inline uint32_t ATON_ACTIV_CTRL_Get_CLR(uint32_t reg)
{
  return ATON_ACTIV_CTRL_GET_CLR(reg);
}


/**
 * Write the content of the CLR field of the CTRL register.
 *
 * \param[in] reg  is the value of the CTRL register
 * \param[in] data is 1-bit value that must be written to the field
 *
 * \return the new content of the CLR field belonging to CTRL register
 */

static inline uint32_t ATON_ACTIV_CTRL_Set_CLR(uint32_t reg, uint32_t data)
{
  return ATON_ACTIV_CTRL_SET_CLR(reg, data);
}


/* ------------------------------------------------------------ TYPE field of the CTRL register ------------------------------------------------------------- */

/** Description of the TYPE field of the CTRL register. */
#define ATON_ACTIV_CTRL_TYPE_DESC  "Activation type"

/** Offset of the TYPE field of the CTRL register. */
#define ATON_ACTIV_CTRL_TYPE_LSB  2UL

/** Size in bits of the TYPE field of the CTRL register. */
#define ATON_ACTIV_CTRL_TYPE_W  (2UL)

/** Mask for retrieving the TYPE field of the CTRL register. */
#define ATON_ACTIV_CTRL_TYPE_MASK  ATON_FIELD_MASK(2UL, 2UL)

/** Reset value of the TYPE field of the CTRL register. */
#define ATON_ACTIV_CTRL_TYPE_DT  0x0UL

/** Access rights of the TYPE field of the CTRL register. */
#define ATON_ACTIV_CTRL_TYPE_AC  "RW"

/** Check whether access to the TYPE field of the CTRL register is secured or not. */
#define ATON_ACTIV_CTRL_TYPE_S  0

/** Check whether access to the TYPE field of the CTRL register is privileged or not. */
#define ATON_ACTIV_CTRL_TYPE_P  0

/** Read the content of the TYPE field of the CTRL register. */
#define ATON_ACTIV_CTRL_GET_TYPE(REG)  ATON_GET_FIELD(REG, ATON_ACTIV_CTRL_TYPE_LSB, ATON_ACTIV_CTRL_TYPE_W)

/** Modify the content of the TYPE field of the CTRL register. */
#define ATON_ACTIV_CTRL_SET_TYPE(REG, DATA)  ATON_SET_FIELD(REG, ATON_ACTIV_CTRL_TYPE_LSB, ATON_ACTIV_CTRL_TYPE_W, DATA)


/**
 * Get the description of the TYPE field of CTRL register.
 *
 * \return the description of the TYPE field of CTRL register
 */

static inline const int8_t *ATON_ACTIV_CTRL_TYPE_GetdDesc(void)
{
  return (const int8_t *)ATON_ACTIV_CTRL_TYPE_DESC;
}


/**
 * Read the content of the TYPE field of the CTRL register.
 *
 * \param[in] reg is the value of the CTRL register
 *
 * \return the content of the TYPE field belonging to CTRL register
 */

static inline uint32_t ATON_ACTIV_CTRL_Get_TYPE(uint32_t reg)
{
  return ATON_ACTIV_CTRL_GET_TYPE(reg);
}


/**
 * Write the content of the TYPE field of the CTRL register.
 *
 * \param[in] reg  is the value of the CTRL register
 * \param[in] data is 2-bit value that must be written to the field
 *
 * \return the new content of the TYPE field belonging to CTRL register
 */

static inline uint32_t ATON_ACTIV_CTRL_Set_TYPE(uint32_t reg, uint32_t data)
{
  return ATON_ACTIV_CTRL_SET_TYPE(reg, data);
}


/* ----------------------------------------------------------- FBYTES field of the CTRL register ------------------------------------------------------------ */

/** Description of the FBYTES field of the CTRL register. */
#define ATON_ACTIV_CTRL_FBYTES_DESC  "Input data width in bytes. Valid values are 1,2 or 3 bytes"

/** Offset of the FBYTES field of the CTRL register. */
#define ATON_ACTIV_CTRL_FBYTES_LSB  6UL

/** Size in bits of the FBYTES field of the CTRL register. */
#define ATON_ACTIV_CTRL_FBYTES_W  (2UL)

/** Mask for retrieving the FBYTES field of the CTRL register. */
#define ATON_ACTIV_CTRL_FBYTES_MASK  ATON_FIELD_MASK(6UL, 2UL)

/** Reset value of the FBYTES field of the CTRL register. */
#define ATON_ACTIV_CTRL_FBYTES_DT  0x2UL

/** Access rights of the FBYTES field of the CTRL register. */
#define ATON_ACTIV_CTRL_FBYTES_AC  "RW"

/** Check whether access to the FBYTES field of the CTRL register is secured or not. */
#define ATON_ACTIV_CTRL_FBYTES_S  0

/** Check whether access to the FBYTES field of the CTRL register is privileged or not. */
#define ATON_ACTIV_CTRL_FBYTES_P  0

/** Read the content of the FBYTES field of the CTRL register. */
#define ATON_ACTIV_CTRL_GET_FBYTES(REG)  ATON_GET_FIELD(REG, ATON_ACTIV_CTRL_FBYTES_LSB, ATON_ACTIV_CTRL_FBYTES_W)

/** Modify the content of the FBYTES field of the CTRL register. */
#define ATON_ACTIV_CTRL_SET_FBYTES(REG, DATA)  ATON_SET_FIELD(REG, ATON_ACTIV_CTRL_FBYTES_LSB, ATON_ACTIV_CTRL_FBYTES_W, DATA)


/**
 * Get the description of the FBYTES field of CTRL register.
 *
 * \return the description of the FBYTES field of CTRL register
 */

static inline const int8_t *ATON_ACTIV_CTRL_FBYTES_GetdDesc(void)
{
  return (const int8_t *)ATON_ACTIV_CTRL_FBYTES_DESC;
}


/**
 * Read the content of the FBYTES field of the CTRL register.
 *
 * \param[in] reg is the value of the CTRL register
 *
 * \return the content of the FBYTES field belonging to CTRL register
 */

static inline uint32_t ATON_ACTIV_CTRL_Get_FBYTES(uint32_t reg)
{
  return ATON_ACTIV_CTRL_GET_FBYTES(reg);
}


/**
 * Write the content of the FBYTES field of the CTRL register.
 *
 * \param[in] reg  is the value of the CTRL register
 * \param[in] data is 2-bit value that must be written to the field
 *
 * \return the new content of the FBYTES field belonging to CTRL register
 */

static inline uint32_t ATON_ACTIV_CTRL_Set_FBYTES(uint32_t reg, uint32_t data)
{
  return ATON_ACTIV_CTRL_SET_FBYTES(reg, data);
}


/* ----------------------------------------------------------- FSHIFT field of the CTRL register ------------------------------------------------------------ */

/** Description of the FSHIFT field of the CTRL register. */
#define ATON_ACTIV_CTRL_FSHIFT_DESC  "Input feature data shift. Range [0-40]. For no shift, set to 16"

/** Offset of the FSHIFT field of the CTRL register. */
#define ATON_ACTIV_CTRL_FSHIFT_LSB  8UL

/** Size in bits of the FSHIFT field of the CTRL register. */
#define ATON_ACTIV_CTRL_FSHIFT_W  (6UL)

/** Mask for retrieving the FSHIFT field of the CTRL register. */
#define ATON_ACTIV_CTRL_FSHIFT_MASK  ATON_FIELD_MASK(8UL, 6UL)

/** Reset value of the FSHIFT field of the CTRL register. */
#define ATON_ACTIV_CTRL_FSHIFT_DT  0x10UL

/** Access rights of the FSHIFT field of the CTRL register. */
#define ATON_ACTIV_CTRL_FSHIFT_AC  "RW"

/** Check whether access to the FSHIFT field of the CTRL register is secured or not. */
#define ATON_ACTIV_CTRL_FSHIFT_S  0

/** Check whether access to the FSHIFT field of the CTRL register is privileged or not. */
#define ATON_ACTIV_CTRL_FSHIFT_P  0

/** Read the content of the FSHIFT field of the CTRL register. */
#define ATON_ACTIV_CTRL_GET_FSHIFT(REG)  ATON_GET_FIELD(REG, ATON_ACTIV_CTRL_FSHIFT_LSB, ATON_ACTIV_CTRL_FSHIFT_W)

/** Modify the content of the FSHIFT field of the CTRL register. */
#define ATON_ACTIV_CTRL_SET_FSHIFT(REG, DATA)  ATON_SET_FIELD(REG, ATON_ACTIV_CTRL_FSHIFT_LSB, ATON_ACTIV_CTRL_FSHIFT_W, DATA)


/**
 * Get the description of the FSHIFT field of CTRL register.
 *
 * \return the description of the FSHIFT field of CTRL register
 */

static inline const int8_t *ATON_ACTIV_CTRL_FSHIFT_GetdDesc(void)
{
  return (const int8_t *)ATON_ACTIV_CTRL_FSHIFT_DESC;
}


/**
 * Read the content of the FSHIFT field of the CTRL register.
 *
 * \param[in] reg is the value of the CTRL register
 *
 * \return the content of the FSHIFT field belonging to CTRL register
 */

static inline uint32_t ATON_ACTIV_CTRL_Get_FSHIFT(uint32_t reg)
{
  return ATON_ACTIV_CTRL_GET_FSHIFT(reg);
}


/**
 * Write the content of the FSHIFT field of the CTRL register.
 *
 * \param[in] reg  is the value of the CTRL register
 * \param[in] data is 6-bit value that must be written to the field
 *
 * \return the new content of the FSHIFT field belonging to CTRL register
 */

static inline uint32_t ATON_ACTIV_CTRL_Set_FSHIFT(uint32_t reg, uint32_t data)
{
  return ATON_ACTIV_CTRL_SET_FSHIFT(reg, data);
}


/* ----------------------------------------------------------- FROUND field of the CTRL register ------------------------------------------------------------ */

/** Description of the FROUND field of the CTRL register. */
#define ATON_ACTIV_CTRL_FROUND_DESC  "Input feature data rounding control,1=enable,0=disable"

/** Offset of the FROUND field of the CTRL register. */
#define ATON_ACTIV_CTRL_FROUND_LSB  14UL

/** Size in bits of the FROUND field of the CTRL register. */
#define ATON_ACTIV_CTRL_FROUND_W  (1UL)

/** Mask for retrieving the FROUND field of the CTRL register. */
#define ATON_ACTIV_CTRL_FROUND_MASK  ATON_FIELD_MASK(14UL, 1UL)

/** Reset value of the FROUND field of the CTRL register. */
#define ATON_ACTIV_CTRL_FROUND_DT  0x0UL

/** Access rights of the FROUND field of the CTRL register. */
#define ATON_ACTIV_CTRL_FROUND_AC  "RW"

/** Check whether access to the FROUND field of the CTRL register is secured or not. */
#define ATON_ACTIV_CTRL_FROUND_S  0

/** Check whether access to the FROUND field of the CTRL register is privileged or not. */
#define ATON_ACTIV_CTRL_FROUND_P  0

/** Read the content of the FROUND field of the CTRL register. */
#define ATON_ACTIV_CTRL_GET_FROUND(REG)  ATON_GET_FIELD(REG, ATON_ACTIV_CTRL_FROUND_LSB, ATON_ACTIV_CTRL_FROUND_W)

/** Modify the content of the FROUND field of the CTRL register. */
#define ATON_ACTIV_CTRL_SET_FROUND(REG, DATA)  ATON_SET_FIELD(REG, ATON_ACTIV_CTRL_FROUND_LSB, ATON_ACTIV_CTRL_FROUND_W, DATA)


/**
 * Get the description of the FROUND field of CTRL register.
 *
 * \return the description of the FROUND field of CTRL register
 */

static inline const int8_t *ATON_ACTIV_CTRL_FROUND_GetdDesc(void)
{
  return (const int8_t *)ATON_ACTIV_CTRL_FROUND_DESC;
}


/**
 * Read the content of the FROUND field of the CTRL register.
 *
 * \param[in] reg is the value of the CTRL register
 *
 * \return the content of the FROUND field belonging to CTRL register
 */

static inline uint32_t ATON_ACTIV_CTRL_Get_FROUND(uint32_t reg)
{
  return ATON_ACTIV_CTRL_GET_FROUND(reg);
}


/**
 * Write the content of the FROUND field of the CTRL register.
 *
 * \param[in] reg  is the value of the CTRL register
 * \param[in] data is 1-bit value that must be written to the field
 *
 * \return the new content of the FROUND field belonging to CTRL register
 */

static inline uint32_t ATON_ACTIV_CTRL_Set_FROUND(uint32_t reg, uint32_t data)
{
  return ATON_ACTIV_CTRL_SET_FROUND(reg, data);
}


/* ------------------------------------------------------------ FSAT field of the CTRL register ------------------------------------------------------------- */

/** Description of the FSAT field of the CTRL register. */
#define ATON_ACTIV_CTRL_FSAT_DESC  "Input feature data saturation control,1=enable,0=disable"

/** Offset of the FSAT field of the CTRL register. */
#define ATON_ACTIV_CTRL_FSAT_LSB  15UL

/** Size in bits of the FSAT field of the CTRL register. */
#define ATON_ACTIV_CTRL_FSAT_W  (1UL)

/** Mask for retrieving the FSAT field of the CTRL register. */
#define ATON_ACTIV_CTRL_FSAT_MASK  ATON_FIELD_MASK(15UL, 1UL)

/** Reset value of the FSAT field of the CTRL register. */
#define ATON_ACTIV_CTRL_FSAT_DT  0x0UL

/** Access rights of the FSAT field of the CTRL register. */
#define ATON_ACTIV_CTRL_FSAT_AC  "RW"

/** Check whether access to the FSAT field of the CTRL register is secured or not. */
#define ATON_ACTIV_CTRL_FSAT_S  0

/** Check whether access to the FSAT field of the CTRL register is privileged or not. */
#define ATON_ACTIV_CTRL_FSAT_P  0

/** Read the content of the FSAT field of the CTRL register. */
#define ATON_ACTIV_CTRL_GET_FSAT(REG)  ATON_GET_FIELD(REG, ATON_ACTIV_CTRL_FSAT_LSB, ATON_ACTIV_CTRL_FSAT_W)

/** Modify the content of the FSAT field of the CTRL register. */
#define ATON_ACTIV_CTRL_SET_FSAT(REG, DATA)  ATON_SET_FIELD(REG, ATON_ACTIV_CTRL_FSAT_LSB, ATON_ACTIV_CTRL_FSAT_W, DATA)


/**
 * Get the description of the FSAT field of CTRL register.
 *
 * \return the description of the FSAT field of CTRL register
 */

static inline const int8_t *ATON_ACTIV_CTRL_FSAT_GetdDesc(void)
{
  return (const int8_t *)ATON_ACTIV_CTRL_FSAT_DESC;
}


/**
 * Read the content of the FSAT field of the CTRL register.
 *
 * \param[in] reg is the value of the CTRL register
 *
 * \return the content of the FSAT field belonging to CTRL register
 */

static inline uint32_t ATON_ACTIV_CTRL_Get_FSAT(uint32_t reg)
{
  return ATON_ACTIV_CTRL_GET_FSAT(reg);
}


/**
 * Write the content of the FSAT field of the CTRL register.
 *
 * \param[in] reg  is the value of the CTRL register
 * \param[in] data is 1-bit value that must be written to the field
 *
 * \return the new content of the FSAT field belonging to CTRL register
 */

static inline uint32_t ATON_ACTIV_CTRL_Set_FSAT(uint32_t reg, uint32_t data)
{
  return ATON_ACTIV_CTRL_SET_FSAT(reg, data);
}


/* ---------------------------------------------------------- FRNDMODE field of the CTRL register ----------------------------------------------------------- */

/** Description of the FRNDMODE field of the CTRL register. */
#define ATON_ACTIV_CTRL_FRNDMODE_DESC  "Input feature round mode. For more information see section: Rounding and Saturation. Valid values are 0 or 1. Bit 1 of this field is reserved for future use and ignored in this implementation"

/** Offset of the FRNDMODE field of the CTRL register. */
#define ATON_ACTIV_CTRL_FRNDMODE_LSB  16UL

/** Size in bits of the FRNDMODE field of the CTRL register. */
#define ATON_ACTIV_CTRL_FRNDMODE_W  (2UL)

/** Mask for retrieving the FRNDMODE field of the CTRL register. */
#define ATON_ACTIV_CTRL_FRNDMODE_MASK  ATON_FIELD_MASK(16UL, 2UL)

/** Reset value of the FRNDMODE field of the CTRL register. */
#define ATON_ACTIV_CTRL_FRNDMODE_DT  0x0UL

/** Access rights of the FRNDMODE field of the CTRL register. */
#define ATON_ACTIV_CTRL_FRNDMODE_AC  "RW"

/** Check whether access to the FRNDMODE field of the CTRL register is secured or not. */
#define ATON_ACTIV_CTRL_FRNDMODE_S  0

/** Check whether access to the FRNDMODE field of the CTRL register is privileged or not. */
#define ATON_ACTIV_CTRL_FRNDMODE_P  0

/** Read the content of the FRNDMODE field of the CTRL register. */
#define ATON_ACTIV_CTRL_GET_FRNDMODE(REG)  ATON_GET_FIELD(REG, ATON_ACTIV_CTRL_FRNDMODE_LSB, ATON_ACTIV_CTRL_FRNDMODE_W)

/** Modify the content of the FRNDMODE field of the CTRL register. */
#define ATON_ACTIV_CTRL_SET_FRNDMODE(REG, DATA)  ATON_SET_FIELD(REG, ATON_ACTIV_CTRL_FRNDMODE_LSB, ATON_ACTIV_CTRL_FRNDMODE_W, DATA)


/**
 * Get the description of the FRNDMODE field of CTRL register.
 *
 * \return the description of the FRNDMODE field of CTRL register
 */

static inline const int8_t *ATON_ACTIV_CTRL_FRNDMODE_GetdDesc(void)
{
  return (const int8_t *)ATON_ACTIV_CTRL_FRNDMODE_DESC;
}


/**
 * Read the content of the FRNDMODE field of the CTRL register.
 *
 * \param[in] reg is the value of the CTRL register
 *
 * \return the content of the FRNDMODE field belonging to CTRL register
 */

static inline uint32_t ATON_ACTIV_CTRL_Get_FRNDMODE(uint32_t reg)
{
  return ATON_ACTIV_CTRL_GET_FRNDMODE(reg);
}


/**
 * Write the content of the FRNDMODE field of the CTRL register.
 *
 * \param[in] reg  is the value of the CTRL register
 * \param[in] data is 2-bit value that must be written to the field
 *
 * \return the new content of the FRNDMODE field belonging to CTRL register
 */

static inline uint32_t ATON_ACTIV_CTRL_Set_FRNDMODE(uint32_t reg, uint32_t data)
{
  return ATON_ACTIV_CTRL_SET_FRNDMODE(reg, data);
}


/* ----------------------------------------------------------- FOBYTES field of the CTRL register ----------------------------------------------------------- */

/** Description of the FOBYTES field of the CTRL register. */
#define ATON_ACTIV_CTRL_FOBYTES_DESC  "Input feature out bytes after shift. Valid values are 1 or 2 bytes"

/** Offset of the FOBYTES field of the CTRL register. */
#define ATON_ACTIV_CTRL_FOBYTES_LSB  18UL

/** Size in bits of the FOBYTES field of the CTRL register. */
#define ATON_ACTIV_CTRL_FOBYTES_W  (2UL)

/** Mask for retrieving the FOBYTES field of the CTRL register. */
#define ATON_ACTIV_CTRL_FOBYTES_MASK  ATON_FIELD_MASK(18UL, 2UL)

/** Reset value of the FOBYTES field of the CTRL register. */
#define ATON_ACTIV_CTRL_FOBYTES_DT  0x2UL

/** Access rights of the FOBYTES field of the CTRL register. */
#define ATON_ACTIV_CTRL_FOBYTES_AC  "RW"

/** Check whether access to the FOBYTES field of the CTRL register is secured or not. */
#define ATON_ACTIV_CTRL_FOBYTES_S  0

/** Check whether access to the FOBYTES field of the CTRL register is privileged or not. */
#define ATON_ACTIV_CTRL_FOBYTES_P  0

/** Read the content of the FOBYTES field of the CTRL register. */
#define ATON_ACTIV_CTRL_GET_FOBYTES(REG)  ATON_GET_FIELD(REG, ATON_ACTIV_CTRL_FOBYTES_LSB, ATON_ACTIV_CTRL_FOBYTES_W)

/** Modify the content of the FOBYTES field of the CTRL register. */
#define ATON_ACTIV_CTRL_SET_FOBYTES(REG, DATA)  ATON_SET_FIELD(REG, ATON_ACTIV_CTRL_FOBYTES_LSB, ATON_ACTIV_CTRL_FOBYTES_W, DATA)


/**
 * Get the description of the FOBYTES field of CTRL register.
 *
 * \return the description of the FOBYTES field of CTRL register
 */

static inline const int8_t *ATON_ACTIV_CTRL_FOBYTES_GetdDesc(void)
{
  return (const int8_t *)ATON_ACTIV_CTRL_FOBYTES_DESC;
}


/**
 * Read the content of the FOBYTES field of the CTRL register.
 *
 * \param[in] reg is the value of the CTRL register
 *
 * \return the content of the FOBYTES field belonging to CTRL register
 */

static inline uint32_t ATON_ACTIV_CTRL_Get_FOBYTES(uint32_t reg)
{
  return ATON_ACTIV_CTRL_GET_FOBYTES(reg);
}


/**
 * Write the content of the FOBYTES field of the CTRL register.
 *
 * \param[in] reg  is the value of the CTRL register
 * \param[in] data is 2-bit value that must be written to the field
 *
 * \return the new content of the FOBYTES field belonging to CTRL register
 */

static inline uint32_t ATON_ACTIV_CTRL_Set_FOBYTES(uint32_t reg, uint32_t data)
{
  return ATON_ACTIV_CTRL_SET_FOBYTES(reg, data);
}


/* ------------------------------------------------------------ ROUND field of the CTRL register ------------------------------------------------------------ */

/** Description of the ROUND field of the CTRL register. */
#define ATON_ACTIV_CTRL_ROUND_DESC  "output rounding control, 1=enable,0=disable"

/** Offset of the ROUND field of the CTRL register. */
#define ATON_ACTIV_CTRL_ROUND_LSB  20UL

/** Size in bits of the ROUND field of the CTRL register. */
#define ATON_ACTIV_CTRL_ROUND_W  (1UL)

/** Mask for retrieving the ROUND field of the CTRL register. */
#define ATON_ACTIV_CTRL_ROUND_MASK  ATON_FIELD_MASK(20UL, 1UL)

/** Reset value of the ROUND field of the CTRL register. */
#define ATON_ACTIV_CTRL_ROUND_DT  0x0UL

/** Access rights of the ROUND field of the CTRL register. */
#define ATON_ACTIV_CTRL_ROUND_AC  "RW"

/** Check whether access to the ROUND field of the CTRL register is secured or not. */
#define ATON_ACTIV_CTRL_ROUND_S  0

/** Check whether access to the ROUND field of the CTRL register is privileged or not. */
#define ATON_ACTIV_CTRL_ROUND_P  0

/** Read the content of the ROUND field of the CTRL register. */
#define ATON_ACTIV_CTRL_GET_ROUND(REG)  ATON_GET_FIELD(REG, ATON_ACTIV_CTRL_ROUND_LSB, ATON_ACTIV_CTRL_ROUND_W)

/** Modify the content of the ROUND field of the CTRL register. */
#define ATON_ACTIV_CTRL_SET_ROUND(REG, DATA)  ATON_SET_FIELD(REG, ATON_ACTIV_CTRL_ROUND_LSB, ATON_ACTIV_CTRL_ROUND_W, DATA)


/**
 * Get the description of the ROUND field of CTRL register.
 *
 * \return the description of the ROUND field of CTRL register
 */

static inline const int8_t *ATON_ACTIV_CTRL_ROUND_GetdDesc(void)
{
  return (const int8_t *)ATON_ACTIV_CTRL_ROUND_DESC;
}


/**
 * Read the content of the ROUND field of the CTRL register.
 *
 * \param[in] reg is the value of the CTRL register
 *
 * \return the content of the ROUND field belonging to CTRL register
 */

static inline uint32_t ATON_ACTIV_CTRL_Get_ROUND(uint32_t reg)
{
  return ATON_ACTIV_CTRL_GET_ROUND(reg);
}


/**
 * Write the content of the ROUND field of the CTRL register.
 *
 * \param[in] reg  is the value of the CTRL register
 * \param[in] data is 1-bit value that must be written to the field
 *
 * \return the new content of the ROUND field belonging to CTRL register
 */

static inline uint32_t ATON_ACTIV_CTRL_Set_ROUND(uint32_t reg, uint32_t data)
{
  return ATON_ACTIV_CTRL_SET_ROUND(reg, data);
}


/* ------------------------------------------------------------- SAT field of the CTRL register ------------------------------------------------------------- */

/** Description of the SAT field of the CTRL register. */
#define ATON_ACTIV_CTRL_SAT_DESC  "output saturation control,1=enable,0=disable"

/** Offset of the SAT field of the CTRL register. */
#define ATON_ACTIV_CTRL_SAT_LSB  21UL

/** Size in bits of the SAT field of the CTRL register. */
#define ATON_ACTIV_CTRL_SAT_W  (1UL)

/** Mask for retrieving the SAT field of the CTRL register. */
#define ATON_ACTIV_CTRL_SAT_MASK  ATON_FIELD_MASK(21UL, 1UL)

/** Reset value of the SAT field of the CTRL register. */
#define ATON_ACTIV_CTRL_SAT_DT  0x0UL

/** Access rights of the SAT field of the CTRL register. */
#define ATON_ACTIV_CTRL_SAT_AC  "RW"

/** Check whether access to the SAT field of the CTRL register is secured or not. */
#define ATON_ACTIV_CTRL_SAT_S  0

/** Check whether access to the SAT field of the CTRL register is privileged or not. */
#define ATON_ACTIV_CTRL_SAT_P  0

/** Read the content of the SAT field of the CTRL register. */
#define ATON_ACTIV_CTRL_GET_SAT(REG)  ATON_GET_FIELD(REG, ATON_ACTIV_CTRL_SAT_LSB, ATON_ACTIV_CTRL_SAT_W)

/** Modify the content of the SAT field of the CTRL register. */
#define ATON_ACTIV_CTRL_SET_SAT(REG, DATA)  ATON_SET_FIELD(REG, ATON_ACTIV_CTRL_SAT_LSB, ATON_ACTIV_CTRL_SAT_W, DATA)


/**
 * Get the description of the SAT field of CTRL register.
 *
 * \return the description of the SAT field of CTRL register
 */

static inline const int8_t *ATON_ACTIV_CTRL_SAT_GetdDesc(void)
{
  return (const int8_t *)ATON_ACTIV_CTRL_SAT_DESC;
}


/**
 * Read the content of the SAT field of the CTRL register.
 *
 * \param[in] reg is the value of the CTRL register
 *
 * \return the content of the SAT field belonging to CTRL register
 */

static inline uint32_t ATON_ACTIV_CTRL_Get_SAT(uint32_t reg)
{
  return ATON_ACTIV_CTRL_GET_SAT(reg);
}


/**
 * Write the content of the SAT field of the CTRL register.
 *
 * \param[in] reg  is the value of the CTRL register
 * \param[in] data is 1-bit value that must be written to the field
 *
 * \return the new content of the SAT field belonging to CTRL register
 */

static inline uint32_t ATON_ACTIV_CTRL_Set_SAT(uint32_t reg, uint32_t data)
{
  return ATON_ACTIV_CTRL_SET_SAT(reg, data);
}


/* ----------------------------------------------------------- OBYTES field of the CTRL register ------------------------------------------------------------ */

/** Description of the OBYTES field of the CTRL register. */
#define ATON_ACTIV_CTRL_OBYTES_DESC  "number of output bytes:1, 2 or 3"

/** Offset of the OBYTES field of the CTRL register. */
#define ATON_ACTIV_CTRL_OBYTES_LSB  22UL

/** Size in bits of the OBYTES field of the CTRL register. */
#define ATON_ACTIV_CTRL_OBYTES_W  (2UL)

/** Mask for retrieving the OBYTES field of the CTRL register. */
#define ATON_ACTIV_CTRL_OBYTES_MASK  ATON_FIELD_MASK(22UL, 2UL)

/** Reset value of the OBYTES field of the CTRL register. */
#define ATON_ACTIV_CTRL_OBYTES_DT  0x2UL

/** Access rights of the OBYTES field of the CTRL register. */
#define ATON_ACTIV_CTRL_OBYTES_AC  "RW"

/** Check whether access to the OBYTES field of the CTRL register is secured or not. */
#define ATON_ACTIV_CTRL_OBYTES_S  0

/** Check whether access to the OBYTES field of the CTRL register is privileged or not. */
#define ATON_ACTIV_CTRL_OBYTES_P  0

/** Read the content of the OBYTES field of the CTRL register. */
#define ATON_ACTIV_CTRL_GET_OBYTES(REG)  ATON_GET_FIELD(REG, ATON_ACTIV_CTRL_OBYTES_LSB, ATON_ACTIV_CTRL_OBYTES_W)

/** Modify the content of the OBYTES field of the CTRL register. */
#define ATON_ACTIV_CTRL_SET_OBYTES(REG, DATA)  ATON_SET_FIELD(REG, ATON_ACTIV_CTRL_OBYTES_LSB, ATON_ACTIV_CTRL_OBYTES_W, DATA)


/**
 * Get the description of the OBYTES field of CTRL register.
 *
 * \return the description of the OBYTES field of CTRL register
 */

static inline const int8_t *ATON_ACTIV_CTRL_OBYTES_GetdDesc(void)
{
  return (const int8_t *)ATON_ACTIV_CTRL_OBYTES_DESC;
}


/**
 * Read the content of the OBYTES field of the CTRL register.
 *
 * \param[in] reg is the value of the CTRL register
 *
 * \return the content of the OBYTES field belonging to CTRL register
 */

static inline uint32_t ATON_ACTIV_CTRL_Get_OBYTES(uint32_t reg)
{
  return ATON_ACTIV_CTRL_GET_OBYTES(reg);
}


/**
 * Write the content of the OBYTES field of the CTRL register.
 *
 * \param[in] reg  is the value of the CTRL register
 * \param[in] data is 2-bit value that must be written to the field
 *
 * \return the new content of the OBYTES field belonging to CTRL register
 */

static inline uint32_t ATON_ACTIV_CTRL_Set_OBYTES(uint32_t reg, uint32_t data)
{
  return ATON_ACTIV_CTRL_SET_OBYTES(reg, data);
}


/* ---------------------------------------------------------- ORNDMODE field of the CTRL register ----------------------------------------------------------- */

/** Description of the ORNDMODE field of the CTRL register. */
#define ATON_ACTIV_CTRL_ORNDMODE_DESC  "output rounding mode. For more information see section: Rounding and Saturation. Valid values are 0 or 1. Bit 1 of this field is reserved for future use and ignored in this implementation"

/** Offset of the ORNDMODE field of the CTRL register. */
#define ATON_ACTIV_CTRL_ORNDMODE_LSB  24UL

/** Size in bits of the ORNDMODE field of the CTRL register. */
#define ATON_ACTIV_CTRL_ORNDMODE_W  (2UL)

/** Mask for retrieving the ORNDMODE field of the CTRL register. */
#define ATON_ACTIV_CTRL_ORNDMODE_MASK  ATON_FIELD_MASK(24UL, 2UL)

/** Reset value of the ORNDMODE field of the CTRL register. */
#define ATON_ACTIV_CTRL_ORNDMODE_DT  0x0UL

/** Access rights of the ORNDMODE field of the CTRL register. */
#define ATON_ACTIV_CTRL_ORNDMODE_AC  "RW"

/** Check whether access to the ORNDMODE field of the CTRL register is secured or not. */
#define ATON_ACTIV_CTRL_ORNDMODE_S  0

/** Check whether access to the ORNDMODE field of the CTRL register is privileged or not. */
#define ATON_ACTIV_CTRL_ORNDMODE_P  0

/** Read the content of the ORNDMODE field of the CTRL register. */
#define ATON_ACTIV_CTRL_GET_ORNDMODE(REG)  ATON_GET_FIELD(REG, ATON_ACTIV_CTRL_ORNDMODE_LSB, ATON_ACTIV_CTRL_ORNDMODE_W)

/** Modify the content of the ORNDMODE field of the CTRL register. */
#define ATON_ACTIV_CTRL_SET_ORNDMODE(REG, DATA)  ATON_SET_FIELD(REG, ATON_ACTIV_CTRL_ORNDMODE_LSB, ATON_ACTIV_CTRL_ORNDMODE_W, DATA)


/**
 * Get the description of the ORNDMODE field of CTRL register.
 *
 * \return the description of the ORNDMODE field of CTRL register
 */

static inline const int8_t *ATON_ACTIV_CTRL_ORNDMODE_GetdDesc(void)
{
  return (const int8_t *)ATON_ACTIV_CTRL_ORNDMODE_DESC;
}


/**
 * Read the content of the ORNDMODE field of the CTRL register.
 *
 * \param[in] reg is the value of the CTRL register
 *
 * \return the content of the ORNDMODE field belonging to CTRL register
 */

static inline uint32_t ATON_ACTIV_CTRL_Get_ORNDMODE(uint32_t reg)
{
  return ATON_ACTIV_CTRL_GET_ORNDMODE(reg);
}


/**
 * Write the content of the ORNDMODE field of the CTRL register.
 *
 * \param[in] reg  is the value of the CTRL register
 * \param[in] data is 2-bit value that must be written to the field
 *
 * \return the new content of the ORNDMODE field belonging to CTRL register
 */

static inline uint32_t ATON_ACTIV_CTRL_Set_ORNDMODE(uint32_t reg, uint32_t data)
{
  return ATON_ACTIV_CTRL_SET_ORNDMODE(reg, data);
}


/* ----------------------------------------------------------- CONFCLR field of the CTRL register ----------------------------------------------------------- */

/** Description of the CONFCLR field of the CTRL register. */
#define ATON_ACTIV_CTRL_CONFCLR_DESC  "Clear configuration registers (auto-cleared)"

/** Offset of the CONFCLR field of the CTRL register. */
#define ATON_ACTIV_CTRL_CONFCLR_LSB  30UL

/** Size in bits of the CONFCLR field of the CTRL register. */
#define ATON_ACTIV_CTRL_CONFCLR_W  (1UL)

/** Mask for retrieving the CONFCLR field of the CTRL register. */
#define ATON_ACTIV_CTRL_CONFCLR_MASK  ATON_FIELD_MASK(30UL, 1UL)

/** Reset value of the CONFCLR field of the CTRL register. */
#define ATON_ACTIV_CTRL_CONFCLR_DT  0x0UL

/** Access rights of the CONFCLR field of the CTRL register. */
#define ATON_ACTIV_CTRL_CONFCLR_AC  "RW"

/** Check whether access to the CONFCLR field of the CTRL register is secured or not. */
#define ATON_ACTIV_CTRL_CONFCLR_S  0

/** Check whether access to the CONFCLR field of the CTRL register is privileged or not. */
#define ATON_ACTIV_CTRL_CONFCLR_P  0

/** Read the content of the CONFCLR field of the CTRL register. */
#define ATON_ACTIV_CTRL_GET_CONFCLR(REG)  ATON_GET_FIELD(REG, ATON_ACTIV_CTRL_CONFCLR_LSB, ATON_ACTIV_CTRL_CONFCLR_W)

/** Modify the content of the CONFCLR field of the CTRL register. */
#define ATON_ACTIV_CTRL_SET_CONFCLR(REG, DATA)  ATON_SET_FIELD(REG, ATON_ACTIV_CTRL_CONFCLR_LSB, ATON_ACTIV_CTRL_CONFCLR_W, DATA)


/**
 * Get the description of the CONFCLR field of CTRL register.
 *
 * \return the description of the CONFCLR field of CTRL register
 */

static inline const int8_t *ATON_ACTIV_CTRL_CONFCLR_GetdDesc(void)
{
  return (const int8_t *)ATON_ACTIV_CTRL_CONFCLR_DESC;
}


/**
 * Read the content of the CONFCLR field of the CTRL register.
 *
 * \param[in] reg is the value of the CTRL register
 *
 * \return the content of the CONFCLR field belonging to CTRL register
 */

static inline uint32_t ATON_ACTIV_CTRL_Get_CONFCLR(uint32_t reg)
{
  return ATON_ACTIV_CTRL_GET_CONFCLR(reg);
}


/**
 * Write the content of the CONFCLR field of the CTRL register.
 *
 * \param[in] reg  is the value of the CTRL register
 * \param[in] data is 1-bit value that must be written to the field
 *
 * \return the new content of the CONFCLR field belonging to CTRL register
 */

static inline uint32_t ATON_ACTIV_CTRL_Set_CONFCLR(uint32_t reg, uint32_t data)
{
  return ATON_ACTIV_CTRL_SET_CONFCLR(reg, data);
}


/* ******************************************************* VERSION register of one of the ACTIV Units ******************************************************* */

/** Offset of the VERSION register from the base address of the ACTIV Unit. */
#define ATON_ACTIV_VERSION_OFFSET  0x4UL

/** Reset value of the VERSION register of the ACTIV Unit. */
#define ATON_ACTIV_VERSION_DT \
  (ATON_ACTIV_VERSION_TYPE_DT  << ATON_ACTIV_VERSION_TYPE_LSB)  | \
  (ATON_ACTIV_VERSION_MINOR_DT << ATON_ACTIV_VERSION_MINOR_LSB) | \
  (ATON_ACTIV_VERSION_MAJOR_DT << ATON_ACTIV_VERSION_MAJOR_LSB)



/** Description of the VERSION register. */
#define ATON_ACTIV_VERSION_DESC  "Version register"

/** Address of the VERSION register of one of the ACTIV Units. */
#define ATON_ACTIV_VERSION_ADDR(UNIT)  (ATON_ACTIV_BASE(UNIT) + ATON_ACTIV_VERSION_OFFSET)

/** Get the content of the VERSION register of one of the ACTIV Units. */
#define ATON_ACTIV_VERSION_GET(UNIT)  (*((volatile uint32_t *)(uintptr_t)ATON_ACTIV_VERSION_ADDR(UNIT)))


/**
 * Get the description of VERSION register.
 *
 * \return the description of VERSION register
 */

static inline const int8_t *ATON_ACTIV_VERSION_GetDesc(void)
{
  return (const int8_t *)ATON_ACTIV_VERSION_DESC;
}


/**
 * Get the offset of the VERSION register.
 *
 * \return the offset of VERSION register
 */

static inline uint32_t ATON_ACTIV_VERSION_GetOffset(void)
{
  return ATON_ACTIV_VERSION_OFFSET;
}


/**
 * Get the address of the VERSION register.
 *
 * \param[in] instance is the index of the Unit (among the ACTIV Units) containing the VERSION register whose address must be returned
 *                     (it must be <em>instance \< 2<\em>)
 *
 * \return the address of VERSION register belonging to Unit having index \e instance among the ACTIV Units
 */

static inline uint32_t ATON_ACTIV_VERSION_GetAddr(uint32_t instance)
{
  return ATON_ACTIV_VERSION_ADDR(instance);
}


/**
 * Read the content of the VERSION register.
 *
 * \param[in] instance is the index of the Unit (among the ACTIV Units) containing the VERSION register whose content must be retrieved
 *                     (it must be <em>instance \< 2<\em>)
 *
 * \return the content of VERSION register belonging to Unit having index \e instance among the ACTIV Units
 */

static inline uint32_t ATON_ACTIV_VERSION_Get(uint32_t instance)
{
  return ATON_ACTIV_VERSION_GET(instance);
}


/* ----------------------------------------------------------- TYPE field of the VERSION register ----------------------------------------------------------- */

/** Description of the TYPE field of the VERSION register. */
#define ATON_ACTIV_VERSION_TYPE_DESC  "Block type"

/** Offset of the TYPE field of the VERSION register. */
#define ATON_ACTIV_VERSION_TYPE_LSB  0UL

/** Size in bits of the TYPE field of the VERSION register. */
#define ATON_ACTIV_VERSION_TYPE_W  (8UL)

/** Mask for retrieving the TYPE field of the VERSION register. */
#define ATON_ACTIV_VERSION_TYPE_MASK  ATON_FIELD_MASK(0UL, 8UL)

/** Reset value of the TYPE field of the VERSION register. */
#define ATON_ACTIV_VERSION_TYPE_DT  0x1bUL

/** Access rights of the TYPE field of the VERSION register. */
#define ATON_ACTIV_VERSION_TYPE_AC  "R"

/** Check whether access to the TYPE field of the VERSION register is secured or not. */
#define ATON_ACTIV_VERSION_TYPE_S  0

/** Check whether access to the TYPE field of the VERSION register is privileged or not. */
#define ATON_ACTIV_VERSION_TYPE_P  0

/** Read the content of the TYPE field of the VERSION register. */
#define ATON_ACTIV_VERSION_GET_TYPE(REG)  ATON_GET_FIELD(REG, ATON_ACTIV_VERSION_TYPE_LSB, ATON_ACTIV_VERSION_TYPE_W)


/**
 * Get the description of the TYPE field of VERSION register.
 *
 * \return the description of the TYPE field of VERSION register
 */

static inline const int8_t *ATON_ACTIV_VERSION_TYPE_GetdDesc(void)
{
  return (const int8_t *)ATON_ACTIV_VERSION_TYPE_DESC;
}


/**
 * Read the content of the TYPE field of the VERSION register.
 *
 * \param[in] reg is the value of the VERSION register
 *
 * \return the content of the TYPE field belonging to VERSION register
 */

static inline uint32_t ATON_ACTIV_VERSION_Get_TYPE(uint32_t reg)
{
  return ATON_ACTIV_VERSION_GET_TYPE(reg);
}


/* ---------------------------------------------------------- MINOR field of the VERSION register ----------------------------------------------------------- */

/** Description of the MINOR field of the VERSION register. */
#define ATON_ACTIV_VERSION_MINOR_DESC  "Block minor version"

/** Offset of the MINOR field of the VERSION register. */
#define ATON_ACTIV_VERSION_MINOR_LSB  8UL

/** Size in bits of the MINOR field of the VERSION register. */
#define ATON_ACTIV_VERSION_MINOR_W  (4UL)

/** Mask for retrieving the MINOR field of the VERSION register. */
#define ATON_ACTIV_VERSION_MINOR_MASK  ATON_FIELD_MASK(8UL, 4UL)

/** Reset value of the MINOR field of the VERSION register. */
#define ATON_ACTIV_VERSION_MINOR_DT  0x1UL

/** Access rights of the MINOR field of the VERSION register. */
#define ATON_ACTIV_VERSION_MINOR_AC  "R"

/** Check whether access to the MINOR field of the VERSION register is secured or not. */
#define ATON_ACTIV_VERSION_MINOR_S  0

/** Check whether access to the MINOR field of the VERSION register is privileged or not. */
#define ATON_ACTIV_VERSION_MINOR_P  0

/** Read the content of the MINOR field of the VERSION register. */
#define ATON_ACTIV_VERSION_GET_MINOR(REG)  ATON_GET_FIELD(REG, ATON_ACTIV_VERSION_MINOR_LSB, ATON_ACTIV_VERSION_MINOR_W)


/**
 * Get the description of the MINOR field of VERSION register.
 *
 * \return the description of the MINOR field of VERSION register
 */

static inline const int8_t *ATON_ACTIV_VERSION_MINOR_GetdDesc(void)
{
  return (const int8_t *)ATON_ACTIV_VERSION_MINOR_DESC;
}


/**
 * Read the content of the MINOR field of the VERSION register.
 *
 * \param[in] reg is the value of the VERSION register
 *
 * \return the content of the MINOR field belonging to VERSION register
 */

static inline uint32_t ATON_ACTIV_VERSION_Get_MINOR(uint32_t reg)
{
  return ATON_ACTIV_VERSION_GET_MINOR(reg);
}


/* ---------------------------------------------------------- MAJOR field of the VERSION register ----------------------------------------------------------- */

/** Description of the MAJOR field of the VERSION register. */
#define ATON_ACTIV_VERSION_MAJOR_DESC  "Block major version"

/** Offset of the MAJOR field of the VERSION register. */
#define ATON_ACTIV_VERSION_MAJOR_LSB  12UL

/** Size in bits of the MAJOR field of the VERSION register. */
#define ATON_ACTIV_VERSION_MAJOR_W  (4UL)

/** Mask for retrieving the MAJOR field of the VERSION register. */
#define ATON_ACTIV_VERSION_MAJOR_MASK  ATON_FIELD_MASK(12UL, 4UL)

/** Reset value of the MAJOR field of the VERSION register. */
#define ATON_ACTIV_VERSION_MAJOR_DT  0x1UL

/** Access rights of the MAJOR field of the VERSION register. */
#define ATON_ACTIV_VERSION_MAJOR_AC  "R"

/** Check whether access to the MAJOR field of the VERSION register is secured or not. */
#define ATON_ACTIV_VERSION_MAJOR_S  0

/** Check whether access to the MAJOR field of the VERSION register is privileged or not. */
#define ATON_ACTIV_VERSION_MAJOR_P  0

/** Read the content of the MAJOR field of the VERSION register. */
#define ATON_ACTIV_VERSION_GET_MAJOR(REG)  ATON_GET_FIELD(REG, ATON_ACTIV_VERSION_MAJOR_LSB, ATON_ACTIV_VERSION_MAJOR_W)


/**
 * Get the description of the MAJOR field of VERSION register.
 *
 * \return the description of the MAJOR field of VERSION register
 */

static inline const int8_t *ATON_ACTIV_VERSION_MAJOR_GetdDesc(void)
{
  return (const int8_t *)ATON_ACTIV_VERSION_MAJOR_DESC;
}


/**
 * Read the content of the MAJOR field of the VERSION register.
 *
 * \param[in] reg is the value of the VERSION register
 *
 * \return the content of the MAJOR field belonging to VERSION register
 */

static inline uint32_t ATON_ACTIV_VERSION_Get_MAJOR(uint32_t reg)
{
  return ATON_ACTIV_VERSION_GET_MAJOR(reg);
}


/* ***************************************************** ACTIVPARAM register of one of the ACTIV Units ****************************************************** */

/** Offset of the ACTIVPARAM register from the base address of the ACTIV Unit. */
#define ATON_ACTIV_ACTIVPARAM_OFFSET  0x8UL

/** Reset value of the ACTIVPARAM register of the ACTIV Unit. */
#define ATON_ACTIV_ACTIVPARAM_DT \
  (ATON_ACTIV_ACTIVPARAM_PARAM_DT << ATON_ACTIV_ACTIVPARAM_PARAM_LSB) | \
  (ATON_ACTIV_ACTIVPARAM_FUNC_DT  << ATON_ACTIV_ACTIVPARAM_FUNC_LSB)



/** Description of the ACTIVPARAM register. */
#define ATON_ACTIV_ACTIVPARAM_DESC  "ReLU parameter for parametric ReLU or thresholded ReLU"

/** Address of the ACTIVPARAM register of one of the ACTIV Units. */
#define ATON_ACTIV_ACTIVPARAM_ADDR(UNIT)  (ATON_ACTIV_BASE(UNIT) + ATON_ACTIV_ACTIVPARAM_OFFSET)

/** Get the content of the ACTIVPARAM register of one of the ACTIV Units. */
#define ATON_ACTIV_ACTIVPARAM_GET(UNIT)  (*((volatile uint32_t *)(uintptr_t)ATON_ACTIV_ACTIVPARAM_ADDR(UNIT)))

/** Set the content of the ACTIVPARAM register of one of the ACTIV Units. */
#define ATON_ACTIV_ACTIVPARAM_SET(UNIT, DATA)  do { *((volatile uint32_t *)(uintptr_t)ATON_ACTIV_ACTIVPARAM_ADDR(UNIT)) = (DATA); } while (0);


/**
 * Get the description of ACTIVPARAM register.
 *
 * \return the description of ACTIVPARAM register
 */

static inline const int8_t *ATON_ACTIV_ACTIVPARAM_GetDesc(void)
{
  return (const int8_t *)ATON_ACTIV_ACTIVPARAM_DESC;
}


/**
 * Get the offset of the ACTIVPARAM register.
 *
 * \return the offset of ACTIVPARAM register
 */

static inline uint32_t ATON_ACTIV_ACTIVPARAM_GetOffset(void)
{
  return ATON_ACTIV_ACTIVPARAM_OFFSET;
}


/**
 * Get the address of the ACTIVPARAM register.
 *
 * \param[in] instance is the index of the Unit (among the ACTIV Units) containing the ACTIVPARAM register whose address must be returned
 *                     (it must be <em>instance \< 2<\em>)
 *
 * \return the address of ACTIVPARAM register belonging to Unit having index \e instance among the ACTIV Units
 */

static inline uint32_t ATON_ACTIV_ACTIVPARAM_GetAddr(uint32_t instance)
{
  return ATON_ACTIV_ACTIVPARAM_ADDR(instance);
}


/**
 * Read the content of the ACTIVPARAM register.
 *
 * \param[in] instance is the index of the Unit (among the ACTIV Units) containing the ACTIVPARAM register whose content must be retrieved
 *                     (it must be <em>instance \< 2<\em>)
 *
 * \return the content of ACTIVPARAM register belonging to Unit having index \e instance among the ACTIV Units
 */

static inline uint32_t ATON_ACTIV_ACTIVPARAM_Get(uint32_t instance)
{
  return ATON_ACTIV_ACTIVPARAM_GET(instance);
}


/**
 * Write the content of the ACTIVPARAM register.
 *
 * \param[in] instance is the index of the Unit (among the ACTIV Units) containing the ACTIVPARAM register whose content must be modified
 *                     (it must be <em>instance \< 2<\em>)
 * \param[in] data     is 32-bit value that must be written to the register
 */

static inline void ATON_ACTIV_ACTIVPARAM_Set(uint32_t instance, uint32_t data)
{
  ATON_ACTIV_ACTIVPARAM_SET(instance, data);
}


/* --------------------------------------------------------- PARAM field of the ACTIVPARAM register --------------------------------------------------------- */

/** Description of the PARAM field of the ACTIVPARAM register. */
#define ATON_ACTIV_ACTIVPARAM_PARAM_DESC  "ReLU parameter"

/** Offset of the PARAM field of the ACTIVPARAM register. */
#define ATON_ACTIV_ACTIVPARAM_PARAM_LSB  0UL

/** Size in bits of the PARAM field of the ACTIVPARAM register. */
#define ATON_ACTIV_ACTIVPARAM_PARAM_W  (16UL)

/** Mask for retrieving the PARAM field of the ACTIVPARAM register. */
#define ATON_ACTIV_ACTIVPARAM_PARAM_MASK  ATON_FIELD_MASK(0UL, 16UL)

/** Reset value of the PARAM field of the ACTIVPARAM register. */
#define ATON_ACTIV_ACTIVPARAM_PARAM_DT  0x0UL

/** Access rights of the PARAM field of the ACTIVPARAM register. */
#define ATON_ACTIV_ACTIVPARAM_PARAM_AC  "RW"

/** Check whether access to the PARAM field of the ACTIVPARAM register is secured or not. */
#define ATON_ACTIV_ACTIVPARAM_PARAM_S  0

/** Check whether access to the PARAM field of the ACTIVPARAM register is privileged or not. */
#define ATON_ACTIV_ACTIVPARAM_PARAM_P  0

/** Read the content of the PARAM field of the ACTIVPARAM register. */
#define ATON_ACTIV_ACTIVPARAM_GET_PARAM(REG)  ATON_GET_FIELD(REG, ATON_ACTIV_ACTIVPARAM_PARAM_LSB, ATON_ACTIV_ACTIVPARAM_PARAM_W)

/** Modify the content of the PARAM field of the ACTIVPARAM register. */
#define ATON_ACTIV_ACTIVPARAM_SET_PARAM(REG, DATA)  ATON_SET_FIELD(REG, ATON_ACTIV_ACTIVPARAM_PARAM_LSB, ATON_ACTIV_ACTIVPARAM_PARAM_W, DATA)


/**
 * Get the description of the PARAM field of ACTIVPARAM register.
 *
 * \return the description of the PARAM field of ACTIVPARAM register
 */

static inline const int8_t *ATON_ACTIV_ACTIVPARAM_PARAM_GetdDesc(void)
{
  return (const int8_t *)ATON_ACTIV_ACTIVPARAM_PARAM_DESC;
}


/**
 * Read the content of the PARAM field of the ACTIVPARAM register.
 *
 * \param[in] reg is the value of the ACTIVPARAM register
 *
 * \return the content of the PARAM field belonging to ACTIVPARAM register
 */

static inline uint32_t ATON_ACTIV_ACTIVPARAM_Get_PARAM(uint32_t reg)
{
  return ATON_ACTIV_ACTIVPARAM_GET_PARAM(reg);
}


/**
 * Write the content of the PARAM field of the ACTIVPARAM register.
 *
 * \param[in] reg  is the value of the ACTIVPARAM register
 * \param[in] data is 16-bit value that must be written to the field
 *
 * \return the new content of the PARAM field belonging to ACTIVPARAM register
 */

static inline uint32_t ATON_ACTIV_ACTIVPARAM_Set_PARAM(uint32_t reg, uint32_t data)
{
  return ATON_ACTIV_ACTIVPARAM_SET_PARAM(reg, data);
}


/* --------------------------------------------------------- FUNC field of the ACTIVPARAM register ---------------------------------------------------------- */

/** Description of the FUNC field of the ACTIVPARAM register. */
#define ATON_ACTIV_ACTIVPARAM_FUNC_DESC  "function input range normalization left shift parameter"

/** Offset of the FUNC field of the ACTIVPARAM register. */
#define ATON_ACTIV_ACTIVPARAM_FUNC_LSB  16UL

/** Size in bits of the FUNC field of the ACTIVPARAM register. */
#define ATON_ACTIV_ACTIVPARAM_FUNC_W  (4UL)

/** Mask for retrieving the FUNC field of the ACTIVPARAM register. */
#define ATON_ACTIV_ACTIVPARAM_FUNC_MASK  ATON_FIELD_MASK(16UL, 4UL)

/** Reset value of the FUNC field of the ACTIVPARAM register. */
#define ATON_ACTIV_ACTIVPARAM_FUNC_DT  0x0UL

/** Access rights of the FUNC field of the ACTIVPARAM register. */
#define ATON_ACTIV_ACTIVPARAM_FUNC_AC  "RW"

/** Check whether access to the FUNC field of the ACTIVPARAM register is secured or not. */
#define ATON_ACTIV_ACTIVPARAM_FUNC_S  0

/** Check whether access to the FUNC field of the ACTIVPARAM register is privileged or not. */
#define ATON_ACTIV_ACTIVPARAM_FUNC_P  0

/** Read the content of the FUNC field of the ACTIVPARAM register. */
#define ATON_ACTIV_ACTIVPARAM_GET_FUNC(REG)  ATON_GET_FIELD(REG, ATON_ACTIV_ACTIVPARAM_FUNC_LSB, ATON_ACTIV_ACTIVPARAM_FUNC_W)

/** Modify the content of the FUNC field of the ACTIVPARAM register. */
#define ATON_ACTIV_ACTIVPARAM_SET_FUNC(REG, DATA)  ATON_SET_FIELD(REG, ATON_ACTIV_ACTIVPARAM_FUNC_LSB, ATON_ACTIV_ACTIVPARAM_FUNC_W, DATA)


/**
 * Get the description of the FUNC field of ACTIVPARAM register.
 *
 * \return the description of the FUNC field of ACTIVPARAM register
 */

static inline const int8_t *ATON_ACTIV_ACTIVPARAM_FUNC_GetdDesc(void)
{
  return (const int8_t *)ATON_ACTIV_ACTIVPARAM_FUNC_DESC;
}


/**
 * Read the content of the FUNC field of the ACTIVPARAM register.
 *
 * \param[in] reg is the value of the ACTIVPARAM register
 *
 * \return the content of the FUNC field belonging to ACTIVPARAM register
 */

static inline uint32_t ATON_ACTIV_ACTIVPARAM_Get_FUNC(uint32_t reg)
{
  return ATON_ACTIV_ACTIVPARAM_GET_FUNC(reg);
}


/**
 * Write the content of the FUNC field of the ACTIVPARAM register.
 *
 * \param[in] reg  is the value of the ACTIVPARAM register
 * \param[in] data is 4-bit value that must be written to the field
 *
 * \return the new content of the FUNC field belonging to ACTIVPARAM register
 */

static inline uint32_t ATON_ACTIV_ACTIVPARAM_Set_FUNC(uint32_t reg, uint32_t data)
{
  return ATON_ACTIV_ACTIVPARAM_SET_FUNC(reg, data);
}


/* ******************************************************** FUNC register of one of the ACTIV Units ********************************************************* */

/** Offset of the FUNC register from the base address of the ACTIV Unit. */
#define ATON_ACTIV_FUNC_OFFSET  0xcUL

/** Reset value of the FUNC register of the ACTIV Unit. */
#define ATON_ACTIV_FUNC_DT \
  (ATON_ACTIV_FUNC_OUTSHIFT_DT << ATON_ACTIV_FUNC_OUTSHIFT_LSB) | \
  (ATON_ACTIV_FUNC_CSHIFT_DT   << ATON_ACTIV_FUNC_CSHIFT_LSB)   | \
  (ATON_ACTIV_FUNC_BSHIFT_DT   << ATON_ACTIV_FUNC_BSHIFT_LSB)   | \
  (ATON_ACTIV_FUNC_SIGNEDOP_DT << ATON_ACTIV_FUNC_SIGNEDOP_LSB) | \
  (ATON_ACTIV_FUNC_BWIDTH_DT   << ATON_ACTIV_FUNC_BWIDTH_LSB)



/** Description of the FUNC register. */
#define ATON_ACTIV_FUNC_DESC  "Functional parameter"

/** Address of the FUNC register of one of the ACTIV Units. */
#define ATON_ACTIV_FUNC_ADDR(UNIT)  (ATON_ACTIV_BASE(UNIT) + ATON_ACTIV_FUNC_OFFSET)

/** Get the content of the FUNC register of one of the ACTIV Units. */
#define ATON_ACTIV_FUNC_GET(UNIT)  (*((volatile uint32_t *)(uintptr_t)ATON_ACTIV_FUNC_ADDR(UNIT)))

/** Set the content of the FUNC register of one of the ACTIV Units. */
#define ATON_ACTIV_FUNC_SET(UNIT, DATA)  do { *((volatile uint32_t *)(uintptr_t)ATON_ACTIV_FUNC_ADDR(UNIT)) = (DATA); } while (0);


/**
 * Get the description of FUNC register.
 *
 * \return the description of FUNC register
 */

static inline const int8_t *ATON_ACTIV_FUNC_GetDesc(void)
{
  return (const int8_t *)ATON_ACTIV_FUNC_DESC;
}


/**
 * Get the offset of the FUNC register.
 *
 * \return the offset of FUNC register
 */

static inline uint32_t ATON_ACTIV_FUNC_GetOffset(void)
{
  return ATON_ACTIV_FUNC_OFFSET;
}


/**
 * Get the address of the FUNC register.
 *
 * \param[in] instance is the index of the Unit (among the ACTIV Units) containing the FUNC register whose address must be returned
 *                     (it must be <em>instance \< 2<\em>)
 *
 * \return the address of FUNC register belonging to Unit having index \e instance among the ACTIV Units
 */

static inline uint32_t ATON_ACTIV_FUNC_GetAddr(uint32_t instance)
{
  return ATON_ACTIV_FUNC_ADDR(instance);
}


/**
 * Read the content of the FUNC register.
 *
 * \param[in] instance is the index of the Unit (among the ACTIV Units) containing the FUNC register whose content must be retrieved
 *                     (it must be <em>instance \< 2<\em>)
 *
 * \return the content of FUNC register belonging to Unit having index \e instance among the ACTIV Units
 */

static inline uint32_t ATON_ACTIV_FUNC_Get(uint32_t instance)
{
  return ATON_ACTIV_FUNC_GET(instance);
}


/**
 * Write the content of the FUNC register.
 *
 * \param[in] instance is the index of the Unit (among the ACTIV Units) containing the FUNC register whose content must be modified
 *                     (it must be <em>instance \< 2<\em>)
 * \param[in] data     is 32-bit value that must be written to the register
 */

static inline void ATON_ACTIV_FUNC_Set(uint32_t instance, uint32_t data)
{
  ATON_ACTIV_FUNC_SET(instance, data);
}


/* ---------------------------------------------------------- OUTSHIFT field of the FUNC register ----------------------------------------------------------- */

/** Description of the OUTSHIFT field of the FUNC register. */
#define ATON_ACTIV_FUNC_OUTSHIFT_DESC  "Optional right shift to be applied to the function evaluator final result"

/** Offset of the OUTSHIFT field of the FUNC register. */
#define ATON_ACTIV_FUNC_OUTSHIFT_LSB  0UL

/** Size in bits of the OUTSHIFT field of the FUNC register. */
#define ATON_ACTIV_FUNC_OUTSHIFT_W  (6UL)

/** Mask for retrieving the OUTSHIFT field of the FUNC register. */
#define ATON_ACTIV_FUNC_OUTSHIFT_MASK  ATON_FIELD_MASK(0UL, 6UL)

/** Reset value of the OUTSHIFT field of the FUNC register. */
#define ATON_ACTIV_FUNC_OUTSHIFT_DT  0x0UL

/** Access rights of the OUTSHIFT field of the FUNC register. */
#define ATON_ACTIV_FUNC_OUTSHIFT_AC  "RW"

/** Check whether access to the OUTSHIFT field of the FUNC register is secured or not. */
#define ATON_ACTIV_FUNC_OUTSHIFT_S  0

/** Check whether access to the OUTSHIFT field of the FUNC register is privileged or not. */
#define ATON_ACTIV_FUNC_OUTSHIFT_P  0

/** Read the content of the OUTSHIFT field of the FUNC register. */
#define ATON_ACTIV_FUNC_GET_OUTSHIFT(REG)  ATON_GET_FIELD(REG, ATON_ACTIV_FUNC_OUTSHIFT_LSB, ATON_ACTIV_FUNC_OUTSHIFT_W)

/** Modify the content of the OUTSHIFT field of the FUNC register. */
#define ATON_ACTIV_FUNC_SET_OUTSHIFT(REG, DATA)  ATON_SET_FIELD(REG, ATON_ACTIV_FUNC_OUTSHIFT_LSB, ATON_ACTIV_FUNC_OUTSHIFT_W, DATA)


/**
 * Get the description of the OUTSHIFT field of FUNC register.
 *
 * \return the description of the OUTSHIFT field of FUNC register
 */

static inline const int8_t *ATON_ACTIV_FUNC_OUTSHIFT_GetdDesc(void)
{
  return (const int8_t *)ATON_ACTIV_FUNC_OUTSHIFT_DESC;
}


/**
 * Read the content of the OUTSHIFT field of the FUNC register.
 *
 * \param[in] reg is the value of the FUNC register
 *
 * \return the content of the OUTSHIFT field belonging to FUNC register
 */

static inline uint32_t ATON_ACTIV_FUNC_Get_OUTSHIFT(uint32_t reg)
{
  return ATON_ACTIV_FUNC_GET_OUTSHIFT(reg);
}


/**
 * Write the content of the OUTSHIFT field of the FUNC register.
 *
 * \param[in] reg  is the value of the FUNC register
 * \param[in] data is 6-bit value that must be written to the field
 *
 * \return the new content of the OUTSHIFT field belonging to FUNC register
 */

static inline uint32_t ATON_ACTIV_FUNC_Set_OUTSHIFT(uint32_t reg, uint32_t data)
{
  return ATON_ACTIV_FUNC_SET_OUTSHIFT(reg, data);
}


/* ----------------------------------------------------------- CSHIFT field of the FUNC register ------------------------------------------------------------ */

/** Description of the CSHIFT field of the FUNC register. */
#define ATON_ACTIV_FUNC_CSHIFT_DESC  "Optional left shift to be applied to coefficient C"

/** Offset of the CSHIFT field of the FUNC register. */
#define ATON_ACTIV_FUNC_CSHIFT_LSB  6UL

/** Size in bits of the CSHIFT field of the FUNC register. */
#define ATON_ACTIV_FUNC_CSHIFT_W  (6UL)

/** Mask for retrieving the CSHIFT field of the FUNC register. */
#define ATON_ACTIV_FUNC_CSHIFT_MASK  ATON_FIELD_MASK(6UL, 6UL)

/** Reset value of the CSHIFT field of the FUNC register. */
#define ATON_ACTIV_FUNC_CSHIFT_DT  0x0UL

/** Access rights of the CSHIFT field of the FUNC register. */
#define ATON_ACTIV_FUNC_CSHIFT_AC  "RW"

/** Check whether access to the CSHIFT field of the FUNC register is secured or not. */
#define ATON_ACTIV_FUNC_CSHIFT_S  0

/** Check whether access to the CSHIFT field of the FUNC register is privileged or not. */
#define ATON_ACTIV_FUNC_CSHIFT_P  0

/** Read the content of the CSHIFT field of the FUNC register. */
#define ATON_ACTIV_FUNC_GET_CSHIFT(REG)  ATON_GET_FIELD(REG, ATON_ACTIV_FUNC_CSHIFT_LSB, ATON_ACTIV_FUNC_CSHIFT_W)

/** Modify the content of the CSHIFT field of the FUNC register. */
#define ATON_ACTIV_FUNC_SET_CSHIFT(REG, DATA)  ATON_SET_FIELD(REG, ATON_ACTIV_FUNC_CSHIFT_LSB, ATON_ACTIV_FUNC_CSHIFT_W, DATA)


/**
 * Get the description of the CSHIFT field of FUNC register.
 *
 * \return the description of the CSHIFT field of FUNC register
 */

static inline const int8_t *ATON_ACTIV_FUNC_CSHIFT_GetdDesc(void)
{
  return (const int8_t *)ATON_ACTIV_FUNC_CSHIFT_DESC;
}


/**
 * Read the content of the CSHIFT field of the FUNC register.
 *
 * \param[in] reg is the value of the FUNC register
 *
 * \return the content of the CSHIFT field belonging to FUNC register
 */

static inline uint32_t ATON_ACTIV_FUNC_Get_CSHIFT(uint32_t reg)
{
  return ATON_ACTIV_FUNC_GET_CSHIFT(reg);
}


/**
 * Write the content of the CSHIFT field of the FUNC register.
 *
 * \param[in] reg  is the value of the FUNC register
 * \param[in] data is 6-bit value that must be written to the field
 *
 * \return the new content of the CSHIFT field belonging to FUNC register
 */

static inline uint32_t ATON_ACTIV_FUNC_Set_CSHIFT(uint32_t reg, uint32_t data)
{
  return ATON_ACTIV_FUNC_SET_CSHIFT(reg, data);
}


/* ----------------------------------------------------------- BSHIFT field of the FUNC register ------------------------------------------------------------ */

/** Description of the BSHIFT field of the FUNC register. */
#define ATON_ACTIV_FUNC_BSHIFT_DESC  "Optional left shift to be applied to coefficient B"

/** Offset of the BSHIFT field of the FUNC register. */
#define ATON_ACTIV_FUNC_BSHIFT_LSB  12UL

/** Size in bits of the BSHIFT field of the FUNC register. */
#define ATON_ACTIV_FUNC_BSHIFT_W  (5UL)

/** Mask for retrieving the BSHIFT field of the FUNC register. */
#define ATON_ACTIV_FUNC_BSHIFT_MASK  ATON_FIELD_MASK(12UL, 5UL)

/** Reset value of the BSHIFT field of the FUNC register. */
#define ATON_ACTIV_FUNC_BSHIFT_DT  0x0UL

/** Access rights of the BSHIFT field of the FUNC register. */
#define ATON_ACTIV_FUNC_BSHIFT_AC  "RW"

/** Check whether access to the BSHIFT field of the FUNC register is secured or not. */
#define ATON_ACTIV_FUNC_BSHIFT_S  0

/** Check whether access to the BSHIFT field of the FUNC register is privileged or not. */
#define ATON_ACTIV_FUNC_BSHIFT_P  0

/** Read the content of the BSHIFT field of the FUNC register. */
#define ATON_ACTIV_FUNC_GET_BSHIFT(REG)  ATON_GET_FIELD(REG, ATON_ACTIV_FUNC_BSHIFT_LSB, ATON_ACTIV_FUNC_BSHIFT_W)

/** Modify the content of the BSHIFT field of the FUNC register. */
#define ATON_ACTIV_FUNC_SET_BSHIFT(REG, DATA)  ATON_SET_FIELD(REG, ATON_ACTIV_FUNC_BSHIFT_LSB, ATON_ACTIV_FUNC_BSHIFT_W, DATA)


/**
 * Get the description of the BSHIFT field of FUNC register.
 *
 * \return the description of the BSHIFT field of FUNC register
 */

static inline const int8_t *ATON_ACTIV_FUNC_BSHIFT_GetdDesc(void)
{
  return (const int8_t *)ATON_ACTIV_FUNC_BSHIFT_DESC;
}


/**
 * Read the content of the BSHIFT field of the FUNC register.
 *
 * \param[in] reg is the value of the FUNC register
 *
 * \return the content of the BSHIFT field belonging to FUNC register
 */

static inline uint32_t ATON_ACTIV_FUNC_Get_BSHIFT(uint32_t reg)
{
  return ATON_ACTIV_FUNC_GET_BSHIFT(reg);
}


/**
 * Write the content of the BSHIFT field of the FUNC register.
 *
 * \param[in] reg  is the value of the FUNC register
 * \param[in] data is 5-bit value that must be written to the field
 *
 * \return the new content of the BSHIFT field belonging to FUNC register
 */

static inline uint32_t ATON_ACTIV_FUNC_Set_BSHIFT(uint32_t reg, uint32_t data)
{
  return ATON_ACTIV_FUNC_SET_BSHIFT(reg, data);
}


/* ---------------------------------------------------------- SIGNEDOP field of the FUNC register ----------------------------------------------------------- */

/** Description of the SIGNEDOP field of the FUNC register. */
#define ATON_ACTIV_FUNC_SIGNEDOP_DESC  "Signed/unsigned activations"

/** Offset of the SIGNEDOP field of the FUNC register. */
#define ATON_ACTIV_FUNC_SIGNEDOP_LSB  20UL

/** Size in bits of the SIGNEDOP field of the FUNC register. */
#define ATON_ACTIV_FUNC_SIGNEDOP_W  (1UL)

/** Mask for retrieving the SIGNEDOP field of the FUNC register. */
#define ATON_ACTIV_FUNC_SIGNEDOP_MASK  ATON_FIELD_MASK(20UL, 1UL)

/** Reset value of the SIGNEDOP field of the FUNC register. */
#define ATON_ACTIV_FUNC_SIGNEDOP_DT  0x0UL

/** Access rights of the SIGNEDOP field of the FUNC register. */
#define ATON_ACTIV_FUNC_SIGNEDOP_AC  "RW"

/** Check whether access to the SIGNEDOP field of the FUNC register is secured or not. */
#define ATON_ACTIV_FUNC_SIGNEDOP_S  0

/** Check whether access to the SIGNEDOP field of the FUNC register is privileged or not. */
#define ATON_ACTIV_FUNC_SIGNEDOP_P  0

/** Read the content of the SIGNEDOP field of the FUNC register. */
#define ATON_ACTIV_FUNC_GET_SIGNEDOP(REG)  ATON_GET_FIELD(REG, ATON_ACTIV_FUNC_SIGNEDOP_LSB, ATON_ACTIV_FUNC_SIGNEDOP_W)

/** Modify the content of the SIGNEDOP field of the FUNC register. */
#define ATON_ACTIV_FUNC_SET_SIGNEDOP(REG, DATA)  ATON_SET_FIELD(REG, ATON_ACTIV_FUNC_SIGNEDOP_LSB, ATON_ACTIV_FUNC_SIGNEDOP_W, DATA)


/**
 * Get the description of the SIGNEDOP field of FUNC register.
 *
 * \return the description of the SIGNEDOP field of FUNC register
 */

static inline const int8_t *ATON_ACTIV_FUNC_SIGNEDOP_GetdDesc(void)
{
  return (const int8_t *)ATON_ACTIV_FUNC_SIGNEDOP_DESC;
}


/**
 * Read the content of the SIGNEDOP field of the FUNC register.
 *
 * \param[in] reg is the value of the FUNC register
 *
 * \return the content of the SIGNEDOP field belonging to FUNC register
 */

static inline uint32_t ATON_ACTIV_FUNC_Get_SIGNEDOP(uint32_t reg)
{
  return ATON_ACTIV_FUNC_GET_SIGNEDOP(reg);
}


/**
 * Write the content of the SIGNEDOP field of the FUNC register.
 *
 * \param[in] reg  is the value of the FUNC register
 * \param[in] data is 1-bit value that must be written to the field
 *
 * \return the new content of the SIGNEDOP field belonging to FUNC register
 */

static inline uint32_t ATON_ACTIV_FUNC_Set_SIGNEDOP(uint32_t reg, uint32_t data)
{
  return ATON_ACTIV_FUNC_SET_SIGNEDOP(reg, data);
}


/* ----------------------------------------------------------- BWIDTH field of the FUNC register ------------------------------------------------------------ */

/** Description of the BWIDTH field of the FUNC register. */
#define ATON_ACTIV_FUNC_BWIDTH_DESC  "Number of MSB bits of the input activation to be used to address ROM0. This field configures the number of outer segments (max outer segments = 32). Valid values range = 0,1,2,3,4 and 5 corresponding to 1,2,4,8,16 and 32 outer segment(s) respectively"

/** Offset of the BWIDTH field of the FUNC register. */
#define ATON_ACTIV_FUNC_BWIDTH_LSB  23UL

/** Size in bits of the BWIDTH field of the FUNC register. */
#define ATON_ACTIV_FUNC_BWIDTH_W  (3UL)

/** Mask for retrieving the BWIDTH field of the FUNC register. */
#define ATON_ACTIV_FUNC_BWIDTH_MASK  ATON_FIELD_MASK(23UL, 3UL)

/** Reset value of the BWIDTH field of the FUNC register. */
#define ATON_ACTIV_FUNC_BWIDTH_DT  0x0UL

/** Access rights of the BWIDTH field of the FUNC register. */
#define ATON_ACTIV_FUNC_BWIDTH_AC  "RW"

/** Check whether access to the BWIDTH field of the FUNC register is secured or not. */
#define ATON_ACTIV_FUNC_BWIDTH_S  0

/** Check whether access to the BWIDTH field of the FUNC register is privileged or not. */
#define ATON_ACTIV_FUNC_BWIDTH_P  0

/** Read the content of the BWIDTH field of the FUNC register. */
#define ATON_ACTIV_FUNC_GET_BWIDTH(REG)  ATON_GET_FIELD(REG, ATON_ACTIV_FUNC_BWIDTH_LSB, ATON_ACTIV_FUNC_BWIDTH_W)

/** Modify the content of the BWIDTH field of the FUNC register. */
#define ATON_ACTIV_FUNC_SET_BWIDTH(REG, DATA)  ATON_SET_FIELD(REG, ATON_ACTIV_FUNC_BWIDTH_LSB, ATON_ACTIV_FUNC_BWIDTH_W, DATA)


/**
 * Get the description of the BWIDTH field of FUNC register.
 *
 * \return the description of the BWIDTH field of FUNC register
 */

static inline const int8_t *ATON_ACTIV_FUNC_BWIDTH_GetdDesc(void)
{
  return (const int8_t *)ATON_ACTIV_FUNC_BWIDTH_DESC;
}


/**
 * Read the content of the BWIDTH field of the FUNC register.
 *
 * \param[in] reg is the value of the FUNC register
 *
 * \return the content of the BWIDTH field belonging to FUNC register
 */

static inline uint32_t ATON_ACTIV_FUNC_Get_BWIDTH(uint32_t reg)
{
  return ATON_ACTIV_FUNC_GET_BWIDTH(reg);
}


/**
 * Write the content of the BWIDTH field of the FUNC register.
 *
 * \param[in] reg  is the value of the FUNC register
 * \param[in] data is 3-bit value that must be written to the field
 *
 * \return the new content of the BWIDTH field belonging to FUNC register
 */

static inline uint32_t ATON_ACTIV_FUNC_Set_BWIDTH(uint32_t reg, uint32_t data)
{
  return ATON_ACTIV_FUNC_SET_BWIDTH(reg, data);
}


/* ***************************************************** ACTIVPARAM2 register of one of the ACTIV Units ***************************************************** */

/** Offset of the ACTIVPARAM2 register from the base address of the ACTIV Unit. */
#define ATON_ACTIV_ACTIVPARAM2_OFFSET  0x10UL

/** Reset value of the ACTIVPARAM2 register of the ACTIV Unit. */
#define ATON_ACTIV_ACTIVPARAM2_DT \
  (ATON_ACTIV_ACTIVPARAM2_PARAM2_DT << ATON_ACTIV_ACTIVPARAM2_PARAM2_LSB)



/** Description of the ACTIVPARAM2 register. */
#define ATON_ACTIV_ACTIVPARAM2_DESC  "additional activation parameters"

/** Address of the ACTIVPARAM2 register of one of the ACTIV Units. */
#define ATON_ACTIV_ACTIVPARAM2_ADDR(UNIT)  (ATON_ACTIV_BASE(UNIT) + ATON_ACTIV_ACTIVPARAM2_OFFSET)

/** Get the content of the ACTIVPARAM2 register of one of the ACTIV Units. */
#define ATON_ACTIV_ACTIVPARAM2_GET(UNIT)  (*((volatile uint32_t *)(uintptr_t)ATON_ACTIV_ACTIVPARAM2_ADDR(UNIT)))

/** Set the content of the ACTIVPARAM2 register of one of the ACTIV Units. */
#define ATON_ACTIV_ACTIVPARAM2_SET(UNIT, DATA)  do { *((volatile uint32_t *)(uintptr_t)ATON_ACTIV_ACTIVPARAM2_ADDR(UNIT)) = (DATA); } while (0);


/**
 * Get the description of ACTIVPARAM2 register.
 *
 * \return the description of ACTIVPARAM2 register
 */

static inline const int8_t *ATON_ACTIV_ACTIVPARAM2_GetDesc(void)
{
  return (const int8_t *)ATON_ACTIV_ACTIVPARAM2_DESC;
}


/**
 * Get the offset of the ACTIVPARAM2 register.
 *
 * \return the offset of ACTIVPARAM2 register
 */

static inline uint32_t ATON_ACTIV_ACTIVPARAM2_GetOffset(void)
{
  return ATON_ACTIV_ACTIVPARAM2_OFFSET;
}


/**
 * Get the address of the ACTIVPARAM2 register.
 *
 * \param[in] instance is the index of the Unit (among the ACTIV Units) containing the ACTIVPARAM2 register whose address must be returned
 *                     (it must be <em>instance \< 2<\em>)
 *
 * \return the address of ACTIVPARAM2 register belonging to Unit having index \e instance among the ACTIV Units
 */

static inline uint32_t ATON_ACTIV_ACTIVPARAM2_GetAddr(uint32_t instance)
{
  return ATON_ACTIV_ACTIVPARAM2_ADDR(instance);
}


/**
 * Read the content of the ACTIVPARAM2 register.
 *
 * \param[in] instance is the index of the Unit (among the ACTIV Units) containing the ACTIVPARAM2 register whose content must be retrieved
 *                     (it must be <em>instance \< 2<\em>)
 *
 * \return the content of ACTIVPARAM2 register belonging to Unit having index \e instance among the ACTIV Units
 */

static inline uint32_t ATON_ACTIV_ACTIVPARAM2_Get(uint32_t instance)
{
  return ATON_ACTIV_ACTIVPARAM2_GET(instance);
}


/**
 * Write the content of the ACTIVPARAM2 register.
 *
 * \param[in] instance is the index of the Unit (among the ACTIV Units) containing the ACTIVPARAM2 register whose content must be modified
 *                     (it must be <em>instance \< 2<\em>)
 * \param[in] data     is 32-bit value that must be written to the register
 */

static inline void ATON_ACTIV_ACTIVPARAM2_Set(uint32_t instance, uint32_t data)
{
  ATON_ACTIV_ACTIVPARAM2_SET(instance, data);
}


/* -------------------------------------------------------- PARAM2 field of the ACTIVPARAM2 register -------------------------------------------------------- */

/** Description of the PARAM2 field of the ACTIVPARAM2 register. */
#define ATON_ACTIV_ACTIVPARAM2_PARAM2_DESC  "zero offset for TRELU operation for use in scale/offset integer arithmetic"

/** Offset of the PARAM2 field of the ACTIVPARAM2 register. */
#define ATON_ACTIV_ACTIVPARAM2_PARAM2_LSB  0UL

/** Size in bits of the PARAM2 field of the ACTIVPARAM2 register. */
#define ATON_ACTIV_ACTIVPARAM2_PARAM2_W  (16UL)

/** Mask for retrieving the PARAM2 field of the ACTIVPARAM2 register. */
#define ATON_ACTIV_ACTIVPARAM2_PARAM2_MASK  ATON_FIELD_MASK(0UL, 16UL)

/** Reset value of the PARAM2 field of the ACTIVPARAM2 register. */
#define ATON_ACTIV_ACTIVPARAM2_PARAM2_DT  0x0UL

/** Access rights of the PARAM2 field of the ACTIVPARAM2 register. */
#define ATON_ACTIV_ACTIVPARAM2_PARAM2_AC  "RW"

/** Check whether access to the PARAM2 field of the ACTIVPARAM2 register is secured or not. */
#define ATON_ACTIV_ACTIVPARAM2_PARAM2_S  0

/** Check whether access to the PARAM2 field of the ACTIVPARAM2 register is privileged or not. */
#define ATON_ACTIV_ACTIVPARAM2_PARAM2_P  0

/** Read the content of the PARAM2 field of the ACTIVPARAM2 register. */
#define ATON_ACTIV_ACTIVPARAM2_GET_PARAM2(REG)  ATON_GET_FIELD(REG, ATON_ACTIV_ACTIVPARAM2_PARAM2_LSB, ATON_ACTIV_ACTIVPARAM2_PARAM2_W)

/** Modify the content of the PARAM2 field of the ACTIVPARAM2 register. */
#define ATON_ACTIV_ACTIVPARAM2_SET_PARAM2(REG, DATA)  ATON_SET_FIELD(REG, ATON_ACTIV_ACTIVPARAM2_PARAM2_LSB, ATON_ACTIV_ACTIVPARAM2_PARAM2_W, DATA)


/**
 * Get the description of the PARAM2 field of ACTIVPARAM2 register.
 *
 * \return the description of the PARAM2 field of ACTIVPARAM2 register
 */

static inline const int8_t *ATON_ACTIV_ACTIVPARAM2_PARAM2_GetdDesc(void)
{
  return (const int8_t *)ATON_ACTIV_ACTIVPARAM2_PARAM2_DESC;
}


/**
 * Read the content of the PARAM2 field of the ACTIVPARAM2 register.
 *
 * \param[in] reg is the value of the ACTIVPARAM2 register
 *
 * \return the content of the PARAM2 field belonging to ACTIVPARAM2 register
 */

static inline uint32_t ATON_ACTIV_ACTIVPARAM2_Get_PARAM2(uint32_t reg)
{
  return ATON_ACTIV_ACTIVPARAM2_GET_PARAM2(reg);
}


/**
 * Write the content of the PARAM2 field of the ACTIVPARAM2 registe