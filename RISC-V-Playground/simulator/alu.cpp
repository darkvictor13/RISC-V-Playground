/**
 * @file alu.cpp
 * @brief Arquivo responsável por implementar a classe ALU
 * @author mGuerra
 * @version 0.1
*/

#include "alu.h"

/**
 * @brief ALU::ALU: Construtor da classe ALU
 */
ALU::ALU()
{

}

/**
 * @brief ALU::connect: Conecta a Alu com suas saídas
 * @param DataMemory dataMemory: Objeto que representa
 * @param MakeBranch makeBranch: Objeto que representa
 * @param MuxTypeC muxC: Objeto que representa
 */
void ALU::connect(DataMemory *dataMemory, MakeBranch *makeBranch, MuxTypeC *muxC)
{
    this->dataMemory = dataMemory;
    this->makeBranch = makeBranch;
    this->muxC = muxC;
}

/**
 * @brief ALU::setValueA: Altera o valor da primeira entrada do circuito
 * @param Word valueA: Primeira entrada do circuito
 */
void ALU::setValueA(Word valueA)
{
    this->valueA = valueA;
    hasValueA = true;

    emit receivedValueA(valueA);

    tryExecute();
}

/**
 * @brief ALU::setValueB: Altera o valor da segunda entrada do circuito
 * @param Word valueB: Segunda entrada do circuito
 */
void ALU::setValueB(Word valueB)
{
    this->valueB = valueB;
    hasValueB = true;

    emit receivedValueB(valueB);

    tryExecute();
}

/**
 * @brief ALU::setControl: Altera o valor que representa a operação a ser realizada
 * @param Word control: Operação a ser realizada
 */
void ALU::setControl(Word control)
{
    this->control = control;
    hasControl = true;

    emit receivedControl(control);

    tryExecute();
}

/**
 * @brief ALU::setReverse: Altera o valor da variavél que indica se inverte
 * a saída da flag ZERO
 * @param reverse: Valor a ser escrito
 */
void ALU::setReverse(Word reverse)
{
    this->reverse = reverse;
    hasReverse = true;

    emit receivedReverse(reverse);

    tryExecute();
}

/**
 * @brief ALU::tryExecute: Tenta Executar o subcircuito
 *
 * @warning Executa apenas quando Possui todos os valores
 */
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

/**
 * @brief ALU::execute: Realiza a operação necessária
 * e indica que foi executada
 */
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

/**
 * @brief ALU::~ALU: Destrutor da classe ALU
 */
ALU::~ALU()
{

}
