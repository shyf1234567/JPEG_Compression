#-------------------------------------------------
#
# Project created by QtCreator 2016-02-17T19:41:07
#
#-------------------------------------------------

QT       += core gui
CONFIG += c++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = JPEG_impression
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    filebrowser.cpp \
    global.cpp \
    image.cpp

HEADERS  += mainwindow.h \
    filebrowser.h \
    global.h \
    image.h

FORMS    += mainwindow.ui \
    filebrowser.ui
