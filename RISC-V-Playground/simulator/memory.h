/**
 * @file memory.h
 * @brief
 * @author mGuerra
 * @version 0.1
*/

#ifndef MEMORY_H
#define MEMORY_H

#define MEMORY_SPACE 1024

#include "word/word.h"

class Memory
{
public:
    Word memory[MEMORY_SPACE];

    Memory();

    void initMemory();
    void loadMemory();

    void setValue(Word value, Word address);
    Word getValue(Word address);

    ~Memory();
};

#endif // MEMORY_H
