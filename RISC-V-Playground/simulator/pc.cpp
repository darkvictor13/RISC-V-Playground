/**
 * @file pc.cpp
 * @brief Arquivo responsável por implementar a classe PC
 * @author mGuerra
 * @version 0.1
*/

#include "pc.h"

/**
 * @brief PC::PC: Construtor da classe
 */
PC::PC()
{

}

/**
 * @brief PC::connect: Conecta via ponteiro
 * aos elementos necessários para passagem de dados

 * @param InstructionMemory instructionMemory
 * @param AddBranch addBranch
 * @param AddNext addNext
 */
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

/**
 * @brief PC::tryExecute: Tenta alterar o valor de Pc
 *
 * @warning Executa apenas quando Possui todos os valores

 */
void PC::tryExecute()
{
    if(hasAddress && canRun) {
        emit executed();

        hasAddress = false;
        canRun = false;

        execute();
    }
}

/**
 * @brief PC::execute: Realiza todas as ações propostas pela classe
 */
void PC::execute()
{
    instructionMemory->setAddress(address);
    addNext->setValueA(address);
    addNext->setValueB(4);
    addBranch->setValueA(address);
}

/**
 * @brief PC::~PC: Destrutor da classe
 */
PC::~PC()
{

}
