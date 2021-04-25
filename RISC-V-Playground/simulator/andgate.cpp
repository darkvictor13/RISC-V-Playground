#include "andgate.h"

AndGate::AndGate()
{

}

void AndGate::connect(MuxTypeA *muxA)
{
    this->muxA = muxA;
}

void AndGate::setBranch(Word branch)
{
    this->branch = branch;
    hasBranch = true;

    emit receivedBransh(branch);

    tryExecute();
}

void AndGate::setZero(Word zero)
{
    this->zero = zero;
    hasZero = true;

    emit receivedZero(zero);

    tryExecute();
}

void AndGate::tryExecute()
{
    if(hasBranch && hasZero) {
        emit executed();

        hasBranch = false;
        hasZero = false;

        execute();

        branch = 0;
        zero = 0;
    }
}

void AndGate::execute()
{
    if(branch == 1 && zero == 1) {
        muxA->setSelection(1);
    }else{
        muxA->setSelection(0);
    }
}

AndGate::~AndGate()
{

}
