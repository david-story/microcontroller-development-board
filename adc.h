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

#define AN0     0
#define AN1     1
#define AN2     2
#define AN3     3
#define AN4     4

#define AN7     7
#define AN8     8
#define AN9     9
#define AN10    10
#define AN11    11

#define AN14    14
#define AN15    15
#define AN16    16
#define AN17    17
#define AN18    18

long read_adc(int pin_value);
void set_adc(int pin_value);
int adc_select(int pin_value);

#endif /* adc */

/* *****************************************************************************
 End of File
 */
