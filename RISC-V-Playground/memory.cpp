/**
  @file memory.cpp
  @brief Arquivo que implementa os métodos da classe Memory
  @author Victor Emanuel Almeida
  @version 0.1
*/

#include "memory.h"

/**
 * @brief Inicializa todas as células de memória com zero
 */
Memory::Memory()
{
    cout << "Destruindo a classe memória" << endl;
    for(int i = 0; i < MEMORY_SIZE; i++) {
        vectorData[i] = 0;
    }
}

/**
 * @brief Lê o valor contido na memória
 * @param position: indica o registrador a ser lido
 * @return o valor contido na memória na posição[position]
 */
int Memory::get(int position)
{
    return this->vectorData[position];
}

/**
 * @brief Escreve o valor passado por referência na memória
 * @param position: indica o registrador a ser lido
 * @param value valor a ser escrito
 */
void Memory::set(int position, int value)
{
    this->vectorData[position] = value;
}

Memory::~Memory()
{
    cout << "Destruindo a classe memória" << endl;
}
