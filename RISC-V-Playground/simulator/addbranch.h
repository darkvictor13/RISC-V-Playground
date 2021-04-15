#ifndef ADDBRANCH_H
#define ADDBRANCH_H

#include "add.h"

#include "muxtypea.h"

class MuxTypeA;

class AddBranch : public Add
{
private:
    MuxTypeA *muxA = NULL;

public:
    AddBranch();

    void connect(MuxTypeA *muxA);

    void execute();

    ~AddBranch();
};

#endif // ADDBRANCH_H
