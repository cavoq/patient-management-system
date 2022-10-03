#include "model/header/patientmodel.h"

PatientModel::PatientModel(const QList<Patient>& patients, QObject *parent)
    : QAbstractTableModel(parent), patients(patients)
{
}

QVariant PatientModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
            return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
            case 0:
                return tr("Titel");
            case 1:
                return tr("Vorname");
            case 2:
                return tr("Nachname");
            case 3:
                return tr("Geburtsdatum");
            default:
                break;
        }
    }
    return QVariant();
}

int PatientModel::rowCount(const QModelIndex &parent) const
{
    return parent.isValid() ? 0 : this->patients.size();
}

int PatientModel::columnCount(const QModelIndex &parent) const
{
    return parent.isValid() ? 0 : this->column_count;
}

QVariant PatientModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >= this->patients.size() || index.row() < 0)
        return QVariant();

    if (role == Qt::DisplayRole) {
        const auto &patient = this->patients.at(index.row());
        switch (index.column()) {
            case 0:
                return patient.titel;
            case 1:
                return patient.name.first_name;
            case 2:
                return patient.name.last_name;
            case 3:
                return patient.birth_date;
            default:
                break;
        }
    }
    return QVariant();
}
