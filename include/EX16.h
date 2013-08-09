/*
**  EX16.h
**
**  Standard definitions for use with the Explorer16 board
*/

#ifndef _EX16
#define _EX16

#include <xc.h>

#if defined(__PIC24FJ256GB110__) || defined(__PIC24FJ256GA110__)
#include <pps.h>
#endif

#if __C30_VERSION__ >= 300
#undef _ISR
#define _ISR __attribute__((interrupt,no_auto_psv))
#undef _ISRFAST
#define _ISRFAST __attribute__((interrupt,shadow,no_auto_psv))
#endif

#define FCY 16000000UL      // instruction clock 16MHz

#define USE_AND_OR  // use OR to assemble control register bits
#define _FAR __attribute__(( far))

// prototypes
void InitEX16( void);       // initialize the Explorer 16 board

void Delayms( unsigned t);  // wait for t x 1msec

int GetKEY( void);          // wait for a button to be pressed

int ReadKEY( void);         // check the 4 button inputs status

#define POT_CH    5         // channel 5 = 10k potentiometer 
#define TEMP_CH   4         // channel 4 = TC1047 Temp sensor 
#define POTMASK   0xffdf    // make AN5 an analog input
#define TEMPMASK  0xffef    // make AN4 an analog input

void InitADC( int amask);   // initialize ADC and analog pins
int ReadADC( int ch);       // sample/convert one analog input

#endif

