/*
 * File:   adc.c
 * Author: David
 *
 * Created on March 17, 2019, 4:29 PM
 */


#include <xc.h>
#include "adc.h"
#include "adc1.h"
#include "adc2.h"

long read_adc(int pin_value)
{
    int which_class;
    long result;
    which_class = adc_select(pin_value);
    if (which_class == 1)
    {
        result = class1_adc_read(pin_value);
        return result;
    }
    else if (which_class == 2)
    {
        result = class2_adc_read(pin_value);
        return result;
    }
    else
    {
        return;
    }
}

void set_adc(int pin_value)
{
    // sets analog values based on pin-out for
    // PIC32MZ2048EFH064
    
    if (pin_value == AN0)
    {
        // sets analog select as true
        ANSELBbits.ANSB0 = 1;
        // sets tri-state to input
        TRISBbits.TRISB0 = 1;
        return;
    }
    
    else if (pin_value == AN1)
    {
        // sets analog select as true
        ANSELBbits.ANSB1 = 1;
        // sets tri-state to input
        TRISBbits.TRISB1 = 1;
        return;
    }
    
    else if (pin_value == AN2)
    {
        // sets analog select as true
        ANSELBbits.ANSB2 = 1;
        // sets tri-state to input
        TRISBbits.TRISB2 = 1;
        return;
    }
    
    else if (pin_value == AN3)
    {
        // sets analog select as true
        ANSELBbits.ANSB3 = 1;
        // sets tri-state to input
        TRISBbits.TRISB3 = 1;
        return;
    }
    
    else if (pin_value == AN4)
    {
        // sets analog select as true
        ANSELBbits.ANSB4 = 1;
        // sets tri-state to input
        TRISBbits.TRISB4 = 1;
        return;
    }
    
    else if (pin_value == AN7)
    {
        // sets analog select as true
        ANSELBbits.ANSB12 = 1;
        // sets tri-state to input
        TRISBbits.TRISB12 = 1;
        return;
    }
    
    else if (pin_value == AN8)
    {
        // sets analog select as true
        ANSELBbits.ANSB13 = 1;
        // sets tri-state to input
        TRISBbits.TRISB13 = 1;
        return;
    }
    
    else if (pin_value == AN9)
    {
        // sets analog select as true
        ANSELBbits.ANSB14 = 1;
        // sets tri-state to input
        TRISBbits.TRISB14 = 1;
        return;
    }
    
    else if (pin_value == AN10)
    {
        // sets analog select as true
        ANSELBbits.ANSB15 = 1;
        // sets tri-state to input
        TRISBbits.TRISB15 = 1;
        return;
    }
    
    else if (pin_value == AN11)
    {
        // sets analog select as true
        ANSELGbits.ANSG9 = 1;
        // sets tri-state to input
        TRISGbits.TRISG9 = 1;
        return;
    }
    
    else if (pin_value == AN14)
    {
        // sets analog select as true
        ANSELGbits.ANSG6 = 1;
        // sets tri-state to input
        TRISGbits.TRISG6 = 1;
        return;
    }
    
    else if (pin_value == AN15)
    {
        // sets analog select as true
        ANSELEbits.ANSE7 = 1;
        // sets tri-state to input
        TRISEbits.TRISE7 = 1;
        return;
    }
    
    else if (pin_value == AN16)
    {
        // sets analog select as true
        ANSELEbits.ANSE6 = 1;
        // sets tri-state to input
        TRISEbits.TRISE6 = 1;
        return;
    }
    
    else if (pin_value == AN17)
    {
        // sets analog select as true
        ANSELEbits.ANSE5 = 1;
        // sets tri-state to input
        TRISEbits.TRISE5 = 1;
        return;
    }
    
    else if (pin_value == AN18)
    {
        // sets analog select as true
        ANSELEbits.ANSE4 = 1;
        // sets tri-state to input
        TRISEbits.TRISE4 = 1;
        return;
    }
    
    else
    {
        return;
    }
    
}

int adc_select(int pin_value)
{
    if(pin_value == AN0)
    {
        return 1;
    }
    
    else if(pin_value == AN1)
    {
        return 1;
    }
    
    else if(pin_value == AN2)
    {
        return 1;
    }
    
    else if(pin_value == AN3)
    {
        return 1;
    }
    
    else if(pin_value == AN4)
    {
        return 1;
    }
    
    else if(pin_value == AN7)
    {
        return 2;
    }
    
    else if(pin_value == AN8)
    {
        return 2;
    }
    
    else if(pin_value == AN9)
    {
        return 2;
    }
    
    else if(pin_value == AN10)
    {
        return 2;
    }
    
    else if(pin_value == AN11)
    {
        return 2;
    }
    
    else if(pin_value == AN14)
    {
        return 2;
    }
    
    else if(pin_value == AN15)
    {
        return 2;
    }
    
    else if(pin_value == AN16)
    {
        return 2;
    }
    
    else if(pin_value == AN17)
    {
        return 2;
    }
    
    else if(pin_value == AN18)
    {
        return 2;
    }
    
    else
    {
        return 0;
    }
}
