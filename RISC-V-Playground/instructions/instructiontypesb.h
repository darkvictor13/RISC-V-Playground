/**
 * @file instructiontypesb.h
 * @brief Arquivo responsável por definir a classe
 * @author mGuerra
 * @version 0.1
*/

#ifndef INSTRUCTIONTYPESB_H
#define INSTRUCTIONTYPESB_H

#include "instruction.h"

/**
  * @brief Indica o índice do bit que representa 2^11
  */
#define SB_IMMEDIATE_C 7

/**
  * @brief Indica o início da primeira parte do imediato
  */
#define SB_IMMEDIATE_A_FIRST 8

/**
  * @brief Indica o fim da primeira parte do imediato
  */
#define SB_IMMEDIATE_A_LAST 11

/**
  * @brief Indica o início do Registrador Source 2
  */
#define RS2_FIRST 20

/**
  * @brief Indica o fun do Registrador Source 2
  */
#define RS2_LAST 24

/**
  * @brief Indica o início da segunda parte do imediato
  */
#define SB_IMMEDIATE_B_FIRST 25

/**
  * @brief Indica o fim da segunda parte do imediato
  */
#define SB_IMMEDIATE_B_LAST 30

/**
  * @brief Indica o índice do bit que representa 2^12
  */
#define SB_IMMEDIATE_D 31

/**
  * @brief Indica o tamanho total da primeira parte do imediato
  */
#define SIZE_IMMEDIATE_A (SB_IMMEDIATE_A_LAST - SB_IMMEDIATE_A_FIRST + 1)

/**
  * @brief Indica o tamanho total da segunda parte do imediato
  */
#define SIZE_IMMEDIATE_B (SB_IMMEDIATE_B_LAST - SB_IMMEDIATE_B_FIRST + 1)

/**
 * @brief A classe InstructionTypeSB: representa uma instrução do tipo SB
 */
class InstructionTypeSB : public Instruction
{
public:
    InstructionTypeSB();
    InstructionTypeSB(Word *word) : Instruction(word) {};

    void setImmediate(DATA value);
    void setImmediate(QString binary);
    DATA getIntegerImmediate();
    QString getStringImmediate();

    void setRS2(DATA value);
    void setRS2(QString binary);
    DATA getIntegerRS2();
    QString getStringRS2();

    ~InstructionTypeSB();
};

#endif // INSTRUCTIONTYPESB_H
