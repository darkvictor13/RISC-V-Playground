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

class InstructionMemory : public Memory
{
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
};

#endif // INSTRUCTIONMEMORY_H
