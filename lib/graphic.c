/*
** graphic.c
** NTSC/PAL Video Generator using: 
**      T3      Interrupt for main timing
**      OC3     Horizontal Synchronization pulse
**      OC4     SPI buffer reload timing
**      SPI1    pixel serialization (8x16-bit FIFO)
**
** Author: Lucio Di Jasio mailto:pilot@flyingpic24.com
**     rev 2.0 - 06/06/06
**     rev 2.1 - 01/07/08 disabled sck
**     rev 3.0 - 04/28/08 OC3 in PWM mode hw optimization
** Pin assignements:                  
**          SDO1 - RF8 - VIDEO
**          OC3  - RD2 - SYNC32 (requires AV16/32 board)
*/
#include <EX16.h>
#include <font.h>
#include <graphic.h>

// timing definitions for video vertical state machine
#ifdef PAL
    #define V_LINES  312    // total number of lines composing a frame
    #define LINE_T  1024    // total number of Tcy in a line

#else  // default NTSC configuration
    #define V_LINES  262    // total number of lines composing a frame
    #define LINE_T  1016    // total number of Tcy in a line
#endif

#define VSYNC_N  3      // V sync lines

// count the number of remaining black lines top+bottom
#define VBLANK_N    (V_LINES -VRES - VSYNC_N)  

#define PREEQ_N   VBLANK_N /2          // pre equalization + bottom blank lines
#define POSTEQ_N  VBLANK_N - PREEQ_N   // post equalization + top blank lines

// definition of the vertical sync state machine
#define SV_PREEQ    0
#define SV_SYNC     1
#define SV_POSTEQ   2
#define SV_LINE     3

// timing definitions for video horizontal state machine
#define HSYNC_T  90     // Tcy in a horizontal synch pulse 
#define BPORCH_T 90     // Tcy in a back porch 
// Tcy in each pixel, valid values are only 2 or 3
#define PIX_T    2      // Aspect Ratio 2 = 16:9, 3 = 4:3

int _FAR VMap[ VRES * (HRES/16)];

int *VPtr;
int HCount, VCount, VState;

// next state table
int VS[4] = { SV_SYNC, SV_POSTEQ, SV_LINE, SV_PREEQ};
// next counter table
int VC[4] = { VSYNC_N,  POSTEQ_N,    VRES,  PREEQ_N};


void _ISRFAST _T3Interrupt( void)
{
    _RA0=1;
    // advance the state machine
    if ( --VCount == 0)
    {
        VCount = VC[ VState];
        VState = VS[ VState];
     }
    
    // vertical state machine
    switch ( VState) {
        case SV_PREEQ:  // 0
            // prepare for the new frame
            VPtr = VMap;
            break;
            
        case SV_SYNC:   // 1
            // vertical sync pulse
            OC3R = LINE_T - HSYNC_T - BPORCH_T;
            break;
            
        case SV_POSTEQ: // 2
            // horizontal sync pulse
            OC3R = HSYNC_T;
            break;
            
        default:            
        case SV_LINE:   // 3
            // activate OC4 for the SPI loading
            OC4R = HSYNC_T + BPORCH_T;
            OC4CON = 0x0009;    // single pulse mode
            HCount = HRES/128;  // loads 8x16 bits at a time 
            break;                                               
    } //switch

    // clear the interrupt flag
    _T3IF = 0;
    _RA0=0;
} // T3Interrupt


void _ISRFAST _OC4Interrupt( void) 
{    
    _RA1=1;
    // load SPI FIFO with 8 x 16-bit words = 128 pixels
    SPI1BUF = *VPtr++; 
    SPI1BUF = *VPtr++; 
    SPI1BUF = *VPtr++; 
    SPI1BUF = *VPtr++; 
    SPI1BUF = *VPtr++; 
    SPI1BUF = *VPtr++; 
    SPI1BUF = *VPtr++; 
    SPI1BUF = *VPtr++; 

    if ( --HCount > 0)
    { // activate again in time for the next SPI load
            OC4R += ( PIX_T * 7 * 16); 
            OC4CON = 0x0009;    // single pulse mode
    }
            
    // clear the interrupt flag
    _OC4IF = 0;
    _RA1=0;
} // OC4Interrupt


void InitVideo( void)
{
    // 1. set the priority levels
    _T3IP = 4;      // this is the default value anyway
    _OC4IP = 4;

    // 2 configure Timer3 modules
    TMR3 = 0;       // clear the timer
    PR3 = LINE_T;   // set the period register to video line
    T3CON = 0x8000; // enabled, prescaler 1:1, internal clock 
    
    // 3. configure OC3 in continuous pulse mode
    OC3R = HSYNC_T;
    OC3RS = 0;
    OC3CON = 0x000d;    
    
    // 4. enable Timer3/OC4 interrupts, clear the flags
    _OC4IF = 0; _OC4IE = 1;
    _T3IF = 0;  _T3IE = 1;
        
    // 5. init the SPI1
    // Master, 16 bit, disable SCK, disable SS
    if ( PIX_T == 2)
        SPI1CON1 = 0x143B;  // prescaler 1:3
    else
        SPI1CON1 = 0x1437;  // prescaler 1:2
    SPI1CON2 = 0x0001;      // Enhanced mode, 8x FIFO
    SPI1STAT = 0x8000;      // enable SPI port
            
    // 6. init the vertical sync state machine
    VState = SV_PREEQ;
    VCount = PREEQ_N;
    
} // InitVideo


void ClearScreen( void)
{
    int i;
    int *v;
    
    v = (int *)&VMap[0];
    
    // clear the screen     
    for ( i=0; i < (VRES*( HRES/16)); i++)
        *v++ = 0;
} // ClearScreen


void HaltVideo( void)
{
    T3CONbits.TON = 0;   // turn off the vertical state machine
} // HaltVideo

void SynchV( void) 
{
    while ( VState != SV_PREEQ);
} // SynchV


void Plot( unsigned x, unsigned y)
{
     if ((x<HRES) && (y<VRES) )
        VMap[ ((VRES-1-y)<<4) + (x>>4)] |= (0x8000 >> (x & 0xf));
} // Plot

#define abs( a)     (((a)> 0) ? (a) : -(a))

void Line( int x0, int y0, int x1, int y1)
{
     int steep, t ;
     int deltax, deltay, error;
     int x, y;
     int ystep;

     steep = ( abs(y1 - y0) > abs(x1 - x0));
     
     if ( steep )
     { // swap x and y
         t = x0; x0 = y0; y0 = t;
         t = x1; x1 = y1; y1 = t;
     }
     if (x0 > x1) 
     {  // swap ends
         t = x0; x0 = x1; x1 = t;
         t = y0; y0 = y1; y1 = t;
     }
     
     deltax = x1 - x0;
     deltay = abs(y1 - y0);
     error = 0;
     y = y0;
     
     if (y0 < y1) ystep = 1; else ystep = -1;
     for (x = x0; x < x1; x++)
     {
         if ( steep) Plot(y,x); else Plot(x,y);
         error += deltay;
         if ( (error<<1) >= deltax)
         {
             y += ystep;
             error -= deltax;
         } // if 
     } // for
} // Line


/****************************************************************
** Text on Graphic Page
*/

int cx, cy;


void putcV( int a)
{
    int i, *p;
    const char *pf;
    
    // 1. check if char in range
    a -= F_OFFS;
    if ( a < 0)         a = 0;
    if ( a >= F_SIZE)   a = F_SIZE-1; 
     
    // 2. check page boundaries 
    if ( cx >= HRES/8)          // wrap around x
    {
        cx = 0;
        cy++;   
    } 
    if ( cy >= VRES/8)          // wrap around y (or scroll?)
        cy = 0;
        
    // 3. set pointer to word in the video map
    p = &VMap[ cy * 8 * HRES/16 + cx/2];
    // set pointer to first row of the character in the font array
    pf = &Font8x8[ a << 3];
    
    // 4. copy one by one each line of the character on the screen
    for ( i=0; i<8; i++)
    {
        if ( cx & 1)
        {
            *p &= 0xff00;
            *p |= *pf++;
        } 
        else 
        {
            *p &= 0xff;
            *p |= (*pf++)<<8;
        }   
        // point to next row
        p += HRES/16; 
    } // for
    
    // increment cursor position
    cx++;
} // putcV

void putsV( char *s)
{
    while (*s)
        putcV( *s++);
} // putsV
