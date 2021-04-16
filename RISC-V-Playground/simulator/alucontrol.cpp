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

    tryExecute();
}

void ALUControl::setALUOp(Word aluOp)
{
    this->aluOp = aluOp;
    hasALUOp = true;

    tryExecute();
}

void ALUControl::tryExecute()
{
    if(hasALUOp) {
        execute();

        hasALUOp = false;
    }
}

void ALUControl::execute()
{
    if(aluOp.test(1) && instruction == 7) {
        alu->setControl(0);
        return;
    }

    if(aluOp.test(1) && instruction == 6) {
        alu->setControl(1);
        return;
    }

    if(aluOp == 0 || (aluOp.test(1) && instruction == 0)) {
        alu->setControl(2);
        return;
    }

    if(aluOp.test(0) || (aluOp.test(1) && instruction == 8)) {
        alu->setControl(6);
        return;
    }
}

ALUControl::~ALUControl()
{

}
