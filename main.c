/*
 * File:   main.c
 * Author: David
 *
 * Created on March 15, 2019, 10:36 PM
 */


#include <xc.h>
#include "config.h"
#include "delay.h"
#include "adc1.h"

void main(void) {
    configure_chip();
    long value = 0;
    while(1)
    {
        value = class2_adc_read(17);
        delay_ms(250);
    }
    
    return;
}
