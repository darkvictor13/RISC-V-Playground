/**
 * @file assembler.cpp
 * @brief Arquivo responsável por implementar a classe Assembler
 * @author mGuerra
 * @version 0.1
*/


#include "assembler.h"

/**
 * @brief Assembler::Assembler: contrutor da classe Assembler
 */
Assembler::Assembler()
{

}

/**
 * @brief Assembler::assemble: método responsável por gerara a partir de um arquivo contendo o código assemble o código binário da arquitetura RISC-V e guardalo em um arquivo especificado
 * @param QString inputFileName: nome do arquivo de origem do código assmeble
 * @param QString outputFileName: nome do arquivo de destino do código binário
 */
void Assembler::assemble(QString inputFileName, QString outputFileName)
{
    QStringList lines = getLines(inputFileName);
    vector<QStringList> words = splitLines(lines);

    vector<Label> labelsTable = mountLabelsTable(words);
    vector<Word> instructions = mountInstructions(words, labelsTable);

    generateFile(instructions, outputFileName);
}

/**
 * @brief Assembler::getLines: função responsável por ler o arquivo de origem do código assemble linha a linha e gerar uma lista de QStrings
 * @param QString fileName: nome do arquivo de origem do código assemble
 * @return QStringList: lista das linhas de código contidas no arquivo de origem
 */
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

/**
 * @brief Assembler::splitLine: função responsável por serar o nome da instrução e seus argumentos, gerando assim uma lista com estes
 * @param QString line: uma linha contendo uma instrução escrita em código assemble a ser separada
 * @return QStringList: lista de strings contendo o nome e os arqumentos da instrução
 */
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

/**
 * @brief Assembler::splitLines: função responsável por separar todas as palavras dentro de cada linha de código
 * @param QStringList lines: linhas de código assemble
 * @return vector<QStringList>: vector de listas de string contendo os nomes das instruções e seus argumentos
 */
vector<QStringList> Assembler::splitLines(QStringList lines)
{
    vector<QStringList> words;

    for(int i = 0; i < lines.size(); i++) {
        words.push_back(splitLine(lines[i]));
    }

    return words;
}

/**
 * @brief Assembler::isLabel: função responsável por identificar se uma string representa um label
 * @param QStringList line: string a ser identificada como label ou não
 * @return bool: valor booleano que indica se uma string é um label
 */
bool Assembler::isLabel(QStringList line)
{
    return line.size() == 1 && line[0][line[0].size() - 1] == ':';
}

/**
 * @brief Assembler::isData: função responsável por identificar se uma string representa um dado
 * @param QStringList line: string a ser identificada como dado ou não
 * @return bool: valor booleano que indica se uma string é um dado
 */
bool Assembler::isData(QStringList line)
{
    return line[0][0] == '.';
}

/**
 * @brief Assembler::isInstruction: função responsável por identificar se uma string representa uma instrução
 * @param QStringList line: string a ser identificada como instrução ou não
 * @return bool: valor booleano que indica se uma string é uma instrução ou não
 */
bool Assembler::isInstruction(QStringList line) {
    return !isLabel(line) && !isData(line);
}

/**
 * @brief Assembler::mountLabelsTable: função responsável por gerar a tabela de labels para um arquivo de instruções
 * @param vector<QStringList> words: lista de linhas do arquivo
 * @return vector<Label>: tabela de labels
 */
vector<Label> Assembler::mountLabelsTable(vector<QStringList> words)
{
    emit consoleLog("Creating table of labels ...\n");

    vector<Label> labelsTable;

    int position = 0;

    for(int i = 0; i < (int) words.size(); i++) {
        if(isLabel(words[i])) {
            Label label;

            QString identifier = words[i][0];
            identifier.remove(':');

            label.identifier = identifier;
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

/**
 * @brief Assembler::mountInstructions: função responsável por percorrer a lista de instruções e gerar uma outra lista de instruções desta vez em binário
 * @param vector<QStringList> words: lista de instruções ja separados por palávras
 * @param vector<Label> labelsTable: tabela de labels
 * @return vector<Word>: lista de instruções em binário
 */
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
 * @brief Assembler::mountInstruction: função responsável por selecionar o tipo apropriado para uma isntrução e fazer a chamda da sua fnção geradora
 * @param QStringList line: linha contendo uma instrução
 * @param vector<Label> labelsTable: tabela de labels
 * @param int position: posição da instrução
 * @return Word: instrução completa em binário
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

/**
 * @brief Assembler::getRegister: função responsável por gerar o número do registrador a partir do seu identificador em formato string
 * @param QString word: string contendo a identificação do registrador
 * @return int: número do registrador
 */
int Assembler::getRegister(QString word)
{
    return word.midRef(1).toInt();
}

/**
 * @brief Assembler::getImmediate: função responsável por gerar o valor immediato
 * @param QString word: string contendo o valor immediato da instrução
 * @return int: valor immediato
 */
int Assembler::getImmediate(QString word)
{
    return word.toInt();
}

/**
 * @brief Assembler::mountADD: função responsável por gerar o código binário da instrução add
 * @param QStringList line: lista contendo o nome e cada um dos parámetros da instrução
 * @return Word: instrução completa em código binário
 */
Word Assembler::mountADD(QStringList line)
{
    InstructionTypeR instruction;

    instruction.setOpcode(51);
    instruction.setRD(getRegister(line[1]));
    instruction.setFunct3(0);
    instruction.setRS1(getRegister(line[2]));
    instruction.setRS2(getRegister(line[3]));
    instruction.setFunct7(0);

    //emit consoleLog("add -> " + instruction.getString());

    return instruction;
}

/**
 * @brief Assembler::mountSUB: função responsável por gerar o código binário da instrução sub
 * @param QStringList line: lista contendo o nome e cada um dos parámetros da instrução
 * @return Word: instrução completa em código binário
 */
Word Assembler::mountSUB(QStringList line)
{
    InstructionTypeR instruction;

    instruction.setOpcode(51);
    instruction.setRD(getRegister(line[1]));
    instruction.setFunct3(0);
    instruction.setRS1(getRegister(line[2]));
    instruction.setRS2(getRegister(line[3]));
    instruction.setFunct7(32);

    //emit consoleLog("sub -> " + instruction.getString());

    return instruction;
}

/**
 * @brief Assembler::mountAND: função responsável por gerar o código binário da instrução and
 * @param QStringList line: lista contendo o nome e cada um dos parámetros da instrução
 * @return Word: instrução completa em código binário
 */
Word Assembler::mountAND(QStringList line)
{
    InstructionTypeR instruction;

    instruction.setOpcode(51);
    instruction.setRD(getRegister(line[1]));
    instruction.setFunct3(7);
    instruction.setRS1(getRegister(line[2]));
    instruction.setRS2(getRegister(line[3]));
    instruction.setFunct7(0);

    //emit consoleLog("and -> " + instruction.getString());

    return instruction;
}

/**
 * @brief Assembler::mountOR: função responsável por gerar o código binário da instrução or
 * @param QStringList line: lista contendo o nome e cada um dos parámetros da instrução
 * @return Word: instrução completa em código binário
 */
Word Assembler::mountOR(QStringList line)
{
    InstructionTypeR instruction;

    instruction.setOpcode(51);
    instruction.setRD(getRegister(line[1]));
    instruction.setFunct3(6);
    instruction.setRS1(getRegister(line[2]));
    instruction.setRS2(getRegister(line[3]));
    instruction.setFunct7(0);

    //emit consoleLog("or -> " + instruction.getString());

    return instruction;
}

/**
 * @brief Assembler::mountADDI: função responsável por gerar o código binário da instrução addi
 * @param QStringList line: lista contendo o nome e cada um dos parámetros da instrução
 * @return Word: instrução completa em código binário
 */
Word Assembler::mountADDI(QStringList line)
{
    InstructionTypeI instruction;

    instruction.setOpcode(19);
    instruction.setRD(getRegister(line[1]));
    instruction.setFunct3(0);
    instruction.setRS1(getRegister(line[2]));
    instruction.setImmediate(getImmediate(line[3]));

    //emit consoleLog("addi -> " + instruction.getString());

    return instruction;
}

/**
 * @brief Assembler::mountLW: função responsável por gerar o código binário da instrução lw
 * @param QStringList line: lista contendo o nome e cada um dos parámetros da instrução
 * @return Word: instrução completa em código binário
 */
Word Assembler::mountLW(QStringList line)
{
    InstructionTypeI instruction;

    instruction.setOpcode(3);
    instruction.setRD(getRegister(line[1]));
    instruction.setFunct3(2);
    instruction.setRS1(getRegister(line[3]));
    instruction.setImmediate(getImmediate(line[2]));

    //emit consoleLog("lw -> " + instruction.getString());

    return instruction;
}

/**
 * @brief Assembler::mountSW: função responsável por gerar o código binário da instrução sw
 * @param QStringList line: lista contendo o nome e cada um dos parámetros da instrução
 * @return Word: instrução completa em código binário
 */
Word Assembler::mountSW(QStringList line)
{
    InstructionTypeS instruction;

    instruction.setOpcode(35);
    instruction.setFunct3(2);
    instruction.setRS1(getRegister(line[3]));
    instruction.setRS2(getRegister(line[1]));
    instruction.setImmediate(getImmediate(line[2]));

    //emit consoleLog("sw -> " + instruction.getString());

    return instruction;
}

/**
 * @brief Assembler::mountBEQ: função responsável por gerar o código binário da instrução beq
 * @param QStringList line: lista contendo o nome e cada um dos parámetros da instrução
 * @param vector<Label> labelsTable: tabela de labels que associa cada um dos lebols lidos no arquivo de entrada à sua posição no arquivo
 * @param int position: posição da instruçõe em relação às outras
 * @return Word: instrução completa em código binário
 */
Word Assembler::mountBEQ(QStringList line, vector<Label> labelsTable, int position)
{
    InstructionTypeSB instruction;

    instruction.setOpcode(99);
    instruction.setFunct3(0);
    instruction.setRS1(getRegister(line[1]));
    instruction.setRS2(getRegister(line[2]));
    instruction.setImmediate(generateOffset(line[3], labelsTable, position));

    //emit consoleLog("beq -> " + instruction.getString());

    return instruction;
}

/**
 * @brief Assembler::mountBNE: função responsável por gerar o código binário da instrução bne
 * @param QStringList line: lista contendo o nome e cada um dos parámetros da instrução
 * @param vector<Label> labelsTable: tabela de labels que associa cada um dos lebols lidos no arquivo de entrada à sua posição no arquivo
 * @param int position: posição da instruçõe em relação às outras
 * @return Word: instrução completa em código binário
 */
Word Assembler::mountBNE(QStringList line, vector<Label> labelsTable, int position)
{
    InstructionTypeSB instruction;

    instruction.setOpcode(99);
    instruction.setFunct3(1);
    instruction.setRS1(getRegister(line[1]));
    instruction.setRS2(getRegister(line[2]));
    instruction.setImmediate(generateOffset(line[3], labelsTable, position));

    //emit consoleLog("bne -> " + instruction.getString());

    return instruction;
}

/**
 * @brief Assembler::generateOffset: função responsável por cacular offset das instruções de salto
 * @param QString label: nome do label contido na instrução
 * @param vector<Label> labelsTable: tabela de labels que associa cada um dos lebols lidos no arquivo de entrada à sua posição no arquivo
 * @param int position: posição da instruçõe em relação às outras
 * @return int: valor que indica o real valor do offset para a instrução
 */
int Assembler::generateOffset(QString label, vector<Label> labelsTable, int position)
{
    int size = labelsTable.size();
    for(int i = 0; i < size; i++) {
        if(!label.compare(labelsTable[i].identifier)) {
            return (labelsTable[i].position - position) * 4;
        }
    }

    return label.toInt();
}

/**
 * @brief Assembler::generateFile: método que escrebe um conjunto de instruções em binário dentro de um arquivo de texto linha a linha
 * @param vector<Word> instructions: vector de instrções contendo o código em binário de cada instrução, codificado para a arquii=tetura RISC-V
 * @param QString fileName: nome do arquivo de destino do conjunto de instruções
 */
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
