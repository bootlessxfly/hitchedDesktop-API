#-------------------------------------------------
#
# Project created by QtCreator 2015-06-28T10:04:04
#
#-------------------------------------------------

QT       += core gui
#QT += qml quick widgets sql core bluetooth printsupport androidextras
QT += widgets
SOURCES += main.cpp
QT += quick androidextras


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = send-sms
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

FORMS    += widget.ui

CONFIG += mobility
MOBILITY = 

DISTFILES += \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/AndroidManifest.xml \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew \
    android/gradlew.bat

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android-sources

