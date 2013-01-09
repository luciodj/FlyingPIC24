/*
**  The Matrix
**
*/
#include <config.h>
#include <CONU2.h>
#include <stdlib.h>

#define COL     40
#define ROW     23
#define DELAY 3000

main()
{
    int v[40];  // vector containing lengh of each string
    int i,j,k;
    
    // 1. initializations
    T1CON = 0x8030; // TMR1 on, prescale 256, Tcy/2
    InitU2();       // initialize the console
    Clrscr();       // clear the terminal (VT100 emulation)
    getU2();        // wait for character to randomize sequence
    srand( TMR1); 
    
    // 2. init each column lenght
    for( j =0; j<COL; j++)
            v[j] = rand()%ROW;
    
    // 3. main loop
    while( 1)
    {
        Home();
        
        // 3.1 refresh the screen with random columns
        for( i=0; i<ROW; i++)
        {
            // 3.1.1 delay to slow down the screen update
            TMR1 =0;   
            while( TMR1<DELAY);
            
            // refresh one row at a time
            for( j=0; j<COL; j++)
            {
            // print random characters for each column length
                if ( i < v[j])
                    putU2( 33 + (rand()%94));
                else 
                    putU2(' ');
                putU2( ' ');
            } // for j
            pcr();
        } // for i

        // 3.2 randomly increase or reduce each column length
        for( j=0; j<COL; j++)
        {
            switch ( rand()%3)
            {
              case 0: // increase length
                v[j]++;
                if (v[j]>ROW)
                    v[j]=ROW;
                break;

              case 1: // decrease length
                v[j]--;
                if (v[j]<1)
                    v[j]=1;
                break;

              default:// unchanged 
                        break;
             } // switch
        } // for
    } // main loop
} // main
