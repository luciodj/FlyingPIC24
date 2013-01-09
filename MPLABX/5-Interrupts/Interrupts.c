/*
** Interrupts.c
**
*/ 
#include <config.h>

int dSec = 0;
int Sec = 0;
int Min = 0;

// 1. Timer1 interrupt service routine
void _ISR _T1Interrupt( void) 
{
    // 1.1 your code here
    dSec++;         // increment the tens of a second counter
    if ( dSec > 9)  // 10 tens in a second
    { 
        dSec = 0;
        Sec++;      // increment the seconds counter
        
        if ( Sec > 59)  // 60 seconds make a minute
        {
            Sec = 0;
            Min++;  // increment the minute counter
    
            if ( Min > 59)// 59 minutes in an hour
                Min = 0;
        } // minutes
    } // seconds

    // 1.2 clear the interrupt flag
    _T1IF = 0;
    
} //T1Interrupt

main()
{
    // 2. initializations
    _T1IP = 4;      // this is the default value anyway
    TMR1 = 0;       // clear the timer
    PR1 = 25000-1;  // set the period register
    TRISA = 0xff00; // set PORTA lsb as output
    
    // 2.1 configure Timer1 module
    T1CON = 0x8020; // enabled, prescaler 1:64, internal clock  
    
    // 2.2 init the Timer 1 Interrupt control bits
    _T1IF = 0;      // clear the interrupt flag, before
    _T1IE = 1;      // enable the T1 interrupt source
    
    // 2.3 init the processor priority level
    _IPL = 0;   // this is the default value anyway
    
    // 3. main loop
    while( 1)
    {
        // your main code here
        PORTA = Sec;   
        
    } // main loop

} // main
