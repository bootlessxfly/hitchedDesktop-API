#include "widget.h"
#include "addressbook.h"
#include "ui_widget.h"
#include <QtAndroidExtras>
#include <QAndroidJniObject>
#include <QtDebug>
#include <vector>
#include <QStringList>

Contact::Contact(std::string name, std::string number) : name(name), number(number) {}

QStringList loadContacts() {
    QStringList list;
    list << "Name: Billy\nNumber: 4239872345\n";
    list << "Name: Will O'Rourke\nNumber: 1402457893\n";
    list << "Name: John Harrison\nNumber: 3475295673\n";
    return list;
}

struct Contact getContactWithIndex(int index) {
    std::vector<Contact> list = {
        Contact("Billy", "4239872345"),
        Contact("Will O'Rourke", "1402457893"),
        Contact("John Harrison", "3475295673")
    };

    if (index > list.size()) {
        return Contact("NULL", "NULL");
    } else {
        return list[index];
    }
}
