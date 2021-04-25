/**
 * @file memory.h
 * @briefArquivo responsável por definir a classe
 * @author mGuerra
 * @version 0.1
*/

#ifndef MUXTYPEC_H
#define MUXTYPEC_H

#include "mux.h"

#include "registers.h"

class Registers;

/**
 * @brief A classe MuxTypeC:
 */
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
