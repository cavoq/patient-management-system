/* Class that is responsible for reading the patients from a json file */

#ifndef PATIENTJSONREADER_H
#define PATIENTJSONREADER_H


#include "model/header/address.h"
#include "model/header/name.h"
#include "model/header/patient.h"
#include "qjsonobject.h"

class PatientJsonReader
{
public:
    PatientJsonReader();
    QList<Patient> readFromJson(QString jsonFile);

private:
    Address readAddress(QJsonObject &jsonAddress);
    Name readName(QJsonObject &jsonName);
    Patient readPatient(QJsonObject &jsonPatient);
};

#endif // PATIENTJSONREADER_H
