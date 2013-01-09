/*
** POTgame.c
** Playing with a potentiometer
*/
#include <EX16.h>
#include <config.h>

main ()
{
    int pot, pos, mole, mallet, c;
    
    // initializations
    TRISA = 0xff00;     // select all PORTA pins as outputs 
    
    // initialize ADC and analog inputs
    InitADC( POTMASK);  
    
    // use the first reading to randomize the number generator
    srand( ReadADC( POT_CH)); 
    // generate the first random position
    mole = 0x80 >> (rand() & 0x7);
    // init the counter
    c = 0;
      
    // main loop
    while( 1)
    {   
        // select the POT input and convert 
        pot = ReadADC( POT_CH);

        // reduce the 10-bit result to a 3 bit value (0..7)
        // (divide by 128 or shift right 7 times
        pos = pot >> 7;
        
        // turn on only the corresponding LED
        // 0 -> leftmost LED.... 7-> rigtmost LED
        mallet = (0x80 >> pos);

        // when the cursor hits the mole LED, generate new one
        while (mallet == mole )
            mole = 0x80 >> (rand() & 0x7);
          
        // display the user LED and 50% dim random LED
        if ((c & 0xf) == 0) 
            PORTA = mallet + mole;
        else
            PORTA = mallet ;
            
        // counter to alternate loops
        c++;
    } // main loop
} // main
