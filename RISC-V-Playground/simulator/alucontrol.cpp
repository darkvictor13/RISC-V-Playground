#include "alucontrol.h"

ALUControl::ALUControl()
{

}

void ALUControl::connect(ALU *alu)
{
    this->alu = alu;
}

void ALUControl::setInstruction(Word instruction)
{
    this->instruction = instruction;
    hasInstruction = true;

    emit receivedInstruction(instruction);

    tryExecute();
}

void ALUControl::setALUOp(Word aluOp)
{
    this->aluOp = aluOp;
    hasALUOp = true;

    emit receivedALUOp(aluOp);

    tryExecute();
}

void ALUControl::tryExecute()
{
    if(hasALUOp && hasInstruction) {
        emit executed();

        hasInstruction = false;
        hasALUOp = false;

        execute();

        instruction = 0;
        aluOp = 0;
    }
}

void ALUControl::execute()
{
    alu->setReverse(instruction.getInteger(0, 0));

    if(aluOp == 0) {
        alu->setControl(2);
        return;
    }

    if(aluOp == 1) {
        alu->setControl(6);
        return;
    }

    if(aluOp == 2) {
        if(instruction == 0) {
            alu->setControl(2);
            return;
        }

        if(instruction == 6) {
            alu->setControl(1);
            return;
        }

        if(instruction == 7) {
            alu->setControl(0);
            return;
        }

        if(instruction == 8) {
            alu->setControl(6);
            return;
        }
    }
}

ALUControl::~ALUControl()
{

}
