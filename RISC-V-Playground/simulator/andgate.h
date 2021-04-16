#ifndef ANDGATE_H
#define ANDGATE_H

#include "word/word.h"

#include "muxtypea.h"

class MuxTypeA;

class AndGate
{
private:
    MuxTypeA *muxA = NULL;

    Word branch = 0;
    Word zero = 0;

    bool hasBranch = false;
    bool hasZero = false;

public:
    AndGate();

    void connect(MuxTypeA *muxA);

    void setBranch(Word branch);
    void setZero(Word zero);

    void tryExecute();
    void execute();

    ~AndGate();
};

#endif // ANDGATE_H
