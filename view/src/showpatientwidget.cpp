#include "view/header/showpatientwidget.h"
#include "ui_patientformwidget.h"

ShowPatientWidget::ShowPatientWidget(QWidget *parent, PatientTableModel *patientTableModel, const QModelIndexList &selectionIndexes) :
    PatientFormWidget(parent, patientTableModel, selectionIndexes)
{
   this->setWindowTitle("Patientendaten ansehen");
   ui->acceptButton->hide();
   ui->discardButton->hide();
   this->adjustSize();
   setFormData();
   setEditable(false);
}

ShowPatientWidget::~ShowPatientWidget()
{
    delete &selectionIndexes;
    delete ui;
}

void ShowPatientWidget::setEditable(bool editable)
{
    const QList<QLineEdit*> lineEdits = ui->formLayoutWidget->findChildren<QLineEdit*>();
    for (QLineEdit *lineEdit: lineEdits) {
        lineEdit->setReadOnly(!editable);
    }
    ui->birthDateDateEdit->setReadOnly(!editable);
    const QString &gender = ui->genderComboBox->currentText();
    ui->genderComboBox->clear();
    ui->genderComboBox->addItem(gender);
    ui->genderComboBox->setCurrentText(gender);
}
