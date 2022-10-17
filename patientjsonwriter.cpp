#include "patientjsonwriter.h"
#include "qjsondocument.h"
#include <QIODevice>
#include <QFile>
#include <iostream>

PatientJsonWriter::PatientJsonWriter() {}

bool PatientJsonWriter::writeToJson(QString jsonFile, const QList<Patient>& patients)
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

bool PatientJsonWriter::writePatient(QJsonObject &jsonPatient, const Patient &patient)
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

bool PatientJsonWriter::writeAddress(QJsonObject &jsonAddress, const Address &address)
{
    jsonAddress.insert("street", address.street);
    jsonAddress.insert("house number", address.houseNumber);
    jsonAddress.insert("plz", address.plz);
    jsonAddress.insert("location", address.location);
    return true;
}

bool PatientJsonWriter::writeName(QJsonObject &jsonName, const Name &name)
{
    jsonName.insert("first name", name.firstName);
    jsonName.insert("last name", name.lastName);
    return true;
}
