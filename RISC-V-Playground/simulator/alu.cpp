/**
 * @file instructiontypesb.cpp
 * @brief Arquivo responsável por implementar a classe
 * @author mGuerra
 * @version 0.1
*/

#include "alu.h"

ALU::ALU()
{

}

void ALU::connect(DataMemory *dataMemory, MakeBranch *makeBranch, MuxTypeC *muxC)
{
    this->dataMemory = dataMemory;
    this->makeBranch = makeBranch;
    this->muxC = muxC;
}

void ALU::setValueA(Word valueA)
{
    this->valueA = valueA;
    hasValueA = true;

    emit receivedValueA(valueA);

    tryExecute();
}

void ALU::setValueB(Word valueB)
{
    this->valueB = valueB;
    hasValueB = true;

    emit receivedValueB(valueB);

    tryExecute();
}

void ALU::setControl(Word control)
{
    this->control = control;
    hasControl = true;

    emit receivedControl(control);

    tryExecute();
}

void ALU::setReverse(Word reverse)
{
    this->reverse = reverse;
    hasReverse = true;

    emit receivedReverse(reverse);

    tryExecute();
}

void ALU::tryExecute()
{
    if(hasValueA && hasValueB && hasControl) {
        emit executed();

        hasValueA = false;
        hasValueB = false;
        hasControl = false;
        hasReverse = false;

        execute();

        valueA = 0;
        valueB = 0;
        control = 0;
        reverse = 0;
    }
}

void ALU::execute()
{
    Word result;

    switch (control.getInteger()) {
        case 0: result = valueA & valueB;
            break;
        case 1: result = valueA | valueB;
            break;
        case 2: result = valueA + valueB;
            break;
        case 6: result = valueA - valueB;
            break;
    }

    if((result == 0 && reverse == 0) || (result != 0 && reverse == 1)) {
        makeBranch->setZero(1);
    }else{
        makeBranch->setZero(0);
    }

    dataMemory->setAddress(result);
    muxC->setValueA(result);
}

ALU::~ALU()
{

}
