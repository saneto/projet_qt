#include "joy.h"
#include <windows.h>
#include <stdio.h>
#include <iostream>

joy::joy()
{


this->start();
}

joy::~joy()
{

    this->terminate();
}
void joy::run()
{
emit this->response("ok okokokok");
    short keeprunning = 1;

        while (keeprunning)
        {
            JOYCAPS jc;
            JOYINFOEX lastJoyState;

            if (joyGetNumDevs()==0)
            {
                fprintf(stderr, "Please connect a joystick\n");


                Sleep(500);
                continue;
            }

            if (joyGetDevCaps(JOYSTICKID1, &jc, sizeof(jc))!=JOYERR_NOERROR)
            {
                fprintf(stderr, "Please connect a compatible joystick\n");

                Sleep(1000);
                continue;
            }

            lastJoyState.dwSize=sizeof(lastJoyState);
            lastJoyState.dwFlags=JOY_RETURNALL | JOY_RETURNPOVCTS | JOY_RETURNCENTERED | JOY_USEDEADZONE;

            {
                const unsigned int naxes = jc.wNumAxes;
                const unsigned int nbuts = jc.wNumButtons;
                const int MID_VALUE =(int)(USHRT_MAX/2);

                int cur_b = 0;
                int cur_x = 0;
                int cur_y = 0;
                int cur_z = 0;
                int cur_r = 0;
                int cur_u = 0;
                int cur_v = 0;
                int cur_h = 0;

                int old_b = 0;
                int old_x = 0;
                int old_y = 0;
                int old_z = 0;
                int old_r = 0;
                int old_u = 0;
                int old_v = 0;
                int old_h = 0;

                int cnt = 0;

                while(keeprunning)
                {
                    if (joyGetPosEx(JOYSTICKID1, &lastJoyState) != JOYERR_NOERROR)
                    {
                        fprintf(stderr, "Please reconnect the joystick\n");
                        //cur_b=15;
                        Sleep(60);
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

                    cnt++; // to force display/send every so many samples even if no change

                    if (cnt>45||cur_b!=old_b||cur_x!=old_x||cur_y!=old_y||cur_z!=old_z||cur_r!=old_r||cur_u!=old_u||cur_v!=old_v)
                    {
                       // fprintf(stdout, "B: ");
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
                        fprintf(stdout, "\n");

                        Sleep(10); // wait at least 100ms before the next output
                        cnt=0;
                    }

                    if (cur_b==15)
                    {
                        fprintf(stdout, "End program button sequence initiated\n");
                        keeprunning=0;
                    }
                }

                Sleep(10); // wait 10ms between checks for the next sample
            }
        }
}
