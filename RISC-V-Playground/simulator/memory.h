/**
 * @file memory.h
 * @brief Arquivo responsável por definir a classe Memory
 * @author mGuerra
 * @version 0.1
*/

#ifndef MEMORY_H
#define MEMORY_H

/**
  * @brief Indica o tamanho total da memória
  */
#define MEMORY_SPACE 64

#include <QTextStream>
#include <QObject>
#include <QFile>

#include "word/word.h"

/**
 * @brief A classe Memory: Classe abstrata base para os
 * diferentes tipos de memória
 */
class Memory : public QObject
{
    Q_OBJECT

public:
    Word memory[MEMORY_SPACE];

    Memory();

    void init();
    void takeMemoryData(QString fileName);
    void loadValue(Word value, Word address);
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
