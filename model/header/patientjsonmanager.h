/**
 * PatientJsonManager class, that is responsible for
 * json operations like saving and reading patient data from a file.
 */

#ifndef PATIENTJSONMANAGER_H
#define PATIENTJSONMANAGER_H

#include <vector>
#include <QtCore>
#include "model/header/patient.h"

class PatientJsonManager
{
private:
    Address readAddress(QJsonObject &jsonAddress);
    Name readName(QJsonObject &jsonName);
    Patient readPatient(QJsonObject &jsonPatient);
    bool writeAddress(QJsonObject &jsonObject, Address &address);
    bool writeName(QJsonObject &jsonObject, Name &name);
    bool writePatient(QJsonObject &jsonObject, Patient &patient);

public:
    PatientJsonManager();
    bool writeToJson(QString jsonFile, QList<Patient> &patients);
    QList<Patient> readFromJson(QString jsonFile);
};

#endif // PATIENTJSONMANAGER_H
