/**
  @file instructiontyper.h
  @brief Arquivo que define a classe InstructionTypeR
  @author Victor Emanuel Almeida
  @version 0.1
*/

#ifndef INSTRUCTIONTYPERH
#define INSTRUCTIONTYPERH

#include "instruction.h"

#define RS2_BEGIN 20
#define F7_BEGIN  25

/**
 * @brief A classe InstructionTypeR:
 */
class InstructionTypeR : public Instruction
{
private:
    int reg_src_2;
    int funct_7;
public:
    InstructionTypeR();
    InstructionTypeR(int op, int rd, int f3, int rs1, int rs2, int f7);
    bool * instructionToBin();
    void printInfo();
};

#endif // INSTRUCTIONTYPERH
