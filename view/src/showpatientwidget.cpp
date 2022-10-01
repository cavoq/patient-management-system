#include "view/header/showpatientwidget.h"
#include "ui_showpatientwidget.h"

ShowPatientWidget::ShowPatientWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShowPatientWidget)
{
    ui->setupUi(this);
}

ShowPatientWidget::~ShowPatientWidget()
{
    delete ui;
}
