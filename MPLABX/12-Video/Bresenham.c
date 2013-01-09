/*
** Bresenham.c
**
** Testing the graphic module
** Bresenham line drawing algorithm
*/
#include <config.h>
#include <graphic.h>
#include <stdlib.h>

main()
{
    int i;

    // initializations
    InitVideo();    // start the state machines
    srand( 12);
    
    // main loop
    while( 1)
    {   
        ClearScreen();
        Line( 0, 0, 0, VRES-1);
        Line( 0, VRES-1, HRES-1, VRES-1);
        Line( HRES-1, VRES-1, HRES-1, 0);
        Line( 0, 0, HRES-1, 0);
    
        for( i = 0; i<100; i++)     
            Line( rand()%HRES, rand()%VRES, rand()%HRES, rand()%VRES);
        while( 1)
        {        
            if ( !_RD6)
                break;
        } // wait for a key

    } // main loop

} // main
