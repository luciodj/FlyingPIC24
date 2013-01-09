/*
** Wave.C
** 
**  Wave File Player 
**  Uses 2 x 8 bit PWM channels at 44kHz
*/

#include <EX16.h>
#include <AudioPWM.h>
#include <SDMMC.h>
#include <fileio.h>
#include <stdlib.h>
#include "Wave.h"

// WAVE file constants
#define  RIFF_DWORD  0x46464952UL
#define  WAVE_DWORD  0x45564157UL
#define  DATA_DWORD  0x61746164UL
#define  FMT_DWORD   0x20746d66UL     
#define  WAV_DWORD   0x00564157UL


typedef struct {
    long ckID;
    long ckSize;
    long ckType;
} chunk;

typedef struct {
    // format chunk 
    unsigned short  subtype;    // compression code  
    unsigned short  channels;   // # of channels
                                //  (1= mono,2= stereo)
    unsigned long   srate;      // sample rate in Hz
    unsigned long   bps;        // bytes per second
    unsigned short  align;      // block alignement
    unsigned short  bitpsample; // bit per sample
//    unsigned short  extra;      // extra format bytes
} WAVE_fmt;


unsigned PlayWAV( char *name)
{
    chunk       ck;    
    WAVE_fmt    wav;
    int         last;
    MFILE       *fp;
    unsigned long lc, r, d;

    // audio codec parameters
    int skip, size, stereo;
    unsigned long rate;
    
    // 1. open the file           
    if ( (fp = fopenM( name, "r")) == NULL)
    {   // failed to open 
        return FALSE;
    }
    
    // 2. verify it is a RIFF-WAVE formatted file
    freadM( (void*)&ck, sizeof(chunk), fp);
       
    // check that file type is correct
    if (( ck.ckID != RIFF_DWORD) || ( ck.ckType != WAVE_DWORD))
        goto Exit;
        
    // 3. look for the chunk containing the wave format data
    freadM( (void*)&ck, 8, fp);
    if ( ck.ckID != FMT_DWORD)
        goto Exit;

    // 4. get the WAVE_FMT struct
    freadM( (void*)&wav, sizeof(WAVE_fmt), fp);
    stereo = wav.channels;
     
    // 5. skip extra format bytes
    fseekM( fp, ck.ckSize - sizeof(WAVE_fmt));
         
    // 6. search for the "data" chunk
    while( 1)
    {   // read next chunk 
        if ( freadM( (void*)&ck, 8, fp) != 8)
            goto Exit;

        if ( ck.ckID != DATA_DWORD)
            fseekM( fp, ck.ckSize );
        else
            break;
    } 

    // 7. find the data size 
    lc = ck.ckSize;

    // 8. compute the period and adjust the bit rate
    rate = wav.srate;          // r = samples per second
    skip = 1;                  // skip factor to reduce noise
    while ( rate < 22050)
    {
        rate <<= 1;            // divide sample rate by two
        skip <<= 1;            // multiply skip by two
    }
    
    // 9. check if the sample rate compatible with TMR3 
    d = (FCY/rate)-1;
    if ( d > ( 65536L))        // max TMR3 period (16 bit)
    {
        fcloseM( fp);
        return FALSE;
    }
    
    // 10. init the Audio state machine
    CurBuf = 0;
    stereo = wav.channels;
    size  = 1;                  // default, bytes per channel
    if ( wav.bitpsample == 16)
        size = 2;
    
    // 11. start loading both buffers
    if ( lc < B_SIZE*2)         // allow for files > BSIZE*2
        goto Exit;
    r = freadM( ABuffer[0], B_SIZE*2, fp);
    AEmptyFlag = FALSE;         // both buffers are full
    lc-= B_SIZE*2 ;             // keep track of what is left
        
    // 12. start playing, enable the interrupt 
    InitAudio( rate, skip, size, stereo);
    
    // 13. keep feeding the buffers in the playing loop
    while (lc >=B_SIZE)
    {
        if ( ReadKEY())              // on pressing any key
        {                           
            lc = 0;               // signal playback completed
            break;
        }
        if ( AEmptyFlag)
        {
            r = freadM( ABuffer[1-CurBuf], B_SIZE, fp);
            AEmptyFlag = FALSE;
            lc-= B_SIZE;
            
        }
    } // while wav data available

    // 14. flush the buffers with the data tail
    if( lc>0) 
    {
        // load the last sector 
        r = freadM( ABuffer[1-CurBuf], lc, fp);
        last = ABuffer[1-CurBuf][r-1];
        while(( r<B_SIZE) && (last>0)) 
            ABuffer[1-CurBuf][r++] = last;
        
        // wait for current buffer to be emptied
        AEmptyFlag = 0;
        while (!AEmptyFlag);
    }

    // 15.finish the last buffer
    AEmptyFlag = 0;
    while (!AEmptyFlag);
    
Exit:
    // 16. stop playback 
    HaltAudio();

    // 17. close the file 
    fcloseM( fp);

    // 18. return with success
    return TRUE;

} // playWAV

