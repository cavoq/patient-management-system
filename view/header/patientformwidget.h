/**
 *  Declaration of the PatientFormWidget, a form widget that displays data of a patient in a form.
 */


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

    /**
     * Constructs a new PatientFormWidget object.
     *
     * @param parent Parent widget.
     * @param patientTableModel PatientTableModel that will be used.
     * @param selectionIndexes Corresponding indexes of the selected row.
     */
    explicit PatientFormWidget(QWidget *parent = nullptr, PatientTableModel *patientTableModel = nullptr, const QModelIndexList &selectionIndexes = QModelIndexList());

    /**
     * Destructs the PatientFormWidget.
     */
    ~PatientFormWidget();

    /// User interface object of the PatientFormWidget.
    Ui::PatientFormWidget *ui;

    /// Instance of the @see PatienTableModel.
    PatientTableModel *patientTableModel;

    /// Corresponding indexes of the selected row.
    const QModelIndexList &selectionIndexes;

    /**
     * Sets the form data of the widget to the data of the selected row.
     */
    void setFormData();
};

#endif // PATIENTFORMWIDGET_H
