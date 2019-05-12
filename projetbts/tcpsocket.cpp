#include "tcpsocket.h"

Tcpsocket::Tcpsocket(QObject *parent) : QObject(parent)
{
    socket = new QTcpSocket(this);
}

Tcpsocket::~Tcpsocket()
{
    socket->close();
}
void Tcpsocket::testconnection(QHostAddress ad,quint16 p)
{
    ad="192.168.0.105";
    socket->connectToHost(ad,p);
    QMessageBox *m=new QMessageBox();
    if(socket->waitForConnected(900))
    {
        m->setText("La connection avec le serveur a été établie .");
        m->exec();
       socket->write("Master");
       socket->flush();
        emit this->ErreurDeconnection(1);
    }else
    {

        m->setText("Impossible de se connecter au serveur");
        m->exec();
        emit this->ErreurDeconnection(-1);

    }
}

void Tcpsocket::Send(char *b, int a, int vitesse)
{

    if(socket->waitForConnected(900))
    {
      if(a>=0){
            socket->write("L "+QByteArray(b)+"+"+QByteArray::number(a)+":"+QByteArray::number(vitesse)+"\n");
            socket->flush();
         }else{
            socket->write("L "+QByteArray(b)+QByteArray::number(a)+":"+QByteArray::number(vitesse)+"\n");
            socket->flush();
        }

    }else{
        qDebug() << "Error: " << socket->errorString();
        qDebug()<<socket->isOpen();
        emit this->ErreurDeconnection(-1);
    }
}
void Tcpsocket::send(QString r)
{

     if(socket->waitForConnected(900))
    {
        socket->write(r.toUtf8());
        socket->flush();
    }else{
        qDebug() << "Error: " << socket->errorString();
        emit this->ErreurDeconnection(-1);
    }
}
void Tcpsocket::RCV(char *r)
{


    if(socket->waitForConnected(900))
    {
         socket->write("Recup");
         r=new char[socket->bytesAvailable()];
         r=socket->readAll().QByteArray::data();
    }else{
        m->setText("Impossible de lire connexion avec le serveur perdu");
        m->exec();
        emit this->ErreurDeconnection(-1);
    }
}
void Tcpsocket::Fin()
{
    socket->close();
}
