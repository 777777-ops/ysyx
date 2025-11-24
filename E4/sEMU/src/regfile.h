#ifndef REGFILE_H
#define REGFILE_H

#include <stdint.h>

uint32_t read_reg(uint8_t rs);
void write_reg(uint32_t data, uint8_t ds);

#endif

