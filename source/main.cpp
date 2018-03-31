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
#include <nrf51_bitfields.h>

MicroBit uBit;

const char OM[]="\nOM\n",
  MANI[]= "\nMANI\n",
  PADME[]= "\nPADME\n",
  HUM[]= "\nHUM\n";

static const char *meditations[4]= {
  OM, MANI, PADME, HUM
};

void send_continuously(uint8_t channel)
{
    NRF_RADIO->FREQUENCY= channel < 100 ? channel : 100;
    NRF_RADIO->TEST= RADIO_TEST_PLLLOCK_Msk | RADIO_TEST_CONSTCARRIER_Msk;

    // Firstly, disable the Radio interrupt. We want to wait until the transmission completes.
    NVIC_DisableIRQ(RADIO_IRQn);

    // Turn off the transceiver.
    NRF_RADIO->EVENTS_DISABLED = 0;
    NRF_RADIO->TASKS_DISABLE = 1;
    while(NRF_RADIO->EVENTS_DISABLED == 0);

    // Turn on the transmitter, and wait for it to signal that it's ready to use.
    NRF_RADIO->EVENTS_READY = 0;
    NRF_RADIO->TASKS_TXEN = 1;
    while (NRF_RADIO->EVENTS_READY == 0);
}

int main(void) {
    uBit.init();
    uBit.serial.baud(115200);

    uBit.radio.enable();
    unsigned char channel=0;
 considered_harmful:
    if (uBit.buttonA.isPressed()) {
        channel++;
    }
    else if (uBit.buttonB.isPressed()) {
        channel--;
    }
    else
        goto considered_harmful;
    channel%=100;

    send_continuously(channel);

    printf("\r\nChannel: %03d\r\n", channel);

    uBit.display.scroll(channel);

    printf("\r\nInterrupt registers\r\n");
    dumpIrqEnables();
    printf("\r\nClock registers\r\n");
    dumpClockRegisters();
    printf("\r\nRadio registers\r\n");
    dumpRadioRegisters();

    uBit.sleep(680);
    goto considered_harmful;
}
