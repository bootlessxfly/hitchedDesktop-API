#include "widget.h"
#include "permissions.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    checkPermissions();
    Widget w;
    w.show();

    return a.exec();
}
