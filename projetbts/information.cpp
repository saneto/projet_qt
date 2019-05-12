#include "information.h"
#include "QtConcurrent/QtConcurrentRun"
information::information()
{
    epaule=0;
    base=0;
    tangage=0;
    roulis=0;
    coude=0;
    pince=true;
}

information::~information()
{

}
/*void information::setall(Tcpsocket *s)
{

char * rep;
s->RCV(rep);

}*/
void information::setall0()
{

    epaule=0;
    base=0;
    tangage=0;
    roulis=0;
    coude=0;
    pince=true;
}
int information::getepaule()
{
    return epaule;
}
int information::getbase()
{
    return base;
}
int information::gettangage()
{
    return tangage;
}
int information::getroulis()
{
    return roulis;
}
int information::getcoude()
{
    return coude;
}
bool information::getpince()
{
    return pince;
}
void information::setepaule(int e )
{
    epaule+=e;
}
void information::setbase(int b)
{
    base+=b;
}
void information::settangage(int t)
{
    tangage+=t;
}
void information::setroulis(int r)
{
    roulis+=r;
}
void information::setcoude(int c)
{
    coude+=c;
}
void information:: setpince(bool p)
{
    pince= p;
}
void information::tri(char*a)
{

}

