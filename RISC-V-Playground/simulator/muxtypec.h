/**
 * @file muxtypec.h
 * @brief Arquivo responsável por definir a classe MuxTypeC
 * @author mGuerra
 * @version 0.1
*/

#ifndef MUXTYPEC_H
#define MUXTYPEC_H

#include "mux.h"

#include "registers.h"

class Registers;

/**
 * @brief A classe MuxTypeC: Multiplexador para selecionar
 * o valor que será colocado no Registrador
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
