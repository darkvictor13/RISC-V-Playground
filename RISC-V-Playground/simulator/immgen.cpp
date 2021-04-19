#include "immgen.h"

ImmGen::ImmGen()
{

}

void ImmGen::connect(AddBranch *addBranch, MuxTypeB *muxB)
{
    this->addBranch = addBranch;
    this->muxB = muxB;
}

void ImmGen::setInstruction(Word instruction)
{
    this->instruction = instruction;
    hasInstruction = false;

    emit receivedInstruction(instruction);

    tryExecute();
}

void ImmGen::tryExecute()
{
    if(hasInstruction) {
        execute();

        emit executed();

        hasInstruction = false;
    }
}

void ImmGen::execute()
{
    //muxB->setValueB();
}

ImmGen::~ImmGen()
{

}
