![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# Tilt Click

---

- **CIC Prefix**  : TILT
- **Author**      : Nenad Filipovic
- **Verison**     : 1.0.0
- **Date**        : Feb 2019.

---

### Software Support

We provide a library for the Tilt Click on our [LibStock](https://libstock.mikroe.com/projects/view/1232/tilt-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

The library covers all the necessary functions to control Tilt Click board.
Tilt click communicates with the target board via GPIO protocol, PWM and INT pins. 
This library contains drivers to detect tilt movement's direction: left, right, up or down.

Key functions :

- ``` uint8_t tilt_direction() ``` - Check the tilt movement's direction function.
- ``` uint8_t tilt_left() ``` - Check the tilt left movement's direction function.
- ``` uint8_t tilt_up() ``` - Check the tilt up movement's direction function.

**Examples Description**

The application is composed of three sections :

- System Initialization - Initializes GPIO, sets PWM and INT pins as input.
- Application Initialization - Initialization driver enable's - GPIO and start write log.
- Application Task - (code snippet) This is an example which demonstrates the use of Tilt Click board.
     Detect the movement's direction of RPI-1035 Surface Mount Type 4-Direction Detector on Tilt click board.
     Results are being sent to the Usart Terminal where you can track their changes.
     All data logs on usb uart when the movement's direction is changed.


```.c

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

```



The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/1232/tilt-click) page.

Other mikroE Libraries used in the example:

- GPIO
- UART

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
