#ifndef ADDRESS_H
#define ADDRESS_H

#include <QString>

class Address
{
public:
    Address();
    Address(QString street, QString houseNumber, int plz, QString location);
    QString street;
    QString houseNumber;
    int plz;
    QString location;
};

#endif // ADDRESS_H
