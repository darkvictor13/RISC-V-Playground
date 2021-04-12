/**
 * @file instruction.cpp
 * @brief Arquivo que implementa os métodos da classe Instruction
 * @author mGuerra
 * @version 0.1
*/

#include "instruction.h"

Instruction::Instruction()
{
    cout << "Criei uma intrução" << endl;
}

void Instruction::setOpcode(DATA value)
{
    set(value, OPCODE_FIRST, OPCODE_LAST);
}

void Instruction::setOpcode(string binary)
{
    set(binary, OPCODE_FIRST, OPCODE_LAST);
}

DATA Instruction::getIntegerOpcode()
{
    return getInteger(OPCODE_FIRST, OPCODE_LAST);
}

string Instruction::getStringOpcode()
{
    return getString(OPCODE_FIRST, OPCODE_LAST);
}

void Instruction::setFunct3(DATA value)
{
    set(value, FUNCT3_FIRST, FUNCT3_LAST);
}

void Instruction::setFunct3(string binary)
{
    set(binary, FUNCT3_FIRST, FUNCT3_LAST);
}

DATA Instruction::getIntegerFunct3()
{
    return getInteger(FUNCT3_FIRST, FUNCT3_LAST);
}

string Instruction::getStringFunct3()
{
    return getString(FUNCT3_FIRST, FUNCT3_LAST);
}

void Instruction::setRS1(DATA value)
{
    set(value, RS1_FIRST, RS1_LAST);
}

void Instruction::setRS1(string binary)
{
    set(binary, RS1_FIRST, RS1_LAST);
}

DATA Instruction::getIntegerRS1()
{
    return getInteger(RS1_FIRST, RS1_LAST);
}

string Instruction::getStringRS1()
{
    return getString(RS1_FIRST, RS1_LAST);
}

Instruction::~Instruction()
{

}

