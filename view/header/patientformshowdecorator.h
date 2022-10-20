#ifndef PATIENTFORMSHOWDECORATOR_H
#define PATIENTFORMSHOWDECORATOR_H


#include "view/header/patientformwidget.h"

class PatientFormShowDecorator
{
public:
    PatientFormShowDecorator(PatientFormWidget *patientFormWidget);
    ~PatientFormShowDecorator();
    void show();

private:
    PatientFormWidget *patientFormWidget;
    void adjustUi();
    void setEditable(bool editable);
};

#endif // PATIENTFORMSHOWDECORATOR_H
