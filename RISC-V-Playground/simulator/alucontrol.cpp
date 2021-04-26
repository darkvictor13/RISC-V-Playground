/**
 * @file alucontrol.cpp
 * @brief Arquivo responsável por implementar a classe ALUControl
 * @author mGuerra
 * @version 0.1
*/

#include "alucontrol.h"

/**
 * @brief ALUControl::ALUControl: Construtor da classe
 */
ALUControl::ALUControl()
{

}

/**
 * @brief ALUControl::connect: Conecta via ponteiro
 * aos elementos necessários para passagem de dados
 * @param ALU alu: A unidade lógica e aritimética
 */
void ALUControl::connect(ALU *alu)
{
    this->alu = alu;
}

/**
 * @brief ALUControl::setInstruction: Recebe uma instrução
 * a ser decodificada
 * @param Word instruction: Palavra recebida
 */
void ALUControl::setInstruction(Word instruction)
{
    this->instruction = instruction;
    hasInstruction = true;

    emit receivedInstruction(instruction);

    tryExecute();
}

/**
 * @brief ALUControl::setALUOp: Altera o valor contido
 * na variável aluOp
 * @param aluOp: Valor a ser escrito
 */
void ALUControl::setALUOp(Word aluOp)
{
    this->aluOp = aluOp;
    hasALUOp = true;

    emit receivedALUOp(aluOp);

    tryExecute();
}

/**
 * @brief ALUControl::tryExecute: Tenta Executar o subcircuito
 *
 * @warning Executa apenas quando Possui todos os valores
 */
void ALUControl::tryExecute()
{
    if(hasALUOp && hasInstruction) {
        emit executed();

        hasInstruction = false;
        hasALUOp = false;

        execute();

        instruction = 0;
        aluOp = 0;
    }
}

/**
 * @brief ALUControl::execute: Realiza todas as ações propostas pela classe
 */
void ALUControl::execute()
{
    alu->setReverse(instruction.getInteger(0, 0));

    if(aluOp == 0) {
        alu->setControl(2);
        return;
    }

    if(aluOp == 1) {
        alu->setControl(6);
        return;
    }

    if(aluOp == 2) {
        if(instruction == 0) {
            alu->setControl(2);
            return;
        }

        if(instruction == 6) {
            alu->setControl(1);
            return;
        }

        if(instruction == 7) {
            alu->setControl(0);
            return;
        }

        if(instruction == 8) {
            alu->setControl(6);
            return;
        }
    }
}

/**
 * @brief ALUControl::~ALUControl: Destrutor da classe
 */
ALUControl::~ALUControl()
{

}
