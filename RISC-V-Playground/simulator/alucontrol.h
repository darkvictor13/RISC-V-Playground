#ifndef ALUCONTROL_H
#define ALUCONTROL_H

#include "word/word.h"

#include "alu.h"
#include "addbranch.h"

class ALU;
class AddBranch;

class ALUControl
{
private:
    AddBranch *addBranch = NULL;

    Word instruction = 0;

    bool hasInstruction = false;

public:
    ALUControl();

    void connect(AddBranch *addBranch);

    void setInstruction(Word instruction);

    void tryExecute();
    void execute();

    ~ALUControl();
};

#endif // ALUCONTROL_H
