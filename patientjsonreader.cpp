/*
 *  Implementation of the PatientJsonReader, used to read the patients from a json file.
 */

#include "patientjsonreader.h"
#include <QFile>
#include <QJsonParseError>
#include <iostream>
#include <QIODevice>

PatientJsonReader::PatientJsonReader() {}

QList<Patient> PatientJsonReader::readFromJson(QString jsonFile)
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

Patient PatientJsonReader::readPatient(QJsonObject &jsonPatient)
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

Address PatientJsonReader::readAddress(QJsonObject &jsonAddress)
{
    QString street = jsonAddress.value("street").toString();
    QString houseNumber = jsonAddress.value("house number").toString();
    QString plz = jsonAddress.value("plz").toString();
    QString location = jsonAddress.value("location").toString();
    return Address(street, houseNumber, plz, location);
}

Name PatientJsonReader::readName(QJsonObject &jsonName)
{
    QString firstName = jsonName.value("first name").toString();
    QString lastName = jsonName.value("last name").toString();
    return Name(firstName, lastName);
}
