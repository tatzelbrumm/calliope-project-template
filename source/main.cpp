/**
 * This is an minimialistic Proof-of-Concept
 * of direct register level programming
 * that bypasses all higher level libraries and runtimes
 *
 * @copyright (c) Christoph Maier
 * @author Christoph Maier.
 *
 * Licensed under the Apache License 2.0
 */

#include <nrf51.h>

int main(void)
{
  NRF_GPIO_Type *gpiobase= (NRF_GPIO_Type *)NRF_GPIO_BASE;

  for (int p= 4; p < 13; gpiobase->PIN_CNF[p++]= 0x70dUL);
  for (int p= 13; p < 16; gpiobase->PIN_CNF[p++]= 0x505UL);

  for (uint32_t r= 1; r < (1<<3); r++)
  {
    for (uint32_t c= 0; c < (1<<9); c++)
    {
      uint32_t clr= ((~r&7)<<13)|(c<<4); 
      uint32_t set= (r<<13)|((~c&0x1ffUL)<<4);
      for (uint32_t n= 0; n < 131072; n++)
      {
	gpiobase->OUTSET= set;
	gpiobase->OUTCLR= clr;
      }
    }
  }
}
