/**
 * Bare bones serial interface for low-level diagnostics
 *
 * @copyright (c) Christoph Maier
 * @author Christoph Maier.
 * based on work by Matthias L. Jugel, Calliope gGmbH.
 *
 * Licensed under the Apache License 2.0
 */

/**
 To show the difference in the interrupt configuration, include MicroBit.h
 */
#include <MicroBit.h>

class Cereal
{
public:
  MicroBit *ubit;

  Cereal(MicroBit *ubit);

  void putc(char c);
  void puts(const char* string);
  void puthex(uint32_t datum, unsigned int digits=1);
  void putreg(volatile void *reg, const char* name);
  void crlf(void);
};
