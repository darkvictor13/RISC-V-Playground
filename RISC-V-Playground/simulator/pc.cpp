#include "pc.h"

PC::PC()
{

}

void PC::connect(InstructionMemory *instructionMemory, AddBranch *addBranch, AddNext *addNext)
{
    this->instructionMemory = instructionMemory;
    this->addBranch = addBranch;
    this->addNext = addNext;
}

void PC::run()
{
    canRun = true;
}

void PC::setAddress(Word address)
{
    this->address = address;
    hasAddress = true;

    tryExecute();
}

void PC::tryExecute()
{
    if(hasAddress && canRun) {
        execute();

        hasAddress = false;
        canRun = false;
    }
}

void PC::execute()
{
    instructionMemory->setAddress(address);
    addNext->setValueA(address);
    addNext->setValueB(4);
    addBranch->setValueA(address);
}

PC::~PC()
{

}
