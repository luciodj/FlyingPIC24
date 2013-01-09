/*
** A Loop in the pattern
**
** Exercise 2-1 Output a counter on PORTA
*/
#include <config.h>

#define DELAY   16       
// use just 16 to speed up the simulation with MPLAB SIM 

unsigned char count;    // an 8-bit counter (also see chapt.4)

main()
{
    // init control registers
    TRISA = 0xff00; // all PORTA as output
    T1CON = 0x8030; // TMR1 on, prescale 1:256 Tclk/2
    
    // init counter
    count = 0;
    
    // main application loop
    while( 1)
    {
        // increment counter value
        count = count+1;
        
        // output counter value and wait for 1/4 of a second
        PORTA = count;  
        TMR1 = 0;
        while ( TMR1 < DELAY)
        {
        }
    } // main loop
} // main
