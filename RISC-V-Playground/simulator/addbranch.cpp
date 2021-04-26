/**
 * @file addbranch.cpp
 * @brief Arquivo responsável por implementar a classe AddBranch
 * @author mGuerra
 * @version 0.1
*/

#include "addbranch.h"

/**
 * @brief AddBranch::AddBranch: Construtor da classe AddBranch
 */
AddBranch::AddBranch()
{

}

/**
 * @brief AddBranch::connect: Conecta o Multiplexador ao somador
 * @param MuxTypeA muxA: Multiplexador que seleciona entre
 * o valor 4 ou o offset
 */
void AddBranch::connect(MuxTypeA *muxA)
{
    this->muxA = muxA;
}

/**
 * @brief AddBranch::execute: Executa o somador com os valores
 * inseridos
 */
void AddBranch::execute()
{
    Word result = valueA + valueB;

    muxA->setValueB(result);
}

/**
 * @brief AddBranch::~AddBranch: Destrutor da classe AddBranch
 */
AddBranch::~AddBranch()
{

}
