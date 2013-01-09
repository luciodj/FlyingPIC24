/*
** LineTest1.c
**
** Testing the basic graphic module
** Drawing lines
*/
#include <config.h>
#include <graphic.h>

main()
{
    int x;
    float x0 = 10, y0 = 20, x1 = 200, y1 = 150, x2 = 20, y2 = 150;

    // initializations
    ClearScreen();  // init the video map
    InitVideo();    // start the video state machine

    // draw an oblique line (x0,y0) � (x1,y1)
    for( x=x0; x<x1; x++)
        Plot( x, y0+(y1-y0)/(x1-x0)* (x-x0));

    // draw a second (steeper) line (x0,y0) � ( x2,y2)
    for( x=x0; x<x2; x++)
        Plot( x, y0+(y2-y0)/(x2-x0)* (x-x0));

    // main loop    
    while( 1)
    {   
    } // main loop

} // main
