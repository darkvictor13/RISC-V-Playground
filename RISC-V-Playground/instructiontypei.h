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

    void setRD(DATA value);
    void setRD(string binary);
    DATA getIntegerRD();
    string getStringRD();

    void setImmediate(DATA value);
    void setImmediate(string binary);
    DATA getIntegerImmediate();
    string getStringImmediate();

    ~InstructionTypeI();
};

#endif // INSTRUCTIONTYPEI_H
