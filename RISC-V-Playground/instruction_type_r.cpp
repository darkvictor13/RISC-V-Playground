#include "instruction_type_r.h"

Instruction_Type_R::Instruction_Type_R() : Instruction()
{
    this->funct_7   = 0;
    this->reg_src_2 = 0;
}

Instruction_Type_R::Instruction_Type_R(int op, int rd, int f3, int rs1, int rs2, int f7)
    : Instruction(op, rd, f3, rs1)
{
    this->funct_7   = f7;
    this->reg_src_2 = rs2;
}


void Instruction_Type_R::printInfo()
{
    cout << "So p ver se compila\n\n";
    cout << "Opcode              = " << this->getOpcode()  << endl;
    cout << "Registrador destino = " << this->getRegDest() << endl;
    cout << "Funct 3             = " << this->getFunc3()   << endl;
    cout << "Registrador sorce 1 = " << this->getRegSrc1() << endl;
    cout << "Registrador sorce 2 = " << this->reg_src_2    << endl;
    cout << "Funct 7             = " << this->funct_7      << endl;
}
