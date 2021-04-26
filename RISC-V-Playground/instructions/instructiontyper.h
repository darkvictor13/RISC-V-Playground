/**
 * @file instructiontyper.h
 * @brief Arquivo responsável por definir a classe InstructionTypeR
 * @author mGuerra
 * @version 0.1
*/

#ifndef INSTRUCTIONTYPER_H
#define INSTRUCTIONTYPER_H

#include "instruction.h"

/**
  * @brief Indica o início do Registrador Destino
  */
#define RD_FIRST 7

/**
  * @brief Indica o fim do Registrador Destino
  */
#define RD_LAST 11

/**
  * @brief Indica o início do Registrador Source 2
  */
#define RS2_FIRST 20

/**
  * @brief Indica o fim do Registrador Source 2
  */
#define RS2_LAST 24

/**
  * @brief Indica o início do Funct 7
  */
#define FUNCT7_FIRST 25

/**
  * @brief Indica o fim do Funct 7
  */
#define FUNCT7_LAST 31

/**
 * @brief A classe InstructionTypeR: representa uma instrução do tipo R
 */
class InstructionTypeR : public Instruction
{
public:
    InstructionTypeR();
    InstructionTypeR(Word *word) : Instruction(word) {};

    void setRD(DATA value);
    void setRD(QString binary);
    DATA getIntegerRD();
    QString getStringRD();

    void setRS2(DATA value);
    void setRS2(QString binary);
    DATA getIntegerRS2();
    QString getStringRS2();

    void setFunct7(DATA value);
    void setFunct7(QString binary);
    DATA getIntegerFunct7();
    QString getStringFunct7();

    ~InstructionTypeR();
};

#endif // INSTRUCTIONTYPER_H
