#include "view/header/mainwindow.h"

#include <QApplication>
#include <iostream>
#include <QtCore>
#include "model/header/patientmanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
