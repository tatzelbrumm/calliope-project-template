/*
 * radio.cpp
 * =========
 * Receiver side
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

const char OM[]="OM",
  MANI[]= "MANI",
  PADME[]= "PADME",
  HUM[]= "HUM";

static const char *meditations[4]= {
  OM, MANI, PADME, HUM
};

static volatile uint8_t omCount;

void onData(MicroBitEvent e)
{
    PacketBuffer b=uBit.radio.datagram.recv();
    omCount= b[0];
    uBit.serial.send("\r\nReceived ");
    uBit.serial.send(omCount);
    uBit.serial.send("\r\n");
    if (4 > omCount)
        uBit.display.scroll(meditations[omCount]);
}

int main(void) {
    uBit.init();
    uBit.messageBus.listen(MICROBIT_ID_RADIO, MICROBIT_RADIO_EVT_DATAGRAM, onData);
    uBit.radio.enable();
    uBit.serial.baud(115200);

    printf("\r\nClock registers\r\n");
    dumpClockRegisters();
    printf("\r\nRadio registers\r\n");
    dumpRadioRegisters();

    release_fiber();
}
