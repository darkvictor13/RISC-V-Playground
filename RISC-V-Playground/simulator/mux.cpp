/**
 * @file mux.cpp
 * @brief Arquivo responsável por implementar a classe Mux
 * @author mGuerra
 * @version 0.1
*/

#include "mux.h"

/**
 * @brief Mux::Mux: Construtor da classe
 */
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

/**
 * @brief Mux::tryExecute: Tenta Executar o subcircuito
 *
 * @warning Executa apenas quando Possui todos os valores

 */
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

/**
 * @brief Mux::~Mux: Destrutor da classe
 */
Mux::~Mux()
{

}
