#include "view/header/changepatientwidget.h"
#include "model/header/patienttablemodel.h"
#include "ui_patientformwidget.h"

ChangePatientWidget::ChangePatientWidget(QWidget *parent, PatientTableModel *patientTableModel, const QModelIndexList &indexes) : PatientFormWidget(parent, patientTableModel, indexes)
{
    this->setWindowTitle("Patientendaten ändern");
    connect(ui->acceptButton, SIGNAL(clicked()), this, SLOT(accept()));
    connect(ui->discardButton, SIGNAL(clicked()), this, SLOT(discard()));
}

ChangePatientWidget::~ChangePatientWidget()
{
    delete ui;
}

bool ChangePatientWidget::verify()
{

   return false;
}

void ChangePatientWidget::accept()
{
   QVariantList formData = getFormData();
   patientTableModel->setRowData(indexes, formData);
}

void ChangePatientWidget::discard()
{
    this->close();
}
