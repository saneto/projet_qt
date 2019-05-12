#ifndef JOYSTICK_H
#define JOYSTICK_H
#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <QDialog>
#include <QThread>
class joystick:public QThread
{
    Q_OBJECT
public:
    joystick();
    ~joystick();
    void run();
 signals:
    void connection(const QString &z);
    void ok(const QString &z);
};

#endif // JOYSTICK_H
