/**
 * @file instructiontypesb.cpp
 * @brief
 * @author mGuerra
 * @version 0.1
*/

#include "instructiontypesb.h"

InstructionTypeSB::InstructionTypeSB()
{

}

void InstructionTypeSB::setImmediate(DATA value)
{
    set(value & mask(0, IMMEDIATE_A_LAST - IMMEDIATE_A_FIRST), IMMEDIATE_A_FIRST, IMMEDIATE_A_LAST);

    value >>= IMMEDIATE_A_LAST - IMMEDIATE_A_FIRST;

    set(value & mask(0, IMMEDIATE_B_LAST - IMMEDIATE_B_FIRST), IMMEDIATE_B_FIRST, IMMEDIATE_B_LAST);

    value >>= IMMEDIATE_B_LAST - IMMEDIATE_B_FIRST;

    if(value & mask(0, 0)) {
        set(IMMEDIATE_C);
    }else{
        reset(IMMEDIATE_C);
    }

    value >>= 1;

    if(value & mask(0, 0)) {
        set(IMMEDIATE_D);
    }else{
        reset(IMMEDIATE_D);
    }
}

void InstructionTypeSB::setImmediate(string binary)
{
    set(binary.substr(0, IMMEDIATE_A_LAST - IMMEDIATE_A_FIRST), IMMEDIATE_A_FIRST, IMMEDIATE_A_LAST);
    set(binary.substr(IMMEDIATE_A_LAST - IMMEDIATE_A_FIRST + 1, IMMEDIATE_B_LAST - IMMEDIATE_B_FIRST), IMMEDIATE_B_FIRST, IMMEDIATE_B_LAST);
    set(binary.substr(IMMEDIATE_A_LAST - IMMEDIATE_A_FIRST + IMMEDIATE_B_LAST - IMMEDIATE_B_FIRST + 2, 1), IMMEDIATE_C, IMMEDIATE_C);
    set(binary.substr(IMMEDIATE_A_LAST - IMMEDIATE_A_FIRST + IMMEDIATE_B_LAST - IMMEDIATE_B_FIRST + 3, 1), IMMEDIATE_D, IMMEDIATE_D);
}

DATA InstructionTypeSB::getIntegerImmediate()
{

    return (getInteger(IMMEDIATE_D, IMMEDIATE_D) << (IMMEDIATE_A_LAST - IMMEDIATE_A_FIRST + IMMEDIATE_B_LAST - IMMEDIATE_B_FIRST + 3)) & (getInteger(IMMEDIATE_C, IMMEDIATE_C) << (IMMEDIATE_A_LAST - IMMEDIATE_A_FIRST + IMMEDIATE_B_LAST - IMMEDIATE_B_FIRST + 2)) & (getInteger(IMMEDIATE_B_FIRST, IMMEDIATE_B_LAST) << (IMMEDIATE_A_LAST - IMMEDIATE_A_FIRST)) & getInteger(IMMEDIATE_A_FIRST, IMMEDIATE_A_LAST);
}

string InstructionTypeSB::getStringImmediate()
{
    return getString(IMMEDIATE_A_FIRST, IMMEDIATE_A_LAST).append(getString(IMMEDIATE_B_FIRST, IMMEDIATE_B_LAST)).append(getString(IMMEDIATE_C, IMMEDIATE_C)).append(getString(IMMEDIATE_D, IMMEDIATE_D));
}

void InstructionTypeSB::setRS2(DATA value)
{
    set(value, RS2_FIRST, RS2_LAST);
}

void InstructionTypeSB::setRS2(string binary)
{
    set(binary, RS2_FIRST, RS2_LAST);
}

DATA InstructionTypeSB::getIntegerRS2()
{
    return getInteger(RS2_FIRST, RS2_LAST);
}

string InstructionTypeSB::getStringRS2()
{
    return getString(RS2_FIRST, RS2_LAST);
}

InstructionTypeSB::~InstructionTypeSB()
{

}
