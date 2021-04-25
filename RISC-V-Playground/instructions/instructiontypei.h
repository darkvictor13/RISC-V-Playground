/**
 * @file instructiontypei.h
 * @brief
 * @author mGuerra
 * @version 0.1
*/

#ifndef INSTRUCTIONTYPEI_H
#define INSTRUCTIONTYPEI_H

#include "instruction.h"

#define RD_FIRST 7
#define RD_LAST 11

#define IMMEDIATE_FIRST 20
#define IMMEDIATE_LAST 31

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
