#include "cpu.h"
#include "memory.h"
#include "rom.h"
#include "dbg.h"
#include <stdlib.h>
#include <string.h>

int count = 0;
static FILE* open_file(const char* file_name){
   check(file_name != NULL, "ERROR ADDRESS");
   char path[100];
   sprintf(path, "tests/codes/%s", file_name);

   FILE *file = fopen(path,"r");
   check(file != NULL, "Coundn't Fould File");

   return file;
error:
   return NULL;
}

int main(int args,char* argv[]){

   if(args > 1){
       FILE *file = open_file(argv[1]);
       if(file == NULL) return 0;
       load_file_rom(file);
       load_file_mem(file);
       fclose(file);
   }	   
   while(cycle()){
      count ++;
   }
   return 0;
}
