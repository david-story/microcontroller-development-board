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

void main(void) {
    configure_chip();
    while(1)
    {
        PORTG = ~PORTG;
        PORTB = ~PORTB;
        PORTE = ~PORTE;
        delay_ms(250);
    }
    
    return;
}
