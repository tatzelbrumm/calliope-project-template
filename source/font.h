/*
 * zpix bitmap font definitions
 */
#include <stdint.h>

extern const uint16_t charcode[];
extern const uint8_t glyph[][18];

void ExpandGlyph(const uint8_t glyph[18], uint16_t *bitmap);
void WriteGlyph(const uint8_t glyph[18]);
