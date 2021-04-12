/**
 * @file assembler.cpp
 * @brief
 * @author mGuerra
 * @version 0.1
*/

#include "assembler.h"

Assembler::Assembler()
{

}

/**
 * @brief Assembler::assemble
 * @param fileName
 */
void Assembler::assemble(string fileName)
{
    ifstream inputStream(fileName);

    if (!inputStream) {
        cerr << "Can't open input file!";
    }

    vector<string> lines;

    string line;

    while (getline(inputStream, line)) {
        lines.push_back(line);
    }

}
