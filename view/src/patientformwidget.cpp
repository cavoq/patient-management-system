#include "view/header/patientformwidget.h"
#include "ui_patientformwidget.h"

PatientFormWidget::PatientFormWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PatientFormWidget)
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

void PatientFormWidget::discard()
{
    this->close();
}
