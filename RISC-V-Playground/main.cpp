/**
 * @file main.cpp
 * @brief Arquivo principal do programa
 * @author mGuerra, Victor
 * @version 0.1
*/

#include "view/viewmainwindow.h"
#include "assembler/assembler.h"

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

  @section uso Instruções para uso

  Uma vez iniciada a execução do programa esses são os passos necessários para o uso do Software:
  
  - Abrindo o arquivo

  @image html img1.png

  - Selecionando o arquivo

  @image html img2.png

  - Carregando as instruções

  @image html img3.png

  - Execute passo a passo

  @image html img4.png

  @section j Abas do Programa:
  - Registers: Mostra o conteúdo dos registradores.
  -
  -
  -

  @section Como Como foi implementado

  @subsection caminho O caminho de Dados:
  O caminho de dados foi implementado de forma igual ao explicado em sala de aula:

  @image html caminho.png

  Porém para a implementação da instrução BNE, faz-se necessário a inclusão de mais uma "flag",
  chamada de reverse a qual nega o valor da flag "Zero" quando a instrução chamada é a BNE.

  @subsection softwares Softwares utilizados para o desenvolvimento:

  - Controle de Versão: Git;
  - Hospedagem do controle de Versão: Github;
  - Framework: Qt;
  - Documentação: Doxygen;
  - Hospedagem do Site gerado pela documentação: Github

  Escrever algo aqui


  @section D Descrevendo a experiência

  Escrever algo aqui

  
  @subsection positivos Pontos positivos:

  - Falar coisas positivas sobre a experiencia;
  - O Software atinge o objetivo de simular uma máquina RISC-V;
  - O Software representa o simula exatamente o caminho de dados
  proposto em sala;
  - O Software representa cada instrução no nível binário;
  -

  @subsection negativos Pontos negativos:

  - Falar coisas negativas sobre a experiencia;
  - Houve trabalho feito a toa;

  @section trabalho Descrição da dinâmica de trabalho do grupo
  Dentro da documentação de cada método e classe possui o nome do autor
*/

/**
 * @brief main
 * @param argc quantidade de argumentos passados pelo usuário
 * @param argv  matriz de char, com argc linhas, contendo cada um dos argumentos
 * passados pelo usuário
 * @return O código lançado pela QApplication, 0 se ocorreu tudo certo
 */
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //QFile file("../themes/Combinear/Combinear.qss");
    //file.open(QFile::ReadOnly);

    //QString styleSheet = QLatin1String(file.readAll());
    //app.setStyleSheet(styleSheet);

    ViewMainWindow mainWindow;

    mainWindow.show();

    return app.exec();
}
