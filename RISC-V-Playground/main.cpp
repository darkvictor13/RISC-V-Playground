/**
 * @file main.cpp
 * @brief
 * @author mGuerra
 * @version 0.1
*/

#include "viewmainwindow.h"

#include <QApplication>
#include <QFile>

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
