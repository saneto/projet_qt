#ifndef TCPCLIENT_H
#define TCPCLIENT_H
#include <QObject>
#include<QThread>
#include <winsock2.h>
#include <windows.h>
#include <iostream>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <QTcpSocket>

class tcpclient
{
private:
            WSADATA WSAData;
            SOCKADDR_IN to;
            SOCKET sock;
public:
    tcpclient(unsigned short port,const char* Ip);
    void CLConnect(char* b, int a, int vitesse);
    void CLSend( char* b, int a, int vitesse);
    void CLRecv(char *a);
    ~tcpclient();


};

#endif // TCPCLIENT_H
