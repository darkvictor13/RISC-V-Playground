#include "alucontrol.h"

ALUControl::ALUControl()
{

}

void ALUControl::connect(ALU *alu)
{
    this->alu = alu;
}

void ALUControl::setALUOp(Word instruction)
{
    this->aluOp = instruction;
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
    if(aluOp == 0) {
        alu->setControl(2);
    }

    if(aluOp.test(0)) {
        alu->setControl(6);
    }

    ///////////////////////////
}

ALUControl::~ALUControl()
{

}
