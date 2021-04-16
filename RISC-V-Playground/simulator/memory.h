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

#include <QTextStream>
#include <QFile>

class Memory
{
public:
    Word memory[MEMORY_SPACE];

    Memory();

    void initMemory();
    void loadMemory(QString fileName);

    void setValue(Word value, Word address);
    void setValue(QString binary, int address);
    Word getValue(Word address);

    ~Memory();
};

#endif // MEMORY_H
