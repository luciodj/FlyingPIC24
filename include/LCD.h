/*
** LCD.h
**
*/
#include <p24fxxxx.h>

#define LCDDATA 1
#define LCDCMD  0
#define PMDATA  PMDIN1

void InitLCD( void);
char ReadLCD( int addr);

#define BusyLCD() ReadLCD( LCDCMD) & 0x80
#define AddrLCD() ReadLCD( LCDCMD) & 0x7F
#define getLCD()  ReadLCD( LCDDATA)


void WriteLCD( int addr, char c);

#define putLCD( d)  WriteLCD( LCDDATA, (d))
#define CmdLCD( c)  WriteLCD( LCDCMD, (c))

#define HomeLCD()   WriteLCD( LCDCMD, 2)
#define ClrLCD()    WriteLCD( LCDCMD, 1)
#define SetLCDG( a) WriteLCD( LCDCMD, (a & 0x3F) | 0x40)
#define SetLCDC( a) WriteLCD( LCDCMD, (a & 0x7F) | 0x80)

void putsLCD( char *s);



