/*
 * File:   adc2.c
 * Author: David
 *
 * Created on March 17, 2019, 12:50 PM
 */


#include <xc.h>
#include "adc2.h"

void configure_class2_adc()
{
    /* Configure ADCCON1 */
    ADCCON1bits.FRACT = 0;          // Do not use Fractional output format
    ADCCON1bits.SELRES = 3;         // ADC7 resolution is 12 bits
    ADCCON1bits.STRGSRC = 0;        // No scan trigger.
    /* Configure ADCCON2 */
    ADCCON2bits.SAMC = 5;           // ADC7 sampling time = 5 * TAD7
    ADCCON2bits.ADCDIV = 1;         // ADC7 clock freq is half of control clock = TAD7
    /* Initialize warm up time register */
    ADCANCON = 0;
    ADCANCONbits.WKUPCLKCNT = 5;    // Wakeup exponent = 32 * TADx
    /* Clock setting */
    ADCCON3 = 0;
    ADCCON3bits.ADCSEL = 0;         // Select input clock source
    ADCCON3bits.CONCLKDIV = 1;      // Control clock frequency is half of input clock
    ADCCON3bits.VREFSEL = 0;        // Select AVDD and AVSS as reference source
    /* No selection for dedicated ADC modules, no presync trigger, not sync sampling */
    ADCTRGMODE = 0;
    /* Select ADC input mode */
    ADCIMCON1bits.SIGN7 = 0;        // unsigned data format
    ADCIMCON1bits.DIFF7 = 0;        // Single ended mode
    ADCIMCON1bits.SIGN8 = 0;        // unsigned data format
    ADCIMCON1bits.DIFF8 = 0;        // Single ended mode
    ADCIMCON1bits.SIGN9 = 0;        // unsigned data format
    ADCIMCON1bits.DIFF9 = 0;        // Single ended mode
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
    ADCFLTR1 = 0;                   // No oversampling filters are used.
    ADCFLTR2 = 0;
    ADCFLTR3 = 0;
    ADCFLTR4 = 0;
    ADCFLTR5 = 0;
    ADCFLTR6 = 0;
    
    /* Set up the trigger sources */
    ADCTRGSNSbits.LVL7 = 0;         // Edge trigger
    ADCTRGSNSbits.LVL8 = 0;         // Edge trigger
    ADCTRGSNSbits.LVL9 = 0;         // Edge trigger
    ADCTRGSNSbits.LVL10 = 0;        // Edge trigger
    ADCTRGSNSbits.LVL11 = 0;        // Edge trigger
   
    ADCTRG2bits.TRGSRC7 = 1;        // Set AN7  to trigger from software
    ADCTRG3bits.TRGSRC8 = 1;        // Set AN8  to trigger from software
    ADCTRG3bits.TRGSRC9 = 1;        // Set AN9  to trigger from software
    ADCTRG3bits.TRGSRC10 = 1;       // Set AN10 to trigger from software
    ADCTRG3bits.TRGSRC11 = 1;       // Set AN11 to trigger from software
    
    /* Early interrupt */
    ADCEIEN1 = 0; // No early interrupt
    ADCEIEN2 = 0;
    
}
void class2_adc_on(int adc_num)
{
    /* Turn the ADC on */
    ADCCON1bits.ON = 1;
    /* Wait for voltage reference to be stable */
    while(!ADCCON2bits.BGVRRDY);    // Wait until the reference voltage is ready
    while(ADCCON2bits.REFFLT);      // Wait if there is a fault with the reference voltage
    
    /* Enable clock to analog circuit */
    ADCANCONbits.ANEN7 = 1; // Enable the clock to analog bias
    
    if(adc_num == 7)
    {
        /* Wait for ADC to be ready */
        while(!ADCANCONbits.WKRDY7); // Wait until ADC7 is ready
        /* Enable the ADC module */
        ADCCON3bits.DIGEN7 = 1; // Enable ADC7
    }
    else if (adc_num == 8)
    {
        /* Wait for ADC to be ready */
        while(!ADCANCONbits.WKRDY7); // Wait until ADC7 is ready
        /* Enable the ADC module */
        ADCCON3bits.DIGEN7 = 1; // Enable ADC7
    }
    
     else if (adc_num == 9)
    {
        /* Wait for ADC to be ready */
        while(!ADCANCONbits.WKRDY7); // Wait until ADC7 is ready
        /* Enable the ADC module */
        ADCCON3bits.DIGEN7 = 1; // Enable ADC7
    }
    
     else if (adc_num == 10)
    {
        while(!ADCANCONbits.WKRDY7); // Wait until ADC7 is ready
        /* Enable the ADC module */
        ADCCON3bits.DIGEN7 = 1; // Enable ADC7
    }
    
     else if (adc_num == 11)
    {
        /* Wait for ADC to be ready */
        while(!ADCANCONbits.WKRDY7); // Wait until ADC7 is ready
        /* Enable the ADC module */
        ADCCON3bits.DIGEN7 = 1; // Enable ADC7
    }
    
     else if (adc_num == 14)
    {
        /* Wait for ADC to be ready */
        while(!ADCANCONbits.WKRDY7); // Wait until ADC7 is ready
        /* Enable the ADC module */
        ADCCON3bits.DIGEN7 = 1; // Enable ADC7
    }
    
     else if (adc_num == 15)
    {
        /* Wait for ADC to be ready */
        while(!ADCANCONbits.WKRDY7); // Wait until ADC7 is ready
        /* Enable the ADC module */
        ADCCON3bits.DIGEN7 = 1; // Enable ADC7
    }
    
     else if (adc_num == 16)
    {
        /* Wait for ADC to be ready */
        while(!ADCANCONbits.WKRDY7); // Wait until ADC7 is ready
        /* Enable the ADC module */
        ADCCON3bits.DIGEN7 = 1; // Enable ADC7
    }
    
     else if (adc_num == 17)
    {
        /* Wait for ADC to be ready */
        while(!ADCANCONbits.WKRDY7); // Wait until ADC7 is ready
        /* Enable the ADC module */
        ADCCON3bits.DIGEN7 = 1; // Enable ADC7
    }
    
     else if (adc_num == 18)
    {
        /* Wait for ADC to be ready */
        while(!ADCANCONbits.WKRDY7); // Wait until ADC7 is ready
        /* Enable the ADC module */
        ADCCON3bits.DIGEN7 = 1; // Enable ADC7
    }
    
     else
     {
         return;
     }
    return;
}
void class2_adc_off(int adc_num)
{
    /* Turn the ADC off */
    ADCCON1bits.ON = 0;
    ADCCON3bits.DIGEN7 = 0; // Disable ADC7
    return;
}
long class2_adc_read(int adc_num)
{
    long result = 0;
    
    if (adc_num == 7)
    {
        // activate ADC module
        class2_adc_on(adc_num);
        
        // Select analog_pin and begin conversion
        ADCCON3bits.ADINSEL = adc_num;
        ADCCON3bits.SAMP = 0;
        ADCCON3bits.RQCNVRT = 1;
        /* Wait the conversions to complete */
        while (ADCDSTAT1bits.ARDY7 == 0);
    
        /* fetch the result */
        result = ADCDATA7;
        
        // deactivate ADC module
        class2_adc_off(adc_num);
        return result;
    }
    else if (adc_num == 8)
    {
        // activate ADC module
        class2_adc_on(adc_num);
        
        // Select analog_pin and begin conversion
        ADCCON3bits.ADINSEL = adc_num;
        ADCCON3bits.SAMP = 0;
        ADCCON3bits.RQCNVRT = 1;
        /* Wait the conversions to complete */
        while (ADCDSTAT1bits.ARDY8 == 0);
    
        /* fetch the result */
        result = ADCDATA8;
        
        // deactivate ADC module
        class2_adc_off(adc_num);
        return result;
    }
    
    else if (adc_num == 9)
    {
        // activate ADC module
        class2_adc_on(adc_num);
        
        // Select analog_pin and begin conversion
        ADCCON3bits.ADINSEL = adc_num;
        ADCCON3bits.SAMP = 0;
        ADCCON3bits.RQCNVRT = 1;
        /* Wait the conversions to complete */
        while (ADCDSTAT1bits.ARDY9 == 0);
    
        /* fetch the result */
        result = ADCDATA9;
        
        // deactivate ADC module
        class2_adc_off(adc_num);
        return result;
    }
    
    else if (adc_num == 10)
    {
        // activate ADC module
        class2_adc_on(adc_num);
        
        // Select analog_pin and begin conversion
        ADCCON3bits.ADINSEL = adc_num;
        ADCCON3bits.SAMP = 0;
        ADCCON3bits.RQCNVRT = 1;
        /* Wait the conversions to complete */
        while (ADCDSTAT1bits.ARDY10 == 0);
    
        /* fetch the result */
        result = ADCDATA10;
        
        // deactivate ADC module
        class2_adc_off(adc_num);
        return result;
    }
    
    else if (adc_num == 11)
    {
        // activate ADC module
        class2_adc_on(adc_num);
        
        // Select analog_pin and begin conversion
        ADCCON3bits.ADINSEL = adc_num;
        ADCCON3bits.SAMP = 0;
        ADCCON3bits.RQCNVRT = 1;
        while (ADCDSTAT1bits.ARDY11 == 0);
    
        /* fetch the result */
        result = ADCDATA11;
        
        // deactivate ADC module
        class2_adc_off(adc_num);
        return result;
    }
    
    else if (adc_num == 14)
    {
        // activate ADC module
        class2_adc_on(adc_num);
        
        // Select analog_pin and begin conversion
        ADCCON3bits.ADINSEL = adc_num;
        ADCCON3bits.SAMP = 0;
        ADCCON3bits.RQCNVRT = 1;
        /* Wait the conversions to complete */
        while (ADCDSTAT1bits.ARDY14 == 0);
    
        /* fetch the result */
        result = ADCDATA14;
        
        // deactivate ADC module
        class2_adc_off(adc_num);
        return result;
    }
    
     else if (adc_num == 15)
    {
        // activate ADC module
        class2_adc_on(adc_num);
        
        // Select analog_pin and begin conversion
        ADCCON3bits.ADINSEL = adc_num;
        ADCCON3bits.SAMP = 0;
        ADCCON3bits.RQCNVRT = 1;
        /* Wait the conversions to complete */
        while (ADCDSTAT1bits.ARDY15 == 0);
    
        /* fetch the result */
        result = ADCDATA15;
        
        // deactivate ADC module
        class2_adc_off(adc_num);
        return result;
    }
    
     else if (adc_num == 16)
    {
        // activate ADC module
        class2_adc_on(adc_num);
        
        // Select analog_pin and begin conversion
        ADCCON3bits.ADINSEL = adc_num;
        ADCCON3bits.SAMP = 0;
        ADCCON3bits.RQCNVRT = 1;
        /* Wait the conversions to complete */
        while (ADCDSTAT1bits.ARDY16 == 0);
    
        /* fetch the result */
        result = ADCDATA16;
        
        // deactivate ADC module
        class2_adc_off(adc_num);
        return result;
    }
    
     else if (adc_num == 17)
    {
        // activate ADC module
        class2_adc_on(adc_num);
        
        // Select analog_pin and begin conversion
        ADCCON3bits.ADINSEL = adc_num;
        ADCCON3bits.SAMP = 0;
        ADCCON3bits.RQCNVRT = 1;
        /* Wait the conversions to complete */
        while (ADCDSTAT1bits.ARDY17 == 0);
    
        /* fetch the result */
        result = ADCDATA17;
        
        // deactivate ADC module
        class2_adc_off(adc_num);
        return result;
    }
    
     else if (adc_num == 18)
    {
        // activate ADC module
        class2_adc_on(adc_num);
        
        // Select analog_pin and begin conversion
        ADCCON3bits.ADINSEL = adc_num;
        ADCCON3bits.SAMP = 0;
        ADCCON3bits.RQCNVRT = 1;
        /* Wait the conversions to complete */
        while (ADCDSTAT1bits.ARDY18 == 0);
    
        /* fetch the result */
        result = ADCDATA18;
        
        // deactivate ADC module
        class2_adc_off(adc_num);
        return result;
    }
    
     else
     {
         return;
     }
}
