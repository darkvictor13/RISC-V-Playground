/**
 * @file add.cpp
 * @brief Arquivo responsável por implementar a classe Add
 * @author mGuerra
 * @version 0.1
*/

#include "add.h"

/**
 * @brief Add::Add: Construtor da classe Add
 */
Add::Add()
{

}

/**
 * @brief Add::setValueA: Altera o valor da primeira entrada do circuito
 * @param valueA
 */
void Add::setValueA(Word valueA)
{
    this->valueA = valueA;
    hasValueA = true;

    emit receivedValueA(valueA);

    tryExecute();
}

/**
 * @brief Add::setValueB: Altera o valor da segunda entrada do circuito
 * @param valueB
 */
void Add::setValueB(Word valueB)
{
    this->valueB = valueB;
    hasValueB = true;

    emit receivedValueB(valueB);

    tryExecute();
}

/**
 * @brief Add::tryExecute: Tenta Executar o subcircuito
 *
 * @warning Executa apenas quando Possui todos os valores
 */
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

/**
 * @brief Add::~Add: Destrutor da classe Add
 */
Add::~Add()
{

}
