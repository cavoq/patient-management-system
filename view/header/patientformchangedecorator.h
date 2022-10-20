#ifndef PATIENTFORMCHANGEDECORATOR_H
#define PATIENTFORMCHANGEDECORATOR_H


#include "view/header/patientformwidget.h"

class PatientFormChangeDecorator: public QObject
{
    Q_OBJECT

public slots:
    void discard();
    void accept();

public:
    PatientFormChangeDecorator(PatientFormWidget *patientFormWidget, QString windowTitle);
    ~PatientFormChangeDecorator();
    void show();

private:
    PatientFormWidget *patientFormWidget;
    QVariantList getFormData();
};

#endif // PATIENTFORMCHANGEDECORATOR_H
