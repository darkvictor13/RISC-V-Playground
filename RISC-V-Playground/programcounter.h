/**
  @file programcounter.h
  @brief Arquivo que define a classe ProgramCounter
  @author Victor Emanuel Almeida
  @version 0.1
*/

#ifndef PROGRAMCOUNTER_H
#define PROGRAMCOUNTER_H

#include <iostream>
#include "instruction.h"
#include "instructiontypei.h"
#include "instructiontyper.h"

using namespace std;

/**
 * @brief A classe ProgramCounter: Classe que tem como objetivo
 * simular o comportamento do program counter, buscando as instruções
 */
class ProgramCounter
{
private:
    int qnt_instructions;
    int actual_instruction;
    Instruction *vectorProgram;
public:
    ProgramCounter();
    ~ProgramCounter();
};

#endif // PROGRAMCOUNTER_H
