#include "joystick.h"
#include "windows.h"
Joystick::Joystick(information *a,tcpclient *rep)
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
        this->tc=rep;
        cnt = 0;
        cur_b = 0;
        cur_x = 0;
        cur_y = 0;
        cur_z = 0;
        cur_r = 0;
        cur_u = 0;
        cur_v = 0;
        cur_h = 0;

        old_b = 0;
        old_x = 0;
        old_y = 0;
        old_z = 0;
        old_r = 0;
        old_u = 0;
        old_v = 0;
        old_h = 0;
        this->start();
    }
}

Joystick::~Joystick()
{

}

void Joystick::run()
{

    while (keeprunning)
    {
        lastJoyState.dwSize=sizeof(lastJoyState);//enregistre les positions 0 du joystick
        lastJoyState.dwFlags=JOY_RETURNALL | JOY_RETURNPOVCTS | JOY_RETURNCENTERED | JOY_USEDEADZONE;
        {
            const int MID_VALUE=(int)(USHRT_MAX/2);
            const unsigned int naxes = jc.wNumButtons;
            const unsigned int nbuts= jc.wNumAxes ;

            while(keeprunning)
            {
                if (joyGetPosEx(JOYSTICKID1, &lastJoyState) != JOYERR_NOERROR)
                {
                    m->setText("joystick deconnecter");
                    m->exec();
                    break; // exit to the outer loop and check for a new joystick connection
                }
                // retour =0;
                old_b = cur_b;
                old_x = cur_x;
                old_y = cur_y;
                old_z = cur_z;
                old_r = cur_r;
                old_u = cur_u;
                old_v = cur_v;
                old_h = cur_h;

                cur_b = lastJoyState.dwButtons;
                cur_x = (int)(lastJoyState.dwXpos)-MID_VALUE;
                cur_y = (int)(lastJoyState.dwYpos)-MID_VALUE;
                cur_z = (int)(lastJoyState.dwZpos)-MID_VALUE;
                cur_r = (int)(lastJoyState.dwRpos)-MID_VALUE;
                cur_u = (int)(lastJoyState.dwUpos)-MID_VALUE;
                cur_v = (int)(lastJoyState.dwVpos)-MID_VALUE;
                cur_h = lastJoyState.dwPOV;

                cnt++;
                if (cnt>45||cur_b!=old_b||cur_x!=old_x||cur_y!=old_y||cur_z!=old_z||cur_r!=old_r||cur_u!=old_u||cur_v!=old_v)//compare les positions actuelle du robot avec les positions 0
                {
                    // fprintf(stdout, "%1d", !!(cur_b&0x020));

                    if(cur_b&0x001)
                    {
                       *E='P';
                        if(i->getpince())
                        {
                           tc->CLSend(E,180,15);
                        }else{ tc->CLSend(E,0,15);
                        }
                    }
                    else if(cur_b&0x002)
                    {
                        this->elem='C';
                    }else if(cur_b&0x004)
                    {
                        this->elem='R';
                    }else if(cur_b&0x008)
                    {
                        this->elem='T';
                    }else if(cur_b&0x010)
                    {
                        this->elem='E';
                    }else if(cur_b&0x020)
                    {
                         this->elem='B';
                    }
                      if((elem=='B')&&(cur_x<0))
                        {
                           i->setbase(-10);
                           tc->CLSend(&elem,i->getbase(),15);
                        }else if((elem=='T')&&(cur_x<0))
                        {
                            i->settangage(-10);
                           tc->CLSend(&elem, i->gettangage(),15);
                        }else if((elem=='B')&&(cur_x>0))
                        {
                          i->setbase(+10);
                           tc->CLSend(&elem,i->getbase(),15);
                        }else if((elem=='T')&&(cur_x>0))
                        {
                          i->settangage(+10);
                          tc->CLSend(&elem, i->gettangage(),15);
                        }else if((elem=='C')&&(cur_y<0))
                        {
                          i->setcoude(-10);
                          tc->CLSend(&elem, i->getcoude(),15);
                        }else if((elem=='R')&&(cur_y<0))
                        {
                            i->setroulis(-10);
                             tc->CLSend(&elem, i->getroulis(),15);
                         }else if((elem=='E')&&(cur_y<0))
                        {
                          i->setepaule(-10);
                            tc->CLSend(&elem, i->getepaule(),15);
                        }else if((elem=='C')&&(cur_y>0))
                        {
                          i->setcoude(+10);
                          tc->CLSend(&elem, i->getcoude(),15);
                         }else if((elem=='R')&&(cur_y>0))
                         {
                          i->setroulis(+10);
                           tc->CLSend(&elem, i->getroulis(),15);
                         }else if((elem=='E')&&(cur_y>0))
                         {
                          i->setepaule(+10);
                            tc->CLSend(&elem, i->getepaule(),15);
                         }

                    Sleep(1000); // wait at least 100ms before the next output
                    // fprintf(stdout, "%1d", !!(cur_b&0x020));
                    cnt=0;
                }
                if (cur_b==15)
                {
                    m->setText("Fin du programme");
                    m->exec();
                    keeprunning=0;
                    break;

                }
            }
            Sleep(1500); // wait 10ms between checks for the next sample
        }
    }
}

/* fprintf(stdout, "B: ");
 fprintf(stdout, "%1d", !!(cur_b&0x200)); // or check if ==0 or !=0 inside an IF statement...
 fprintf(stdout, "%1d", !!(cur_b&0x100));
 fprintf(stdout, "%1d", !!(cur_b&0x080));
 fprintf(stdout, "%1d", !!(cur_b&0x040));
 fprintf(stdout, "%1d", !!(cur_b&0x020));
 fprintf(stdout, "%1d", !!(cur_b&0x010));
 fprintf(stdout, "%1d", !!(cur_b&0x008));
 fprintf(stdout, "%1d", !!(cur_b&0x004));
 fprintf(stdout, "%1d", !!(cur_b&0x002));
 fprintf(stdout, "%1d", !!(cur_b&0x001));
 if (naxes>0) fprintf(stdout, " X: %7d", cur_x);
 if (naxes>1) fprintf(stdout, " Y: %7d", cur_y);
 if (naxes>2) fprintf(stdout, " Z: %7d", cur_z);
 if (naxes>3) fprintf(stdout, " R: %7d", cur_r);
 if (naxes>4) fprintf(stdout, " U: %7d", cur_u);
 if (naxes>5) fprintf(stdout, " V: %7d", cur_v);
 if (naxes>6) fprintf(stdout, " more skipped");
 if (cur_h<=36000) fprintf(stdout, " POW:  %7d" , cur_h);
 fprintf(stdout, "\n");*/
