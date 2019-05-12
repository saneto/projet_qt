#include "mycamerawindow.h"
#include "ui_mycamerawindow.h"

MyCameraWindow::MyCameraWindow(CvCapture *cam, QWidget *parent) : QWidget(parent) {
    camera = cam;
    QHBoxLayout *layout = new QHBoxLayout;
    cvwidget = new QOpenCVWidget(this);
    label = new QLabel("image");

    layout->addWidget(cvwidget);
    layout->addWidget(label);

    setLayout(layout);
    //resize(100, 100);
    //label->setFixedSize(300, 300);

    startTimer(100);  // 0.1-second timer

 }

void MyCameraWindow::timerEvent(QTimerEvent*) {
    IplImage *image=cvQueryFrame(camera);
    cvwidget->putImage(image);
}




QImage MyCameraWindow::getLabel()
{
    return label->pixmap()->toImage();
}
