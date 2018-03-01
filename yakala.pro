#-------------------------------------------------
#
# Project created by QtCreator 2018-02-02T14:20:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = yakala
TEMPLATE = app

INCLUDEPATH += include/
INCLUDEPATH += include/systemmanager

SOURCES +=  src/main.cpp \
            src/mainwindow.cpp \
            src/thread_systeminfo.cpp \
            src/qcustomplot.cpp \
            src/systemmanager/aliases.cpp \
            src/systemmanager/filesearch.cpp \
            src/systemmanager/networksearch.cpp \
            src/systemmanager/systeminfo.cpp \
            src/systemmanager/environment.cpp \
            src/systemmanager/processes.cpp \
            src/systemmanager/sockets.cpp \
            src/systemmanager/packages.cpp

HEADERS  += include/main.h \
            include/mainwindow.h \
            include/thread_systeminfo.h \
            include/qcustomplot.h \
            include/systemmanager/aliases.h \
            include/systemmanager/filesearch.h \
            include/systemmanager/networksearch.h \
            include/systemmanager/systeminfo.h \
            include/systemmanager/environment.h \
            include/systemmanager/processes.h \
            include/systemmanager/sockets.h \
            include/systemmanager/packages.h

FORMS    += forms/mainwindow.ui

RESOURCES += \
    resources/resources.qrc

DESTDIR = build
OBJECTS_DIR = build
MOC_DIR = build
RCC_DIR = build
UI_DIR = build
