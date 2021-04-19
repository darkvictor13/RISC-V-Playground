/**
 * @file viewmainwindow.cpp
 * @brief
 * @author mGuerra
 * @version 0.1
*/

#include "viewmainwindow.h"
#include "ui_viewmainwindow.h"

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
    QObject::connect(simulator->muxA, &MuxTypeA::receivedValueB, this, &ViewMainWindow::receivedMuxTypeBValueB);
    QObject::connect(simulator->muxA, &MuxTypeA::executed, this, &ViewMainWindow::executedMuxTypeA);

    QObject::connect(simulator->muxB, &MuxTypeB::receivedValueA, this, &ViewMainWindow::receivedMuxTypeBValueA);
    QObject::connect(simulator->muxB, &MuxTypeB::receivedValueB, this, &ViewMainWindow::receivedMuxTypeBValueB);
    QObject::connect(simulator->muxB, &MuxTypeB::executed, this, &ViewMainWindow::executedMuxTypeB);

    QObject::connect(simulator->muxC, &MuxTypeC::receivedValueA, this, &ViewMainWindow::receivedMuxTypeCValueA);
    QObject::connect(simulator->muxC, &MuxTypeC::receivedValueB, this, &ViewMainWindow::receivedMuxTypeCValueB);
    QObject::connect(simulator->muxC, &MuxTypeC::executed, this, &ViewMainWindow::executedMuxTypeC);

    QObject::connect(simulator->pc, &PC::receivedAddress, this, &ViewMainWindow::receivedPCAddress);
    QObject::connect(simulator->pc, &PC::executed, this, &ViewMainWindow::executedPC);

    QObject::connect(simulator->registers, &Registers::receivedReadRegister1, this, &ViewMainWindow::receivedRegistersReadRegister1);
    QObject::connect(simulator->registers, &Registers::receivedReadRegister2, this, &ViewMainWindow::receivedRegistersReadRegister2);
    QObject::connect(simulator->registers, &Registers::receivedWriteRegister, this, &ViewMainWindow::receivedRegistersWriteRegister);
    QObject::connect(simulator->registers, &Registers::receivedWriteData, this, &ViewMainWindow::receivedRegistersWriteData);
    QObject::connect(simulator->registers, &Registers::receivedRegWrite, this, &ViewMainWindow::receivedRegistersWriteData);
    QObject::connect(simulator->registers, &Registers::initRegisters, this, &ViewMainWindow::initRegisters);
    QObject::connect(simulator->registers, &Registers::updateRegister, this, &ViewMainWindow::updateRegister);
    QObject::connect(simulator->registers, &Registers::restartRegisters, this, &ViewMainWindow::restartRegisters);
    QObject::connect(simulator->registers, &Registers::executed, this, &ViewMainWindow::executedRegisters);

    emit init();
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

    QFile file(thisFile + ".b");
    file.open(QFile::ReadOnly | QFile::Text);

    ui->instructionListWidget->addItem(file.readAll());

    file.close();

    emit loadMemory(thisFile);
}

void ViewMainWindow::on_actionRun_triggered()
{
    emit run();
}

void ViewMainWindow::on_actionStep_triggered()
{
    emit step();
}

void ViewMainWindow::on_actionRestart_triggered()
{
    emit restart();
}


void ViewMainWindow::receivedAddBranchValueA(Word valueA)
{
    consoleLog("AddBranch received ValueA equal to: " + valueA.getString() + ".");
}

void ViewMainWindow::receivedAddBranchValueB(Word valueB)
{
    consoleLog("AddBranch received ValueB equal to: " + valueB.getString() + ".");
}

void ViewMainWindow::executedAddBranch()
{
    consoleLog("AddBranch executed.");
}

void ViewMainWindow::receivedAddNextValueA(Word valueA)
{
    consoleLog("AddNext received ValueA equal to: " + valueA.getString() + ".");
}

void ViewMainWindow::receivedAddNextValueB(Word valueB)
{
    consoleLog("AddNext received ValueA equal to: " + valueB.getString() + ".");
}

void ViewMainWindow::executedAddNext()
{
    consoleLog("AddNext executed.");
}

void ViewMainWindow::receivedALUValueA(Word valueA)
{
    consoleLog("ALU received ValueA equal to: " + valueA.getString() + ".");
}

void ViewMainWindow::receivedALUValueB(Word valueB)
{
    consoleLog("ALU received ValueB equal to: " + valueB.getString() + ".");
}

void ViewMainWindow::receivedALUControl(Word control)
{
    consoleLog("ALU received control equal to: " + control.getString() + ".");
}

void ViewMainWindow::executedALU()
{
    consoleLog("ALU executed.");
}

void ViewMainWindow::receivedALUControlInstruction(Word instruction)
{
    consoleLog("ALUControl received instruction equal to: " + instruction.getString() + ".");
}

void ViewMainWindow::receivedALUControlALUOp(Word aluOp)
{
    consoleLog("ALUControl received aluOp equal to: " + aluOp.getString() + ".");
}

void ViewMainWindow::executedALUControl()
{
    consoleLog("ALUControl executed.");
}

void ViewMainWindow::receivedAndGateBransh(Word branch)
{
    consoleLog("AndGate received branch equal to: " + branch.getString() + ".");
}

void ViewMainWindow::receivedAndGateZero(Word zero)
{
    consoleLog("AndGate received zero equal to: " + zero.getString() + ".");
}

void ViewMainWindow::executedAndGate()
{
    consoleLog("AndGate executed.");
}

void ViewMainWindow::receivedControlOpcode(Word opcode)
{
    consoleLog("Control received opcode equal to: " + opcode.getString() + ".");
}

void ViewMainWindow::executedControl()
{
    consoleLog("Control executed.");
}

void ViewMainWindow::receivedDataMemoryAddress(Word address)
{
    consoleLog("DataMemory received address equal to: " + address.getString() + ".");
}

void ViewMainWindow::receivedDataMemoryWriteData(Word writeData)
{
    consoleLog("DataMemory received writeData equal to: " + writeData.getString() + ".");
}

void ViewMainWindow::receivedDataMemoryMemWrite(Word memWrite)
{
    consoleLog("DataMemory received memWrite equal to: " + memWrite.getString() + ".");
}

void ViewMainWindow::receivedDataMemoryMemRead(Word memRead)
{
    consoleLog("DataMemory received memRead equal to: " + memRead.getString() + ".");
}

void ViewMainWindow::initDataMemory(int size)
{
    ui->dataMemoryTableWidget->verticalHeader()->setVisible(false);

    for(int i = 0; i < size; i++) {
        ui->dataMemoryTableWidget->insertRow(ui->dataMemoryTableWidget->rowCount());
        ui->dataMemoryTableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(i)));
        ui->dataMemoryTableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(0)));

        ui->dataMemoryTableWidget->setRowHeight(i, 20);
    }

    consoleLog("DataMemory started.");
}

void ViewMainWindow::loadDataMemory(vector<Word> memoryData)
{
    int size = memoryData.size();

    for(int i = 0; i < size; i++) {
        ui->dataMemoryTableWidget->setItem(i, 1, new QTableWidgetItem(memoryData[i].getString()));
    }

    consoleLog("Loaded DataMemory.");
}

void ViewMainWindow::updateDataMemory(Word value, Word address)
{
    ui->dataMemoryTableWidget->setItem(address.getInteger(), 1, new QTableWidgetItem(value.getString()));

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
    consoleLog("DataMemory executed.");
}

void ViewMainWindow::receivedInstructionMemoryAddress(Word address)
{
    consoleLog("InstructionMemory received address equals to: " + address.getString() + ".");
}

void ViewMainWindow::initInstructionMemory(int size)
{
    ui->instructionMemoryTableWidget->verticalHeader()->setVisible(false);

    for(int i = 0; i < size; i++) {
        ui->instructionMemoryTableWidget->insertRow(ui->instructionMemoryTableWidget->rowCount());
        ui->instructionMemoryTableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(i)));
        ui->instructionMemoryTableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(0)));

        ui->instructionMemoryTableWidget->setRowHeight(i, 20);
    }

    consoleLog("InstructionMemory started.");
}

void ViewMainWindow::loadInstructionMemory(vector<Word> memoryData)
{
    int size = memoryData.size();

    for(int i = 0; i < size; i++) {
        ui->instructionMemoryTableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(memoryData.at(i).getInteger())));
    }

    consoleLog("Loaded InstructionMemory.");
}

void ViewMainWindow::updateInstructionMemory(Word value, Word address)
{
    ui->instructionMemoryTableWidget->setItem(address.getInteger(), 1, new QTableWidgetItem(value.getString()));

    consoleLog("Updated InstructionMemory.");
}

void ViewMainWindow::restartInstructionMemory()
{
    int size = ui->instructionMemoryTableWidget->rowCount();

    for(int i = 0; i < size; i++) {
        ui->instructionMemoryTableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(0)));
    }

    consoleLog("DataMemory reset.");
}

void ViewMainWindow::executedInstructionMemory()
{
    consoleLog("InstructionMemory executed.");
}

void ViewMainWindow::receivedImmGenInstruction(Word instruction)
{
    consoleLog("ImmGen received instruction equal to: " + instruction.getString() + ".");
}

void ViewMainWindow::executedImmGen()
{
    consoleLog("ImmGen executed.");
}

void ViewMainWindow::receivedMuxTypeAValueA(Word valueA)
{
    consoleLog("MuxTypeA received valueA equal to: " + valueA.getString() + ".");
}

void ViewMainWindow::receivedMuxTypeAValueB(Word valueB)
{
    consoleLog("MuxTypeA received valueB equal to: " + valueB.getString() + ".");
}

void ViewMainWindow::receivedMuxTypeASelection(Word control)
{
    consoleLog("MuxTypeA received control equal to: " + control.getString() + ".");
}

void ViewMainWindow::executedMuxTypeA()
{
    consoleLog("MuxTypeA executed.");
}

void ViewMainWindow::receivedMuxTypeBValueA(Word valueA)
{
    consoleLog("MuxTypeB received valueA equal to: " + valueA.getString() + ".");
}

void ViewMainWindow::receivedMuxTypeBValueB(Word valueB)
{
    consoleLog("MuxTypeB received valueB equal to: " + valueB.getString() + ".");
}

void ViewMainWindow::receivedMuxTypeBSelection(Word control)
{
    consoleLog("MuxTypeA received control equal to: " + control.getString() + ".");
}

void ViewMainWindow::executedMuxTypeB()
{
    consoleLog("MuxTypeB executed.");
}

void ViewMainWindow::receivedMuxTypeCValueA(Word valueA)
{
    consoleLog("MuxTypeC received valueA equal to: " + valueA.getString() + ".");
}

void ViewMainWindow::receivedMuxTypeCValueB(Word valueB)
{
    consoleLog("MuxTypeC received valueB equal to: " + valueB.getString() + ".");
}

void ViewMainWindow::receivedMuxTypeCSelection(Word control)
{
    consoleLog("MuxTypeC received control equal to: " + control.getString() + ".");
}

void ViewMainWindow::executedMuxTypeC()
{
    consoleLog("MuxTypeC executed.");
}

void ViewMainWindow::receivedPCAddress(Word address)
{
    consoleLog("PC received address equal to: " + address.getString() + ".");
}

void ViewMainWindow::executedPC()
{
    consoleLog("PC executed.");
}

void ViewMainWindow::receivedRegistersReadRegister1(Word readRegister1)
{
    consoleLog("Registers received readRegister1 equal to: " + readRegister1.getString() + ".");
}

void ViewMainWindow::receivedRegistersReadRegister2(Word readRegister2)
{
    consoleLog("Registers received readRegister2 equal to: " + readRegister2.getString() + ".");
}

void ViewMainWindow::receivedRegistersWriteRegister(Word writeRegister)
{
    consoleLog("Registers received writeRegister equal to: " + writeRegister.getString() + ".");
}

void ViewMainWindow::receivedRegistersWriteData(Word writeData)
{
    consoleLog("Registers received writeData equal to: " + writeData.getString() + ".");
}

void ViewMainWindow::receivedRegistersRegWrite(Word regWrite)
{
    consoleLog("Registers received regWrite equal to: " + regWrite.getString() + ".");
}

void ViewMainWindow::initRegisters(int size)
{
    ui->registersTableWidget->verticalHeader()->setVisible(false);

    for(int i = 0; i < size; i++) {
        ui->registersTableWidget->insertRow(ui->registersTableWidget->rowCount());
        ui->registersTableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(i)));
        ui->registersTableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(0)));

        ui->registersTableWidget->setRowHeight(i, 20);
    }

    consoleLog("");
}

void ViewMainWindow::updateRegister(Word value, Word address)
{
    ui->registersTableWidget->setItem(address.getInteger(), 1, new QTableWidgetItem(value.getString()));
}

void ViewMainWindow::restartRegisters()
{
    int size = ui->registersTableWidget->rowCount();

    for(int i = 0; i < size; i++) {
        ui->registersTableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(0)));
    }

    consoleLog("");
}

void ViewMainWindow::executedRegisters()
{
    consoleLog("Registers executed.");
}

void ViewMainWindow::consoleLog(QString message)
{
    ui->consoleListWidget->addItem(message);
}

QString ViewMainWindow::generateFileName(QString fileName)
{
    return fileName.mid(0, fileName.lastIndexOf("."));
}

