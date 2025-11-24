#include "immSel.h"

uint32_t get_imm(uint32_t inst, uint8_t ImmSel){
   
   uint32_t imm = (inst >> 31) ? 0xFFFFF000 : 0x0;
   
   switch(ImmSel){
	case 0:
	   return (inst >> 20) | imm;
	case 1:
	   return ((inst >> 25) & 0x7F) << 5 | ((inst >> 7) & 0x1F) | imm;
	case 2:
	   return inst & 0xFFFFF000;
	case 3:
	   return 0x0;
	default:
	   return 0x0;
   }
}
