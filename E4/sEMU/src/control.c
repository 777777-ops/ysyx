#include"control.h"

void parse_inst(uint32_t inst, struct signs* signs){
    // 提取opcode (位0-6)
    uint8_t opcode = inst & 0x7F;
    // 提取funct3 (位12-14)
    uint8_t funct3 = (inst >> 12) & 0x7;
    // 提取funct7 (位25-31)
    //uint8_t funct7 = (inst >> 25) & 0x7F;


    signs->PCSel = EQU(opcode,0x67);

    signs->RegWEn = EQU(opcode,0x37) | EQU(opcode,0x33) |
	            EQU(opcode,0x03) | EQU(opcode,0x13) |
		    EQU(opcode,0x67);

    signs->ImmSel = EQU(opcode,0x23) ? 0x1 :
	   	    EQU(opcode,0x37) ? 0x2 :
		    0x0;

    signs->BSel = EQU(opcode,0x33);

    signs->WBSel = EQU(opcode,0x03) ? 0x01 :
	   	   EQU(opcode,0x67) ? 0x02 :
		   0x0;
    
    signs->RSel = EQU(funct3,0x2) ? 0xf :
	   	  EQU(funct3,0x4) ? 0x1 :
		  0x0;
    
    signs->WSel = !EQU(opcode,0x23) ? 0x0 :
	   	  EQU(funct3,0x0) ? 0x1 :
		  EQU(funct3,0x2) ? 0xf :
		  0x0; 
}
