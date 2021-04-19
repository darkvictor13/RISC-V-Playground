#include "mux.h"

Mux::Mux()
{

}

void Mux::setValueA(Word valueA)
{
    this->valueA = valueA;
    hasValueA = true;

    emit receivedValueA(valueA);

    tryExecute();
}

void Mux::setValueB(Word valueB)
{
    this->valueB = valueB;
    hasValueB = true;

    emit receivedValueB(valueB);

    tryExecute();
}

void Mux::setSelection(Word selection)
{
    this->selection = selection;
    hasSelection = true;

    tryExecute();
}

void Mux::tryExecute()
{
    if(hasValueA && hasValueB && hasSelection) {
        execute();

        emit executed();

        hasValueA = false;
        hasValueB = false;
        hasSelection = false;
    }
}

Mux::~Mux()
{

}
