/**
 * @file muxtypeb.h
 * @brief Arquivo responsável por definir a classe MuxTypeB
 * @author mGuerra
 * @version 0.1
*/

#ifndef MUXTYPEB_H
#define MUXTYPEB_H

#include "mux.h"

#include "alu.h"

class ALU;

/**
 * @brief A classe MuxTypeB: Multiplexador para selecionar
 * o valor que será colocado na segunda entrada da ALU
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
