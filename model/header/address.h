/**
 *  Declaration of the data structure address.
 */


#ifndef ADDRESS_H
#define ADDRESS_H

#include <QString>

class Address
{
public:

    /**
     * Constructs a new empty Address object.
     */
    Address();

    /**
     * Constructs a new Address object.
     *
     * @param street Street of the address.
     * @param houseNumber House number of the address.
     * @param plz PLZ of the address.
     * @param location Location of the address.
     */
    Address(QString street, QString houseNumber, QString plz, QString location);

    /// Street of the address.
    QString street;

    /// House number of the address.
    QString houseNumber;

    /// PLZ of the address.
    QString plz;

    /// Location of the address.
    QString location;
};

#endif // ADDRESS_H
