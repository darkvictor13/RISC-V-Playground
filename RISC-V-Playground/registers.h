/**
  @file registers.h
  @brief Arquivo que define a classe Registers
  @author Victor Emanuel Almeida
  @version 0.1
*/

#ifndef REGISTERS_H
#define REGISTERS_H

#define QUANTITY_REGISTERS 32

/**
 * @brief A classe Registers:
 */
class Registers
{
private:
    int vector[QUANTITY_REGISTERS];

public:
    Registers();

    int get(int position);
    void set(int position, int value);

    ~Registers();
};

#endif // REGISTERS_H
