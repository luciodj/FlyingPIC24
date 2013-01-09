/*
** DATest2.c
**
** PWM D to A Audio Test
** Square and triangular waveforms @1kHz
*/
#include <config.h>
#include <EX16.h>

int Count;

void InitAudio( void)
{
    // init the timebase
    T3CON = 0x8000;         // enable TMR3, 1:1, internal clock
    PR3 = 400-1;            // set  period for  given bitrate
    _T3IF = 0;              // clear interrupt flag
    _T3IE = 1;              // enable TMR3 interrupt

    // init PWM
    // set the initial duty cycles
    OC1R = OC1RS = 200;  

    // activate the PWM modules 
    OC1CON = 0x000E;        

} // InitAudio


void _ISRFAST _T3Interrupt( void)
{
    // Squared
    //OC1RS = (Count < 20) ? 400 : 0;
    // Half Triangular
    //OC1RS = (Count < 20)? Count*10 : 0;
    // Triangular
    OC1RS = Count *10;
    Count++;
    if ( Count >= 40)
        Count = 0;
 
    // clear interrupt flag and exit
    _T3IF = 0;
} // T3 Interrupt


main( void)
{
    InitAudio();
    
    // main loop
    while( 1);

}// main

