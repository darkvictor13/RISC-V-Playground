/**
 * @file registers.h
 * @brief
 * @author mGuerra
 * @version 0.1
*/

#ifndef REGISTERS_H
#define REGISTERS_H

#define REGISTERS_SPACE 32

#include "word.h"

/**
 * @brief A classe Registers:
 */
class Registers
{
private:
    Word registers[REGISTERS_SPACE];

public:
    Registers();

    void initRegisters();

    void setValue(DATA value, DATA registerIndex);
    Word getValue(DATA registerIndex);

    ~Registers();
};

#endif // REGISTERS_H
