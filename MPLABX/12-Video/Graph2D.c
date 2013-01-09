/*
** Graph2D.c 
**
** Plotting a 2D function graph
** 
*/

#include <EX16.h>
#include <config.h>

#include <graphic.h>
#include <math.h>

#define X0      10
#define Y0      10
#define PI      3.141592654f
#define NODES   20
#define SIDE    10

typedef struct {
        int x;
        int y;
    } point;

point edge[NODES], prev;

main( void)
{
    int i, j, x, y, z;
    float xf, yf, zf, sf;
    int px, py;

    // initializations
    ClearScreen();
    InitVideo();    

    // draw the x, y and z axes crossing in (X0,Y0)
    Line( X0, 10, X0, VRES-50);         // z axis
    Line( X0-5, Y0, HRES-10, Y0);       // x axis
    Line( X0-2, Y0-2, X0+120, Y0+120);  // y axis

    // init the array of previous egde points
    for( j = 0; j<NODES; j++)
    {
        edge[j].x = X0+ j*SIDE/2;
        edge[j].y = Y0+ j*SIDE/2;
    }

    // Plot the graph of the function for
    for( i=0; i<NODES; i++)
    {
        // transform the x coordinate range to 0..200 offset 100
        x = i * SIDE;
        xf = (6 * PI / 200) * (float)(x-100);
        prev.y = Y0;
        prev.x = X0 + x;

        for ( j=0; j<NODES; j++)
        { 
            // transform the y coordinate range to 0..200 offset 100
            y = j * SIDE;
            yf = (6 * PI / 200) * (float)(y-100);
            
            // compute the function
            sf = sqrt( xf * xf + yf * yf);
            zf = 1/(1+ sf) * cos( sf );
            
            // scale the output
            z = zf * 75;
            
            // apply isometric perspective and offset
            px = X0 + x + y/2;
            py = Y0 + z + y/2; 
            
            // Plot the point
            Plot( px, py);
        
            // draw connecting Lines to visualize the grid
            Line( px, py, prev.x, prev.y);  // connect to prev point on same x
            Line( px, py, edge[j].x, edge[j].y);

            // update the previous points
            prev.x = px;
            prev.y = py;
            edge[j].x = px;
            edge[j].y = py;
        } // for j
    } // for i

    // main loop
    while( 1);

} // main
