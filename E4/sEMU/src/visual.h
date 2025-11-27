#ifndef VISUAL_H
#define VISUAL_H

#include <stdint.h>

#define EQU(A,B) !(A ^ B)
void write_pixels(uint32_t addr, uint8_t WSel, uint32_t data);
void draw();

#endif
