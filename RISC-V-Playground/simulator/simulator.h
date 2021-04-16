/**
 * @file simulator.h
 * @brief
 * @author mGuerra
 * @version 0.1
*/

#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "pc.h"
#include "alucontrol.h"
#include "control.h"
#include "registers.h"
#include "instructionmemory.h"
#include "datamemory.h"
#include "alu.h"
#include "addnext.h"
#include "addbranch.h"
#include "immgen.h"
#include "muxtypea.h"
#include "muxtypeb.h"
#include "muxtypec.h"

class Simulator
{
private:
    PC pc;

    ALUControl aluControl;
    Control control;

    Registers registers;
    InstructionMemory instructionMemory;
    DataMemory dataMemory;

    ALU alu;
    AddNext addNext;
    AddBranch addBranch;

    ImmGen immGen;

    MuxTypeA muxA;
    MuxTypeB muxB;
    MuxTypeC muxC;

    AndGate andGate;

public:
    Simulator();

    void run();
    void step();
    void restart();

    void loadMemory(QString fileName);

    ~Simulator();
};

#endif // SIMULATOR_H
