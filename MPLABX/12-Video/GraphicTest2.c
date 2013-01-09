/*
** GraphicTest2.c
**
** Testing the basic graphic module
** A pattern
*/
#include <config.h>
#include <graphic.h>

main()
{
    int x, y;

    // 1. fill the video memory map with a pattern
    for( y=0; y<VRES; y++)
        for (x=0; x<HRES/16; x++)
            VMap[y*16 + x]= y;  

    // 2. start the video state machine
    InitVideo();

    // 3. main loop
    while( 1)
    {   
    } // main loop

} // main
