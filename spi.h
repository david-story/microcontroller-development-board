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

#ifndef spi    /* Guard against multiple inclusion */
#define spi

void configure_spi(void);
void spi_transmit(int send_data);
long spi_recieve(int send_data);

#endif /* spi */

/* *****************************************************************************
 End of File
 */
