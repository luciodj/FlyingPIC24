/*
** 8 x 8 Font
**
** LDJ v1.3 6/2/06
*/
#define F_OFFS  0x20    // initial offset
#define F_SIZE  0x60    // only the first 96 characters defined

const char Font8x8[] = {
// 20 - SPACE
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
// 1 - !
    0b00011000,
    0b00011000,
    0b00011000,
    0b00011000,
    0b00011000,
    0b00000000,
    0b00011000,
    0b00000000,
// 2 - "
    0b00110110,
    0b00100100,
    0b01001000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
// 3 - #
    0b00000000,
    0b00010010,
    0b01111111,
    0b00010100,
    0b01111111,
    0b00010100,
    0b00100100,
    0b00000000,
// 4 - $
    0b00001000,
    0b00111100,
    0b01001000,
    0b00111110,
    0b00001001,
    0b01001001,
    0b00111110,
    0b00001000,
// 5 - %
    0b00010000,
    0b00101001,
    0b00010010,
    0b00000100,
    0b00001010,
    0b00010101,
    0b00100010,
    0b00000000,
// 6 - &
    0b00000000,
    0b00001110,
    0b00010000,
    0b00110000,
    0b01001010,
    0b01000100,
    0b00111011,
    0b00000000,
// 7 - '
    0b00011000,
    0b00010000,
    0b00010000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
// 8 - (
    0b00001000,
    0b00010000,
    0b00100000,
    0b00100000,
    0b00100000,
    0b00010000,
    0b00001000,
    0b00000000,
// 9 - )
    0b00010000,
    0b00001000,
    0b00000100,
    0b00000100,
    0b00000100,
    0b00001000,
    0b00010000,
    0b00000000,
// A - *
    0b00000000,
    0b00000000,
    0b00010000,
    0b01111100,
    0b00010000,
    0b00101000,
    0b00000000,
    0b00000000,
// B - +
    0b00000000,
    0b00011000,
    0b00011000,
    0b01111110,
    0b00011000,
    0b00011000,
    0b00000000,
    0b00000000,
// C - ,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00110000,
    0b00110000,
    0b01000000,
    0b00000000,
// D - -
    0b00000000,
    0b00000000,
    0b00000000,
    0b01111110,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
// E - .
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00011000,
    0b00011000,
    0b00000000,
// F - /
    0b00000011,
    0b00000110,
    0b00001100,
    0b00011000,
    0b00010000,
    0b00110000,
    0b01100000,
    0b00000000,

// 30 - 0
    0b00111110,
    0b01100001,
    0b01100001,
    0b01100001,
    0b01100001,
    0b01100001,
    0b00111110,
    0b00000000,
// 1
    0b00011000,
    0b00111000,
    0b00011000,
    0b00011000,
    0b00011000,
    0b00011000,
    0b00111100,
    0b00000000,
// 2
    0b00111110,
    0b01000001,
    0b01000011,
    0b00000100,
    0b00001000,
    0b00010001,
    0b01111111,
    0b00000000,
// 3
    0b00111110,
    0b01000001,
    0b00000001,
    0b00001110,
    0b00000001,
    0b01000001,
    0b00111110,
    0b00000000,

// 4
    0b01100000,
    0b01100000,
    0b01100000,
    0b01101000,
    0b01111111,
    0b00001000,
    0b00001000,
    0b00000000,
// 5
    0b01111111,
    0b01100001,
    0b01100000,
    0b01111110,
    0b00000001,
    0b01000001,
    0b00111110,
    0b00000000,
// 6
    0b00111110,
    0b01100001,
    0b01100000,
    0b01111110,
    0b01100001,
    0b01100001,
    0b00111110,
    0b00000000,
// 7
    0b01111111,
    0b01000110,
    0b00000110,
    0b00001100,
    0b00011000,
    0b00110000,
    0b00110000,
    0b00000000,

// 8
    0b00111110,
    0b01100001,
    0b01100001,
    0b00111110,
    0b01100001,
    0b01100001,
    0b00111110,
    0b00000000,
// 9
    0b00111110,
    0b01100001,
    0b01100001,
    0b00111111,
    0b00000010,
    0b00000100,
    0b00111000,
    0b00000000,
// A - :
    0b00000000,
    0b00000000,
    0b00110000,
    0b00110000,
    0b00000000,
    0b00110000,
    0b00110000,
    0b00000000,
// B - ;
    0b00000000,
    0b00000000,
    0b00110000,
    0b00110000,
    0b00000000,
    0b00110000,
    0b01100000,
    0b00000000,

// C - <
    0b00000000,
    0b00000000,
    0b00011000,
    0b00100000,
    0b01000000,
    0b00100000,
    0b00011000,
    0b00000000,
// D - =
    0b00000000,
    0b00000000,
    0b01111111,
    0b00000000,
    0b01111111,
    0b00000000,
    0b00000000,
    0b00000000,
// E - >
    0b00000000,
    0b00000000,
    0b00110000,
    0b00001000,
    0b00000100,
    0b00001000,
    0b00110000,
    0b00000000,
// F - ?
    0b00111110,
    0b01000001,
    0b00000010,
    0b00000100,
    0b00011000,
    0b00000000,
    0b00011000,
    0b00000000,

// 40 - @
    0b00111110,
    0b01000001,
    0b01001101,
    0b01010001,
    0b01001110,
    0b01000001,
    0b00111110,
    0b00000000,
// 1 - A
    0b00011100,
    0b00110010,
    0b01100001,
    0b01100001,
    0b01111111,
    0b01100001,
    0b01100001,
    0b00000000,
// 2 - B
    0b01111110,
    0b01100001,
    0b01100001,
    0b01111110,
    0b01100001,
    0b01100001,
    0b01111110,
    0b00000000,
// 3 - C
    0b00011110,
    0b01100001,
    0b01100000,
    0b01100000,
    0b01100000,
    0b01100001,
    0b00111110,
    0b00000000,

// 4 - D
    0b01111100,
    0b01100010,
    0b01100001,
    0b01100001,
    0b01100001,
    0b01100010,
    0b01111100,
    0b00000000,
// 5 - E
    0b01111111,
    0b01100001,
    0b01100000,
    0b01111100,
    0b01100000,
    0b01100001,
    0b01111111,
    0b00000000,
// 6 - F
    0b01111111,
    0b01100001,
    0b01100000,
    0b01111100,
    0b01100000,
    0b01100000,
    0b01100000,
    0b00000000,
// 7 - G
    0b00011110,
    0b01100001,
    0b01100000,
    0b01100000,
    0b01100111,
    0b01100001,
    0b00111110,
    0b00000000,

// 8 - H
    0b01100001,
    0b01100001,
    0b01100001,
    0b01111111,
    0b01100001,
    0b01100001,
    0b01100001,
    0b00000000,
// 9 - I
    0b00111100,
    0b00011000,
    0b00011000,
    0b00011000,
    0b00011000,
    0b00011000,
    0b00111100,
    0b00000000,
// A - J
    0b00011110,
    0b00001100,
    0b00001100,
    0b00001100,
    0b00001100,
    0b01001100,
    0b00111000,
    0b00000000,
// B - K
    0b01100011,
    0b01100010,
    0b01100100,
    0b01111000,
    0b01100100,
    0b01100010,
    0b01100011,
    0b00000000,
// C - L
    0b01110000,
    0b01100000,
    0b01100000,
    0b01100000,
    0b01100000,
    0b01100001,
    0b01111111,
    0b00000000,
// D - M
    0b01100001,
    0b01100011,
    0b01110101,
    0b01101001,
    0b01100001,
    0b01100001,
    0b01100011,
    0b00000000,
// E - N
    0b01100011,
    0b01110001,
    0b01101001,
    0b01101001,
    0b01100101,
    0b01100011,
    0b01100001,
    0b00000000,
// F - O
    0b00011110,
    0b00100001,
    0b01100001,
    0b01100001,
    0b01100001,
    0b01100001,
    0b00111110,
    0b00000000,

// 50 - P
    0b01111110,
    0b01100001,
    0b01100001,
    0b01111110,
    0b01100000,
    0b01100000,
    0b01100000,
    0b00000000,
// 1 - Q
    0b00011110,
    0b00100001,
    0b01100001,
    0b01100001,
    0b01100001,
    0b01100010,
    0b00111111,
    0b00000000,
// 2 - R
    0b01111110,
    0b01100001,
    0b01100001,
    0b01111110,
    0b01101000,
    0b01100100,
    0b01100011,
    0b00000000,
// 3 - S
    0b00111110,
    0b01000001,
    0b01000000,
    0b00111110,
    0b00000001,
    0b01000001,
    0b01111110,
    0b00000000,
// 4 - T
    0b01111111,
    0b01011001,
    0b00011000,
    0b00011000,
    0b00011000,
    0b00011000,
    0b00111100,
    0b00000000,
// 5 - U
    0b01100011,
    0b01100001,
    0b01100001,
    0b01100001,
    0b01100001,
    0b01100001,
    0b00111110,
    0b00000000,
// 6 - V
    0b01100011,
    0b01100001,
    0b01100001,
    0b00110001,
    0b00110010,
    0b00011100,
    0b00011000,
    0b00000000,
// 7 - W
    0b01100011,
    0b01100001,
    0b01100001,
    0b01101001,
    0b01101001,
    0b00101010,
    0b00010100,
    0b00000000,

// 8 - X
    0b01100011,
    0b00100010,
    0b00010100,
    0b00001000,
    0b00001000,
    0b00010100,
    0b01100011,
    0b00000000,
// 9 - Y
    0b01100011,
    0b00100010,
    0b00010100,
    0b00001000,
    0b00001000,
    0b00001000,
    0b00011100,
    0b00000000,
// A - Z
    0b01111110,
    0b01000100,
    0b00001000,
    0b00010100,
    0b00011000,
    0b00100010,
    0b01111110,
    0b00000000,
// B - [
    0b00000000,
    0b01111000,
    0b01100000,
    0b01100000,
    0b01100000,
    0b01100000,
    0b01111000,
    0b00000000,
// C - backslash
    0b01000000,
    0b01100000,
    0b00110000,
    0b00011000,
    0b00001100,
    0b00000100,
    0b00000110,
    0b00000000,
// D - ]
    0b00011110,
    0b00000110,
    0b00000110,
    0b00000110,
    0b00000110,
    0b00000110,
    0b00011110,
    0b00000000,
// E - ^
    0b00001000,
    0b00010100,
    0b00100010,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
// F - _
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b01111111,

// 60 - `
    0b00110000,
    0b00011000,
    0b00000100,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
// 1 - a
    0b00000000,
    0b01111100,
    0b00000010,
    0b00111111,
    0b01000001,
    0b01000011,
    0b00111101,
    0b00000000,
// 2 - b
    0b01000000,
    0b01000000,
    0b01000000,
    0b01111110,
    0b01000001,
    0b01000001,
    0b01011110,
    0b00000000,
// 3 - c
    0b00000000,
    0b00000000,
    0b00111110,
    0b01000000,
    0b01000000,
    0b01000000,
    0b00111110,
    0b00000000,

// 4 - d
    0b00000001,
    0b00000001,
    0b00111111,
    0b01000001,
    0b01000001,
    0b01000001,
    0b00111101,
    0b00000000,
// 5 - e
    0b00000000,
    0b00111110,
    0b01000001,
    0b01000001,
    0b01111110,
    0b01000000,
    0b00111110,
    0b00000000,
// 6 - f
    0b00111100,
    0b01000000,
    0b01000000,
    0b01111000,
    0b01000000,
    0b01000000,
    0b01000000,
    0b00000000,
// 7 - g
    0b00000000,
    0b00111110,
    0b01000001,
    0b01000001,
    0b00111111,
    0b00000001,
    0b00111110,
    0b00000000,

// 8 - h
    0b01000000,
    0b01000000,
    0b01011100,
    0b01100010,
    0b01000001,
    0b01000001,
    0b01000001,
    0b00000000,
// 9 - i
    0b00000000,
    0b00001000,
    0b00000000,
    0b00011000,
    0b00001000,
    0b00001000,
    0b00011100,
    0b00000000,
// A - j
    0b00000000,
    0b00000100,
    0b00000000,
    0b00001100,
    0b00000100,
    0b00000100,
    0b00000100,
    0b00111000,
// B - k
    0b00100000,
    0b00100110,
    0b00101000,
    0b00110000,
    0b00101000,
    0b00100100,
    0b01110011,
    0b00000000,
// C - l
    0b00110000,
    0b00010000,
    0b00010000,
    0b00010000,
    0b00010000,
    0b00010000,
    0b00111000,
    0b00000000,
// D - m
    0b00000000,
    0b00000000,
    0b01110110,
    0b01001001,
    0b01001001,
    0b01001001,
    0b01001001,
    0b00000000,
// E - n
    0b00000000,
    0b00000000,
    0b01101100,
    0b00100010,
    0b00100010,
    0b00100010,
    0b01100110,
    0b00000000,
// 4F - o
    0b00000000,
    0b00000000,
    0b00111110,
    0b01000001,
    0b01000001,
    0b01000001,
    0b00111110,
    0b00000000,
// 0 - p
    0b00000000,
    0b00000000,
    0b01101110,
    0b00110001,
    0b00100001,
    0b00100001,
    0b00111110,
    0b01110000,
// 1 - q
    0b00000000,
    0b00000000,
    0b00111011,
    0b01000100,
    0b01000100,
    0b01000100,
    0b00111100,
    0b00001110,
// 2 - r
    0b00000000,
    0b00000000,
    0b01011110,
    0b00100000,
    0b00100000,
    0b00100000,
    0b00111000,
    0b00000000,
// 3 - s
    0b00000000,
    0b00000000,
    0b00011111,
    0b00100000,
    0b00011110,
    0b00000001,
    0b00111110,
    0b00000000,
// 4 - t
    0b00010000,
    0b00111100,
    0b00010000,
    0b00010000,
    0b00010000,
    0b00010001,
    0b00001110,
    0b00000000,
// 5 - u
    0b00000000,
    0b00000000,
    0b00100010,
    0b00100010,
    0b00100010,
    0b00100010,
    0b00011101,
    0b00000000,
// 6 - v
    0b00000000,
    0b00000000,
    0b01100001,
    0b00100001,
    0b00100010,
    0b00010100,
    0b00001000,
    0b00000000,
// 7 - w
    0b00000000,
    0b00000000,
    0b01100011,
    0b01000010,
    0b01010010,
    0b01010100,
    0b00101000,
    0b00000000,
// 8 - x
    0b00000000,
    0b00000000,
    0b01100110,
    0b00011000,
    0b00010000,
    0b00101000,
    0b01000110,
    0b00000000,
// 9 - y
    0b00000000,
    0b00000000,
    0b01100011,
    0b00010100,
    0b00001000,
    0b00001000,
    0b00011000,
    0b00000000,
// A - z
    0b00000000,
    0b00000000,
    0b00111111,
    0b00100010,
    0b00001100,
    0b00011001,
    0b00111111,
    0b00000000,
// B - {
    0b00000100,
    0b00001000,
    0b00001000,
    0b00011000,
    0b00001000,
    0b00001000,
    0b00000100,
    0b00000000,
// C - |
    0b00010000,
    0b00010000,
    0b00010000,
    0b00010000,
    0b00010000,
    0b00010000,
    0b00010000,
    0b00010000,
// D - }
    0b00010000,
    0b00001000,
    0b00001000,
    0b00001100,
    0b00001000,
    0b00001000,
    0b00010000,
    0b00000000,
// E - ~
    0b00000000,
    0b00000000,
    0b00110000,
    0b01001001,
    0b00000110,
    0b00000000,
    0b00000000,
    0b00000000,
// F - DEL
    0b11111111,
    0b10000001,
    0b10000001,
    0b10000001,
    0b10000001,
    0b10000001,
    0b10000001,
    0b11111111 
};
    
    
