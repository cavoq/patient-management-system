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

void ChangePatientWidget::setFormData(PatientTableModel& patientTableModel, QModelIndexList& selectionIndexes)
{
    ui->titelLineEdit->setText(patientTableModel.data(selectionIndexes[patientTableModel.TITEL]).toString());
    ui->firstNameLineEdit->setText(patientTableModel.data(selectionIndexes[patientTableModel.VORNAME]).toString());
    ui->nameLineEdit->setText(patientTableModel.data(selectionIndexes[patientTableModel.NACHNAME]).toString());
    ui->birthDateDateEdit->setDate(QDate::fromString(patientTableModel.data(selectionIndexes[patientTableModel.GEBURTSDATUM]).toString(), "dd.MM.yyyy"));
    ui->streetLineEdit->setText(patientTableModel.data(selectionIndexes[patientTableModel.STRASSE]).toString());
    ui->houseNumberLineEdit->setText(patientTableModel.data(selectionIndexes[patientTableModel.HAUSNUMMER]).toString());
    ui->pLZLineEdit->setText(patientTableModel.data(selectionIndexes[patientTableModel.PLZ]).toString());
    ui->placeLineEdit->setText(patientTableModel.data(selectionIndexes[patientTableModel.ORT]).toString());
    ui->phoneNumberLineEdit->setText(patientTableModel.data(selectionIndexes[patientTableModel.TELEFONNUMMER]).toString());
    ui->genderComboBox->setCurrentText(patientTableModel.data(selectionIndexes[patientTableModel.GESCHLECHT]).toString());
}
