#-------------------------------------------------
#
# Project created by QtCreator 2015-05-06T20:52:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = retets
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    joy.cpp \
    joystick.cpp \
    clienttcp.cpp

HEADERS  += mainwindow.h \
    joy.h \
    joystick.h \
    clienttcp.h

FORMS    += mainwindow.ui
LIBS += -l winmm
