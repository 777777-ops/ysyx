#include"memory.h"

static uint8_t mem[4 * 1024 * 1024];

uint32_t* i = &mem[331732];
uint32_t* sum = &mem[331748];

void load_file_mem(FILE* file){

   rewind(file);	
   size_t bytes_read = 1; //debug   
   bytes_read = fread(mem,sizeof(char),1024 * 1024 * 4, file);
   return;
}

uint32_t read_mem(uint32_t addr, uint8_t RSel){
    addr &= ~(0x3);
    
    uint32_t result = 0x0;
    if(RSel & 0x8)
       result |= mem[addr + 3] << 24;
    if(RSel & 0x4)
       result |= mem[addr + 2] << 16;
    if(RSel & 0x2)
       result |= mem[addr + 1] << 8; 
    if(RSel & 0x1)
       result |= mem[addr]; 
    return result;
}


void write_mem(uint32_t addr, uint8_t WSel, uint32_t data){ 
    addr &= ~(0x3);

    mem[addr + 3] = (WSel & 0x8) ? (data >> 24) : 0x0;
    mem[addr + 2] = (WSel & 0x4) ? (data >> 16) : 0x0;
    mem[addr + 1] = (WSel & 0x2) ? (data >> 8) : 0x0;
    mem[addr] = (WSel & 0x1) ? (data) : 0x0;

    return;
}
