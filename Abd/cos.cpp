#include "cos.h"
#include <stdio.h>
#include <iostream>
using namespace std;
coS::coS()
{


}
int coS::lancement()
{
    dcb= new DCB; //pointeur sur la structure de configuration du port série
    desc=CreateFile(L"com1", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);//le L
    //CreateFile((LPCWSTR)"COM1",GENERIC_READ | GENERIC_WRITE ,0,NULL,OPEN_EXISTING ,FILE_ATTRIBUTE_NORMAL ,0 );
    //acquisition de la configuration actuelle (après ouverture du port )
    if  (desc == INVALID_HANDLE_VALUE)
    {
     cout<<"connection\n";
     return -1;
    }
    res =GetCommState(desc,dcb) ;
    if (res==false) {
        cout<<"le port\n";
        return -2;
    }
    dcb->BaudRate = CBR_9600 ;
    dcb->ByteSize = 8;
    dcb->StopBits = ONESTOPBIT;
    dcb->Parity=NOPARITY;
    //mise à jour d’une nouvelle configuration
    res =SetCommState(desc,dcb);
    if (res==false)
    {
        cout<<"recrée le port\n";
        return -3;
    }
    PurgeComm(desc, PURGE_TXCLEAR);
    PurgeComm(desc, PURGE_RXCLEAR );
}
coS::~coS()
{
    CloseHandle(desc);
}
int coS::ecriture( char* b, int valeur, int vitesse)
{
    char a[4];
    sprintf(a, "%i", valeur);
    char *mess=new char[100];
    strcat(mess,"L");
    strcat(mess," ");
    strcat(mess,b);
    strcat(mess,"+");
    strcat(mess,a);
    strcat(mess,":");
    sprintf(a, "%i", vitesse);
    strcat(mess,a);

    nb = strlen(mess);
    if((res =WriteFile(desc, mess , nb +1 , (LPDWORD)&nbecr , NULL))==false)
        {
          return -1;
        }
    else{
        return 0;
    }
}
