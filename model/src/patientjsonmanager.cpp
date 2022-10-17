#include "model/header/patientjsonmanager.h"
#include <QtCore>
#include <iostream>
#include <QIODevice>

PatientJsonManager::PatientJsonManager() {}

bool PatientJsonManager::writeToJson(QString jsonFile, const QList<Patient>& patients)
{
    QJsonObject jsonPatients;
    QJsonDocument document;
    int patientIndex = 0;
    for (const Patient& patient: patients) {
        std::string patientIndexAsString = std::to_string(patientIndex);
        QJsonObject jsonPatient;
        if (!writePatient(jsonPatient, patient)) {
            return false;
        }
        jsonPatients.insert(QString::fromStdString(patientIndexAsString), jsonPatient);
        patientIndex += 1;
    }
    document.setObject(jsonPatients);
    QByteArray bytes = document.toJson(QJsonDocument::Indented);
    QFile file(jsonFile);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        file.write(bytes);
        file.close();
        return true;
     }
     else {
        return false;
     }
}

bool PatientJsonManager::writePatient(QJsonObject &jsonPatient, const Patient &patient)
{
    QJsonObject jsonAddress;
    QJsonObject jsonName;
    if (!writeName(jsonName, patient.name) || !writeAddress(jsonAddress, patient.address)) {
        return false;
    }
    jsonPatient.insert("titel", patient.titel);
    jsonPatient.insert("name", jsonName);
    jsonPatient.insert("address", jsonAddress);
    jsonPatient.insert("phone number", patient.phoneNumber);
    jsonPatient.insert("birth date", patient.birthDate.toString("dd.MM.yyyy"));
    jsonPatient.insert("gender", patient.gender);
    return true;
}

bool PatientJsonManager::writeAddress(QJsonObject &jsonAddress, const Address &address)
{
    jsonAddress.insert("street", address.street);
    jsonAddress.insert("house number", address.houseNumber);
    jsonAddress.insert("plz", address.plz);
    jsonAddress.insert("location", address.location);
    return true;
}

bool PatientJsonManager::writeName(QJsonObject &jsonName, const Name &name)
{
    jsonName.insert("first name", name.firstName);
    jsonName.insert("last name", name.lastName);
    return true;
}

QList<Patient> PatientJsonManager::readFromJson(QString jsonFile)
{
    QList<Patient> patients = QList<Patient>();
    QFile file(jsonFile);
    if (file.open(QIODevice::ReadOnly)) {
        QByteArray bytes = file.readAll();
        file.close();

        QJsonParseError jsonError;
        QJsonDocument document = QJsonDocument::fromJson(bytes, &jsonError);
            if (jsonError.error != QJsonParseError::NoError) {
                throw jsonError.error;
            }
            if (document.isObject()) {
                QJsonObject json = document.object();
                for (auto patientIndex: json) {
                    if (patientIndex.isObject()) {
                        QJsonObject jsonPatient = patientIndex.toObject();
                        Patient patient = readPatient(jsonPatient);
                        patients.push_back(patient);
                    }
                }
            }
        }
    return patients;
}

Patient PatientJsonManager::readPatient(QJsonObject &jsonPatient)
{
    Address address;
    Name name;
    QString titel = jsonPatient.value("titel").toString();
    QDate birthDate = QDate::fromString(jsonPatient.value("birth date").toString(), "dd.MM.yyyy");
    QString gender = jsonPatient.value("gender").toString();
    QString phoneNumber = jsonPatient.value("phone number").toString();
    QJsonValue addressVal = jsonPatient.value("address");
    if (addressVal.isObject()) {
        QJsonObject jsonAddress = addressVal.toObject();
        address = this->readAddress(jsonAddress);
    }
    QJsonValue nameVal = jsonPatient.value("name");
    if (nameVal.isObject()) {
        QJsonObject jsonName = nameVal.toObject();
        name = this->readName(jsonName);
    }
    Patient patient = Patient(address, titel, name, birthDate, phoneNumber, gender);
    return patient;
}

Address PatientJsonManager::readAddress(QJsonObject &jsonAddress)
{
    QString street = jsonAddress.value("street").toString();
    QString houseNumber = jsonAddress.value("house number").toString();
    int plz = jsonAddress.value("plz").toInt();
    QString location = jsonAddress.value("location").toString();
    return Address(street, houseNumber, plz, location);
}

Name PatientJsonManager::readName(QJsonObject &jsonName)
{
    QString firstName = jsonName.value("first name").toString();
    QString lastName = jsonName.value("last name").toString();
    return Name(firstName, lastName);
}
