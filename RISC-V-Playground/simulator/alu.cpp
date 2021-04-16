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
    Word result;

    switch (control.getInteger()) {
        case 0: result = valueA & valueB;
            break;
        case 1: result = valueA | valueB;
            break;
        case 2: result = valueA + valueB;
            break;
        case 6: result = valueA - valueB;
            break;
    }

    andGate->setZero(result);
    instructionMemory->setAddress(result);
    muxC->setValueA(result);
}

ALU::~ALU()
{

}
