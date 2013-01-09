/*
** Graph1D.c
**
** Plotting a 1D function graph
** 
*/

#include <EX16.h>
#include <config.h>

#include <graphic.h>
#include <math.h>


#define X0 10
#define Y0 (VRES/2)
#define PI 3.141592654f

main( void)
{
    int x, y;
    float xf, yf;

    // initializations
    ClearScreen();
    InitVideo();    

    // draw the x and y axes crossin in (X0,Y0)
    Line( X0, 10, X0, VRES-10);     // y axes
    Line( X0-5, Y0, HRES-10, Y0);   // x axes
    
    // plot the graph of the function for 
    for( x=0; x<200; x++)
    {
        xf = (2 * PI / 50) * (float) x;
        yf =  75.0 / ( 8 * PI) * xf * sin( xf);
        Plot( x+X0, yf+Y0);
    }

    // main loop
    while( 1);

} // main
