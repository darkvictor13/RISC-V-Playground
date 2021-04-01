#ifndef TIPO_R_HPP
#define TIPO_R_HPP

#include "instruction.hpp"

class Tipo_R : public Instruction {
private:
    int reg_dest2;
    int funct7;
public:
    Tipo_R();
    ~Tipo_R();
};

#endif // TIPO_R_HPP
