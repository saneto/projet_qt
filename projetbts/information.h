#ifndef INFORMATION_H
#define INFORMATION_H
#include "tcpsocket.h"
#include "windows.h"
class information
{
public:
    information();
    ~information();
    //void setall(Tcpsocket *s);
    void setall0();
    int getepaule();
    int getbase();
    int gettangage();
    int getroulis();
    int getcoude();
    bool getpince();
    void setepaule(int );
    void setbase(int);
    void settangage(int);
    void setroulis(int);
    void setcoude(int);
    void setpince(bool);
    void tri(char*a);
private:
    char*a;
    int epaule;
    int base;
    int tangage;
    int roulis;
    int coude;
    bool pince;


};

#endif // INFORMATION_H
