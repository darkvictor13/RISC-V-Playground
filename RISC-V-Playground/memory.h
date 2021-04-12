/**
 * @file memory.h
 * @brief
 * @author mGuerra
 * @version 0.1
*/

#ifndef MEMORY_H
#define MEMORY_H

#define MEMORY_SPACE 1024

#include "word.h"

class Memory
{
private:
    Word memory[MEMORY_SPACE];

public:
    Memory();

    void initMemory();
    void loadMemory();

    void setValue(DATA value, DATA address);
    Word getValue(DATA address);

    ~Memory();
};

#endif // MEMORY_H
