//
// Numbers
//
// Exercise 4-3 use Timer2 for self timing divisions

#include <config.h>
#include <math.h>

unsigned    timeInt, timeLong, timeLL, timeFloat, timeDouble;

float       f1,f2, f3;
long double d1, d2, d3;

main ()
{
    // init Timer2 module
    T2CON = 0x8000; // TMR2 ON, prescale 1:1, Fosc/2 clock


    f1 = 12.34;     // testing single precision floating point
    f2 = 56.78; 
    TMR2 = 0;       // clear Timer2
    f3 = sinf( f2); 
    timeFloat = TMR2;// read Timer2 value

    d1 = 12.34L;    // testing double precision floating point
    d2 = 56.78L;    
    TMR2 = 0;       // clear Timer2
    d3 = sin( d2);  
    timeDouble = TMR2;// read Timer2 value

} // main
