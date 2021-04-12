/**
  @file mainwindow.h
  @brief Arquivo gerado automaticamente pelo qt, tem o objetivo de definir
  o que terá no menu principal da aplicação
  @author Qt creator team
  @version 0.1
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileSystemModel>
#include <QTextStream>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @brief A classe MainWindow: classe gerada pelo qt, com o objetivo
 * de criar menus
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QString filename;

public:
    MainWindow(QWidget *parent = nullptr);

     void loadFile(const QString &fileName);

    ~MainWindow();

private slots:
    void on_actionSobre_triggered();

    void on_actionSobre_o_QT_triggered();

    void on_actionAbrir_codigo_assembly_triggered();

    void on_actionSalvar_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
