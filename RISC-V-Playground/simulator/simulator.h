/**
 * @file simulator.h
 * @brief
 * @author mGuerra
 * @version 0.1
*/

#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <QObject>

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

class Simulator : public QObject
{
    Q_OBJECT

public:
    PC *pc = new PC();

    ALUControl *aluControl = new ALUControl();
    Control *control = new Control;

    Registers *registers = new Registers();
    InstructionMemory *instructionMemory = new InstructionMemory();
    DataMemory *dataMemory = new DataMemory();

    ALU *alu = new ALU();
    AddNext *addNext = new AddNext();
    AddBranch *addBranch = new AddBranch();

    ImmGen *immGen = new ImmGen();

    MuxTypeA *muxA = new MuxTypeA();
    MuxTypeB *muxB = new MuxTypeB();
    MuxTypeC *muxC = new MuxTypeC();

    MakeBranch *makeBranch = new MakeBranch();

    int steps;

    Simulator();

    ~Simulator();

public slots:
    void init();
    void run();
    void step();
    void restart();

    void loadMemory(QString file);

};

#endif // SIMULATOR_H
