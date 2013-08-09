/*
** config.h
** 
** "Flying PIC24" projects device configuration
*/
#include <xc.h>

// this is the default configuration for all book's projects 
_CONFIG1( JTAGEN_OFF        // disable JTAG interface
        & GCP_OFF           // disable general code protection
        & GWRP_OFF          // disable flash write protection
        & ICS_PGx2          // ICSP interface (2=default)
        & FWDTEN_OFF)       // disable watchdog timer

#if defined ( __PIC24FJ128GA010__ ) || defined (__PIC24FJ256GA110__)
_CONFIG2( IESO_OFF          // two speed start up disabled
        & FCKSM_CSDCMD      // disable clock-swithcing/monitor
        & FNOSC_PRIPLL      // primary oscillator: enable PLL 
        & POSCMOD_XT)       // primary oscillator: XT mode

#else   // GB1 configuration requires additional detail

_CONFIG2( PLL_96MHZ_ON      // enable USB PLL module
        & PLLDIV_DIV2       // 8MHz/2 = 4Mhz input to USB PLL
        & IESO_OFF          // two speed start up disabled
        & FCKSM_CSDCMD      // disable clock-swithcing/monitor
        & FNOSC_PRIPLL      // primary oscillator: enable PLL 
        & POSCMOD_XT)       // primary oscillator: XT mode
#endif

