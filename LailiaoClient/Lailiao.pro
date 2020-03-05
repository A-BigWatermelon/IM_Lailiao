#-------------------------------------------------
#
# Project created by QtCreator 2013-12-02T21:22:43
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += webkit
QT       += webkitwidgets
QT       += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Lailiao
TEMPLATE = app


SOURCES += main.cpp\
        login.cpp \
    client.cpp \
    chat.cpp \
    download.cpp \
    search.cpp \
    transfer.cpp

HEADERS  += login.h \
    constant.h \
    client.h \
    chat.h \
    download.h \
    search.h \
    transfer.h

FORMS    += login.ui \
    transfer.ui \
    search.ui \
    download.ui \
    client.ui \
    chat.ui

RESOURCES += \
    icon.qrc \
    icon.qrc
