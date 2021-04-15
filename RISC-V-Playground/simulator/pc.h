#ifndef PC_H
#define PC_H

#include "word/word.h"

#include "instructionmemory.h"
#include "addbranch.h"
#include "addnext.h"

class InstructionMemory;
class AddBranch;
class AddNext;

class PC
{
private:
    InstructionMemory *instructionMemory = NULL;
    AddBranch *addBranch = NULL;
    AddNext *addNext = NULL;

    Word address = 0;

    bool canRun = false;
    bool hasAddress = false;

public:
    PC();

    void connect(InstructionMemory *instructionMemory, AddBranch *addBranch, AddNext *addNext);

    void run();
    void setAddress(Word address);

    void tryExecute();
    void execute();

    ~PC();
};

#endif // PC_H
