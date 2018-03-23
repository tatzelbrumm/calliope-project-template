/*
 * radio.cpp
 * =========
 * Transmitter side
 *
 * Compile with 
 * #define MICROBIT_BLE_ENABLED      0
 * #define MICROBIT_BLE_PAIRING_MODE 0
 * in yotta_modules/microbit-dal/inc/core/MicroBitConfig.h
 *
 * see https://lancaster-university.github.io/microbit-docs/ubit/radio/# for details
 */

#include <MicroBit.h>
#include <registerdump.h>

MicroBit uBit;

const char OM[]="\nOM\n",
  MANI[]= "\nMANI\n",
  PADME[]= "\nPADME\n",
  HUM[]= "\nHUM\n";

static const char *meditations[4]= {
  OM, MANI, PADME, HUM
};

int main(void) {
    uBit.init();
    uBit.serial.baud(115200);

    uBit.radio.enable();
    PacketBuffer b(1);
    unsigned char count=0;
 considered_harmful:
    if (uBit.buttonA.isPressed()) {
        count++;
    }
    else if (uBit.buttonB.isPressed()) {
        count--;
    }
    else
        goto considered_harmful;
    count%=4;
    b[0]= count;

    uBit.radio.datagram.send(b);

    uBit.serial.send(meditations[count]);

    uBit.display.scroll(meditations[count]);

    printf("\r\nClock registers\r\n");
    dumpClockRegisters();
    printf("\r\nRadio registers\r\n");
    dumpRadioRegisters();

    uBit.sleep(680);
    goto considered_harmful;
}
