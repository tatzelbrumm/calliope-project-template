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

  for (int p= 4; p < 13; gpiobase->PIN_CNF[p++]= 0x70dUL);
  for (int p= 13; p < 16; gpiobase->PIN_CNF[p++]= 0x505UL);

  for (uint32_t r= 1; r < (1<<3); r++)
  {
    for (uint32_t c= 0; c < (1<<9); c++)
    {
      uint32_t clr= ((~r&7)<<13)|(c<<4); 
      uint32_t set= (r<<13)|((~c&0x1ffUL)<<4);
      printf("rows: %1lx ", r);
      printf("cols: %03lx\r\n", c);
      for (int n= 0; n < 32768; n++)
      {
	gpiobase->OUTSET= set;
	gpiobase->OUTCLR= clr;
      }
      printf("Dir  %08lx: ", uint32_t(&gpiobase->DIR));
      printf("%08lx\r\n", gpiobase->DIR);
      printf("In   %08lx: ", uint32_t(&gpiobase->IN));
      printf("%08lx\r\n", gpiobase->IN);
    }
  }

  uBit.serial.send("Ja! Beiherhundt das oder die Flipperwaldt gersput!\r\n");
}
