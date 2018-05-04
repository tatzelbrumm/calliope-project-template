/*
 * zpix bitmap font definitions
 */
#include <stdint.h>

extern const uint8_t charcode[][3];
extern const uint8_t glyph[][18];

void ExpandGlyph(const uint8_t glyph[18], uint16_t *bitmap);
void WriteGlyph(const uint8_t glyph[18]);

void ScrollText(const uint8_t font[][18], const uint16_t text[], uint32_t length, uint32_t delay);
