/*
**  The Matrix Reloaded
**
*/
#include <config.h>
#include <text.h>

#define COL     COLS
#define ROW     ROWS

// define an alien character (sub)set
const char ALIEN[] = "{}[]!@#^*)(+-\\|`~_-=";

main()
{
    int v[ COL];  // vector containing lengh of each string
    int i,j,k;
    
    // 1. initializations
    TRISA=0;
    InitVideo();
    Clrscr();       // clear the screen
    srand( 12);     // start the random number sequence
    
    // 2. init each column lenght
    for( j =0; j<COL; j++)
            v[j] = rand()%ROW;
    
        Home();
        
    // 3. refresh the screen with random columns
    for( i=0; i<ROW; i++)
    {
        // refresh one row at a time
        for( j=0; j<COL; j++)
        {
            // print a random character down to each column lenght
            if ( i < v[j])
                putcV( ALIEN[ rand()%20]);
            else 
                putcV(' ');
//                putcV( ' ');
        } // for j
        pcr();            
    } // for i

    // 4. main loop
    while( 1)
    {
        // 4.1 delay to slow down the screen update
        Delayms( 200);
        
        // 4.2 randomly increase or reduce each column lenght
        for( j=0; j<COL; j++)
        {
            switch ( rand()%3)
            {
                case 0: // increase length
                    v[j]++;
                    if (v[j] > ROW) v[j] = ROW;
                    // add new random character
                    AT( j,v[j]-1);
                    putcV( ALIEN[ rand()%20]);
                    break;
                        
                case 1: // decrease length
                    // remove character
                    if (v[j]>0)
                    {
                        AT( j,v[j]-1);
                        putcV( ' ');
                        v[j]--;
                    }
                    break;
                        
                default:// unchanged 
                    break;
             } // switch
        } // for
    } // main loop
} // main
