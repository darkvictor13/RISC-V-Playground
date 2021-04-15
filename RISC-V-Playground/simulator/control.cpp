#include "control.h"

Control::Control()
{

}

void Control::connect(AndGate *andGate, DataMemory *dataMemory, MuxTypeB *muxB, MuxTypeC *muxC, ALUControl *aluControl, Registers *registers)
{
    this->andGate = andGate;
    this->dataMemory = dataMemory;
    this->muxB = muxB;
    this->muxC = muxC;
    this->aluControl = aluControl;
    this->registers = registers;
}

void Control::setInstruction(Word instruction)
{
    this->instruction = instruction;
    hasInstruction = true;

    tryExecute();
}

void Control::tryExecute()
{
    if(hasInstruction) {
        execute();

        hasInstruction = false;
    }
}

void Control::execute()
{
    //andGate->setValueA();
    //dataMemory->setMemRead();
    //muxC->setSelection();
    //aluControl->setInstruction();
    //dataMemory->setMemWrite();
    //muxB->selection();
    //registers->setRegWrite();
}

Control::~Control()
{

}
