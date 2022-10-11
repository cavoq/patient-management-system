#ifndef ADDRESS_H
#define ADDRESS_H

#include <QString>

class Address
{
public:
    Address();
    Address(QString street, QString house_number, int plz, QString location);
    QString street;
    QString house_number;
    int plz;
    QString location;
};

#endif // ADDRESS_H
