#include "view/header/changepatientwidget.h"
#include "model/header/patienttablemodel.h"
#include "ui_patientformwidget.h"
#include <iostream>

ChangePatientWidget::ChangePatientWidget(QWidget *parent, PatientTableModel *patientTableModel) : PatientFormWidget(parent, patientTableModel)
{
    this->setWindowTitle("Patientendaten ändern");
}

ChangePatientWidget::~ChangePatientWidget()
{
    delete ui;
}

void ChangePatientWidget::setFormData(QModelIndexList& selectionIndexes)
{
    const QList<QLineEdit*> lineEdits = ui->formLayoutWidget->findChildren<QLineEdit*>();
    int column = patientTableModel->TITEL;
    while (column < lineEdits.count()) {
        if (column == patientTableModel->GEBURTSDATUM) {
            column += 1;
            continue;
        }
        const QString value = patientTableModel->data(selectionIndexes[column]).toString();
        lineEdits[column]->setText(value);
        column += 1;
    }
    const QDate birthDate = QDate::fromString(patientTableModel->data(selectionIndexes[patientTableModel->GEBURTSDATUM]).toString(), "dd.MM.yyyy");
    ui->birthDateDateEdit->setDate(birthDate);
    const QString gender = patientTableModel->data(selectionIndexes[patientTableModel->GESCHLECHT]).toString();
    ui->genderComboBox->setCurrentText(gender);
}
