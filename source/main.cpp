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
  NRF_GPIO_Type *gpiobase= (NRF_GPIO_Type *)NRF_GPIO_BASE;

  uBit.init();
  uBit.serial.baud(115200);
  uBit.serial.send("Wenn ist das Nurnstuck git und Slotermeyer?\r\n");
  printf("Base %08lx\r\n", uint32_t(gpiobase));
  printf("Dir  %08lx: ", uint32_t(&gpiobase->DIR));
  printf("%08lx\r\n", gpiobase->DIR);
  printf("In   %08lx: ", uint32_t(&gpiobase->IN));
  printf("%08lx\r\n", gpiobase->IN);

  printf("Configure LED pins\r\n");
  for (int p= 4; p < 13; gpiobase->PIN_CNF[p++]= 0x70dUL);
  for (int p= 13; p < 16; gpiobase->PIN_CNF[p++]= 0x505UL);

  gpiobase->OUTSET= 0x1ff0UL;
  gpiobase->OUTCLR= 0xe000UL;
  
  printf("Dir  %08lx: ", uint32_t(&gpiobase->DIR));
  printf("%08lx\r\n", gpiobase->DIR);
  printf("In   %08lx: ", uint32_t(&gpiobase->IN));
  printf("%08lx\r\n", gpiobase->IN);

  gpiobase->OUTSET= 0xe000UL;
  gpiobase->OUTCLR= 0x1ff0UL; 

  printf("Dir  %08lx: ", uint32_t(&gpiobase->DIR));
  printf("%08lx\r\n", gpiobase->DIR);
  printf("In   %08lx: ", uint32_t(&gpiobase->IN));
  printf("%08lx\r\n", gpiobase->IN);

  uBit.serial.send("Ja! Beiherhundt das oder die Flipperwaldt gersput!\r\n");
}
