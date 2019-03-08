/*
    __tilt_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __tilt_driver.h
@brief    Tilt Driver
@mainpage Tilt Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   TILT
@brief      Tilt Click Driver
@{

| Global Library Prefix | **TILT** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Feb 2019.**      |
| Developer             | **Nenad Filipovic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _TILT_H_
#define _TILT_H_

/** 
 * @macro T_TILT_P
 * @brief Driver Abstract type 
 */
#define T_TILT_P    const uint8_t*

/** @defgroup TILT_COMPILE Compilation Config */              /** @{ */

//  #define   __TILT_DRV_SPI__                            /**<     @macro __TILT_DRV_SPI__  @brief SPI driver selector */
//  #define   __TILT_DRV_I2C__                            /**<     @macro __TILT_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __TILT_DRV_UART__                           /**<     @macro __TILT_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup TILT_VAR Variables */                           /** @{ */

extern const uint8_t _TILT_NO_DETECTION;
extern const uint8_t _TILT_DETECTION;
extern const uint8_t _TILT_LEFT_DETECTION;
extern const uint8_t _TILT_RIGHT_DETECTION;
extern const uint8_t _TILT_UP_DETECTION;
extern const uint8_t _TILT_DOWN_DETECTION;

                                                                       /** @} */
/** @defgroup TILT_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup TILT_INIT Driver Initialization */              /** @{ */

#ifdef   __TILT_DRV_SPI__
void tilt_spiDriverInit(T_TILT_P gpioObj, T_TILT_P spiObj);
#endif
#ifdef   __TILT_DRV_I2C__
void tilt_i2cDriverInit(T_TILT_P gpioObj, T_TILT_P i2cObj, uint8_t slave);
#endif
#ifdef   __TILT_DRV_UART__
void tilt_uartDriverInit(T_TILT_P gpioObj, T_TILT_P uartObj);
#endif

// GPIO Only Drivers - remove in other cases
void tilt_gpioDriverInit(T_TILT_P gpioObj);
                                                                       /** @} */
/** @defgroup TILT_FUNC Driver Functions */                   /** @{ */


/**
 * @brief Check the tilt left movement's direction function
 *
 * @return
 * - 0 : other movement direction;
 * - 1 : left movement direction;
 *
 * Function check the tilt left movement's direction
 * of RPI-1035 Surface Mount Type 4-Direction Detector on Tilt click board.
 */
uint8_t tilt_left();

/**
 * @brief Check the tilt right movement's direction function
 *
 * @return
 * - 0 : other movement direction;
 * - 1 : right movement direction;
 *
 * Function check the tilt right movement's direction
 * of RPI-1035 Surface Mount Type 4-Direction Detector on Tilt click board.
 */
uint8_t tilt_right();

/**
 * @brief Check the tilt up movement's direction function
 *
 * @return
 * - 0 : other movement direction;
 * - 1 : up movement direction;
 *
 * Function check the tilt up movement's direction
 * of RPI-1035 Surface Mount Type 4-Direction Detector on Tilt click board.
 */
uint8_t tilt_up();

/**
 * @brief Check the tilt down movement's direction function
 *
 * @return
 * - 0 : other movement direction;
 * - 1 : down movement direction;
 *
 * Function check the tilt down movement's direction
 * of RPI-1035 Surface Mount Type 4-Direction Detector on Tilt click board.
 */
uint8_t tilt_down();

/**
 * @brief Check the tilt movement's direction function
 *
 * @return
 * - 2 : left movement direction;
 * - 3 : right movement direction;
 * - 4 : up movement direction;
 * - 5 : down movement direction;
 *
 * Function check the tilt movement's direction: left, right, up or down,
 * of RPI-1035 Surface Mount Type 4-Direction Detector on Tilt click board.
 */
uint8_t tilt_direction();




                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_Tilt_STM.c
    @example Click_Tilt_TIVA.c
    @example Click_Tilt_CEC.c
    @example Click_Tilt_KINETIS.c
    @example Click_Tilt_MSP.c
    @example Click_Tilt_PIC.c
    @example Click_Tilt_PIC32.c
    @example Click_Tilt_DSPIC.c
    @example Click_Tilt_AVR.c
    @example Click_Tilt_FT90x.c
    @example Click_Tilt_STM.mbas
    @example Click_Tilt_TIVA.mbas
    @example Click_Tilt_CEC.mbas
    @example Click_Tilt_KINETIS.mbas
    @example Click_Tilt_MSP.mbas
    @example Click_Tilt_PIC.mbas
    @example Click_Tilt_PIC32.mbas
    @example Click_Tilt_DSPIC.mbas
    @example Click_Tilt_AVR.mbas
    @example Click_Tilt_FT90x.mbas
    @example Click_Tilt_STM.mpas
    @example Click_Tilt_TIVA.mpas
    @example Click_Tilt_CEC.mpas
    @example Click_Tilt_KINETIS.mpas
    @example Click_Tilt_MSP.mpas
    @example Click_Tilt_PIC.mpas
    @example Click_Tilt_PIC32.mpas
    @example Click_Tilt_DSPIC.mpas
    @example Click_Tilt_AVR.mpas
    @example Click_Tilt_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __tilt_driver.h

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */