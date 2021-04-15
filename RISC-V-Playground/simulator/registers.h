/**
 * @file registers.h
 * @brief
 * @author mGuerra
 * @version 0.1
*/

#ifndef REGISTERS_H
#define REGISTERS_H

#define REGISTERS_SPACE 32

#include "word/word.h"

#include "alu.h"
#include "muxtypeb.h"
#include "datamemory.h"

class ALU;
class MuxTypeB;
class DataMemory;

class Registers
{
private:
    Word registers[REGISTERS_SPACE];

    ALU *alu = NULL;
    MuxTypeB *muxB = NULL;
    DataMemory *dataMemory = NULL;

    Word readRegister1 = 0;
    Word readRegister2 = 0;
    Word writeRegister = 0;
    Word writeData = 0;
    Word regWrite = 0;

    bool hasReadRegister1 = 0;
    bool hasReadRegister2 = 0;
    bool hasWriteRegister = 0;
    bool hasWriteData = 0;
    bool hasRegWrite = 0;

public:
    Registers();

    void initRegisters();

    void setValue(Word value, Word registerIndex);
    Word getValue(Word registerIndex);

    void connect(ALU *alu, MuxTypeB *muxB, DataMemory *dataMemory);

    void setReadRegister1(Word readRegister1);
    void setReadRegister2(Word readRegister2);
    void setWriteRegister(Word writeRegister);
    void setWriteData(Word writeData);
    void setRegWrite(Word regWrite);

    void tryExecute();
    void execute();

    ~Registers();
};

#endif // REGISTERS_H
