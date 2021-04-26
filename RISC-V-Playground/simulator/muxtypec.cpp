/**
 * @file muxtypec.cpp
 * @brief Arquivo responsável por implementar a classe MuxTypeC
 * @author mGuerra
 * @version 0.1
*/

#include "muxtypec.h"

/**
 * @brief MuxTypeC::MuxTypeC: Construtor da classe
 */
MuxTypeC::MuxTypeC()
{

}

/**
 * @brief MuxTypeC::connect: Conecta via ponteiro
 * aos elementos necessários para passagem de dados

 * @param Registers registers
 */
void MuxTypeC::connect(Registers *registers)
{
    this->registers = registers;
}

/**
 * @brief MuxTypeC::execute: Realiza todas as ações propostas pela classe
 */
void MuxTypeC::execute()
{
    if(selection == 0)  {
        registers->setWriteData(valueA);
    }else{
        registers->setWriteData(valueB);
    }
}

/**
 * @brief MuxTypeC::~MuxTypeC: Destrutor da classe
 */
MuxTypeC::~MuxTypeC()
{

}
