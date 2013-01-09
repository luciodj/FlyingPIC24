/*
** AudioPWM.c
**
** 07/22/06 v1.1 
** 12/01/07 v1.2 all buffers unsigned char, no_auto_psv
*/
#include <AudioPWM.h>

// global definitions
unsigned Offset;            // 50% duty cycle value
unsigned char  _FAR  ABuffer[ 2][ B_SIZE];// double data buffer
int     CurBuf;             // index of buffer in use
volatile int AEmptyFlag;    // flag a buffer needs to be filled

// internal variables
int Stereo;                 // flag stereo play back
int Fix;                    // sign fix for 16-bit samples
int Skip;                   // skip factor, reduce sample/rate
int Size;                   // sample size (8 or 16-bit)

// local definitions
unsigned char *BPtr;        // pointer inside active buffer
int BCount;                 // count bytes used 
int Bytes;                  // number of bytes per sample

void InitAudio( long bitrate, int skip, int size, int stereo)
{
    // 1. init pointers 
    CurBuf = 0;             // start with buffer0 active first
    BPtr = &ABuffer[ CurBuf][size-1];
    BCount = B_SIZE;        // number of samples to be played
    AEmptyFlag = 0;
    Skip = skip;
    Fix = (size==2)? 0x80 : 0;  // sign correction for 16-bit                   
    Stereo = stereo;
    Size = size;
    Bytes = size*stereo;

    // 2. init the timebase
    T3CON = 0x8000;         // enable TMR3, 1:1, internal clock
    PR3 =  FCY / bitrate;   // set the period f
    Offset = PR3/2;         
    _T3IF = 0;              // clear interrupt flag
    _T3IE = 1;              // enable TMR3 interrupt

    // 3. set the initial duty cycles
    OC1R = OC1RS = Offset;  // left
    OC2R = OC2RS = Offset;  // right

    // 4. activate the PWM modules 
    OC1CON = 0x000E;        // CH1 and CH2, PWM mode, TMR3 base
    OC2CON = 0x000E;

} // InitAudio


void HaltAudio( void)
{
//    T3CON = 0;              // disable TMR3
   _T3IE = 0;
} // HaltAudio


void _ISRFAST  _T3Interrupt( void)
{
    static int sk = 1;

    // 1. skip to increase the bitrate (avoid PWM noise)
    if ( --sk == 0)
     {
        // reload the skip 
        sk = Skip;

        // 2. load the new samples for the next cycle
        OC1RS = 30+(*BPtr ^ Fix); 
        if ( Stereo==2)
            OC2RS =30 + (*(BPtr + Size) ^ Fix);
        else    // mono
            OC2RS = OC1RS;
        BPtr += Bytes;
    
        // 3. check if buffer emptied
        BCount -= Bytes;
        if ( BCount <= 0)
        {
            // 3.1 swap buffers
            CurBuf = 1- CurBuf;
            BPtr = &ABuffer[ CurBuf][Size-1];
            
            // 3.2 buffer refilled
            BCount = B_SIZE;
    
            // 3.3 flag a new buffer needs to be filled
            AEmptyFlag = 1;
        }
    } 
    
    // 4. clear interrupt flag and exit
    _T3IF = 0;
} // T3 Interrupt

