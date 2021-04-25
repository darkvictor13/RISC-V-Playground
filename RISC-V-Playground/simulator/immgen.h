#ifndef IMMGEN_H
#define IMMGEN_H

#include <QObject>

#include "word/word.h"

#include "instructions/instructiontyper.h"
#include "instructions/instructiontypei.h"
#include "instructions/instructiontypes.h"
#include "instructions/instructiontypesb.h"

#include "muxtypeb.h"
#include "addbranch.h"

class AddBranch;
class MuxTypeB;

class ImmGen : public QObject
{
    Q_OBJECT

private:
    AddBranch *addBranch = NULL;
    MuxTypeB *muxB = NULL;

    Word instruction = 0;

    bool hasInstruction = false;

public:
    ImmGen();

    void connect(AddBranch *addBranch, MuxTypeB *muxB);

    void setInstruction(Word instruction);

    void tryExecute();
    void execute();

    ~ImmGen();

signals:
    void receivedInstruction(Word instruction);

    void executed();

};

#endif // IMMGEN_H
