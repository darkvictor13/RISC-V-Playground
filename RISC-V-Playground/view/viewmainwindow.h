/**
 * @file viewmainwindow.h
 * @brief Arquivo responsável por definir a interface gráfica do projeto
 * @author mGuerra
 * @version 0.1
*/

#ifndef VIEWMAINWINDOW_H
#define VIEWMAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QTextStream>
#include <QTreeWidgetItem>

#include "simulator/simulator.h"
#include "assembler/assembler.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ViewMainWindow; }
QT_END_NAMESPACE

/**
  * @brief Indica o local de memória da primeira instrução
  */
#define INSTRUCTION_ADDRESS 1000

/**
  * @brief Indica o local de memória do primeiro dado
  */
#define DATA_ADDRESS 2000


/**
 * @brief A classe ViewMainWindow: responsável pela representação dos dados de estado do simulador en tela, alem de permitir a interação do usuário com o simulador e o assembler
 */
class ViewMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    ViewMainWindow(QWidget *parent = nullptr);

    Ui::ViewMainWindow *ui;

    ~ViewMainWindow();

private:
    QString thisFile = "../test/test.in";

    Simulator *simulator = new Simulator();
    Assembler *assembler = new Assembler();

    QString generateFileName(QString fileName);

public slots:
    //void on_actionNew_triggered();
    void on_actionOpen_triggered();

    //void on_actionSave_triggered();
    //void on_actionSave_as_triggered();

    void on_actionPreferences_triggered();

    void on_actionExit_triggered();

    void on_actionAbut_us_triggered();
    void on_actionDocumentation_triggered();

    void on_actionLoad_triggered();
    void on_actionStep_triggered();

    void receivedAddBranchValueA(Word valueA);
    void receivedAddBranchValueB(Word valueB);
    void executedAddBranch();

    void receivedAddNextValueA(Word valueA);
    void receivedAddNextValueB(Word valueB);
    void executedAddNext();

    void receivedALUValueA(Word valueA);
    void receivedALUValueB(Word valueB);
    void receivedALUControl(Word control);
    void receivedALUReverse(Word reverse);
    void executedALU();

    void receivedALUControlInstruction(Word instruction);
    void receivedALUControlALUOp(Word aluOp);
    void executedALUControl();

    void receivedMakeBranchBransh(Word branch);
    void receivedMakeBranchZero(Word zero);
    void executedMakeBranch();

    void receivedControlOpcode(Word opcode);
    void executedControl();

    void receivedDataMemoryAddress(Word address);
    void receivedDataMemoryWriteData(Word writeData);
    void receivedDataMemoryMemWrite(Word memWrite);
    void receivedDataMemoryMemRead(Word memRead);
    void initDataMemory(int size);
    void loadDataMemory(vector<Word> memoryData);
    void updateDataMemory(Word value, Word address);
    void restartDataMemory();
    void executedDataMemory();

    void receivedInstructionMemoryAddress(Word address);
    void initInstructionMemory(int size);
    void loadInstructionMemory(vector<Word> memoryData);
    void updateInstructionMemory(Word value, Word address);
    void restartInstructionMemory();
    void executedInstructionMemory();

    void receivedImmGenInstruction(Word instruction);
    void executedImmGen();

    void receivedMuxTypeAValueA(Word valueA);
    void receivedMuxTypeAValueB(Word valueB);
    void receivedMuxTypeASelection(Word control);
    void executedMuxTypeA();

    void receivedMuxTypeBValueA(Word valueA);
    void receivedMuxTypeBValueB(Word valueB);
    void receivedMuxTypeBSelection(Word control);
    void executedMuxTypeB();

    void receivedMuxTypeCValueA(Word valueA);
    void receivedMuxTypeCValueB(Word valueB);
    void receivedMuxTypeCSelection(Word control);
    void executedMuxTypeC();

    void receivedPCAddress(Word address);
    void executedPC();

    void receivedRegistersReadRegister1(Word readRegister1);
    void receivedRegistersReadRegister2(Word readRegister2);
    void receivedRegistersWriteRegister(Word writeRegister);
    void receivedRegistersWriteData(Word writeData);
    void receivedRegistersRegWrite(Word regWrite);
    void initRegisters(int size);
    void updateRegister(Word value, Word address);
    void restartRegisters();
    void executedReadRegisters();
    void executedWriteRegisters();

    void treeWidgetInit();
    QTreeWidgetItem* treeWidgetAddRoot(QString name, QString value);
    QTreeWidgetItem* treeWidgetAddChild(QTreeWidgetItem *parent,  QString name, QString value);
    void treeWidgetClear();

    void consoleLog(QString message);

signals:
    void assemble(QString inputFileName, QString outputFileName);

    void init();
    void run();
    void step();
    void restart();

    void loadMemory(QString thisFile);

private:
    QTreeWidgetItem *pcItem;
    QTreeWidgetItem *pcAddressItem;

    QTreeWidgetItem *registerItem;
    QTreeWidgetItem *registerReadRegister1Item;
    QTreeWidgetItem *registerReadRegister2Item;
    QTreeWidgetItem *registerWriteRegItem;
    QTreeWidgetItem *registerWriteDataItem;
    QTreeWidgetItem *registerRegWriteItem;

    QTreeWidgetItem *instructionMemoryItem;
    QTreeWidgetItem *instructionMemoryAddressItem;

    QTreeWidgetItem *dataMemoryItem;
    QTreeWidgetItem *dataMemoryAddressItem;
    QTreeWidgetItem *dataMemoryWriteDataItem;
    QTreeWidgetItem *dataMemoryMemWriteItem;
    QTreeWidgetItem *dataMemoryMemReadItem;

    QTreeWidgetItem *controlItem;
    QTreeWidgetItem *controlOpcodeItem;

    QTreeWidgetItem *aluItem;
    QTreeWidgetItem *aluValueAItem;
    QTreeWidgetItem *aluValueBItem;
    QTreeWidgetItem *aluControlValueItem;
    QTreeWidgetItem *aluReverseItem;

    QTreeWidgetItem *aluControlItem;
    QTreeWidgetItem *aluControlInstructionItem;
    QTreeWidgetItem *aluControlOpItem;

    QTreeWidgetItem *immGenItem;
    QTreeWidgetItem *immGenInstructionItem;

    QTreeWidgetItem *addNextItem;
    QTreeWidgetItem *addNextValueAItem;
    QTreeWidgetItem *addNextValueBItem;

    QTreeWidgetItem *addBranchItem;
    QTreeWidgetItem *addBranchValueAItem;
    QTreeWidgetItem *addBranchValueBItem;

    QTreeWidgetItem *makeBranchItem;
    QTreeWidgetItem *makeBranchBranchItem;
    QTreeWidgetItem *makeBranchZeroItem;

    QTreeWidgetItem *muxAItem;
    QTreeWidgetItem *muxAValueAItem;
    QTreeWidgetItem *muxAValueBItem;
    QTreeWidgetItem *muxASelectionItem;

    QTreeWidgetItem *muxBItem;
    QTreeWidgetItem *muxBValueAItem;
    QTreeWidgetItem *muxBValueBItem;
    QTreeWidgetItem *muxBSelectionItem;

    QTreeWidgetItem *muxCItem;
    QTreeWidgetItem *muxCValueAItem;
    QTreeWidgetItem *muxCValueBItem;
    QTreeWidgetItem *muxCSelectionItem;
};
#endif // VIEWMAINWINDOW_H
