#include "instructiontypei.h"

/**
 * @brief Construtor da classe InstructionTypeI
 *
 * Inicializa todos os campos com zero
 */
InstructionTypeI::InstructionTypeI() : Instruction()
{
    cout << "Inicializando uma instrução do TIPO I, com zeros" << endl;
    this->imediate = 0;
}

/**
 * @brief Inicializa todos os valores com os passados por parâmetro
 * @param op valor do opcode
 * @param rd valor do registrador destino
 * @param f3 valor do funct 3
 * @param rs1 valor do registrador fonte 1
 * @param imm
 * @overload InstructionTypeI::InstructionTypeI(int op, int rd, int f3, int rs1, int imm)
 */
InstructionTypeI::InstructionTypeI(int op, int rd, int f3, int rs1, int imm)
    : Instruction(op, rd, f3, rs1)
{
    cout << "Inicializando uma instrução do TIPO I, com parâmetros" << endl;
    this->imediate = imm;
}


void InstructionTypeI::printInfo()
{
    this->dafaultPrintInfo();
    cout << "Imediate            = "  << this->imediate << endl;
}

bool * InstructionTypeI::instructionToBin()
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

   for(num = this->getRegSrc1(); casa_atual < IMEDIATE_BEGIN; casa_atual++) {
       resp[casa_atual] = num % 2;
       num /= 2;
   }

   for(num = this->imediate; casa_atual < INSTRUCTION_SIZE; casa_atual++) {
       resp[casa_atual] = num % 2;
       num /= 2;
   }

   return resp;
}

/**
 * @brief Destrutor da classe InstructionTypeI
 */
InstructionTypeI::~InstructionTypeI()
{
    cout << "Destruindo uma instrução do TIPO I" << endl;
}
