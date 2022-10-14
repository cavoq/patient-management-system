#ifndef PATIENTFORMWIDGET_H
#define PATIENTFORMWIDGET_H

#include "model/header/patienttablemodel.h"
#include <QWidget>

namespace Ui {
class PatientFormWidget;
}

class PatientFormWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PatientFormWidget(QWidget *parent = nullptr, PatientTableModel *patientTableModel = nullptr, const QModelIndexList &indexes = QModelIndexList());
    ~PatientFormWidget();
    Ui::PatientFormWidget *ui;
    PatientTableModel *patientTableModel;
    const QModelIndexList &indexes;
    QVariantList getFormData();
    void setFormData();
};

#endif // PATIENTFORMWIDGET_H
