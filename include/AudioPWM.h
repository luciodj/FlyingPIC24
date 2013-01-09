/*
** AudioPWM.h
**
*/
#include <EX16.h>       // defines FCY
#define TCYxUS  16      // number of Tcycles in a microsecond
#define B_SIZE  2048    // audio buffer size

extern unsigned char ABuffer[ 2][ B_SIZE]; // double data buffer
extern int CurBuf;              // index of buffer in use
extern volatile int AEmptyFlag; // flag a buffer needs to be filled

void InitAudio( long bitrate, int skip, int size, int stereo);
void HaltAudio( void);
