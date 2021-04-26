/**
 * @file instructiontypesb.cpp
 * @brief Arquivo responsável por implementar a classe
 * @author mGuerra
 * @version 0.1
*/

#include "instructiontypesb.h"

/**
 * @brief InstructionTypeSB::InstructionTypeSB: contrutor da classe InstructionSB
 */
InstructionTypeSB::InstructionTypeSB()
{

}

/**
 * @brief InstructionTypeSB::setImmediate: função que permite colocar um valor no campor do Immediate
 * @param DATA value: valor a ser colocado no campo do Immediate
 */
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

/**
 * @brief InstructionTypeSB::setImmediate: função que permite colocar um valor no campor do Immediate
 * @param QString binary: string contendo o valor a ser colocado no campo do Immediate
 */
void InstructionTypeSB::setImmediate(QString binary)
{
    reverse(binary.begin(), binary.end());

    set(binary.mid(1, SIZE_IMMEDIATE_A), SB_IMMEDIATE_A_FIRST, SB_IMMEDIATE_A_LAST);
    set(binary.mid(SIZE_IMMEDIATE_A + 2, SIZE_IMMEDIATE_B), SB_IMMEDIATE_B_FIRST, SB_IMMEDIATE_B_LAST);
    set(binary.mid(SIZE_IMMEDIATE_A + SIZE_IMMEDIATE_B + 1, 1), SB_IMMEDIATE_C, SB_IMMEDIATE_C);
    set(binary.mid(SIZE_IMMEDIATE_A + SIZE_IMMEDIATE_B + 2, 1), SB_IMMEDIATE_D, SB_IMMEDIATE_D);
}

/**
 * @brief InstructionTypeSB::getIntegerImmediate: função que permite extrair o valor do Immediate de uma instrução do tipo SB
 * @return DATA valor: inteiro contido em Immediate
 */
DATA InstructionTypeSB::getIntegerImmediate()
{
    return ((getInteger(SB_IMMEDIATE_D, SB_IMMEDIATE_D) << (SIZE_IMMEDIATE_A + SIZE_IMMEDIATE_B + 1)) |
           (getInteger(SB_IMMEDIATE_C, SB_IMMEDIATE_C) << (SIZE_IMMEDIATE_A + SIZE_IMMEDIATE_B)) |
           (getInteger(SB_IMMEDIATE_B_FIRST, SB_IMMEDIATE_B_LAST) << SIZE_IMMEDIATE_A) |
           getInteger(SB_IMMEDIATE_A_FIRST, SB_IMMEDIATE_A_LAST)) << 1;
}

/**
 * @brief InstructionTypeSB::getStringImmediate: função que permite extrair o valor do Immediate de uma instrução do tipo SB
 * @return QString: string dos bits que conformam o Immediate
 */
QString InstructionTypeSB::getStringImmediate()
{
    return getString(SB_IMMEDIATE_A_FIRST, SB_IMMEDIATE_A_LAST).append(getString(SB_IMMEDIATE_B_FIRST, SB_IMMEDIATE_B_LAST)).append(getString(SB_IMMEDIATE_C, SB_IMMEDIATE_C)).append(getString(SB_IMMEDIATE_D, SB_IMMEDIATE_D));
}

/**
 * @brief InstructionTypeSB::setRS2: função que permite colocar um valor no campor do RS2
 * @param DATA value: valor a ser colocado no campo do RS2
 */
void InstructionTypeSB::setRS2(DATA value)
{
    set(value, RS2_FIRST, RS2_LAST);
}

/**
 * @brief InstructionTypeSB::setRS2: função que permite colocar um valor no campor do RS2
 * @param QString binary string contendo o valor a ser colocado no campo do RS2
 */
void InstructionTypeSB::setRS2(QString binary)
{
    set(binary, RS2_FIRST, RS2_LAST);
}

/**
 * @brief InstructionTypeSB::getIntegerRS2: função que permite extrair o valor do RS2 de uma instrução do tipo SB
 * @return DATA: valor inteiro contido em RS2
 */
DATA InstructionTypeSB::getIntegerRS2()
{
    return getInteger(RS2_FIRST, RS2_LAST);
}

/**
 * @brief InstructionTypeSB::getStringRS2: função que permite extrair o valor do RS2 de uma instrução do tipo SB
 * @return QString: string dos bits que conformam o RS2
 */
QString InstructionTypeSB::getStringRS2()
{
    return getString(RS2_FIRST, RS2_LAST);
}

/**
 * @brief InstructionTypeSB::~InstructionTypeSB: destrutor da classe InstructionSB
 */
InstructionTypeSB::~InstructionTypeSB()
{

}
