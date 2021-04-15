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
    set(value & mask(0, SB_IMMEDIATE_A_LAST - SB_IMMEDIATE_A_FIRST), SB_IMMEDIATE_A_FIRST, SB_IMMEDIATE_A_LAST);

    value >>= SB_IMMEDIATE_A_LAST - SB_IMMEDIATE_A_FIRST;

    set(value & mask(0, SB_IMMEDIATE_B_LAST - SB_IMMEDIATE_B_FIRST), SB_IMMEDIATE_B_FIRST, SB_IMMEDIATE_B_LAST);

    value >>= SB_IMMEDIATE_B_LAST - SB_IMMEDIATE_B_FIRST;

    if(value & mask(0, 0)) {
        set(SB_IMMEDIATE_C);
    }else{
        reset(SB_IMMEDIATE_C);
    }

    value >>= 1;

    if(value & mask(0, 0)) {
        set(SB_IMMEDIATE_D);
    }else{
        reset(SB_IMMEDIATE_D);
    }
}

void InstructionTypeSB::setImmediate(QString binary)
{
    set(binary.mid(0, SB_IMMEDIATE_A_LAST - SB_IMMEDIATE_A_FIRST), SB_IMMEDIATE_A_FIRST, SB_IMMEDIATE_A_LAST);
    set(binary.mid(SB_IMMEDIATE_A_LAST - SB_IMMEDIATE_A_FIRST + 1, SB_IMMEDIATE_B_LAST - SB_IMMEDIATE_B_FIRST), SB_IMMEDIATE_B_FIRST, SB_IMMEDIATE_B_LAST);
    set(binary.mid(SB_IMMEDIATE_A_LAST - SB_IMMEDIATE_A_FIRST + SB_IMMEDIATE_B_LAST - SB_IMMEDIATE_B_FIRST + 2, 1), SB_IMMEDIATE_C, SB_IMMEDIATE_C);
    set(binary.mid(SB_IMMEDIATE_A_LAST - SB_IMMEDIATE_A_FIRST + SB_IMMEDIATE_B_LAST - SB_IMMEDIATE_B_FIRST + 3, 1), SB_IMMEDIATE_D, SB_IMMEDIATE_D);
}

DATA InstructionTypeSB::getIntegerImmediate()
{

    return (getInteger(SB_IMMEDIATE_D, SB_IMMEDIATE_D) << (SB_IMMEDIATE_A_LAST - SB_IMMEDIATE_A_FIRST + SB_IMMEDIATE_B_LAST - SB_IMMEDIATE_B_FIRST + 3)) & (getInteger(SB_IMMEDIATE_C, SB_IMMEDIATE_C) << (SB_IMMEDIATE_A_LAST - SB_IMMEDIATE_A_FIRST + SB_IMMEDIATE_B_LAST - SB_IMMEDIATE_B_FIRST + 2)) & (getInteger(SB_IMMEDIATE_B_FIRST, SB_IMMEDIATE_B_LAST) << (SB_IMMEDIATE_A_LAST - SB_IMMEDIATE_A_FIRST)) & getInteger(SB_IMMEDIATE_A_FIRST, SB_IMMEDIATE_A_LAST);
}

QString InstructionTypeSB::getStringImmediate()
{
    return getString(SB_IMMEDIATE_A_FIRST, SB_IMMEDIATE_A_LAST).append(getString(SB_IMMEDIATE_B_FIRST, SB_IMMEDIATE_B_LAST)).append(getString(SB_IMMEDIATE_C, SB_IMMEDIATE_C)).append(getString(SB_IMMEDIATE_D, SB_IMMEDIATE_D));
}

void InstructionTypeSB::setRS2(DATA value)
{
    set(value, RS2_FIRST, RS2_LAST);
}

void InstructionTypeSB::setRS2(QString binary)
{
    set(binary, RS2_FIRST, RS2_LAST);
}

DATA InstructionTypeSB::getIntegerRS2()
{
    return getInteger(RS2_FIRST, RS2_LAST);
}

QString InstructionTypeSB::getStringRS2()
{
    return getString(RS2_FIRST, RS2_LAST);
}

InstructionTypeSB::~InstructionTypeSB()
{

}
