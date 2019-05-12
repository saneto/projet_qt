#ifndef COS_H
#define COS_H
#include <iostream>
#include <windows.h>
class coS
{
public:
    coS();
    ~coS();
    int lancement();
    int ecriture(char* b, int valeur, int vitesse);
private :
    LPDCB dcb;
    BOOL res;
    HANDLE desc;
    long int nb ;
    long int nbecr;
    DWORD ErrorMask;
    COMSTAT comstat;
    DWORD nblus ;
};

#endif // COS_H
