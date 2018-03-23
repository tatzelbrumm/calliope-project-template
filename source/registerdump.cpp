/*
 * Dump registers for diagnostic purposes
 */

#include <registerdump.h>
#include <nrf51.h>
#include <stdio.h>

void putreg(volatile void *reg, const char *name)
{
    uint32_t *ptr= (uint32_t *)reg;
    printf("%s %08x: %08x\r\n", name, uint32_t(ptr), *ptr);
}

void dumpRadioRegisters(void)
{
    putreg(&NRF_RADIO->TASKS_TXEN, "NRF_RADIO->TASKS_TXEN"); /*!< Enable radio in TX mode. */
    putreg(&NRF_RADIO->TASKS_RXEN, "NRF_RADIO->TASKS_RXEN"); /*!< Enable radio in RX mode. */
    putreg(&NRF_RADIO->TASKS_START, "NRF_RADIO->TASKS_START"); /*!< Start radio. */
    putreg(&NRF_RADIO->TASKS_STOP, "NRF_RADIO->TASKS_STOP"); /*!< Stop radio. */
    putreg(&NRF_RADIO->TASKS_DISABLE, "NRF_RADIO->TASKS_DISABLE"); /*!< Disable radio. */
    putreg(&NRF_RADIO->TASKS_RSSISTART, "NRF_RADIO->TASKS_RSSISTART"); /*!< Start the RSSI and take one sample of the receive signal strength. */
    putreg(&NRF_RADIO->TASKS_RSSISTOP, "NRF_RADIO->TASKS_RSSISTOP"); /*!< Stop the RSSI measurement. */
    putreg(&NRF_RADIO->TASKS_BCSTART, "NRF_RADIO->TASKS_BCSTART"); /*!< Start the bit counter. */
    putreg(&NRF_RADIO->TASKS_BCSTOP, "NRF_RADIO->TASKS_BCSTOP"); /*!< Stop the bit counter. */
    putreg(&NRF_RADIO->EVENTS_READY, "NRF_RADIO->EVENTS_READY"); /*!< Ready event. */
    putreg(&NRF_RADIO->EVENTS_ADDRESS, "NRF_RADIO->EVENTS_ADDRESS"); /*!< Address event. */
    putreg(&NRF_RADIO->EVENTS_PAYLOAD, "NRF_RADIO->EVENTS_PAYLOAD"); /*!< Payload event. */
    putreg(&NRF_RADIO->EVENTS_END, "NRF_RADIO->EVENTS_END"); /*!< End event. */
    putreg(&NRF_RADIO->EVENTS_DISABLED, "NRF_RADIO->EVENTS_DISABLED"); /*!< Disable event. */
    putreg(&NRF_RADIO->EVENTS_DEVMATCH, "NRF_RADIO->EVENTS_DEVMATCH"); /*!< A device address match occurred on the last received packet. */
    putreg(&NRF_RADIO->EVENTS_DEVMISS, "NRF_RADIO->EVENTS_DEVMISS"); /*!< No device address match occurred on the last received packet. */
    putreg(&NRF_RADIO->EVENTS_RSSIEND, "NRF_RADIO->EVENTS_RSSIEND"); /*!< Sampling of the receive signal strength complete. A new RSSI sample is ready for readout at the RSSISAMPLE register. */
    putreg(&NRF_RADIO->EVENTS_BCMATCH, "NRF_RADIO->EVENTS_BCMATCH"); /*!< Bit counter reached bit count value specified in BCC register.*/
    putreg(&NRF_RADIO->SHORTS, "NRF_RADIO->SHORTS"); /*!< Shortcuts for the radio. */
    putreg(&NRF_RADIO->INTENSET, "NRF_RADIO->INTENSET"); /*!< Interrupt enable set register.*/
    putreg(&NRF_RADIO->INTENCLR, "NRF_RADIO->INTENCLR"); /*!< Interrupt enable clear register. */
    putreg(&NRF_RADIO->CRCSTATUS, "NRF_RADIO->CRCSTATUS"); /*!< CRC status of received packet. */
    putreg(&NRF_RADIO->RXMATCH, "NRF_RADIO->RXMATCH"); /*!< Received address. */
    putreg(&NRF_RADIO->RXCRC, "NRF_RADIO->RXCRC"); /*!< Received CRC. */
    putreg(&NRF_RADIO->DAI, "NRF_RADIO->DAI"); /*!< Device address match index. */
    putreg(&NRF_RADIO->PACKETPTR, "NRF_RADIO->PACKETPTR"); /*!< Packet pointer. Decision point: START task. */
    putreg(&NRF_RADIO->FREQUENCY, "NRF_RADIO->FREQUENCY"); /*!< Frequency. */
    putreg(&NRF_RADIO->TXPOWER, "NRF_RADIO->TXPOWER"); /*!< Output power. */
    putreg(&NRF_RADIO->MODE, "NRF_RADIO->MODE"); /*!< Data rate and modulation. */
    putreg(&NRF_RADIO->PCNF0, "NRF_RADIO->PCNF0"); /*!< Packet configuration 0. */
    putreg(&NRF_RADIO->PCNF1, "NRF_RADIO->PCNF1"); /*!< Packet configuration 1. */
    putreg(&NRF_RADIO->BASE0, "NRF_RADIO->BASE0"); /*!< Radio base address 0. Decision point: START task. */
    putreg(&NRF_RADIO->BASE1, "NRF_RADIO->BASE1"); /*!< Radio base address 1. Decision point: START task. */
    putreg(&NRF_RADIO->PREFIX0, "NRF_RADIO->PREFIX0"); /*!< Prefixes bytes for logical addresses 0 to 3. */
    putreg(&NRF_RADIO->PREFIX1, "NRF_RADIO->PREFIX1"); /*!< Prefixes bytes for logical addresses 4 to 7. */
    putreg(&NRF_RADIO->TXADDRESS, "NRF_RADIO->TXADDRESS"); /*!< Transmit address select. */
    putreg(&NRF_RADIO->RXADDRESSES, "NRF_RADIO->RXADDRESSES"); /*!< Receive address select. */
    putreg(&NRF_RADIO->CRCCNF, "NRF_RADIO->CRCCNF"); /*!< CRC configuration. */
    putreg(&NRF_RADIO->CRCPOLY, "NRF_RADIO->CRCPOLY"); /*!< CRC polynomial. */
    putreg(&NRF_RADIO->CRCINIT, "NRF_RADIO->CRCINIT"); /*!< CRC initial value. */
    putreg(&NRF_RADIO->TEST, "NRF_RADIO->TEST"); /*!< Test features enable register.*/
    putreg(&NRF_RADIO->TIFS, "NRF_RADIO->TIFS"); /*!< Inter Frame Spacing in microseconds. */
    putreg(&NRF_RADIO->RSSISAMPLE, "NRF_RADIO->RSSISAMPLE"); /*!< RSSI sample. */
    putreg(&NRF_RADIO->STATE, "NRF_RADIO->STATE"); /*!< Current radio state. */
    putreg(&NRF_RADIO->DATAWHITEIV, "NRF_RADIO->DATAWHITEIV"); /*!< Data whitening initial value. */
    putreg(&NRF_RADIO->BCC, "NRF_RADIO->BCC"); /*!< Bit counter compare. */
    putreg(&NRF_RADIO->DAB[8], "NRF_RADIO->DAB[8]"); /*!< Device address base segment. */
    putreg(&NRF_RADIO->DAP[8], "NRF_RADIO->DAP[8]"); /*!< Device address prefix. */
    putreg(&NRF_RADIO->DACNF, "NRF_RADIO->DACNF"); /*!< Device address match configuration. */
    putreg(&NRF_RADIO->OVERRIDE0, "NRF_RADIO->OVERRIDE0"); /*!< Trim value override register 0. */
    putreg(&NRF_RADIO->OVERRIDE1, "NRF_RADIO->OVERRIDE1"); /*!< Trim value override register 1. */
    putreg(&NRF_RADIO->OVERRIDE2, "NRF_RADIO->OVERRIDE2"); /*!< Trim value override register 2. */
    putreg(&NRF_RADIO->OVERRIDE3, "NRF_RADIO->OVERRIDE3"); /*!< Trim value override register 3. */
    putreg(&NRF_RADIO->OVERRIDE4, "NRF_RADIO->OVERRIDE4"); /*!< Trim value override register 4. */
    putreg(&NRF_RADIO->POWER, "NRF_RADIO->POWER"); /*!< Peripheral power control. */
}
