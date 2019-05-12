#ifndef JOYSTICK_H
#define JOYSTICK_H
#include "tcpsocket.h"
#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <QThread>
#include <QObject>
#include <QMessageBox>
#include "information.h"
class Joystick:public QThread
{

public:
    Joystick(information *,Tcpsocket* );
    ~Joystick();
    void run();
private:
        QMessageBox* m;
        JOYCAPS jc;
        JOYINFOEX lastJoyState;
        char *elem;
        short keeprunning ;
        int cnt ;
        int cur_b;
        int cur_x;
        int cur_y;
        information* i;
        Tcpsocket *tc;
        int old_b;
        int old_x;
        int old_y;
        QString env;
        char  E;
public slots:
        void FaiTh();
};
#endif // JOYSTICK_H
