/*
** TEMPgame.c
** Playing with a Temperature Sensor
*/
#include <EX16.h>
#include <config.h>

main ()
{
    int temp, ref, pos, mallet, mole, j;
    
    // 1. initializations
    InitADC( TEMPMASK); // initialize the ADC and analog inputs
    TRISA = 0xff00;     // all PORTA pins as outputs 

    // 2. use the first reading to randomize a number generator
    srand( ReadADC( TEMP_CH)); 
    // generate the first random position
    mole = 0x80 >> (rand() & 0x7);
      
    // 3. compute the average value for the initial reference 
    temp = 0;
    for ( j= 0; j<16; j++)
         temp += ReadADC( TEMP_CH);  // read the temperature
    ref = temp >> 4;
    
    // 4. main loop
    while( 1)
    {   
        // 4.1 take the average temperature
        temp = 0;
        for ( j=0; j<16; j++)
        {   
            temp += ReadADC( TEMP_CH); // read the temperature
        }
        temp >>= 4;                    // averaged over 16 values

        // 4.2 compare with the initial reading
        //    and move the bar 1 pos. per C
        pos = 3 + (temp - ref);
        
        // 4.3 keep result in value range 0..7, keep bar visible
        if ( pos > 7)
            pos = 7;
        if ( pos < 0)
            pos = 0;

        // 4.4 turn on the corresponding LED
        mallet = ( 0x80 >> pos);
        
        // display result for 1/2 second
        for( j=0; j<128; j++)
        { // display the user LED and dim random LED
            if ((j & 0xf) == 0)
                PORTA = mallet + mole;
            else
                PORTA = mallet ;
            Delayms( 5);
        }

        // 4.5 when the cursor hits mole LED, generate new one
        while ( mallet == mole )
            mole = 0x80 >> (rand() & 0x7);
    } // main loop
} // main
