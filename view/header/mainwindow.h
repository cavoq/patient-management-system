#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "model/header/patienttablemodel.h"
#include "patientjsonreader.h"
#include "patientjsonwriter.h"
#include "qsortfilterproxymodel.h"

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
    void search(const QString &searchString);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    PatientJsonReader *patientJsonReader = new PatientJsonReader();
    PatientJsonWriter *patientJsonWriter = new PatientJsonWriter();
    QSortFilterProxyModel *sortProxyModel = new QSortFilterProxyModel;
    PatientTableModel *patientTableModel;
    Ui::MainWindow *ui;
    void loadPatients();
    void connectSignals();
    void hideColumns();
    QStringList getSearchTexts(const QString &searchString);
    void showWarning(const QString &title, const QString &text);
    bool checkSelection();
    QString getFileFromDialog();
};
#endif // MAINWINDOW_H
