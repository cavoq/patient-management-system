#include "model/header/patienttablemodel.h"

PatientTableModel::PatientTableModel(const QList<Patient>& patients, QObject *parent)
    : QAbstractTableModel(parent), patients(patients)
{
}

QVariant PatientTableModel::headerData(int section, Qt::Orientation orientation, int role) const
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

int PatientTableModel::rowCount(const QModelIndex &parent) const
{
    return parent.isValid() ? 0 : this->patients.size();
}

int PatientTableModel::columnCount(const QModelIndex &parent) const
{
    return parent.isValid() ? 0 : this->column_count;
}

QVariant PatientTableModel::data(const QModelIndex &index, int role) const
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
                return patient.birth_date.toString("dd.MM.yyyy");
            default:
                break;
        }
    }
    return QVariant();
}

bool PatientTableModel::insertRows(int position, int rows, const QModelIndex &index)
{
    Q_UNUSED(index);
    beginInsertRows(QModelIndex(), position, position + rows - 1);

    for (int row = 0; row < rows; ++row)
        this->patients.insert(position, Patient());

    endInsertRows();
    return true;
}

bool PatientTableModel::removeRows(int position, int rows, const QModelIndex &index)
{
    Q_UNUSED(index);
    beginRemoveRows(QModelIndex(), position, position + rows - 1);

    for (int row = 0; row < rows; ++row)
        this->patients.removeAt(position);

    endRemoveRows();
    return true;
}

bool PatientTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole) {
        const int row = index.row();
        auto patient = this->patients.value(row);

        switch (index.column()) {
            case 0:
                patient.titel = value.toString();
                break;
            case 1:
                patient.name.first_name = value.toString();
                break;
            case 2:
                patient.name.last_name = value.toString();
                break;
            case 3:
                patient.birth_date = value.toDate();
            default:
                return false;
        }
        this->patients.replace(row, patient);
        emit dataChanged(index, index, {Qt::DisplayRole, Qt::EditRole});

        return true;
    }

    return false;
}

const QList<Patient>& PatientTableModel::getPatients() const
{
    return this->patients;
}
