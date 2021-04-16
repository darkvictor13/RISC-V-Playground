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

void Memory::loadMemory(QString fileName)
{
    QFile file(fileName + ".b");
    file.open(QFile::ReadOnly | QFile::Text);

    int position = 0;

    QTextStream streamInput(&file);

    while(!streamInput.atEnd()) {
        setValue(streamInput.readLine(),position);
    };

    file.close();
}

void Memory::setValue(Word value, Word address)
{
    memory[address.getInteger()].set(value);
}

void Memory::setValue(QString binary, int address)
{
    Word word(binary);

    memory[address].set(word);
}

Word Memory::getValue(Word address)
{
    return memory[address.getInteger()];
}

Memory::~Memory()
{

}
