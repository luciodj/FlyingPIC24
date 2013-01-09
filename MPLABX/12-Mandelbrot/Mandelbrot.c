/*
** Mandelbrot.c
**
** Mandelbrot Set graphic demo
*/
#include <config.h>
#include <graphic.h>

#define SIZE  VRES
#define MAXIT 64

void Mandelbrot( float xx0, float yy0, float w)
{
    float x, y, d, x0, y0, x2, y2;
    int i, j, k;

    // calculate increments
    d = w/SIZE;
    
    // repeat on each screen pixel
    y0 = yy0;
    for (i=0; i<SIZE; i++)
    {
        x0 = xx0;
        for (j=0; j<SIZE; j++)
        {        
            // initialization
              x = x0;
              y = y0;         
              k = 0;
             
             // core iteration
              do {
                x2 = x*x;
                y2 = y*y;
                y = 2*x*y + y0;
                x = x2 - y2 + x0;                        
                k++;
              } while ( (x2 + y2 < 4)  && ( k < MAXIT)); 
            
            // check if the point belongs to the Mandelbrot set
            if ( k & 2) Plot( j, i);
            //if ( k == MAXIT) Plot( j, i);

            // compute next point x0
            x0 += d;             
         } // for j
         //PORTA = i;
         // compute next y0
         y0 += d; 
     } // for i
 } // Mandelbrot
 
main()
{
    float x, y, w;
    
    // initializations
    InitVideo();    // start the state machines
    
    // intial coordinates lower left corner of the grid 
    x = -2.0;
    y = -2.0;
    // initial grid size
    w = 4.0;
    
    while( 1)
    {    
        ClearScreen();          // clear the screen
        Mandelbrot( x, y, w);   // draw new image
       

        // wait for a button to be pressed
        while (1) 
        {  // wait for a key pressed          
            if ( !_RD6)
            {  // first quadrant
                w/= 2;
                y += w;
                break;
            }
            if ( !_RD7)
            { // second quadrant
                w/= 2;
                y += w;
                x += w;
                break;
            }
            if ( !_RA7)
            {  // third quadrant
                w/= 2;
                x += w;
                break;
            }
            if ( !_RD13)
            { // fourth quadrant
                w/= 2;
                break;
            }        
        } // wait for a key
        
    } // main loop

} // main
