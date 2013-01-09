/*
** Serial-p
** UART2 RS232 asynchronous communication demonstration
** uses peripheral library uart.h 
*/

#include <ex16.h>

#include <config.h>
#include <uart.h>

// I/O definitions for hardware handshake manual I/O control
#define CTS     _RF12       // Cleart To Send, in, handshake
#define RTS     _RF13       // Request To Send, out, handshake
#define TRTS    TRISFbits.TRISF13   // tris control for RTS pin

// initialize the UART2 serial port
void InitU2( void)
{ OpenUART2( UART_EN          // enable UART2
            | UART_UEN_00       // CTS and RTS under I/O ctrl
            | UART_BRGH_FOUR    // use high speed mode FCY/4
            | UART_NO_PAR_8BIT  // no parity, 8 bit
            | UART_1STOPBIT     // one stop bit
            ,
            UART_TX_ENABLE      // enable transmitter
            , 
            FCY/4 / 115200      // set brate = 115200
            );

    RTS     = 1;        // set RTS default status
    TRTS    = 0;        // make RTS output
} // initU2


// send a character to the UART2 serial port
int putU2( char c)
{
    while ( CTS);               // wait for !CTS, clear to send
    while ( BusyUART2());       // wait while Tx buffer full
    WriteUART2( c);
    return c;
} // putU2


// wait for a new character to arrive to the UART2 serial port
char getU2( void)
{
    RTS = 0;                    // assert Request To Send !RTS
    while ( !DataRdyUART2());   // wait 
    RTS = 1;
    return ReadUART2();         // read from the receive buffer
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
