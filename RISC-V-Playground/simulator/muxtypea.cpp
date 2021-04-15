#include "muxtypea.h"

MuxTypeA::MuxTypeA()
{

}

void MuxTypeA::connect(PC *pc)
{
    this->pc = pc;
}

void MuxTypeA::execute()
{
    if(selection == 0)  {
        pc->setAddress(valueA);
    }else{
        pc->setAddress(valueB);
    }
}

MuxTypeA::~MuxTypeA()
{

}
