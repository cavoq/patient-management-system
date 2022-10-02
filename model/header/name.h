#ifndef NAME_H
#define NAME_H

#include <QString>

struct Name {
    QString first_name;
    QString last_name;

    Name() {}
    Name(QString first_name, QString last_name) : first_name(first_name), last_name(last_name) {}
};

#endif // NAME_H
