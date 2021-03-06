/*
 * File:   config.c
 * Author: David
 *
 * Created on March 16, 2019, 4:52 PM
 */

#include <xc.h>
#include "config.h"
#include "adc1.h"

// -------------------------------------------------------------------------- //
/*
 * Chip Configuration Directives
 *
 */
// -------------------------------------------------------------------------- //

#pragma config USERID = 0xFFFF              // Enter Hexadecimal value (Enter Hexadecimal value)
#pragma config FMIIEN = OFF                  // Ethernet RMII/MII Enable (MII Enabled)
#pragma config FETHIO = OFF                   // Ethernet I/O Pin Select (Default Ethernet I/O)
#pragma config PGL1WAY = OFF                  // Permission Group Lock One Way Configuration (Allow only one reconfiguration)
#pragma config PMDL1WAY = OFF                 // Peripheral Module Disable Configuration (Allow only one reconfiguration)
#pragma config IOL1WAY = OFF                  // Peripheral Pin Select Configuration (Allow only one reconfiguration)
#pragma config FUSBIDIO = OFF                 // USB USBID Selection (Controlled by the USB Module)

// DEVCFG2
#pragma config FPLLIDIV = DIV_8             // System PLL Input Divider (8x Divider)
#pragma config FPLLRNG = RANGE_34_68_MHZ    // System PLL Input Range (34-68 MHz Input)
#pragma config FPLLICLK = PLL_FRC           // System PLL Input Clock Selection (FRC is input to the System PLL)
#pragma config FPLLMULT = MUL_128           // System PLL Multiplier (PLL Multiply by 128)
#pragma config FPLLODIV = DIV_32            // System PLL Output Clock Divider (32x Divider)
#pragma config UPLLFSEL = FREQ_24MHZ        // USB PLL Input Frequency Selection (USB PLL input is 24 MHz)

// DEVCFG1
#pragma config FNOSC = FRCDIV               // Oscillator Selection Bits (Fast RC Osc w/Div-by-N (FRCDIV))
#pragma config DMTINTV = WIN_127_128        // DMT Count Window Interval (Window/Interval value is 127/128 counter value)
#pragma config FSOSCEN = ON                 // Secondary Oscillator Enable (Enable SOSC)
#pragma config IESO = ON                    // Internal/External Switch Over (Enabled)
#pragma config POSCMOD = OFF                // Primary Oscillator Configuration (Primary osc disabled)
#pragma config OSCIOFNC = OFF               // CLKO Output Signal Active on the OSCO Pin (Disabled)
#pragma config FCKSM = CSECME               // Clock Switching and Monitor Selection (Clock Switch Enabled, FSCM Enabled)
#pragma config WDTPS = PS1048576            // Watchdog Timer Postscaler (1:1048576)
#pragma config WDTSPGM = STOP               // Watchdog Timer Stop During Flash Programming (WDT stops during Flash programming)
#pragma config WINDIS = NORMAL              // Watchdog Timer Window Mode (Watchdog Timer is in non-Window mode)
#pragma config FWDTEN = ON                  // Watchdog Timer Enable (WDT Enabled)
#pragma config FWDTWINSZ = WINSZ_25         // Watchdog Timer Window Size (Window size is 25%)
#pragma config DMTCNT = DMT31               // Deadman Timer Count Selection (2^31 (2147483648))
#pragma config FDMTEN = ON                  // Deadman Timer Enable (Deadman Timer is enabled)

// DEVCFG0
#pragma config DEBUG = OFF                  // Background Debugger Enable (Debugger is disabled)
#pragma config JTAGEN = OFF                 // JTAG Enable (JTAG Port Enabled)
#pragma config ICESEL = ICS_PGx1            // ICE/ICD Comm Channel Select (Communicate on PGEC1/PGED1)
#pragma config TRCEN = ON                   // Trace Enable (Trace features in the CPU are enabled)
#pragma config BOOTISA = MIPS32             // Boot ISA Selection (Boot code and Exception code is MIPS32)
#pragma config FECCCON = OFF_UNLOCKED       // Dynamic Flash ECC Configuration (ECC and Dynamic ECC are disabled (ECCCON bits are writable))
#pragma config FSLEEP = OFF                 // Flash Sleep Mode (Flash is powered down when the device is in Sleep mode)
#pragma config DBGPER = PG_ALL              // Debug Mode CPU Access Permission (Allow CPU access to all permission regions)
#pragma config SMCLR = MCLR_NORM            // Soft Master Clear Enable bit (MCLR pin generates a normal system Reset)
#pragma config SOSCGAIN = GAIN_2X           // Secondary Oscillator Gain Control bits (2x gain setting)
#pragma config SOSCBOOST = ON               // Secondary Oscillator Boost Kick Start Enable bit (Boost the kick start of the oscillator)
#pragma config POSCGAIN = GAIN_2X           // Primary Oscillator Gain Control bits (2x gain setting)
#pragma config POSCBOOST = ON               // Primary Oscillator Boost Kick Start Enable bit (Boost the kick start of the oscillator)
#pragma config EJTAGBEN = NORMAL            // EJTAG Boot (Normal EJTAG functionality)

// DEVCP0
#pragma config CP = OFF                     // Code Protect (Protection Disabled)

// SEQ3
#pragma config TSEQ = 0xFFFF                // Boot Flash True Sequence Number (Enter Hexadecimal value)
#pragma config CSEQ = 0xFFFF                // Boot Flash Complement Sequence Number (Enter Hexadecimal value)

// DEVADC0
#pragma config ADCFG = 0xFFFFFFFF           // Enter Hexadecimal value (Enter Hexadecimal value)

void configure_chip()
{
    
    // configures i/o ports for chip
    configure_io();
    configure_analog_pins();
    configure_class1_adc();
}

void configure_analog_pins()
{
    // Analog select for PORTB
    ANSELB = 0x00;
    // Analog select for PORTE
    ANSELE = 0x00;
    // Analog select for PORTG
    ANSELG = 0x00;
}

void configure_io()
{
    // Tri-state B configuration (input = 1 : output = 0)
    TRISB = 0x000000;
    // Tri-state C configuration (input = 1 : output = 0)
    TRISC = 0x000000;
    // Tri-state D configuration (input = 1 : output = 0)
    TRISD = 0x000000;
    // Tri-state E configuration (input = 1 : output = 0)
    TRISE = 0x000000;
    // Tri-state F configuration (input = 1 : output = 0)
    TRISF = 0x000000;
    // Tri-state G configuration (input = 1 : output = 0)
    TRISG = 0x000000;
    
    // PORTB Initial Start-Up Value (High = 1 : Low = 0)
    PORTB = 0x000000;
    // PORTB Initial Start-Up Value (High = 1 : Low = 0)
    PORTC = 0x000000;
    // PORTB Initial Start-Up Value (High = 1 : Low = 0)
    PORTD = 0x000000;
    // PORTB Initial Start-Up Value (High = 1 : Low = 0)
    PORTE = 0x000000;
    // PORTB Initial Start-Up Value (High = 1 : Low = 0)
    PORTF = 0x000000;
    // PORTB Initial Start-Up Value (High = 1 : Low = 0)
    PORTG = 0x000000;
}