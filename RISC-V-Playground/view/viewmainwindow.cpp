/**
 * @file viewmainwindow.cpp
 * @brief
 * @author mGuerra
 * @version 0.1
*/

#include "viewmainwindow.h"
#include "ui_viewmainwindow.h"

#define INSTRUCTION_ADDRESS 1000
#define DATA_ADDRESS 2000

ViewMainWindow::ViewMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ViewMainWindow)
{
    ui->setupUi(this);

    QObject::connect(this, &ViewMainWindow::assemble, assembler, &Assembler::assemble);
    QObject::connect(assembler, &Assembler::consoleLog, this, &ViewMainWindow::consoleLog);

    QObject::connect(this, &ViewMainWindow::init, simulator, &Simulator::init);
    QObject::connect(this, &ViewMainWindow::run, simulator, &Simulator::run);
    QObject::connect(this, &ViewMainWindow::step, simulator, &Simulator::step);
    QObject::connect(this, &ViewMainWindow::restart, simulator, &Simulator::restart);
    QObject::connect(this, &ViewMainWindow::loadMemory, simulator, &Simulator::loadMemory);

    QObject::connect(simulator->addBranch, &AddBranch::receivedValueA, this, &ViewMainWindow::receivedAddBranchValueA);
    QObject::connect(simulator->addBranch, &AddBranch::receivedValueB, this, &ViewMainWindow::receivedAddBranchValueB);
    QObject::connect(simulator->addBranch, &AddBranch::executed, this, &ViewMainWindow::executedAddBranch);

    QObject::connect(simulator->addNext, &AddNext::receivedValueA, this, &ViewMainWindow::receivedAddNextValueA);
    QObject::connect(simulator->addNext, &AddNext::receivedValueB, this, &ViewMainWindow::receivedAddNextValueB);
    QObject::connect(simulator->addNext, &AddNext::executed, this, &ViewMainWindow::executedAddNext);

    QObject::connect(simulator->alu, &ALU::receivedValueA, this, &ViewMainWindow::receivedALUValueA);
    QObject::connect(simulator->alu, &ALU::receivedValueB, this, &ViewMainWindow::receivedALUValueB);
    QObject::connect(simulator->alu, &ALU::receivedControl, this, &ViewMainWindow::receivedALUControl);
    QObject::connect(simulator->alu, &ALU::executed, this, &ViewMainWindow::executedALU);

    QObject::connect(simulator->aluControl, &ALUControl::receivedInstruction, this, &ViewMainWindow::receivedALUControlInstruction);
    QObject::connect(simulator->aluControl, &ALUControl::receivedALUOp, this, &ViewMainWindow::receivedALUControlALUOp);
    QObject::connect(simulator->aluControl, &ALUControl::executed, this, &ViewMainWindow::executedALUControl);

    QObject::connect(simulator->andGate, &AndGate::receivedBransh, this, &ViewMainWindow::receivedAndGateBransh);
    QObject::connect(simulator->andGate, &AndGate::receivedZero, this, &ViewMainWindow::receivedAndGateZero);
    QObject::connect(simulator->andGate, &AndGate::executed, this, &ViewMainWindow::executedAndGate);

    QObject::connect(simulator->control, &Control::receivedOpcode, this, &ViewMainWindow::receivedControlOpcode);
    QObject::connect(simulator->control, &Control::executed, this, &ViewMainWindow::executedControl);

    QObject::connect(simulator->dataMemory, &DataMemory::receivedAddress, this, &ViewMainWindow::receivedDataMemoryAddress);
    QObject::connect(simulator->dataMemory, &DataMemory::receivedWriteData, this, &ViewMainWindow::receivedDataMemoryWriteData);
    QObject::connect(simulator->dataMemory, &DataMemory::receivedMemWrite, this, &ViewMainWindow::receivedDataMemoryMemWrite);
    QObject::connect(simulator->dataMemory, &DataMemory::receivedMemRead, this, &ViewMainWindow::receivedDataMemoryMemRead);
    QObject::connect(simulator->dataMemory, &DataMemory::initMemory, this, &ViewMainWindow::initDataMemory);
    QObject::connect(simulator->dataMemory, &DataMemory::loadMemory, this, &ViewMainWindow::loadDataMemory);
    QObject::connect(simulator->dataMemory, &DataMemory::updateMemory, this, &ViewMainWindow::updateDataMemory);
    QObject::connect(simulator->dataMemory, &DataMemory::restartMemory, this, &ViewMainWindow::restartDataMemory);
    QObject::connect(simulator->dataMemory, &DataMemory::executed, this, &ViewMainWindow::executedDataMemory);

    QObject::connect(simulator->instructionMemory, &InstructionMemory::receivedAddress, this, &ViewMainWindow::receivedInstructionMemoryAddress);
    QObject::connect(simulator->instructionMemory, &InstructionMemory::initMemory, this, &ViewMainWindow::initInstructionMemory);
    QObject::connect(simulator->instructionMemory, &InstructionMemory::loadMemory, this, &ViewMainWindow::loadInstructionMemory);
    QObject::connect(simulator->instructionMemory, &InstructionMemory::updateMemory, this, &ViewMainWindow::updateInstructionMemory);
    QObject::connect(simulator->instructionMemory, &InstructionMemory::restartMemory, this, &ViewMainWindow::restartInstructionMemory);
    QObject::connect(simulator->instructionMemory, &InstructionMemory::executed, this, &ViewMainWindow::executedInstructionMemory);

    QObject::connect(simulator->immGen, &ImmGen::receivedInstruction, this, &ViewMainWindow::receivedImmGenInstruction);
    QObject::connect(simulator->immGen, &ImmGen::executed, this, &ViewMainWindow::executedImmGen);

    QObject::connect(simulator->muxA, &MuxTypeA::receivedValueA, this, &ViewMainWindow::receivedMuxTypeAValueA);
    QObject::connect(simulator->muxA, &MuxTypeA::receivedValueB, this, &ViewMainWindow::receivedMuxTypeAValueB);
    QObject::connect(simulator->muxA, &MuxTypeA::receivedSelection, this, &ViewMainWindow::receivedMuxTypeASelection);
    QObject::connect(simulator->muxA, &MuxTypeA::executed, this, &ViewMainWindow::executedMuxTypeA);

    QObject::connect(simulator->muxB, &MuxTypeB::receivedValueA, this, &ViewMainWindow::receivedMuxTypeBValueA);
    QObject::connect(simulator->muxB, &MuxTypeB::receivedValueB, this, &ViewMainWindow::receivedMuxTypeBValueB);
    QObject::connect(simulator->muxB, &MuxTypeB::receivedSelection, this, &ViewMainWindow::receivedMuxTypeBSelection);
    QObject::connect(simulator->muxB, &MuxTypeB::executed, this, &ViewMainWindow::executedMuxTypeB);

    QObject::connect(simulator->muxC, &MuxTypeC::receivedValueA, this, &ViewMainWindow::receivedMuxTypeCValueA);
    QObject::connect(simulator->muxC, &MuxTypeC::receivedValueB, this, &ViewMainWindow::receivedMuxTypeCValueB);
    QObject::connect(simulator->muxC, &MuxTypeC::receivedSelection, this, &ViewMainWindow::receivedMuxTypeCSelection);
    QObject::connect(simulator->muxC, &MuxTypeC::executed, this, &ViewMainWindow::executedMuxTypeC);

    QObject::connect(simulator->pc, &PC::receivedAddress, this, &ViewMainWindow::receivedPCAddress);
    QObject::connect(simulator->pc, &PC::executed, this, &ViewMainWindow::executedPC);

    QObject::connect(simulator->registers, &Registers::receivedReadRegister1, this, &ViewMainWindow::receivedRegistersReadRegister1);
    QObject::connect(simulator->registers, &Registers::receivedReadRegister2, this, &ViewMainWindow::receivedRegistersReadRegister2);
    QObject::connect(simulator->registers, &Registers::receivedWriteRegister, this, &ViewMainWindow::receivedRegistersWriteRegister);
    QObject::connect(simulator->registers, &Registers::receivedWriteData, this, &ViewMainWindow::receivedRegistersWriteData);
    QObject::connect(simulator->registers, &Registers::receivedRegWrite, this, &ViewMainWindow::receivedRegistersRegWrite);
    QObject::connect(simulator->registers, &Registers::initRegisters, this, &ViewMainWindow::initRegisters);
    QObject::connect(simulator->registers, &Registers::updateRegister, this, &ViewMainWindow::updateRegister);
    QObject::connect(simulator->registers, &Registers::restartRegisters, this, &ViewMainWindow::restartRegisters);
    QObject::connect(simulator->registers, &Registers::executedRead, this, &ViewMainWindow::executedReadRegisters);
    QObject::connect(simulator->registers, &Registers::executedWrite, this, &ViewMainWindow::executedWriteRegisters);

    simulator->init();
    treeWidgetInit();
}

ViewMainWindow::~ViewMainWindow()
{
    delete ui;
}

void ViewMainWindow::on_actionNew_triggered()
{
    thisFile = "new";
    ui->plainTextEdit->setPlainText("");
}

void ViewMainWindow::on_actionOpen_triggered()
{
    thisFile = QFileDialog::getOpenFileName(this, "Open assembly file", "../tests/", "");

    QFile file(thisFile);
    file.open(QFile::ReadOnly | QFile::Text);

    ui->plainTextEdit->setPlainText(file.readAll());

    file.close();

    thisFile = generateFileName(thisFile);
}

void ViewMainWindow::on_actionSave_triggered()
{
    QFile file(thisFile);
    file.open(QFile::WriteOnly | QFile::Text);

    QTextStream outputFile(&file);
    outputFile << ui->plainTextEdit->toPlainText();

    file.close();
}

void ViewMainWindow::on_actionSave_as_triggered()
{
    thisFile = QFileDialog::getOpenFileName(this, "Open assembly file", "../tests/", "");

    QFile file(thisFile);
    file.open(QFile::WriteOnly | QFile::Text);

    QTextStream outputFile(&file);
    outputFile << ui->plainTextEdit->toPlainText();

    file.close();
}

void ViewMainWindow::on_actionPreferences_triggered()
{

}

void ViewMainWindow::on_actionExit_triggered()
{
    close();
}

void ViewMainWindow::on_actionAbut_us_triggered()
{

}

void ViewMainWindow::on_actionDocumentation_triggered()
{

}

void ViewMainWindow::on_actionLoad_triggered()
{
    emit assemble(thisFile + ".s", thisFile + ".b");

    ui->instructionListWidget->clear();

    QFile file(thisFile + ".b");
    file.open(QFile::ReadOnly | QFile::Text);

    QTextStream streamInput(&file);

    int position = 1000;

    while(!streamInput.atEnd()) {
        ui->instructionListWidget->addItem("[" + QString::number(position) + " ... " + QString::number(position + 3) + "]   - >   " + streamInput.readLine());

        position += 4;
    };

    file.close();

    emit loadMemory(thisFile);
}

void ViewMainWindow::on_actionRun_triggered()
{
    emit run();
}

void ViewMainWindow::on_actionStep_triggered()
{
    treeWidgetClear();
    emit step();
}

void ViewMainWindow::on_actionRestart_triggered()
{
    emit restart();
}


void ViewMainWindow::receivedAddBranchValueA(Word valueA)
{
    //consoleLog("AddBranch received ValueA equal to: " + valueA.getDecimal() + ".");
    addBranchValueAItem->setData(1, 0, valueA.getDecimal());
}

void ViewMainWindow::receivedAddBranchValueB(Word valueB)
{
    //consoleLog("AddBranch received ValueB equal to: " + valueB.getDecimal() + ".");
    addBranchValueBItem->setData(1, 0, valueB.getDecimal());
}

void ViewMainWindow::executedAddBranch()
{
    //consoleLog("AddBranch executed.");
    addBranchItem->setData(1, 0, "executed");
}

void ViewMainWindow::receivedAddNextValueA(Word valueA)
{
    //consoleLog("AddNext received ValueA equal to: " + valueA.getDecimal() + ".");
    addNextValueAItem->setData(1, 0, valueA.getDecimal());
}

void ViewMainWindow::receivedAddNextValueB(Word valueB)
{
    //consoleLog("AddNext received ValueB equal to: " + valueB.getDecimal() + ".");
    addNextValueBItem->setData(1, 0, valueB.getDecimal());
}

void ViewMainWindow::executedAddNext()
{
    //consoleLog("AddNext executed.");
    addNextItem->setData(1, 0, "executed");
}

void ViewMainWindow::receivedALUValueA(Word valueA)
{
    //consoleLog("ALU received ValueA equal to: " + valueA.getDecimal() + ".");
    aluValueAItem->setData(1, 0, valueA.getDecimal());
}

void ViewMainWindow::receivedALUValueB(Word valueB)
{
    //consoleLog("ALU received ValueB equal to: " + valueB.getDecimal() + ".");
    aluValueBItem->setData(1, 0, valueB.getDecimal());
}

void ViewMainWindow::receivedALUControl(Word control)
{
    //consoleLog("ALU received control equal to: " + control.getDecimal() + ".");
    aluControlValueItem->setData(1, 0, control.getDecimal());
}

void ViewMainWindow::executedALU()
{
    //consoleLog("ALU executed.");
    aluItem->setData(1, 0, "executed");
}

void ViewMainWindow::receivedALUControlInstruction(Word instruction)
{
    //consoleLog("ALUControl received instruction equal to: " + instruction.getDecimal() + ".");
    aluControlInstructionItem->setData(1, 0, instruction.getDecimal());
}

void ViewMainWindow::receivedALUControlALUOp(Word aluOp)
{
    //consoleLog("ALUControl received aluOp equal to: " + aluOp.getDecimal() + ".");
    aluControlOpItem->setData(1, 0, aluOp.getDecimal());
}

void ViewMainWindow::executedALUControl()
{
    //consoleLog("ALUControl executed.");
    aluControlItem->setData(1, 0, "executed");
}

void ViewMainWindow::receivedAndGateBransh(Word branch)
{
    //consoleLog("AndGate received branch equal to: " + branch.getDecimal() + ".");
    andGateBranchItem->setData(1, 0, branch.getDecimal());
}

void ViewMainWindow::receivedAndGateZero(Word zero)
{
    //consoleLog("AndGate received zero equal to: " + zero.getDecimal() + ".");
    andGateZeroItem->setData(1, 0, zero.getDecimal());
}

void ViewMainWindow::executedAndGate()
{
    //consoleLog("AndGate executed.");
    andGateItem->setData(1, 0, "executed");
}

void ViewMainWindow::receivedControlOpcode(Word opcode)
{
    //consoleLog("Control received opcode equal to: " + opcode.getDecimal() + ".");
    controlOpcodeItem->setData(1, 0, opcode.getDecimal());
}

void ViewMainWindow::executedControl()
{
    //consoleLog("Control executed.");
    controlItem->setData(1, 0, "executed");
}

void ViewMainWindow::receivedDataMemoryAddress(Word address)
{
    //consoleLog("DataMemory received address equal to: " + address.getDecimal() + ".");
    dataMemoryAddressItem->setData(1, 0, address.getDecimal());
}

void ViewMainWindow::receivedDataMemoryWriteData(Word writeData)
{
    //consoleLog("DataMemory received writeData equal to: " + writeData.getDecimal() + ".");
    dataMemoryWriteDataItem->setData(1, 0, writeData.getDecimal());
}

void ViewMainWindow::receivedDataMemoryMemWrite(Word memWrite)
{
    //consoleLog("DataMemory received memWrite equal to: " + memWrite.getDecimal() + ".");
    dataMemoryMemWriteItem->setData(1, 0, memWrite.getDecimal());
}

void ViewMainWindow::receivedDataMemoryMemRead(Word memRead)
{
    //consoleLog("DataMemory received memRead equal to: " + memRead.getDecimal() + ".");
    dataMemoryMemReadItem->setData(1, 0, memRead.getDecimal());
}

void ViewMainWindow::initDataMemory(int size)
{
    ui->dataMemoryTableWidget->verticalHeader()->setVisible(false);
    ui->dataMemoryTableWidget->setColumnWidth(0, 100);
    ui->dataMemoryTableWidget->setColumnWidth(1, 100);

    int address = DATA_ADDRESS;

    for(int i = 0; i < size; i++) {
        ui->dataMemoryTableWidget->insertRow(ui->dataMemoryTableWidget->rowCount());
        ui->dataMemoryTableWidget->setItem(i, 0, new QTableWidgetItem(" [" + QString::number(address) + " ... " + QString::number(address + 3) + "] "));
        ui->dataMemoryTableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(0)));
        ui->dataMemoryTableWidget->item(i, 0)->setTextAlignment(Qt::AlignCenter);

        ui->dataMemoryTableWidget->setRowHeight(i, 20);
        address += 4;
    }

    consoleLog("DataMemory started.");
}

void ViewMainWindow::loadDataMemory(vector<Word> memoryData)
{
    int size = memoryData.size();

    for(int i = 0; i < size; i++) {
        ui->dataMemoryTableWidget->setItem(i, 1, new QTableWidgetItem(memoryData[i].getDecimal()));
    }

    consoleLog("Loaded DataMemory.");
}

void ViewMainWindow::updateDataMemory(Word value, Word address)
{
    ui->dataMemoryTableWidget->setItem(address.getInteger(), 1, new QTableWidgetItem(value.getDecimal()));

    consoleLog("Updated DataMemory.");
}

void ViewMainWindow::restartDataMemory()
{
    int size = ui->dataMemoryTableWidget->rowCount();

    for(int i = 0; i < size; i++) {
        ui->dataMemoryTableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(0)));
    }

    consoleLog("DataMemory reset.");
}

void ViewMainWindow::executedDataMemory()
{
    //consoleLog("DataMemory executed.");
    dataMemoryItem->setData(1, 0, "executed");
}

void ViewMainWindow::receivedInstructionMemoryAddress(Word address)
{
    //consoleLog("InstructionMemory received address equals to: " + address.getDecimal() + ".");
    instructionMemoryAddressItem->setData(1, 0, address.getDecimal());
}

void ViewMainWindow::initInstructionMemory(int size)
{
    ui->instructionMemoryTableWidget->verticalHeader()->setVisible(false);
    ui->instructionMemoryTableWidget->setColumnWidth(0, 100);
    ui->instructionMemoryTableWidget->setColumnWidth(1, 100);

    int address = INSTRUCTION_ADDRESS;

    for(int i = 0; i < size; i++) {
        ui->instructionMemoryTableWidget->insertRow(ui->instructionMemoryTableWidget->rowCount());
        ui->instructionMemoryTableWidget->setItem(i, 0, new QTableWidgetItem(" [" + QString::number(address) + " ... " + QString::number(address + 3) + "] "));
        ui->instructionMemoryTableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(0)));
        ui->instructionMemoryTableWidget->item(i, 0)->setTextAlignment(Qt::AlignCenter);

        ui->instructionMemoryTableWidget->setRowHeight(i, 20);
        address += 4;
    }

    consoleLog("InstructionMemory started.");
}

void ViewMainWindow::loadInstructionMemory(vector<Word> memoryData)
{
    int size = memoryData.size();

    for(int i = 0; i < size; i++) {
        ui->instructionMemoryTableWidget->setItem(i, 1, new QTableWidgetItem(memoryData.at(i).getDecimal()));
    }

    consoleLog("Loaded InstructionMemory.");
}

void ViewMainWindow::updateInstructionMemory(Word value, Word address)
{
    ui->instructionMemoryTableWidget->setItem(address.getInteger(), 1, new QTableWidgetItem(value.getDecimal()));

    consoleLog("Updated InstructionMemory.");
}

void ViewMainWindow::restartInstructionMemory()
{
    int size = ui->instructionMemoryTableWidget->rowCount();

    for(int i = 0; i < size; i++) {
        ui->instructionMemoryTableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(0)));
    }

    consoleLog("InstructionMemory reset.");
}

void ViewMainWindow::executedInstructionMemory()
{
    //consoleLog("InstructionMemory executed.");
    instructionMemoryItem->setData(1, 0, "executed");
}

void ViewMainWindow::receivedImmGenInstruction(Word instruction)
{
    //consoleLog("ImmGen received instruction equal to: " + instruction.getDecimal() + ".");
    immGenInstructionItem->setData(1, 0, instruction.getDecimal());
}

void ViewMainWindow::executedImmGen()
{
    //consoleLog("ImmGen executed.");
    immGenItem->setData(1, 0, "executed");
}

void ViewMainWindow::receivedMuxTypeAValueA(Word valueA)
{
    //consoleLog("MuxTypeA received valueA equal to: " + valueA.getDecimal() + ".");
    muxAValueAItem->setData(1, 0, valueA.getDecimal());
}

void ViewMainWindow::receivedMuxTypeAValueB(Word valueB)
{
    //consoleLog("MuxTypeA received valueB equal to: " + valueB.getDecimal() + ".");
    muxAValueBItem->setData(1, 0, valueB.getDecimal());
}

void ViewMainWindow::receivedMuxTypeASelection(Word selection)
{
    //consoleLog("MuxTypeA received control equal to: " + selection.getDecimal() + ".");
    muxASelectionItem->setData(1, 0, selection.getDecimal());
}

void ViewMainWindow::executedMuxTypeA()
{
    //consoleLog("MuxTypeA executed.");
    muxAItem->setData(1, 0, "executed");
}

void ViewMainWindow::receivedMuxTypeBValueA(Word valueA)
{
    //consoleLog("MuxTypeB received valueA equal to: " + valueA.getDecimal() + ".");
    muxBValueAItem->setData(1, 0, valueA.getDecimal());
}

void ViewMainWindow::receivedMuxTypeBValueB(Word valueB)
{
    //consoleLog("MuxTypeB received valueB equal to: " + valueB.getDecimal() + ".");
    muxBValueBItem->setData(1, 0, valueB.getDecimal());
}

void ViewMainWindow::receivedMuxTypeBSelection(Word selection)
{
    //consoleLog("MuxTypeB received control equal to: " + selection.getDecimal() + ".");
    muxBSelectionItem->setData(1, 0, selection.getDecimal());
}

void ViewMainWindow::executedMuxTypeB()
{
    //consoleLog("MuxTypeB executed.");
    muxBItem->setData(1, 0, "executed");
}

void ViewMainWindow::receivedMuxTypeCValueA(Word valueA)
{
    //consoleLog("MuxTypeC received valueA equal to: " + valueA.getDecimal() + ".");
    muxCValueAItem->setData(1, 0, valueA.getDecimal());
}

void ViewMainWindow::receivedMuxTypeCValueB(Word valueB)
{
    //consoleLog("MuxTypeC received valueB equal to: " + valueB.getDecimal() + ".");
    muxCValueBItem->setData(1, 0, valueB.getDecimal());
}

void ViewMainWindow::receivedMuxTypeCSelection(Word selection)
{
    //consoleLog("MuxTypeC received control equal to: " + selection.getDecimal() + ".");
    muxCSelectionItem->setData(1, 0, selection.getDecimal());
}

void ViewMainWindow::executedMuxTypeC()
{
    //consoleLog("MuxTypeC executed.");
    muxCItem->setData(1, 0, "executed");
}

void ViewMainWindow::receivedPCAddress(Word address)
{
    //consoleLog("PC received address equal to: " + address.getDecimal() + ".");
    pcAddressItem->setData(1, 0, address.getDecimal());
}

void ViewMainWindow::executedPC()
{
    //consoleLog("PC executed.");
    pcItem->setData(1, 0, "executed");
}

void ViewMainWindow::receivedRegistersReadRegister1(Word readRegister1)
{
    //consoleLog("Registers received readRegister1 equal to: " + readRegister1.getDecimal() + ".");
    registerReadRegister1Item->setData(1, 0, readRegister1.getDecimal());
}

void ViewMainWindow::receivedRegistersReadRegister2(Word readRegister2)
{
    //consoleLog("Registers received readRegister2 equal to: " + readRegister2.getDecimal() + ".");
    registerReadRegister2Item->setData(1, 0, readRegister2.getDecimal());
}

void ViewMainWindow::receivedRegistersWriteRegister(Word writeRegister)
{
    //consoleLog("Registers received writeRegister equal to: " + writeRegister.getDecimal() + ".");
    registerWriteRegItem->setData(1, 0, writeRegister.getDecimal());
}

void ViewMainWindow::receivedRegistersWriteData(Word writeData)
{
    //consoleLog("Registers received writeData equal to: " + writeData.getDecimal() + ".");
    registerWriteDataItem->setData(1, 0, writeData.getDecimal());
}

void ViewMainWindow::receivedRegistersRegWrite(Word regWrite)
{
    //consoleLog("Registers received regWrite equal to: " + regWrite.getDecimal() + ".");
    registerRegWriteItem->setData(1, 0, regWrite.getDecimal());
}

void ViewMainWindow::initRegisters(int size)
{
    ui->registersTableWidget->verticalHeader()->setVisible(false);
    ui->registersTableWidget->setColumnWidth(0, 60);
    ui->registersTableWidget->setColumnWidth(1, 100);

    for(int i = 0; i < size; i++) {
        ui->registersTableWidget->insertRow(ui->registersTableWidget->rowCount());
        ui->registersTableWidget->setItem(i, 0, new QTableWidgetItem("x" + QString::number(i)));
        ui->registersTableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(0)));

        ui->registersTableWidget->item(i,0)->setTextAlignment(Qt::AlignCenter);
        ui->registersTableWidget->item(i,1)->setTextAlignment(Qt::AlignRight);

        ui->registersTableWidget->setRowHeight(i, 20);
    }

    consoleLog("");
}

void ViewMainWindow::updateRegister(Word value, Word address)
{
    ui->registersTableWidget->setItem(address.getInteger(), 1, new QTableWidgetItem(value.getDecimal()));
}

void ViewMainWindow::restartRegisters()
{
    int size = ui->registersTableWidget->rowCount();

    for(int i = 0; i < size; i++) {
        ui->registersTableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(0)));
    }

    consoleLog("");
}

void ViewMainWindow::executedReadRegisters()
{
    //consoleLog("Registers Read executed.");
    registerItem->setData(1, 0, "executed read");
}

void ViewMainWindow::executedWriteRegisters()
{
    //consoleLog("Registers Write executed.");
    registerItem->setData(1, 0, "executed write");
}

void ViewMainWindow::treeWidgetInit()
{
    pcItem = treeWidgetAddRoot("PC", "- - -");
    pcAddressItem = treeWidgetAddChild(pcItem, "address", "- - -");

    registerItem = treeWidgetAddRoot("Registers", "- - -");
    registerReadRegister1Item = treeWidgetAddChild(registerItem, "readReg1", "- - -");
    registerReadRegister2Item = treeWidgetAddChild(registerItem, "readReg2", "- - -");
    registerWriteRegItem = treeWidgetAddChild(registerItem, "writeReg", "- - -");
    registerWriteDataItem = treeWidgetAddChild(registerItem, "writeData", "- - -");
    registerRegWriteItem = treeWidgetAddChild(registerItem, "regWrite", "- - -");

    instructionMemoryItem = treeWidgetAddRoot("InstructionMemory", "- - -");
    instructionMemoryAddressItem = treeWidgetAddChild(instructionMemoryItem, "address", "- - -");

    dataMemoryItem = treeWidgetAddRoot("DataMemory", "- - -");
    dataMemoryAddressItem = treeWidgetAddChild(dataMemoryItem, "address", "- - -");
    dataMemoryWriteDataItem = treeWidgetAddChild(dataMemoryItem, "writeData", "- - -");
    dataMemoryMemWriteItem = treeWidgetAddChild(dataMemoryItem, "memWrite", "- - -");
    dataMemoryMemReadItem = treeWidgetAddChild(dataMemoryItem, "memRead", "- - -");

    controlItem = treeWidgetAddRoot("Control", "- - -");
    controlOpcodeItem = treeWidgetAddChild(controlItem, "opcode", "- - -");

    aluItem = treeWidgetAddRoot("ALU", "- - -");
    aluValueAItem = treeWidgetAddChild(aluItem, "valueA", "- - -");
    aluValueBItem = treeWidgetAddChild(aluItem, "valueB", "- - -");
    aluControlValueItem = treeWidgetAddChild(aluItem, "control", "- - -");

    aluControlItem = treeWidgetAddRoot("ALUControl", "- - -");
    aluControlInstructionItem = treeWidgetAddChild(aluControlItem, "instruction", "- - -");
    aluControlOpItem = treeWidgetAddChild(aluControlItem, "aluOp", "- - -");

    immGenItem = treeWidgetAddRoot("ImmGen", "- - -");
    immGenInstructionItem = treeWidgetAddChild(immGenItem, "instruction", "- - -");

    addNextItem = treeWidgetAddRoot("AddNext", "- - -");
    addNextValueAItem = treeWidgetAddChild(addNextItem, "valueA", "- - -");
    addNextValueBItem = treeWidgetAddChild(addNextItem, "valueB", "- - -");

    addBranchItem = treeWidgetAddRoot("AddBranch", "- - -");
    addBranchValueAItem = treeWidgetAddChild(addBranchItem, "valueA", "- - -");
    addBranchValueBItem = treeWidgetAddChild(addBranchItem, "valueB", "- - -");

    andGateItem = treeWidgetAddRoot("AndGate", "- - -");
    andGateBranchItem = treeWidgetAddChild(andGateItem, "branch", "- - -");
    andGateZeroItem = treeWidgetAddChild(andGateItem, "zero", "- - -");

    muxAItem = treeWidgetAddRoot("MuxA", "- - -");
    muxAValueAItem = treeWidgetAddChild(muxAItem, "valueA", "- - -");
    muxAValueBItem = treeWidgetAddChild(muxAItem, "valueB", "- - -");
    muxASelectionItem = treeWidgetAddChild(muxAItem, "selection", "- - -");

    muxBItem = treeWidgetAddRoot("MuxB", "- - -");
    muxBValueAItem = treeWidgetAddChild(muxBItem, "valueA", "- - -");
    muxBValueBItem = treeWidgetAddChild(muxBItem, "valueB", "- - -");
    muxBSelectionItem = treeWidgetAddChild(muxBItem, "selection", "- - -");

    muxCItem = treeWidgetAddRoot("MuxC", "- - -");
    muxCValueAItem = treeWidgetAddChild(muxCItem, "valueA", "- - -");
    muxCValueBItem = treeWidgetAddChild(muxCItem, "valueB", "- - -");
    muxCSelectionItem = treeWidgetAddChild(muxCItem, "selection", "- - -");
}

QTreeWidgetItem* ViewMainWindow::treeWidgetAddRoot(QString name, QString value)
{
    QTreeWidgetItem *item = new QTreeWidgetItem(ui->treeWidget);

    item->setText(0, name);
    item->setText(1, value);
    item->textAlignment(Qt::AlignLeft);
    //item->icon();

    ui->treeWidget->addTopLevelItem(item);

    return item;
}

QTreeWidgetItem* ViewMainWindow::treeWidgetAddChild(QTreeWidgetItem *parent,  QString name, QString value)
{
    QTreeWidgetItem *item = new QTreeWidgetItem(parent);

    item->setText(0, name);
    item->setText(1, value);
    //item->icon();

    parent->addChild(item);

    return item;
}

void ViewMainWindow::treeWidgetClear()
{
    pcItem->setData(1, 0, "- - -");
    pcAddressItem->setData(1, 0, "- - -");

    registerItem->setData(1, 0, "- - -");
    registerReadRegister1Item->setData(1, 0, "- - -");
    registerReadRegister2Item->setData(1, 0, "- - -");
    registerWriteRegItem->setData(1, 0, "- - -");
    registerWriteDataItem->setData(1, 0, "- - -");
    registerRegWriteItem->setData(1, 0, "- - -");

    instructionMemoryItem->setData(1, 0, "- - -");
    instructionMemoryAddressItem->setData(1, 0, "- - -");

    dataMemoryItem->setData(1, 0, "- - -");
    dataMemoryAddressItem->setData(1, 0, "- - -");
    dataMemoryWriteDataItem->setData(1, 0, "- - -");
    dataMemoryMemWriteItem->setData(1, 0, "- - -");
    dataMemoryMemReadItem->setData(1, 0, "- - -");

    controlItem->setData(1, 0, "- - -");
    controlOpcodeItem->setData(1, 0, "- - -");

    aluItem->setData(1, 0, "- - -");
    aluValueAItem->setData(1, 0, "- - -");
    aluValueBItem->setData(1, 0, "- - -");
    aluControlValueItem->setData(1, 0, "- - -");

    aluControlItem->setData(1, 0, "- - -");
    aluControlInstructionItem->setData(1, 0, "- - -");
    aluControlOpItem->setData(1, 0, "- - -");

    immGenItem->setData(1, 0, "- - -");
    immGenInstructionItem->setData(1, 0, "- - -");

    addNextItem->setData(1, 0, "- - -");
    addNextValueAItem->setData(1, 0, "- - -");
    addNextValueBItem->setData(1, 0, "- - -");

    addBranchItem->setData(1, 0, "- - -");
    addBranchValueAItem->setData(1, 0, "- - -");
    addBranchValueBItem->setData(1, 0, "- - -");

    andGateItem->setData(1, 0, "- - -");
    andGateBranchItem->setData(1, 0, "- - -");
    andGateZeroItem->setData(1, 0, "- - -");

    muxAItem->setData(1, 0, "- - -");
    muxAValueAItem->setData(1, 0, "- - -");
    muxAValueBItem->setData(1, 0, "- - -");
    muxASelectionItem->setData(1, 0, "- - -");

    muxBItem->setData(1, 0, "- - -");
    muxBValueAItem->setData(1, 0, "- - -");
    muxBValueBItem->setData(1, 0, "- - -");
    muxBSelectionItem->setData(1, 0, "- - -");

    muxCItem->setData(1, 0, "- - -");
    muxCValueAItem->setData(1, 0, "- - -");
    muxCValueBItem->setData(1, 0, "- - -");
    muxCSelectionItem->setData(1, 0, "- - -");
}

void ViewMainWindow::consoleLog(QString message)
{
    ui->consoleListWidget->addItem(message);
}

QString ViewMainWindow::generateFileName(QString fileName)
{
    return fileName.mid(0, fileName.lastIndexOf("."));
}

