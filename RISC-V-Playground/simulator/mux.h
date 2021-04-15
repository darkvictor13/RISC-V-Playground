#ifndef MUX_H
#define MUX_H

#include "word/word.h"

class Mux
{
public:
    Word valueA = 0;
    Word valueB = 0;
    Word selection = 0;

    bool hasValueA = false;
    bool hasValueB = false;
    bool hasSelection = false;

    Mux();

    void setValueA(Word valueA);
    void setValueB(Word valueB);
    void setSelection(Word selection);

    void tryExecute();
    void execute() {};

    ~Mux();
};

#endif // MUX_H
