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
#include "spi.h"

void main(void) {
    configure_chip();
    long value = 0;
    
    set_gpio_pin(RD0,  OUTPUT);
    set_gpio_pin(RD11, OUTPUT);
    set_gpio_pin(RD10, OUTPUT);
    set_gpio_pin(RD9,  OUTPUT);
    set_gpio_pin(RF5,  OUTPUT);
    set_gpio_pin(RF4,  OUTPUT);
    
    set_gpio_pin(RG9, OUTPUT);
   
    set_output(RD0,  HIGH);
    set_output(RD11, HIGH);
    set_output(RD10, HIGH);
    set_output(RD9,  HIGH);
    set_output(RF5,  HIGH);
    set_output(RF4,  HIGH);
        
    int iterator = 0;
    configure_spi();
    while(1)
    {
        spi_transmit(iterator);
        iterator++;
    }
     
    return;
}
