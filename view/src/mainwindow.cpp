#include "view/header/mainwindow.h"
#include "model/header/patientmanager.h"
#include "model/header/patienttablemodel.h"
#include "ui_mainwindow.h"
#include "view/header/addpatientwidget.h"
#include "view/header/changepatientwidget.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->patientManager->load_from_json("patients.json");
    this->patientTableModel = new PatientTableModel(this->patientManager->getPatients(), this);
    ui->tableView->setModel(this->patientTableModel);
    this->connectSignals();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectSignals()
{
    connect(ui->addPatientsButton, SIGNAL(clicked()), this, SLOT(openAddPatientWidget()));
    connect(ui->changePatientsButto, SIGNAL(clicked()), this, SLOT(openChangePatientWidget()));
}

void MainWindow::openAddPatientWidget()
{
    AddPatientWidget* add_patient_widget = new AddPatientWidget();
    add_patient_widget->show();
}

void MainWindow::openChangePatientWidget()
{
    const QModelIndex selection = ui->tableView->selectionModel()->currentIndex();
    if (!selection.isValid()) {
        QMessageBox warning;
        warning.setWindowTitle("Warnung");
        warning.setText("Es wurde kein Patient zum bearbeiten ausgewählt");
        warning.exec();
        return;
    }
    QModelIndexList indexes = ui->tableView->selectionModel()->selection().indexes();
    ChangePatientWidget* changePatientWidget = new ChangePatientWidget(nullptr, patientTableModel);
    changePatientWidget->setFormData(indexes);
    changePatientWidget->show();
}
