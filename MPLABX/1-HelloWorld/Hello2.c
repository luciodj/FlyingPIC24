/*
** Hello Embedded World
**
** Hello2.c controlling PortA pin direction
*/
#include <config.h>     // set the configuration bits

int main( void)
{
    PORTA =     0xff;
    TRISA =     0;      // configure all PORTA pins as outputs
    return 0;
}
