#ifndef PATIENTMODEL_H
#define PATIENTMODEL_H

#include <QAbstractTableModel>

#include "model/header/patient.h"

class PatientModel : public QAbstractTableModel
{
    Q_OBJECT

private:
    QList<Patient> patients;
    const unsigned int column_count = 4;

public:
    explicit PatientModel(const QList<Patient>& patients, QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
};

#endif // PATIENTMODEL_H
