#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP


class Instruction {
private:
    int opcode;
    int reg_dest;
    int funct3;
    int reg_src1;
public:
    Instruction();
    Instruction(int o, int rd, int f3, int rs1);

    //virtual double processa()=0;

    int getOpcode();

    //virtual ~Instruction();
    ~Instruction();
};

#endif // INSTRUCTION_HPP
