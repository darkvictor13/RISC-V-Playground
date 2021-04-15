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

    tryExecute();
}

void InstructionMemory::tryExecute()
{
    if(hasAddress) {
        execute();

        hasAddress = false;
    }
}

void InstructionMemory::execute()
{
    Word value = getValue(address).getInteger();

    control->setInstruction(value.getInteger(0, 6));
    registers->setReadRegister1(value.getInteger(15, 19));
    registers->setReadRegister2(value.getInteger(20, 24));
    registers->setWriteRegister(value.getInteger(7, 11));
    immGen->setInstruction(value);

    Word control = (value.test(30) << 3) | value.getInteger(12, 14);

    aluControl->setInstruction(control);
}

InstructionMemory::~InstructionMemory()
{

}
