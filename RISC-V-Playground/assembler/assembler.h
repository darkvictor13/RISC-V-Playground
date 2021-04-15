/**
 * @file assembler.h
 * @brief
 * @author mGuerra
 * @version 0.1
*/

#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include <QMessageBox>
#include <QTextStream>
#include <QMainWindow>
#include <QListWidget>
#include <QFile>

#include "instructions/instructiontyper.h"
#include "instructions/instructiontypei.h"
#include "instructions/instructiontypes.h"
#include "instructions/instructiontypesb.h"

struct Label{
    QString identifier;
    int position;
};

using namespace std;

class Assembler
{
private:
    QListWidget *console;

public:
    Assembler();

    void setConsole(QListWidget *console);

    void assemble(QString fileName);

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

    Word mountADD(QStringList line);
    Word mountSUB(QStringList line);
    Word mountAND(QStringList line);
    Word mountOR(QStringList line);
    Word mountADDI(QStringList line);
    Word mountLW(QStringList line);
    Word mountSW(QStringList line);
    Word mountBEQ(QStringList line, vector<Label> labelsTable, int position);
    Word mountBNE(QStringList line, vector<Label> labelsTable, int position);

    QString generateFileName(QString fileName);
    void generateFile(vector<Word> instructions, QString fileName);
};

#endif // ASSEMBLER_H
