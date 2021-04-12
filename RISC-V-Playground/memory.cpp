/**
 * @file memory.cpp
 * @brief
 * @author mGuerra
 * @version 0.1
*/

#include "memory.h"

Memory::Memory()
{
    initMemory();
}

void Memory::initMemory()
{
    for(int i = 0; i < MEMORY_SPACE; i++) {
        memory[i].reset();
    }
}

void Memory::loadMemory(/*pointer to a file*/)
{

}

void Memory::setValue(DATA value, DATA address)
{
    memory[address].set(value);
}

Word Memory::getValue(DATA address)
{
    return memory[address];
}

Memory::~Memory()
{

}
