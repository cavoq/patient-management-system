#ifndef ADRESS_H
#define ADRESS_H

#include <string>

class Adress
{
public:
    Adress();
    Adress(std::string street, int house_number, int plz, std::string location);
    std::string street;
    int house_number;
    int plz;
    std::string location;
};

#endif // ADRESS_H
