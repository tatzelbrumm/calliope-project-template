/**
 * This is a simple template for use with Calliope mini.
 *
 * @copyright (c) Calliope gGmbH.
 * @author Matthias L. Jugel.
 *
 * Licensed under the Apache License 2.0
 */

#include <MicroBit.h>
#include <registerdump.h>

MicroBit uBit;


int main(void) {
    uBit.init();
    uBit.serial.baud(115200);
    printf("\r\nInterrupt registers\r\n");
    dumpIrqEnables();
    printf("\r\nClock registers\r\n");
    dumpClockRegisters();
    printf("\r\nRadio registers\r\n");
    dumpRadioRegisters();
}
