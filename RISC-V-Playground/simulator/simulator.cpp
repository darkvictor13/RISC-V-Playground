/**
 * @file simulator.cpp
 * @brief
 * @author mGuerra
 * @version 0.1
*/

#include "simulator.h"

Simulator::Simulator()
{
    pc.connect(&instructionMemory, &addBranch, &addNext);

    aluControl.connect(&alu);
    control.connect(&andGate, &dataMemory, &muxB, &muxC, &aluControl, &registers);

    registers.connect(&alu, &muxB, &dataMemory);
    instructionMemory.connect(&control, &registers, &immGen, &aluControl);
    dataMemory.connect(&muxC);

    alu.connect(&instructionMemory, &andGate, &muxC);
    addNext.connect(&muxA);
    addBranch.connect(&muxA);

    immGen.connect(&addBranch, &muxB);

    muxA.connect(&pc);
    muxB.connect(&alu);
    muxC.connect(&registers);

    andGate.connect(&muxA);
}

void Simulator::run()
{

}

void Simulator::step()
{

}

void Simulator::restart()
{

}

void Simulator::loadMemory(QString fileName)
{
    instructionMemory.loadMemory(fileName);
}

Simulator::~Simulator()
{

}
