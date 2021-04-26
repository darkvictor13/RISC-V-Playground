/**
 * @file instructiontypei.h
 * @brief Arquivo responsável por definir a classe InstructionTypeI
 * @author mGuerra
 * @version 0.1
*/

#ifndef INSTRUCTIONTYPEI_H
#define INSTRUCTIONTYPEI_H

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
  * @brief Indica o início do Imediato
  */
#define IMMEDIATE_FIRST 20

/**
  * @brief Indica o fim do Imediato
  */
#define IMMEDIATE_LAST 31

/**
 * @brief A classe InstructionTypeI: representa uma instrução do tipo I
 */
class InstructionTypeI : public Instruction
{
public:
    InstructionTypeI();
    InstructionTypeI(Word *word) : Instruction(word) {};

    void setRD(DATA value);
    void setRD(QString binary);
    DATA getIntegerRD();
    QString getStringRD();

    void setImmediate(DATA value);
    void setImmediate(QString binary);
    DATA getIntegerImmediate();
    QString getStringImmediate();

    ~InstructionTypeI();
};

#endif // INSTRUCTIONTYPEI_H
