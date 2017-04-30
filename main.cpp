#include "widget.h"
#include "permissions.h"
#include "addressbook.h"
#include <QApplication>
#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL
  Java_com_github_hitcheddesktopapi_AddressBook_getAddressBook(JNIEnv *env,
                                                    jobject obj,
                                                    jint n)
{
    qDebug() << "Computed fibonacci is:" << n;
}

#ifdef __cplusplus
}
#endif

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //checkPermissions();
    Widget w;
    w.show();

    return a.exec();
}

