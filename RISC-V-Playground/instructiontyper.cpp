#include "instructiontyper.h"

InstructionTypeR::InstructionTypeR() : Instruction()
{
    this->funct_7   = 0;
    this->reg_src_2 = 0;
}

InstructionTypeR::InstructionTypeR(int op, int rd, int f3, int rs1, int rs2, int f7)
    : Instruction(op, rd, f3, rs1)
{
    this->funct_7   = f7;
    this->reg_src_2 = rs2;
}

bool * InstructionTypeR::instructionToBin()
{
   bool *resp = (bool*)malloc(32 * sizeof(bool));
   *resp = {0};

   int casa_atual;
   int num = this->getOpcode();
   for(casa_atual = OP_BEGIN; casa_atual < RD_BEGIN; casa_atual++) {
       resp[casa_atual] = num % 2;
       num /= 2;
   }

   for(num = this->getRegDest(); casa_atual < F3_BEGIN; casa_atual++) {
       resp[casa_atual] = num % 2;
       num /= 2;
   }

   for(num = this->getFunc3(); casa_atual < RS1_BEGIN; casa_atual++) {
       resp[casa_atual] = num % 2;
       num /= 2;
   }

   for(num = this->getRegSrc1(); casa_atual < RS2_BEGIN; casa_atual++) {
       resp[casa_atual] = num % 2;
       num /= 2;
   }

   for(num = this->reg_src_2; casa_atual < F7_BEGIN; casa_atual++) {
       resp[casa_atual] = num % 2;
       num /= 2;
   }

   for(num = this->funct_7; casa_atual < INSTRUCTION_SIZE; casa_atual++) {
       resp[casa_atual] = num % 2;
       num /= 2;
   }

   return resp;
}

void InstructionTypeR::printInfo()
{
    cout << "So p ver se compila\n\n";
    cout << "Opcode              = " << this->getOpcode()  << endl;
    cout << "Registrador destino = " << this->getRegDest() << endl;
    cout << "Funct 3             = " << this->getFunc3()   << endl;
    cout << "Registrador sorce 1 = " << this->getRegSrc1() << endl;
    cout << "Registrador sorce 2 = " << this->reg_src_2    << endl;
    cout << "Funct 7             = " << this->funct_7      << endl;
}
