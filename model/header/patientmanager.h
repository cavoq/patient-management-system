/**
 * PatientManager class, that holds the patient data and is responsible for
 * operations like saving and reading patient data from a file.
 */

#ifndef PATIENTMANAGER_H
#define PATIENTMANAGER_H

#include <vector>
#include <QtCore>
#include "model/header/patient.h"

class PatientManager
{
private:
    QList<Patient> patients;
    Address create_address(QJsonObject& json_address);
    Name create_name(QJsonObject& json_name);

public:
    PatientManager();
    QList<Patient>& getPatients();
    void save_to_json(QString json_file);
    void load_from_json(QString json_file);
};

#endif // PATIENTMANAGER_H
