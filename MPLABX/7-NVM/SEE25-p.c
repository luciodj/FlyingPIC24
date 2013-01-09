/* 
** NVM Access Library
*/

#include <EX16.h>
#include <spi.h>
#include "SEE.h"

// I/O definitions for PIC24 + Explorer16 demo board
#define CSEE    _RD12       // select line for Serial EEPROM
#define TCSEE   _TRISD12    // tris control for CSEE pin

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
    TCSEE = 0;              // make CSEE pin output

// peripheral configurations
    OpenSPI2( SPI_MODE8_ON          // 8-bit mode
            | SPI_CKE_ON            // high to low
            | CLK_POL_ACTIVE_HIGH   // CK idle low
            | MASTER_ENABLE_ON      // master mode
            | PRI_PRESCAL_4_1       // primary prescaler 1:4
            ,                       
              FRAME_ENABLE_OFF      // no framing
            , 
              SPI_ENABLE            // turn module on
            );

}//InitSEE


char WriteSPI( char i)
// send one byte of data and waits until it receives one byte
// back from the SPI2 port
{
    WriteSPI2( i);            // send one byte of data
    while( !DataRdySPI2());   // wait to receive one byte back
    return ReadSPI2();        // return the received value
} // WriteSPI


char ReadSR( void)
{ // Check the Serial EEPROM status register
    int i;  
    CSEE = 0;               // select the Serial EEPROM
    WriteSPI( SEE_RDSR);    // send a READ STATUS COMMAND
    i = WriteSPI( 0);       // send/receive
    CSEE = 1;               // deselect to terminate command
    return i;
} // ReadSR


int iReadSEE( int address)
{ // read a 16-bit value starting at an even address

    int lsb, msb;

    // wait until any work in progress is completed
    while ( ReadSR() & 0x3);    // check the two lsb WEN and WIP
    
    // perform a 16-bit read sequence (two byte sequential read)
    CSEE = 0;               // select the Serial EEPROM
    WriteSPI( SEE_READ);    // read command
    WriteSPI( address>>8);  // address MSB first
    WriteSPI( address & 0xfe);// address LSB (word aligned)
    msb = WriteSPI( 0); // send dummy, read msb
    lsb = WriteSPI( 0); // send dummy, read lsb
    CSEE = 1;
    return ( (msb<<8)+ lsb);    
} // iReadSEE


void WriteEnable( void)
{ // send a Write Enable command
    CSEE = 0;               // select the Serial EEPROM
    WriteSPI( SEE_WEN); // write enable command
    CSEE = 1;               // deselect to complete the command
} // WriteEnable   


void iWriteSEE( int address, int data)
{ // write a 16-bit value starting at an even address

    // wait until any work in progress is completed
    while ( ReadSR() & 0x3);    // check the two lsb WEN and WIP
    
    // Set the Write Enable Latch
    WriteEnable();
    
    // perform a 16-bit write sequence (2 byte page write)
    CSEE = 0;                   // select the Serial EEPROM
    WriteSPI( SEE_WRITE);       // write command
    WriteSPI( address>>8);      // address MSB first
    WriteSPI( address & 0xfe);  // address LSB (word aligned)
    WriteSPI( data >>8);        // send msb
    WriteSPI( data & 0xff); // send lsb
    CSEE = 1;
} // iWriteSEE


