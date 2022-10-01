#include "model/header/patient.h"

Patient::Patient(Adress& adress, std::string titel, Name& name, std::string birth_date, std::string phone_number, Gender gender)
{
    this->adress = adress;
    this->titel = titel;
    this->name = name;
    this->birth_date = birth_date;
    this->phone_number = phone_number;
    this->gender = gender;
}
