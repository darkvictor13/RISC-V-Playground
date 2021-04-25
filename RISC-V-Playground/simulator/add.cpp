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
        emit executed();

        hasValueA = false;
        hasValueB = false;

        execute();

        valueA = 0;
        valueB = 0;
    }
}

Add::~Add()
{

}
