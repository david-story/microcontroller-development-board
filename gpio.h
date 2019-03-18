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

#ifndef gpio    /* Guard against multiple inclusion */
#define gpio

void set_gpio_pin(int pin_value, int state);
int  set_output(int pin_value, int output_value);
int  read_input(int pin_value);
int  get_pin_value(int pin_value);

#define HIGH    1
#define LOW     0

#define INPUT   1
#define OUTPUT  0

#define RB0     0
#define RB1     1
#define RB2     2
#define RB3     3
#define RB4     4
#define RB5     5
#define RB6     6
#define RB7     7
#define RB8     8
#define RB9     9
#define RB10    10
#define RB11    11
#define RB12    12
#define RB13    13
#define RB14    14
#define RB15    15

#define RC12    16
#define RC13    17
#define RC14    18
#define RC15    19

#define RD0     20
#define RD1     21
#define RD2     22
#define RD3     23
#define RD4     24
#define RD5     25
#define RD9     29
#define RD10    30
#define RD11    31

#define RE0     39
#define RE1     40
#define RE2     41
#define RE3     42
#define RE4     43
#define RE5     44
#define RE6     45
#define RE7     46

#define RF0     37
#define RF1     38
#define RF3     40
#define RF4     41
#define RF5     42

#define RG6     52
#define RG7     53
#define RG8     54
#define RG9     55

#endif /* gpio */

/* *****************************************************************************
 End of File
 */
