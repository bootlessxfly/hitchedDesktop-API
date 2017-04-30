#include "widget.h"
#include "ui_widget.h"
#include <QtAndroidExtras>
#include <QAndroidJniObject>
#include <QtDebug>

bool checkPermissions(char *permissionName) {
    QAndroidJniObject activity =  QAndroidJniObject::callStaticObjectMethod("org/qtproject/qt5/android/QtNative",
                                                                            "activity",
                                                                            "()Landroid/app/Activity;");
    QAndroidJniObject permission = QAndroidJniObject::fromString(permissionName);
    int hasPermission = QAndroidJniObject::callStaticMethod<jint>("android/support/v4/content/ContextCompat", "checkSelfPermission",
                                                                  "(Landroid/content/Context;Ljava/lang/String;)I;",
                                                                        activity.object(), permission.object<jstring>());

    qDebug() << hasPermission << " is the response" << endl;
    if (hasPermission == 0) {
        return true;
    } else {
        return false;
    }
}

void requestPermission() {
    QAndroidJniObject activity =  QAndroidJniObject::callStaticObjectMethod("org/qtproject/qt5/android/QtNative",
                                                                            "activity",
                                                                            "()Landroid/app/Activity;");
    QString array[4];
    array[0] = "android.permission.READ_SMS";
    array[1] = "android.permission.RECEIVE_SMS";
    array[2] = "android.permission.SEND_SMS";
    array[3] = "android.permission.WRITE_SMS";
    QAndroidJniObject::callStaticObjectMethod("android/support/v4/app/ActivityCompat",
                                              "requestPermissions",
                                              "(Landroid/app/Activity;[Ljava/lang/String;I;)V;", activity.object(), array, new jint(0));
}
