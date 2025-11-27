#include"memory.h"
#include"visual.h"
#include<stdio.h>
#define EQU(A,B) !(A ^ B)
static uint8_t mem[4 * 1024 * 1024 * 4];

uint32_t* i = (uint32_t*)&mem[331732];     //debug
uint32_t* sum = (uint32_t*)&mem[331748];   //debug

void load_file_mem(FILE* file){

   rewind(file);	
   size_t bytes_read = 1; //debug   
   bytes_read = fread(mem,sizeof(char),1024 * 1024 * 4 * 4, file);
   UNUSED(bytes_read);
   return;
}

uint32_t read_mem(uint32_t addr, uint8_t RSel){
   uint32_t result = 0x0;
   if(EQU(RSel, 0xf)){
      addr &= ~(0x3);
      result |= mem[addr + 3] << 24;
      result |= mem[addr + 2] << 16;
      result |= mem[addr + 1] << 8; 
      result |= mem[addr]; 
   }else if(EQU(RSel, 0x1)){
      result |= mem[addr];
   }

   return result;
}


void write_mem(uint32_t addr, uint8_t WSel, uint32_t data){ 
   if(addr >= 0x20000000 &&  addr < 0x20040000){
	   write_pixels(addr, WSel, data); 
      printf("addr:%8x | input:%8x\n", addr,data);
	   return;	
   }
   if(EQU(WSel, 0xf)){
      	addr &= ~(0x3);
      	mem[addr + 3] = (data >> 24);
      	mem[addr + 2] = (data >> 16);
      	mem[addr + 1] = (data >> 8);
   	mem[addr] =     (data);
   }else if(EQU(WSel, 0x1)){
      mem[addr] = data;
   }

   //debug
   //printf("addr:%8x | input:%8x\n", addr,data);

   return;
}
