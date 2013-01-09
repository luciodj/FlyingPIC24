/*
**  PS/2 T4 polling 
*/
#include <EX16.h>
#include <PS2.h>

#define PS2DAT  _RG12   // PS2 Data input pin
#define PS2CLK  _RG13   // PS2 Clock input pin, Open Drain
#define CLKMASK 0x2000  // mask to detect the clock line bit 13
#define DATMASK 0x1000  // mask to detect the data line bit 12

#define KMAX        20  // timeout after 500us
#define KB_SIZE     16

// definition of the keyboard PS/2 state machine 
#define PS2START    0
#define PS2BIT      1
#define PS2PARITY   2
#define PS2STOP     3

// PS2 KBD state machine and buffer
int PS2State;
int KBDBuf, KState, KCount, KParity, KTimer;

// head and tail or write and read pointers
volatile int KBR, KBW;

// circular buffer
char KCB[ KB_SIZE];

// mailbox
volatile char KBDReady;
volatile char KBDCode;


void InitKBD( void)
{
    // init I/Os
    _ODG13 = 1;     // make RG13 open drain output
    _TRISG13 = 1;   // make RG13 an input pin (for now)
    _TRISG12 = 1;   // make RG12 an input pin

    // init the circular buffer pointers
    KBR = 0;
    KBW = 0;
    // clear the flag
    KBDReady = 0;

    PR4 = 25 * 16;  // 25 us
    T4CON = 0x8000; // T4 on, prescaler 1:1
    _T4IP = 3;      // lower priority
    _T4IF = 0;      // clear interrupt flag
    _T4IE = 1;      // enable interrupt 

} // Init KBD


void _ISR _T4Interrupt( void)
{
    int PS2IN;
    // check if buffer available 
    if ( !KBDReady && ( KBR!=KBW))
    {
        KBDCode = KCB[ KBR++];
        KBR %= KB_SIZE;
        KBDReady = 1;            // signal character available
    }
 _RA0 = 1;
    // sample the inputs clock and data at the same time
    PS2IN = PORTG;
    
    // Keyboard state machine
    if ( KState) 
    {   // previous time clock was high KState 1
        if ( !(PS2IN & CLKMASK))        // PS2CLK = 0
        {   // falling edge detected, 
            KState = 0;                 // transition to State0
            KTimer = KMAX;              // restart the counter
        
            switch( PS2State){
            default:
            case PS2START:   
                if ( !(PS2IN & DATMASK))
                { 
                    KCount = 8;         // init bit counter
                    KParity = 0;        // init parity check
                    PS2State = PS2BIT;
                }
                break;

            case PS2BIT:      
                KBDBuf >>=1;            // shift in data bit
                if ( PS2IN & DATMASK)   //PS2DAT
                    KBDBuf |= 0x80;
                KParity ^= KBDBuf;      // calculate parity
                if ( --KCount == 0)     // if all bit read
                    PS2State = PS2PARITY;
                break;

            case PS2PARITY:         
                if ( PS2IN & DATMASK)
                    KParity ^= 0x80;
                if ( KParity & 0x80)     // if parity is odd
                    PS2State = PS2STOP;
                else 
                    PS2State = PS2START;   
                break;

            case PS2STOP:    
                if ( PS2IN & DATMASK)   // verify stop bit
                {
                    KCB[ KBW] = KBDBuf; // write in buffer
                    if ( (KBW+1)%KB_SIZE != KBR)// check if full
                        KBW++;          // else increment 
                    KBW %= KB_SIZE;     // wrap around
                }    
                PS2State = PS2START;
                break;

            } // switch
        } // falling edge
        else 
        { // clock still high, remain in State1
            KTimer--;
            if ( KTimer ==0)
                PS2State = PS2START;
        } // clock still high
    } // Kstate 1
    else 
    { // Kstate 0
        if ( PS2IN & CLKMASK)           // PS2CLK = 1
        { // rising edge, transition to State1
            KState = 1;
        } // rising edge
        else 
        { // clocl still low, remain in State0
            KTimer--;
            if ( KTimer == 0)
                PS2State = PS2START;
        } // clock still low
    } // Kstate 0

    // clear the interrupt flag
    _T4IF = 0;
 _RA0 = 0;
} // T4 Interrupt


// PS2 keyboard codes (standard set #2)
const char keyCodes[128]={    
                0,  F9,   0,  F5,  F3,  F1,  F2, F12,   //00
                0, F10,  F8,  F6,  F4, TAB, '`',   0,   //08
                0,   0,L_SHFT, 0,L_CTRL,'q','1',   0,   //10
                0,   0, 'z', 's', 'a', 'w', '2',   0,   //18
                0, 'c', 'x', 'd', 'e', '4', '3',   0,   //20
                0, ' ', 'v', 'f', 't', 'r', '5',   0,   //28
                0, 'n', 'b', 'h', 'g', 'y', '6',   0,   //30
                0,   0, 'm', 'j', 'u', '7', '8',   0,   //38
                0, ',', 'k', 'i', 'o', '0', '9',   0,   //40
                0, '.', '/', 'l', ';', 'p', '-',   0,   //48
                0,   0,'\'',   0, '[', '=',   0,   0,   //50
          CAPS, R_SHFT,ENTER, ']',  0,0x5c,   0,   0,   //58
                0,   0,   0,   0,   0,   0, BKSP,  0,   //60
                0, '1',   0, '4', '7',   0,   0,   0,   //68
                0, '.', '2', '5', '6', '8', ESC, NUM,   //70
              F11, '+', '3', '-', '*', '9',   0,   0    //78
            };
const char keySCodes[128] = {
                0,  F9,   0,  F5,  F3,  F1,  F2, F12,   //00
                0, F10,  F8,  F6,  F4, TAB, '~',   0,   //08
                0,   0,L_SHFT, 0,L_CTRL,'Q','!',   0,   //10
                0,   0, 'Z', 'S', 'A', 'W', '@',   0,   //18
                0, 'C', 'X', 'D', 'E', '$', '#',   0,   //20
                0, ' ', 'V', 'F', 'T', 'R', '%',   0,   //28
                0, 'N', 'B', 'H', 'G', 'Y', '^',   0,   //30
                0,   0, 'M', 'J', 'U', '&', '*',   0,   //38
                0, '<', 'K', 'I', 'O', ')', '(',   0,   //40
                0, '>', '?', 'L', ':', 'P', '_',   0,   //48
                0,   0,'\"',   0, '{', '+',   0,   0,   //50
          CAPS, R_SHFT,ENTER, '}',  0, '|',   0,   0,   //58
                0,   0,   0,   0,   0,   0, BKSP,  0,   //60
                0, '1',   0, '4', '7',   0,   0,   0,   //68
                0, '.', '2', '5', '6', '8', ESC, NUM,   //70
              F11, '+', '3', '-', '*', '9',   0,   0    //78
            };

/*                  R ALT PRNT R CTRL L GUI R GUI APPS KP / KP EN END
                    L ARROW HOME INSERT DELETE D ARROW R ARROW U ARROW PG DN
                    SCRN PG UP PAUSE 
*/

int CapsFlag=0;

char getC( void)
{
    unsigned char c;
    
    while( 1)
    {
        while( !KBDReady);      // wait for a key to be pressed
        // check if it is a break code
        while (KBDCode == (char) 0xf0)
        {   // consume the break code
            KBDReady = 0; 
            // wait for a new key code
            while ( !KBDReady);
            // check if the shift button is released
            if ( KBDCode == L_SHFT)
                CapsFlag = 0;
            // and discard it
            KBDReady = 0;       
            // wait for the next key 
            while ( !KBDReady);
        }
        // check for special keys
        if ( KBDCode == L_SHFT)
        {    
            CapsFlag = 1;
            KBDReady = 0;
        }
        else if ( KBDCode == CAPS)
        {
            CapsFlag = !CapsFlag;
            KBDReady = 0;
        }
    
        else // translate into an ASCII code
        {        
            if ( CapsFlag)
                c = keySCodes[KBDCode%128];
            else
                c = keyCodes[KBDCode%128];
            break;
        }
    }
    // consume the current character
    KBDReady = 0;
    
    return ( c);
} // getC
