#include "cvcam.h"
#include<QMessageBox>
CvCam::CvCam(const QString Flux)
{
    QMessageBox *m=new QMessageBox();

    camera=cvCaptureFromFile(Flux.toStdString().c_str());
    if(camera==NULL)
    {
        m->setText("Aucune camera connecter");
        m->exec();
    }else{
        m->setText("Pour fermer la caméra appuyer sur la touche 'q'");
        m->exec();
        this->run();
    }
}
void CvCam::run()
{
        cvNamedWindow("img", CV_WINDOW_AUTOSIZE);
        while (cvWaitKey(10)!='Q'){
            img=cvQueryFrame(camera);
            cvShowImage("img",img);
        }
        cvReleaseCapture(&camera);
        cvDestroyWindow( "img" );

}
CvCam::~CvCam()
{

}

