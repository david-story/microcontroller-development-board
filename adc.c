/*
 * File:   adc.c
 * Author: David
 *
 * Created on March 16, 2019, 5:50 PM
 */


#include <xc.h>
#include "adc.h"

void adc_configure(int adc_num)
{
    // copy calibration values from DEVADCx to ADCxCFG
    
    // Configure AICPMPEN bit (ADCCON1<12> and IOANCPEN bit (CFGCON<7>) = 1)
    // iff VDD < 2.5 v else it defaults to 0 if VDD >= 2.5 v
    
    // Begin ADC configuration
    
    // Configure ADCCON1: keep ON bit = 0
    ADCCON1 = 0b00000000011000000010011001110000;
    
    // Configure ADCCON2: pay attention to ADC-DIV<6:0> and SAMC<9:0>
    
    // Configure ADCANCON: keep all ANENx bit = 0, WKUPCLKCNT bits = 0xA
    
    // Configure ADCCON3: keep all DIGENx = 0, attention to ADCSEL<1:0>, CONCLKDIV<5:0>,
    // and VREFSEL<2:0>
    
    // Configure ADCxTime
    
    // Configure ADCDIVx<6:0>
    
    // Configure SAMCx<9:0>
    
    // Configure ADCTRGMODE
    
    // Configure ADCIMCONx
    
    // Configure ADCTRGSNS
    
    // Configure ADCCSSx
    
    // Configure ADCGIRQENx
    
    // Configure ADCTRGx
    
    // Configure ADCBASE
    
    // Configure Comparators / Filters
    
}

long adc_read(int adc_num)
{
    long val;
    val = 0xFFFF;
    return val;
}