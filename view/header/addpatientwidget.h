#ifndef ADDPATIENTWIDGET_H
#define ADDPATIENTWIDGET_H

#include <QWidget>
#include "view/header/patientformwidget.h"

namespace Ui {
class AddPatientWidget;
}

class AddPatientWidget : public PatientFormWidget
{
    Q_OBJECT

public:
    explicit AddPatientWidget(QWidget *parent = nullptr);
    ~AddPatientWidget();
};

#endif // ADDPATIENTWIDGET_H
