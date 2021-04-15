#include "andgate.h"

AndGate::AndGate()
{

}

void AndGate::connect(MuxTypeA *muxA)
{
    this->muxA = muxA;
}

void AndGate::setValueA(Word valueA)
{
    this->valueA = valueA;
    hasValueA = true;

    tryExecute();
}

void AndGate::setValueB(Word valueB)
{
    this->valueB = valueB;
    hasValueB = true;

    tryExecute();
}

void AndGate::tryExecute()
{
    if(hasValueA && hasValueB) {
        execute();

        hasValueA = false;
        hasValueB = false;
    }
}

void AndGate::execute()
{
    Word result = valueA & valueB;

    muxA->setSelection(result);
}

AndGate::~AndGate()
{

}
