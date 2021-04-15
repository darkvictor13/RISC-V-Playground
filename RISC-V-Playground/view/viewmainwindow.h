/**
 * @file viewmainwindow.h
 * @brief
 * @author mGuerra
 * @version 0.1
*/

#ifndef VIEWMAINWINDOW_H
#define VIEWMAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QTextStream>

#include "simulator/simulator.h"
#include "assembler/assembler.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ViewMainWindow; }
QT_END_NAMESPACE

class ViewMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    ViewMainWindow(QWidget *parent = nullptr);

    Ui::ViewMainWindow *ui;

    ~ViewMainWindow();

private slots:
    void on_actionNew_triggered();
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionSave_as_triggered();
    void on_actionPreferences_triggered();
    void on_actionExit_triggered();
    void on_actionAbut_us_triggered();
    void on_actionDocumentation_triggered();
    void on_actionLoad_triggered();
    void on_actionRun_triggered();
    void on_actionStep_triggered();
    void on_actionRestart_triggered();

private:
    QString thisFile = "../test/test.in";

    Simulator simulator;
    Assembler assembler;
};
#endif // VIEWMAINWINDOW_H
