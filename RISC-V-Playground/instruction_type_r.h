#ifndef INSTRUCTION_TYPE_R_H
#define INSTRUCTION_TYPE_R_H

#include "instruction.h"

#define RS2_BEGIN 20
#define F7_BEGIN  25

class Instruction_Type_R : public Instruction
{
private:
    int reg_src_2;
    int funct_7;
public:
    Instruction_Type_R();
    Instruction_Type_R(int op, int rd, int f3, int rs1, int rs2, int f7);
    bool * instructionToBin();
    void printInfo();
};

#endif // INSTRUCTION_TYPE_R_H
