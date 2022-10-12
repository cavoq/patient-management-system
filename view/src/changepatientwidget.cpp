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
    ui->titelLineEdit->setText(patientTableModel.data(selectionIndexes[0]).toString());
    ui->firstNameLineEdit->setText(patientTableModel.data(selectionIndexes[1]).toString());
    ui->nameLineEdit->setText(patientTableModel.data(selectionIndexes[2]).toString());
    ui->birthDateDateEdit->setDate(QDate::fromString(patientTableModel.data(selectionIndexes[3]).toString(), "dd.MM.yyyy"));
    ui->streetLineEdit->setText(patientTableModel.data(selectionIndexes[4]).toString());
    ui->houseNumberLineEdit->setText(patientTableModel.data(selectionIndexes[5]).toString());
    ui->pLZLineEdit->setText(patientTableModel.data(selectionIndexes[6]).toString());
    ui->placeLineEdit->setText(patientTableModel.data(selectionIndexes[7]).toString());
    ui->phoneNumberLineEdit->setText(patientTableModel.data(selectionIndexes[8]).toString());
}
