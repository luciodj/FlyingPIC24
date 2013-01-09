/*
** Glass.c
** Playing with an alphanumeric LCD display
*/
#include <config.h>

#define LCDDATA 1
#define LCDCMD  0
#define PMDATA  PMDIN1

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
    PMDATA = 0b00111000;        // 8-bit, 2 lines, 5x7
    TMR1 = 0; while( TMR1<3);   // 3 x 16us = 48us   
    
    PMDATA = 0b00001100;        // ON, cursor off, blink off
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
    dummy = PMDATA;             // initiate a read cycle, dummy
    while( PMMODEbits.BUSY);    // wait for PMP to be available
    return( PMDATA);            // read the status register
    
} // ReadLCD

#define BusyLCD() ReadLCD( LCDCMD) & 0x80
#define AddrLCD() ReadLCD( LCDCMD) & 0x7F
#define getLCD()  ReadLCD( LCDDATA)

void WriteLCD( int addr, char c)
{
    while( BusyLCD());
    while( PMMODEbits.BUSY);    // wait for PMP to be available
    PMADDR = addr;
    PMDATA = c;
} // WriteLCD
    

#define putLCD( d)  WriteLCD( LCDDATA, (d))
#define CmdLCD( c)  WriteLCD( LCDCMD, (c))
#define HomeLCD()   WriteLCD( LCDCMD, 2)
#define ClrLCD()    WriteLCD( LCDCMD, 1)
#define SetLCDC( a) WriteLCD( LCDCMD, (a & 0x7F) | 0x80)
#define SetLCDG( a) WriteLCD( LCDCMD, (a & 0x3F) | 0x40)

void putsLCD( char *s)
{
    while( *s) putLCD( *s++);
} //putsLCD


#define TFLY 9000       // 9000 x 16us = 144ms
#define DELAY() TMR1=0; while( TMR1<TFLY)


main( void)
{
    int i;
        
    // initializations
    InitLCD();
    
    // put a title on the first line    
    putsLCD( "Flying the PIC24");

    // generate two new characters
    SetLCDG(0);
    putLCD( 0b00010);
    putLCD( 0b00010);
    putLCD( 0b00110);
    putLCD( 0b11111);
    putLCD( 0b00110);
    putLCD( 0b00010);
    putLCD( 0b00010);
    putLCD( 0);     // alignment
    
    putLCD( 0b00000);
    putLCD( 0b00100);
    putLCD( 0b01100);
    putLCD( 0b11100);
    putLCD( 0b00000);
    putLCD( 0b00000);
    putLCD( 0b00000);
    putLCD( 0);     // alignment
    
    // main loop
    while( 1)
    {
        // the entire plane appears at the right margin
        SetLCDC(0x40+14);
        putLCD( 0); putLCD( 1);
        DELAY();
        
        // fly fly fly (right to left)
        for( i=13; i>=0; i--)
        {
            SetLCDC(0x40+i);        // cursor to next position
            putLCD(0); putLCD(1);   // new airplane
            putLCD(' ');            // erase the previous tail
            DELAY();
        }
        
        // the tip disappears off the left margin,
        // only the tail is visible
        SetLCDC(0x40);
        putLCD( 1); putLCD(' ');
        DELAY();       

        // erase the tail
        SetLCDC(0x40);      // point to left margin 2nd line
        putLCD(' ');
        
        // and draw just the tip appearing from the right
        SetLCDC(0x40+15);   // point to right margin 2nd line
        putLCD( 0);
        DELAY();
        
    } // repeat the main loop
} // main
