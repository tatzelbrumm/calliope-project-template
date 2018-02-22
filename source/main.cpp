/**
 * This is an minimialistic Proof-of-Concept
 * of direct register level programming
 * that bypasses all higher level libraries and runtimes
 *
 * @copyright (c) Christoph Maier
 * @author Christoph Maier.
 * based on work by Matthias L. Jugel, Calliope gGmbH.
 *
 * Licensed under the Apache License 2.0
 */

#include <cereal.h>

MicroBit uBit;  // instantiate MicroBit

Cereal cereal(&uBit);

void putIRQenables(void) {
  cereal.putreg(&NVIC->ISER, "NVIC->ISER\t");
  cereal.putreg(&NVIC->ICER, "NVIC->ICER\t");
  cereal.putreg(&NVIC->ISPR, "NVIC->ISPR\t");
  cereal.putreg(&NVIC->ICPR, "NVIC->ICPR\t");
  for (int b= 0; b<8; b++) {
    cereal.puts("NVIC->IP[");
    cereal.puthex(b);
    cereal.putreg(&NVIC->IP[b], "]\t");
  }

  cereal.putreg(&SCB->CPUID, "SCB->CPUID\t");
  cereal.putreg(&SCB->ICSR, "SCB->ICSR\t");
  cereal.putreg(&SCB->AIRCR, "SCB->AIRCR\t");
  cereal.putreg(&SCB->SCR, "SCB->SCR\t");
  cereal.putreg(&SCB->CCR, "SCB->CCR\t");
  cereal.putreg(&SCB->SHP[1], "SCB->SHP[1]\t");
  cereal.putreg(&SCB->SHCSR, "SCB->SHCSR\t");

  cereal.putreg(&NRF_POWER->INTENCLR, "NRF_POWER->INTENCLR\t");
  cereal.putreg(&NRF_CLOCK->INTENCLR, "NRF_CLOCK->INTENCLR\t");
  cereal.putreg(&NRF_RADIO->INTENCLR, "NRF_RADIO->INTENCLR\t");
  cereal.putreg(&NRF_UART0->INTENCLR, "NRF_UART0->INTENCLR\t");
  cereal.putreg(&NRF_SPI0->INTENCLR, "NRF_SPI0->INTENCLR\t");
  cereal.putreg(&NRF_TWI0->INTENCLR, "NRF_TWI0->INTENCLR\t");
  cereal.putreg(&NRF_SPI1->INTENCLR, "NRF_SPI1->INTENCLR\t");
  cereal.putreg(&NRF_TWI1->INTENCLR, "NRF_TWI1->INTENCLR\t");
  cereal.putreg(&NRF_SPIS1->INTENCLR, "NRF_SPIS1->INTENCLR\t");
  cereal.putreg(&NRF_SPIM1->INTENCLR, "NRF_SPIM1->INTENCLR\t");
  cereal.putreg(&NRF_GPIOTE->INTENCLR, "NRF_GPIOTE->INTENCLR\t");
  cereal.putreg(&NRF_ADC->INTENCLR, "NRF_ADC->INTENCLR\t");
  cereal.putreg(&NRF_TIMER0->INTENCLR, "NRF_TIMER0->INTENCLR\t");
  cereal.putreg(&NRF_TIMER1->INTENCLR, "NRF_TIMER1->INTENCLR\t");
  cereal.putreg(&NRF_TIMER2->INTENCLR, "NRF_TIMER2->INTENCLR\t");
  cereal.putreg(&NRF_RTC0->INTENCLR, "NRF_RTC0->INTENCLR\t");
  cereal.putreg(&NRF_TEMP->INTENCLR, "NRF_TEMP->INTENCLR\t");
  cereal.putreg(&NRF_RNG->INTENCLR, "NRF_RNG->INTENCLR\t");
  cereal.putreg(&NRF_ECB->INTENCLR, "NRF_ECB->INTENCLR\t");
  cereal.putreg(&NRF_AAR->INTENCLR, "NRF_AAR->INTENCLR\t");
  cereal.putreg(&NRF_CCM->INTENCLR, "NRF_CCM->INTENCLR\t");
  cereal.putreg(&NRF_WDT->INTENCLR, "NRF_WDT->INTENCLR\t");
  cereal.putreg(&NRF_RTC1->INTENCLR, "NRF_RTC1->INTENCLR\t");
  cereal.putreg(&NRF_QDEC->INTENCLR, "NRF_QDEC->INTENCLR\t");
  cereal.putreg(&NRF_LPCOMP->INTENCLR,"NRF_LPCOMP->INTENCLR\t");
}

int main(void) {
  NRF_GPIO_Type *gpiobase= (NRF_GPIO_Type *)NRF_GPIO_BASE;

  uBit.init();
  uBit.serial.baud(115200);
  uBit.serial.send("Wenn ist das Nurnstuck git und Slotermeyer?\r\n");

  cereal.putreg(&gpiobase->DIR, "Dir  ");
  cereal.putreg(&gpiobase->IN, "In   ");

  for (int p= 4; p < 13; gpiobase->PIN_CNF[p++]= 0x70dUL);
  for (int p= 13; p < 16; gpiobase->PIN_CNF[p++]= 0x505UL);

  for (uint32_t r= 1; r < (1<<3); r<<=1)
  {
    for (uint32_t c= 1; c < (1<<9); c<<=1)
    {
      uint32_t clr= ((~r&7)<<13)|(c<<4); 
      uint32_t set= (r<<13)|((~c&0x1ffUL)<<4);
      cereal.puts("rows: ");
      cereal.puthex(r);
      cereal.puts(" cols: ");
      cereal.puthex(c, 3);
      cereal.crlf();

      gpiobase->OUTSET= set;
      gpiobase->OUTCLR= clr;

      for (volatile uint32_t n= 0; n < 131072; n++);

      cereal.putreg(&gpiobase->DIR, "Dir  ");
      cereal.putreg(&gpiobase->IN, "In   ");
    }
  }
  uBit.serial.send("Ja! Beiherhundt das oder die Flipperwaldt gersput!\r\n");
  putIRQenables();
}
