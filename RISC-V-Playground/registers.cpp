#include "registers.h"

Registers::Registers()
{
    for(int i = 0; i < QUANTITY_REGISTERS; i++) {
        vector[i] = 0;
    }
}

int Registers::get(int position)
{
    return this->vector[position];
}

void Registers::set(int position, int value)
{
    this->vector[position] = value;
}

Registers::~Registers()
{

}
