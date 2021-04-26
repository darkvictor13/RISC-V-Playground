/**
 * @file addnext.cpp
 * @brief Arquivo responsável por implementar a classe AddNext
 * @author mGuerra
 * @version 0.1
*/

#include "addnext.h"

/**
 * @brief AddNext::AddNext: Destrutor da classe AddNext
 */
AddNext::AddNext()
{

}

/**
 * @brief AddNext::connect: Conecta o Multiplexador ao somador
 * @param muxA: Multiplexador que seleciona entre
 * o valor 4 ou o offset
 */
void AddNext::connect(MuxTypeA *muxA)
{
    this->muxA = muxA;
}

/**
 * @brief AddBranch::execute: Executa o somador com os valores
 * inseridos
 */
void AddNext::execute()
{
    Word result = valueA + valueB;

    muxA->setValueA(result);
}

/**
 * @brief AddNext::~AddNext: Destrutor da classe AddNext
 */
AddNext::~AddNext()
{

}
