#-------------------------------------------------
#
# Project created by QtCreator 2015-05-21T11:01:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Abd
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cos.cpp

HEADERS  += mainwindow.h \
    cos.h

FORMS    += mainwindow.ui
LIBS += -l winmm
