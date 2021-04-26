/**
 * @file muxtypea.cpp
 * @brief Arquivo responsável por implementar a classe MuxTypeA
 * @author mGuerra
 * @version 0.1
*/

#include "muxtypea.h"

/**
 * @brief MuxTypeA::MuxTypeA: Construtor da classe
 */
MuxTypeA::MuxTypeA()
{

}

/**
 * @brief MuxTypeA::connect: Conecta via ponteiro
 * aos elementos necessários para passagem de dados

 * @param PC pc
 */
void MuxTypeA::connect(PC *pc)
{
    this->pc = pc;
}

/**
 * @brief MuxTypeA::execute: Realiza todas as ações propostas pela classe
 */
void MuxTypeA::execute()
{
    if(selection == 0)  {
        pc->setAddress(valueA);
    }else{
        pc->setAddress(valueB);
    }
}

/**
 * @brief MuxTypeA::~MuxTypeA: Destrutor da classe
 */
MuxTypeA::~MuxTypeA()
{

}
