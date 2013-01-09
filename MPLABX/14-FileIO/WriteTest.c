/*
**  WriteTest.c
**
*/

#include <EX16.h>
#include <config.h>
#include <CONU2.h>
#include <fileio.h>

#define B_SIZE   1024

char data[B_SIZE];

int main( void)
{
    MFILE *fs, *fd;
    unsigned r;

    //initializations
    InitU2();           //115,200 baud 8,n,1
 
    putsU2( "init");
    while( !DetectSD());    // assumes SDCD pin is by default an input
    Delayms( 100);          // wait for card to power up
        
    if ( mount())
    {
        putsU2("mount");
        if ( (fs = fopenM( "source.txt", "r")))
        {
            putsU2("source file opened for reading");
            if ( (fd = fopenM( "dest3.txt", "w")))
            {
                putsU2("destination file opened for writing");
                do{
                    r = freadM( data, B_SIZE, fs);

                    r = fwriteM( data, r, fd);

                    putU2('.');

                } while( r==B_SIZE);

                fcloseM( fd);
                putsU2("destination file closed");
            }
            else 
                putsU2("could not open the destination file");

            fcloseM( fs);
            putsU2("source file closed");
        } 
        else
            putsU2("could not open the source file");

        umount();
        putsU2("umount");

    }
    else 
        putsU2("mount failed");
    
    // main loop
    while( 1);
} // main
