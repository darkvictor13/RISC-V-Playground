#ifndef ALU_H
#define ALU_H

#include <QObject>

#include "word/word.h"

#include "instructionmemory.h"
#include "andgate.h"
#include "muxtypec.h"

class InstructionMemory;
class AndGate;
class MuxTypeC;

class ALU : public QObject
{
    Q_OBJECT

private:
    InstructionMemory *instructionMemory = NULL;
    AndGate *andGate = NULL;
    MuxTypeC *muxC = NULL;

    Word valueA = 0;
    Word valueB = 0;
    Word control = 0;

    bool hasValueA = false;
    bool hasValueB = false;
    bool hasControl = false;

public:
    ALU();

    void connect(InstructionMemory *instructionMemory, AndGate *andGate, MuxTypeC *muxC);

    void setValueA(Word valueA);
    void setValueB(Word valueB);
    void setControl(Word control);

    void tryExecute();
    void execute();

    ~ALU();

signals:
    void receivedValueA(Word valueA);
    void receivedValueB(Word valueB);
    void receivedControl(Word control);

    void executed();

};

#endif // ALU_H
