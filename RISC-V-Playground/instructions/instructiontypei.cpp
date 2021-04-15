/**
 * @file instruction.cpp
 * @brief
 * @author mGuerra
 * @version 0.1
*/

#include "instructiontypei.h"

InstructionTypeI::InstructionTypeI()
{

}

void InstructionTypeI::setRD(DATA value)
{
    set(value, RD_FIRST, RD_LAST);
}

void InstructionTypeI::setRD(QString binary)
{
    set(binary, RD_FIRST, RD_LAST);
}

DATA InstructionTypeI::getIntegerRD()
{
    return getInteger(RD_FIRST, RD_LAST);
}

QString InstructionTypeI::getStringRD()
{
    return getString(RD_FIRST, RD_LAST);
}

void InstructionTypeI::setImmediate(DATA value)
{
    set(value, IMMEDIATE_FIRST, IMMEDIATE_LAST);
}

void InstructionTypeI::setImmediate(QString binary)
{
    set(binary, IMMEDIATE_FIRST, IMMEDIATE_LAST);
}

DATA InstructionTypeI::getIntegerImmediate()
{
    return getInteger(IMMEDIATE_FIRST, IMMEDIATE_LAST);
}

QString InstructionTypeI::getStringImmediate()
{
    return getString(IMMEDIATE_FIRST, IMMEDIATE_LAST);
}

InstructionTypeI::~InstructionTypeI()
{

}
