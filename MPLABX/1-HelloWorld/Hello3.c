/*
** Hello Embedded World
**
** Hello3.c Testing PORTB, another surprise!
*/
#include <config.h>

int main( void)
{
    PORTB =     0xff;
    TRISB =     0;      // configure all PORTB pins as outputs
    return 0;
}
