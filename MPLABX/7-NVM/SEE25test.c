/*
** SEE25 Library test
*/ 
#include <config.h>
#include <SEE.h>

main()
{
    int i, r;

    // initialize the SPI2 port and CS to access the 25LC256
    InitSEE();
    
    // fill memory and verify
    for( i=0; i<16*1024; i++)
    {
        iWriteSEE( i<<1, i);    // write
        r = iReadSEE( i<<1);    // read back
        if (r!=i)
           break;               // error
    }

    // main loop
    while( 1);
    
} //main
