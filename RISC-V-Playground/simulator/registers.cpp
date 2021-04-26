/**
 * @file registers.cpp
 * @brief Arquivo responsável por implementar a classe Registers
 * @author mGuerra
 * @version 0.1
*/

#include "registers.h"

/**
 * @brief Registers::Registers: Construtor da classe
 */
Registers::Registers()
{

}

void Registers::init()
{
    for(int i = 0; i < REGISTERS_SPACE; i++) {
        registers[i].reset();
    }

    emit initRegisters(REGISTERS_SPACE);
}

void Registers::setValue(Word value, Word registerIndex)
{
    registers[registerIndex.getInteger()].set(value);

    emit updateRegister(value, registerIndex);
}

Word Registers::getValue(Word registerIndex)
{
    return registers[registerIndex.getInteger()];
}

void Registers::restart()
{
    for(int i = 0; i < REGISTERS_SPACE; i++) {
        registers[i].reset();
    }

    emit restartRegisters();
}

/**
 * @brief Registers::connect: Conecta via ponteiro
 * aos elementos necessários para passagem de dados

 * @param ALU alu
 * @param MuxTypeB muxB
 * @param DataMemory dataMemory
 */
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

    emit receivedReadRegister1(readRegister1);

    tryExecute();
}

void Registers::setReadRegister2(Word readRegister2)
{
    this->readRegister2 = readRegister2;
    hasReadRegister2 = true;

    emit receivedReadRegister2(readRegister2);

    tryExecute();
}

void Registers::setWriteRegister(Word writeRegister)
{
    this->writeRegister = writeRegister;
    hasWriteRegister = true;

    emit receivedWriteRegister(writeRegister);

    tryExecute();
}

void Registers::setWriteData(Word writeData)
{
    this->writeData = writeData;
    hasWriteData = true;

    emit receivedWriteData(writeData);

    tryExecute();
}

void Registers::setRegWrite(Word regWrite)
{
    this->regWrite = regWrite;
    hasRegWrite = true;

    emit receivedRegWrite(regWrite);

    tryExecute();
}

/**
 * @brief Registers::tryExecute: Tenta Executar o subcircuito
 *
 * @warning Executa apenas quando Possui todos os valores

 */
void Registers::tryExecute()
{
    if(hasReadRegister1 && hasReadRegister2 && hasWriteRegister) {
        emit executedRead();

        hasReadRegister1 = false;
        hasReadRegister2 = false;
        hasWriteRegister = false;

        executeRead();
    }

    if(hasWriteData && hasRegWrite) {
        emit executedWrite();

        hasWriteData = false;
        hasRegWrite = false;

        executeWrite();

        writeData = 0;
        regWrite = 0;
    }
}

void Registers::executeRead()
{
    alu->setValueA(getValue(readRegister1));
    muxB->setValueA(getValue(readRegister2));
    dataMemory->setWriteData(getValue(readRegister2));
}

void Registers::executeWrite()
{
    if(regWrite == 1) {
        setValue(writeData, writeRegister);
    }
}

/**
 * @brief Registers::~Registers: Destrutor da classe
 */
Registers::~Registers()
{

}
