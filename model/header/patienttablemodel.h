/**
 *  Declaration of PatientTableModel, a @see QAbstractTableModel used by
 *  a @see QTableView.
 */


#ifndef PATIENTTABLEMODEL_H
#define PATIENTTABLEMODEL_H

#include <QAbstractTableModel>

#include "model/header/patient.h"

class PatientTableModel : public QAbstractTableModel
{
    Q_OBJECT

public:

    /**
     * The columnIdentifier enum, that maps the attributes of a patient
     * to the corresponding table model indexes.
     */
    enum columnIdentifier {
        TITEL,
        VORNAME,
        NACHNAME,
        GEBURTSDATUM,
        STRASSE,
        HAUSNUMMER,
        PLZ,
        ORT,
        TELEFONNUMMER,
        GESCHLECHT
    };

    /**
     * Constructs a new PatientTableModel object.
     *
     * @param patients List of patients that the model uses.
     * @param parent Parent object @see QObject.
     */
    explicit PatientTableModel(const QList<Patient>& patients, QObject *parent = nullptr);

    /**
     * Returns the corresponding header data for a section.
     *
     * @param section Section index.
     * @param orientation Orientation of the table.
     * @param role Role of the variant.
     * @return Returns the data as a QVariant object.
     */
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    /**
     * Get the row count of the table model.
     *
     * @param parent QModelIndex of the parent object.
     * @return Returns the row count of the table model.
     */
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    /**
     * Get the column count of the table model.
     *
     * @param parent QModelIndex of the parent object.
     * @return Returns the column count of the table model.
     */
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    /**
     * Get the model indexes of a row.
     *
     * @param row Index of row.
     * @return Returns all corresponding model indexes of the row as a QModelIndexList.
     */
    QModelIndexList indexes(const int row);

    /**
     * Sets the data of a row.
     *
     * @param indexes Corresponding model indexes of the row.
     * @param values Corresponding values the model indexes will be set to.
     * @param role Role of the model indexes in the row.
     * @return Returns true if size of the indexes and values have the same size
     * and the row data was set successfully.
     */
    bool setRowData(const QModelIndexList &indexes, const QVariantList &values, int role = Qt::EditRole);

    /**
     * Inserts new empty rows.
     *
     * @param postion Index where the rows will be inserted.
     * @param rows Number of rows to be inserted.
     * @param index Unused parameter (needed for overriding).
     * @return Returns true if inserting was successful.
     */
    bool insertRows(int position, int rows, const QModelIndex &index = QModelIndex()) override;

    /**
     * Remove rows.
     *
     * @param postion Index where the rows will be removed from.
     * @param rows Number of rows to be removed.
     * @param index Unused parameter (needed for overriding).
     * @return Returns true if removing was successful.
     */
    bool removeRows(int position, int rows, const QModelIndex &index = QModelIndex()) override;

    /**
     * Get the patients of the table model.
     *
     * @return Returns the patients of the table model as a list.
     */
    const QList<Patient>& getPatients() const;

    /**
     *  Get the patients of the table model.
     *
     * @param   selection Selected rows the patients should be returned from.
     * @return  Returns the corresponding patients of the rows in the table model as a list.
     */
    const QList<Patient> getPatients(QModelIndexList &selection) const;

    /**
     *  Returns data of the table model.
     *
     * @param   index QModelIndex data will be returned from.
     * @param   role Role of the data.
     * @return  Returns the data as a QVariant.
     */
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:

    /// List of patients for the table model.
    QList<Patient> patients;

    /// Column count of the table model.
    const unsigned int column_count = 10;

    /**
     * Sets the data of a single entry of the table model.
     *
     * @param index QModelIndex of the entry.
     * @param value QVariant containing the data.
     * @param role  Role of the entry.
     * @return Returns true if the index exists and the entry could be set to th data.
     */
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

};

#endif // PATIENTTABLEMODEL_H
