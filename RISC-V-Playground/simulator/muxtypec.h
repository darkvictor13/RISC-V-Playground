#ifndef MUXTYPEC_H
#define MUXTYPEC_H

#include "mux.h"

#include "registers.h"

class Registers;

class MuxTypeC : public Mux
{
private:
    Registers *registers = NULL;

public:
    MuxTypeC();

    void connect(Registers *registers);

    void execute();

    ~MuxTypeC();
};

#endif // MUXTYPEC_H
