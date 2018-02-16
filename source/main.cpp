/**
 * This is a simple template for use with Calliope mini.
 *
 * @copyright (c) Calliope gGmbH.
 * @author Matthias L. Jugel.
 *
 * Licensed under the Apache License 2.0
 */

#include <MicroBit.h>

MicroBit uBit;

void hexdump(const char *prefix, const uint8_t *b, int size) {
    for (int i = 0; i < size; i += 16) {
        if (prefix != NULL && strlen(prefix) > 0) printf("%s %06x: ", prefix, i);
        for (int j = 0; j < 16; j++) {
            if ((i + j) < size) printf("%02x", b[i + j]); else printf("  ");
            if ((j + 1) % 2 == 0) putchar(' ');
        }
        putchar(' ');
        for (int j = 0; j < 16 && (i + j) < size; j++) {
            putchar(b[i + j] >= 0x20 && b[i + j] <= 0x7E ? b[i + j] : '.');
        }
        printf("\r\n");
    }
}


int main(void) {
    volatile uint32_t gpiobase= NRF_GPIO_BASE;

    uint8_t quadbyte[4];
    uint8_t* p= quadbyte;

    for (uint16_t b= 4; b-- > 0; *p++= uint8_t(gpiobase>>(b<<3)) );

    uBit.init();
    uBit.serial.baud(115200);
    uBit.serial.send("Wenn ist das Nurnstuck git und Slotermeyer?\r\n");
    hexdump("datum", quadbyte, 4);
    uBit.serial.send("Ja! Beiherhundt das oder die Flipperwaldt gersput!\r\n");
}
