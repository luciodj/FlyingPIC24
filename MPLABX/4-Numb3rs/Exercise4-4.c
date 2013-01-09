//
// Complex Numbers
//
// Exercise 4-4 self timing complex math
//

#include <p24fxxxx.h>

unsigned    timeInt, timeLong, timeLL, timeFloat, timeDouble;
__complex__ int z, k;
__complex__ float fz, fk;

main ()
{
    // init Timer2 module
    T2CON = 0x8000; // TMR2 ON, prescale 1:1, Fosc/2 clock

    // init complex variables 
    k = 2 + 3j;
    __real__ z = 1;
    __imag__ z = 1;
    fk = 2.0 + 3.0j;
    fz = 4.0 + 5.0j;
    
    // integer complex multiplication
    TMR2 = 0;   
    k *= z;
    timeInt = TMR2;
    
    // float complex multiplication
    TMR2 = 0;   
    fk *= fz;
    timeFloat = TMR2;
    
}
