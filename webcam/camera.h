#ifndef CAMERA_H
#define CAMERA_H

#include <QDialog>
#include <QCamera>
#include <QCameraImageCapture>
#include <QMediaRecorder>
#include <QMainWindow>

namespace Ui { class Camera; }

class Camera : public QMainWindow
{
    Q_OBJECT

public:
    Camera(QWidget *parent = 0);
    ~Camera();

private slots:
    void setCamera(const QCameraInfo &cameraInfo);

    void startCamera();
    void stopCamera();

    void record();
    void pause();
    void stop();

    void updateCameraDevice(QAction *action);
    void displayViewfinder();

protected:
    void closeEvent(QCloseEvent *event);

private:
    Ui::Camera *ui;
    QCamera *camera;
    QMediaRecorder* mediaRecorder;
    bool isCapturingImage;
    bool applicationExiting;
};
#endif // CAMERA_H
