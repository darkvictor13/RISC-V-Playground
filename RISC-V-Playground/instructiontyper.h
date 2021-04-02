/**
  @file instructiontyper.h
  @brief Arquivo que define a classe InstructionTypeR
  @author Victor Emanuel Almeida
  @version 0.1
*/

#ifndef INSTRUCTIONTYPERH
#define INSTRUCTIONTYPERH

#include "instruction.h"

/**
  * @brief Indica o indice do vetor binário em que inicia o
  * a informação de qual é o registrador sorce 2
  */
#define RS2_BEGIN 20

/**
  * @brief Indica o indice do vetor binário em que inicia o
  * a informação de qual é o funct 7 da instrução
  */
#define F7_BEGIN  25

/**
 * @brief A classe InstructionTypeR: Classe que tem como objetivo
 * guardar e operar sobre os valores de uma instrução do tipo R
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

    ~InstructionTypeR();
};

#endif // INSTRUCTIONTYPERH
