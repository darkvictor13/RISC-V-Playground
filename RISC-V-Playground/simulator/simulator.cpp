/**
 * @file simulator.cpp
 * @brief Arquivo responsável por implementar a classe
 * @author mGuerra
 * @version 0.1
*/

#include "simulator.h"

Simulator::Simulator()
{
    pc->connect(instructionMemory, addBranch, addNext);

    aluControl->connect(alu);
    control->connect(makeBranch, dataMemory, muxB, muxC, aluControl, registers);

    registers->connect(alu, muxB, dataMemory);
    instructionMemory->connect(control, registers, immGen, aluControl);
    dataMemory->connect(muxC);

    alu->connect(dataMemory, makeBranch, muxC);
    addNext->connect(muxA);
    addBranch->connect(muxA);

    immGen->connect(addBranch, muxB);

    muxA->connect(pc);
    muxB->connect(alu);
    muxC->connect(registers);

    makeBranch->connect(muxA);
}

void Simulator::init()
{
    registers->init();
    instructionMemory->init();
    dataMemory->init();
}

void Simulator::run()
{
    while(instructionMemory->testInstruction(pc->getAddress())) {
        pc->run();
    }
}

void Simulator::step()
{
    pc->run();
}

void Simulator::restart()
{
    pc->restart();
    dataMemory->restart();
}

void Simulator::loadMemory(QString file)
{
    pc->restart();
    dataMemory->restart();
    instructionMemory->restart();
    instructionMemory->takeMemoryData(file);
}

Simulator::~Simulator()
{

}
