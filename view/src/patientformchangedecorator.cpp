#include "view/header/patientformchangedecorator.h"
#include "ui_patientformwidget.h"

PatientFormChangeDecorator::PatientFormChangeDecorator(PatientFormWidget *patientFormWidget, QString windowTitle)
{
    this->patientFormWidget = patientFormWidget;
    this->patientFormWidget->setWindowTitle(windowTitle);
    PatientFormChangeDecorator::connect(patientFormWidget->ui->acceptButton, SIGNAL(clicked()), this, SLOT(accept()));
    PatientFormChangeDecorator::connect(patientFormWidget->ui->discardButton, SIGNAL(clicked()), this, SLOT(discard()));
}

PatientFormChangeDecorator::~PatientFormChangeDecorator()
{
    delete &patientFormWidget->selectionIndexes;
    delete patientFormWidget->ui;
}

void PatientFormChangeDecorator::show()
{
    patientFormWidget->show();
}

QVariantList PatientFormChangeDecorator::getFormData()
{
    QVariantList formData;
    const QVariant titel = QVariant(patientFormWidget->ui->titelLineEdit->text());
    const QVariant firstName = QVariant(patientFormWidget->ui->firstNameLineEdit->text());
    const QVariant lastName = QVariant(patientFormWidget->ui->nameLineEdit->text());
    const QVariant birthDate = QVariant(patientFormWidget->ui->birthDateDateEdit->date());
    const QVariant street = QVariant(patientFormWidget->ui->streetLineEdit->text());
    const QVariant houseNumber = QVariant(patientFormWidget->ui->houseNumberLineEdit->text());
    const QVariant plz = QVariant(patientFormWidget->ui->pLZLineEdit->text());
    const QVariant location = QVariant(patientFormWidget->ui->placeLineEdit->text());
    const QVariant phoneNumber = QVariant(patientFormWidget->ui->phoneNumberLineEdit->text());
    const QVariant gender = QVariant(patientFormWidget->ui->genderComboBox->currentText());
    formData << titel << firstName << lastName << birthDate << street
             << houseNumber << plz << location << phoneNumber << gender;
    return formData;
}

void PatientFormChangeDecorator::accept()
{
   QVariantList formData = getFormData();
   patientFormWidget->patientTableModel->setRowData(patientFormWidget->selectionIndexes, formData);
   patientFormWidget->close();
}

void PatientFormChangeDecorator::discard()
{
    patientFormWidget->close();
}
