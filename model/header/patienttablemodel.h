#ifndef PATIENTTABLEMODEL_H
#define PATIENTTABLEMODEL_H

#include <QAbstractTableModel>

#include "model/header/patient.h"

class PatientTableModel : public QAbstractTableModel
{
    Q_OBJECT

private:
    QList<Patient> patients;
    const unsigned int column_count = 10;

public:
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
    explicit PatientTableModel(const QList<Patient>& patients, QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    bool removeRows(int position, int rows, const QModelIndex &index = QModelIndex()) override;
    bool insertRows(int position, int rows, const QModelIndex &index = QModelIndex()) override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    const QList<Patient>& getPatients() const;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
};

#endif // PATIENTTABLEMODEL_H
