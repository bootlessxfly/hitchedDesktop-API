#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets>
#include <QtAndroidExtras>
#include <QAndroidJniObject>
#include <QListWidgetItem>



namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButton_clicked();
    void onAddressItemClicked(QListWidgetItem* item);

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
