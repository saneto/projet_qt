#-------------------------------------------------
#
# Project created by QtCreator 2015-05-18T14:59:29
#
#-------------------------------------------------

QT       += core gui
QT += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = projetbts
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cvcam.cpp \
    information.cpp \
    joystick.cpp \
    tcpclient.cpp \
    sauvegarde.cpp

HEADERS  += mainwindow.h \
    cvcam.h \
    information.h \
    joystick.h \
    tcpclient.h \
    sauvegarde.h

FORMS    += mainwindow.ui
LIBS += -l winmm -lws2_32
#LIBS += -LC:\Users\Eleve\Desktop\projetbdelouzair\opencv\build\x86\vc12\lib -lopencv_core2411 -lopencv_highgui2411
#LIBS += -LC:\Users\Eleve\Desktop\projetbdelouzair\opencv\build\x86\vc12\bin -lopencv_ffmpeg2411
#INCLUDEPATH += -C:\Users\Eleve\Desktop\projetbdelouzair\opencv\build\include
LIBS += -LC:\Users\aymane\Downloads\opencv\build\x86\vc11\staticlib -lopencv_ts300 -lopencv_world300
LIBS += -LC:\Users\aymane\Downloads\opencv\build\x86\vc11\bin -lopencv_ffmpeg300
INCLUDEPATH += -C:\Users\aymane\Downloads\opencv\build\include
