/**
 * @file memory.h
 * @briefArquivo responsável por definir a classe
 * @author mGuerra
 * @version 0.1
*/

#ifndef MUXTYPEB_H
#define MUXTYPEB_H

#include "mux.h"

#include "alu.h"

class ALU;

/**
 * @brief A classe MuxTypeB:
 */
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
