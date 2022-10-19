/*
 *  Declaration of the PatientJsonWriter, used to read patients from a json file.
 */

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

    /*
     * Write a list if patients into a json file.
     *
     * @param jsonFile file to write to
     * @param patients list of patients to be written
     * @return returns true if writting ws successful
     */
    bool writeToJson(QString jsonFile, const QList<Patient> &patients);

private:
    bool writeAddress(QJsonObject &jsonObject, const Address &address);
    bool writeName(QJsonObject &jsonObject, const Name &name);
    bool writePatient(QJsonObject &jsonObject, const Patient &patient);
};

#endif // PATIENTJSONWRITER_H
