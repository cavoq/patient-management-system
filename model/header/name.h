#ifndef NAME_H
#define NAME_H

#include <string>

struct Name {
    std::string first_name;
    std::string last_name;

    Name() {}
    Name(std::string first_name, std::string last_name) : first_name(first_name), last_name(last_name) {}
};

#endif // NAME_H
