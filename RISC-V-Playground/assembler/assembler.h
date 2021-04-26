/**
 * @file assembler.h
 * @brief Arquivo responsável por definir a classe Assembler
 * @author mGuerra
 * @version 0.1
*/

#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include <QTextStream>
#include <QListWidget>
#include <QMessageBox>
#include <QObject>
#include <QFile>

#include "instructions/instructiontyper.h"
#include "instructions/instructiontypei.h"
#include "instructions/instructiontypes.h"
#include "instructions/instructiontypesb.h"

using namespace std;

/**
 * @brief A estrutura Label: responsável por representar um label dentro do código assemble, para isso armazena a o nome do label e a posição em que este se encontra.
 */
struct Label{
    QString identifier;
    int position;
};

/**
 * @brief A classe Assembler: responsável por gerar o código binario a partir das instruções assembler para os processadorees da arquitetura RISC-V
 */
class Assembler : public QObject
{
    Q_OBJECT

private:
    QStringList getLines(QString fileName);
    QStringList splitLine(QString line);
    vector<QStringList> splitLines(QStringList lines);

    bool isLabel(QStringList word);
    bool isData(QStringList word);
    bool isInstruction(QStringList word);

    vector<Label> mountLabelsTable(vector<QStringList> words);
    vector<Word> mountInstructions(vector<QStringList> words, vector<Label> labelsTable);
    Word mountInstruction(QStringList line, vector<Label> labelsTable, int position);

    QStringList instructionsList = {"add", "sub", "and", "or", "addi", "lw", "sw", "beq", "bne"};

    int getRegister(QString word);
    int getImmediate(QString word);

    Word mountADD(QStringList line);
    Word mountSUB(QStringList line);
    Word mountAND(QStringList line);
    Word mountOR(QStringList line);
    Word mountADDI(QStringList line);
    Word mountLW(QStringList line);
    Word mountSW(QStringList line);
    Word mountBEQ(QStringList line, vector<Label> labelsTable, int position);
    Word mountBNE(QStringList line, vector<Label> labelsTable, int position);

    int generateOffset(QString label, vector<Label> labelsTable, int position);

    void generateFile(vector<Word> instructions, QString fileName);

public:
    Assembler();

public slots:
    void assemble(QString inputFileName, QString outputFileName);

signals:
    void consoleLog(QString message);

};

#endif // ASSEMBLER_H
