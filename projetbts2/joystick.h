#ifndef JOYSTICK_H
#define JOYSTICK_H
#include "tcpclient.h"
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
    Joystick(information *,tcpclient *);
    ~Joystick();
    void run();
private:
        QMessageBox* m;
        JOYCAPS jc;
        JOYINFOEX lastJoyState;
        char elem;
        short keeprunning ;
        int cnt ;
        int cur_b;
        int cur_x;
        int cur_y;
        int cur_z;
        int cur_r;
        int cur_u;
        int cur_v;
        int cur_h;
        information* i;

        int old_b;
        int old_x;
        int old_y;
        int old_z;
        int old_r;
        int old_u;
        int old_v;
        int old_h;
        char *E;
        tcpclient*   tc;
};
#endif // JOYSTICK_H
