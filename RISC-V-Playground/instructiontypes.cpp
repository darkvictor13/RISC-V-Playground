/**
 * @file instructiontypes.cpp
 * @brief
 * @author mGuerra
 * @version 0.1
*/

#include "instructiontypes.h"

InstructionTypeS::InstructionTypeS()
{

}

void InstructionTypeS::setImmediate(DATA value)
{
    set(value & mask(0, IMMEDIATE_A_LAST - IMMEDIATE_A_FIRST), IMMEDIATE_A_FIRST, IMMEDIATE_A_LAST);
    set(value >> (IMMEDIATE_A_LAST - IMMEDIATE_A_FIRST), IMMEDIATE_B_FIRST, IMMEDIATE_B_LAST);
}

void InstructionTypeS::setImmediate(string binary)
{
    set(binary.substr(0, IMMEDIATE_A_LAST - IMMEDIATE_A_FIRST), IMMEDIATE_A_FIRST, IMMEDIATE_A_LAST);
    set(binary.substr(IMMEDIATE_A_LAST - IMMEDIATE_A_FIRST + 1), IMMEDIATE_B_FIRST, IMMEDIATE_B_LAST);
}

DATA InstructionTypeS::getIntegerImmediate()
{
    return (getInteger(IMMEDIATE_B_FIRST, IMMEDIATE_B_LAST) << (IMMEDIATE_A_LAST - IMMEDIATE_A_FIRST)) & getInteger(IMMEDIATE_A_FIRST, IMMEDIATE_A_LAST);
}

string InstructionTypeS::getStringImmediate()
{
    return getString(IMMEDIATE_A_FIRST, IMMEDIATE_A_LAST).append(getString(IMMEDIATE_B_FIRST, IMMEDIATE_B_LAST));
}

void InstructionTypeS::setRS2(DATA value)
{
    set(value, RS2_FIRST, RS2_LAST);
}

void InstructionTypeS::setRS2(string binary)
{
    set(binary, RS2_FIRST, RS2_LAST);
}

DATA InstructionTypeS::getIntegerRS2()
{
    return getInteger(RS2_FIRST, RS2_LAST);
}

string InstructionTypeS::getStringRS2()
{
    return getString(RS2_FIRST, RS2_LAST);
}

InstructionTypeS::~InstructionTypeS()
{

}
