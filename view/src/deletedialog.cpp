#include "view/header/deletedialog.h"
#include "ui_deletedialog.h"

DeleteDialog::DeleteDialog(QWidget *parent, PatientTableModel *patientTableModel, const QModelIndexList &selectionIndexes) :
    QWidget(parent),
    ui(new Ui::DeleteDialog),
    patientTableModel(patientTableModel),
    selectionIndexes(selectionIndexes)
{
    ui->setupUi(this);
    this->setWindowTitle("Patient löschen");
    connect(ui->deleteButton, SIGNAL(clicked()), this, SLOT(confirm()));
    connect(ui->cancelButton, SIGNAL(clicked()), this, SLOT(cancel()));
}

DeleteDialog::~DeleteDialog()
{
    delete &selectionIndexes;
    delete ui;
}

void DeleteDialog::confirm()
{
    patientTableModel->removeRow(selectionIndexes.first().row());
    this->close();
}

void DeleteDialog::cancel()
{
    this->close();
}
