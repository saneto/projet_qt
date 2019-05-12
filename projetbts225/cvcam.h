#ifndef CVCAM_H
#define CVCAM_H
#include <C:\Users\aymane\Downloads\opencv\build\include\opencv\cv.h>
#include <C:\Users\aymane\Downloads\opencv\build\include\opencv\highgui.h>
/*#include <C:\Users\Eleve\Desktop\projetbdelouzair\opencv\build\include\opencv\cv.h>
#include <C:\Users\Eleve\Desktop\projetbdelouzair\opencv\build\include\opencv\highgui.h>*/
#include <QWidget>
#include <QThread>
#include <QMainWindow>
#include <QString>
#include <QGuiApplication>

class CvCam: public QThread
{
private :
     CvCapture *camera;
    IplImage *img;
public:
    void run();
    CvCam();
    ~CvCam();
    void fin();
signals:
    void cameraEchoue(QString*);
};

#endif // CVCAM_H
