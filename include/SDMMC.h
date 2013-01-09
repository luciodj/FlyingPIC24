/*
** SDMMC.h
**
** SDMMC card interface  
**
*/

#ifndef _SDMMC
#define _SDMMC

#define FALSE   0
#define TRUE    !FALSE
#define FAIL    0

// IO definitions
#define SD_LED                      _RA0
#define READ_LED                    _RA1
#define WRITE_LED                   _RA2


typedef unsigned long LBA; // logic block address, 32 bit wide


void InitSD( void);     // initializes the I/O pins for the SD/MMC interface 
int InitMedia( void);   // initializes the SD/MMC memory device

int DetectSD( void);    // detects the card presence 
int DetectWP( void);    // detects the position of the write protect switch

int ReadSECTOR ( LBA, unsigned char *);  // reads a block of data
int WriteSECTOR( LBA, unsigned char *);  // writes a block of data

#endif

