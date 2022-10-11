#include "view/header/addpatientwidget.h"
#include "ui_patientformwidget.h"

AddPatientWidget::AddPatientWidget(QWidget *parent) : PatientFormWidget(parent)
{
    this->setWindowTitle("Patient hinzufügen");
}

AddPatientWidget::~AddPatientWidget()
{
    delete ui;
}
