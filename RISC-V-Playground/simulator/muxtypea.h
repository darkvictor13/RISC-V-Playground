#ifndef MUXTYPEA_H
#define MUXTYPEA_H

#include "mux.h"

#include "pc.h"

class PC;

class MuxTypeA : public Mux
{
private:
    PC *pc = NULL;

public:
    MuxTypeA();

    void connect(PC *pc);

    void execute();

    ~MuxTypeA();
};

#endif // MUXTYPEA_H
