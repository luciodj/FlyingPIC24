/*
** writeLCD.c
** replaces stdio lib write function
**
** v1.00 LDJ 7/30/06
*/
#include <p24fxxxx.h>
#include <stdio.h>
#include <LCD.h>

int write(int handle, void *buffer, unsigned int len)
{
    int i, *p;
    const char *pf;

    switch (handle)
    {
    case 0:
    case 1:
    case 2:
        for (i = len; i; --i)
            putLCD( *(char*)buffer++);
        break;
    default:
        break;
    }
    return(len);
}

