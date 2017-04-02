#-------------------------------------------------
#
# Project created by QtCreator 2015-06-28T10:04:04
#
#-------------------------------------------------

QT += widgets core gui quick
#QT += qml quick widgets sql core bluetooth printsupport androidextras
QT += androidextras
SOURCES += main.cpp


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = send-sms
TEMPLATE = app


SOURCES += widget.cpp

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
    android/gradlew.bat \
    android-sources/AndroidManifest.xml \
    android-sources/gradle/wrapper/gradle-wrapper.jar \
    android-sources/gradlew \
    android-sources/res/values/libs.xml \
    android-sources/build.gradle \
    android-sources/gradle/wrapper/gradle-wrapper.properties \
    android-sources/gradlew.bat

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android-sources

