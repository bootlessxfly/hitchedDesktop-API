#include "widget.h"
#include "ui_widget.h"
#include <QtAndroidExtras>
#include <QAndroidJniObject>
#include <QtDebug>

bool checkPermissions() {
    QAndroidJniObject activity =  QAndroidJniObject::callStaticObjectMethod("org/qtproject/qt5/android/QtNative",
                                                                            "activity",
                                                                            "()Landroid/app/Activity;");
    QAndroidJniObject permission = QAndroidJniObject::fromString("android.permission.READ_SMS");
    int hasPermission = QAndroidJniObject::callStaticMethod<jint>("android/support/v4/content/ContextCompat", "checkSelfPermission", "(Landroid/content/Context;Ljava/lang/String)I",
                                                                        activity.object(), permission.object<jstring>());

    qDebug() << hasPermission << " is the response" << endl;
    if (hasPermission == 0) {
        return true;
    } else {
        return false;
    }
}
