/**
 * @file memory.cpp
 * @brief Arquivo responsável por implementar a classe
 * @author mGuerra
 * @version 0.1
*/

#include "muxtypeb.h"

MuxTypeB::MuxTypeB()
{

}

void MuxTypeB::connect(ALU *alu) {
    this->alu = alu;
}

void MuxTypeB::execute()
{
    if(selection == 0)  {
        alu->setValueB(valueA);
    }else{
        alu->setValueB(valueB);
    }
}

MuxTypeB::~MuxTypeB()
{

}
