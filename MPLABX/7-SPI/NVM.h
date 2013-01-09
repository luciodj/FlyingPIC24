/*
** NVM storage library
** 
** encapsulates 25LC256 Serial EEPROM 
** as a NVM storage device for PIC24 + Explorer16 applications
*/

// initialize access to memory device
void InitNVM(void);

// 16-bit integer read and write functions
// NOTE: address must be an even value between 0x0000 and 0x7ffe
// (see page write restrictions on the device datasheet)
int  iReadNVM ( int address);
void iWriteNVM( int address, int data);
