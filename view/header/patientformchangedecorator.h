/**
 *  Declaration of the PatientFormChangeDecorator, decorates @see PatientFormWidget.
 */


#ifndef PATIENTFORMCHANGEDECORATOR_H
#define PATIENTFORMCHANGEDECORATOR_H

#include "view/header/patientformwidget.h"

class PatientFormChangeDecorator: public QObject
{
    Q_OBJECT

public slots:

    /**
     * Discards the current changes and closes the window.
     */
    void discard();

    /**
     * Accepts the current changes by changing the data of the selected patient.
     */
    void accept();

public:

    /**
     * Constructs a new PatientFormChangeDecorator object.
     *
     * @param patientFormWidget PatientFormWidget to decorate.
     * @param windowTitle Title of the window.
     */
    PatientFormChangeDecorator(PatientFormWidget *patientFormWidget, QString windowTitle);

    /**
     * Destructs the PatientFormChangeDecorator by destructing the {@link #patientFormWidget}.
     */
    ~PatientFormChangeDecorator();

    /**
     * Displays {@link #patientFormWidget}.
     */
    void show();

private:

    /// Decorated @see PatientFormWidet object.
    PatientFormWidget *patientFormWidget;

    /// Returns the current form data as a QVariantList.
    QVariantList getFormData();
};

#endif // PATIENTFORMCHANGEDECORATOR_H
