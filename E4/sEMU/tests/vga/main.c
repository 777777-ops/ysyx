#include "cpu.h"
#include "memory.h"
#include "rom.h"
#include "dbg.h"
#include "visual.h"
#include <stdlib.h>
#include <string.h>

int count = 0;
static FILE* open_file(const char* file_name){
   check(file_name != NULL, "ERROR ADDRESS");

   FILE *file = fopen(file_name,"r");
   check(file != NULL, "Coundn't Fould File");

   return file;
error:
   return NULL;
}

int main(){

   char name[] = {"../codes/vga.bin"};
   FILE *file = open_file(name);
   if(file == NULL) return 0;
   load_file_rom(file);
   load_file_mem(file);
   fclose(file);
   
   while(cycle()){
      count ++;
     // printf("%d\n",count);
   }
   draw();
   return 0;
}
