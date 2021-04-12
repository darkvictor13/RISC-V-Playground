/**
 * @file instructiontyper.cpp
 * @brief Arquivo que implementa os métodos da classe InstructionTypeR
 * @author mGuerra
 * @version 0.1
*/

#include "instructiontyper.h"

InstructionTypeR::InstructionTypeR()
{

}

void InstructionTypeR::setRD(DATA value)
{
    set(value, RD_FIRST, RD_LAST);
}

void InstructionTypeR::setRD(string binary)
{
    set(binary, RD_FIRST, RD_LAST);
}

DATA InstructionTypeR::getIntegerRD()
{
    return getInteger(RD_FIRST, RD_LAST);
}

string InstructionTypeR::getStringRD()
{
    return getString(RD_FIRST, RD_LAST);
}

void InstructionTypeR::setRS2(DATA value)
{
    set(value, RS2_FIRST, RS2_LAST);
}

void InstructionTypeR::setRS2(string binary)
{
    set(binary, RS2_FIRST, RS2_LAST);
}

DATA InstructionTypeR::getIntegerRS2()
{
    return getInteger(RS2_FIRST, RS2_LAST);
}

string InstructionTypeR::getStringRS2()
{
    return getString(RS2_FIRST, RS2_LAST);
}

void InstructionTypeR::setFunct7(DATA value)
{
    set(value, FUNCT7_FIRST, FUNCT7_LAST);
}

void InstructionTypeR::setFunct7(string binary)
{
    set(binary, FUNCT7_FIRST, FUNCT7_LAST);
}

DATA InstructionTypeR::getIntegerFunct7()
{
    return getInteger(FUNCT7_FIRST, FUNCT7_LAST);
}

string InstructionTypeR::getStringFunct7()
{
    return getString(FUNCT7_FIRST, FUNCT7_LAST);
}

InstructionTypeR::~InstructionTypeR()
{

}
