#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <iostream>

using namespace std;

class Instruction
{
private:
    int opcode;
    int reg_dest;
    int funct_3;
    int reg_src_1;
public:
    Instruction();
    Instruction(int op, int rd, int f3, int rs1);

    int getOpcode();
    int getRegDest();
    int getFunc3();
    int getRegSrc1();

    virtual void printInfo() = 0;
};

#endif // INSTRUCTION_H
