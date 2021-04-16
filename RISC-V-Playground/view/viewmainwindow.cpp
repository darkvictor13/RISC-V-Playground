/**
 * @file viewmainwindow.cpp
 * @brief
 * @author mGuerra
 * @version 0.1
*/

#include "viewmainwindow.h"
#include "ui_viewmainwindow.h"

ViewMainWindow::ViewMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ViewMainWindow)
{
    ui->setupUi(this);

    assembler.setConsole(ui->consoleListWidget);
}

ViewMainWindow::~ViewMainWindow()
{
    delete ui;
}


void ViewMainWindow::on_actionNew_triggered()
{
    thisFile = "new";

    ui->plainTextEdit->setPlainText("");
}

void ViewMainWindow::on_actionOpen_triggered()
{
    thisFile = QFileDialog::getOpenFileName(this, "Open assembly file", "../tests/", "");

    QFile file(thisFile);
    file.open(QFile::ReadOnly | QFile::Text);

    ui->plainTextEdit->setPlainText(file.readAll());

    file.close();

    thisFile = generateFileName(thisFile);
}

void ViewMainWindow::on_actionSave_triggered()
{
    QFile file(thisFile);
    file.open(QFile::WriteOnly | QFile::Text);

    QTextStream outputFile(&file);
    outputFile << ui->plainTextEdit->toPlainText();

    file.close();
}

void ViewMainWindow::on_actionSave_as_triggered()
{
    thisFile = QFileDialog::getOpenFileName(this, "Open assembly file", "../files/", "");

    QFile file(thisFile);
    file.open(QFile::WriteOnly | QFile::Text);

    QTextStream outputFile(&file);
    outputFile << ui->plainTextEdit->toPlainText();

    file.close();
}

void ViewMainWindow::on_actionPreferences_triggered()
{

}

void ViewMainWindow::on_actionExit_triggered()
{
    close();
}

void ViewMainWindow::on_actionAbut_us_triggered()
{

}

void ViewMainWindow::on_actionDocumentation_triggered()
{

}

void ViewMainWindow::on_actionLoad_triggered()
{
    assembler.assemble(thisFile + ".s", thisFile + ".b");

    QFile file(thisFile + ".b");
    file.open(QFile::ReadOnly | QFile::Text);

    ui->instructionListWidget->addItem(file.readAll());

    file.close();

    simulator.loadMemory(thisFile);
}

void ViewMainWindow::on_actionRun_triggered()
{

}

void ViewMainWindow::on_actionStep_triggered()
{

}

void ViewMainWindow::on_actionRestart_triggered()
{

}

QString ViewMainWindow::generateFileName(QString fileName)
{
    return fileName.mid(0, fileName.lastIndexOf("."));
}

