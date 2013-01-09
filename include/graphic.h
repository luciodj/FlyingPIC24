/*
** graphic.h
** 
** Composite Video Graphic library
*/
#define VRES     192    // desired vertical resolution
#define HRES     256    // desired horizontal resolution (pixel)

void InitVideo( void);

void HaltVideo( void);

void ClearScreen( void);

void Plot( unsigned x, unsigned y);

void Line( int x0, int y0, int x1, int y1);

void SynchV( void);

extern int VMap[HRES/16*VRES];


/****************************************************************
** Text on Graphic Page
**
*/

extern int cx, cy;

void putcV( int a);

void putsV( char *s);


#define Home()      { cx=0; cy=0;}
#define Clrscr()    { ClearScreen(); Home();}
#define AT( x, y)   { cx = (x); cy = (y);}
    
