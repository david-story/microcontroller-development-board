/*
 * File:   i2c.c
 * Author: David
 *
 * Created on March 16, 2019, 5:50 PM
 */


#include <xc.h>
#include "i2c.h"

// I2C_wait_for_idle() waits until the I2C peripheral is no longer doing anything  

void I2C_wait_for_idle(void) {
    while (I2C4CON & 0x1F); // Acknowledge sequence not in progress
    // Receive sequence not in progress
    // Stop condition not in progress
    // Repeated Start condition not in progress
    // Start condition not in progress
    while (I2C4STATbits.TRSTAT); // Bit = 0 ? Master transmit is not in progress
}

// I2C_start() sends a start condition  

void I2C_start() {
    I2C_wait_for_idle();
    I2C4CONbits.SEN = 1;
    while (I2C4CONbits.SEN == 1);
}

// I2C_stop() sends a stop condition  

void I2C_stop() {
    I2C_wait_for_idle();
    I2C4CONbits.PEN = 1;
}

// I2C_restart() sends a repeated start/restart condition

void I2C_restart() {
    I2C_wait_for_idle();
    I2C4CONbits.RSEN = 1;
    while (I2C4CONbits.RSEN == 1);
}

// I2C_ack() sends an ACK condition

void I2C_ack(void) {
    I2C_wait_for_idle();
    I2C4CONbits.ACKDT = 0; // Set hardware to send ACK bit
    I2C4CONbits.ACKEN = 1; // Send ACK bit, will be automatically cleared by hardware when sent  
    while (I2C4CONbits.ACKEN); // Wait until ACKEN bit is cleared, meaning ACK bit has been sent
}

// I2C_nack() sends a NACK condition

void I2C_nack(void) {
    I2C_wait_for_idle();
    I2C4CONbits.ACKDT = 1; // Set hardware to send NACK bit
    I2C4CONbits.ACKEN = 1; // Send NACK bit, will be automatically cleared by hardware when sent  
    while (I2C4CONbits.ACKEN); // Wait until ACKEN bit is cleared, meaning NACK bit has been sent
}

// address is I2C slave address, set wait_ack to 1 to wait for ACK bit or anything else to skip ACK checking  

void I2C_write(unsigned char address, char wait_ack) {
    I2C4TRN = address | 0; // Send slave address with Read/Write bit cleared
    while (I2C4STATbits.TBF == 1); // Wait until transmit buffer is empty
    I2C_wait_for_idle(); // Wait until I2C bus is idle
    if (wait_ack) while (I2C4STATbits.ACKSTAT == 1); // Wait until ACK is received  
}

// value is the value of the data we want to send, set ack_nack to 0 to send an ACK or anything else to send a NACK 

void I2C_read(unsigned char *value, char ack_nack) {
    I2C4CONbits.RCEN = 1; // Receive enable
    while (I2C4CONbits.RCEN); // Wait until RCEN is cleared (automatic)  
    while (!I2C4STATbits.RBF); // Wait until Receive Buffer is Full (RBF flag)  
    *value = I2C4RCV; // Retrieve value from I2C1RCV
    if (!ack_nack) // Do we need to send an ACK or a NACK?  
        I2C_ack(); // Send ACK  
    else
        I2C_nack(); // Send NACK  
}

void I2C_write_BYTE(unsigned char dev_address, unsigned char reg_address, unsigned char value) {
    I2C_start(); /* Send start condition */
    I2C_write(dev_address, 1); /* Send MPU9250's address, read/write bit not set (AD + R) */
    I2C_write(reg_address, 1); /* Send the register address (RA) */
    I2C_write(value, 1); /* Send the value to set it to */
    I2C_stop(); /* Send stop condition */
}

// Read a byte from register at reg_address and return in *value

void I2C_read_BYTE(unsigned char dev_address, unsigned char reg_address, unsigned char *value) {
    I2C_start(); /* Send start condition */
    I2C_write(dev_address, 1); /* Send MPU9250's address, read/write bit not set (AD + R) */
    I2C_write(reg_address, 1); /* Send the register address (RA) */
    I2C_restart(); /* Send repeated start condition */
    I2C_write(dev_address | 1, 1); /* Send MPU9250's address, read/write bit set (AD + W) */
    I2C_read(value, 1); /* Read value from the I2C bus */
    I2C_stop(); /* Send stop condition */
}

// I2C_init() initialises I2C1 at at frequency of [frequency]Hz

void I2C_init(double frequency, double clockspeed) {
    ANSELGbits.ANSG8 = 0;
    ANSELGbits.ANSG7 = 0;
    TRISGbits.TRISG8 = 1;
    TRISGbits.TRISG7 = 1;
    double BRG;
    I2C4CON = 0; // Turn off I2C1 module
    I2C4CONbits.DISSLW = 1; // Disable slew rate for 100kHz
    BRG = (1 / (2 * frequency)) - 0.000000104;
    BRG *= (clockspeed / 2) - 2;
    I2C4BRG = (int) BRG; // Set baud rate
    I2C4CONbits.ON = 1; // Turn on I2C1 module
}