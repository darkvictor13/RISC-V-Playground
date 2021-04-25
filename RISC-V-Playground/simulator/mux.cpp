/**
 * @file memory.cpp
 * @brief Arquivo responsável por implementar a classe
 * @author mGuerra
 * @version 0.1
*/

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

    emit receivedSelection(selection);

    tryExecute();
}

void Mux::tryExecute()
{
    if(hasValueA && hasValueB && hasSelection) {
        emit executed();

        hasValueA = false;
        hasValueB = false;
        hasSelection = false;

        execute();

        valueA = 0;
        valueB = 0;
        selection = 0;
    }
}

Mux::~Mux()
{

}
