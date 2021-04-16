#include "datamemory.h"

DataMemory::DataMemory()
{

}

void DataMemory::connect(MuxTypeC *muxC)
{
    this->muxC = muxC;
}

void DataMemory::setAddress(Word address)
{
    this->address = address;
    hasAddress = true;

    tryExecute();
}

void DataMemory::setWriteData(Word writeData)
{
    this->writeData = writeData;
    hasWriteData = true;

    tryExecute();
}

void DataMemory::setMemWrite(Word memWrite)
{
    this->memWrite = memWrite;
    hasMemWrite = true;

    tryExecute();
}

void DataMemory::setMemRead(Word memRead)
{
    this->memRead = memRead;
    hasMemRead = true;

    tryExecute();
}

void DataMemory::tryExecute()
{
    if(hasAddress && hasWriteData && hasMemWrite && hasMemRead) {
        execute();

        hasAddress = false;
        hasWriteData = false;
        hasMemWrite = false;
        hasMemRead = false;
    }
}

void DataMemory::execute()
{
    if(memRead == 1) {
        muxC->setValueB(getValue(address));
    }else{
        muxC->setValueB(getValue(0));
    }

    if(memWrite == 1) {
        setValue(writeData, address);
    }
}

DataMemory::~DataMemory()
{

}
