#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "information.h"
#include "joystick.h"
#include "cvcam.h"
#include"tcpsocket.h"
#include <QMainWindow>
#include <QMessageBox>
#include "parametre.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
signals:
    void FinDJ();
private:
    bool Apprentissage;
    Ui::MainWindow *ui;
    Joystick*j;
    int i;
    Tcpsocket sock;
    information info;
    QMessageBox *m;
    bool getJ;
    bool etat;
    bool PremiereCo;
    char* a;
    const char*l;
    bool Gescla;
    CvCam * v;
    QString Adc;
    QHostAddress adresse;
    quint16 port;
    parametre Para;
public slots:
  void recption(const QString &a) ;
  void keyPressEvent(QKeyEvent *e);
  void Debutco(const int);
  void rec(const QString);
  void AdresseCam(const QString);
  void AdresseServeur(QHostAddress);
  void PortSRV(quint16);
private slots:
  void on_Pos0_clicked();
  void on_bonus_clicked();
  void on_malus_clicked();
  void on_horizontalSlider_valueChanged(int value);
  void on_Joy_clicked();
  void on_Posact_clicked();
  void on_Val_clicked();
  void on_Base_clicked();
  void on_epaule_clicked();
  void on_coude_clicked();
  void on_tangage_clicked();
  void on_roulis_clicked();
  void on_pince_clicked();
  void on_radioButton_clicked();
  void on_auto_2_clicked();
  void on_Camera_clicked();
  void on_pushButton_clicked();
  void on_pushButton_2_clicked();
  void on_pushButton_3_clicked();
  void on_pushButton_4_clicked();
  void on_pushButton_5_clicked();
};

#endif // MAINWINDOW_H
