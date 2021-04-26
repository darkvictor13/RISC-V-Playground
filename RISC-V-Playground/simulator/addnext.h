/**
 * @file addnext.h
 * @brief Arquivo responsável por definir a classe AddNext
 * @author mGuerra
 * @version 0.1
*/

#ifndef ADDNEXT_H
#define ADDNEXT_H

#include "add.h"

#include "muxtypea.h"

class MuxTypeA;

/**
 * @brief A classe AddNext: Calcula para onde o Pc deve
 * apontar para obter a próxima instrução
 */
class AddNext : public Add
{
private:
    MuxTypeA *muxA = NULL;

public:
    AddNext();

    void connect(MuxTypeA *muxA);

    void execute();

    ~AddNext();
};

#endif // ADDNEXT_H
