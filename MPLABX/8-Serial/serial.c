/*
** Serial
** UART2 RS232 asynchronous communication demonstration
*/
#include <config.h>

// I/O definitions for the Explorer16
#define CTS     _RF12       // Cleart To Send, in, handshake
#define RTS     _RF13       // Request To Send, out, handshake
#define TRTS    TRISFbits.TRISF13   // tris control for RTS pin

// timing and baud rate calculations
#define BRATE    34         // 115200 baud (BREGH=1)
#define U_ENABLE 0x8008     // enable the UART peripheral 
#define U_TX     0x0400     // enable transmission


// initialize the UART2 serial port
void InitU2( void)
{
    U2BRG   = BRATE;    
    U2MODE  = U_ENABLE;
    U2STA   = U_TX;
    RTS     = 1;        // set RTS default status
    TRTS    = 0;        // make RTS output
} // initU2


// send a character to the UART2 serial port
int putU2( int c)
{
    while ( CTS);               // wait for !CTS, clear to send
    while ( U2STAbits.UTXBF);   // wait while Tx buffer full
    U2TXREG = c;
    return c;
} // putU2


// wait for a new character to arrive to the UART2 serial port
char getU2( void)
{
    RTS = 0;                    // assert Request To Send !RTS
    while ( !U2STAbits.URXDA);  // wait 
    RTS = 1;
    return U2RXREG;             // read from the receive buffer
}// getU2


main()
{
    char c;
    
    // 1. init the UART2 serial port 
    InitU2();
    
    // 2. prompt 
    putU2( '>');
    
    // 3. main loop
    while ( 1)
    {
        // 3.1 wait for a character
        c = getU2();

        // 3.2 echo the character
        putU2( c);           
    } // main loop
    
}// main
