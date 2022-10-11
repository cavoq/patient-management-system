#include "view/header/mainwindow.h"

#include <QApplication>
#include <iostream>
#include <QtCore>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
