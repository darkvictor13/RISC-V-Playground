/**
 * @file instructiontypesb.h
 * @brief
 * @author mGuerra
 * @version 0.1
*/

#ifndef INSTRUCTIONTYPESB_H
#define INSTRUCTIONTYPESB_H

#include "instruction.h"

#define SB_IMMEDIATE_C 7

#define SB_IMMEDIATE_A_FIRST 8
#define SB_IMMEDIATE_A_LAST 11

#define RS2_FIRST 20
#define RS2_LAST 24

#define SB_IMMEDIATE_B_FIRST 25
#define SB_IMMEDIATE_B_LAST 30

#define SB_IMMEDIATE_D 31

class InstructionTypeSB : public Instruction
{
public:
    InstructionTypeSB();

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
