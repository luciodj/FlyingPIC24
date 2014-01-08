/*
**
** LCD.c
**
*/

#include <LCD.h>

void InitLCD( void)
{
    // PMP initialization 
    PMCON = 0x83BF;             // Enable the PMP, long waits
    PMMODE = 0x3FF;             // Master Mode 1
    PMAEN = 0x0001;             // PMA0 enabled
    
    // init TMR1
    T1CON = 0x8030;             // Fosc/2, 1:256, 16us/tick

    // wait for >30ms
    TMR1 = 0; while( TMR1<2000);// 2000 x 16us = 32ms   
    
    //initiate the HD44780 display 8-bit init sequence
    PMADDR = LCDCMD;            // command register
    PMDATA = 0b00111000;        // 8-bit interface, 2 lines,5x7
    TMR1 = 0; while( TMR1<3);   // 3 x 16us = 48us   
    
    PMDATA = 0b00001100;        // disp ON, cursor off, blink off
    TMR1 = 0; while( TMR1<3);   // 3 x 16us = 48us   
    
    PMDATA = 0b00000001;        // clear display
    TMR1 = 0; while( TMR1<100); // 100 x 16us = 1.6ms   
    
    PMDATA = 0b00000110;        // increment cursor, no shift
    TMR1 = 0; while( TMR1<100); // 100 x 16us = 1.6ms   
} // InitLCD


char ReadLCD( int addr)
{
    int dummy;
    while( PMMODEbits.BUSY);    // wait for PMP to be available
    PMADDR = addr;              // select the command address
    dummy = PMDATA;             // initiate a dummy read cycle
    while( PMMODEbits.BUSY);    // wait for PMP to be available
    return( PMDATA);            // read the status register
    
} // ReadLCD


void WriteLCD( int addr, char c)
{
    while( BusyLCD());
    while( PMMODEbits.BUSY);    // wait for PMP to be available
    PMADDR = addr;
    PMDATA = c;
} // WriteLCD
    

void putsLCD( char *s)
{
    while( *s) putLCD( *s++);
} //putsLCD
