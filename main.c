/*
 * File:   main.c
 * Author: David
 *
 * Created on March 15, 2019, 10:36 PM
 */

#include <xc.h>
#include "config.h"
#include "delay.h"
#include "adc.h"
#include "gpio.h"

void main(void) {
    configure_chip();
    long value = 0;
    
    set_gpio_pin(RB5, INPUT);
    set_gpio_pin(RB4, INPUT);
    set_gpio_pin(RB3, INPUT);
    set_gpio_pin(RB2, INPUT);
    set_gpio_pin(RG9, INPUT);
   
    set_output(RB4, HIGH);
        
    while(1)
    {
        
    }
     
    return;
}
