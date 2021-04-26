/**
 * @file alu.h
 * @brief Arquivo responsável por definir a classe ALU
 * @author mGuerra
 * @version 0.1
*/

#ifndef ALU_H
#define ALU_H

#include <QObject>

#include "word/word.h"

#include "instructionmemory.h"
#include "makebranch.h"
#include "muxtypec.h"

class DataMemory;
class MakeBranch;
class MuxTypeC;

/**
 * @brief A classe ALU: Representa a unidade lógica e aritimética
 * responsável por executar toda operação do programa
 */
class ALU : public QObject
{
    Q_OBJECT

private:
    DataMemory *dataMemory = NULL;
    MakeBranch *makeBranch = NULL;
    MuxTypeC *muxC = NULL;

    Word valueA = 0;
    Word valueB = 0;
    Word control = 0;
    Word reverse = 0;

    bool hasValueA = false;
    bool hasValueB = false;
    bool hasControl = false;
    bool hasReverse = false;

public:
    ALU();

    void connect(DataMemory *dataMemory, MakeBranch *makeBranch, MuxTypeC *muxC);

    void setValueA(Word valueA);
    void setValueB(Word valueB);
    void setControl(Word control);
    void setReverse(Word reverse);

    void tryExecute();
    void execute();

    ~ALU();

signals:
    void receivedValueA(Word valueA);
    void receivedValueB(Word valueB);
    void receivedControl(Word control);
    void receivedReverse(Word reverse);

    void executed();

};

#endif // ALU_H
