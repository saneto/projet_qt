#ifndef TCPSOCKET_H
#define TCPSOCKET_H
#include <QMessageBox>
#include <QDebug>
#include <QTcpSocket>
#include <QObject>
#include <QHostAddress>

class Tcpsocket : public QObject
{
    Q_OBJECT
public:
    explicit Tcpsocket(QObject *parent = 0);
    ~Tcpsocket();
    void testconnection(QHostAddress adresse,quint16 port);
    void Send( char *b, int a, int vitesse);
    void RCV(char *r);
    void send(QString r);
    void Fin();
private:
        QTcpSocket *socket;
    QMessageBox *m;
signals:
    void ErreurDeconnection(const int &);
public slots:
};

#endif // TCPSOCKET_H

