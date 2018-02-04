#-------------------------------------------------
#
# Project created by QtCreator 2018-02-02T14:20:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = yakala
TEMPLATE = app
INCLUDEPATH += include/


SOURCES +=  src/aliases.cpp \
            src/filesearch.cpp \
            src/main.cpp \
            src/mainwindow.cpp \
            src/networksearch.cpp \
            src/systeminfo.cpp \
            src/thread_systeminfo.cpp

HEADERS  += include/aliases.h \
            include/filesearch.h \
            include/main.h \
            include/mainwindow.h \
            include/networksearch.h \
            include/systeminfo.h \
            include/thread_systeminfo.h

FORMS    += forms/mainwindow.ui

RESOURCES += \
    resources/resources.qrc

DESTDIR = build
OBJECTS_DIR = build
MOC_DIR = build
RCC_DIR = build
UI_DIR = build
