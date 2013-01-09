/*
**
**  PS/2 Change Notification
**
*/
#include <EX16.h>
#include <PS2.h>

#define PS2DAT  _RG12       // PS2 Data input pin
#define PS2CLK  _RG9        // PS2 Clock input pin 

// definition of the keyboard PS/2 state machine 
#define PS2START    0
#define PS2BIT      1
#define PS2PARITY   2
#define PS2STOP     3

// PS2 KBD state machine and buffer
int PS2State;
int KBDBuf, KCount, KParity;

// mailbox
volatile char KBDReady;
volatile char KBDCode;


void InitKBD( void)
{
    // init I/Os
    _TRISG9 = 1;            // make RG9 an input pin 
    _TRISG12 = 1;           // make RG12 an input pin

    // clear the flag
    KBDReady = 0;

    CNEN1 = 0x0800;         // enable CN11 - RG9 pin 
    _CNIF = 0;              // clear the interrupt flag
    _CNIE = 1;              // enable  change notification int
} // InitKBD



void _ISR _CNInterrupt( void)
{ // change notification interrupt service routine

    // make sure it was a falling edge
    if ( PS2CLK == 0)
    {
        switch( PS2State){
        default:
        case PS2START:   
            if ( ! PS2DAT)
            { 
                KCount = 8;             // init bit counter
                KParity = 0;            // init parity check
                PS2State = PS2BIT;
            }
            break;
    
        case PS2BIT:      
            KBDBuf >>=1;                // shift in data bit
            if ( PS2DAT)                
                KBDBuf |= 0x80;
            KParity ^= KBDBuf;          // update parity
            if ( --KCount == 0)         // if all bit read
                PS2State = PS2PARITY;   //    move on
            break;
    
        case PS2PARITY:         
            if ( PS2DAT)
                KParity ^= 0x80;
            if ( KParity & 0x80)        // if parity is odd
                PS2State = PS2STOP;     //    move on
            else 
                PS2State = PS2START;   
            break;
    
        case PS2STOP:    
            if ( PS2DAT)                // verify stop bit
            {
                KBDCode = KBDBuf;       // keycode in mailbox
                KBDReady = 1;           // set flag, available
            }    
            PS2State = PS2START;
            break;
    
        } // switch state machine
    } // if falling edge

    // clear interrupt flag
    _CNIF = 0;

} // CN Interrupt

