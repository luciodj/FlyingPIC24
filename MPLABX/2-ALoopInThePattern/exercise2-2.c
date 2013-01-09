/*
** A Loop in the pattern
**
** Exercise 2-2 rotate a pattern on PORTA
*/
#include <config.h>

#define DELAY   16       
// use just 16 to speed up the simulation with MPLAB SIM 

unsigned int pattern;    // a 16-bit pattern

main()
{
    unsigned int c;     // temporary variable
    
    // init control registers
    TRISA = 0xff00; // all PORTA as output
    T1CON = 0x8030; // TMR1 on, prescale 1:256 Tclk/2
    
    // init pattern
    pattern = 0x7310;
    
    // main application loop
    while( 1)
    {
        // output pattern and wait for 1/4 of a second
        PORTA = pattern;    
        TMR1 = 0;
        while ( TMR1 < DELAY)
        {
        }

/* rotate left
       // get pattern msb (bit 15)
        c = pattern & 0x8000;
        // shift left 16-bit pattern 
        pattern = pattern << 1;
        // rotate back msb into pattern lsb
        if ( c!=0) 
            pattern = pattern | 1;
*/

/* rotate right */
        // get pattern lsb (bit 0)
        c = pattern & 1;
        // shift right 16-bit pattern
        pattern = pattern >> 1;
        // rotate back lsb into pattern msb
        if ( c!=0)
            pattern = pattern | 0x8000;
            
    } // main loop
} // main
