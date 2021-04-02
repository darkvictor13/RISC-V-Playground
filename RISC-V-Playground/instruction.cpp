/**
  @file instruction.cpp
  @brief Arquivo que implementa os métodos da classe Instruction
  @author Victor Emanuel Almeida
  @version 0.1
*/

#include "instruction.h"

/**
 * @brief Construtor da classe Instruction
 *
 * Inicializa todos os campos com zero
 */
Instruction::Instruction()
{
    cout << "Inicializando uma instrução, com zeros" << endl;
    this->opcode    = 0;
    this->reg_dest  = 0;
    this->funct_3   = 0;
    this->reg_src_1 = 0;
}

/**
 * @brief Inicializa os membros com os valores passados por referência
 * @param op: valor do opcode
 * @param rd: valor do registrador destino
 * @param f3: valor do funct 3
 * @param rs1: valor do registrador fonte 1
 * @overload Instruction::Instruction(int op, int rd, int f3, int rs1)
 */
Instruction::Instruction(int op, int rd, int f3, int rs1)
{
    cout << "Inicializando uma instrução com parâmetros" << endl;
    this->opcode    = op;
    this->reg_dest  = rd;
    this->funct_3   = f3;
    this->reg_src_1 = rs1;
}

/**
 * @brief Obtêm o valor do opcode para alguém fora da classe
 * @return o valor do opcode
 */
int Instruction::getOpcode()
{
    return this->opcode;
}

/**
 * @brief
 * @brief Obtêm o valor do registrador destino para alguém fora da classe
 * @return o valor do registrador de destino
 */
int Instruction::getRegDest()
{
    return this->reg_dest;
}

/**
 * @brief
 * @brief Obtêm o valor do Funct 3 para alguém fora da classe
 * @return o valor do funct3
 */
int Instruction::getFunc3()
{
    return this->funct_3;
}

/**
 * @brief Obtêm o valor do registrador sorce 1 para alguém fora da classe
 * @return valor do registrador fonte 1
 */
int Instruction::getRegSrc1()
{
    return this->reg_src_1;
}

/**
 * @brief Imprime todas as informações contidas na classe base
 *
 * Essas informações devem ser usadas para imprimir dentro das classes derivadas
 * adicionando as informações dos memvros específicos de cada classe
 */
void Instruction::dafaultPrintInfo()
{
    cout << "Opcode              = "  << this->getOpcode()  << endl;
    cout << "Registrador destino = x" << this->getRegDest() << endl;
    cout << "Funct 3             = "  << this->getFunc3()   << endl;
    cout << "Registrador sorce 1 = x" << this->getRegSrc1() << endl;
}

/**
 * @brief Destrutor da classe Instruction
 */
Instruction::~Instruction()
{
    cout << "Destruindo a instrução base" << endl;
}
