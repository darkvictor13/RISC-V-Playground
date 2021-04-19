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

    emit receivedOpcode(opcode);

    tryExecute();
}

void Control::tryExecute()
{
    if(hasOpcode) {
        execute();

        emit executed();

        hasOpcode = false;
    }
}

void Control::execute()
{
    if(opcode == 3) { // lw

        andGate->setBranch(0);
        dataMemory->setMemRead(1);
        muxC->setSelection(1);
        aluControl->setALUOp(0);
        dataMemory->setMemWrite(0);
        muxB->setSelection(1);
        registers->setRegWrite(1);

        return;
    }

    if(opcode == 19) { // addi

        andGate->setBranch(0);
        dataMemory->setMemRead(0);
        muxC->setSelection(0);
        aluControl->setALUOp(2);
        dataMemory->setMemWrite(0);
        muxB->setSelection(1);
        registers->setRegWrite(1);

        return;
    }

    if(opcode == 35) { // sw

        andGate->setBranch(0);
        dataMemory->setMemRead(0);
        aluControl->setALUOp(0);
        dataMemory->setMemWrite(1);
        muxB->setSelection(1);
        registers->setRegWrite(0);

        return;
    }

    if(opcode == 51) { // type-R

        andGate->setBranch(0); //  Branch
        dataMemory->setMemRead(0); // MemRead
        muxC->setSelection(0); // MemToReg
        aluControl->setALUOp(2); // ALUOp
        dataMemory->setMemWrite(0); // MemWrite
        muxB->setSelection(0); // ALUSrc
        registers->setRegWrite(1); // RegWrite

        return;
    }

    if(opcode == 99) { // beq, bne

        andGate->setBranch(1);
        dataMemory->setMemRead(0);
        aluControl->setALUOp(1);
        dataMemory->setMemWrite(0);
        muxB->setSelection(0);
        registers->setRegWrite(0);

        return;
    }
}

Control::~Control()
{

}
