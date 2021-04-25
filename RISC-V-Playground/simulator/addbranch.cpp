/**
 * @file instructiontypesb.cpp
 * @brief Arquivo responsável por implementar a classe
 * @author mGuerra
 * @version 0.1
*/

#include "addbranch.h"

AddBranch::AddBranch()
{

}

void AddBranch::connect(MuxTypeA *muxA)
{
    this->muxA = muxA;
}

void AddBranch::execute()
{
    Word result = valueA + valueB;

    muxA->setValueB(result);
}

AddBranch::~AddBranch()
{

}
