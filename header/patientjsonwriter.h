/**
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

    /**
     * Constructs a new PatientJsonWriter object.
     */
    PatientJsonWriter();

    /**
     * Write a list of patients into a json file.
     *
     * @param jsonFile File to write to.
     * @param patients List of patients to be written.
     * @return Returns true if writting ws successful.
     */
    bool writeToJson(QString jsonFile, const QList<Patient> &patients);

private:

    /**
     * Writes the address of a patient into a QJsonObject.
     *
     * @param jsonObject Json object to write to.
     * @param address Address of the patient.
     * @return Returns true if writting was successful.
     */
    bool writeAddress(QJsonObject &jsonObject, const Address &address);

    /**
     * Writes the name of a patient into a QJsonObject (first name and second name).
     *
     * @param jsonObject Json object to write to.
     * @param name Name of the patient.
     * @return Returns true if writting was successful.
     */
    bool writeName(QJsonObject &jsonObject, const Name &name);

    /**
     * Writes the patient into a QJsonObject.
     *
     * @param jsonObject Json object to write to.
     * @param patient Patient to be written.
     * @return Returns true if writting was successful.
     */
    bool writePatient(QJsonObject &jsonObject, const Patient &patient);
};

#endif // PATIENTJSONWRITER_H
