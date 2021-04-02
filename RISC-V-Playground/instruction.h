/**
  @file instruction.h
  @brief Arquivo que define a classe Instruction
  @author Victor Emanuel Almeida
  @version 0.1
*/

#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <iostream>
#include <cstdlib>

using namespace std;

#define OP_SIZE  7
#define RD_SIZE  5
#define F3_SIZE  3
#define RS1_SIZE 5

/**
  * @brief Indica o indice do vetor binário em que inicia o
  * a informação de qual é o opcode
  */
#define OP_BEGIN  0

/**
  * @brief Indica o indice do vetor binário em que inicia o
  * a informação de qual é o registrador destino
  */
#define RD_BEGIN  7

/**
  * @brief Indica o indice do vetor binário em que inicia o
  * a informação de qual é o funct 3
  */
#define F3_BEGIN  12

/**
  * @brief Indica o indice do vetor binário em que inicia o
  * a informação de qual é o registrador sorce 1
  */
#define RS1_BEGIN 15

/**
  * @brief Indica o tamanho total da instrução
  */
#define INSTRUCTION_SIZE 32

/**
 * @brief A classe Instruction: Classe abstrata a qual é base para
 * todos os modos de instrução
 */
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

    void dafaultPrintInfo();

    /**
     * @brief printInfo: uma função virtual pura que permite
     * que essa classe seja abstrata
     */
    virtual void printInfo() = 0;

    /**
     * @brief instructionToBin: uma função virtual pura
     * @return nas classes derivadas deve ser um vetor de booleanos
     * que representa o valor da instrução em binário
     */
    virtual bool * instructionToBin() = 0;

    virtual ~Instruction();
};

#endif // INSTRUCTION_H
