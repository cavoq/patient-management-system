#include "view/header/changepatientwidget.h"
#include "model/header/patienttablemodel.h"
#include "ui_patientformwidget.h"

ChangePatientWidget::ChangePatientWidget(QWidget *parent) : PatientFormWidget(parent)
{
    this->setWindowTitle("Patientendaten ändern");
}

ChangePatientWidget::~ChangePatientWidget()
{
    delete ui;
}

void ChangePatientWidget::setFormData(PatientTableModel& patientTableModel, QModelIndexList& patientIndexes)
{
}
