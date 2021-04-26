/**
 * @file immgen.cpp
 * @brief Arquivo responsável por implementar a classe ImmGen
 * @author mGuerra
 * @version 0.1
*/

#include "immgen.h"

/**
 * @brief ImmGen::ImmGen: Construtor da classe
 */
ImmGen::ImmGen()
{

}

/**
 * @brief ImmGen::connect: Conecta via ponteiro
 * aos elementos necessários para passagem de dados

 * @param AddBranch addBranch: Circuito Somador
 * @param MuxTypeB muxB: Multiplexador do tipo B
 */
void ImmGen::connect(AddBranch *addBranch, MuxTypeB *muxB)
{
    this->addBranch = addBranch;
    this->muxB = muxB;
}

void ImmGen::setInstruction(Word instruction)
{
    this->instruction = instruction;
    hasInstruction = true;

    emit receivedInstruction(instruction);

    tryExecute();
}

/**
 * @brief ImmGen::tryExecute: Tenta Executar o subcircuito
 *
 * @warning Executa apenas quando Possui todos os valores

 */
void ImmGen::tryExecute()
{
    if(hasInstruction) {
        emit executed();

        hasInstruction = false;

        execute();

        instruction = 0;
    }
}

/**
 * @brief ImmGen::execute: Realiza todas as ações propostas pela classe
 */
void ImmGen::execute()
{
    Instruction instructionFormat(&instruction);

    Word value;
    int opcode = instructionFormat.getIntegerOpcode();

    if(opcode == 19 || opcode == 3) {
        InstructionTypeI instructionTypeI(&instruction);
        value = instructionTypeI.getIntegerImmediate();
        value.extendInt(11);
    }else if(opcode == 35) {
        InstructionTypeS instructionTypeS(&instruction);
        value = instructionTypeS.getIntegerImmediate();
        value.extendInt(11);
    }else if(opcode == 99) {
        InstructionTypeSB instructionTypeSB(&instruction);
        value = instructionTypeSB.getIntegerImmediate();
        value.extendInt(12);
    }else{
        value = 0;
    }

    muxB->setValueB(value);
    addBranch->setValueB(value);
}

/**
 * @brief ImmGen::~ImmGen: Destrutor da classe
 */
ImmGen::~ImmGen()
{

}
