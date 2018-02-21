/**
 * This is a simple template for use with Calliope mini.
 *
 * @copyright (c) Christoph Maier
 * @author Christoph Maier.
 * based on work by Matthias L. Jugel, Calliope gGmbH.
 *
 * Licensed under the Apache License 2.0
 */

/*
 * yotta_modules/mbed-classic/api/SerialBase.h
 */
#include <SerialBase.h>

class Cereal : public mbed::SerialBase
{
public:
  Cereal(PinName tx, PinName rx) : mbed::SerialBase(tx, rx) {}

  void puts(const char* string)
  {
    while (*string)
    {
      _base_putc(*string++);
    }
  }

  void puthex(uint32_t datum, unsigned int digits=1)
  {
    char dig[8];
    unsigned int d= 0;
    while (d < digits || datum) {
      char c= datum & 0xF;
      c+= c<10? '0' : 'A'-10;
      dig[d++]= c;
      datum >>= 4;
    }
    while (d-- > 0) {
      _base_putc(dig[d]);
    }
  }
};
  
Cereal cereal(USBTX, USBRX);

int main(void) {
  NRF_GPIO_Type *gpiobase= (NRF_GPIO_Type *)NRF_GPIO_BASE;

  cereal.baud(115200);
  cereal.puts("Wenn ist das Nurnstuck git und Slotermeyer?\r\n");

  cereal.puts("Dir  ");
  cereal.puthex(uint32_t(&gpiobase->DIR),8);
  cereal.puts("  ");
  cereal.puthex(gpiobase->DIR,8);
  cereal.puts("\r\n");
  cereal.puts("In   ");
  cereal.puthex(uint32_t(&gpiobase->IN),8);
  cereal.puts("  ");
  cereal.puthex(gpiobase->IN,8);
  cereal.puts("\r\n");

  for (int p= 4; p < 13; gpiobase->PIN_CNF[p++]= 0x70dUL);
  for (int p= 13; p < 16; gpiobase->PIN_CNF[p++]= 0x505UL);

  for (uint32_t r= 1; r < (1<<3); r++)
  {
    for (uint32_t c= 0; c < (1<<9); c++)
    {
      uint32_t clr= ((~r&7)<<13)|(c<<4); 
      uint32_t set= (r<<13)|((~c&0x1ffUL)<<4);
      cereal.puts("rows: ");
      cereal.puthex(r);
      cereal.puts(" cols: ");
      cereal.puthex(c, 3);
      cereal.puts("\r\n");

      gpiobase->OUTSET= set;
      gpiobase->OUTCLR= clr;

      cereal.puts("Dir  ");
      cereal.puthex(uint32_t(&gpiobase->DIR),8);
      cereal.puts("  ");
      cereal.puthex(gpiobase->DIR,8);
      cereal.puts("\r\n");
      cereal.puts("In   ");
      cereal.puthex(uint32_t(&gpiobase->IN),8);
      cereal.puts("  ");
      cereal.puthex(gpiobase->IN,8);
      cereal.puts("\r\n");

      for (volatile uint32_t n= 0; n < 131072; n++);
    }
  }
  cereal.puts("Ja! Beiherhundt das oder die Flipperwaldt gersput!\r\n");
}
