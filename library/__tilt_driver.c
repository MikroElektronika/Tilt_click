/*
    __tilt_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__tilt_driver.h"
#include "__tilt_hal.c"

/* ------------------------------------------------------------------- MACROS */



/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __TILT_DRV_I2C__
static uint8_t _slaveAddress;
#endif

const uint8_t _TILT_NO_DETECTION                                            = 0;
const uint8_t _TILT_DETECTION                                               = 1;
const uint8_t _TILT_LEFT_DETECTION                                          = 2;
const uint8_t _TILT_RIGHT_DETECTION                                         = 3;
const uint8_t _TILT_UP_DETECTION                                            = 4;
const uint8_t _TILT_DOWN_DETECTION                                          = 5;



/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */

static uint8_t tilt_stateVO1();

static uint8_t tilt_stateVO2();

/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */

/* Check the state of VO1 ( PWM ) pin function */
static uint8_t tilt_stateVO1()
{
    return hal_gpio_pwmGet();
}

/* Check the state of VO2 ( INT ) pin function */
static uint8_t tilt_stateVO2()
{
    return hal_gpio_intGet();
}

/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __TILT_DRV_SPI__

void tilt_spiDriverInit(T_TILT_P gpioObj, T_TILT_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __TILT_DRV_I2C__

void tilt_i2cDriverInit(T_TILT_P gpioObj, T_TILT_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __TILT_DRV_UART__

void tilt_uartDriverInit(T_TILT_P gpioObj, T_TILT_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif

// GPIO Only Drivers - remove in other cases
void tilt_gpioDriverInit(T_TILT_P gpioObj)
{
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
}

/* ----------------------------------------------------------- IMPLEMENTATION */


/* Check the tilt left movement's direction function */
uint8_t tilt_left()
{
    uint8_t tmp;
    
    tmp = _TILT_NO_DETECTION;
    
    if ( tilt_stateVO1() == _TILT_DETECTION )
    {
        if ( tilt_stateVO2() == _TILT_NO_DETECTION )
        {
            tmp = _TILT_DETECTION;
        }
    }
    
    return tmp;
}

/* Check the tilt right movement's direction function */
uint8_t tilt_right()
{
    uint8_t tmp;

    tmp = _TILT_NO_DETECTION;

    if ( tilt_stateVO1() == _TILT_NO_DETECTION )
    {
        if ( tilt_stateVO2() == _TILT_DETECTION )
        {
            tmp = _TILT_DETECTION;
        }
    }

    return tmp;
}

/* Check the tilt up movement's direction function */
uint8_t tilt_up()
{
    uint8_t tmp;

    tmp = _TILT_NO_DETECTION;

    if ( tilt_stateVO1() == _TILT_NO_DETECTION )
    {
        if ( tilt_stateVO2() == _TILT_NO_DETECTION )
        {
            tmp = _TILT_DETECTION;
        }
    }

    return tmp;
}

/* Check the tilt down movement's direction function */
uint8_t tilt_down()
{
    uint8_t tmp;

    tmp = _TILT_NO_DETECTION;

    if ( tilt_stateVO1() == _TILT_DETECTION )
    {
        if ( tilt_stateVO2() == _TILT_DETECTION )
        {
            tmp = _TILT_DETECTION;
        }
    }

    return tmp;
}

/* Check the tilt movement's direction function */
uint8_t tilt_direction()
{
    uint8_t tmp;

    tmp = _TILT_NO_DETECTION;

    if ( tilt_left() )
    {
        tmp = _TILT_LEFT_DETECTION;
    }
    
    if ( tilt_right() )
    {
        tmp = _TILT_RIGHT_DETECTION;
    }
    
    if ( tilt_up() )
    {
        tmp = _TILT_UP_DETECTION;
    }
    
    if ( tilt_down() )
    {
        tmp = _TILT_DOWN_DETECTION;
    }

    return tmp;
}




/* -------------------------------------------------------------------------- */
/*
  __tilt_driver.c

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