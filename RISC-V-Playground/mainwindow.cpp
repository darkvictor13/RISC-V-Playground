/**
  @file mainwindow.cpp
  @brief Arquivo gerado automaticamente pelo qt, tem o objetivo de criar
  o menu principal da aplicação
  @author Qt creator team
  @version 0.1
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"

/**
 * @brief COnstrutor da classe MainWindow
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

/**
 * @brief Destrutor da classe MainWindow
 */
MainWindow::~MainWindow()
{
    delete ui;
}

