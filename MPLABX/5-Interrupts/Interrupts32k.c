/*
** Interrupts32k.c
**
** testing the secondary oscillator 
*/ 
#include <config.h>

// notify the compiler we are not modifying the PSV
int dSec = 0;
int Sec = 0;
int Min = 0;

// 1. Timer1 interrupt service routine
void _ISR _T1Interrupt( void) 
{
    // 1.1 clear the interrupt flag
    _T1IF = 0;
    
    // 1.2 your code here
    Sec++;      // increment the seconds counter
    
    if ( Sec > 59)  // 60 seconds make a minute
    {
        Sec = 0;
        Min++;  // increment the minute counter

        if ( Min > 59)// 59 minutes in an hour
            Min = 0;
    } // minutes
} //T1Interrupt

main()
{
    // 2. init Timer 1, T1ON, 1:1 prescaler, internal  source
    _T1IP = 4;      // this is the default value anyway
    TMR1 = 0;       // clear the timer
    PR1 = 32768-1;  // set the period register
    TRISA = 0xff00; // set PORTA lsb as output

    // 2.1 configure Secondary OSC and Timer1 module
    __builtin_write_OSCCONL( 2);    // unlock and enable SOSC
    T1CON = 0x8002; // enabled, prescaler 1:1, secondary osc
    
    // 2.2 init the Timer 1 Interrupt, clear the flag, enable e
    _T1IF = 0;  
    _T1IE = 1;
    
    // 2.3 init the processor priority level
    _IPL = 0;   // this is the default value anyway
    
    // 3. main loop
    while( 1)
    {
        // your main code here
        PORTA = Sec & 0xff;   
        
    } // main loop

} // main
