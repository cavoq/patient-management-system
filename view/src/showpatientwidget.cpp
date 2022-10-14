#include "view/header/showpatientwidget.h"
#include "ui_patientformwidget.h"

ShowPatientWidget::ShowPatientWidget(QWidget *parent, PatientTableModel *patientTableModel, const QModelIndexList &indexes) : PatientFormWidget(parent, patientTableModel, indexes)
{
   this->setWindowTitle("Patientendaten ansehen");
   ui->acceptButton->hide();
   ui->discardButton->hide();
   setFormData();
}

ShowPatientWidget::~ShowPatientWidget()
{
    delete ui;
}
