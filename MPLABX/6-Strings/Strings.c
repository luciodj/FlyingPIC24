/*
** Strings.c
*/
#include <config.h>
#include <string.h>

// 1. variable declarations
const char e[5] = { 'H','E', 'L','L','O'};
const char f[] = "HELLO";
const char a[] = "Learn to fly with the PIC24";
char b[100] = "Initialized";

// 2. main program
main()
{
    TRISA = 0xfe;
    strcpy( b, "MPLAB C Compiler"); // assign new content to b
    PORTA = 1;
} // main
