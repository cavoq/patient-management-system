#include "view/header/patientformwidget.h"
#include "model/header/patienttablemodel.h"
#include "ui_patientformwidget.h"

PatientFormWidget::PatientFormWidget(QWidget *parent, PatientTableModel *patientTableModel) :
    QWidget(parent),
    ui(new Ui::PatientFormWidget),
    patientTableModel(patientTableModel)
{
    ui->setupUi(this);
    const QStringList genders {"Mann", "Frau", "Divers"};
    ui->genderComboBox->addItems(genders);
    connect(ui->acceptButton, SIGNAL(clicked()), this, SLOT(verify()));
    connect(ui->discardButton, SIGNAL(clicked()), this, SLOT(discard()));
}

PatientFormWidget::~PatientFormWidget()
{
    delete ui;
}

bool PatientFormWidget::verify()
{
   return false;
}

void PatientFormWidget::accept() {

}

void PatientFormWidget::discard()
{
    this->close();
}
