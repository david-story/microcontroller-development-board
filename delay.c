/*
 * File:   delay.c
 * Author: David
 *
 * Created on March 16, 2019, 4:48 PM
 */


#include <xc.h>
#include "delay.h"

#define SYS_FREQ 200000000 // Running at 200MHz

void delay_us(unsigned int us)
{
    // Convert microseconds us into how many clock ticks it will take
    us *= SYS_FREQ / 10000000 / 2; // Core Timer updates every 2 ticks

    _CP0_SET_COUNT(0); // Set Core Timer count to 0

    while (us > _CP0_GET_COUNT()); // Wait until Core Timer count reaches the number we calculated earlier
}

void delay_ms(int ms)
{
    delay_us(ms * 1000);
}