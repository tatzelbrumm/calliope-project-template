#include <stdint.h>
#include <LED-Matrix.h>

void busy_wait(uint32_t delay)
{
    volatile uint32_t t= delay;
    while (t--);
}

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

void ScrollText(const uint8_t font[][18], const uint16_t text[], uint32_t length, uint32_t scroll_delay, uint32_t char_delay)
{
    static uint16_t bitmap[24]; // double width buffer
    static uint16_t column= 0;
    uint16_t col= column;
    uint16_t letter= 0;

    for (int c= 0; c < 12; c++) { // clear initial display
        bitmap[column++]= 0;
        if (column > 23) column= 0;
    }
    while (letter < length) {
        if (0 == col%12) {
            ExpandGlyph(font[text[letter++]], bitmap+column);
            column= 12-column;
        }
        HT1632C_Write_Pattern(bitmap, col, 24);
        busy_wait(col++ % 12 ? scroll_delay : char_delay);
        if (col > 23) col= 0;
    }
    for (int c= 0; c < 12; c++) { // display the last glyph
        HT1632C_Write_Pattern(bitmap, col, 24);
        busy_wait(col++ % 12 ? scroll_delay : char_delay);
        if (col > 23) col= 0;
    }
    for (int c= 0; c < 12; c++) { // clear final display
        bitmap[column++]= 0;
        if (column > 23) column= 0;
    }
    for (int c= 0; c < 12; c++) { // shift out the last glyph
        HT1632C_Write_Pattern(bitmap, col, 24);
        busy_wait(col++ % 12 ? scroll_delay : char_delay);
        if (col > 23) col= 0;
    }
}

void ScrollText(const uint8_t font[][18], const uint16_t text[], uint32_t length, uint32_t delay)
{
    ScrollText(font, text, length, delay, delay);
}
