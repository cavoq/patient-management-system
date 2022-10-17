#include "model/header/patient.h"

Patient::Patient(Address& address, QString titel, Name& name, QDate birthDate, QString phoneNumber, QString gender)
{
    this->address = address;
    this->titel = titel;
    this->name = name;
    this->birthDate = birthDate;
    this->phoneNumber = phoneNumber;
    this->gender = gender;
}

Patient::Patient() {}
