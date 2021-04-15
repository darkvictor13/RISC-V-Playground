#include "addnext.h"

AddNext::AddNext()
{

}

void AddNext::connect(MuxTypeA *muxA)
{
    this->muxA = muxA;
}

void AddNext::execute()
{
    Word result = valueA + valueB;

    muxA->setValueA(result);
}

AddNext::~AddNext()
{

}
