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

/*
void MainWindow::loadFile(const QString &fileName)
//! [42] //! [43]
{
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Application"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(QDir::toNativeSeparators(fileName), file.errorString()));
        return;
    }

    QTextStream in(&file);
#ifndef QT_NO_CURSOR
    QGuiApplication::setOverrideCursor(Qt::WaitCursor);
#endif
    textEdit->setPlainText(in.readAll());
#ifndef QT_NO_CURSOR
    QGuiApplication::restoreOverrideCursor();
#endif

    setCurrentFile(fileName);
    statusBar()->showMessage(tr("File loaded"), 2000);
}

void MainWindow::on_actionAbrir_codigo_assembly_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    if (!fileName.isEmpty())
        loadFile(fileName);
}*/

void MainWindow::on_actionSobre_triggered()
{
    QMessageBox::about(this, "RISC-V-Playground", "Colocar aqui info");
}

void MainWindow::on_actionSobre_o_QT_triggered()
{
    QMessageBox::aboutQt(this);
}

void MainWindow::on_actionAbrir_codigo_assembly_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this,
        "Open assembly file", "../files/", "");
    QFile file(filename);
    file.open(QFile::ReadOnly | QFile::Text);
    ui->plainTextEdit->setPlainText(file.readAll());
    file.close();
}

void MainWindow::on_actionSalvar_triggered()
{
    QFile file("../files/test.s");
    file.open(QFile::WriteOnly | QFile::Text);
    QTextStream out(&file);
    out << ui->plainTextEdit->toPlainText();
    file.close();
}
