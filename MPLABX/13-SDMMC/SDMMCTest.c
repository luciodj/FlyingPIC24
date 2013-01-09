/*
**  SDMMCTest.c
**
**  Read/write Test
*/
#include <config.h>
#include <EX16.h>
#include <SDMMC.h>

#define START_ADDRESS       10000   // start block address
#define N_BLOCKS            10000   // number of blocks
#define B_SIZE              512     // sector/data block size

unsigned char    data[ B_SIZE];
unsigned char  buffer[ B_SIZE];

main( void)
{
    LBA addr;
    int i, r;

    // I/O initializations
    TRISA=0;    // initialize PORTA LED outputs
    InitSD();   // initialize I/Os for the SD/MMC card

    // fill the buffer with "data"
    for( i=0; i<B_SIZE; i++)
        data[i]= i;
 
    // wait for card to be inserted
    while( !DetectSD())    // assumes SDCD pin is by default an input
        Delayms( 100);     // wait for card contacts de-bounce and power up
        
    // initialize the memory card (returns 0 if successful)
    r = InitMedia();
    if ( r)                 // could not initialize the card
    {
        PORTA = r;          // show error code on LEDs
        while( 1);          // halt here
    }
    else
    {
        // fill N_BLOCK blocks/SECOTR with the contents of data buffer
        addr = START_ADDRESS;
        for( i=0; i<N_BLOCKS; i++)
            if (!WriteSECTOR( addr+i, data))
            {   // writing failed
                PORTA = 0x0f;
                while( 1);  // halt here
            }

        // verify the contents of each block/SECTOR written
        addr = START_ADDRESS;
        for( i=0; i<N_BLOCKS; i++)
        {   // read back one block at a time
            if (!ReadSECTOR( addr+i, buffer))
            {   // reading failed
                PORTA = 0xf0;
                while( 1);  // halt here
            }
            
            // verify each block content
            if ( memcmp( data, buffer, B_SIZE))
            {   // mismatch
                PORTA = 0x55;
                while( 1); // halt here
            }
        } // for each block
    } // else media initialized

    // indicate successful execution
    PORTA = 0xFF;
    // main loop
    while( 1);

} // main

