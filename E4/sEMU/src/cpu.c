#include"control.h"
#include"immSel.h"
#include"memory.h"
#include"regfile.h"
#include"rom.h"


uint32_t pc;        //pc
uint32_t inst;
uint32_t result;   //运算结果
uint8_t rs1,rs2,rd;
uint32_t reg_read1,reg_read2,reg_write;
uint32_t imm;

struct signs sign;

//解析指令中的寄存器信息,顺带提取
static void parse_reg(){
    rd  = (inst >> 7)  & 0x1F;  // 位11-7
    rs1 = (inst >> 15) & 0x1F;  // 位19-15
    rs2 = (inst >> 20) & 0x1F;  // 位24-20
 
    reg_read1 = read_reg(rs1);
    reg_read2 = read_reg(rs2);
}

static void check_end(){
    uint32_t end_flag = read_reg(0xa);
    if(!end_flag)
        printf("HIT GOOD TRAP\n");  // 成功结束
    else
        printf("HIT BAD TRAP\n");   // 错误结束
    
}

//主循环
bool cycle(){
   //取指
   inst = get_inst(pc);

   //ebreak
   if(EQU(inst,0x00100073)){
   	check_end();
	return false;
   }

   //解析
   parse_reg();
   parse_inst(inst, &sign);
   imm = get_imm(inst, sign.ImmSel);
   //运行
   result = reg_read1 + (sign.BSel ? reg_read2 : imm);

   reg_write = EQU(sign.WBSel,0) ? result :
               EQU(sign.WBSel,1) ? read_mem(result, sign.RSel) :
   	       EQU(sign.WBSel,2) ? (uint32_t)(pc + 4) : 0x0;



   //写回寄存器
   if(sign.RegWEn)
	write_reg(reg_write, rd);
   //写回内存
   if(sign.WSel)
	write_mem(result, sign.WSel, reg_read2);

   pc = sign.PCSel ? result : pc + 4;
   return true;
}

