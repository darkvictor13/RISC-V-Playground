/**
 * @file instructionmemory.cpp
 * @brief Arquivo responsável por implementar a classe InstructionMemory
 * @author mGuerra
 * @version 0.1
*/

#include "instructionmemory.h"

/**
 * @brief InstructionMemory::InstructionMemory: Construtor da classe
 */
InstructionMemory::InstructionMemory()
{

}

/**
 * @brief InstructionMemory::connect: Conecta via ponteiro
 * aos elementos necessários para passagem de dados

 * @param Control control
 * @param Registers registers
 * @param ImmGen immGen
 * @param ALUControl aluControl
 */
void InstructionMemory::connect(Control *control, Registers *registers, ImmGen *immGen, ALUControl *aluControl)
{
    this->control = control;
    this->registers = registers;
    this->immGen = immGen;
    this->aluControl = aluControl;
}

void InstructionMemory::setAddress(Word address)
{
    this->address = address;
    hasAddress = true;

    emit receivedAddress(address);

    tryExecute();
}

/**
 * @brief InstructionMemory::tryExecute: Tenta Executar o subcircuito
 *
 * @warning Executa apenas quando Possui todos os valores

 */
void InstructionMemory::tryExecute()
{
    if(hasAddress) {
        emit executed();

        hasAddress = false;

        execute();

        address = 0;
    }
}

/**
 * @brief InstructionMemory::execute: Realiza todas as ações propostas pela classe
 */
void InstructionMemory::execute()
{
    Word value = getValue(address);

    control->setOpcode(value.getInteger(0, 6));
    registers->setReadRegister1(value.getInteger(15, 19));
    registers->setReadRegister2(value.getInteger(20, 24));
    registers->setWriteRegister(value.getInteger(7, 11));
    immGen->setInstruction(value);

    Word instruction = (value.getInteger(30, 30) << 3) | value.getInteger(12, 14);

    aluControl->setInstruction(instruction);
}

/**
 * @brief InstructionMemory::~InstructionMemory: Destrutor da classe
 */
InstructionMemory::~InstructionMemory()
{

}
