/**
 * @file memory.h
 * @briefArquivo responsável por definir a classe
 * @author mGuerra
 * @version 0.1
*/

#ifndef PC_H
#define PC_H

#include <QObject>

#include "word/word.h"

#include "instructionmemory.h"
#include "addbranch.h"
#include "addnext.h"

class InstructionMemory;
class AddBranch;
class AddNext;

/**
 * @brief A classe PC:
 */
class PC : public QObject
{
    Q_OBJECT

private:
    InstructionMemory *instructionMemory = NULL;
    AddBranch *addBranch = NULL;
    AddNext *addNext = NULL;

    Word address = 0;

    bool canRun = false;
    bool hasAddress = true;

public:
    PC();

    void connect(InstructionMemory *instructionMemory, AddBranch *addBranch, AddNext *addNext);

    void run();
    void restart();
    Word getAddress();

    void setAddress(Word address);

    void tryExecute();
    void execute();

    ~PC();

signals:
    void receivedAddress(Word address);

    void executed();

};

#endif // PC_H
