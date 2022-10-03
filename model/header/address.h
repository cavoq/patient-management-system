#ifndef ADDRESS_H
#define ADDRESS_H

#include <QString>

class Address
{
public:
    Address();
    ~Address();
    Address(QString street, int house_number, int plz, QString location);
    QString street;
    int house_number;
    int plz;
    QString location;
};

#endif // ADDRESS_H
