/**
 * @file instructiontypesb.h
 * @brief
 * @author mGuerra
 * @version 0.1
*/

#ifndef INSTRUCTIONTYPESB_H
#define INSTRUCTIONTYPESB_H

#include "instruction.h"

#define IMMEDIATE_C 7
#define IMMEDIATE_A_FIRST 8
#define IMMEDIATE_A_LAST 11

#define RS2_FIRST 20
#define RS2_LAST 24

#define IMMEDIATE_B_FIRST 25
#define IMMEDIATE_B_LAST 30

#define IMMEDIATE_D 31

/**
 * @brief A classe InstructionTypeSB:
 */
class InstructionTypeSB : public Instruction
{
public:
    InstructionTypeSB();

    void setImmediate(DATA value);
    void setImmediate(string binary);
    DATA getIntegerImmediate();
    string getStringImmediate();

    void setRS2(DATA value);
    void setRS2(string binary);
    DATA getIntegerRS2();
    string getStringRS2();

    ~InstructionTypeSB();
};

#endif // INSTRUCTIONTYPESB_H
