#ifndef PATIENT_H
#define PATIENT_H

#include "model/header/name.h"
#include "model/header/address.h"

class Patient
{
public:
    Patient();
    ~Patient();
    Patient(Address& adress, QString titel, Name& name, QString birth_date, QString phone_number, QString gender);
    Address address;
    QString titel;
    Name name;
    QString birth_date;
    QString phone_number;
    QString gender;
};

#endif // PATIENT_H
