#include "widget.h"
#include "ui_widget.h"
#include "permissions.h"
#include "addressbook.h"
#include <QDebug>
#include <QStringListModel>
#include <QListView>
#include <QStringList>
#include <QAbstractListModel>
#include <QListWidgetItem>
#include <string>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("example SMS");

    QStringList list = loadContacts();
    ui->listWidget->addItems(list);

    connect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem*)),
                this, SLOT(onAddressItemClicked(QListWidgetItem*)));
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

void Widget::onAddressItemClicked(QListWidgetItem* item)
{
    QSize size = ui->listWidget->size();
    for (int i = 0; i < size.height(); i++) {
        if (ui->listWidget->item(i) == item) {
            struct Contact temp = getContactWithIndex(i);
            qDebug() << "Number: " << QString::fromStdString(temp.number) << endl;
            ui->lineEditDestinataire->setText(QString::fromStdString(temp.number));
            ui->tabWidget->setCurrentWidget(ui->tab_2);
            break;
        }
    }
}
