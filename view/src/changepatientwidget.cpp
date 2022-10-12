#include "view/header/changepatientwidget.h"
#include "model/header/patienttablemodel.h"
#include "ui_patientformwidget.h"
#include <iostream>

ChangePatientWidget::ChangePatientWidget(QWidget *parent) : PatientFormWidget(parent)
{
    this->setWindowTitle("Patientendaten ändern");
}

ChangePatientWidget::~ChangePatientWidget()
{
    delete ui;
}

void ChangePatientWidget::setFormData(PatientTableModel& patientTableModel, QModelIndexList& selectionIndexes)
{
    const QList<QLineEdit*> lineEdits = ui->formLayoutWidget->findChildren<QLineEdit*>();
    for (int i = 0; i < lineEdits.count(); ++i) {
        const QVariant columnData = patientTableModel.data(selectionIndexes[i]);
        std::cout << columnData.toString().toStdString() << std::endl;
        lineEdits[i]->setText(columnData.toString());
    }
    ui->birthDateDateEdit->setDate(patientTableModel.data(selectionIndexes[3]).toDate());
}
