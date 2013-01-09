/*
**   WaveTest.c
**
*/
#include <config.h>
#include <fileio.h>
#include <EX16.h>
#include "Wave.h"


int main( void)
{
    InitEX16();
 
    if ( !mount())
        PORTA = FError + 0x80;
    else
    {
        PORTA = 0xFF;
        if ( PlayWAV( "SONG.WAV"))
            PORTA = 0x1;
    } // mounted

    while( 1)
    {
    } // main loop

} //main 
