#include "model/header/patient.h"

Patient::Patient(Address& address, std::string titel, Name& name, std::string birth_date, std::string phone_number, Gender gender)
{
    this->address = address;
    this->titel = titel;
    this->name = name;
    this->birth_date = birth_date;
    this->phone_number = phone_number;
    this->gender = gender;
}
