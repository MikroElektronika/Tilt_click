/*
Example for Tilt Click

    Date          : Feb 2019.
    Author        : Nenad Filipovic

Test configuration MSP :
    
    MCU              : MSP432
    Dev. Board       : Clicker 2 for MSP432
    ARM Compiler ver : v6.1.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes GPIO, sets PWM and INT pins as input.
- Application Initialization - Initialization driver enable's - GPIO and start write log.
- Application Task - (code snippet) This is an example which demonstrates the use of Tilt Click board.
     Detect the movement's direction of RPI-1035 Surface Mount Type 4-Direction Detector on Tilt click board.
     Results are being sent to the Usart Terminal where you can track their changes.
     All data logs on usb uart when the movement's direction is changed.

*/

#include "Click_Tilt_types.h"
#include "Click_Tilt_config.h"


uint8_t tiltDirection;
uint8_t tiltDirectionOld = 0;

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_PWM_PIN, _GPIO_INPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_INT_PIN, _GPIO_INPUT );

    mikrobus_logInit( _MIKROBUS2, 9600 );

    mikrobus_logWrite( "-------------", _LOG_LINE );
    mikrobus_logWrite( " Tilt  Click ", _LOG_LINE );
    mikrobus_logWrite( "-------------", _LOG_LINE );
    Delay_100ms();
}

void applicationInit()
{
    tilt_gpioDriverInit( (T_TILT_P)&_MIKROBUS1_GPIO );
    Delay_100ms();

    mikrobus_logWrite( " Initialized ", _LOG_LINE );
    mikrobus_logWrite( "-------------", _LOG_LINE );
}

void applicationTask()
{
    tiltDirection = tilt_direction();

    if ( tiltDirectionOld != tiltDirection )
    {
        if ( tiltDirection == _TILT_LEFT_DETECTION )
            mikrobus_logWrite( "    LEFT     ", _LOG_LINE );

        if ( tiltDirection == _TILT_RIGHT_DETECTION )
            mikrobus_logWrite( "    RIGHT    ", _LOG_LINE );

        if ( tiltDirection == _TILT_UP_DETECTION )
            mikrobus_logWrite( "     UP      ", _LOG_LINE );

        if ( tiltDirection == _TILT_DOWN_DETECTION )
            mikrobus_logWrite( "    DOWN     ", _LOG_LINE );

        tiltDirectionOld = tiltDirection;
        mikrobus_logWrite( "-------------", _LOG_LINE );
    }
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
            applicationTask();
    }
}