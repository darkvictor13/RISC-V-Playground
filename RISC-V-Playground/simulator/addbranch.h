/**
 * @file add.h
 * @brief Arquivo responsável por definir a classe
 * @author mGuerra
 * @version 0.1
*/

#ifndef ADDBRANCH_H
#define ADDBRANCH_H

#include "add.h"

#include "muxtypea.h"

class MuxTypeA;

/**
 * @brief A classe AddBranch:
 */
class AddBranch : public Add
{
private:
    MuxTypeA *muxA = NULL;

public:
    AddBranch();

    void connect(MuxTypeA *muxA);

    void execute();

    ~AddBranch();
};

#endif // ADDBRANCH_H
