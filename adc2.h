/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.h

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#ifndef adc2   /* Guard against multiple inclusion */
#define adc2

void configure_class2_adc();
void class2_adc_on(int adc_num);
void class2_adc_off(int adc_num);
long class2_adc_read(int adc_num);

#endif /* adc */

/* *****************************************************************************
 End of File
 */