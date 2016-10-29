#-------------------------------------------------
#
# Project created by QtCreator 2016-10-29T14:22:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Dashboard
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp\
        ../../source/qcgaugewidget.cpp

HEADERS  += mainwindow.h\
            ../../source/qcgaugewidget.h

FORMS    += mainwindow.ui
