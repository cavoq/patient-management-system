#include "view/header/changepatientwidget.h"
#include "ui_patientformwidget.h"
#include "view/header/patientformwidget.h"
#include "model/header/patienttablemodel.h"

ChangePatientWidget::ChangePatientWidget(QWidget *parent, PatientTableModel *patientTableModel, const QModelIndexList &selectionIndexes) :
    PatientFormWidget(parent, patientTableModel, selectionIndexes)
{
    this->setWindowTitle("Patientendaten ändern");
    connect(ui->acceptButton, SIGNAL(clicked()), this, SLOT(accept()));
    connect(ui->discardButton, SIGNAL(clicked()), this, SLOT(discard()));
    setFormData();
}

ChangePatientWidget::~ChangePatientWidget()
{
    delete &selectionIndexes;
    delete ui;
}

bool ChangePatientWidget::verify()
{
   return false;
}

void ChangePatientWidget::accept()
{
   QVariantList formData = getFormData();
   patientTableModel->setRowData(selectionIndexes, formData);
   this->close();
}

void ChangePatientWidget::discard()
{
    this->close();
}
