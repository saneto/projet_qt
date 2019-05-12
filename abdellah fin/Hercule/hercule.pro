#-------------------------------------------------
#
# Project created by QtCreator 2015-05-24T17:42:41
#
#-------------------------------------------------

QT       += core gui
QT       += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = hercule
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ../Hercule200/serveur.cpp \
    ../Hercule200/thread.cpp \
    serie.cpp

HEADERS  += mainwindow.h \
    ../Hercule200/serveur.h \
    ../Hercule200/thread.h \
    serie.h
LIBS += -l winmm
FORMS    += mainwindow.ui
