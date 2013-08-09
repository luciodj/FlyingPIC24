//
// ComplexNumbers.c
//
//
#include <config.h>

__complex__ int z, k;
int r, i;

main ()
{
    // init complex variables
    k = 2 + 3j;
    __real__ z = 1;
    __imag__ z = 1;
    
    // complex integer multiplication
    k *= z;
}
