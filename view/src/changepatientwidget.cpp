#include "view/header/changepatientwidget.h"
#include "ui_changepatientwidget.h"

ChangePatientWidget::ChangePatientWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChangePatientWidget)
{
    ui->setupUi(this);
}

ChangePatientWidget::~ChangePatientWidget()
{
    delete ui;
}
