#include "camera.h"
#include "ui_camera.h"

#include <QMediaService>
#include <QMediaRecorder>
#include <QCameraViewfinder>
#include <QCameraInfo>
#include <QMediaMetaData>
#include <QMessageBox>
#include <QPalette>
#include <QtWidgets>

Q_DECLARE_METATYPE(QCameraInfo)

Camera::Camera(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Camera),
    camera(0),
    mediaRecorder(0),
    isCapturingImage(false),
    applicationExiting(false)
{
    ui->setupUi(this);

    //recherche des caméras

    QActionGroup *videoDevicesGroup = new QActionGroup(this);
    videoDevicesGroup->setExclusive(true);
    foreach (const QCameraInfo &cameraInfo, QCameraInfo::availableCameras()) {
        QAction *videoDeviceAction = new QAction(cameraInfo.description(), videoDevicesGroup);
        videoDeviceAction->setCheckable(true);
        videoDeviceAction->setData(QVariant::fromValue(cameraInfo));
        if (cameraInfo == QCameraInfo::defaultCamera())
            videoDeviceAction->setChecked(true);
    }
    connect(videoDevicesGroup, SIGNAL(triggered(QAction*)), SLOT(updateCameraDevice(QAction*)));
    setCamera(QCameraInfo::defaultCamera());
}

Camera::~Camera()
{
    delete mediaRecorder;
    delete camera;
}

void Camera::setCamera(const QCameraInfo &cameraInfo)
{
    delete mediaRecorder;
    delete camera;

  camera = new QCamera(cameraInfo);
    mediaRecorder = new QMediaRecorder(camera);
    camera->setViewfinder(ui->viewfinder);
    camera->start();
}
void Camera::record()
{
    mediaRecorder->record();
}

void Camera::pause()
{
    mediaRecorder->pause();
}

void Camera::stop()
{
    mediaRecorder->stop();
}

void Camera::startCamera()
{
    camera->start();
}

void Camera::stopCamera()
{
    camera->stop();
}


void Camera::updateCameraDevice(QAction *action)
{
    setCamera(qvariant_cast<QCameraInfo>(action->data()));
}

void Camera::displayViewfinder()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Camera::closeEvent(QCloseEvent *event)
{
    if (isCapturingImage) {
        setEnabled(false);
        applicationExiting = true;
        event->ignore();
    } else {
        event->accept();
    }
}
