/**
 * @file memory.h
 * @briefArquivo responsável por definir a classe
 * @author mGuerra
 * @version 0.1
*/

#ifndef MUXTYPEA_H
#define MUXTYPEA_H

#include "mux.h"

#include "pc.h"

class PC;

/**
 * @brief A classe MuxTypeA:
 */
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
