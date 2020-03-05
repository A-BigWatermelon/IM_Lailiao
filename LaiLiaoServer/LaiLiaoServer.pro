#-------------------------------------------------
#
# Project created by QtCreator 2013-12-03T21:15:44
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += sql
QT       += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LaiLiaoServer
TEMPLATE = app


SOURCES += main.cpp\
        server.cpp \
    clientsocket.cpp \
    dbhelper.cpp

HEADERS  += server.h \
    clientsocket.h \
    constant.h \
    ui_clientsocket.h \
    ui_server.h \
    dbhelper.h

FORMS    += server.ui

RESOURCES += \
    icon.qrc
