/*
** CONU2 Test
** UART2 RS232 asynchronous communication demonstration
*/
#include <config.h>
#include <CONU2.h>

#define BUF_SIZE 128

main()
{
    char s[ BUF_SIZE];
    
    // 1. init the console serial port 
    InitU2();
    
    // 2. text prompt 
    Clrscr();
    Home();
    putsU2( "Learn to fly with the PIC24!\r\n");
    sprintf( s, "Learn to fly the PIC24! %d\r\n", 17);
    putsU2( s);
    
    // 3. main loop
    while ( 1)
    {
        // 3.1 read a full line of text
        getsnU2( s, sizeof(s));
        // 3.2 send a string to the serial port
        putsU2( s);
        // 3.3 send a carriage return
        pcr();
    } // main loop
}// main
