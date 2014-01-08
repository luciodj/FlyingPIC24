/*
**
** Playing with an LCD display
*/

#include <config.h>
#include <LCD.h>

#define TFLY 9000       // 9000 x 16us = 144ms
#define DELAY() TMR1=0; while( TMR1<TFLY)

int cg[] = { 0x0041, 0x0187, 0x3fff, 0x5563, 0xffff, 0x0380, 0x01c0};
char sg[24];

void Sprite( int shift)
{    // shift is a value 0..14
    long l;
    int i; 
    
    for( i=0; i<7; i++)
    {
         l = ((long)cg[i]) << shift;
         sg[i] = l >> 20;
         sg[i+8] = l >> 10;
         sg[i+16] = l >> 2;
    }
    sg[7] = 0;
    sg[15] = 0;
    sg[23]= 0;
    
    // generate three new characters from the sprite sg
    SetLCDG(0);
    for( i=0; i<24; i++)
        putLCD( sg[ i]);
}
             
main( void)
{
    int i, j;
        
    // initializations
    InitLCD();
    
    // put a title on the first line    
    putsLCD( "Flying the PIC24");

    
    // main loop
    while( 1)
    {
        // erase the tail
        
        // fly fly
        for( i=13; i>=0; i--)
        {
            for( j = 0; j<8; j++)
            {
                Sprite( j);
                SetLCDC(0x40+i);      // set the cursor
                putLCD(1); putLCD(0); putLCD(4);
                DELAY();
            } // for j
        } // for i
        
        // the tip disappears, only the tail is visible
    } // main loop
} // main
