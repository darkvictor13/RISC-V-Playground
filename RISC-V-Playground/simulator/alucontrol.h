/**
 * @file alucontrol.h
 * @brief Arquivo responsável por definir a classe ALUControl
 * @author mGuerra
 * @version 0.1
*/

#ifndef ALUCONTROL_H
#define ALUCONTROL_H

#include <QObject>

#include "word/word.h"

#include "alu.h"
#include "addbranch.h"

class ALU;
class AddBranch;

/**
 * @brief A classe ALUControl: Responsável por indicar que operação
 * a ALU deve executar
 */
class ALUControl : public QObject
{
    Q_OBJECT

private:
    ALU *alu = NULL;

    Word instruction = 0;
    Word aluOp = 0;

    bool hasInstruction = false;
    bool hasALUOp = false;

public:
    ALUControl();

    void connect(ALU *alu);

    void setInstruction(Word instruction);
    void setALUOp(Word aluOp);

    void tryExecute();
    void execute();

    ~ALUControl();

signals:
    void receivedInstruction(Word instruction);
    void receivedALUOp(Word aluOp);

    void executed();

};

#endif // ALUCONTROL_H
