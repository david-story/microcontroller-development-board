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

#ifndef adc    /* Guard against multiple inclusion */
#define adc

void adc_configure(int adc_num);
long adc_read(int adc_num);

#endif /* adc */

/* *****************************************************************************
 End of File
 */
