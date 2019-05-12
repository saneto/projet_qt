#ifndef SERIE_H
#define SERIE_H


class serie
{
public:
    serie();
    ~serie();
    void debut();
private:
    LPDCB dcb;
    HANDLE desc;
    BOOL res;

};

#endif // SERIE_H
