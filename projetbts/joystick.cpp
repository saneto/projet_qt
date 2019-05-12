#include "joystick.h"
#include "windows.h"
#include "QtConcurrent/QtConcurrentRun"
#include <QDebug>
Joystick::Joystick(information *a,Tcpsocket* b)
{
    m=new QMessageBox();
    keeprunning = 1;
    if (joyGetNumDevs()==0)//detection présence d'un joystick
    {
        m->setText("Veuillez connecter un joystick");
        m->exec();
    }else if(joyGetDevCaps(JOYSTICKID1, &jc, sizeof(jc))!=JOYERR_NOERROR)//verification de la compatibiliter
    {
         m->setText("Veuillez connecter un joystick compatible");
         m->exec();

    }
    else{
         m->setText("Joystick connecter");
         m->exec();
        this->elem='\0';
        this->i=a;
        cnt = 0;
        cur_b = 0;
        cur_x = 0;
        cur_y = 0;
        tc=b;
        old_b = 0;
        old_x = 0;
        old_y = 0;
    }
}

Joystick::~Joystick()
{
    this->exit();
}

void Joystick::run()
{
    while (keeprunning)
    {
        lastJoyState.dwSize=sizeof(lastJoyState);
        lastJoyState.dwFlags=JOY_RETURNALL | JOY_RETURNPOVCTS | JOY_RETURNCENTERED | JOY_USEDEADZONE;
        {
            const int MID_VALUE=(int)(USHRT_MAX/2);

            while(keeprunning)
            {
                if (joyGetPosEx(JOYSTICKID1, &lastJoyState) != JOYERR_NOERROR)
                {
                    m->setText("joystick deconnecter");
                    m->exec();
                    break;
                }
                old_b = cur_b;
                old_x = cur_x;
                old_y = cur_y;
                cur_b = lastJoyState.dwButtons;
                cur_x = (int)(lastJoyState.dwXpos)-MID_VALUE;
                cur_y = (int)(lastJoyState.dwYpos)-MID_VALUE;
                cnt++;
                if (cnt>45||cur_b!=old_b||cur_x!=old_x||cur_y!=old_y)
                {
                    if(cur_b&0x001)
                    {
                        if(i->getpince())
                        {
                            i->setpince(false);
                            tc->send("L P-511:20");
                        }else{ i->setpince(true);
                            tc->send("L P+511:20");
                        }
                    }
                    else if(cur_b&0x002)
                    {
                        this->elem="C\0";
                    }else if(cur_b&0x004)
                    {
                        this->elem="R\0";
                    }else if(cur_b&0x008)
                    {
                        this->elem="T\0";
                    }else if(cur_b&0x010)
                    {
                        this->elem="E\0";
                    }else if(cur_b&0x020)
                    {
                        this->elem="B\0";
                    }else if(cur_b&0x040)
                    {
                        this->quit();
                    }
                    else if((elem=="B\0")&&(cur_x<0))
                    {
                        i->setbase(-5);
                        tc->Send(elem,i->getbase(),15);
                    }else if((elem=="B\0")&&(cur_x>0))
                    {

                        i->setbase(+5);
                        tc->Send(elem,i->getbase(),15);
                    }else if((elem=="C\0")&&(cur_y<0))
                    {
                        i->setcoude(-5);
                        tc->Send(elem, i->getcoude(),15);
                    }else if((elem=="C\0")&&(cur_y>0))
                    {
                        i->setcoude(+5);
                        tc->Send(elem, i->getcoude(),15);
                    }else if((elem=="R\0")&&(cur_x<0))
                    {
                        i->settangage(-5);
                        tc->Send(elem, i->gettangage(),15);
                    }else if((elem=="R\0")&&(cur_x>0))
                    {
                        i->settangage(+5);
                        tc->Send(elem, i->gettangage(),15);
                    }else if((elem=="C\0")&&(cur_y<0))
                    {
                        i->setcoude(-5);
                        tc->Send(elem, i->getcoude(),15);
                    }else if((elem=="C\0")&&(cur_y>0))
                    {
                        i->setcoude(+5);
                        tc->Send(elem, i->getcoude(),15);
                    }else if((elem=="T\0")&&(cur_y<0))
                    {
                        i->setroulis(-5);
                        tc->Send(elem, i->getroulis(),15);
                    }else if((elem=="T\0")&&(cur_y>0))
                    {
                        i->setroulis(+5);
                        tc->Send(elem, i->getroulis(),15);
                    }else if((elem=="E\0")&&(cur_y<0))
                    {
                        i->setepaule(-5);
                        tc->Send(elem, i->getepaule(),15);
                    }else if((elem=="E\0")&&(cur_y>0))
                    {
                        i->setepaule(+5);
                        tc->Send(elem, i->getepaule(),15);
                    }
                    Sleep(500);
                   }
            }
        }
    }
}

void Joystick::FaiTh()
{
    qDebug()<<"Fin thread";
    tc->deleteLater();
    this->destroyed();
    this->exit();
}
