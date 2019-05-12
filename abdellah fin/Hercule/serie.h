#ifndef SERIE_H
#define SERIE_H
#include "windows.h"
#include <QString>
class serie
{
public:
    serie();
    ~serie();
    void debut(QString envoi);
private:
    LPDCB dcb;
    HANDLE desc;
    BOOL res;

};

#endif // SERIE_H
