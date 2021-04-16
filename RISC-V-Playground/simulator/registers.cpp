/**
 * @file registers.cpp
 * @brief
 * @author mGuerra
 * @version 0.1
*/

#include "registers.h"

#include <stdint.h>

#define REGISTERS_SPACE 32

Registers::Registers()
{

}

void Registers::initRegisters()
{
    for(int i = 0; i < REGISTERS_SPACE; i++) {
        registers[i].reset();
    }
}

void Registers::setValue(Word value, Word registerIndex)
{
    registers[registerIndex.getInteger()].set(value);
}

Word Registers::getValue(Word registerIndex)
{
    return registers[registerIndex.getInteger()];
}

void Registers::connect(ALU *alu, MuxTypeB *muxB, DataMemory *dataMemory)
{
    this->alu = alu;
    this->muxB = muxB;
    this->dataMemory = dataMemory;
}

void Registers::setReadRegister1(Word readRegister1)
{
    this->readRegister1 = readRegister1;
    hasReadRegister1 = true;

    tryExecute();
}

void Registers::setReadRegister2(Word readRegister2)
{
    this->readRegister2 = readRegister2;
    hasReadRegister2 = true;

    tryExecute();
}

void Registers::setWriteRegister(Word writeRegister)
{
    this->writeRegister = writeRegister;
    hasWriteRegister = true;

    tryExecute();
}

void Registers::setWriteData(Word writeData)
{
    this->writeData = writeData;
    hasWriteData = true;

    tryExecute();
}

void Registers::setRegWrite(Word regWrite)
{
    this->regWrite = regWrite;
    hasRegWrite = true;

    tryExecute();
}

void Registers::tryExecute()
{
    if(hasReadRegister1 && hasReadRegister2 && hasWriteRegister && hasRegWrite) {
        execute();

        hasReadRegister1 = false;
        hasReadRegister2 = false;
        hasWriteRegister = false;
        hasRegWrite = false;
    }

    if(hasWriteData && regWrite == 1) {
        dataMemory->setWriteData(getValue(readRegister2));
        hasWriteData = false;
    }
}

void Registers::execute()
{
    alu->setValueA(getValue(readRegister1));
    muxB->setValueA(getValue(readRegister2));

    if(regWrite == 1) {
        dataMemory->setWriteData(getValue(readRegister2));
    }
}

Registers::~Registers()
{

}
