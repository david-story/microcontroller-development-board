/*
 * File:   spi.c
 * Author: David
 *
 * Created on March 17, 2019, 6:20 PM
 */


#include <xc.h>
#include "spi.h"

void configure_spi(void)
{
    IEC0CLR=0x03800000;     // disable all interrupts
    SPI1CON = 0;            // stops and resets the SPI1.
    SPI1BUF = 0;            // clears the receive buffer
    IFS0CLR=0x03800000;     // clear any existing event
    IPC5CLR=0x1f000000;     // clear the priority
    IPC5SET=0x0d000000;     // set IPL=3, subpriority 1
    IEC0SET=0x03800000;     // enable RX, TX and Error interrupts
    SPI1BRG=0x1;            // use FPB/4 clock frequency
    SPI1STATCLR=0x40;       // clear the Overflow
    SPI1CON=0x8220;         // SPI ON, 8 bits transfer, SMP=1, Master mode
    
    return;
}
void spi_transmit(int send_data)
{
    SPI1BUF = send_data;
    return;
}
long spi_recieve(int send_data)
{
    send_data = SPI1BUF;
    return send_data;
}
