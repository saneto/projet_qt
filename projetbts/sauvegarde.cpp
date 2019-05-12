#include "sauvegarde.h"

sauvegarde::sauvegarde()
{
    QFile f("sauvegarde.txt");
   if(f.exists())
   {
       f.open(QIODevice::WriteOnly);
   }
}

sauvegarde::~sauvegarde()
{

}

void sauvegarde::Save(char* b, int a, int vitesse)
{
    f.setFileName("sauvegarde.txt");
    if(!f.open(QIODevice::Append))
    {
        qDebug() << "Could not open "  ;
        return;
    }
    QTextStream out(&f);
    if(a>=0)
    {
        out<<"L "<<b<<"+"<<a<<":"<<vitesse<<"\n";
    }else{
        out<<"L "<<b<<a<<":"<<vitesse<<"\n";
    }
    f.flush();
    f.close();
}

void sauvegarde::load( )
{
    f.setFileName("sauvegarde.txt");
    if(!f.open(QIODevice::ReadOnly))
    {
        qDebug() << "Could not open " ;
        return;
    }
    QString reception;
    QTextStream  in(&f);
    while(!in.atEnd())
    {
       if((reception=in.readLine())==" ")
       {

       }else{
           emit this->env(reception);
            //sleep(1);
       }



    }


    f.close();

}
