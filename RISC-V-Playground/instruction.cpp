#include "instruction.h"

Instruction::Instruction()
{
    this->opcode    = 0;
    this->reg_dest  = 0;
    this->funct_3   = 0;
    this->reg_src_1 = 0;
}

int Instruction::getOpcode()
{
    return this->opcode;
}

int Instruction::getRegDest()
{
    return this->reg_dest;
}

int Instruction::getFunc3()
{
    return this->funct_3;
}

int Instruction::getRegSrc1()
{
    return this->reg_src_1;
}

Instruction::Instruction(int op, int rd, int f3, int rs1)
{
    this->opcode    = op;
    this->reg_dest  = rd;
    this->funct_3   = f3;
    this->reg_src_1 = rs1;
}
