/**
 * @file instructiontypes.cpp
 * @brief Arquivo responsável por implementar a classe InstructionTypeS
 * @author mGuerra
 * @version 0.1
*/

#include "instructiontypes.h"

/**
 * @brief InstructionTypeS::InstructionTypeS: contrutor da classe InstructionS
 */
InstructionTypeS::InstructionTypeS()
{

}

/**
 * @brief InstructionTypeS::setImmediate: função que permite colocar um valor no campor do Immediate
 * @param DATA value: valor a ser colocado no campo do Immediate
 */
void InstructionTypeS::setImmediate(DATA value)
{
    set(value & mask(0, S_IMMEDIATE_A_LAST - S_IMMEDIATE_A_FIRST), S_IMMEDIATE_A_FIRST, S_IMMEDIATE_A_LAST);
    set(value >> (S_IMMEDIATE_A_LAST - S_IMMEDIATE_A_FIRST), S_IMMEDIATE_B_FIRST, S_IMMEDIATE_B_LAST);
}

/**
 * @brief InstructionTypeS::setImmediate: função que permite colocar um valor no campor do Immediate
 * @param QString binary: string contendo o valor a ser colocado no campo do Immediate
 */
void InstructionTypeS::setImmediate(QString binary)
{
    set(binary.mid(0, S_IMMEDIATE_A_LAST - S_IMMEDIATE_A_FIRST + 1), S_IMMEDIATE_A_FIRST, S_IMMEDIATE_A_LAST);
    set(binary.mid(S_IMMEDIATE_A_LAST - S_IMMEDIATE_A_FIRST + 1), S_IMMEDIATE_B_FIRST, S_IMMEDIATE_B_LAST);
}

/**
 * @brief InstructionTypeS::getIntegerImmediate: função que permite extrair o valor do Immediate de uma instrução do tipo S
 * @return DATA: valor inteiro contido em Immediate
 */
DATA InstructionTypeS::getIntegerImmediate()
{
    return (getInteger(S_IMMEDIATE_B_FIRST, S_IMMEDIATE_B_LAST) << (S_IMMEDIATE_A_LAST - S_IMMEDIATE_A_FIRST)) | getInteger(S_IMMEDIATE_A_FIRST, S_IMMEDIATE_A_LAST);
}

/**
 * @brief InstructionTypeS::getStringImmediate: função que permite extrair o valor do Immediate de uma instrução do tipo S
 * @return QString: string dos bits que conformam o Immediate
 */
QString InstructionTypeS::getStringImmediate()
{
    return getString(S_IMMEDIATE_A_FIRST, S_IMMEDIATE_A_LAST).append(getString(S_IMMEDIATE_B_FIRST, S_IMMEDIATE_B_LAST));
}

/**
 * @brief InstructionTypeS::setRS2: função que permite colocar um valor no campor do RS2
 * @param DATA value: valor a ser colocado no campo do RS2
 */
void InstructionTypeS::setRS2(DATA value)
{
    set(value, RS2_FIRST, RS2_LAST);
}

/**
 * @brief InstructionTypeS::setRS2: função que permite colocar um valor no campor do RS2
 * @param QString binary: string contendo o valor a ser colocado no campo do RS2
 */
void InstructionTypeS::setRS2(QString binary)
{
    set(binary, RS2_FIRST, RS2_LAST);
}

/**
 * @brief InstructionTypeS::getIntegerRS2: função que permite extrair o valor do RS2 de uma instrução do tipo S
 * @return DATA: valor inteiro contido em RS2
 */
DATA InstructionTypeS::getIntegerRS2()
{
    return getInteger(RS2_FIRST, RS2_LAST);
}

/**
 * @brief InstructionTypeS::getStringRS2: função que permite extrair o valor do RS2 de uma instrução do tipo S
 * @return QString: string dos bits que conformam o RS2
 */
QString InstructionTypeS::getStringRS2()
{
    return getString(RS2_FIRST, RS2_LAST);
}

/**
 * @brief InstructionTypeS::~InstructionTypeS: destrutor da classe InstructionS
 */
InstructionTypeS::~InstructionTypeS()
{

}
