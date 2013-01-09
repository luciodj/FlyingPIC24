/*
** text.h
**
** Text Page Video Module
*/
#define PAL
#define ROWS    25      // rows of text
#define COLS    48      // columns of text

// Text Page array
extern char  VMap[ COLS * ROWS];

// initializes the video output
void InitVideo( void);

// stops the video output
void HaltVideo( void);

// clears the video map 
void ClearScreen( void);

// cursor 
extern int cx, cy;

void putcV( int a);

void putsV( char *s);

void pcr( void);


#define Home()      { cx=0; cy=0;}
#define Clrscr()    { ClearScreen(); Home();}
#define AT( x, y)   { cx = (x); cy = (y);}

    
