#include "alucontrol.h"

ALUControl::ALUControl()
{

}

void ALUControl::connect(AddBranch *addBranch)
{
    this->addBranch = addBranch;
}


void ALUControl::setInstruction(Word instruction)
{
    this->instruction = instruction;
    hasInstruction = true;

    tryExecute();
}

void ALUControl::tryExecute()
{
    if(hasInstruction) {
        execute();

        hasInstruction = false;
    }
}

void ALUControl::execute()
{
    //addBranch->setValueB();
}

ALUControl::~ALUControl()
{

}
