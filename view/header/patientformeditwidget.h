#ifndef PATIENTFORMEDITWIDGET_H
#define PATIENTFORMEDITWIDGET_H


#include "model/header/patienttablemodel.h"
namespace Ui {
class PatientFormEditWidget;
}

class PatienFormEditWidget : public PatientFormWidget
{
    Q_OBJECT

public slots:
    void discard();
    void accept();
    bool verify();

public:
    explicit PatienFormEditWidget(QWidget *parent = nullptr, PatientTableModel *patientTableModel = nullptr);
    ~PatientFormEditWidget();};

#endif // PATIENTFORMEDITWIDGET_H
