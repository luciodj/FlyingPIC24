/*
** TextTest.c
**
*/
#include <config.h>
#include <graphic.h>

main( void)
{
    int i;
    
    // initializations
//TRISA=0;
    InitVideo();    // start the state machines
    Clrscr();
    
    AT( 0, 0);
    putsV( "FLYING THE PIC24!");
        
    AT( 0, 2);
    for( i=32; i<128; i++)
    {
        putcV( i);
    }
    while (1);

} // main
