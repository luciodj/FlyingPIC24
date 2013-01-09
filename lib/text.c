/*
** text.c
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
**          OC3  - RD2 - SYNC (requires AV16/32 board)
*/
#include <EX16.h>
#include <text.h>
#include <font.h>

#define VRES (ROWS*8)
#define HRES (COLS*8)

// timing definitions for video vertical state machine
#ifdef PAL
    #define V_LINES  312    // total number of lines in frame
    #define LINE_T  1024    // total number of Tcy in a line
#else  // default NTSC configuration
    #define V_LINES  262    // total number of lines in frame
    #define LINE_T  1016    // total number of Tcy in a line
#endif

#define VSYNC_N     3      // V sync lines

// count the number of remaining black lines top+bottom
#define VBLANK_N    (V_LINES -VRES - VSYNC_N)  

#define PREEQ_N   VBLANK_N /2        // pre equ + bottom blank 
#define POSTEQ_N  VBLANK_N - PREEQ_N // post eq + top blank 

// definition of the vertical sync state machine
#define SV_PREEQ    0
#define SV_SYNC     1
#define SV_POSTEQ   2
#define SV_LINE     3

// timing definitions for video horizontal state machine
#define HSYNC_T  85     // Tcy in a horizontal synch pulse
#define BPORCH_T 90     // Tcy in a back porch
// Tcy in each pixel, valid values are only 2 or 3
#define PIX_T    2      // Aspect Ratio 2 = 16:9, 3 = 4:3
// use 2 (16:9) to allow for up to 48 columns of text

// Text Page array
char  VMap[ COLS * ROWS];
char *VPtr, *LPtr;

// reordered Font
unsigned char RFont[ F_SIZE*8];
unsigned char *FPtr;

int HCount, VCount, RCount, VState; 

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
                LPtr = VMap;
                RCount = 0;
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
            OC4CON = 0x0009;    // single event 
            HCount = HRES/128;  // reload counter

            // prepare the font pointer
            FPtr = &RFont[ RCount * F_SIZE];
            // prepare the line pointer
            VPtr = LPtr;
                                               
            // Advance the RCount
            if ( ++RCount == 8)
            { 
                RCount = 0;
                LPtr += COLS;
            }
    } //switch

    // clear the interrupt flag
    _T3IF = 0;
    _RA0=0;

} // T3Interrupt


void _ISRFAST _OC4Interrupt( void) 
{    
_RA1=1;
    unsigned i,k;
    
    // load SPI buffers indirectly from font 
    i=8;
    do{
        k = FPtr[ *VPtr++];
        SPI1BUF = ( k << 8) | FPtr[ *VPtr++];;
    } while( --i >0);

    if ( --HCount > 0)
    { // activate again in time for the next SPI load
            OC4R += ( PIX_T * 8 * 16); 
            OC4CON = 0x0009;    // single event                 
    }
            
    // clear the interrupt flag
    _OC4IF = 0;
_RA1=0;

} // OC4Interrupt


void InitVideo( void)
{
    int i, j;
    const char *p;
    unsigned char *r = RFont;
    
    // 1. prepare a reversed font table
    for (i=0; i<8; i++)
    {
        p = Font8x8 + i;
        for (j=0; j<F_SIZE; j++)
        {
            *r++ = *p;
            p += 8;
        } // for j
    }  // for i   
         
    // 2. set the priority levels
    _T3IP = 4;      // this is the default value anyway
    _OC4IP = 4;

    TMR3 = 0;       // clear the timer
    PR3 = LINE_T;   // set the period register to NTSC line 
    
    // 3. configure Timer3 modules
    T3CON = 0x8000; // enabled, prescaler 1:1, internal clock 
    
    // 4. configure OC3 in continuous pulse mode
    OC3R = HSYNC_T;
    OC3RS = 0;
    OC3CON = 0x000d;    
    
    // 5. init Timer3/OC4 Interrupts, clear the flags
    _OC4IF = 0; _OC4IE = 1;
    _T3IF = 0;  _T3IE = 1;
        
    // 6. init the SPI1
    // Master, 16 bit, disable SCK, disable SS
    if ( PIX_T == 2)
        SPI1CON1 = 0x143B;  // prescaler 1:2
    else
        SPI1CON1 = 0x1437;  // prescaler 1:3
    SPI1CON2 = 0x0001;      // Enhanced mode, 8x FIFO
    SPI1STAT = 0x8000;      // enable SPI port
            
    // 7. init the vertical sync state machine
    VState = SV_PREEQ;
    VCount = PREEQ_N;
    
} // InitVideo


void ClearScreen( void)
{
    int i, j;
    char *v;
    
    v = VMap;
    
    // clear the screen     
    for ( i=0; i < (ROWS); i++)
        for ( j=0; j < (COLS); j++)
           *v++ = ' ' - F_OFFS;
} // ClearScreen


void HaltVideo( void)
{
    T3CONbits.TON = 0;   // turn off the vertical state machine
} // HaltVideo


int cx, cy;

void putcV( int a)
{    
    // check if char in font range
    a -= F_OFFS;
    if ( a < 0)         a = 0;
    if ( a >= F_SIZE)   a = F_SIZE-1; 
     
    // check page boundaries 
    if ( cx >= COLS)        // wrap around x
    {
        cx = 0;
        cy++;   
    } 
    cy %= ROWS;             // wrap around y
        
    // find first row in the video map
    VMap[ cy * COLS + cx] = a;
        
    // increment cursor position
    cx++;
} // putcV


void putsV( char *s)
{
    while (*s)
        putcV( *s++);
} // putsV


void pcr( void)
{
    cx = 0; 
    cy++;
    cy %= ROWS;
} // pcr
