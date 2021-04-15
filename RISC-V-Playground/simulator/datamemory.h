#ifndef DATAMEMORY_H
#define DATAMEMORY_H

#include "memory.h"

#include "muxtypec.h"

class MuxTypeC;

class DataMemory : public Memory
{
private:
    MuxTypeC *muxC = NULL;

    Word address = 0;
    Word writeData = 0;
    Word memWrite = 0;
    Word memRead = 0;

    bool hasAddress = false;
    bool hasWriteData = false;
    bool hasMemWrite = false;
    bool hasMemRead = false;

public:
    DataMemory();

    void connect(MuxTypeC *muxC);

    void setAddress(Word address);
    void setWriteData(Word writeData);
    void setMemWrite(Word memWrite);
    void setMemRead(Word memRead);

    void tryExecute();
    void execute();

    ~DataMemory();
};

#endif // DATAMEMORY_H
