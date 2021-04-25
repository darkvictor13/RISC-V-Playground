/**
 * @file instructiontypes.cpp
 * @brief Arquivo responsável por implementar a classe
 * @author mGuerra
 * @version 0.1
*/

#include "instructiontypes.h"

InstructionTypeS::InstructionTypeS()
{

}

void InstructionTypeS::setImmediate(DATA value)
{
    set(value & mask(0, S_IMMEDIATE_A_LAST - S_IMMEDIATE_A_FIRST), S_IMMEDIATE_A_FIRST, S_IMMEDIATE_A_LAST);
    set(value >> (S_IMMEDIATE_A_LAST - S_IMMEDIATE_A_FIRST), S_IMMEDIATE_B_FIRST, S_IMMEDIATE_B_LAST);
}

void InstructionTypeS::setImmediate(QString binary)
{
    set(binary.mid(0, S_IMMEDIATE_A_LAST - S_IMMEDIATE_A_FIRST + 1), S_IMMEDIATE_A_FIRST, S_IMMEDIATE_A_LAST);
    set(binary.mid(S_IMMEDIATE_A_LAST - S_IMMEDIATE_A_FIRST + 1), S_IMMEDIATE_B_FIRST, S_IMMEDIATE_B_LAST);
}

DATA InstructionTypeS::getIntegerImmediate()
{
    return (getInteger(S_IMMEDIATE_B_FIRST, S_IMMEDIATE_B_LAST) << (S_IMMEDIATE_A_LAST - S_IMMEDIATE_A_FIRST)) | getInteger(S_IMMEDIATE_A_FIRST, S_IMMEDIATE_A_LAST);
}

QString InstructionTypeS::getStringImmediate()
{
    return getString(S_IMMEDIATE_A_FIRST, S_IMMEDIATE_A_LAST).append(getString(S_IMMEDIATE_B_FIRST, S_IMMEDIATE_B_LAST));
}

void InstructionTypeS::setRS2(DATA value)
{
    set(value, RS2_FIRST, RS2_LAST);
}

void InstructionTypeS::setRS2(QString binary)
{
    set(binary, RS2_FIRST, RS2_LAST);
}

DATA InstructionTypeS::getIntegerRS2()
{
    return getInteger(RS2_FIRST, RS2_LAST);
}

QString InstructionTypeS::getStringRS2()
{
    return getString(RS2_FIRST, RS2_LAST);
}

InstructionTypeS::~InstructionTypeS()
{

}
