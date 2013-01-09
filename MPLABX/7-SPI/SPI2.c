/*
** SPI2
*/
#include <config.h>

// I/O definitions
#define CSEE    _RD12       // select line for Serial EEPROM
#define TCSEE   _TRISD12    // tris control for CSEE pin

// peripheral configurations
#define SPI_MASTER  0x0120  // select 8-bit master mode, CKE=1, CKP =0
#define SPI_ENABLE  0x8000  // enable SPI port, clear status

// 25LC256 Serial EEPROM commands
#define SEE_WRSR    1       // write status register    
#define SEE_WRITE   2       // write command
#define SEE_READ    3       // read command
#define SEE_WDI     4       // write disable
#define SEE_STAT    5       // read status register
#define SEE_WEN     6       // write enable


// send one byte of data and receive one back at the same time
int WriteSPI2( int data)
{
    SPI2BUF = data;                 // write to buffer for TX
    while( !SPI2STATbits.SPIRBF);   // wait transfer completion
    return SPI2BUF;                 // read the received value
} // WriteSPI2


main()
{
    int i;
    
    // 1. init the SPI peripheral 
    TCSEE = 0;              // make SSEE pin output
    CSEE = 1;               // de-select the Serial EEPROM
    SPI2CON1 = SPI_MASTER;  // select mode
    SPI2STAT = SPI_ENABLE;  // enable the peripheral

    // 2. main loop
    while( 1)
    {   
        // 2.1 send a Write Enable command
        CSEE = 0;               // select the Serial EEPROM
        WriteSPI2( SEE_WEN);    // write enable command
        CSEE = 1;               // deselect, terminate command
        
        // 2.2 Check the Serial EEPROM status 
        CSEE = 0;               // select the Serial EEPROM
        WriteSPI2( SEE_STAT);   // send a READ STATUS COMMAND
        i = WriteSPI2( 0);      // send/receive
        CSEE = 1;               // deselect, terminate command
    } // main loop
    
} // main
    
