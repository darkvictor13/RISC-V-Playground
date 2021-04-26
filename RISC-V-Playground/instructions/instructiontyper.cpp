/**
 * @file instructiontyper.cpp
 * @brief Arquivo responsável por implementar a classe
 * @author mGuerra
 * @version 0.1
*/

#include "instructiontyper.h"

/**
 * @brief InstructionTypeR::InstructionTypeR: contrutor da classe InstructionR
 */
InstructionTypeR::InstructionTypeR()
{

}

/**
 * @brief InstructionTypeR::setRD
 * @param value
 */
void InstructionTypeR::setRD(DATA value)
{
    set(value, RD_FIRST, RD_LAST);
}

/**
 * @brief InstructionTypeR::setRD
 * @param QString binary
 */
void InstructionTypeR::setRD(QString binary)
{
    set(binary, RD_FIRST, RD_LAST);
}

/**
 * @brief InstructionTypeR::getIntegerRD: função que permite extrair o valor do RD de uma instrução
 * @return DATA: valor inteiro contido em RD
 */
DATA InstructionTypeR::getIntegerRD()
{
    return getInteger(RD_FIRST, RD_LAST);
}

/**
 * @brief InstructionTypeR::getStringRD: função que permite extrair o valor do RD de uma instrução
 * @return QString: string dos bits que conformam o RD
 */
QString InstructionTypeR::getStringRD()
{
    return getString(RD_FIRST, RD_LAST);
}

/**
 * @brief InstructionTypeR::setRS2
 * @param value
 */
void InstructionTypeR::setRS2(DATA value)
{
    set(value, RS2_FIRST, RS2_LAST);
}

/**
 * @brief InstructionTypeR::setRS2
 * @param QString binary
 */
void InstructionTypeR::setRS2(QString binary)
{
    set(binary, RS2_FIRST, RS2_LAST);
}

/**
 * @brief InstructionTypeR::getIntegerRS2: função que permite extrair o valor do RS2 de uma instrução
 * @return DATA: valor inteiro contido em RS2
 */
DATA InstructionTypeR::getIntegerRS2()
{
    return getInteger(RS2_FIRST, RS2_LAST);
}

/**
 * @brief InstructionTypeR::getStringRS2: função que permite extrair o valor do RS2 de uma instrução
 * @return QString: string dos bits que conformam o RS2
 */
QString InstructionTypeR::getStringRS2()
{
    return getString(RS2_FIRST, RS2_LAST);
}

/**
 * @brief InstructionTypeR::setFunct7
 * @param value
 */
void InstructionTypeR::setFunct7(DATA value)
{
    set(value, FUNCT7_FIRST, FUNCT7_LAST);
}

/**
 * @brief InstructionTypeR::setFunct7
 * @param QString binary
 */
void InstructionTypeR::setFunct7(QString binary)
{
    set(binary, FUNCT7_FIRST, FUNCT7_LAST);
}

/**
 * @brief InstructionTypeR::getIntegerFunct7: função que permite extrair o valor do Funct7 de uma instrução
 * @return DATA: valor inteiro contido em Funct7
 */
DATA InstructionTypeR::getIntegerFunct7()
{
    return getInteger(FUNCT7_FIRST, FUNCT7_LAST);
}

/**
 * @brief InstructionTypeR::getStringFunct7: função que permite extrair o valor do Funct7 de uma instrução
 * @return QString: string dos bits que conformam o Funct7
 */
QString InstructionTypeR::getStringFunct7()
{
    return getString(FUNCT7_FIRST, FUNCT7_LAST);
}

/**
 * @brief InstructionTypeR::~InstructionTypeR: destrutor da classe InstructionR
 */
InstructionTypeR::~InstructionTypeR()
{

}
