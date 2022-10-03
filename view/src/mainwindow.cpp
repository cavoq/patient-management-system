#include "view/header/mainwindow.h"
#include "model/header/patientmanager.h"
#include "model/header/patientmodel.h"
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
    PatientModel* patient_model = new PatientModel(patients, this);
    ui->tableView->setModel(patient_model);
}
