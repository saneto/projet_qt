#include "cvcam.h"

CvCam::CvCam()
{
    camera=cvCaptureFromFile("http://192.168.12.200/mjpg/video.mjpg");
    if(camera==NULL)
    {
      //  emit this->cameraEchoue("Aucun camera connecter");
    }
    else{
        this->run();
    }
}
void CvCam::run()
{


        // Create a window in which the captured images will be presented
        cvNamedWindow("img", CV_WINDOW_AUTOSIZE);
        while (cvWaitKey(10)!=atoi("q")){
            double t1=(double)cvGetTickCount();
            img=cvQueryFrame(camera);
            double t2=(double)cvGetTickCount();
            printf("time: %gms  fps: %.2g\n",(t2-t1)/(cvGetTickFrequency()*1000.), 1000./((t2-t1)/(cvGetTickFrequency()*1000.)));
            cvShowImage("img",img);

        }
        cvReleaseCapture(&camera);
         cvDestroyWindow( "img" );

}
void CvCam::fin()
{

    this->quit();

}

CvCam::~CvCam()
{

}

