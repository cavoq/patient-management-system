#include "model/header/patientmanager.h"
#include <QtCore>
#include <iostream>
#include <QIODevice>

PatientManager::PatientManager() {}

std::vector<Patient>& PatientManager::getPatients()
{
    return this->patients;
}

void PatientManager::save_to_json(QString json_file)
{
    QJsonObject content;
    QJsonDocument document;
    int patient_index = 0;
    for(Patient& patient: this->patients)
    {
        std::string patient_index_as_string = std::to_string(patient_index);
        QJsonObject q_patient;
        QJsonObject q_adress;
        QJsonObject q_name;
        q_name.insert("first name", patient.name.first_name.c_str());
        q_name.insert("last name", patient.name.last_name.c_str());
        q_adress.insert("street", patient.address.street.c_str());
        q_adress.insert("house number", patient.address.house_number);
        q_adress.insert("plz", patient.address.plz);
        q_adress.insert("location", patient.address.location.c_str());
        q_patient.insert("titel", patient.titel.c_str());
        q_patient.insert("name", q_name);
        q_patient.insert("address", q_adress);
        q_patient.insert("phone number", patient.phone_number.c_str());
        q_patient.insert("birth date", patient.birth_date.c_str());
        q_patient.insert("gender", patient.gender);
        content.insert(QString::fromStdString(patient_index_as_string), q_patient);
        patient_index += 1;
    }
    document.setObject(content);
    QByteArray bytes = document.toJson(QJsonDocument::Indented);
    QFile file(json_file);
    if(file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
    {
        file.write(bytes);
        file.close();
     }
     else
     {
        std::cout << "file open failed: " << json_file.toStdString() << std::endl;
     }
}

void PatientManager::load_from_json(QString json_file)
{
    this->patients.clear();
    QFile file(json_file);
    if(file.open(QIODevice::ReadOnly))
    {
        QByteArray bytes = file.readAll();
        file.close();

        QJsonParseError jsonError;
        QJsonDocument document = QJsonDocument::fromJson(bytes, &jsonError);
            if(jsonError.error != QJsonParseError::NoError)
            {
                std::cout << "fromJson failed: " << jsonError.errorString().toStdString() << std::endl;
                return ;
            }
            if(document.isObject())
            {
                QJsonObject json = document.object();
                for(auto patient_index: json)
                {
                    Address address;
                    Name name;
                    if(patient_index.isObject())
                    {
                        std::string titel = patient_index.toObject().value("titel").toString().toStdString();
                        std::string birth_date = patient_index.toObject().value("birth date").toString().toStdString();
                        Gender gender = (Gender) patient_index.toObject().value("gender").toInt();
                        std::string phone_number = patient_index.toObject().value("phone number").toString().toStdString();
                        QJsonValue address_val = patient_index.toObject().value("address");
                        if (address_val.isObject())
                        {
                            QJsonObject json_address = address_val.toObject();
                            address = this->create_address(json_address);
                        }
                        QJsonValue name_val = patient_index.toObject().value("name");
                        if (name_val.isObject())
                        {
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
    std::string street = json_address.value("street").toString().toStdString();
    int house_number = json_address.value("house number").toInt();
    int plz = json_address.value("plz").toInt();
    std::string location = json_address.value("location").toString().toStdString();
    return Address(street, house_number, plz, location);
}

Name PatientManager::create_name(QJsonObject& json_name)
{
    std::string first_name = json_name.value("first name").toString().toStdString();
    std::string last_name = json_name.value("last name").toString().toStdString();
    return Name(first_name, last_name);
}
