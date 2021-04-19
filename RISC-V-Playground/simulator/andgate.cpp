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
    if(branch && zero) {
        execute();

        emit executed();

        branch = false;
        zero = false;
    }
}

void AndGate::execute()
{
    Word result = branch & zero;

    muxA->setSelection(result);
}

AndGate::~AndGate()
{

}
