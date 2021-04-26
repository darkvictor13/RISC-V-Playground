/**
 * @file instruction.cpp
 * @brief Arquivo responsável por implementar a classe Instruction
 * @author mGuerra
 * @version 0.1
*/

#include "instruction.h"

/**
 * @brief Instruction::Instruction: contrutor da classe Instruction
 */
Instruction::Instruction()
{

}

/**
 * @brief Instruction::setOpcode: função que coloca o Opcode de uma função
 * @param DATA value: valor a ser colocado no campo do Opcode
 */
void Instruction::setOpcode(DATA value)
{
    set(value, OPCODE_FIRST, OPCODE_LAST);
}

/**
 * @brief Instruction::setOpcode: função que coloca o Opcode de uma função
 * @param QString binary:
 */
void Instruction::setOpcode(QString binary)
{
    set(binary, OPCODE_FIRST, OPCODE_LAST);
}

/**
 * @brief Instruction::getIntegerOpcode: função que permite extrair o valor do Opcode de uma instrução
 * @return DATA: valor inteiro contido em Opcode
 */
DATA Instruction::getIntegerOpcode()
{
    return getInteger(OPCODE_FIRST, OPCODE_LAST);
}

/**
 * @brief Instruction::getStringOpcode: função que permite extrair o valor do Opcode de uma instrução
 * @return QString: string dos bits que conformam o Opcode
 */
QString Instruction::getStringOpcode()
{
    return getString(OPCODE_FIRST, OPCODE_LAST);
}

/**
 * @brief Instruction::setFunct3
 * @param value
 */
void Instruction::setFunct3(DATA value)
{
    set(value, FUNCT3_FIRST, FUNCT3_LAST);
}

/**
 * @brief Instruction::setFunct3
 * @param QString binary
 */
void Instruction::setFunct3(QString binary)
{
    set(binary, FUNCT3_FIRST, FUNCT3_LAST);
}

/**
 * @brief Instruction::getIntegerFunct3: função que permite extrair o valor do Funct3 de uma instrução
 * @return DATA: valor inteiro contido em Funct3
 */
DATA Instruction::getIntegerFunct3()
{
    return getInteger(FUNCT3_FIRST, FUNCT3_LAST);
}

/**
 * @brief Instruction::getStringFunct3: função que permite extrair o valor do Funct3 de uma instrução
 * @return QString: string dos bits que conformam o Funct3
 */
QString Instruction::getStringFunct3()
{
    return getString(FUNCT3_FIRST, FUNCT3_LAST);
}

/**
 * @brief Instruction::setRS1
 * @param value
 */
void Instruction::setRS1(DATA value)
{
    set(value, RS1_FIRST, RS1_LAST);
}

/**
 * @brief Instruction::setRS1
 * @param QString binary
 */
void Instruction::setRS1(QString binary)
{
    set(binary, RS1_FIRST, RS1_LAST);
}

/**
 * @brief Instruction::getIntegerRS1: função que permite extrair o valor do RS1 de uma instrução
 * @return DATA: valor inteiro contido em RS1
 */
DATA Instruction::getIntegerRS1()
{
    return getInteger(RS1_FIRST, RS1_LAST);
}

/**
 * @brief Instruction::getStringRS1: função que permite extrair o valor do RS1 de uma instrução
 * @return QString: string dos bits que conformam o RS1
 */
QString Instruction::getStringRS1()
{
    return getString(RS1_FIRST, RS1_LAST);
}

/**
 * @brief Instruction::~Instruction: destrutor da classe Instruction
 */
Instruction::~Instruction()
{

}

