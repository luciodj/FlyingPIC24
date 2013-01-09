/*
**  DATest3.c
**
** PWM Audio Test
** 400Hz sinusoid precomputed @40kHz
*/
#include <EX16.h>
#include <config.h>

int Sample;            // pointer inside active buffer

const int Table[100] = {
200, 212, 225, 237, 249, 261, 273, 285, 296, 307,
317, 327, 336, 345, 354, 361, 368, 375, 380, 385,
390, 393, 396, 398, 399, 399, 399, 398, 396, 393,
390, 386, 381, 375, 368, 361, 354, 345, 337, 327,
317, 307, 296, 285, 273, 262, 250, 237, 225, 212,
200, 187, 175, 162, 150, 138, 126, 115, 103, 93,
82,  72,  63,  54,  46,  38,  31,  24,  19,  14,
9,   6,   3,   1,   0,   0,   0,   2,   3,   6,
9,   13,  18,  24,  30,  37,  45,  53,  62,  72,
81,  92,  103, 114, 125, 137, 149, 161, 174, 186
};

void InitAudio( void)
{
    // init the timebase
    T3CON = 0x8000;         // enable TMR3, 1:1, internal clock
    PR3 = 400-1;            // set period for  given bitrate
    _T3IF = 0;              // clear interrupt flag
    _T3IE = 1;              // enable TMR3 interrupt

    // init PWM
    // set the initial duty cycles
    OC1R = OC1RS = 200;  // left

    // activate the PWM modules 
    OC1CON = 0x000E;        

} // initAudio


void _ISRFAST _T3Interrupt( void)
{
    // load the new samples for the next cycle

    // 172Hz sqare wave 
    //OC1RS = (Sample++ > 128) ? 255 : 0;

    // 400 Hz sinusoid @44100
    OC1RS = Table[ Sample];
//    OC1RS = 200+ (int)( 200* sin(Sample++ *0.0628));

    if ( ++Sample >=100)
        Sample = 0;

    // clear interrupt flag and exit
    _T3IF = 0;
} // T3 Interrupt


main( void)
{
    InitAudio();
    
    // main loop
    while( 1);

}// main

