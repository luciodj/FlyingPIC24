/*
** GraphicTest.c
**
** Testing the basic graphic module
** A dark screen
*/
#include <config.h>
#include <graphic.h>

main()
{
    // initializations
    TRISA = 0;
    ClearScreen();  // init the video map
    InitVideo();    // start the video state machine

    // main loop    
    while( 1)
    {   
   
    } // main loop

} // main
