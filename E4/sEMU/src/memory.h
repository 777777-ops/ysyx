#ifndef MEMORY_H
#define MEMORY_H

#include<stdint.h>
#include<stdio.h>
#define UNUSED(x) (void)(x)

void load_file_mem(FILE* file);
uint32_t read_mem(uint32_t addr, uint8_t RSel);
void write_mem(uint32_t addr, uint8_t WSel, uint32_t data);

#endif

