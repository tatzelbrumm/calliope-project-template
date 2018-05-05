/**
 * This is an minimialistic Proof-of-Concept
 * of Chinese scrolling text display
 * that bypasses all higher level libraries and runtimes
 *
 * @copyright (c) Christoph Maier
 * @author Christoph Maier.
 * based on work by Matthias L. Jugel, Calliope gGmbH.
 *
 * Licensed under the Apache License 2.0
 */

#include <cereal.h>
#include <font.h>
#include <LED-Matrix.h>
//#include <nrf51.h> // redundant, just to make Eclipse happy
//#include <core_cm0.h> // redundant, just to make Eclipse happy

//const uint16_t sinotext[]= {71, 674, 1499, 299, 56, 1478, 80, 1163, 90, 2145, 1154, 429, 164, 313, 1478, 1831, 1284, 1154};
const uint16_t sinotext[]= {484, 205, 1495, 80, 521, 968, 2543, 487, 1788, 706};
const uint16_t sinolength= sizeof(sinotext)/sizeof(uint16_t);

Cereal cereal(USBTX, USBRX);

uint16_t readpattern[12]; // pattern read back

void delay(uint32_t count) { for (volatile uint32_t t=count; --t; ); }

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

void printpattern(const uint16_t pattern[]) {
  for (int r=16; r-->4; ) {
    for (int c=0; c<12; c++) {
      cereal.puts(pattern[c]&(1<<r)? "#":".");
    }
    cereal.crlf();
  }
}

int main(void) {
  NRF_GPIO_Type *gpiobase= (NRF_GPIO_Type *)NRF_GPIO_BASE;

  cereal.baud(115200);
  //cereal.puts("Wenn ist das Nurnstuck git und Slotermeyer?\r\n");
  //cereal.putreg(&gpiobase->DIR, "Dir  ");
  //cereal.putreg(&gpiobase->IN, "In   ");

  HT1632C_Init();

  //cereal.putreg(&gpiobase->DIR, "Dir  ");
  //cereal.putreg(&gpiobase->IN, "In   ");

  HT1632C_clr();

  //cereal.putreg(&gpiobase->DIR, "Dir  ");
  //cereal.putreg(&gpiobase->IN, "In   ");

  //cereal.puts("Ja! Beiherhundt das oder die Flipperwaldt gersput!\r\n");
  //putIRQenables();

 considered_harmful:
  cereal.puts("Scrolling message\r\n");
  ScrollText(glyph, sinotext, sinolength, 1<<18, 1<<20);
  cereal.puts("Scrolling done\r\n");
  delay(1<<20);
  goto considered_harmful;
}
