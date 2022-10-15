#include "view/header/patientformwidget.h"
#include "model/header/patienttablemodel.h"
#include "ui_patientformwidget.h"
#include <iostream>
#include <ostream>

PatientFormWidget::PatientFormWidget(QWidget *parent, PatientTableModel *patientTableModel, const QModelIndexList &indexes):
    QWidget(parent),
    ui(new Ui::PatientFormWidget),
    patientTableModel(patientTableModel),
    indexes(indexes)
{
    ui->setupUi(this);
    const QStringList genders {"Mann", "Frau", "Divers"};
    ui->genderComboBox->addItems(genders);
}

PatientFormWidget::~PatientFormWidget()
{
    delete ui;
}

QVariantList PatientFormWidget::getFormData()
{
    QVariantList formData;
    const QVariant titel = QVariant(ui->titelLineEdit->text());
    const QVariant firstName = QVariant(ui->firstNameLineEdit->text());
    const QVariant lastName = QVariant(ui->firstNameLineEdit->text());
    const QVariant birthDate = QVariant(ui->birthDateDateEdit->date());
    const QVariant street = QVariant(ui->streetLineEdit->text());
    const QVariant houseNumber = QVariant(ui->houseNumberLineEdit->text());
    const QVariant plz = QVariant(ui->pLZLineEdit->text());
    const QVariant location = QVariant(ui->placeLineEdit->text());
    const QVariant phoneNumber = QVariant(ui->phoneNumberLineEdit->text());
    const QVariant gender = QVariant(ui->genderComboBox->currentText());
    formData << titel << firstName << lastName << birthDate << street
             << houseNumber << plz << location << phoneNumber << gender;
    std::cout << formData.first().toString().toStdString() << std::endl;
    return formData;
}

void PatientFormWidget::setFormData()
{
    const QList<QLineEdit*> lineEdits = ui->formLayoutWidget->findChildren<QLineEdit*>();
    int column = patientTableModel->TITEL;
    while (column < lineEdits.count()) {
        if (column == patientTableModel->GEBURTSDATUM) {
            column += 1;
            continue;
        }
        const QString value = patientTableModel->data(indexes.at(column)).toString();
        lineEdits[column]->setText(value);
        column += 1;
    }
    const QDate birthDate = QDate::fromString(patientTableModel->data(indexes.at(patientTableModel->GEBURTSDATUM)).toString(), "dd.MM.yyyy");
    ui->birthDateDateEdit->setDate(birthDate);
    const QString gender = patientTableModel->data(indexes.at(patientTableModel->GESCHLECHT)).toString();
    ui->genderComboBox->setCurrentText(gender);
}
