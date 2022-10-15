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
}

ShowPatientWidget::~ShowPatientWidget()
{
    delete &selectionIndexes;
    delete ui;
}
