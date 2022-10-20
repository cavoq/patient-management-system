#include "view/header/patientformshowdecorator.h"
#include "ui_patientformwidget.h"
#include "view/header/patientformwidget.h"

PatientFormShowDecorator::PatientFormShowDecorator(PatientFormWidget *patientFormWidget)
{
    this->patientFormWidget = patientFormWidget;
    this->patientFormWidget->setWindowTitle("Patientendaten ansehen");
    adjustUi();
    setEditable(false);
}


PatientFormShowDecorator::~PatientFormShowDecorator()
{
    delete &patientFormWidget->selectionIndexes;
    delete patientFormWidget->ui;
}

void PatientFormShowDecorator::show()
{
    patientFormWidget->show();
}

void PatientFormShowDecorator::adjustUi()
{
    patientFormWidget->ui->acceptButton->hide();
    patientFormWidget->ui->discardButton->hide();
    patientFormWidget->adjustSize();
}

void PatientFormShowDecorator::setEditable(bool editable)
{
    const QList<QLineEdit*> lineEdits = patientFormWidget->ui->formLayoutWidget->findChildren<QLineEdit*>();
    for (QLineEdit *lineEdit: lineEdits) {
        lineEdit->setReadOnly(!editable);
    }
    patientFormWidget->ui->birthDateDateEdit->setReadOnly(!editable);
    const QString &gender = patientFormWidget->ui->genderComboBox->currentText();
    patientFormWidget->ui->genderComboBox->clear();
    patientFormWidget->ui->genderComboBox->addItem(gender);
    patientFormWidget->ui->genderComboBox->setCurrentText(gender);
}
