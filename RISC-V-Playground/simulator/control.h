#ifndef CONTROL_H
#define CONTROL_H

#include <QObject>

#include "word/word.h"

#include "makebranch.h"
#include "datamemory.h"
#include "muxtypeb.h"
#include "muxtypec.h"
#include "alucontrol.h"
#include "registers.h"

class MakeBranch;
class DataMemory;
class MuxTypeB;
class MuxTypeC;
class ALUControl;
class Registers;

class Control : public QObject
{
    Q_OBJECT

private:
    MakeBranch *makeBranch = NULL;
    DataMemory *dataMemory = NULL;
    MuxTypeB *muxB = NULL;
    MuxTypeC *muxC = NULL;
    ALUControl *aluControl = NULL;
    Registers *registers = NULL;

    Word opcode = 0;

    bool hasOpcode = false;

public:
    Control();

    void connect(MakeBranch *makeBranch, DataMemory *dataMemory, MuxTypeB *muxB, MuxTypeC *muxC, ALUControl *aluControl, Registers *registers);

    void setOpcode(Word opcode);

    void tryExecute();
    void execute();

    ~Control();

signals:
    void receivedOpcode(Word opcode);

    void executed();

};

#endif // CONTROL_H
