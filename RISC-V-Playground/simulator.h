/**
  @file simulator.h
  @brief Arquivo que define a classe Simulator
  @author Victor Emanuel Almeida
  @version 0.1
*/

#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <QFile>
#include <QString>
#include <QTextStream>
#include <istream>

#include "arithmeticlogicunit.h"
#include "instruction.h"
#include "instructiontyper.h"
#include "memory.h"
#include "programcounter.h"
#include "registers.h"

/**
 * @brief A classe Simulator: Classe que tem como objetivo
 * juntar todos os componentes do simulador.
 */
class Simulator
{
private:
    ArithmeticLogicUnit arithmetic_logic_unit;
    Memory memory;
    ProgramCounter program_counter;
public:
    Simulator();

    void writeFileClear(QString filename);
    Instruction * readAssemblyFile();
    void assembly(string filename);

    ~Simulator();
};

#endif // SIMULATOR_H
