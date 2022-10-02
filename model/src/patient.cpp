#include "model/header/patient.h"

Patient::Patient(Address& address, QString titel, Name& name, QString birth_date, QString phone_number, QString gender)
{
    this->address = address;
    this->titel = titel;
    this->name = name;
    this->birth_date = birth_date;
    this->phone_number = phone_number;
    this->gender = gender;
}
