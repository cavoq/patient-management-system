/**
 *  Declaration of the PatientFormShowDecorator, decorates @see PatientFormWidget.
 */


#ifndef PATIENTFORMSHOWDECORATOR_H
#define PATIENTFORMSHOWDECORATOR_H


#include "view/header/patientformwidget.h"

class PatientFormShowDecorator
{
public:

    /**
     * Constructs a new PatientFormShowDecorator object.
     *
     * @param patientFormWidget PatientFormWidget to decorate.
     */
    PatientFormShowDecorator(PatientFormWidget *patientFormWidget);

    /**
     * Destructs the PatientFormChangeDecorator by destructing the {@link #patientFormWidget}.
     */
    ~PatientFormShowDecorator();

    /**
     * Displays {@link #patientFormWidget}.
     */
    void show();

private:

    /// Decorated @see PatientFormWidet object.
    PatientFormWidget *patientFormWidget;

    /**
     * Adjusts the user interface by removing the buttons in the {@link #patientFormWidget}
     * and resizing the window accordingly.
     */
    void adjustUi();

    /**
     * Sets the editability of the {@link #patientFormWidget}.
     *
     * @param editable Set to false, if the user should not be able
     * to edit data in the window.
     */
    void setEditable(bool editable);
};

#endif // PATIENTFORMSHOWDECORATOR_H
