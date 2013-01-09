//
// MoreLoops.c
// Exercise 3-1 
// waiting for a button before starting the sequence
//
#include <config.h>

// 1. define timing constant
#define SHORT_DELAY 100
#define LONG_DELAY  800

// 2. declare and initialize an array with the message bitmap 
char bitmap[30] = { 
    0b11111111, // H
    0b00001000,
    0b00001000,
    0b11111111,
    0b00000000,
    0b00000000,
    0b11111111, // E
    0b10001001,
    0b10001001,
    0b10000001,
    0b00000000,
    0b00000000,
    0b11111111, // L
    0b10000000,
    0b10000000,
    0b10000000,
    0b00000000,
    0b00000000,
    0b11111111, // L
    0b10000000,
    0b10000000,
    0b10000000,
    0b00000000,
    0b00000000,
    0b01111110, // O
    0b10000001,
    0b10000001,
    0b01111110,
    0b00000000,
    0b00000000
    };
    
// 3. the main program
main()
{
    // 3.1 variable declarations
    int i;              // i will serve as the index 
    
    // 3.2 initialization
    TRISA =  0;         // all PORTA as output
    T1CON =  0x8030;    // TMR1 on, prescale 1:256 Tclk/2
    
    // 3.3 the main loop    
    while( 1)
    {
        // 3.3.0 wait for S3 to be pressed
        while( _RD6);
        
        // 3.3.1 display loop, hand moving to the right
        for( i=0; i<30; i++)
        {   // 3.3.1.1 update the LEDs
            PORTA = bitmap[i];
                
            // 3.3.1.2 short pause
            TMR1 = 0;
            while ( TMR1 < SHORT_DELAY)
            {
            }
        } // for i
            
        // 3.3.2 long pause, hand moving back to the left
        PORTA = 0;      // turn LEDs off
        TMR1 =  0;
        while ( TMR1 < LONG_DELAY)
        {
        }
    } // main loop
} // main
