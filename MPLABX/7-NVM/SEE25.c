/*
** SEE25.c
**
** 25LCXXX SPI Serial EEPROM  Access Library Module
*/
#include <xc.h>
#include <SEE.h>

// I/O definitions for PIC24 + Explorer16 demo board
#define CSEE    _RD12       // select line for Serial EEPROM
#define TCSEE   _TRISD12    // tris control for CSEE pin

// peripheral configurations
#define SPI_MASTER  0x0122  // select 8-bit master mode, CKE=1, CKP=0, 4MHz
#define SPI_ENABLE  0x8000  // enable SPI port, clear status

// 25LC256 Serial EEPROM commands
#define SEE_WRSR    1       // write status register    
#define SEE_WRITE   2       // write command
#define SEE_READ    3       // read command
#define SEE_WDI     4       // write disable
#define SEE_RDSR    5       // read status register
#define SEE_WEN     6       // write enable

void InitSEE(void)
{
    // init the SPI peripheral 
    CSEE = 1;               // de-select the Serial EEPROM
    TCSEE = 0;              // make SSEE pin output
    SPI2CON1 = SPI_MASTER;  // select mode
    SPI2STAT = SPI_ENABLE;  // enable the peripheral

}//InitSEE


// send one byte of data and receive one back at the same time
int WriteSPI2( int data)
{
    SPI2BUF = data;                 // write to buffer for TX
    while( !SPI2STATbits.SPIRBF);   // wait transfer completed
    return SPI2BUF;                 // read the received value
}//WriteSPI2


int ReadSR( void)
{
    // Check the Serial EEPROM status register
    int i;  
    CSEE = 0;               // select the Serial EEPROM
    WriteSPI2( SEE_RDSR);   // send a READ STATUS COMMAND
    i = WriteSPI2( 0);      // send/receive
    CSEE = 1;               // deselect to terminate command
    return i;
} //ReadSR


int iReadSEE( long address)
{ // read a 16-bit value starting at an even address

    int lsb, msb;

    // wait until any work in progress is completed
    while ( ReadSR() & 0x1);    // check the WIP flag
    
    // perform a 16-bit read sequence (two byte sequential read)
    CSEE = 0;                   // select the Serial EEPROM
    WriteSPI2( SEE_READ);       // read command
    WriteSPI2( address>>8);     // address MSB first
    WriteSPI2( address & 0xfe); // address LSB (word aligned)
    msb = WriteSPI2( 0);        // send dummy, read msb
    lsb = WriteSPI2( 0);        // send dummy, read lsb
    CSEE = 1;
    return ( (msb<<8)+ lsb);    
}//iReadSEE


void WriteEnable( void)
{
    // send a Write Enable command
    CSEE = 0;               // select the Serial EEPROM
    WriteSPI2( SEE_WEN);    // write enable command
    CSEE = 1;               // deselect to complete the command
}//WriteEnable   


void iWriteSEE( long address, int data)
{ // write a 16-bit value starting at an even address

    // wait until any work in progress is completed
    while ( ReadSR() & 0x1);    // check the WIP flag
    
    // Set the Write Enable Latch
    WriteEnable();
    
    // perform a 16-bit write sequence (2 byte page write)
    CSEE = 0;                   // select the Serial EEPROM
    WriteSPI2( SEE_WRITE);      // write command
    WriteSPI2( address>>8);     // address MSB first
    WriteSPI2( address & 0xfe); // address LSB (word aligned)
    WriteSPI2( data >>8);       // send msb
    WriteSPI2( data & 0xff);    // send lsb
    CSEE = 1;
}//iWriteSEE


