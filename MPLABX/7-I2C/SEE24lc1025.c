/*
** SEE24LC1025.c
**
** 24LCXXX I2C serial EEPROM access demo
**
** modified to support 24LC1025 example
*/
#include <config.h>
//#include <EX16.h>
#include <see.h>

#define BUS_FRQ     100000L // 100kHz

void initSEE( void)
// fcy = processor operating frequency in Hz (system clock)
{  // Configure I2C for 7 bit address mode 100kHz

    OpenI2C1(I2C_ON & I2C_IDLE_CON & I2C_7BIT_ADD & I2C_STR_EN
            & I2C_GCALL_DIS & I2C_SM_DIS & I2C_IPMI_DIS, 
        ( FCY /(2*BUS_FRQ))-1);

    IdleI2C1();

    OpenTimer1( T1_ON | T1_SOURCE_INT | T1_PS_1_256, -1);
    TMR1=0;
    while( TMR1< 100);
    
} //initSEE 
 
 
int addressSEE( long add)
// send the address selection command
// repeat if SEE busy 
{
    long cmd;
  
    // 1. form block address and SEE read command
    cmd = (add>>16) & 1;        // extract A16
    cmd <<= 2;                  // move it to b0 position
    cmd |= 0x50;                // select SEE device
    cmd <<= 1;                  // make room for READ bit
        
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


    // 3. send address MSB, bit 8-15
    MasterWriteI2C1( add>>8); 
    IdleI2C1();


    // 3. send address LSB, bit 0-7
    MasterWriteI2C1( add); 
    IdleI2C1();

    // 4. exit returning the cmd byte
    return cmd;
} // addressSEE
    
    
int readSEE( long add)
// random access read command sequence
{
    int cmd, r; 
   
    // 1. select address
    cmd = addressSEE( add);
    
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
} //readSEE  


void writeSEE( long add, int v)
// SEE write command sequence
{
    int cmd; 
    
    // 1. select address
    cmd = addressSEE( add);
         
    // 2. stream data out 
    MasterWriteI2C1( v&0xFF);  
    IdleI2C1();  

    MasterWriteI2C1( v>>8);
    IdleI2C1();  

    // 3. terminate the command sequence
    StopI2C1(); 
    IdleI2C1();
    
} //writeSEE   
  

long i, r;
  
main (void )
{
    
    initSEE(); 
    
    // test filling all 128k bytes == 64k 16-bit integers
    for( i=0; i<64*1024L; i++)
    {
        writeSEE( i<<1, i);
        r = readSEE( i<<1);
        if (r!=i) 
           break;
    }    

    // main loop
    while( 1)
    {
        asm( "nop");
        asm( "nop");
        asm( "nop");
    }    
}
