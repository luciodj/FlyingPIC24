/*
** RTCC Alarm demo
**
** this version uses the PIC24F peripheral libraries 
*/
#include <config.h>
#include <rtcc.h>
 
void InitRTCC( void)
{   
    RtccInitClock();
    RtccWrOn();         // unlock and enable writing to RTCC 

    // set 12/01/2006 WED 12:01:30
    {
        rtccTimeDate TD = { 0x06, 0x20, // year
                            0x01, 0x11, // day, month
                            0x12, 0x03, // hour, weekday
                            0x30, 0x01};// sec, min
        RtccWriteTimeDate( &TD, FALSE);
    }

    mRtccOn();            // enables RTCC and locks
} // InitRTCC


void SetALARM( void)
{
    mRtccAlrmDisable();

    // set the ALARM for a specific day of the year (my birthday)
    rtccTimeDate ATD = { 0x00, 0x00, // any year
                        0x25, 0x12, // day, month
                        0x06, 0x00, // hour, weekday
                        0x00, 0x00};// sec, min
   RtccWriteAlrmTimeDate(  &ATD);

    // set the repeat counter
    _ARPT = 0;          // once
    _CHIME = 1;         // no reload

// 
    // set the alarm mask 
    _ALRMEN = 1;        // enable alarm
    RtccSetAlarmRpt( RTCC_RPT_SEC, TRUE);

    mRtcc_Clear_Intr_Status_Bit;
    mRtccSetInt( TRUE);

} // Set ALARM


void _ISR _RTCCInterrupt( void)
{
    // will call this routine every second
    //  every day, every month or once a year 
    //  or once in four years on Feb29th!
    //  depending on the AlarmRpt setting
    // ...
    _RA0 = 1- _RA0; // toggle LED0

    mRtcc_Clear_Intr_Status_Bit;

} // RTCC interrupt service routine


main()
{
    // initialization
    TRISA = 0xff80;
    InitRTCC();
    SetALARM();

    while( 1)   // main loop 
    {
        // wait here
    } // main loop

} // main
