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

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
