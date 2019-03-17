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

#ifndef adc1   /* Guard against multiple inclusion */
#define adc1

void configure_class1_adc();
void class1_adc_on(int adc_num);
void class1_adc_off(int adc_num);
long class1_adc_read(int adc_num);

#endif /* adc */

/* *****************************************************************************
 End of File
 */
