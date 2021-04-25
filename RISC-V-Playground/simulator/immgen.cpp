/**
 * @file instructiontypesb.cpp
 * @brief Arquivo responsável por implementar a classe
 * @author mGuerra
 * @version 0.1
*/

#include "immgen.h"

ImmGen::ImmGen()
{

}

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

void ImmGen::tryExecute()
{
    if(hasInstruction) {
        emit executed();

        hasInstruction = false;

        execute();

        instruction = 0;
    }
}

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

ImmGen::~ImmGen()
{

}
