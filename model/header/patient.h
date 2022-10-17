#ifndef PATIENT_H
#define PATIENT_H

#include "model/header/name.h"
#include "model/header/address.h"
#include "qdatetime.h"

class Patient
{
public:
    Patient();
    Patient(Address& adress, QString titel, Name& name, QDate birthDate, QString phoneNumber, QString gender);
    Address address;
    QString titel;
    Name name;
    QDate birthDate;
    QString phoneNumber;
    QString gender;
};

#endif // PATIENT_H
