/**
 * @file assembler.h
 * @brief
 * @author mGuerra
 * @version 0.1
*/

#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include <iostream>
#include <fstream>
#include <vector>

#include <QMainWindow>

using namespace std;

class Assembler
{
public:
    Assembler();

    void assemble(string fileName);
};

#endif // ASSEMBLER_H
