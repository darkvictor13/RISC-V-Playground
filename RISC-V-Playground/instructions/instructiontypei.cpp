/**
 * @file instructiontypei.cpp
 * @brief Arquivo responsável por implementar a classe InstructionTypeI
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
 * @brief InstructionTypeI::setRD: função que permite colocar um valor no campor do RD
 * @param DATA value: valor a ser colocado no campo do RD
 */
void InstructionTypeI::setRD(DATA value)
{
    set(value, RD_FIRST, RD_LAST);
}

/**
 * @brief InstructionTypeI::setRD: função que permite colocar um valor no campor do RD
 * @param QString binary: string contendo o valor a ser colocado no campo do RD
 */
void InstructionTypeI::setRD(QString binary)
{
    set(binary, RD_FIRST, RD_LAST);
}

/**
 * @brief InstructionTypeI::getIntegerRD: função que permite extrair o valor do RD de uma instrução do tipo I
 * @return DATA: valor inteiro contido em RD
 */
DATA InstructionTypeI::getIntegerRD()
{
    return getInteger(RD_FIRST, RD_LAST);
}

/**
 * @brief InstructionTypeI::getStringRD: função que permite extrair o valor do RD de uma instrução do tipo I
 * @return QString: string dos bits que conformam o RD
 */
QString InstructionTypeI::getStringRD()
{
    return getString(RD_FIRST, RD_LAST);
}

/**
 * @brief InstructionTypeI::setImmediate: função que permite colocar um valor no campor do Immediate
 * @param DATA value: valor a ser colocado no campo do Immediate
 */
void InstructionTypeI::setImmediate(DATA value)
{
    set(value, IMMEDIATE_FIRST, IMMEDIATE_LAST);
}

/**
 * @brief InstructionTypeI::setImmediate: função que permite colocar um valor no campor do Immediate
 * @param QString binary: string contendo o valor a ser colocado no campo do Immediate
 */
void InstructionTypeI::setImmediate(QString binary)
{
    set(binary, IMMEDIATE_FIRST, IMMEDIATE_LAST);
}

/**
 * @brief InstructionTypeI::getIntegerImmediate: função que permite extrair o valor do Immediate de uma instrução do tipo I
 * @return DATA: valor inteiro contido em Immediate
 */
DATA InstructionTypeI::getIntegerImmediate()
{
    return getInteger(IMMEDIATE_FIRST, IMMEDIATE_LAST);
}

/**
 * @brief InstructionTypeI::getStringImmediate: : função que permite extrair o valor do Immediate de uma instrução do tipo I
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
