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
    ALU *alu = NULL;

    Word aluOp = 0;

    bool hasALUOp = false;

public:
    ALUControl();

    void connect(ALU *alu);

    void setALUOp(Word instruction);

    void tryExecute();
    void execute();

    ~ALUControl();
};

#endif // ALUCONTROL_H
