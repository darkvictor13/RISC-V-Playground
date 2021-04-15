#ifndef CONTROL_H
#define CONTROL_H

#include "word/word.h"

#include "andgate.h"
#include "datamemory.h"
#include "muxtypeb.h"
#include "muxtypec.h"
#include "alucontrol.h"
#include "registers.h"

class AndGate;
class DataMemory;
class MuxTypeB;
class MuxTypeC;
class ALUControl;
class Registers;

class Control
{
private:
    AndGate *andGate = NULL;
    DataMemory *dataMemory = NULL;
    MuxTypeB *muxB = NULL;
    MuxTypeC *muxC = NULL;
    ALUControl *aluControl = NULL;
    Registers *registers = NULL;

    Word instruction = 0;

    bool hasInstruction = false;

public:
    Control();

    void connect(AndGate *andGate, DataMemory *dataMemory, MuxTypeB *muxB, MuxTypeC *muxC, ALUControl *aluControl, Registers *registers);

    void setInstruction(Word instruction);

    void tryExecute();
    void execute();

    ~Control();
};

#endif // CONTROL_H
