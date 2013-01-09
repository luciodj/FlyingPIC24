/*
** It's an analog world
** Converting the analog signal from a potentiometer
*/
#include <config.h>

#define POT_CH  5       // 10k potentiometer on pin AN5 
#define POTMASK 0xffdf  // AN5 = analog inputs


// initialize the ADC for single conversion, select input pins
void InitADC( int amask) 
{
    AD1PCFG = amask;    // select analog input pins
    AD1CON1 = 0x00E0;   // auto convert after end of sampling 
    AD1CSSL = 0;        // no scanning required 
    AD1CON3 = 0x1F01;   // sample time=31Tad, Tad=2xTcy=125ns
    AD1CON2 = 0;        // use MUXA, AVss and AVdd used as Vref
    AD1CON1bits.ADON = 1; // turn on the ADC
    
    // Explorer 16 Development Board Errata (work around 2)
    // RB15 should always be a digital output
    _LATB15 = 0;
    _TRISB15 = 0;
} // InitADC


int ReadADC( int ch)
{
    AD1CHS  = ch;               // select analog input channel
    
    // start sampling, automatic conversion will follow
    AD1CON1bits.SAMP = 1;       
    while (!AD1CON1bits.DONE);  // wait to complete conversion
    return ADC1BUF0;            // read the conversion result
} // ReadADC


main ()
{
    int pot, pos;
    
    // initializations
    InitADC( POTMASK);   // initialize the ADC and analog inputs
    TRISA = 0xff00;     // all PORTA pins as outputs 
    
    // main loop
    while( 1)
    {   
        pot = ReadADC( POT_CH);  // select the POT input, convert

        // reduce the 10-bit result to a 3 bit value (0..7)
        // (divide by 128 or shift right 7 times)
        pos = pot >> 7;
        
        // turn on only the corresponding LED
        // 0 -> leftmost LED.... 7-> rigtmost LED
        PORTA = (0x80 >> pos);
        
    } // main loop
} // main
