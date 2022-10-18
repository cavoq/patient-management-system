/* Class that is responsible for writing the patients to a json file */

#ifndef PATIENTJSONWRITER_H
#define PATIENTJSONWRITER_H


#include "model/header/address.h"
#include "model/header/name.h"
#include "model/header/patient.h"
#include "qjsonobject.h"

class PatientJsonWriter
{
public:
    PatientJsonWriter();
    bool writeToJson(QString jsonFile, const QList<Patient> &patients);

private:
    bool writeAddress(QJsonObject &jsonObject, const Address &address);
    bool writeName(QJsonObject &jsonObject, const Name &name);
    bool writePatient(QJsonObject &jsonObject, const Patient &patient);
};

#endif // PATIENTJSONWRITER_H
