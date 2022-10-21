/**
 *  Declaration of the data structure Patient.
 */


#ifndef PATIENT_H
#define PATIENT_H

#include "model/header/name.h"
#include "model/header/address.h"
#include "qdatetime.h"

class Patient
{
public:

    /**
     * Constructs a new empty Patient object.
     */
    Patient();

    /**
     * Constructs a new Patient object.
     *
     * @param adress Address of the patient.
     * @param titel Titel of the patient.
     * @param name Name of the patient.
     * @param birthDate Birth date of the patient.
     * @param phoneNumber Phone number of the patient,
     * @param gender Gender of the patient.
     */
    Patient(Address& adress, QString titel, Name& name, QDate birthDate, QString phoneNumber, QString gender);

    /// Adress of the patient.
    Address address;

    /// Titel of the patient.
    QString titel;

    /// Name of the patient.
    Name name;

    /// Birth date of the patient.
    QDate birthDate;

    /// Phone number of the patient.
    QString phoneNumber;

    /// Gender of the patient.
    QString gender;
};

#endif // PATIENT_H
