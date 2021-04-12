/**
  @file arithmeticlogicunit.h
  @brief Arquivo que define a classe ArithmeticLogicUnit
  @author Victor Emanuel Almeida
  @version 0.1
*/

#ifndef ARITHMETICLOGICUNIT_H
#define ARITHMETICLOGICUNIT_H

#include <iostream>
#include "instruction.h"
#include "instructiontyper.h"
#include "instructiontypei.h"
#include "registers.h"

using namespace std;


/**
 * @brief A classe ArithmeticLogicUnit: Classe que tem como objetivo
 * simular o comportamento de uma unidade lógica e aritimética
 */
class ArithmeticLogicUnit
{
private:
    Registers registers;
    int op;
    int src1;
    int src2;
public:
    int operate(Instruction * instruction);
    int operate();

    ArithmeticLogicUnit();
    ~ArithmeticLogicUnit();
};

#endif // ARITHMETICLOGICUNIT_H
