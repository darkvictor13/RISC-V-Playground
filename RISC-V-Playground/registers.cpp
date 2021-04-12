/**
 * @file registers.cpp
 * @brief
 * @author mGuerra
 * @version 0.1
*/

#include "registers.h"

#include <stdint.h>

#define REGISTERS_SPACE 32

Registers::Registers()
{

}

void Registers::initRegisters()
{
    for(int i = 0; i < REGISTERS_SPACE; i++) {
        registers[i].reset();
    }
}

void Registers::setValue(DATA value, DATA registerIndex)
{
    registers[registerIndex].set(value);
}

Word Registers::getValue(DATA registerIndex)
{
    return registers[registerIndex];
}

Registers::~Registers()
{

}
