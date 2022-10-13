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

public slots:
    void discard();
    void accept();
    bool verify();

public:
    explicit PatientFormWidget(QWidget *parent = nullptr, PatientTableModel *patientTableModel = nullptr);
    ~PatientFormWidget();
    Ui::PatientFormWidget *ui;
    PatientTableModel *patientTableModel;
};

#endif // PATIENTFORMWIDGET_H
