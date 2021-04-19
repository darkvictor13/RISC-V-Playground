/**
 * @file memory.h
 * @brief
 * @author mGuerra
 * @version 0.1
*/

#ifndef MEMORY_H
#define MEMORY_H

#define MEMORY_SPACE 64

#include <QTextStream>
#include <QObject>
#include <QFile>

#include "word/word.h"

class Memory : public QObject
{
    Q_OBJECT

public:
    Word memory[MEMORY_SPACE];

    Memory();

    void init();
    void takeMemoryData(QString fileName);
    void setValue(Word value, Word address);
    void setValue(QString binary, int address);
    Word getValue(Word address);
    void restart();

    bool testInstruction(Word address);

    ~Memory();

signals:
    void initMemory(int size);
    void loadMemory(vector<Word> memoryData);
    void updateMemory(Word value, Word address);
    void restartMemory();

};

#endif // MEMORY_H
