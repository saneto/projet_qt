#ifndef MYCAMERAWINDOW_H
#define MYCAMERAWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <C:\Users\aymane\Desktop\opencv\build\include\opencv\cv.h>
#include <C:\Users\aymane\Desktop\opencv\build\include\opencv\highgui.h>
#include <QtGui>
#include <qlabel.h>
#include "opencvwidget.h"

class MyCameraWindow : public QWidget
{
    Q_OBJECT
    private:
        QOpenCVWidget *cvwidget;
        CvCapture *camera;
        QLabel *label;
        QPixmap photo;

    public:
        MyCameraWindow(CvCapture *cam, QWidget *parent=0);
        QImage getLabel();

    protected:
        void timerEvent(QTimerEvent*);
};

#endif // MYCAMERAWINDOW_H
