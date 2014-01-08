/*
** Numbers.c
*/
#include <config.h>

int         i1, i2, i3;
long        x1, x2, x3;
long long   xx1, xx2, xx3;
float       f1,f2, f3;
long double d1, d2, d3;

main()
{
    T1CON = 0x8000;     // enable Timer1 1:1 with main clock

    i1 = 0x1234;        // testing integers (16-bit)
    i2 = 0x5678;
    TMR1 = 0;           // clear the timer
    i3 = i1 * i2;
   
    x1 = 0x01234567L;   // testing long integers (32-bit)
    x2 = 0x89ABCDEFL;
    TMR1 = 0;           // clear the timer
    x3 = x1 * x2;

    xx1 = 0x0123456789ABCDEFLL;   // testing 64-bit integers
    xx2 = 0xFEDCBA9876543210LL;
    TMR1 = 0;                     // clear the timer
    xx3 = xx1 * xx2;

    f1 = 12.34;     // testing single precision floating point
    f2 = 56.78; 
    TMR1 = 0;       // clear the timer
    f3 = f1 * f2;

    d1 = 12.34L;    // testing double precision floating point
    d2 = 56.78L;    
    TMR1 = 0;       // clear the timer
    d3 = d1 * d2;

} // main
