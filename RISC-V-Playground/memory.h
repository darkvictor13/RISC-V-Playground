/**
  @file memory.h
  @brief Arquivo que define a classe Memory
  @author Victor Emanuel Almeida
  @version 0.1
*/

#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>

using namespace std;

/**
  * @brief O Tamanho total do vetor que representa a memória
  */
#define MEMORY_SIZE 1024

/**
 * @brief A classe Memory: Classe que tem como objetivo
 * simular a memória
 */
class Memory
{
private:
    /**
     * @brief um vetor de inteiros, onde cada indice representa uma célula de memória
     * e o conteúdo de cada elemento representa o valor daquela célula de memória
     */
    int vectorData[MEMORY_SIZE];
public:
    Memory();

    int get(int position);
    void set(int position, int value);

    ~Memory();
};

#endif // MEMORY_H
