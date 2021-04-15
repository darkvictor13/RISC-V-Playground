#ifndef ANDGATE_H
#define ANDGATE_H

#include "word/word.h"

#include "muxtypea.h"

class MuxTypeA;

class AndGate
{
private:
    MuxTypeA *muxA = NULL;

    Word valueA = 0;
    Word valueB = 0;

    bool hasValueA = false;
    bool hasValueB = false;

public:
    AndGate();

    void connect(MuxTypeA *muxA);

    void setValueA(Word valueA);
    void setValueB(Word valueB);

    void tryExecute();
    void execute();

    ~AndGate();
};

#endif // ANDGATE_H
