#include "add.h"

Add::Add()
{

}

void Add::setValueA(Word valueA)
{
    this->valueA = valueA;
    hasValueA = true;

    tryExecute();
}

void Add::setValueB(Word valueB)
{
    this->valueB = valueB;
    hasValueB = true;

    tryExecute();
}

void Add::tryExecute()
{
    if(hasValueA && hasValueB) {
        execute();

        hasValueA = false;
        hasValueB = false;
    }
}

Add::~Add()
{

}
