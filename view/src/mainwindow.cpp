#include "view/header/mainwindow.h"
#include "model/header/patientmanager.h"
#include "model/header/patienttablemodel.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initialize()
{
    PatientManager* patient_manager = new PatientManager();
    patient_manager->load_from_json("patients.json");
    QList<Patient> patients = patient_manager->getPatients();
    PatientTableModel* patient_table_model = new PatientTableModel(patients, this);
    ui->tableView->setModel(patient_table_model);
}
