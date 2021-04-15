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

    tryExecute();
}

void ImmGen::tryExecute()
{
    if(hasInstruction) {
        execute();

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
