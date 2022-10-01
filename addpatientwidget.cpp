#include "addpatientwidget.h"
#include "ui_addpatientwidget.h"

AddPatientWidget::AddPatientWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddPatientWidget)
{
    ui->setupUi(this);
}

AddPatientWidget::~AddPatientWidget()
{
    delete ui;
}
