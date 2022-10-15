#include "view/header/mainwindow.h"
#include "model/header/patientmanager.h"
#include "model/header/patienttablemodel.h"
#include "ui_mainwindow.h"
#include "view/header/addpatientwidget.h"
#include "view/header/changepatientwidget.h"
#include "view/header/showpatientwidget.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->patientManager->load_from_json("patients.json");
    this->patientTableModel = new PatientTableModel(this->patientManager->getPatients(), this);
    ui->tableView->setModel(this->patientTableModel);
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
}

void MainWindow::openAddPatientWidget()
{
    AddPatientWidget* addPatientWidget = new AddPatientWidget();
    addPatientWidget->show();
}

void MainWindow::openChangePatientWidget()
{
    if (!checkSelection()) {
        showWarning("Warnung", "Es wurde kein Patient zum bearbeiten ausgewählt");
        return;
    }
    QModelIndexList* selection = new QModelIndexList(ui->tableView->selectionModel()->selection().indexes());
    ChangePatientWidget* changePatientWidget = new ChangePatientWidget(nullptr, patientTableModel, *selection);
    changePatientWidget->show();
}

bool MainWindow::checkSelection() {
    const QModelIndex currentIndex = ui->tableView->selectionModel()->currentIndex();
    if (!currentIndex.isValid() || !ui->tableView->selectionModel()->isSelected(currentIndex)) {
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
        showWarning("Warnung", "Es wurde kein Patient zum ansehen ausgewählt");
        return;
    }
    QModelIndexList* selection = new QModelIndexList(ui->tableView->selectionModel()->selection().indexes());
    ShowPatientWidget* showPatientWidget = new ShowPatientWidget(nullptr, patientTableModel, *selection);
    showPatientWidget->show();
}

void MainWindow::cancelSelection()
{
    if (!ui->tableView->selectionModel()->hasSelection()) {
        return;
    }
    ui->tableView->selectionModel()->clearSelection();
}
