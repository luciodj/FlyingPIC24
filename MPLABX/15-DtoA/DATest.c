/*
** DATest.c
**
** PWM D to A Audio Test
**
*/
#include <config.h>
#include <EX16.h>

void InitAudio( void)
{
    // init TMR3 to provide the timebas
    T3CON = 0x8000;         // enable TMR3,  1:1, int clock
    PR3 = 400-1;            // set period for given bitrate
    _T3IF = 0;              // clear interrupt flag
    _T3IE = 1;              // enable TMR3 interrupt

    // init PWM
    // set the initial duty cycles
    OC1R = OC1RS = 200;     // init at 50% duty cycle

    // activate the PWM modules 
    OC1CON = 0x000E;        

} // InitAudio


void HaltAudio( void)
{
    T3CON = 0;              // disable TMR3
} // Halt audio


void _ISRFAST _T3Interrupt( void)
{
    // clear interrupt flag and exit
    _T3IF = 0;
} // T3 Interrupt


main( void)
{
    InitAudio();
    
    // main loop
    while( 1);

}// main

