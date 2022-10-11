#include "model/header/address.h"

Address::Address(QString street, QString house_number, int plz, QString location)
{
    this->street = street;
    this->house_number = house_number;
    this->plz = plz;
    this->location = location;
}

Address::Address() {}
