/**
 *  Declaration of the PatientJsonReader, used to read patients from a json file.
 */

#ifndef PATIENTJSONREADER_H
#define PATIENTJSONREADER_H

#include "model/header/address.h"
#include "model/header/name.h"
#include "model/header/patient.h"
#include "qjsonobject.h"

class PatientJsonReader
{
public:

    /**
     * Constructs a mew PatientJsonReader object.
     */
    PatientJsonReader();

    /**
     * Reads a list of patients from a json file.
     *
     * @param jsonFile Json file to read from.
     * @return Returns a list of patients if reading was successful.
     * @throws QJsonParseError if reading failed.
     */
    QList<Patient> readFromJson(QString jsonFile);

private:

    /**
     * Reads the address from a QJsonObject.
     *
     * @param jsonAddress Json object to read from.
     * @return Returns the address that got read.
     */
    Address readAddress(QJsonObject &jsonAddress);

    /**
     * Reads the name from a QJsonObject.
     *
     * @param jsonName Json object to read from.
     * @return Returns the name that got read.
     */
    Name readName(QJsonObject &jsonName);

    /**
     * Reads a patient from a QJsonObject.
     *
     * @param jsonPatient Json object to read from.
     * @return Returns the patient that got read.
     */
    Patient readPatient(QJsonObject &jsonPatient);
};

#endif // PATIENTJSONREADER_H
