#include "mainwindow.h"
#include "instruction.h"
#include "instruction_type_r.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    Instruction_Type_R teste(51, 5, 0, 5, 5, 0);

    teste.printInfo();

    QApplication a(argc, argv);

    MainWindow w;

    w.show();

    return a.exec();
}
