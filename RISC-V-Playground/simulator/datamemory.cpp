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

    emit receivedAddress(address);

    tryExecute();
}

void DataMemory::setWriteData(Word writeData)
{
    this->writeData = writeData;
    hasWriteData = true;

    emit receivedWriteData(writeData);

    tryExecute();
}

void DataMemory::setMemWrite(Word memWrite)
{
    this->memWrite = memWrite;
    hasMemWrite = true;

    emit receivedMemWrite(memWrite);

    tryExecute();
}

void DataMemory::setMemRead(Word memRead)
{
    this->memRead = memRead;
    hasMemRead = true;

    emit receivedMemRead(memRead);

    tryExecute();
}

void DataMemory::tryExecute()
{
    if(hasAddress && hasWriteData && hasMemWrite && hasMemRead) {
        execute();

        emit executed();

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
