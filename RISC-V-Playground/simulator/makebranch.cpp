/**
 * @file makebranch.cpp
 * @brief Arquivo responsável por implementar a classe MakeBranch
 * @author mGuerra
 * @version 0.1
*/

#include "makebranch.h"

/**
 * @brief MakeBranch::MakeBranch(): Construtor da classe
 */
MakeBranch::MakeBranch()
{

}

/**
 * @brief MakeBranch::connect: Conecta via ponteiro
 * aos elementos necessários para passagem de dados

 * @param MuxTypeA muxA
 */
void MakeBranch::connect(MuxTypeA *muxA)
{
    this->muxA = muxA;
}

void MakeBranch::setBranch(Word branch)
{
    this->branch = branch;
    hasBranch = true;

    emit receivedBransh(branch);

    tryExecute();
}

void MakeBranch::setZero(Word zero)
{
    this->zero = zero;
    hasZero = true;

    emit receivedZero(zero);

    tryExecute();
}

/**
 * @brief MakeBranch::tryExecute: Tenta Executar o subcircuito
 *
 * @warning Executa apenas quando Possui todos os valores

 */
void MakeBranch::tryExecute()
{
    if(hasBranch && hasZero) {
        emit executed();

        hasBranch = false;
        hasZero = false;

        execute();

        branch = 0;
        zero = 0;
    }
}

/**
 * @brief MakeBranch::execute: Realiza todas as ações propostas pela classe
 */
void MakeBranch::execute()
{
    if(branch == 1 && zero == 1) {
        muxA->setSelection(1);
    }else{
        muxA->setSelection(0);
    }
}

/**
 * @brief MakeBranch::~MakeBranch: Destrutor da classe
 */
MakeBranch::~MakeBranch()
{

}
