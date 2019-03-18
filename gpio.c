/*
 * File:   gpio.c
 * Author: David
 *
 * Created on March 17, 2019, 6:20 PM
 */

#include <xc.h>
#include "gpio.h"

void set_gpio_pin(int pin_value, int state)
{
    if (pin_value == RB0  || pin_value == RB1  || pin_value == RB2  ||
        pin_value == RB3  || pin_value == RB4  || pin_value == RB5  ||
        pin_value == RB6  || pin_value == RB7  || pin_value == RB8  ||
        pin_value == RB9  || pin_value == RB10 || pin_value == RB11 ||
        pin_value == RB12 || pin_value == RB13 || pin_value == RB14 ||
        pin_value == RB15)
    {
        if (state == INPUT)
        {
            TRISB = TRISB ^ (0x01 << pin_value);
            return;
        }
        else if (state == OUTPUT)
        {
            TRISB = TRISB & (~(0x01 << pin_value));
            return;
        }
    }
    
    else if (pin_value == RC12  || pin_value == RC13  || pin_value == RC14 ||
             pin_value == RC15)
    {
        if (state == INPUT)
        {
            TRISC = TRISC ^ (0x01 << (pin_value - 4));
            return;
        }
        else if (state == OUTPUT)
        {
            TRISC = TRISC & (~(0x01 << (pin_value - 4)));
            return;
        }
    }
    
    else if (pin_value == RD0 || pin_value == RD1  || pin_value == RD2 ||
             pin_value == RD3 || pin_value == RD4  || pin_value == RD5 ||
             pin_value == RD9 || pin_value == RD10 || pin_value == RD11)
    {
        if (state == INPUT)
        {
            TRISD = TRISD ^ (0x01 << (pin_value - 20));
            return;
        }
        else if (state == OUTPUT)
        {
            TRISD = TRISD & (~(0x01 << (pin_value - 20)));
            return;
        }
    }
    
    else if (pin_value == RE0 || pin_value == RE1  || pin_value == RE2 ||
             pin_value == RE3 || pin_value == RE4  || pin_value == RE5 ||
             pin_value == RE6 || pin_value == RE7)
    {
        if (state == INPUT)
        {
            TRISE = TRISE ^ (0x01 << (pin_value - 39));
            return;
        }
        else if (state == OUTPUT)
        {
            TRISE = TRISE & (~(0x01 << (pin_value - 39)));
            return;
        }
    }
    
    else if (pin_value == RF0 || pin_value == RF1  || pin_value == RF3 ||
             pin_value == RF4 || pin_value == RF5)
    {
        if (state == INPUT)
        {
            TRISF = TRISF ^ (0x01 << (pin_value - 37));
            return;
        }
        else if (state == OUTPUT)
        {
            TRISF = TRISF & (~(0x01 << (pin_value - 37)));
            return;
        }
    }
    
    else if (pin_value == RG6 || pin_value == RG7  || pin_value == RG8 ||
             pin_value == RG9)
    {
        if (state == INPUT)
        {
            TRISG = TRISG ^ (0x01 << (pin_value - 46));
            return;
        }
        else if (state == OUTPUT)
        {
            TRISG = TRISG & (~(0x01 << (pin_value - 46)));
            return;
        }
    }
    
    return;
}
int set_output(int pin_value, int output_value)
{
    if (pin_value == RB0  || pin_value == RB1  || pin_value == RB2  ||
        pin_value == RB3  || pin_value == RB4  || pin_value == RB5  ||
        pin_value == RB9  || pin_value == RB10 || pin_value == RB11 ||
        pin_value == RB12 || pin_value == RB13 || pin_value == RB14 ||
        pin_value == RB15)
    {
        if (output_value == HIGH)
        {
            PORTB = PORTB ^ (0x01 << pin_value);
            return PORTB;
        }
        else if (output_value == LOW)
        {
            PORTB = PORTB & (~(0x01 << pin_value));
            return PORTB;
        }
    }
    
    else if (pin_value == RC12  || pin_value == RC13  || pin_value == RC14 ||
             pin_value == RC15)
    {
        if (output_value == HIGH)
        {
            PORTC = PORTC ^ (0x01 << (pin_value - 4));
            return PORTC;
        }
        else if (output_value == LOW)
        {
            PORTC = PORTC & (~(0x01 << (pin_value - 4)));
            return PORTC;
        }
    }
    
    else if (pin_value == RD0 || pin_value == RD1  || pin_value == RD2 ||
             pin_value == RD3 || pin_value == RD4  || pin_value == RD5 ||
             pin_value == RD9 || pin_value == RD10 || pin_value == RD11)
    {
        if (output_value == HIGH)
        {
            PORTD = PORTD ^ (0x01 << (pin_value - 20));
            return PORTD;
        }
        else if (output_value == LOW)
        {
            PORTD = PORTD & (~(0x01 << (pin_value - 20)));
            return PORTD;
        }
    }
    
    else if (pin_value == RE0 || pin_value == RE1  || pin_value == RE2 ||
             pin_value == RE3 || pin_value == RE4  || pin_value == RE5 ||
             pin_value == RE6 || pin_value == RE7)
    {
        if (output_value == HIGH)
        {
            PORTE = PORTE ^ (0x01 << (pin_value - 39));
            return PORTE;
        }
        else if (output_value == LOW)
        {
            PORTE = PORTE & (~(0x01 << (pin_value - 39)));
            return PORTE;
        }
    }
    
    else if (pin_value == RF0 || pin_value == RF1  || pin_value == RF3 ||
             pin_value == RF4 || pin_value == RF5)
    {
        if (output_value == HIGH)
        {
            PORTF = PORTF ^ (0x01 << (pin_value - 47));
            return PORTF;
        }
        else if (output_value == LOW)
        {
            PORTF = PORTF & (~(0x01 << (pin_value - 47)));
            return PORTF;
        }
    }
    
    else if (pin_value == RG6 || pin_value == RG7  || pin_value == RG8 ||
             pin_value == RG9)
    {
        if (output_value == HIGH)
        {
            PORTG = PORTG ^ (0x01 << (pin_value - 56));
            return PORTG;
        }
        else if (output_value == LOW)
        {
            PORTG = PORTG & (~(0x01 << (pin_value - 56)));
            return PORTG;
        }
    }
    return;
}
int read_input(int pin_value)
{
    return 1;
}
int get_pin_value(int pin_value)
{
    return 1;
}