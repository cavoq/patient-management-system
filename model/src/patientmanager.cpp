#include "model/header/patientmanager.h"
#include <QtCore>
#include <iostream>
#include <QIODevice>

PatientManager::PatientManager() {}

QList<Patient>& PatientManager::getPatients()
{
    return this->patients;
}

void PatientManager::save_to_json(QString json_file)
{
    QJsonObject content;
    QJsonDocument document;
    int patient_index = 0;
    for (Patient& patient: this->patients) {
        std::string patient_index_as_string = std::to_string(patient_index);
        QJsonObject q_patient;
        QJsonObject q_adress;
        QJsonObject q_name;
        q_name.insert("first name", patient.name.first_name);
        q_name.insert("last name", patient.name.last_name);
        q_adress.insert("street", patient.address.street);
        q_adress.insert("house number", patient.address.house_number);
        q_adress.insert("plz", patient.address.plz);
        q_adress.insert("location", patient.address.location);
        q_patient.insert("titel", patient.titel);
        q_patient.insert("name", q_name);
        q_patient.insert("address", q_adress);
        q_patient.insert("phone number", patient.phone_number);
        q_patient.insert("birth date", patient.birth_date.toString());
        q_patient.insert("gender", patient.gender);
        content.insert(QString::fromStdString(patient_index_as_string), q_patient);
        patient_index += 1;
    }
    document.setObject(content);
    QByteArray bytes = document.toJson(QJsonDocument::Indented);
    QFile file(json_file);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        file.write(bytes);
        file.close();
     }
     else {
        std::cout << "file open failed: " << json_file.toStdString() << std::endl;
     }
}

void PatientManager::load_from_json(QString json_file)
{
    this->patients.clear();
    QFile file(json_file);
    if (file.open(QIODevice::ReadOnly)) {
        QByteArray bytes = file.readAll();
        file.close();

        QJsonParseError jsonError;
        QJsonDocument document = QJsonDocument::fromJson(bytes, &jsonError);
            if (jsonError.error != QJsonParseError::NoError) {
                std::cout << "fromJson failed: " << jsonError.errorString().toStdString() << std::endl;
                return ;
            }
            if (document.isObject()) {
                QJsonObject json = document.object();
                for (auto patient_index: json) {
                    Address address;
                    Name name;
                    if (patient_index.isObject()) {
                        QString titel = patient_index.toObject().value("titel").toString();
                        QDate birth_date = QDate::fromString(patient_index.toObject().value("birth date").toString(), "dd.MM.yyyy");
                        QString gender = patient_index.toObject().value("gender").toString();
                        QString phone_number = patient_index.toObject().value("phone number").toString();
                        QJsonValue address_val = patient_index.toObject().value("address");
                        if (address_val.isObject()) {
                            QJsonObject json_address = address_val.toObject();
                            address = this->create_address(json_address);
                        }
                        QJsonValue name_val = patient_index.toObject().value("name");
                        if (name_val.isObject()) {
                            QJsonObject json_name = name_val.toObject();
                            name = this->create_name(json_name);
                        }
                        Patient patient = Patient(address, titel, name, birth_date, phone_number, gender);
                        this->patients.push_back(patient);
                    }
                }
            }
        }
}

Address PatientManager::create_address(QJsonObject& json_address)
{
    QString street = json_address.value("street").toString();
    int house_number = json_address.value("house number").toInt();
    int plz = json_address.value("plz").toInt();
    QString location = json_address.value("location").toString();
    return Address(street, house_number, plz, location);
}

Name PatientManager::create_name(QJsonObject& json_name)
{
    QString first_name = json_name.value("first name").toString();
    QString last_name = json_name.value("last name").toString();
    return Name(first_name, last_name);
}
