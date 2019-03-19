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

#ifndef i2c    /* Guard against multiple inclusion */
#define i2c

void I2C_wait_for_idle(void);
void I2C_start();
void I2C_stop();
void I2C_restart() ;
void I2C_ack(void);
void I2C_nack(void);
void I2C_write(unsigned char address, char wait_ack);
void I2C_read(unsigned char *value, char ack_nack);
void I2C_write_BYTE(unsigned char dev_address, unsigned char reg_address, unsigned char value);
void I2C_read_BYTE(unsigned char dev_address, unsigned char reg_address, unsigned char *value);
void I2C_init(double frequency, double clockspeed);

#endif /* i2c */

/* *****************************************************************************
 End of File
 */
