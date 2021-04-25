/**
 * @file instructiontypesb.cpp
 * @brief Arquivo responsável por implementar a classe
 * @author mGuerra
 * @version 0.1
*/

#include "instructionmemory.h"

InstructionMemory::InstructionMemory()
{

}

void InstructionMemory::connect(Control *control, Registers *registers, ImmGen *immGen, ALUControl *aluControl)
{
    this->control = control;
    this->registers = registers;
    this->immGen = immGen;
    this->aluControl = aluControl;
}

void InstructionMemory::setAddress(Word address)
{
    this->address = address;
    hasAddress = true;

    emit receivedAddress(address);

    tryExecute();
}

void InstructionMemory::tryExecute()
{
    if(hasAddress) {
        emit executed();

        hasAddress = false;

        execute();

        address = 0;
    }
}

void InstructionMemory::execute()
{
    Word value = getValue(address);

    control->setOpcode(value.getInteger(0, 6));
    registers->setReadRegister1(value.getInteger(15, 19));
    registers->setReadRegister2(value.getInteger(20, 24));
    registers->setWriteRegister(value.getInteger(7, 11));
    immGen->setInstruction(value);

    Word instruction = (value.getInteger(30, 30) << 3) | value.getInteger(12, 14);

    aluControl->setInstruction(instruction);
}

InstructionMemory::~InstructionMemory()
{

}
