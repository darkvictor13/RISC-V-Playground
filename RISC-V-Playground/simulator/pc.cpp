/**
 * @file memory.cpp
 * @brief Arquivo responsável por implementar a classe
 * @author mGuerra
 * @version 0.1
*/

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

    tryExecute();
}

void PC::restart()
{
    address = 0;
    hasAddress = true;
}

Word PC::getAddress()
{
    return address;
}

void PC::setAddress(Word address)
{
    this->address = address;
    hasAddress = true;

    emit receivedAddress(address.getInteger());
}

void PC::tryExecute()
{
    if(hasAddress && canRun) {
        emit executed();

        hasAddress = false;
        canRun = false;

        execute();
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
