#include "model/header/address.h"

Address::Address(QString street, QString houseNumber, int plz, QString location)
{
    this->street = street;
    this->houseNumber = houseNumber;
    this->plz = plz;
    this->location = location;
}

Address::Address() {}
