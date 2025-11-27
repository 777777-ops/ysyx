#include <regfile.h>

static uint32_t regs[32];

uint32_t* tp = &regs[4];

uint32_t read_reg(uint8_t rs){
    return regs[rs];
}

void write_reg(uint32_t data, uint8_t ds){
    if(ds != 0x0)
    	regs[ds] = data;
}
