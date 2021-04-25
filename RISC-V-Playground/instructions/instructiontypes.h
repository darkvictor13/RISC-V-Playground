/**
 * @file instructiontypes.h
 * @brief Arquivo responsável por definir a classe
 * @author mGuerra
 * @version 0.1
*/

#ifndef INSTRUCTIONTYPES_H
#define INSTRUCTIONTYPES_H

#include "instruction.h"

/**
  * @brief Indica o início da primeira parte do Imediato
  */
#define S_IMMEDIATE_A_FIRST 7

/**
  * @brief Indica o fim da primeira parte do Imediato
  */
#define S_IMMEDIATE_A_LAST 11

/**
  * @brief Indica o início do Registrador Source 2
  */
#define RS2_FIRST 20

/**
  * @brief Indica o fim do Registrador Source 2
  */
#define RS2_LAST 24

/**
  * @brief Indica o início da segunda parte do Imediato
  */
#define S_IMMEDIATE_B_FIRST 25

/**
  * @brief Indica o fim da segunda parte do Imediato
  */
#define S_IMMEDIATE_B_LAST 31

/**
 * @brief A classe InstructionTypeS:
 */
class InstructionTypeS : public Instruction
{
public:
    InstructionTypeS();
    InstructionTypeS(Word *word) : Instruction(word) {};

    void setImmediate(DATA value);
    void setImmediate(QString binary);
    DATA getIntegerImmediate();
    QString getStringImmediate();

    void setRS2(DATA value);
    void setRS2(QString binary);
    DATA getIntegerRS2();
    QString getStringRS2();

    ~InstructionTypeS();
};

#endif // INSTRUCTIONTYPES_H
