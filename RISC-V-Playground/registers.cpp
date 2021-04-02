/**
  @file registers.cpp
  @brief Arquivo que implementa os métodos da classe Registers
  @author Victor Emanuel Almeida
  @version 0.1
*/

#include "registers.h"

/**
 * @brief Inicializa todos os registradores com zero
 */
Registers::Registers()
{
    cout << "Criando classe registradores" << endl;
    for(int i = 0; i < QUANTITY_REGISTERS; i++) {
        vector[i] = 0;
    }
}

/**
 * @brief Lê o valor contido em um registrador
 * @param position: indica o registrador a ser lido
 * @return o valor contido no registrador x[position]
 */
int Registers::get(int position)
{
    return this->vector[position];
}

/**
 * @brief Escreve o valor passado por referência em um registrador
 * @param position: indica o registrador a ser lido
 * @param value valor a ser escrito
 */
void Registers::set(int position, int value)
{
    if (position) {
        this->vector[position] = value;
    }else {
        cout << "É impossível escrever no registrador x0, ele sempre armazena o valor 0" << endl;
    }
}

/**
 * @brief Construtor da classe Registers
 */
Registers::~Registers()
{
    cout << "Destruindo classe registradores" << endl;
}
