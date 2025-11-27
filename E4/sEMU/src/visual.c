#include <am.h>
#include <klib-macros.h>
#include "visual.h"
static uint32_t buffer[256 * 256];

void write_pixels(uint32_t addr, uint8_t WSel, uint32_t data){ 
   addr -= 0x20000000;

   if(EQU(WSel, 0xf)){
      addr &= ~(0x3);
      addr >>= 2;
      buffer[addr] = data;
   }else if(EQU(WSel, 0x1)){
      uint32_t temp = buffer[addr & (~(0x3)) >> 2];
      uint8_t insert = data;
      //位移个数
      uint8_t bits = (addr & 0x3) << 3;

      temp &= ~(0xFF << bits);
      temp |= insert << bits;

      buffer[addr & (~(0x3)) >> 2] = temp;
   }
   return;
}

void draw(){
   //设置时间
   uint64_t start_time = io_read(AM_TIMER_UPTIME).us;

   io_write(AM_GPU_FBDRAW, 0, 0, buffer, 256, 256, true);

   while(io_read(AM_TIMER_UPTIME).us - start_time < 5000000){}
}

