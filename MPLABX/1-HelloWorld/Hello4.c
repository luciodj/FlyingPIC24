/*
** Hello Embedded World
**
** Hello4.c learning to control the Analog Pins
*/
#include <config.h>

int main( void)
{
    PORTB   = 0xff;
    AD1PCFG = 0xffff;       // all PORTB as digital
    TRISB   = 0;            // all PORTB as output
    return 0;
}
