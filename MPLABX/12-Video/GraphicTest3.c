/*
** GraphicTest3.c
**
** Testing the basic graphic module
** Starry Night
*/
#include <config.h>
#include <graphic.h>

/*
void Plot( unsigned x, unsigned y) 
{
     if ((x<HRES) && (y<VRES) )
        VMap[ ((VRES-1-y)<<4) + (x>>4)] |= (0x8000 >> (x & 0xf));
} // Plot
*/


main()
{
    int i;

    // initializations
    ClearScreen();  // init the video map
    InitVideo();    // start the video state machine
    srand(13);      // seed the pseudo random number generator
    
    for( i=0; i<1000; i++)
    {
        Plot( rand()%HRES, rand()%VRES);  
    }

    // main loop    
    while( 1)
    {   
   
    } // main loop

} // main
