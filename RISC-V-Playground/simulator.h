/**
  @file simulator.h
  @brief Arquivo que define a classe Simulator
  @author Victor Emanuel Almeida
  @version 0.1
*/

#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "arithmeticlogicunit.h"
#include "instruction.h"
#include "instructiontyper.h"
#include "memory.h"
#include "programcounter.h"
#include "registers.h"

/**
 * @brief A classe Simulator:
 */
class Simulator
{
private:
    ArithmeticLogicUnit arithmetic_logic_unit;
    Memory memory;
    ProgramCounter program_counter;
    Registers registers;

public:
    Simulator();
    ~Simulator();
};

#endif // SIMULATOR_H
