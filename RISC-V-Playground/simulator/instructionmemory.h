/**
 * @file add.h
 * @brief Arquivo responsável por definir a classe
 * @author mGuerra
 * @version 0.1
*/

#ifndef INSTRUCTIONMEMORY_H
#define INSTRUCTIONMEMORY_H

#include "memory.h"

#include "control.h"
#include "registers.h"
#include "immgen.h"
#include "alucontrol.h"

class Control;
class Registers;
class ImmGen;
class ALUControl;

/**
 * @brief A classe InstructionMemory:
 */
class InstructionMemory : public Memory
{
    Q_OBJECT

private:
    Control *control = NULL;
    Registers *registers = NULL;
    ImmGen *immGen = NULL;
    ALUControl *aluControl = NULL;

    Word address = 0;

    bool hasAddress = false;

public:
    InstructionMemory();

    void connect(Control *control, Registers *registers, ImmGen *immGen, ALUControl *aluControl);

    void setAddress(Word address);

    void tryExecute();
    void execute();

    ~InstructionMemory();

signals:
    void receivedAddress(Word address);

    void executed();

};

#endif // INSTRUCTIONMEMORY_H
