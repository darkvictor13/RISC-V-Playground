/**
 * @file instructiontypes.h
 * @brief
 * @author mGuerra
 * @version 0.1
*/

#ifndef INSTRUCTIONTYPES_H
#define INSTRUCTIONTYPES_H

#include "instruction.h"

#define IMMEDIATE_A_FIRST 7
#define IMMEDIATE_A_LAST 11

#define RS2_FIRST 20
#define RS2_LAST 24

#define IMMEDIATE_B_FIRST 25
#define IMMEDIATE_B_LAST 31

/**
 * @brief A classe InstructionTypeS:
 */
class InstructionTypeS : public Instruction
{
public:
    InstructionTypeS();

    void setImmediate(DATA value);
    void setImmediate(string binary);
    DATA getIntegerImmediate();
    string getStringImmediate();

    void setRS2(DATA value);
    void setRS2(string binary);
    DATA getIntegerRS2();
    string getStringRS2();

    ~InstructionTypeS();
};

#endif // INSTRUCTIONTYPES_H
