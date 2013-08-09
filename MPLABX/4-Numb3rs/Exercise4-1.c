//
// Numbers
//
// Exercise 4-1 use Timer2 for self timing multiplications

#include <config.c>

unsigned    timeInt, timeLong, timeLL, timeFloat, timeDouble;

char        h;
int         i1, i2, i3;
long        l1, l2, l3;
long long   ll1, ll2, ll3;
float       f1,f2, f3;
long double d1, d2, d3;

main ()
{
    // init Timer2 module
    T2CON = 0x8000; // TMR2 ON, prescale 1:1, Fosc/2 clock

    i1 = 1234;      // testing integers (16-bit)
    i2 = 5678;  
    TMR2 = 0;       // clear Timer2
    i3= i1 * i2;    
    timeInt = TMR2; // read Timer2 value
    
    l1 = 1234L;     // testing long integers (32-bit)
    l2 = 5678L; 
    TMR2 = 0;       // clear Timer2
    l3= l1 * l2;    
    timeLong = TMR2;// read Timer2 value

    ll1 = 1234LL;   // testing long long integers (64-bit)
    ll2 = 5678LL;   
    TMR2 = 0;       // clear Timer2
    ll3= ll1 * ll2; 
    timeLL = TMR2;  // read Timer2 value

    f1 = 12.34;     // testing single precision floating point
    f2 = 56.78; 
    TMR2 = 0;       // clear Timer2
    f3= f1 * f2;    
    timeFloat = TMR2;// read Timer2 value

    d1 = 12.34L;    // testing double precision floating point
    d2 = 56.78L;    
    TMR2 = 0;       // clear Timer2
    d3= d1 * d2;    
    timeDouble = TMR2;// read Timer2 value

} // main
