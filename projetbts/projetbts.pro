#-------------------------------------------------
#
# Project created by QtCreator 2015-05-18T14:59:29
#
#-------------------------------------------------

QT       += core gui
QT       += concurrent
QT += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = projetbts
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cvcam.cpp \
    information.cpp \
    joystick.cpp \
    sauvegarde.cpp \
    tcpsocket.cpp \
    parametre.cpp

HEADERS  += mainwindow.h \
    cvcam.h \
    information.h \
    joystick.h \
    sauvegarde.h \
    tcpsocket.h \
    parametre.h

FORMS    += mainwindow.ui \
    parametre.ui
LIBS += -l winmm
LIBS += -LC:\Users\aymane\Downloads\opencv\build\x86\vc11\staticlib -lopencv_ts300 -lopencv_world300
LIBS += -LC:\Users\aymane\Downloads\opencv\build\x86\vc11\bin -lopencv_ffmpeg300
INCLUDEPATH += -C:\Users\aymane\Downloads\opencv\build\include
