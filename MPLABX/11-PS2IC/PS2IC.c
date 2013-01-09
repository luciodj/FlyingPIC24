/*
**
**  PS/2 Input Change
*/
#include <EX16.h>
#include <PS2.h>

#define PS2DAT  _RG12       // PS2 Data input pin
#define PS2CLK  _RD8        // PS2 Clock input pin 

// definition of the keyboard PS/2 state machine 
#define PS2START    0
#define PS2BIT      1
#define PS2PARITY   2
#define PS2STOP     3

#define TMAX        500

// PS2 KBD state machine and buffers
int PS2State;
int KBDBuf, KCount, KParity;

// mailbox
volatile char KBDReady;
volatile char KBDCode;


void InitKBD( void)
{
    // init I/Os
    _TRISD8 = 1;        // make RD8, IC1 an input pin, clock
    _TRISG12 = 1;       // make RG12 an input pin, data

    // clear the flag
    KBDReady = 0;

    IC1CON = 0x0082;    // TMR2, int. every capt, falling edge
    _IC1IF = 0;         // clear the interrupt flag
    _IC1IE = 1;         // enable the IC1 interrupt

    _T2IF = 0;          // clear the timer interrupt flag
    _T2IE = 1;          // interruptz on (TMR2 not active yet)
} // init KBD



void _ISR _IC1Interrupt( void)
{ // input capture interrupt service routine

    // reset timer on every edge
    TMR2 = 0;

    switch( PS2State){
    default:
    case PS2START:   
        if ( !PS2DAT)
        { 
            KCount = 8;             // init bit counter
            KParity = 0;            // init parity check
            PR2 = TMAX*16;          // init timer period
            T2CON = 0x8000;         // enable TMR2
            PS2State = PS2BIT;        
        }
        break;

    case PS2BIT:      
        KBDBuf >>=1;                // shift in data bit
        if ( PS2DAT)                
            KBDBuf |= 0x80;
        KParity ^= KBDBuf;          // update parity
        if ( --KCount == 0)         // if all bit read, move on
            PS2State = PS2PARITY;
        break;

    case PS2PARITY:         
        if ( PS2DAT)
            KParity ^= 0x80;
        if ( KParity & 0x80)        // if parity is odd, next
            PS2State = PS2STOP;
        else 
            PS2State = PS2START;    // else restart
        break;

    case PS2STOP:    
        if ( PS2DAT)                // verify stop bit
        {
            KBDCode = KBDBuf;       // save key code in mailbox
            KBDReady = 1;           // set flag, key available
            T2CON = 0;              // stop the timer
        }    
        PS2State = PS2START;
        break;

    } // switch state machine

    // clear interrupt flag
    _IC1IF = 0;

} // IC1 Interrupt


void _ISR _T2Interrupt( void)
{ // timeout
    // reset the state machine
    PS2State = PS2START;

    // stop the timer
    T2CON = 0;
    
    // clear flag and exit
    _T2IF = 0;

} // T2 Interrupt
