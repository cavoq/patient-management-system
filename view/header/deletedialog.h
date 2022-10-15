#ifndef DELETEDIALOG_H
#define DELETEDIALOG_H

#include "model/header/patienttablemodel.h"
#include <QWidget>

namespace Ui {
class DeleteDialog;
}

class DeleteDialog : public QWidget
{
    Q_OBJECT

public:
    explicit DeleteDialog(QWidget *parent = nullptr, PatientTableModel *patientTableModel = nullptr, const QModelIndexList &selectionIndexes = QModelIndexList());
    ~DeleteDialog();

public slots:
    void confirm();
    void cancel();

private:
    Ui::DeleteDialog *ui;
    PatientTableModel *patientTableModel;
    const QModelIndexList &selectionIndexes;
};

#endif // DELETEDIALOG_H
