#ifndef IMMGEN_H
#define IMMGEN_H

#include "word/word.h"

#include "muxtypeb.h"
#include "addbranch.h"

class AddBranch;
class MuxTypeB;

class ImmGen
{
private:
    AddBranch *addBranch = NULL;
    MuxTypeB *muxB = NULL;

    Word instruction = 0;

    bool hasInstruction = false;

public:
    ImmGen();

    void connect(AddBranch *addBranch, MuxTypeB *muxB);

    void setInstruction(Word instruction);

    void tryExecute();
    void execute();

    ~ImmGen();
};

#endif // IMMGEN_H
