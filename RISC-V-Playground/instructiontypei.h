#ifndef INSTRUCTIONTYPEI_H
#define INSTRUCTIONTYPEI_H

#include "instruction.h"

#define ADDI_OPCODE 19
#define ADDI_FUNCT_3 6

/**
  * @brief Indica o indice do vetor binário em que inicia o
  * a informação de qual é o imediato
  */
#define IMEDIATE_BEGIN 20

class InstructionTypeI : public Instruction
{
private:
    int imediate;
public:
    InstructionTypeI();
    InstructionTypeI(int op, int rd, int f3, int rs1, int imm);

    void printInfo();
    bool * instructionToBin();

    ~InstructionTypeI();
};

#endif // INSTRUCTIONTYPEI_H
