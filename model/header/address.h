#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>

class Address
{
public:
    Address();
    Address(std::string street, int house_number, int plz, std::string location);
    std::string street;
    int house_number;
    int plz;
    std::string location;
};

#endif // ADDRESS_H
