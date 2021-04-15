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

void Control::setOpcode(Word opcode)
{
    this->opcode = opcode;
    hasOpcode = true;

    tryExecute();
}

void Control::tryExecute()
{
    if(hasOpcode) {
        execute();

        hasOpcode = false;
    }
}

void Control::execute()
{
    //andGate->setValueA();
    //dataMemory->setMemRead();
    //muxC->setSelection();
    //aluControl->setALUOp();
    //dataMemory->setMemWrite();
    //muxB->selection();
    //registers->setRegWrite();
}

Control::~Control()
{

}
