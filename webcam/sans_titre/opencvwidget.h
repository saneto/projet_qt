#ifndef OPENCVWIDGET_H
#define OPENCVWIDGET_H
#include <C:\Users\Eleve\Desktop\projetbdelouzair\opencv\build\include\opencv\cv.h>
#include <QPixmap>
#include <QLabel>
#include <QWidget>
#include <QVBoxLayout>
#include <QImage>
class QOpenCVWidget : public QWidget {
    private:
        QLabel *imagelabel;
        QVBoxLayout *layout;

        QImage image;

    public:
        QOpenCVWidget(QWidget *parent = 0);
        ~QOpenCVWidget(void);
        void putImage(IplImage *);
        QImage getImageLabel();
};

#endif // OPENCVWIDGET_H
