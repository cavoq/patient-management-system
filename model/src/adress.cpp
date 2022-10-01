#include "model/header/adress.h"

Adress::Adress(std::string street, int house_number, int plz, std::string location)
{
    this->street = street;
    this->house_number = house_number;
    this->plz = plz;
    this->location = location;
}

Adress::Adress()
{
}
