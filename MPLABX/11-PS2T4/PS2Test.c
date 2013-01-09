/* 
** PS2 KBD Test
*/
#include <config.h>
#include <PS2.h>

main()
{
    InitKBD();                  // init state machine
    LATA = 0;
    TRISA = 0;                  // PORTA LED outputs

    while ( 1)
    {
        if ( KBDReady)          // wait for the flag 
        {
            PORTA = KBDCode;    // fetch the key code 
            KBDReady = 0;       // clear the flag 
        }
    } // main loop
} //main
