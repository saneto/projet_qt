#include "tcpclient.h"
#include <stdio.h>
tcpclient::tcpclient(unsigned short port,const char* Ip)
{
    WSAStartup(MAKEWORD(2,0), &WSAData);
    if((sock = socket( AF_INET , SOCK_STREAM ,  IPPROTO_TCP))==-1)
    {
       // emit this->Erreur("Erreur socket");
    }
    to.sin_family = AF_INET;
    to.sin_addr.s_addr = inet_addr (Ip);
    to.sin_port = htons(port);
    //this->CLConnect();
}

tcpclient::~tcpclient()
{
    closesocket(sock);
        WSACleanup();
}
void tcpclient::CLConnect(char* b, int a, int vitesse)
{

    if (connect( sock ,(SOCKADDR *)& to , sizeof(to)) == -1 )
    {
        // emit this->Erreur("Erreur connect");
    }
    this->CLSend(b,a,vitesse);
}
void tcpclient::CLSend(char* b, int valeur, int vitesse)
{
    char a[4];
    sprintf(a, "%i", valeur);
    char *mess=new char[100];
    mess[0]='1';
    mess[1]='\0';
    strcat(mess,"L");
    strcat(mess," ");
    strcat(mess,b);
    strcat(mess,"+");
    strcat(mess,a);
    strcat(mess,":");
    sprintf(a, "%i", vitesse);
    strcat(mess,a);
    //printf("ok tout marche");
    if (send( sock ,mess, strlen(mess),0) == -1 )
    {
       // emit this->Erreur("Erreur d'envoi");
    }
   // this->ServRecv();
}
void tcpclient::CLRecv(char *a)
{
    char m[250]="\0";
    if(recv(sock ,m,250,0 ) == -1 )
    {

    }
    a=m;
}



