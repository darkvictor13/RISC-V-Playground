/**
 * @file memory.cpp
 * @brief Arquivo responsável por implementar a classe
 * @author mGuerra
 * @version 0.1
*/

#include "muxtypec.h"

MuxTypeC::MuxTypeC()
{

}

void MuxTypeC::connect(Registers *registers)
{
    this->registers = registers;
}

void MuxTypeC::execute()
{
    if(selection == 0)  {
        registers->setWriteData(valueA);
    }else{
        registers->setWriteData(valueB);
    }
}

MuxTypeC::~MuxTypeC()
{

}
