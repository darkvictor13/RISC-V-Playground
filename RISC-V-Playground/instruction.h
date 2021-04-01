#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <iostream>
#include <cstdlib>

#define OP_SIZE  7
#define RD_SIZE  5
#define F3_SIZE  3
#define RS1_SIZE 5

#define OP_BEGIN  0
#define RD_BEGIN  7
#define F3_BEGIN  12
#define RS1_BEGIN 15

#define INSTRUCTION_SIZE 32

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
    virtual bool * instructionToBin() = 0;
};

#endif // INSTRUCTION_H
