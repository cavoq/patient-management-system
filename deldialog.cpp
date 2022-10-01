#include "deldialog.h"
#include "ui_deldialog.h"

delDialog::delDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::delDialog)
{
    ui->setupUi(this);
}

delDialog::~delDialog()
{
    delete ui;
}
