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

        loadValue(word, position);

        instructions.push_back(word);

        position++;
    };

    file.close();

    emit loadMemory(instructions);
}

void Memory::loadValue(Word value, Word address)
{
    memory[address.getInteger()].set(value);

    emit updateMemory(value, address);
}

void Memory::setValue(Word value, Word address)
{
    int position = address.getInteger() / 4;

    memory[position].set(value);

    emit updateMemory(value, Word(position));
}

void Memory::setValue(QString binary, int address)
{
    Word word(binary);

    int position = address / 4;

    memory[position].set(word);
}

Word Memory::getValue(Word address)
{
    int position = address.getInteger() / 4;

    return memory[position];
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
    Word position(address.getInteger() / 4);

    if(getValue(position).any()) {
        return true;
    }

    return false;
}

Memory::~Memory()
{

}
