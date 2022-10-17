#include "view/header/mainwindow.h"
#include "model/header/patientmanager.h"
#include "model/header/patienttablemodel.h"
#include "ui_mainwindow.h"
#include "view/header/addpatientwidget.h"
#include "view/header/changepatientwidget.h"
#include "view/header/deletedialog.h"
#include "view/header/showpatientwidget.h"
#include <QMessageBox>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->patientManager->load_from_json("patients.json");
    this->patientTableModel = new PatientTableModel(this->patientManager->getPatients(), this);
    this->sortModel->setSourceModel(patientTableModel);
    ui->tableView->setModel(this->sortModel);
    for (int i = 4; i < 10; ++i) {
        ui->tableView->setColumnHidden(i, true);
    }
    this->connectSignals();
}

MainWindow::~MainWindow()
{
    delete patientTableModel;
    delete ui;
}

void MainWindow::connectSignals()
{
    connect(ui->addPatientsButton, SIGNAL(clicked()), this, SLOT(openAddPatientWidget()));
    connect(ui->changePatientsButto, SIGNAL(clicked()), this, SLOT(openChangePatientWidget()));
    connect(ui->showPatientsButton, SIGNAL(clicked()), this, SLOT(openShowPatientWidget()));
    connect(ui->cancelSelectionButton, SIGNAL(clicked()), this, SLOT(cancelSelection()));
    connect(ui->deletePatientsButton, SIGNAL(clicked()), this, SLOT(openDeletePatientDialog()));
    connect(ui->exportPatientsButton, SIGNAL(clicked()), this, SLOT(exportPatients()));
}

void MainWindow::openAddPatientWidget()
{
    AddPatientWidget* addPatientWidget = new AddPatientWidget();
    addPatientWidget->show();
}

void MainWindow::openChangePatientWidget()
{
    if (!checkSelection()) {
        showWarning("Warnung", "Es wurde kein oder mehr als ein Patient zum bearbeiten ausgewählt");
        return;
    }
    QModelIndexList* selectionIndexes = new QModelIndexList(ui->tableView->selectionModel()->selection().indexes());
    ChangePatientWidget* changePatientWidget = new ChangePatientWidget(nullptr, patientTableModel, *selectionIndexes);
    changePatientWidget->show();
}

bool MainWindow::checkSelection() {
    const QModelIndexList selection = ui->tableView->selectionModel()->selectedRows();
    if (selection.empty() || selection.count() > 1) {
        return false;
    }
    return true;
}

void MainWindow::showWarning(const QString &title, const QString &message) {
    QMessageBox warning;
    warning.setWindowTitle(title);
    warning.setText(message);
    warning.exec();
}

void MainWindow::openShowPatientWidget()
{
    if (!checkSelection()) {
        showWarning("Warnung", "Es wurde kein oder mehr als ein Patient zum ansehen ausgewählt");
        return;
    }
    QModelIndexList* selectionIndexes = new QModelIndexList(ui->tableView->selectionModel()->selection().indexes());
    ShowPatientWidget* showPatientWidget = new ShowPatientWidget(nullptr, patientTableModel, *selectionIndexes);
    showPatientWidget->show();
}

void MainWindow::openDeletePatientDialog()
{
    if (!checkSelection()) {
        showWarning("Warnung", "Es wurde kein oder mehr als ein Patient zum löschen ausgewählt");
        return;
    }
    QModelIndexList* selectionIndexes = new QModelIndexList(ui->tableView->selectionModel()->selection().indexes());
    DeleteDialog* deleteDialog = new DeleteDialog(nullptr, patientTableModel, *selectionIndexes);
    deleteDialog->show();
}

void MainWindow::cancelSelection()
{
    if (!ui->tableView->selectionModel()->hasSelection()) {
        return;
    }
    ui->tableView->selectionModel()->clearSelection();
}

void MainWindow::exportPatients()
{
    QModelIndexList selection = ui->tableView->selectionModel()->selectedRows();
    std::sort(selection.begin(), selection.end());
    QList<Patient> selectedPatients = patientTableModel->getPatients(selection);
}
