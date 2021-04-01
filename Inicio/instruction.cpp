#include "instruction.hpp"

Instruction::Instruction() {
    this->opcode = 0;
    this->reg_dest = 0;
    this->funct3 = 0;
    this->reg_src1 = 0;
}

Instruction::Instruction(int o, int rd, int f3, int rs1){
    this->opcode = o;
    this->reg_dest = rd;
    this->funct3 = f3;
    this->reg_src1 = rs1;
}

int Instruction::getOpcode() {
    return this->opcode;
}
