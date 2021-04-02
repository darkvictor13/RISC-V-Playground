/**
  @file registers.h
  @brief Arquivo que define a classe Registers
  @author Victor Emanuel Almeida
  @version 0.1
*/

#ifndef REGISTERS_H
#define REGISTERS_H

#include <iostream>

using namespace std;

/**
  * @brief O Tamanho total do vetor que representa os registradores,
  */
#define QUANTITY_REGISTERS 32

/**
 * @brief A classe Registers: Classe que tem como objetivo simular
 * o comportamento dos registradores, bem como armazenar seus valores
 */
class Registers
{
private:
    /**
     * @brief um vetor de inteiros, onde cada indice representa um registrador e
     * o conteúdo de cada elemento representa o valor do registrador
     */
    int vector[QUANTITY_REGISTERS];

public:
    Registers();

    int get(int position);
    void set(int position, int value);

    ~Registers();
};

#endif // REGISTERS_H
