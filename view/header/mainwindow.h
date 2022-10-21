/**
 *  Declaration of the MainWindow, is responsible for everything that happens in the
 *  MainWindow of the application.
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "model/header/patienttablemodel.h"
#include "header/multicolumnfilterproxymodel.h"
#include "header/patientjsonreader.h"
#include "header/patientjsonwriter.h"
#include "view/header/patientformwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:

    /**
     * Opens the widget for adding new patients into the {@link #patienTableModel}.
     */
    void openAddPatientWidget();

    /**
     * Opens the widget for changing an existing patient in the {@link #patienTableModel}.
     */
    void openChangePatientWidget();

    /**
     * Opens the widget for displaying an existing patient in the {@link #patienTableModel}.
     */
    void openShowPatientWidget();

    /**
     * Opens the dialog for deleting an existing patient in the {@link #patienTableModel}.
     */
    void openDeletePatientDialog();

    /**
     * Cnacel the selection in the {@link #patienTableModel} and clears the search fields.
     */
    void cancelSelection();

    /**
     * Opens a file dialog for exporting selected patients.
     */
    void exportPatients();

public:

    /**
     * Constructs a new MainWindow object.
     *
     * @param parent Parent widget.
     */
    MainWindow(QWidget *parent = nullptr);

    /**
     * Destructs the MainWindow object.
     */
    ~MainWindow();

private:

    /// Instance of @see PatientJsonReader.
    PatientJsonReader *patientJsonReader = new PatientJsonReader();

    /// Instance of @see PatientJsonWriter.
    PatientJsonWriter *patientJsonWriter = new PatientJsonWriter();

    /// Instance of @see MultiColumnFilterModel.
    MultiColumnFilterProxyModel *filterProxyModel = new MultiColumnFilterProxyModel();

    /// Instance of @see PatientTableModel.
    PatientTableModel *patientTableModel;

    /**
     * Construct a new PatientFormWidget using the selected row.
     * @return Returns a new PatientFormWidget using the currently
     * selected row.
     */
    PatientFormWidget *getPatientFormWidget();

    /// User interface object for the MainWindow.
    Ui::MainWindow *ui;

    /**
     * Loads the patients into the table model, by reading them from
     * the json file and passing them to {@link #patienTableModel}.
     */
    void loadPatients();

    /**
     * Connects the signals of the application to their corresponding slots.
     */
    void connectSignals();

    /**
     * Hides columns that should not be displayed.
     * Only the titel, first name, name and birth date of
     * a patient will appear in the table view.
     */
    void hideColumns();

    /**
     * Displayes a message to the user.
     *
     * @param title The title of the message window.
     * @param text The message for the user.
     */
    void showMessage(const QString &title, const QString &text);

    /**
     * Check if the table selection is valid.
     *
     * @return Returns true, if only one patient is selected.
     */
    bool checkSelection();

    /**
     * Gets a file from a dialog with the file system.
     *
     * @return Returns the name of the selected file from the dialog.
     */
    QString getFileFromDialog();
};
#endif // MAINWINDOW_H
