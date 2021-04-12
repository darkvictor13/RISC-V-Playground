/**
 * @file main.cpp
 * @brief
 * @author mGuerra
 * @version 0.1
*/

#include "viewmainwindow.h"

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

/**
 * @brief Função principal do programa, aquela que chama todas as demais
 * @param argc quantidade de argumentos passados pelo usuário
 * @param argv matriz de char, com argc linhas, contendo cada um dos argumentos
 * passados pelo usuário
 * @return O código lançado pela QApplication, 0 se ocorreu tudo certo
 */

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QFile file("../themes/Combinear/Combinear.qss");
    file.open(QFile::ReadOnly);

    QString styleSheet = QLatin1String(file.readAll());
    app.setStyleSheet(styleSheet);

    ViewMainWindow mainWindow;

    mainWindow.show();

    return app.exec();
}
