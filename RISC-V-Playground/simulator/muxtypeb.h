#ifndef MUXTYPEB_H
#define MUXTYPEB_H

#include "mux.h"

#include "alu.h"

class ALU;

class MuxTypeB : public Mux
{
private:
    ALU *alu = NULL;

public:
    MuxTypeB();

    void connect(ALU *alu);

    void execute();

    ~MuxTypeB();
};

#endif // MUXTYPEB_H
