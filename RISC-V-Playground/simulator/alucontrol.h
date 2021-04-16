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

    Word instruction = 0;
    Word aluOp = 0;

    bool hasInstruction = false;
    bool hasALUOp = false;

public:
    ALUControl();

    void connect(ALU *alu);

    void setInstruction(Word instruction);
    void setALUOp(Word aluOp);

    void tryExecute();
    void execute();

    ~ALUControl();
};

#endif // ALUCONTROL_H
