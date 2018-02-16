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

int main(void) {
    volatile uint32_t gpiobase= NRF_GPIO_BASE;

    uBit.init();
    uBit.serial.baud(115200);
    uBit.serial.send("Wenn ist das Nurnstuck git und Slotermeyer?\r\n");
    printf("%08x\r\n", gpiobase);
    uBit.serial.send("Ja! Beiherhundt das oder die Flipperwaldt gersput!\r\n");
}
