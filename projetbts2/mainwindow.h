#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "information.h"
#include <joystick.h>
#include "cvcam.h"
#include <QMainWindow>
#include <QMessageBox>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Joystick*j;
    int i;
    tcpclient * tcp;
    information info;
    QMessageBox *m;
    bool getJ;
    bool etat;
    char a='\0';
    bool Gescla;
    CvCam * v;
public slots:
  void recption(const QString &a) ;
  void keyPressEvent(QKeyEvent *e);
private slots:
  void on_Pos0_clicked();
  void on_bonus_clicked();
  void on_malus_clicked();
  void on_horizontalSlider_valueChanged(int value);
  void on_Joy_clicked();
  void on_Posact_clicked();
  void on_Souris_clicked();
  void on_Val_clicked();
  void on_Base_clicked();
  void on_epaule_clicked();
  void on_coude_clicked();
  void on_tangage_clicked();
  void on_roulis_clicked();
  void on_pince_clicked();
  void on_envoyer_clicked();
  void on_radioButton_clicked();
  void on_auto_2_clicked();
  void on_PiF_clicked();
  void on_PiO_clicked();
  void on_Camera_clicked();
};

#endif // MAINWINDOW_H
