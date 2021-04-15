/**
 * @file instruction.cpp
 * @brief
 * @author mGuerra
 * @version 0.1
*/

#include "instruction.h"

Instruction::Instruction()
{

}

void Instruction::setOpcode(DATA value)
{
    set(value, OPCODE_FIRST, OPCODE_LAST);
}

void Instruction::setOpcode(QString binary)
{
    set(binary, OPCODE_FIRST, OPCODE_LAST);
}

DATA Instruction::getIntegerOpcode()
{
    return getInteger(OPCODE_FIRST, OPCODE_LAST);
}

QString Instruction::getStringOpcode()
{
    return getString(OPCODE_FIRST, OPCODE_LAST);
}

void Instruction::setFunct3(DATA value)
{
    set(value, FUNCT3_FIRST, FUNCT3_LAST);
}

void Instruction::setFunct3(QString binary)
{
    set(binary, FUNCT3_FIRST, FUNCT3_LAST);
}

DATA Instruction::getIntegerFunct3()
{
    return getInteger(FUNCT3_FIRST, FUNCT3_LAST);
}

QString Instruction::getStringFunct3()
{
    return getString(FUNCT3_FIRST, FUNCT3_LAST);
}

void Instruction::setRS1(DATA value)
{
    set(value, RS1_FIRST, RS1_LAST);
}

void Instruction::setRS1(QString binary)
{
    set(binary, RS1_FIRST, RS1_LAST);
}

DATA Instruction::getIntegerRS1()
{
    return getInteger(RS1_FIRST, RS1_LAST);
}

QString Instruction::getStringRS1()
{
    return getString(RS1_FIRST, RS1_LAST);
}

Instruction::~Instruction()
{

}

