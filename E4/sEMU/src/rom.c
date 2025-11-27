#include "dbg.h"
#include "rom.h"

static uint32_t code[1024 * 1024 * 4] = {
    0x000010b7,
    0x00500113,
    0x00300193,
    0x00310233,
    0x0040a023,
    0x0000a283,
    0x04100313,
    0x00608223,
    0x0040c383,
    0x00000067
};

void load_file_rom(FILE* file){

   rewind(file);	
   size_t bytes_read = 1; //debug   
   bytes_read = fread(code,sizeof(int),1024 * 1024 * 4,file);
   UNUSED(bytes_read);

   return;
}


uint32_t get_inst(uint32_t pc){
    uint32_t a = code[pc >> 2];
    return a;
}
