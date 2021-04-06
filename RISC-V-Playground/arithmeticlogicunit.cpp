/**
  @file arithmeticlogicunit.cpp
  @brief Arquivo que implementa os métodos da classe ArithmeticLogicUnit
  @author Victor Emanuel Almeida
  @version 0.1
*/

#include "arithmeticlogicunit.h"

/**
 * @brief Contrutor da classe ArithmeticLogicUnit
 */
ArithmeticLogicUnit::ArithmeticLogicUnit()
{
    cout << "Criando a classe ALU" << endl;
}

/**
 * @brief Destrutor da classe ArithmeticLogicUnit
 */
ArithmeticLogicUnit::~ArithmeticLogicUnit()
{
    cout << "Destruindo a classe ALU" << endl;
}


int ArithmeticLogicUnit::operate(Instruction * instruction)
{
    int op = instruction->getOpcode();
    if(op == ADDI_OPCODE) {
        return 1;
    }else if (op == BEQ_OPCODE) {
        if (instruction->getFunc3() == BEQ_FUNCT_3) {

        }else {

        }
        // da para fazer em uma operacao so
        return 2;
    }else {
        int f3 = instruction->getFunc3();
        if(f3 == OR_FUNCT_3) {

        }else if (f3 == AND_FUNCT_3) {

        }else {
            // dar um jeito de operar sobre soma e subtracao
        }
        return 3;
    }
}
