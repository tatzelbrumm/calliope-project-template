/**
 * Bare bones serial interface for low-level diagnostics
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
  Cereal(PinName tx, PinName rx);

  void puts(const char* string);
  void puthex(uint32_t datum, unsigned int digits=1);
  void putdigits(uint32_t datum, unsigned int base, unsigned int digits=1);
  void putreg(volatile void *reg, const char* name);
  void crlf(void);
};
