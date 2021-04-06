/**
  @file instructiontyper.cpp
  @brief Arquivo que implementa os métodos da classe InstructionTypeR
  @author Victor Emanuel Almeida
  @version 0.1
*/

#include "instructiontyper.h"

/**
 * @brief Construtor da classe InstructionTypeR
 *
 * Inicializa todos os campos com zero
 */
InstructionTypeR::InstructionTypeR() : Instruction()
{
    cout << "Inicializando uma instrução do TIPO R, com zeros" << endl;
    this->funct_7   = 0;
    this->reg_src_2 = 0;
}

/**
 * @brief Inicializa todos os valores com os passados por parâmetro
 * @param op valor do opcode
 * @param rd valor do registrador destino
 * @param f3 valor do funct 3
 * @param rs1 valor do registrador fonte 1
 * @param rs2 valor do registrador fonte 1
 * @param f7 valor do funct 7
 * @overload InstructionTypeR::InstructionTypeR(int op, int rd, int f3, int rs1, int rs2, int f7)
 */
InstructionTypeR::InstructionTypeR(int op, int rd, int f3, int rs1, int rs2, int f7)
    : Instruction(op, rd, f3, rs1)
{
    cout << "Inicializando uma instrução do TIPO R, com parâmetros" << endl;
    this->funct_7   = f7;
    this->reg_src_2 = rs2;
}

/**
 * @brief Cria um vetor contendo o valor binário da instrução
 *
 * Dá para escrever mais aqui
 * @warning o vetor dinâmico de valores booleanos deve ser desalocado por quem chamou.
 * @pre Todos os membros da classe devem estar inicializados.
 * @post cria o vetor dinâmico de valores booleanos, contendo o valor binário da instrução.
 * @return vetor de valores booleanos, contendo o valor binário da instrução.
 */
bool * InstructionTypeR::instructionToBin()
{
   bool *resp = (bool*)malloc(INSTRUCTION_SIZE * sizeof(bool));
   *resp = {0};

   int casa_atual;
   int num = this->getOpcode();
   for(casa_atual = OP_BEGIN; casa_atual < RD_BEGIN; casa_atual++) {
       resp[casa_atual] = num % 2;
       num /= 2;
   }

   for(num = this->getRegDest(); casa_atual < F3_BEGIN; casa_atual++) {
       resp[casa_atual] = num % 2;
       num /= 2;
   }

   for(num = this->getFunc3(); casa_atual < RS1_BEGIN; casa_atual++) {
       resp[casa_atual] = num % 2;
       num /= 2;
   }

   for(num = this->getRegSrc1(); casa_atual < RS2_BEGIN; casa_atual++) {
       resp[casa_atual] = num % 2;
       num /= 2;
   }

   for(num = this->reg_src_2; casa_atual < F7_BEGIN; casa_atual++) {
       resp[casa_atual] = num % 2;
       num /= 2;
   }

   for(num = this->funct_7; casa_atual < INSTRUCTION_SIZE; casa_atual++) {
       resp[casa_atual] = num % 2;
       num /= 2;
   }

   return resp;
}

/**
 * @brief Imprime na tela todas as informações dos membros da classe
 *
 * @warning utiliza a função Instruction::dafaultPrintInfo();
 */
void InstructionTypeR::printInfo()
{
    this->dafaultPrintInfo();
    cout << "Registrador sorce 2 = x" << this->reg_src_2 << endl;
    cout << "Funct 7             = " << this->funct_7    << endl;
}

/**
 * @brief Destrutor da classe InstructionTypeR
 */
InstructionTypeR::~InstructionTypeR()
{
    cout << "Destruindo uma instrução do TIPO R" << endl;
}
