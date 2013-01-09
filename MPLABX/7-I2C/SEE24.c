/*
** SEE24.c
** 
** 24LCXX I2C serial EEPROM access demo
*/
#include <EX16.h>
#include <i2c.h>
#include <timer.h>
#include <see.h>

#define READ_CMD    1
#define WRITE_CMD   0

#define BUS_FRQ     100000L // 100kHz

void InitSEE( void)
{  // Configure I2C for 7 bit address mode 100kHz

    OpenI2C1(I2C_ON | I2C_IDLE_CON | I2C_7BIT_ADD | I2C_STR_EN
            | I2C_GCALL_DIS | I2C_SM_DIS | I2C_IPMI_DIS,
        (FCY /(2*BUS_FRQ))-1);

    IdleI2C1();

    OpenTimer1( T1_ON | T1_SOURCE_INT | T1_PS_1_256, -1);
    TMR1=0;
    while( TMR1< 100);
    
} //initSEE 
 
 
int AddressSEE( long add)
// send the address selection command
// repeat if SEE busy 
{
    int cmd;
    
    // 1. Form SEE command + address msb (3)
    cmd = 0xA0 | ((add>>7)&0xE);
    
    // 2. WRITE(!) the Address msb
    // try send command and repeat until ACK is received
    while( 1)
    { 
        StartI2C1(); 
        IdleI2C1();
        
        // send command and address msb(3)
        MasterWriteI2C1( cmd+WRITE_CMD); 
        IdleI2C1();
        
        if (I2C1STATbits.ACKSTAT==0)
            break;
            
        StopI2C1();
        IdleI2C1();
    } // while waiting for ACK

    // 3. send address lsb
    MasterWriteI2C1( add); 
    IdleI2C1();

    // 4. exit returning the cmd byte
    return cmd;
} // AddressSEE
    
    
int iReadSEE( long add)
// random access read command sequence
{
    int cmd, r; 
   
    // 1. select address
    cmd = AddressSEE( add);
    
    StopI2C1();
    IdleI2C1();
      
    // 2. read command
    StartI2C1(); IdleI2C1();
    MasterWriteI2C1( cmd+READ_CMD);
    IdleI2C1();

    // 3. stream data in (will continue until NACK is sent)
    r= MasterReadI2C1( );
    
    AckI2C1(); IdleI2C1();      
    r|= (MasterReadI2C1()<<8);

    // 4. terminate read sequence (send NACK then STOP)
    NotAckI2C1(); IdleI2C1();
    StopI2C1(); IdleI2C1();
    
    return r;
} // iReadSEE


void iWriteSEE( long add, int v)
// SEE write command sequence
{
    int cmd; 
    
    // 1. select address
    cmd = AddressSEE( add);
         
    // 2. stream data out 
    MasterWriteI2C1( v&0xFF);  
    IdleI2C1();  

    MasterWriteI2C1( v>>8);
    IdleI2C1();  

    // 3. terminate the command sequence
    StopI2C1(); 
    IdleI2C1();
    
} // iWriteSEE
  
