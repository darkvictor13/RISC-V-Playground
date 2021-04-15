#ifndef ADDNEXT_H
#define ADDNEXT_H

#include "add.h"

#include "muxtypea.h"

class MuxTypeA;

class AddNext : public Add
{
private:
    MuxTypeA *muxA = NULL;

public:
    AddNext();

    void connect(MuxTypeA *muxA);

    void execute();

    ~AddNext();
};

#endif // ADDNEXT_H
