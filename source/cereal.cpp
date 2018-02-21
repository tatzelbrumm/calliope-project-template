/**
 * Bare bones serial interface for low-level diagnostics
 *
 * @copyright (c) Christoph Maier
 * @author Christoph Maier.
 * based on work by Matthias L. Jugel, Calliope gGmbH.
 *
 * Licensed under the Apache License 2.0
 */

#include <cereal.h>

Cereal::Cereal(PinName tx, PinName rx) : mbed::SerialBase(tx, rx) {}

void Cereal::puts(const char* string)
{
  while (*string) {
      _base_putc(*string++);
  }
}

void Cereal::puthex(uint32_t datum, unsigned int digits)
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

