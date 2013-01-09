/*
**  EX16.c
** 
**  History:
**    05/30/08 - Wayne Duquaine, Added initPPS to allow 
**              GB1/GA1 PIMs to be used with the EX16 board 
**    08/06/10 - LDJ, Modified to use the PIC24 peripheral lib
*/
#include <EX16.h>

void InitEX16( void)
{
    // if using a GA1 or GB1 PIM, initialize the PPS module
#if defined(__PIC24FJ256GB110__) || defined(__PIC24FJ256GA110__)
#include <pps.h>
    InitPPS();
#endif

    // prepare Port A for use with LED bar
    LATA = 0;             // all LED off 
    TRISA = 0xFF00;       // all output 

} // InitEX16



#if defined(__PIC24FJ256GB110__) || defined(__PIC24FJ256GA110__)


// GB110,GA110 Errata considerations
#define SPI2_ENSURE_CLOCK_DONE  while(PORTGbits.RG6==1);   


int InitPPS( void)
{
//   Setup Peripheral Pin Select for UART2, SPI1, SPI2,
//   IC1, OC1, OC3, OC4 on PIC24 GB110 and GA110 PIMs
    PPSUnLock;
    
// SPI1
    PPSOutput( PPS_RP15, PPS_SDO1);     // SDO1 =RP15 F8/pin 53
// SDO1 is the only pin we will use 

// SPI2
    PPSInput( PPS_SDI2,  PPS_RP26);     // SDI2 =RP26 G7/pin 11
    PPSOutput( PPS_RP22, PPS_SCK2OUT);  // SCK2 =RP21 G6/pin 10
    PPSOutput( PPS_RP21, PPS_SDO2);     // SDO2 =RP19 G8/pin 12

// UART
    PPSInput( PPS_U2RX,  PPS_RP10);     // U2RX =RP10 F4/pin 49
    PPSInput( PPS_U2CTS, PPS_RPI32);    // U2CTS=RP32 F12/pin40
    PPSOutput( PPS_RP17, PPS_U2TX);     // U2TX =RP17 F5/pin 50
    PPSOutput( PPS_RP31, PPS_U2RTS);    // U2RTS=RP31 F13pin 39

// IC
    PPSInput( PPS_IC1,   PPS_RP2);      // IC1  =RP2  D8/pin 68

// OC
    PPSOutput( PPS_RP19, PPS_OC1);      // OC1  =RP11 D0/pin 72
    PPSOutput( PPS_RP11, PPS_OC2);      // OC2  =RP24 D1/pin 76
    PPSOutput( PPS_RP24, PPS_OC4);      // OC4  =RP22 D3/pin 78

// GB110 PIM pin-remapping to accomodate additional USB pins
// GB110 shares usage of D2/pin 77 between SDI1 and OC3
//      pin 54 SDI1 is remapped to Explorer pin 77/D2 
// NOTE: we will use it only as OC3
//      pin 55 SCK1 is remapped to Explorer pin 25/B0 
// NOTE: pin 55 is input only, connecting it to SCK1
//          restricts usage to "slave mode" only 
//      pin 56 RG3  is remapped to Explorer pin 89/G1
//      pin 57 RG2  is remapped to Explorer pin 90/G0

#ifdef __PIC24FJ256GB110__
    PPSOutput( PPS_RP23, PPS_OC3OUT);   // OC3=RP23 D2/pin 77 
#endif

    // Done, lock the PPS configuration 
    PPSLock;
            
    return 0;
} // InitPPS
#endif


void Delayms( unsigned t)
{
    T1CON = 0x8000;     // enable tmr1, Tcy, 1:1
    while (t--)         // wait for t (msec) 
    {
        TMR1 = 0;       
        while ( TMR1 < (FCY/1000)); // wait 1ms
    }
} // Delayms


int ReadKEY( void)
{   // returns 0.F if key pressed, 0 = none
    int c = 0;

	_TRISA7 = 1;// ensure RA7 input
    if ( !_RD6) // leftmost button 
        c |= 8;
    if ( !_RD7)
        c |= 4;
    if ( !_RA7) 
        c |= 2;
    if ( !_RD13) // rightmost button
        c |= 1;

    return c;
} // ReadKEY


int GetKEY( void)
{   // wait for a key pressed and debounce
    int i=0, r=0, j=0;
    int c;

    // wait for a key pressed for at least .1sec
    do{
        Delayms( 10);
        if ( (c = ReadKEY()))
        {
            if ( c>r)       // if more than one button pressed
                r = c;      // take the new code
            i++;    
        }
        else 
            i=0;
    } while ( i<10);

    // wait for key released for at least .1 sec
    i =0;
    do {
        Delayms( 10);   
        if ( (c = ReadKEY()))
        {
            if (c>r)        // if more then one button pressed 
                r = c;      // take the new code
            i=0;            
            j++;            // keep counting to detect long button hold
        }
        else 
            i++;
    } while ( i<10);        
    
    // check if a button was pushed longer than 500ms
    if ( j>80) 
        r+=0x80;

    return r;
} // GetKEY


// initialize the ADC, select Analog input pins
void InitADC( int amask) 
{
    AD1PCFG = amask;    // select analog input pins
    AD1CON1 = 0x00E0;   // auto convert after end of sampling 
    AD1CSSL = 0;        // no scanning required 
    AD1CON3 = 0x1F3F;   // max sample time = 31Tad, Tad = 2 x Tcy 
    AD1CON2 = 0;        // use MUXA, AVss and AVdd are used as Vref+/-
    AD1CON1bits.ADON = 1; // turn on the ADC

    // Explorer 16 Development Board Errata (work around 2)
    // RB15 should always be a digital output
    _LATB15 = 0;
    _TRISB15 = 0;
} // InitADC


// sample/convert one analog input
int ReadADC( int ch)
{
    AD1CHS  = ch;               // select analog input channel
    AD1CON1bits.SAMP = 1;       // start sampling, automatic conversion will follow
    while (!AD1CON1bits.DONE);   // wait to complete the conversion
    return ADC1BUF0;            // read the conversion result
} // readADC

