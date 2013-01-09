/*
** Temp.c
** Converting the analog signal from a TC1047 Temperature Sensor
*/
#include <EX16.h>
#include <config.h>

#define TEMP_CH   4         // ch 4 = TC1047 Temperature sensor 
#define TEMPMASK  0xffef    // AN4 as analog input

main ()
{
    int temp, ref, pos, j;
    
    // 1. initializations
    InitADC( TEMPMASK);  // initialize ADC Explorer16 inputs
    TRISA = 0xff00;      // select PORTA pins as outputs


    // 2. get the central bar reference
    temp = 0;
    for ( j= 16; j >0; j--)
         temp += ReadADC( TEMP_CH);  // read the temperature
    ref = temp >> 4;

    // 3.0 main loop
    while( 1)
    {
        // 3.1 get a new measurement
        temp = 0;
        for ( j= 16; j >0; j--)
        {
            temp += ReadADC( TEMP_CH);  // read the temperature
        }
        temp >>= 4;                     // averaged over 16 values
        Delayms( 500);               // 1/2 second

        // 3.2 compare with initial reading, move bar 1 dot/C
        pos = 3 + (temp - ref);

        // 3.3 keep result in value range 0..7, keep bar visible
        if ( pos > 7)
            pos = 7;
        if ( pos < 0)
            pos = 0;

        // 3.4 turn on the corresponding LED
        PORTA = ( 0x80 >> pos);
    } // main loop
} // main
