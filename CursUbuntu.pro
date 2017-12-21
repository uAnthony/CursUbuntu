#-------------------------------------------------
#
# Project created by QtCreator 2017-12-12T08:54:30
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       += core sql
QT       += gui
QT       += core
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CursUbuntu
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tasks.cpp \
    query1.cpp

HEADERS  += mainwindow.h \
    tasks.h \
    query1.h \
    parameters.h

FORMS    += mainwindow.ui
