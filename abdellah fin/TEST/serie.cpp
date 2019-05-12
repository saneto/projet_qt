#include "serie.h"

serie::serie()
{
    LPDCB dcb= new DCB; //pointeur sur la structure de configuration du port série
    // COMSTAT comstat;
    // CString nom(_T());
    HANDLE desc=CreateFile(L"com1", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);//le L
            //CreateFile((LPCWSTR)"COM1",GENERIC_READ | GENERIC_WRITE ,0,NULL,OPEN_EXISTING ,FILE_ATTRIBUTE_NORMAL ,0 );
    //acquisition de la configuration actuelle (après ouverture du port )
    if  (desc == INVALID_HANDLE_VALUE)
    {
         cout<<"erreur d'affichage1\n";
    }
    BOOL res =GetCommState(desc,dcb) ;
    if (res==false) {
        cout<<"erreur d'affichage2\n";
    }
    //construction d’une structure de configuration dela liaison (exemple )
    /* res =BuildCommDCB((LPCWSTR)"COM1: baud=9600 parity=N data=8 stop=1" ,dcb);
    if (res==false) {
        cout<<"erreur d'affichage3\n";
    }*/
    // modificaton possible des champs de la sructure :
    dcb->BaudRate = CBR_9600 ;
    dcb->ByteSize = 8;

    //mise à jour d’une nouvelle configuration
    res =SetCommState(desc,dcb);
    if (res==false) {
        cout<<"erreur d'affichage4\n";
    }
    //purger les buffers d’émission et réception.
    PurgeComm(desc, PURGE_TXCLEAR);
    PurgeComm(desc, PURGE_RXCLEAR );
}

serie::~serie()
{

}

serie::debut()
{
    //envoi de caractères
    char txt[200]="L B+100:20 L C-100:25";//044=$B+100:20
    //int i=5,choix,t;
    long int nb = strlen(txt);
    long int nbecr;
    if((res =WriteFile(desc, txt , nb , (LPDWORD)&nbecr , NULL))==false)
    {
        cout<<"erreur d'affichage \n";
    }
     cout<<"envoi de "<<nbecr<<" caractères\n";
}

