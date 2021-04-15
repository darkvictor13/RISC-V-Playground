/**
 * @file instruction.h
 * @brief
 * @author mGuerra
 * @version 0.1
*/

#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "word/word.h"

#define OPCODE_FIRST 0
#define OPCODE_LAST 6

#define FUNCT3_FIRST 12
#define FUNCT3_LAST 14

#define RS1_FIRST 15
#define RS1_LAST 19

class Instruction : public Word
{
public:
    Instruction();
    Instruction(Word *word) : Word(*word) {};
    Instruction(DATA value) : Word(value) {};
    Instruction(QString binary) : Word(binary) {};

    void setOpcode(DATA value);
    void setOpcode(QString binary);
    DATA getIntegerOpcode();
    QString getStringOpcode();

    void setFunct3(DATA value);
    void setFunct3(QString binary);
    DATA getIntegerFunct3();
    QString getStringFunct3();

    void setRS1(DATA value);
    void setRS1(QString binary);
    DATA getIntegerRS1();
    QString getStringRS1();

    ~Instruction();
};

#endif // INSTRUCTION_H
