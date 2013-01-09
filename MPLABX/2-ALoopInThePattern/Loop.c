/*
** Loop.c 
**
** A Loop In The Pattern
**
*/
#include "config.h"

#define DELAY   16000       

main()
{
    // init control registers
    TRISA = 0xff00; // all PORTA as output
    T1CON = 0x8030; // TMR1 on, prescale 1:256 Tclk/2
    
    // main application loop
    while( 1)
    {
        //1. turn pin 0-7 on and wait for 1/4 of a second
        PORTA = 0xff;   
        TMR1 = 0;
        while ( TMR1 < DELAY)
        {
        }

        // 2. turn all pin off and wait for a 1/4 of a second
        PORTA = 0;
        TMR1 = 0;
        while ( TMR1 < DELAY)
        {
        }
    } // main loop
  } // main
