#include "model/header/patienttablemodel.h"
#include <iostream>

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
            case 4:
                return tr("Straße");
            case 5:
                return tr("Hausnummer");
            case 6:
                return tr("PLZ");
            case 7:
                return tr("Ort");
            case 8:
                return tr("Telefonnummer");
            case 9:
                return tr("Geschlecht");
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
                return patient.name.firstName;
            case 2:
                return patient.name.lastName;
            case 3:
                return patient.birthDate.toString("dd.MM.yyyy");
            case 4:
                return patient.address.street;
            case 5:
                return patient.address.houseNumber;
            case 6:
                return patient.address.plz;
            case 7:
                return patient.address.location;
            case 8:
                return patient.phoneNumber;
            case 9:
                return patient.gender;
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
                patient.name.firstName = value.toString();
                break;
            case 2:
                patient.name.lastName = value.toString();
                break;
            case 3:
                patient.birthDate = value.toDate();
                break;
            case 4:
                patient.address.street = value.toString();
                break;
            case 5:
                patient.address.houseNumber = value.toString();
                break;
            case 6:
                patient.address.plz = value.toInt();
                break;
            case 7:
                patient.address.location = value.toString();
                break;
            case 8:
                patient.phoneNumber = value.toString();
                break;
            case 9:
                patient.gender = value.toString();
                break;
            default:
                return false;
        }
        this->patients.replace(row, patient);
        emit dataChanged(index, index, {Qt::DisplayRole, Qt::EditRole});

        return true;
    }

    return false;
}

bool PatientTableModel::setRowData(const QModelIndexList &indexes, const QVariantList &values, int role)
{
    if (indexes.count() != values.count()) {
        return false;
    }

    for (int i = 0; i < values.count(); ++i) {
        if (!setData(indexes[i], values[i], role)) {
            return false;
        }
    }
    return true;
}

const QList<Patient>& PatientTableModel::getPatients() const
{
    return this->patients;
}

const QList<Patient> PatientTableModel::getPatients(QModelIndexList &selection) const
{
    QList<Patient> selectedPatients = QList<Patient>();
    for (QModelIndex select: selection) {
        int rowPosition = select.row();
        selectedPatients.append(this->patients.at(rowPosition));
    }
    return selectedPatients;
}
