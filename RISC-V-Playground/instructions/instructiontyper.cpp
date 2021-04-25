/**
 * @file instructiontyper.cpp
 * @brief Arquivo responsável por implementar a classe
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

void InstructionTypeR::setRD(QString binary)
{
    set(binary, RD_FIRST, RD_LAST);
}

DATA InstructionTypeR::getIntegerRD()
{
    return getInteger(RD_FIRST, RD_LAST);
}

QString InstructionTypeR::getStringRD()
{
    return getString(RD_FIRST, RD_LAST);
}

void InstructionTypeR::setRS2(DATA value)
{
    set(value, RS2_FIRST, RS2_LAST);
}

void InstructionTypeR::setRS2(QString binary)
{
    set(binary, RS2_FIRST, RS2_LAST);
}

DATA InstructionTypeR::getIntegerRS2()
{
    return getInteger(RS2_FIRST, RS2_LAST);
}

QString InstructionTypeR::getStringRS2()
{
    return getString(RS2_FIRST, RS2_LAST);
}

void InstructionTypeR::setFunct7(DATA value)
{
    set(value, FUNCT7_FIRST, FUNCT7_LAST);
}

void InstructionTypeR::setFunct7(QString binary)
{
    set(binary, FUNCT7_FIRST, FUNCT7_LAST);
}

DATA InstructionTypeR::getIntegerFunct7()
{
    return getInteger(FUNCT7_FIRST, FUNCT7_LAST);
}

QString InstructionTypeR::getStringFunct7()
{
    return getString(FUNCT7_FIRST, FUNCT7_LAST);
}

InstructionTypeR::~InstructionTypeR()
{

}
