#include <stdint.h>
#include <LED-Matrix.h>

/*
 * Expand a 12*8 + 6*2*4 glyph into a zero padded 12*16 bitmap
 * The top 8 pixels of each row are stored in a byte array
 * The bottom 4 pixels of each row are stored in a nibble array following the byte array
 */
void ExpandGlyph(const uint8_t glyph[18], uint16_t *bitmap)
{
    for (uint8_t col=0; col<6; col++) {
        uint8_t column= col<<1;      // display column
        uint8_t lsn= glyph[12+col];  // pointer to lower nibble of column data
        uint16_t c0= (glyph[column]<<8) + (lsn & 0xF0);
        uint16_t c1= (glyph[column+1]<<8) + ((lsn << 4) & 0xF0);
        *bitmap++= c0;
        *bitmap++= c1;
    }
}

/*
 * Send a 12*8 + 6*2*4 glyph to the HT1632C LED driver
 */
void WriteGlyph(const uint8_t glyph[18])
{
    uint16_t bitmap[12];
    ExpandGlyph(glyph, bitmap);
    HT1632C_Write_Pattern(bitmap);
}
