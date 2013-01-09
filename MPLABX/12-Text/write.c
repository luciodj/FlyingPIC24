/*
** write.c
** replaces stdio lib write function
**
** v1.00 LDJ 7/3/06
*/

#include <p24xxxx.h>
#include <text.h>
#include <font.h>

int write(int handle, void *buffer, unsigned int len)
{
    int i;

    switch (handle)
    {
    case 0:
    case 1:
    case 2:
        for (i = len; i; --i)
            putcV( *(char*)buffer);
        break;
    default:
        break;
    }
    return(len);
}

