/**
 * @file datamemory.cpp
 * @brief Arquivo responsável por implementar a classe DataMemory
 * @author mGuerra
 * @version 0.1
*/

#include "datamemory.h"

/**
 * @brief DataMemory::DataMemory: Construtor da classe
 */
DataMemory::DataMemory()
{

}

/**
 * @brief DataMemory::connect: Conecta via ponteiro
 * aos elementos necessários para passagem de dados

 * @param MuxTypeC muxC: Multiplexador do tipo C
 */
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

/**
 * @brief DataMemory::tryExecute: Tenta Executar o subcircuito
 *
 * @warning Executa apenas quando Possui todos os valores

 */
void DataMemory::tryExecute()
{
    if(hasAddress && hasWriteData && hasMemWrite && hasMemRead) {
        emit executed();

        hasAddress = false;
        hasWriteData = false;
        hasMemWrite = false;
        hasMemRead = false;

        execute();

        address = 0;
        writeData = 0;
        memWrite = 0;
        memRead = 0;
    }
}

/**
 * @brief DataMemory::execute: Realiza todas as ações propostas pela classe
 */
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

/**
 * @brief DataMemory::~DataMemory: Destrutor da classe
 */
DataMemory::~DataMemory()
{

}
