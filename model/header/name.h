/**
 *  Declaration the data structure Name.
 */


#ifndef NAME_H
#define NAME_H

#include <QString>

struct Name {

    /// First name of a person.
    QString firstName;

    /// Last name of a person.
    QString lastName;

    /**
     * Constructs a new empty Name object.
     */
    Name() {}

    /**
     * Constructs a new Name object.
     *
     * @param firstName First name of the person.
     * @param lastName Last name of the person.
     */
    Name(QString firstName, QString lastName) : firstName(firstName), lastName(lastName) {}
};

#endif // NAME_H
