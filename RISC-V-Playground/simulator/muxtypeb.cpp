/**
 * @file muxtypeb.cpp
 * @brief Arquivo responsável por implementar a classe MuxTypeB
 * @author mGuerra
 * @version 0.1
*/

#include "muxtypeb.h"

/**
 * @brief MuxTypeB::MuxTypeB: Construtor da classe
 */
MuxTypeB::MuxTypeB()
{

}

/**
 * @brief MuxTypeB::connect: Conecta via ponteiro
 * aos elementos necessários para passagem de dados

 * @param ALU alu
 */
void MuxTypeB::connect(ALU *alu) {
    this->alu = alu;
}

/**
 * @brief MuxTypeB::execute: Realiza todas as ações propostas pela classe
 */
void MuxTypeB::execute()
{
    if(selection == 0)  {
        alu->setValueB(valueA);
    }else{
        alu->setValueB(valueB);
    }
}

/**
 * @brief MuxTypeB::~MuxTypeB: Destrutor da classe
 */
MuxTypeB::~MuxTypeB()
{

}
