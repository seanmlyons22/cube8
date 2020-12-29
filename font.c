#include "font.h"
#include <avr/eeprom.h>

volatile const unsigned char font[455] EEMEM = {
    0x00,0x00,0x00,0x00,0x00,0x00,0x5f,0x5f,0x00,0x00,  //  !
    0x00,0x03,0x00,0x03,0x00,0x14,0x7f,0x14,0x7f,0x14,  // "#
    0x24,0x2a,0x7f,0x2a,0x12,0x23,0x13,0x08,0x64,0x62,  // $%
    0x36,0x49,0x55,0x22,0x50,0x00,0x05,0x03,0x00,0x00,  // &'
    0x00,0x1c,0x22,0x41,0x00,0x00,0x41,0x22,0x1c,0x00,  // ()
    0x14,0x08,0x3e,0x08,0x14,0x08,0x08,0x3e,0x08,0x08,  // *+
    0x00,0x50,0x30,0x00,0x00,0x08,0x08,0x08,0x08,0x08,  // ,-
    0x00,0x60,0x60,0x00,0x00,0x20,0x10,0x08,0x04,0x02,  // ./
    0x3e,0x51,0x49,0x45,0x3e,0x00,0x42,0x7f,0x40,0x00,  // 01
    0x42,0x61,0x51,0x49,0x46,0x21,0x41,0x45,0x4b,0x31,  // 23
    0x18,0x14,0x12,0x7f,0x10,0x27,0x45,0x45,0x45,0x39,  // 45
    0x3c,0x4a,0x49,0x49,0x30,0x01,0x71,0x09,0x05,0x03,  // 67
    0x36,0x49,0x49,0x49,0x36,0x06,0x49,0x49,0x29,0x1e,  // 89
    0x00,0x36,0x36,0x00,0x00,0x00,0x56,0x36,0x00,0x00,  // :;
    0x08,0x14,0x22,0x41,0x00,0x14,0x14,0x14,0x14,0x14,  // <=
    0x00,0x41,0x22,0x14,0x08,0x02,0x01,0x51,0x09,0x06,  // >?
    0x32,0x49,0x79,0x41,0x3e,0x7e,0x11,0x11,0x11,0x7e,  // @A
    0x7f,0x49,0x49,0x49,0x36,0x3e,0x41,0x41,0x41,0x22,  // BC
    0x7f,0x41,0x41,0x22,0x1c,0x7f,0x49,0x49,0x49,0x41,  // DE
    0x7f,0x09,0x09,0x09,0x01,0x3e,0x41,0x49,0x49,0x7a,  // FG
    0x7f,0x08,0x08,0x08,0x7f,0x00,0x41,0x7f,0x41,0x00,  // HI
    0x20,0x40,0x41,0x3f,0x01,0x7f,0x08,0x14,0x22,0x41,  // JK
    0x7f,0x40,0x40,0x40,0x40,0x7f,0x02,0x0c,0x02,0x7f,  // LM
    0x7f,0x04,0x08,0x10,0x7f,0x3e,0x41,0x41,0x41,0x3e,  // NO
    0x7f,0x09,0x09,0x09,0x06,0x3e,0x41,0x51,0x21,0x5e,  // PQ
    0x7f,0x09,0x19,0x29,0x46,0x46,0x49,0x49,0x49,0x31,  // RS
    0x01,0x01,0x7f,0x01,0x01,0x3f,0x40,0x40,0x40,0x3f,  // TU
    0x1f,0x20,0x40,0x20,0x1f,0x3f,0x40,0x38,0x40,0x3f,  // VW
    0x63,0x14,0x08,0x14,0x63,0x07,0x08,0x70,0x08,0x07,  // XY
    0x61,0x51,0x49,0x45,0x43,0x00,0x7f,0x41,0x41,0x00,  // Z[
    0x02,0x04,0x08,0x10,0x20,0x00,0x41,0x41,0x7f,0x00,  // \]
    0x04,0x02,0x01,0x02,0x04,0x40,0x40,0x40,0x40,0x40,  // ^_
    0x00,0x01,0x02,0x04,0x00,0x20,0x54,0x54,0x54,0x78,  // `a
    0x7f,0x48,0x44,0x44,0x38,0x38,0x44,0x44,0x44,0x20,  // bc
    0x38,0x44,0x44,0x48,0x7f,0x38,0x54,0x54,0x54,0x18,  // de
    0x08,0x7e,0x09,0x01,0x02,0x0c,0x52,0x52,0x52,0x3e,  // fg
    0x7f,0x08,0x04,0x04,0x78,0x00,0x44,0x7d,0x40,0x00,  // hi
    0x20,0x40,0x44,0x3d,0x00,0x7f,0x10,0x28,0x44,0x00,  // jk
    0x00,0x41,0x7f,0x40,0x00,0x7c,0x04,0x18,0x04,0x78,  // lm
    0x7c,0x08,0x04,0x04,0x78,0x38,0x44,0x44,0x44,0x38,  // no
    0x7c,0x14,0x14,0x14,0x08,0x08,0x14,0x14,0x18,0x7c,  // pq
    0x7c,0x08,0x04,0x04,0x08,0x48,0x54,0x54,0x54,0x20,  // rs
    0x04,0x3f,0x44,0x40,0x20,0x3c,0x40,0x40,0x20,0x7c,  // tu
    0x1c,0x20,0x40,0x20,0x1c,0x3c,0x40,0x30,0x40,0x3c,  // vw
    0x44,0x28,0x10,0x28,0x44,0x0c,0x50,0x50,0x50,0x3c,  // xy
    0x44,0x64,0x54,0x4c,0x44                // z
};


volatile const unsigned char bitmaps[6][8] EEMEM = {
    {0xc3,0xc3,0x00,0x18,0x18,0x81,0xff,0x7e}, // smiley 3 small
    {0x3c,0x42,0x81,0x81,0xc3,0x24,0xa5,0xe7}, // Omega
    {0x00,0x04,0x06,0xff,0xff,0x06,0x04,0x00},  // Arrow
    {0x81,0x42,0x24,0x18,0x18,0x24,0x42,0x81}, // X
    {0xBD,0xA1,0xA1,0xB9,0xA1,0xA1,0xA1,0x00}, // ifi
    {0xEF,0x48,0x4B,0x49,0x4F,0x00,0x00,0x00} // TG
};

const unsigned char paths[44] PROGMEM = {0x07,0x06,0x05,0x04,0x03,0x02,0x01,0x00,0x10,0x20,0x30,0x40,0x50,0x60,0x70,0x71,0x72,0x73,0x74,0x75,0x76,0x77,0x67,0x57,0x47,0x37,0x27,0x17,
0x04,0x03,0x12,0x21,0x30,0x40,0x51,0x62,0x73,0x74,0x65,0x56,0x47,0x37,0x26,0x15}; // circle, len 16, offset 28

void font_getpath (unsigned char path, unsigned char *destination, int length)
{
    int i;
    int offset = 0;
    
    if (path == 1)
        offset=28;
    
    for (i = 0; i < length; i++)
        destination[i] = pgm_read_byte(&paths[i+offset]);
}

void font_getchar (char chr, unsigned char dst[5])
{
    uint8_t i;
    chr -= 32; // our bitmap font starts at ascii char 32.
    
    for (i = 0; i < 5; i++)
        dst[i] = (unsigned char)eeprom_read_byte((uint8_t*)&font[(chr*5)+i]);
}

void font_getbitmap (char bitmap, unsigned char dst[8])
{
    int i;
    
    for (i = 0; i < 8; i++)
        dst[i] = (unsigned char)eeprom_read_byte((uint8_t*)&bitmaps[(uint8_t)bitmap][(uint8_t)i]);
    
}

unsigned char font_getbitmappixel ( char bitmap, char x, char y)
{
    uint8_t tmp = eeprom_read_byte((uint8_t*)&bitmaps[(uint8_t)bitmap][(uint8_t)x]);
    return (tmp >> y) & 0x01;
}




