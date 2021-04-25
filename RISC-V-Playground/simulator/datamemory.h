/**
 * @file add.h
 * @brief Arquivo responsável por definir a classe
 * @author mGuerra
 * @version 0.1
*/

#ifndef DATAMEMORY_H
#define DATAMEMORY_H

#include "memory.h"

#include "muxtypec.h"

class MuxTypeC;

/**
 * @brief A classe DataMemory:
 */
class DataMemory : public Memory
{
    Q_OBJECT

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

signals:
    void receivedAddress(Word address);
    void receivedWriteData(Word writeData);
    void receivedMemWrite(Word memWrite);
    void receivedMemRead(Word memRead);

    void executed();

};

#endif // DATAMEMORY_H
