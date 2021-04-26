/**
 * @file muxtypea.h
 * @brief Arquivo responsável por definir a classe MuxTypeA
 * @author mGuerra
 * @version 0.1
*/

#ifndef MUXTYPEA_H
#define MUXTYPEA_H

#include "mux.h"

#include "pc.h"

class PC;

/**
 * @brief A classe MuxTypeA: Multiplexador para selecionar
 * o valor que será colocado do program counter
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
