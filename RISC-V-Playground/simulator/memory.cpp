/**
 * @file memory.cpp
 * @brief
 * @author mGuerra
 * @version 0.1
*/

#include "memory.h"

Memory::Memory()
{

}

void Memory::init()
{
    for(int i = 0; i < MEMORY_SPACE; i++) {
        memory[i].reset();
    }

    emit initMemory(MEMORY_SPACE);
}

void Memory::takeMemoryData(QString fileName)
{
    QFile file(fileName + ".b");
    file.open(QFile::ReadOnly | QFile::Text);

    QTextStream streamInput(&file);

    int position = 0;
    vector<Word> instructions;

    while(!streamInput.atEnd()) {
        Word word(streamInput.readLine());

        setValue(word, position);

        instructions.push_back(word);

        position++;
    };

    file.close();

    emit loadMemory(instructions);
}

void Memory::setValue(Word value, Word address)
{
    memory[address.getInteger()].set(value);

    emit updateMemory(value, address);
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

void Memory::restart()
{
    for(int i = 0; i < MEMORY_SPACE; i++) {
        memory[i].reset();
    }

    emit restartMemory();
}

bool Memory::testInstruction(Word address)
{
    if(getValue(address).any()) {
        return true;
    }

    return false;
}

Memory::~Memory()
{

}
