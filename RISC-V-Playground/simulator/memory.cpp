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

void Memory::setValue(Word value, Word address)
{
    memory[address.getInteger()].set(value);
}

Word Memory::getValue(Word address)
{
    return memory[address.getInteger()];
}

Memory::~Memory()
{

}
