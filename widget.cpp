#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("example SMS");
    this->setLayout(ui->verticalLayout);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
// get the Qt android activity
QAndroidJniObject activity =  QAndroidJniObject::callStaticObjectMethod("org/qtproject/qt5/android/QtNative",
                                                                        "activity",
                                                                        "()Landroid/app/Activity;");
if (activity.isValid()){
    // get the default SmsManager
    QAndroidJniObject mySmsManager = QAndroidJniObject::callStaticObjectMethod("android/telephony/SmsManager",
                                                                               "getDefault",
                                                                               "()Landroid/telephony/SmsManager;" );
    // get phone number & text from UI and convert to Java String
    QAndroidJniObject myPhoneNumber = QAndroidJniObject::fromString(ui->lineEditDestinataire->text());
    QAndroidJniObject myTextMessage = QAndroidJniObject::fromString(ui->lineEditTexte->text());
    QAndroidJniObject scAddress = NULL;
    QAndroidJniObject sentIntent = NULL;
    QAndroidJniObject deliveryIntent = NULL;

    // call the java function:
    // public void SmsManager.sendTextMessage(String destinationAddress,
    //                                        String scAddress, String text,
    //                                        PendingIntent sentIntent, PendingIntent deliveryIntent)
    // see: http://developer.android.com/reference/android/telephony/SmsManager.html

    mySmsManager.callMethod<void>("sendTextMessage",
                                  "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Landroid/app/PendingIntent;Landroid/app/PendingIntent;)V",
                                   myPhoneNumber.object<jstring>(),
                                   scAddress.object<jstring>(),
                                   myTextMessage.object<jstring>(), NULL, NULL );

      }
else
    qDebug() << "Something wrong with Qt activity...";

}

