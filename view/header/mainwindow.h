#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "model/header/patienttablemodel.h"
#include "header/multicolumnfilterproxymodel.h"
#include "header/patientjsonreader.h"
#include "header/patientjsonwriter.h"
#include "view/header/patientformwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void openAddPatientWidget();
    void openChangePatientWidget();
    void openShowPatientWidget();
    void openDeletePatientDialog();
    void cancelSelection();
    void exportPatients();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    PatientJsonReader *patientJsonReader = new PatientJsonReader();
    PatientJsonWriter *patientJsonWriter = new PatientJsonWriter();
    MultiColumnFilterProxyModel *filterProxyModel = new MultiColumnFilterProxyModel();
    PatientTableModel *patientTableModel;
    PatientFormWidget *getPatientFormWidget();
    Ui::MainWindow *ui;
    void loadPatients();
    void connectSignals();
    void hideColumns();
    void showMessage(const QString &title, const QString &text);
    bool checkSelection();
    QString getFileFromDialog();
};
#endif // MAINWINDOW_H
