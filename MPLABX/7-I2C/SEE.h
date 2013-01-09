/*
** SEE Access library
** 
** encapsulates 24LCxx Serial EEPROM 
** as a NVM storage device for PIC32 + Explorer16 applications
*/

// initialize access to memory device
void InitSEE( void);

// 16-bit integer read and write functions
// NOTE: address must be an even value between 0x0000 and 0x7fe
// (see page write restrictions on the device datasheet)
int  iReadSEE ( long address);
void iWriteSEE( long address, int data);
