#ifndef SAUVEGARDE_H
#define SAUVEGARDE_H
#include <QCoreApplication>
#include <QFile>
#include <QDataStream>
#include <QString>
#include <QDebug>
#include <QThread>
#include "tcpsocket.h"
class sauvegarde:public QThread
{
    Q_OBJECT
private:
    QFile f;
public:
    sauvegarde();
    ~sauvegarde();
    void load( );

    void Save(char* b, int a, int vitesse);
signals:
     void env(const QString );
};

#endif // SAUVEGARDE_H
