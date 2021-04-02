#include "memory.h"

Memory::Memory()
{
    for(int i = 0; i < MEMORY_SIZE; i++) {
        vector[i] = 0;
    }
}

int Memory::get(int position)
{
    return this->vector[position];
}

void Memory::set(int position, int value)
{
    this->vector[position] = value;
}

Memory::~Memory()
{

}
