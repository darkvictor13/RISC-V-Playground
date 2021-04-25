#include "makebranch.h"

MakeBranch::MakeBranch()
{

}

void MakeBranch::connect(MuxTypeA *muxA)
{
    this->muxA = muxA;
}

void MakeBranch::setBranch(Word branch)
{
    this->branch = branch;
    hasBranch = true;

    emit receivedBransh(branch);

    tryExecute();
}

void MakeBranch::setZero(Word zero)
{
    this->zero = zero;
    hasZero = true;

    emit receivedZero(zero);

    tryExecute();
}

void MakeBranch::tryExecute()
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

void MakeBranch::execute()
{
    if(branch == 1 && zero == 1) {
        muxA->setSelection(1);
    }else{
        muxA->setSelection(0);
    }
}

MakeBranch::~MakeBranch()
{

}
