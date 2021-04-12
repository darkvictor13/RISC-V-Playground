/**
 * @file instructiontyper.h
 * @brief
 * @author mGuerra
 * @version 0.1
*/

#ifndef INSTRUCTIONTYPER_H
#define INSTRUCTIONTYPER_H

#include "instruction.h"

#define RD_FIRST 7
#define RD_LAST 11

#define RS2_FIRST 20
#define RS2_LAST 24

#define FUNCT7_FIRST 25
#define FUNCT7_LAST 31

class InstructionTypeR : public Instruction
{
public:
    InstructionTypeR();

    void setRD(DATA value);
    void setRD(string binary);
    DATA getIntegerRD();
    string getStringRD();

    void setRS2(DATA value);
    void setRS2(string binary);
    DATA getIntegerRS2();
    string getStringRS2();

    void setFunct7(DATA value);
    void setFunct7(string binary);
    DATA getIntegerFunct7();
    string getStringFunct7();

    ~InstructionTypeR();
};

#endif // INSTRUCTIONTYPER_H
