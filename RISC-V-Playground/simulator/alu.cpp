#include "alu.h"

ALU::ALU()
{

}

void ALU::connect(InstructionMemory *instructionMemory, AndGate *andGate, MuxTypeC *muxC)
{
    this->instructionMemory =instructionMemory;
    this->andGate = andGate;
    this->muxC = muxC;
}

void ALU::setValueA(Word valueA)
{
    this->valueA = valueA;
    hasValueA = true;

    tryExecute();
}

void ALU::setValueB(Word valueB)
{
    this->valueB = valueB;
    hasValueB = true;

    tryExecute();
}

void ALU::setControl(Word control)
{
    this->control = control;
    hasControl = true;

    tryExecute();
}

void ALU::tryExecute()
{
    if(hasValueA && hasValueB && hasControl) {
        execute();

        hasValueA = false;
        hasValueB = false;
        hasControl = false;
    }
}

void ALU::execute()
{
    //andGate->setValueB();
    //instructionMemory->setAddress();
    //muxC->setValueA();
}

ALU::~ALU()
{

}