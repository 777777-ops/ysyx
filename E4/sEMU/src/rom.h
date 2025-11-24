#ifndef ROM_H
#define ROM_H
#include <stdio.h>
#include <stdint.h>

void load_file_rom(FILE* file);
uint32_t get_inst(uint32_t pc);
#endif
