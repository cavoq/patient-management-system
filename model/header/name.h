#ifndef NAME_H
#define NAME_H

#include <QString>

struct Name {
    QString firstName;
    QString lastName;

    Name() {}
    Name(QString firstName, QString lastName) : firstName(firstName), lastName(lastName) {}
};

#endif // NAME_H
