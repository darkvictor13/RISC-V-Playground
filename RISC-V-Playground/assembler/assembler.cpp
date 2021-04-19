/**
 * @file assembler.cpp
 * @brief
 * @author mGuerra
 * @version 0.1
*/

#include "assembler.h"

/**
 * @brief Assembler::Assembler
 */
Assembler::Assembler()
{

}

/**
 * @brief Assembler::assemble
 * @param fileName
 */
void Assembler::assemble(QString inputFileName, QString outputFileName)
{
    QStringList lines = getLines(inputFileName);
    vector<QStringList> words = splitLines(lines);

    vector<Label> labelsTable = mountLabelsTable(words);
    vector<Word> instructions = mountInstructions(words, labelsTable);

    generateFile(instructions, outputFileName);
}

QStringList Assembler::getLines(QString fileName)
{
    emit consoleLog("Loading file to assemble ...\n");

    QFile file(fileName);

    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream inputFile(&file);

    QStringList lines;

    while(!inputFile.atEnd()) {
        QString line = inputFile.readLine();
        lines.append(line);
    }

    file.close();

    return lines;
}

QStringList Assembler::splitLine(QString line)
{
    QStringList words;

    words.append("");

    for(int i = 0, j = 0; i < line.size(); i++) {
        if(line[i] == ' ' || line[i] == ',' || line[i] == '\t' || line[i] == '(' || line[i] == ')') {
            if(!words[j].isEmpty()) {
                words.append("");
                j++;
            }
        }else{
            words[j].append(line[i]);
        }
    }

    return words;
}

vector<QStringList> Assembler::splitLines(QStringList lines)
{
    vector<QStringList> words;

    for(int i = 0; i < lines.size(); i++) {
        words.push_back(splitLine(lines[i]));
    }

    return words;
}

bool Assembler::isLabel(QStringList line)
{
    return line.size() == 1 && line[0][line[0].size() - 1] == ':';
}

bool Assembler::isData(QStringList line)
{
    return line[0][0] == '.';
}

bool Assembler::isInstruction(QStringList line) {
    return !isLabel(line) && !isData(line);
}

vector<Label> Assembler::mountLabelsTable(vector<QStringList> words)
{
    emit consoleLog("Creating table of labels ...\n");

    vector<Label> labelsTable;

    int position = 0;

    for(int i = 0; i < (int) words.size(); i++) {
        if(isLabel(words[i])) {
            Label label;

            label.identifier = words[i][0];
            label.position = position;

            labelsTable.push_back(label);

            continue;
        }

        if(isData(words[i]) || words[i][0].isEmpty()) {
            continue;
        }

        position++;
    }

    return labelsTable;
}

vector<Word> Assembler::mountInstructions(vector<QStringList> words, vector<Label> labelsTable)
{
    emit consoleLog("Assembling instructions ...\n");

    vector<Word> instructions;

    int position = 0;

    for(int i = 0; i < (int) words.size(); i++) {
        if(isInstruction(words[i])) {

            instructions.push_back(mountInstruction(words[i], labelsTable, position));

            position++;
        }
    }

    return instructions;
}

/**
 * @brief Assembler::translateInstructions
 * @param line
 * @return
 */
Word Assembler::mountInstruction(QStringList line, vector<Label> labelsTable, int position)
{
    // add, sub, and, or, addi, lw, sw, beq e bne.

    int i;

    for(i = 0; i < instructionsList.length(); i++) {
        if(!instructionsList[i].compare(line[0])) {
            break;
        }
    }

    switch(i) {
        case 0: return mountADD(line);
        case 1: return mountSUB(line);
        case 2: return mountAND(line);
        case 3: return mountOR(line);
        case 4: return mountADDI(line);
        case 5: return mountLW(line);
        case 6: return mountSW(line);
        case 7: return mountBEQ(line, labelsTable, position);
        case 8: return mountBNE(line, labelsTable, position);
    }

    return 0;
}

int Assembler::getRegister(QString word)
{
    return word.midRef(1).toInt();
}

int Assembler::getImmediate(QString word)
{
    return word.toInt();
}

Word Assembler::mountADD(QStringList line)
{
    InstructionTypeR instruction;

    instruction.setOpcode(51);
    instruction.setRD(getRegister(line[1]));
    instruction.setFunct3(0);
    instruction.setRS1(getRegister(line[2]));
    instruction.setRS2(getRegister(line[3]));
    instruction.setFunct7(0);

    emit consoleLog("add -> " + instruction.getString());

    return instruction;
}

Word Assembler::mountSUB(QStringList line)
{
    InstructionTypeR instruction;

    instruction.setOpcode(51);
    instruction.setRD(getRegister(line[1]));
    instruction.setFunct3(0);
    instruction.setRS1(getRegister(line[2]));
    instruction.setRS2(getRegister(line[3]));
    instruction.setFunct7(32);

    emit consoleLog("sub -> " + instruction.getString());

    return instruction;
}

Word Assembler::mountAND(QStringList line)
{
    InstructionTypeR instruction;

    instruction.setOpcode(51);
    instruction.setRD(getRegister(line[1]));
    instruction.setFunct3(7);
    instruction.setRS1(getRegister(line[2]));
    instruction.setRS2(getRegister(line[3]));
    instruction.setFunct7(0);

    emit consoleLog("and -> " + instruction.getString());

    return instruction;
}

Word Assembler::mountOR(QStringList line)
{
    InstructionTypeR instruction;

    instruction.setOpcode(51);
    instruction.setRD(getRegister(line[1]));
    instruction.setFunct3(6);
    instruction.setRS1(getRegister(line[2]));
    instruction.setRS2(getRegister(line[3]));
    instruction.setFunct7(0);

    emit consoleLog("or -> " + instruction.getString());

    return instruction;
}

Word Assembler::mountADDI(QStringList line)
{
    InstructionTypeI instruction;

    instruction.setOpcode(19);
    instruction.setRD(getRegister(line[1]));
    instruction.setFunct3(0);
    instruction.setRS1(getRegister(line[2]));
    instruction.setImmediate(getImmediate(line[3]));

    emit consoleLog("addi -> " + instruction.getString());

    return instruction;
}

Word Assembler::mountLW(QStringList line)
{
    InstructionTypeI instruction;

    instruction.setOpcode(3);
    instruction.setRD(getRegister(line[1]));
    instruction.setFunct3(2);
    instruction.setRS1(getRegister(line[3]));
    instruction.setImmediate(getImmediate(line[2]));

    emit consoleLog("lw -> " + instruction.getString());

    return instruction;
}

Word Assembler::mountSW(QStringList line)
{
    InstructionTypeS instruction;

    instruction.setOpcode(35);
    instruction.setFunct3(2);
    instruction.setRS1(getRegister(line[3]));
    instruction.setRS2(getRegister(line[1]));
    instruction.setImmediate(getImmediate(line[2]));

    emit consoleLog("sw -> " + instruction.getString());

    return instruction;
}

Word Assembler::mountBEQ(QStringList line, vector<Label> labelsTable, int position)
{
    InstructionTypeSB instruction;

    instruction.setOpcode(99);
    instruction.setFunct3(0);
    instruction.setRS1(getRegister(line[1]));
    instruction.setRS2(getRegister(line[2]));
    instruction.setImmediate(getImmediate(line[3])); /////////////////////

    emit consoleLog("beq -> " + instruction.getString());

    return instruction;
}

Word Assembler::mountBNE(QStringList line, vector<Label> labelsTable, int position)
{
    InstructionTypeSB instruction;

    instruction.setOpcode(99);
    instruction.setFunct3(1);
    instruction.setRS1(getRegister(line[1]));
    instruction.setRS2(getRegister(line[2]));
    instruction.setImmediate(getImmediate(line[3])); /////////////////////

    emit consoleLog("bne -> " + instruction.getString());

    return instruction;
}

void Assembler::generateFile(vector<Word> instructions, QString fileName)
{

    QFile file(fileName);

    if(!file.open(QIODevice::WriteOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream outputFile(&file);

    QString line;
    int stop = (int) instructions.size();

    for(int i = 0; i < stop; i++) {
        line = instructions[i].getString();

        outputFile << line << '\n';
    }

    file.close();

}
