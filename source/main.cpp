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

/*
Not sure to which the following #include points, they're both identical
./yotta_modules/mbed-classic/targets/cmsis/TARGET_NORDIC/TARGET_MCU_NRF51822/nrf51.h
./yotta_modules/nrf51-sdk/source/nordic_sdk/components/device/nrf51.h
 */
#include <nrf51.h>
/*
./yotta_modules/mbed-classic/targets/cmsis/core_cm0.h
 */
#include <core_cm0.h>

int main(void)
{
  NRF_GPIO_Type *gpiobase= (NRF_GPIO_Type *)NRF_GPIO_BASE;

  for (int p= 4; p < 13; gpiobase->PIN_CNF[p++]= 0x70dUL);
  for (int p= 13; p < 16; gpiobase->PIN_CNF[p++]= 0x505UL);

  while (1)
  {
    for (uint32_t r= 1; r < (1<<3); r<<=1)
    {
      for (uint32_t c= 1; c < (1<<9); c<<=1)
      {
	uint32_t clr= ((~r&7)<<13)|(c<<4); 
	uint32_t set= (r<<13)|((~c&0x1ffUL)<<4);
	for (volatile uint32_t n= 0; n < (1<<19); n++);

	gpiobase->OUTSET= set;
	gpiobase->OUTCLR= clr;
      }
    }
  }
}
