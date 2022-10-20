#include "view/header/patientformwidget.h"
#include "model/header/patienttablemodel.h"
#include "ui_patientformwidget.h"
#include <ostream>

PatientFormWidget::PatientFormWidget(QWidget *parent, PatientTableModel *patientTableModel, const QModelIndexList &selectionIndexes) :
    QWidget(parent),
    ui(new Ui::PatientFormWidget),
    patientTableModel(patientTableModel),
    selectionIndexes(selectionIndexes)
{
    ui->setupUi(this);
    const QStringList genders {"Mann", "Frau", "Divers"};
    ui->genderComboBox->addItems(genders);
    setFormData();
}

PatientFormWidget::~PatientFormWidget()
{
    delete &selectionIndexes;
    delete ui;
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
        const QString value = patientTableModel->data(selectionIndexes.at(column)).toString();
        lineEdits[column]->setText(value);
        column += 1;
    }
    const QDate birthDate = QDate::fromString(patientTableModel->data(selectionIndexes.at(patientTableModel->GEBURTSDATUM)).toString(), "dd.MM.yyyy");
    ui->birthDateDateEdit->setDate(birthDate);
    const QString gender = patientTableModel->data(selectionIndexes.at(patientTableModel->GESCHLECHT)).toString();
    ui->genderComboBox->setCurrentText(gender);
}
