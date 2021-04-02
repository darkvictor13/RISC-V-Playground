/**
  @file main.cpp
  @brief Arquivo principal
  @author Victor Emanuel Almeida
  @version 0.1
*/

#include "mainwindow.h"
#include "instruction.h"
#include "instructiontyper.h"

#include <QApplication>
#include <QFile>

/**
  @mainpage Algorítimo para Simulador RISC-V

  @section Objetivo Objetivo

  Aplicativo tem como objetivo simular o comportamento
  de uma máquina RISC-V.

  Considerando um conjunto limitado de instruções:
  - ADDI
  - ADD
  - SUB
  - AND
  - OR
  - LW
  - SW
  - BEQ
  - BNE

  @section D Descrevendo a experiência

  Escrever algo aqui

  @subsection positivos Pontos positivos

  - Alguma coisa

  @subsection negativos Pontos negativos

  - Alguma coisa

  @section trabalho Descrição da dinâmica de trabalho do grupo

  Dentro da documentação de cada método e classe possui o nome do author
*/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;

    // Abrindo o tema
    QFile file("/home/victor/Repos/Trab_2_OAC/RISC-V-Playground/theme.qss");

    //QFile file("theme.qss");
    file.open(QFile::ReadOnly);

    QString styleSheet = QLatin1String(file.readAll());

    a.setStyleSheet(styleSheet);

    w.show();

    return a.exec();
}
