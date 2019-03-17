/*
 * File:   adc.c
 * Author: David
 *
 * Created on March 16, 2019, 5:50 PM
 */


#include <xc.h>
#include "adc.h"

void configure_class1_adc()
{
    /* initialize ADC calibration setting */
    ADC0CFG = DEVADC0;
    ADC1CFG = DEVADC1;
    ADC2CFG = DEVADC2;
    ADC3CFG = DEVADC3;
    ADC4CFG = DEVADC4;
    ADC7CFG = DEVADC7;
    
    /* Configure ADCCON1 */
    ADCCON1 = 0;                    // No ADCCON1 features are enabled including: Stop-in-Idle, turbo,
   
    // CVD mode, Fractional mode and scan trigger source.
    /* Configure ADCCON2 */
    ADCCON2 = 0;                    // Since, we are using only the Class 1 inputs, no setting is
   
    // required for ADCDIV
    /* Initialize warm up time register */
    ADCANCON = 0;
    ADCANCONbits.WKUPCLKCNT = 5;    // Wakeup exponent = 32 * TADx
   
    /* Clock setting */
    ADCCON3 = 0;
    ADCCON3bits.ADCSEL = 0;         // Select input clock source
    ADCCON3bits.CONCLKDIV = 1;      // Control clock frequency is half of input clock
    ADCCON3bits.VREFSEL = 0;        // Select AVDD and AVSS as reference source

    /* Select ADC sample time and conversion clock */
    ADC0TIMEbits.ADCDIV = 1;        // ADC0 clock frequency is half of control clock = TAD0
    ADC0TIMEbits.SAMC = 5;          // ADC0 sampling time = 5 * TAD0
    ADC0TIMEbits.SELRES = 3;        // ADC0 resolution is 12 bits
    ADC1TIMEbits.ADCDIV = 1;        // ADC1 clock frequency is half of control clock = TAD1
    ADC1TIMEbits.SAMC = 5;          // ADC1 sampling time = 5 * TAD1
    ADC1TIMEbits.SELRES = 3;        // ADC1 resolution is 12 bits
    ADC2TIMEbits.ADCDIV = 1;        // ADC2 clock frequency is half of control clock = TAD2
    ADC2TIMEbits.SAMC = 5;          // ADC2 sampling time = 5 * TAD2
    ADC2TIMEbits.SELRES = 3;        // ADC2 resolution is 12 bits

    /* Select analog input for ADC modules, no presync trigger, not sync sampling */
    ADCTRGMODEbits.SH0ALT = 0;      // ADC0 = AN0
    ADCTRGMODEbits.SH1ALT = 0;      // ADC1 = AN1
    ADCTRGMODEbits.SH2ALT = 0;      // ADC2 = AN2

    /* Select ADC input mode */
    ADCIMCON1bits.SIGN0 = 0;        // unsigned data format
    ADCIMCON1bits.DIFF0 = 0;        // Single ended mode
    ADCIMCON1bits.SIGN1 = 0;        // unsigned data format
    ADCIMCON1bits.DIFF1 = 0;        // Single ended mode
    ADCIMCON1bits.SIGN2 = 0;        // unsigned data format
    ADCIMCON1bits.DIFF2 = 0;        // Single ended mode

    /* Configure ADCGIRQENx */
    ADCGIRQEN1 = 0;                 // No interrupts are used
    ADCGIRQEN2 = 0;

    /* Configure ADCCSSx */
    ADCCSS1 = 0;                    // No scanning is used
    ADCCSS2 = 0;

    /* Configure ADCCMPCONx */
    ADCCMPCON1 = 0;                 // No digital comparators are used. Setting the ADCCMPCONx
    ADCCMPCON2 = 0;                 // register to '0' ensures that the comparator is disabled.
    ADCCMPCON3 = 0;                 // Other registers are ?don't care?.
    ADCCMPCON4 = 0;
    ADCCMPCON5 = 0;
    ADCCMPCON6 = 0;

     /* Configure ADCFLTRx */
     ADCFLTR1 = 0;                  // No oversampling filters are used.
     ADCFLTR2 = 0;
     ADCFLTR3 = 0;
     ADCFLTR4 = 0;
     ADCFLTR5 = 0;
     ADCFLTR6 = 0;

     /* Set up the trigger sources */
     ADCTRGSNSbits.LVL0 = 0;        // Edge trigger
     ADCTRGSNSbits.LVL1 = 0;        // Edge trigger
     ADCTRGSNSbits.LVL2 = 0;        // Edge trigger
     ADCTRG1bits.TRGSRC0 = 1;       // Set AN0 to trigger from software.
     ADCTRG1bits.TRGSRC1 = 1;       // Set AN1 to trigger from software.
     ADCTRG1bits.TRGSRC2 = 1;       // Set AN2 to trigger from software.
     ADCTRG1bits.TRGSRC3 = 1;       // Set AN3 to trigger from software.
     ADCTRG2bits.TRGSRC4 = 1;       // Set AN4 to trigger from software.
     ADCTRG2bits.TRGSRC7 = 1;       // Set AN7 to trigger from software.
     
     /* Early interrupt */
     ADCEIEN1 = 0;                  // No early interrupt
     ADCEIEN2 = 0;
}

void class1_adc_on(int adc_num)
{
    /* Turn the ADC on */
    ADCCON1bits.ON = 1;
    
    /* Wait for voltage reference to be stable */
    while(!ADCCON2bits.BGVRRDY);    // Wait until the reference voltage is ready
    while(ADCCON2bits.REFFLT);      // Wait if there is a fault with the reference voltage
    
    if (adc_num == 0)
    {
        /* Enable clock to analog circuit */
        ADCANCONbits.ANEN0 = 1;         // Enable the clock to analog bias
        while(!ADCANCONbits.WKRDY0);    // Wait until ADC0 is ready
        ADCCON3bits.DIGEN0 = 1;         // Enable ADC0
    }
    
    else if(adc_num == 1)
    {
        /* Enable clock to analog circuit */
        ADCANCONbits.ANEN1 = 1;         // Enable the clock to analog bias
        /* Wait for ADC to be ready */
        while(!ADCANCONbits.WKRDY1);    // Wait until ADC1 is ready
        /* Enable the ADC module */
        ADCCON3bits.DIGEN1 = 1;         // Enable ADC1
    }
    
     else if(adc_num == 2)
    {
         /* Enable clock to analog circuit */
        ADCANCONbits.ANEN2 = 1;         // Enable the clock to analog bias
        /* Wait for ADC to be ready */
        while(!ADCANCONbits.WKRDY2);    // Wait until ADC2 is ready
        /* Enable the ADC module */
        ADCCON3bits.DIGEN2 = 1;         // Enable ADC2
    }
    
     else if(adc_num == 3)
    {
        /* Enable clock to analog circuit */
        ADCANCONbits.ANEN3 = 1;         // Enable the clock to analog bias
        /* Wait for ADC to be ready */
        while(!ADCANCONbits.WKRDY3);    // Wait until ADC3 is ready
        /* Enable the ADC module */
        ADCCON3bits.DIGEN3 = 1;         // Enable ADC3
    }
    
     else if(adc_num == 4)
    {
        /* Enable clock to analog circuit */
        ADCANCONbits.ANEN4 = 1;         // Enable the clock to analog bias
        /* Wait for ADC to be ready */
        while(!ADCANCONbits.WKRDY4);    // Wait until ADC4 is ready
        /* Enable the ADC module */
        ADCCON3bits.DIGEN4 = 1;         // Enable ADC4
    }
    
     else if(adc_num == 7)
    {
        /* Enable clock to analog circuit */
        ADCANCONbits.ANEN7 = 1;         // Enable the clock to analog bias
        /* Wait for ADC to be ready */
        while(!ADCANCONbits.WKRDY7);    // Wait until ADC7 is ready
        /* Enable the ADC module */
        ADCCON3bits.DIGEN7 = 1;         // Enable ADC7
    }
    
     else
     {
        return;
     }
}

void class1_adc_off(int adc_num)
{
    /* Turn the ADC off */
    ADCCON1bits.ON = 0;
    
    if (adc_num == 0)
    {
        /* Disable clock to analog circuit */
        ADCANCONbits.ANEN0 = 0;         // Disable the clock to analog bias
        /* Disable the ADC module */
        ADCCON3bits.DIGEN0 = 0;         // Disable ADC0
    }
    
    else if (adc_num == 1)
    {
        /* Disable clock to analog circuit */
        ADCANCONbits.ANEN1 = 0;         // Disable the clock to analog bias
        /* Disable the ADC module */
        ADCCON3bits.DIGEN1 = 0;         // Disable ADC1
    }
    
    else if (adc_num == 2)
    {
        /* Disable clock to analog circuit */
        ADCANCONbits.ANEN2 = 0;         // Disable the clock to analog bias
        /* Disable the ADC module */
        ADCCON3bits.DIGEN2 = 0;         // Disable ADC1
    }
    
    else if (adc_num == 3)
    {
        /* Disable clock to analog circuit */
        ADCANCONbits.ANEN3 = 0;         // Disable the clock to analog bias
        /* Disable the ADC module */
        ADCCON3bits.DIGEN3 = 0;         // Disable ADC1
    }
    
    else if (adc_num == 4)
    {
        /* Disable clock to analog circuit */
        ADCANCONbits.ANEN4 = 0;         // Disable the clock to analog bias
        /* Disable the ADC module */
        ADCCON3bits.DIGEN4 = 0;         // Disable ADC1
    }
    
    else if (adc_num == 7)
    {
        /* Disable clock to analog circuit */
        ADCANCONbits.ANEN7 = 0;         // Disable the clock to analog bias
        /* Disable the ADC module */
        ADCCON3bits.DIGEN7 = 0;         // Disable ADC1
    }
    
    else
    {
        return;
    }
}

long class1_adc_read(int adc_num)
{  
    long result;
    if (adc_num == 0)
    {
        // turn ADC module on
        class1_adc_on(0);
        /* Trigger a conversion */
        ADCCON3bits.GSWTRG = 1;
        /* Wait the conversions to complete */
        while (ADCDSTAT1bits.ARDY0 == 0);
        // turn ADC module off
        /* fetch the result */
        result = ADCDATA0;
        class1_adc_off(0);
        return result;
    }
    
    else if (adc_num == 1)
    {
        // turn ADC module on
        class1_adc_on(1);
        /* Trigger a conversion */
        ADCCON3bits.GSWTRG = 1;
        /* Wait the conversions to complete */
        while (ADCDSTAT1bits.ARDY1 == 0);
        /* fetch the result */
        result = ADCDATA1;
        // turn ADC module off
        class1_adc_off(1);
        return result;
    }
    
    else if (adc_num == 2)
    {
        // turn ADC module on
        class1_adc_on(2);
        /* Trigger a conversion */
        ADCCON3bits.GSWTRG = 1;
        /* Wait the conversions to complete */
        while (ADCDSTAT1bits.ARDY2 == 0);
        /* fetch the result */
        result = ADCDATA2;
        // turn ADC module off
        class1_adc_off(2);
        return result;
    }
    
    else if (adc_num == 3)
    {
        // turn ADC module on
        class1_adc_on(3);
        /* Trigger a conversion */
        ADCCON3bits.GSWTRG = 1;
        /* Wait the conversions to complete */
        while (ADCDSTAT1bits.ARDY3 == 0);
        /* fetch the result */
        result = ADCDATA3;
        // turn ADC module off
        class1_adc_off(3);
        return result;
    }
    
    else if (adc_num == 4)
    {
        // turn ADC module on
        class1_adc_on(4);
        /* Trigger a conversion */
        ADCCON3bits.GSWTRG = 1;
        /* Wait the conversions to complete */
        while (ADCDSTAT1bits.ARDY4 == 0);
        /* fetch the result */
        result = ADCDATA4;
        // turn ADC module off
        class1_adc_off(4);
        return result;
    }
    
    else if (adc_num == 7)
    {
        // turn ADC module on
        class1_adc_on(7);
        /* Trigger a conversion */
        ADCCON3bits.GSWTRG = 1;
        /* Wait the conversions to complete */
        while (ADCDSTAT1bits.ARDY7 == 0);
        /* fetch the result */
        result = ADCDATA7;
        // turn ADC module off
        class1_adc_off(7);
        return result;
    }
 
    else
    {
        return;
    }
}