#include "view/header/mainwindow.h"
#include "model/header/patienttablemodel.h"
#include "qjsondocument.h"
#include "ui_mainwindow.h"
#include "view/header/addpatientwidget.h"
#include "view/header/changepatientwidget.h"
#include "view/header/deletedialog.h"
#include "view/header/showpatientwidget.h"
#include <QMessageBox>
#include <QFileDialog>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadPatients();
    sortProxyModel->setSourceModel(patientTableModel);
    ui->tableView->setModel(sortProxyModel);
    hideColumns();
    connectSignals();
}

MainWindow::~MainWindow()
{
    patientJsonWriter->writeToJson("patients.json", patientTableModel->getPatients());
    delete patientTableModel;
    delete ui;
}

void MainWindow::loadPatients()
{
    try {
        QList<Patient> patients = patientJsonReader->readFromJson("patients.json");
        patientTableModel = new PatientTableModel(patients, this);
    } catch (QJsonParseError e) {
        showWarning("Error", "Das lesen der Patientendaten schlug fehl");
        return;
    }
}

void MainWindow::hideColumns()
{
    for (int column = patientTableModel->STRASSE; column < patientTableModel->GESCHLECHT; ++column) {
            ui->tableView->setColumnHidden(column, true);
    }
}

void MainWindow::connectSignals()
{
    connect(ui->addPatientsButton, SIGNAL(clicked()), this, SLOT(openAddPatientWidget()));
    connect(ui->changePatientsButto, SIGNAL(clicked()), this, SLOT(openChangePatientWidget()));
    connect(ui->showPatientsButton, SIGNAL(clicked()), this, SLOT(openShowPatientWidget()));
    connect(ui->cancelSelectionButton, SIGNAL(clicked()), this, SLOT(cancelSelection()));
    connect(ui->deletePatientsButton, SIGNAL(clicked()), this, SLOT(openDeletePatientDialog()));
    connect(ui->exportPatientsButton, SIGNAL(clicked()), this, SLOT(exportPatients()));
    connect(ui->searchLineEdit, SIGNAL(textEdited(QString)), this, SLOT(search(QString)));
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
    patientJsonWriter->writeToJson(getFileFromDialog(), selectedPatients);
}

void MainWindow::search(const QString &searchString)
{
    QStringList searchTexts = getSearchTexts(searchString);
    int column = patientTableModel->VORNAME;
    for (QString &searchText: searchTexts) {
        QString findName = searchText.trimmed();
        sortProxyModel->setFilterKeyColumn(column);
        sortProxyModel->setFilterFixedString(findName);
        column += 1;
    }
}

QStringList MainWindow::getSearchTexts(const QString &searchString) {
    QStringList searchTexts = searchString.split(",");
    return searchTexts;
}

QString MainWindow::getFileFromDialog()
{
    QString jsonFileName = QFileDialog::getSaveFileName(this,
         tr("Open Json File"), "/home", tr("Json Files (*.json)"));
    return jsonFileName;
}
