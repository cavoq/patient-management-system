/**
 *  Declaration of the DeleteDialog, which is responsible for deleting patients from the table.
 */


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

    /**
     * Construct a new DeleteDialog object.
     *
     * @param parent Parent widget.
     * @param patientTableModel @see PatientTableModel of the table.
     * @param selectionIndexes Indexes of the selected row.
     */
    explicit DeleteDialog(QWidget *parent = nullptr, PatientTableModel *patientTableModel = nullptr, const QModelIndexList &selectionIndexes = QModelIndexList());

    /**
     * Destructs the DeleteDialog.
     */
    ~DeleteDialog();

public slots:

    /**
     * Confirms the deletion and deletes the selected row.
     */
    void confirm();

    /**
     * Cancels the deletion and closes the window.
     */
    void cancel();

private:

    /// User interface object of the DeleteDialog.
    Ui::DeleteDialog *ui;

    /// Table model of the correspondng row.
    PatientTableModel *patientTableModel;

    /// Corresponding indexes of the selected row.
    const QModelIndexList &selectionIndexes;
};

#endif // DELETEDIALOG_H
