/**
 * @file instructiontypes.h
 * @brief
 * @author mGuerra
 * @version 0.1
*/

#ifndef INSTRUCTIONTYPES_H
#define INSTRUCTIONTYPES_H

#include "instruction.h"

#define S_IMMEDIATE_A_FIRST 7
#define S_IMMEDIATE_A_LAST 11

#define RS2_FIRST 20
#define RS2_LAST 24

#define S_IMMEDIATE_B_FIRST 25
#define S_IMMEDIATE_B_LAST 31

class InstructionTypeS : public Instruction
{
public:
    InstructionTypeS();

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
