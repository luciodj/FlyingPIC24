/*
**  ReadTest.c
**
*/
#include <config.h>
#include <EX16.h>
#include <fileio.h>
#include <CONU2.h>

#define B_SIZE  10
char data[ B_SIZE];

int main( void)
{
    MFILE *fs;
    unsigned r;

    //initializations
    InitU2();               //115,200 baud 8,n,1
 
    putsU2( "init");
    while( !DetectSD());    // assumes SDCD pin is by default an input
    Delayms( 100);          // wait for card to power up
        
    putsU2("media detected");

    if ( mount())
    {
        putsU2( "mount");
        if ( (fs = fopenM( "source.txt", "r")))
        {
            putsU2("file opened");
            do{
                r = freadM( data, B_SIZE, fs);
//                for( i=0; i<r; i++)
//                    putU2( data[i]);
            } while( r==B_SIZE);
            fcloseM( fs);
            putsU2("file closed");
        } 
        else
            putsU2("could not open file");

        umount();
        putsU2("media unmounted");        
    }
    
    // main loop
    while( 1);
} // main
