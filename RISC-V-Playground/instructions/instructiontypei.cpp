/**
 * @file instruction.cpp
 * @brief Arquivo responsável por implementar a classe
 * @author mGuerra
 * @version 0.1
*/

#include "instructiontypei.h"

/**
 * @brief InstructionTypeI::InstructionTypeI: contrutor da classe InstructionI
 */
InstructionTypeI::InstructionTypeI()
{

}

/**
 * @brief InstructionTypeI::setRD
 * @param value
 */
void InstructionTypeI::setRD(DATA value)
{
    set(value, RD_FIRST, RD_LAST);
}

/**
 * @brief InstructionTypeI::setRD
 * @param QString binary
 */
void InstructionTypeI::setRD(QString binary)
{
    set(binary, RD_FIRST, RD_LAST);
}

/**
 * @brief InstructionTypeI::getIntegerRD: função que permite extrair o valor do RD de uma instrução do tipo i
 * @return DATA: valor inteiro contido em RD
 */
DATA InstructionTypeI::getIntegerRD()
{
    return getInteger(RD_FIRST, RD_LAST);
}

/**
 * @brief InstructionTypeI::getStringRD: função que permite extrair o valor do RD de uma instrução
 * @return QString: string dos bits que conformam o RD
 */
QString InstructionTypeI::getStringRD()
{
    return getString(RD_FIRST, RD_LAST);
}

/**
 * @brief InstructionTypeI::setImmediate
 * @param value
 */
void InstructionTypeI::setImmediate(DATA value)
{
    set(value, IMMEDIATE_FIRST, IMMEDIATE_LAST);
}

/**
 * @brief InstructionTypeI::setImmediate
 * @param QString binary
 */
void InstructionTypeI::setImmediate(QString binary)
{
    set(binary, IMMEDIATE_FIRST, IMMEDIATE_LAST);
}

/**
 * @brief InstructionTypeI::getIntegerImmediate: função que permite extrair o valor do Immediate de uma instrução
 * @return DATA: valor inteiro contido em Immediate
 */
DATA InstructionTypeI::getIntegerImmediate()
{
    return getInteger(IMMEDIATE_FIRST, IMMEDIATE_LAST);
}

/**
 * @brief InstructionTypeI::getStringImmediate: : função que permite extrair o valor do Immediate de uma instrução
 * @return QString: string dos bits que conformam o Immediate
 */
QString InstructionTypeI::getStringImmediate()
{
    return getString(IMMEDIATE_FIRST, IMMEDIATE_LAST);
}

/**
 * @brief InstructionTypeI::~InstructionTypeI: destrutor da classe InstructionI
 */
InstructionTypeI::~InstructionTypeI()
{

}
