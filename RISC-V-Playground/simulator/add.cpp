#include "add.h"

Add::Add()
{

}

void Add::setValueA(Word valueA)
{
    this->valueA = valueA;
    hasValueA = true;

    emit receivedValueA(valueA);

    tryExecute();
}

void Add::setValueB(Word valueB)
{
    this->valueB = valueB;
    hasValueB = true;

    emit receivedValueB(valueB);

    tryExecute();
}

void Add::tryExecute()
{
    if(hasValueA && hasValueB) {
        execute();

        emit executed();

        hasValueA = false;
        hasValueB = false;
    }
}

Add::~Add()
{

}
