#ifndef PATIENT_H
#define PATIENT_H

#include "model/header/name.h"
#include "model/header/gender.h"
#include "model/header/address.h"

class Patient
{
public:
    Patient(Address& adress, std::string titel, Name& name, std::string birth_date, std::string phone_number, Gender gender);
    Address address;
    std::string titel;
    Name name;
    std::string birth_date;
    std::string phone_number;
    Gender gender;
};

#endif // PATIENT_H
