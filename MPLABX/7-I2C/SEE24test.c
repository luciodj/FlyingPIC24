/*
** SEE24 Library test
*/
#include <config.h>
#include <SEE.h>

int i, r;

main()
{
    // init the I2C peripheral
    InitSEE();

    // fill the memory and verify
    for( i=0; i<1024; i++)
    {
        iWriteSEE( i<<1, i);
        r = iReadSEE( i<<1);
        if (r!=i)
           break;
    }

    // main loop
    while( 1)
    {
        asm( "nop");
        asm( "nop");
        asm( "nop");
    }
}
