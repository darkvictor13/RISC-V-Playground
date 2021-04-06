/**
  @file main.cpp
  @brief Arquivo principal
  @author Victor Emanuel Almeida
  @version 0.1
*/

#include "mainwindow.h"
#include "instruction.h"
#include "instructiontyper.h"
#include "instructiontypei.h"
#include "arithmeticlogicunit.h"

#include <QApplication>

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

/**
 * @brief Função principal do programa, aquela que chama todas as demais
 * @param argc quantidade de argumentos passados pelo usuário
 * @param argv matriz de char, com argc linhas, contendo cada um dos argumentos
 * passados pelo usuário
 * @return O código lançado pela QApplication, 0 se ocorreu tudo certo
 */
int main(int argc, char **argv)
{
    Instruction *vet[2];
    bool *aux;
    vet[0] = new InstructionTypeI (ADDI_OPCODE, 3, ADDI_FUNCT_3, 3, 10);
    vet[1] = new InstructionTypeR (OR_OPCODE, 5, OR_FUNCT_3, 3, 2, OR_FUNCT_7);

    for (int i = 0; i < 2; i++) {
        vet[i]->printInfo();
        aux = vet[i]->instructionToBin();
        Instruction::printBin(cout, aux);
    }
    //ArithmeticLogicUnit ar;
    //ar.operate(vet + 1);
    QApplication app(argc, argv);
    QCoreApplication::setOrganizationName("Unioeste");
    QCoreApplication::setApplicationName("RISC-V-Playground");

    MainWindow w;

    // Abrindo o tema
    /*
    // o executavel esta dentro de Trab_2_OAC/build
    QFile file("../RISC-V-Playground/theme.qss");
    file.open(QFile::ReadOnly);

    QString styleSheet = QLatin1String(file.readAll());

    app.setStyleSheet(styleSheet);
*/
    w.show();

    delete vet[0];
    delete vet[1];

    return app.exec();
}
