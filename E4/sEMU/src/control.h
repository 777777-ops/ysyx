#ifndef CONTROL_H
#define CONTROL_H

#include <stdbool.h>
#include <stdint.h>

#define EQU(A,B) !(A ^ B)

struct signs{
    bool PCSel;
    bool RegWEn;
    uint8_t ImmSel;//2
    bool BSel;
    uint8_t WBSel; //2
    uint8_t WSel;  //4
    uint8_t RSel;  //4
    bool Zero;
};


void parse_inst(uint32_t inst, struct signs*);


#endif
