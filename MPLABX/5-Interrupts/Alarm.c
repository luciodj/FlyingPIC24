/*
** RTCC Alarm demo
**
*/
#include <config.h>

void InitRTCC( void)
{   
    // unlock and enable SOSC
    __builtin_write_OSCCONL( 2);    
 
    // unlock RCFGCAL, set RTCWREN
    __builtin_write_RTCWEN();    

    _RTCEN = 0;         // disable the clock

    // set 12/01/2006 WED 12:01:30
    _RTCPTR = 3;        // start the sequence
    RTCVAL = 0x2006;    // YEAR
    RTCVAL = 0x1100;    // MONTH-1/DAY-1
    RTCVAL = 0x0312;    // WEEKDAY/HOURS
    RTCVAL = 0x0130;    // MINUTES/SECONDS
    
    // optional calibration
    //_CAL = 0x00;      

    // lock and enable 
    _RTCEN = 1;         // start the clock
    _RTCWREN = 0;       // lock 

} // InitRTCC


void SetALARM( void)
{
    // disable alarm
    _ALRMEN = 0;

    // set the ALARM for a specific day of the year (my birthday)
    _ALRMPTR = 2;       // start the sequence
    ALRMVAL = 0x1124;   // MONTH-1/DAY-1
    ALRMVAL = 0x0006;   // WEEKDAY/HOUR
    ALRMVAL = 0x0000;   // MINUTES/SECONDS

    // set the repeat counter
    _ARPT = 0;          // once
    _CHIME = 1;         // no reload

    // set the alarm mask 
//    _AMASK = 0b1001;    // once a year
//    _AMASK = 0b0010;    // every 10 seconds
    _AMASK = 0b0001;    // every second
    _ALRMEN = 1;        // enable alarm

    _RTCIF = 0;         // clear flag

    _RTCIE = 1;         // enable interrupt

} // Set ALARM


void _ISR _RTCCInterrupt( void)
{
    // will call this routine once every four years on Feb29th!
    // your code here
    // ...
    _RA0 = 1- _RA0; // toggle LED0

    _RTCIF = 0;     // clear flag, see ya in four...

} // RTCC interrupt service routine


main()
{
    // initialization
    TRISA = 0xff00;
    InitRTCC();
    SetALARM();

    while( 1)   // main loop 
    {
        // wait here
    } // main loop

} // main
