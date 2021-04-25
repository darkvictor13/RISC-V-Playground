/**
 * @file instructiontypesb.cpp
 * @brief Arquivo responsável por implementar a classe
 * @author mGuerra
 * @version 0.1
*/

#include "instructiontypesb.h"

InstructionTypeSB::InstructionTypeSB()
{

}

void InstructionTypeSB::setImmediate(DATA value)
{
    value >>= 1;

    set(value & mask(0, SB_IMMEDIATE_A_LAST - SB_IMMEDIATE_A_FIRST), SB_IMMEDIATE_A_FIRST, SB_IMMEDIATE_A_LAST);

    value >>= SB_IMMEDIATE_A_LAST - SB_IMMEDIATE_A_FIRST + 1;

    set(value & mask(0, SB_IMMEDIATE_B_LAST - SB_IMMEDIATE_B_FIRST), SB_IMMEDIATE_B_FIRST, SB_IMMEDIATE_B_LAST);

    value >>= SB_IMMEDIATE_B_LAST - SB_IMMEDIATE_B_FIRST + 1;

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
    reverse(binary.begin(), binary.end());

    set(binary.mid(1, SIZE_IMMEDIATE_A), SB_IMMEDIATE_A_FIRST, SB_IMMEDIATE_A_LAST);
    set(binary.mid(SIZE_IMMEDIATE_A + 2, SIZE_IMMEDIATE_B), SB_IMMEDIATE_B_FIRST, SB_IMMEDIATE_B_LAST);
    set(binary.mid(SIZE_IMMEDIATE_A + SIZE_IMMEDIATE_B + 1, 1), SB_IMMEDIATE_C, SB_IMMEDIATE_C);
    set(binary.mid(SIZE_IMMEDIATE_A + SIZE_IMMEDIATE_B + 2, 1), SB_IMMEDIATE_D, SB_IMMEDIATE_D);
}

DATA InstructionTypeSB::getIntegerImmediate()
{
    return ((getInteger(SB_IMMEDIATE_D, SB_IMMEDIATE_D) << (SIZE_IMMEDIATE_A + SIZE_IMMEDIATE_B + 1)) |
           (getInteger(SB_IMMEDIATE_C, SB_IMMEDIATE_C) << (SIZE_IMMEDIATE_A + SIZE_IMMEDIATE_B)) |
           (getInteger(SB_IMMEDIATE_B_FIRST, SB_IMMEDIATE_B_LAST) << SIZE_IMMEDIATE_A) |
           getInteger(SB_IMMEDIATE_A_FIRST, SB_IMMEDIATE_A_LAST)) << 1;
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
