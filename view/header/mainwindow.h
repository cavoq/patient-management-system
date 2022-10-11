#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "model/header/patientmanager.h"
#include "model/header/patienttablemodel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void openAddPatientWidget();
    void openChangePatientWidget();

public:
    MainWindow(QWidget *parent = nullptr);
    void connectSignals();
    ~MainWindow();

private:
    PatientManager* patientManager = new PatientManager();
    PatientTableModel* patientTableModel;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
