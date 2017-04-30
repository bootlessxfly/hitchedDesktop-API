#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#endif // ADDRESSBOOK_H
#include <string>

QStringList loadContacts();
struct Contact getContactWithIndex(int index);

class Contact {
public:

    std::string name;
    std::string number;

    Contact(std::string, std::string);
};
