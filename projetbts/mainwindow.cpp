#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    getJ=false;
    Gescla=true;
    i=1;
    l="\0";
    adresse="192.168.0.102";
    port=1234;
    sock.setParent(0);
    a='\0';
    Adc="http://192.168.12.200/mjpg/video.mjpg";
    ui->setupUi(this);
    Apprentissage=false;
    connect(&Para,SIGNAL(Came(QString)),this,SLOT(AdresseCam(QString)));
    connect(&Para,SIGNAL(Host(QHostAddress)),this,SLOT(AdresseServeur(QHostAddress)));
    connect(&Para,SIGNAL(Port(quint16)),this,SLOT(PortSRV(quint16)));
    this->setWindowTitle("Hercule");
    ui->pushButton_2->setDisabled(true);
    ui->AffVi->display(1);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->Element->setVisible(false);
    ui->controle->setVisible(false);
    ui->Mcontrole->setVisible(false);
    ui->groupBox->setVisible(false);
    ui->choixP->setVisible(false);
}
MainWindow::~MainWindow()
{
    delete ui;
}
 void MainWindow::recption(const QString &a)
 {
    m=new QMessageBox();
    m->setText(a);
    m->exec();

 }

void MainWindow::on_Pos0_clicked()
{
    etat=false;
    ui->Mcontrole->setVisible(true);
    sock.send("RAZ");
    info.setall0();
}

void MainWindow::on_bonus_clicked()
{
    if(a=="B\0")
    {
        info.setbase(+10);
        qDebug()<<a;
        sock.Send(a,info.getbase(),i);
        ui->lineEdit->setText(QString::number(info.getbase()));
     }else if(a=="E\0")
    {
        info.setepaule(+10);
        sock.Send(a,info.getepaule(),i);
        ui->lineEdit->setText(QString::number(info.getepaule()));

    }else if(a=="T\0")
    {
        info.settangage(+10);
        sock.Send(a,info.gettangage(),i);
        ui->lineEdit->setText(QString::number(info.gettangage()));

    }else if(a=="C\0")
    {
        info.setcoude(+10);
        sock.Send(a,info.getcoude(),i);
        ui->lineEdit->setText(QString::number(info.getcoude()));
    }else if(a=="R\0")
    {
        info.setroulis(+10);
        sock.Send(a,info.getroulis(),i);
        ui->lineEdit->setText(QString::number(info.getroulis()));

    }
}

void MainWindow::on_malus_clicked()
{
    if(a=="B\0")
    {
        info.setbase(-10);
        qDebug()<<a;
        sock.Send(a,info.getbase(),i);
        ui->lineEdit->setText(QString::number(info.getbase()));
     }else if(a=="E\0")
    {
        info.setepaule(-10);
        sock.Send(a,info.getepaule(),i);
        ui->lineEdit->setText(QString::number(info.getepaule()));

    }else if(a=="T\0")
    {
        info.settangage(-10);
        sock.Send(a,info.gettangage(),i);
        ui->lineEdit->setText(QString::number(info.gettangage()));

    }else if(a=="C\0")
    {
        info.setcoude(-10);
        sock.Send(a,info.getcoude(),i);
        ui->lineEdit->setText(QString::number(info.getcoude()));
    }else if(a=="R\0")
    {
        info.setroulis(-10);
        sock.Send(a,info.getroulis(),i);
        ui->lineEdit->setText(QString::number(info.getroulis()));

    }

}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    i=value;
     ui->AffVi->display(value);
}

void MainWindow::on_Joy_clicked()
{
    if(Apprentissage)
    {
        Apprentissage=false;
        sock.send("FDS");
    }

    ui->groupBox->setVisible(false);
    getJ=true;
    Gescla=false;
    j=new Joystick(&info,&sock);
    connect(j,SLOT(FaiTh()),this,SIGNAL(FinDJ()));
    j->start();
    ui->Element->setVisible(false);
    ui->controle->setVisible(false);
}
void MainWindow::on_Posact_clicked()
{
    ui->Mcontrole->setVisible(true);
    /*etat=true;
    info. setall(&sock);*/

}

void MainWindow::on_Val_clicked()
{
    ui->groupBox->setVisible(false);
    ui->Element->setVisible(true);
    ui->controle->setVisible(true);
    sock.send("DDS");
    Gescla=false;
    Apprentissage=true;
    emit this->FinDJ();
    if(getJ)
    {
        j->terminate();
        qDebug()<<"terminer";
        getJ=false;
    }
}

void MainWindow::on_Base_clicked()
{

    ui->malus->setEnabled(true);
    ui->bonus->setEnabled(true);
    ui->lineEdit->setEnabled(true);
    ui->lineEdit->setText(QString::number(info.getbase()));
    a="B\0";
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
}

void MainWindow::on_epaule_clicked()
{
    ui->malus->setEnabled(true);
    ui->bonus->setEnabled(true);
    ui->lineEdit->setEnabled(true);
    ui->lineEdit->setText(QString::number(info.getepaule()));
    a="E\0";
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
}

void MainWindow::on_coude_clicked()
{
    ui->malus->setEnabled(true);
    ui->bonus->setEnabled(true);
    ui->lineEdit->setEnabled(true);
    ui->lineEdit->setText(QString::number(info.getcoude()));
    a="C\0";
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
}

void MainWindow::on_tangage_clicked()
{
    ui->malus->setEnabled(true);
    ui->bonus->setEnabled(true);
    ui->lineEdit->setEnabled(true);
    ui->lineEdit->setText(QString::number(info.gettangage()));
    a="T\0";
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_3->setEnabled(false);

}

void MainWindow::on_roulis_clicked()
{
    ui->malus->setEnabled(true);
    ui->bonus->setEnabled(true);
    ui->lineEdit->setEnabled(true);
    ui->lineEdit->setText(QString::number(info.getroulis()));
    a="R\0";
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
}

void MainWindow::on_pince_clicked()
{

    ui->malus->setEnabled(false);
    ui->bonus->setEnabled(false);
    ui->lineEdit->setEnabled(false);
    if(info.getpince())
    {
        ui->pushButton_3->setEnabled(true);
        ui->pushButton_4->setEnabled(false);
    }else{
        ui->pushButton_3->setEnabled(false);
        ui->pushButton_4->setEnabled(true);
    }

}
void MainWindow::keyPressEvent(QKeyEvent *event)
{

    if(Gescla==true)
    {

            if(event->text()=="T")
            {
                a="T\0";
            }else if(event->text()=="B")
            {
                a="B\0";
            }else if(event->text()=="C")
            {
                a="C\0";
            }else if(event->text()=="R")
            {
                a="R\0";
            } else if(event->text()=="E")
            {
                a="E\0";
            }else if((a=="T\0"||a=="B\0") && event->text() == "-")
            {
            if(a=="B\0")
            {
                info.setbase(-10);
                sock.Send(a,info.getbase(),i);
            }else{
                info.settangage(-10);
                sock.Send(a,info.gettangage(),i);
            }
            }
            else if((a=="T\0"||a=="B\0") && event->text() == "+")
            {
            if(a=="B\0")
            {
                info.setbase(+10);
                sock.Send(a,info.getbase(),i);
            }else{
                info.settangage(+10);
                sock.Send(a,info.gettangage(),i);
            }
            }
            else if((a=="C\0"||a=="R\0"||a=="E\0")&& event->text() == "+")
            {
            if(a=="C\0")
            {
                info.setcoude(+10);
                sock.Send(a,info.getcoude(),i);
            }else if(a=="R\0"){
                info.setroulis(+10);
                sock.Send(a,info.getroulis(),i);
            }else{info.setepaule(+10);
                sock.Send(a,info.getepaule(),i); }

            }
            else if((a=="C\0"||a=="R\0"||a=="E\0") && event->text() == "-")
            {
            if(a=="C\0")
            {
                info.setcoude(-10);
                sock.Send(a,info.getcoude(),i);
            }else if(a=="R\0"){
                info.setroulis(-10);
                sock.Send(a,info.getroulis(),i);
            }else{info.setepaule(-10);
                sock.Send(a,info.getepaule(),i); }
            }
            else if(event->text()=="P")
            {

            if(info.getpince()==true)
            {
                info.setpince(false);
                sock.send("L P-511:20");
            }else{

                info.setpince(true);
                sock.send("L P+511:20");
            }
        }
       }
}


void MainWindow::on_radioButton_clicked()
{
     ui->groupBox->setVisible(true);
    if(Apprentissage)
    {
        sock.send("FDS");
        Apprentissage=false;
    }
    Gescla=true;
    if(getJ==true)
    {
        getJ=false;
        j->~Joystick();
    }
    ui->Element->setVisible(false);
    ui->controle->setVisible(false);
}

void MainWindow::on_auto_2_clicked()
{
    ui->Element->hide();
    ui->controle->hide();
    ui->groupBox->hide();
    sock.send("Auto");
}





void MainWindow::Debutco(int retour)
{
    if(retour==-1)
    {
        ui->pushButton_2->setDisabled(true);
        ui->Element->setVisible(false);
        ui->controle->setVisible(false);
        ui->Mcontrole->setVisible(false);
        ui->groupBox->setVisible(false);
        ui->choixP->setVisible(false);
        ui->pushButton->setDisabled(false);
        ui->pushButton->setStyleSheet("background-color: rgb(250,0 , 0,250)");
    }else{

        ui->pushButton_2->setDisabled(false);
        ui->choixP->setVisible(true);
        ui->pushButton->setDisabled(true);
        ui->pushButton->setStyleSheet("background-color: rgb(0, 250, 0,250)");
    }
}

void MainWindow::on_pushButton_clicked()
{
    connect(&sock,SIGNAL(ErreurDeconnection(int)),this,SLOT(Debutco(int)));

   sock.testconnection(adresse,port);

}
void MainWindow::rec(QString e)
{
   sock.send(e);
}


void MainWindow::on_Camera_clicked()
{
    v=new CvCam(Adc);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->pushButton->setEnabled(true);
sock.Fin();
}



void MainWindow::on_pushButton_3_clicked()
{
    info.setpince(true);
    ui->pushButton_4->setEnabled(true);
    ui->pushButton_3->setEnabled(false);
    sock.send("L P+511:20\n");
}

void MainWindow::on_pushButton_4_clicked()
{
    info.setpince(false);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_3->setEnabled(true);
    sock.send("L P-511:20");
}

void MainWindow::on_pushButton_5_clicked()
{
    Para.show();
}
void MainWindow::AdresseCam(const QString er)
{
    Adc=er;
}

void MainWindow::AdresseServeur(QHostAddress h)
{
    qDebug()<<h;
    adresse=h;
    qDebug()<<adresse;
}

void MainWindow::PortSRV(quint16 P2)
{
    port=P2;
}


