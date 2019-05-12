#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    getJ=false;
    tcp=new tcpclient(4444,"192.168.12.231");
    Gescla=false;
    i=0;

    ui->setupUi(this);
    ui->Element->setVisible(false);
    ui->controle->setVisible(false);
    ui->Mcontrole->setVisible(false);
    ui->groupBox->setVisible(false);
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
    info.setall0();

}

void MainWindow::on_bonus_clicked()
{
    switch(a)
    {
        case 'T':info.settangage(+5);
                tcp->CLConnect(&a,info.gettangage(),i);
                ui->lineEdit->setText(QString::number(info.gettangage()));
                break;
        case 'B':info.setbase(+5);
                tcp->CLConnect(&a,info.getbase(),i);
                ui->lineEdit->setText(QString::number(info.getbase()));
                break;
        case 'C':info.setcoude(+5);
                tcp->CLConnect(&a,info.getcoude(),i);
                ui->lineEdit->setText(QString::number(info.getcoude()));
                break;
        case 'R':info.setroulis(+5);
                tcp->CLSend(&a,info.getroulis(),i);
                ui->lineEdit->setText(QString::number(info.getroulis()));
                break;
        case 'E':info.setepaule(+5);
                tcp->CLSend(&a,info.getepaule(),i);
                ui->lineEdit->setText(QString::number(info.getepaule()));
                break;
    }

}

void MainWindow::on_malus_clicked()
{

   switch(a)
    {
        case 'T':info.settangage(-5);
                tcp->CLSend(&a,info.gettangage(),i);
                ui->lineEdit->setText(QString::number(info.gettangage()));
                break;
        case 'B':info.setbase(-5);
                tcp->CLSend(&a,info.getbase(),i);
                ui->lineEdit->setText(QString::number(info.getbase()));
                break;
        case 'C':info.setcoude(-5);
                tcp->CLSend(&a,info.getcoude(),i);
                ui->lineEdit->setText(QString::number(info.getcoude()));
                break;
        case 'R':info.setroulis(-5);
            tcp->CLSend(&a,info.getroulis(),i);
                ui->lineEdit->setText(QString::number(info.getroulis()));
                break;
        case 'E':info.setepaule(-5);
          //  tcp->CLSend(&a,info.getepaule(),i);
            ui->lineEdit->setText(QString::number(info.getepaule()));
            break;
    }
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    i=value;
     ui->AffVi->display(value);
}

void MainWindow::on_Joy_clicked()
{
    ui->groupBox->setVisible(false);
    getJ=true;
    Gescla=false;
    j=new Joystick(&info, tcp);
    ui->Element->setVisible(false);
    ui->controle->setVisible(false);
    connect(j,SIGNAL(echec( QString  )),this,SLOT(recption( QString )));
}



void MainWindow::on_Posact_clicked()
{
    etat=true;
    //info. setall(tcp);

}

void MainWindow::on_Val_clicked()
{
    ui->groupBox->setVisible(false);
    ui->Element->setVisible(true);
    ui->controle->setVisible(true);
    ui->PiF->setEnabled(false);
    Gescla=false;
    ui->PiO->setEnabled(false);
    if(getJ==true)
    {
        j->~Joystick();
        getJ=false;
    }
}

void MainWindow::on_Base_clicked()
{
    ui->PiF->setEnabled(false);
    ui->PiO->setEnabled(false);
    ui->envoyer->setEnabled(true);
    ui->malus->setEnabled(true);
    ui->bonus->setEnabled(true);
    ui->lineEdit->setEnabled(true);
    a='B';
    if(etat)
    {
        ui->lineEdit->setText(QString::number(info.getbase()));
    }else
    {
         ui->lineEdit->setText(QString::number(0));
    }
}

void MainWindow::on_epaule_clicked()
{
    ui->PiF->setEnabled(false);
    ui->PiO->setEnabled(false);
    ui->envoyer->setEnabled(true);
    ui->malus->setEnabled(true);
    ui->bonus->setEnabled(true);
    ui->lineEdit->setEnabled(true);
    a='E';
    if(etat)
    {
        ui->lineEdit->setText(QString::number(info.getepaule()));
    }else
    {
         ui->lineEdit->setText(QString::number(0));
    }
}

void MainWindow::on_coude_clicked()
{
    ui->PiF->setEnabled(false);
    ui->PiO->setEnabled(false);
    ui->envoyer->setEnabled(true);
    ui->malus->setEnabled(true);
    ui->bonus->setEnabled(true);
    ui->lineEdit->setEnabled(true);
    a='C';
    if(etat)
    {
        ui->lineEdit->setText(QString::number(info.getcoude()));
    }else
    {
         ui->lineEdit->setText(QString::number(0));
    }
}

void MainWindow::on_tangage_clicked()
{
    ui->PiF->setEnabled(false);
    ui->PiO->setEnabled(false);
    ui->envoyer->setEnabled(true);
    ui->malus->setEnabled(true);
    ui->bonus->setEnabled(true);
    ui->lineEdit->setEnabled(true);
    a='T';
    if(etat)
    {
        ui->lineEdit->setText(QString::number(info.gettangage()));
    }else
    {
         ui->lineEdit->setText(QString::number(0));
    }
}

void MainWindow::on_roulis_clicked()
{
    ui->PiF->setEnabled(false);
    ui->PiO->setEnabled(false);
    ui->envoyer->setEnabled(true);
    ui->malus->setEnabled(true);
    ui->bonus->setEnabled(true);
    ui->lineEdit->setEnabled(true);
    a='R';
    if(etat)
    {
        ui->lineEdit->setText(QString::number(info.getroulis()));
    }else
    {
         ui->lineEdit->setText(QString::number(0));
    }
}

void MainWindow::on_pince_clicked()
{
    ui->PiF->setEnabled(true);
    ui->PiO->setEnabled(true);
    ui->envoyer->setEnabled(false);
    ui->malus->setEnabled(false);
    ui->bonus->setEnabled(false);
    ui->lineEdit->setEnabled(false);
    a='P';
    if(etat)
    {
        if(info.getpince())
        {
            ui->PiF->setEnabled(true);
            ui->PiF->setEnabled(false);

        }else{
            ui->PiF->setEnabled(false);
            ui->PiF->setEnabled(true);
        }
    }
}

void MainWindow::on_envoyer_clicked()
{
    /*switch(a)
    {
        case t:tcp->ServSend(a,info.gettangage());
        case b:tcp->ServSend(a,info.getbase());
        case c:tcp->ServSend(a, info.getcoude());
        case r:tcp->ServSend(a,info.getroulis());
        case e:tcp->ServSend(a,info.getepaule());
    }*/


}
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    ui->groupBox->setVisible(true);
   /* //if(event->key() == Qt::Key_Up)
        QMessageBox::information(this, "o.o", "Touche haut pressée!"+event->text());
    if(event->key() == Qt::Key_Down)
        QMessageBox::information(this, "o.o", "Touche bas pressée!");*/

    if(Gescla==true)
    {
        const char*l;
        if(event->text()=="T"||event->text()=="B"||event->text()=="C"||event->text()=="R"||event->text()=="E")
        {
            l=event->text().toStdString().c_str();
            a=*l;
            QMessageBox::information(this, "o.o", "Touche pressée : " + QString(a));
        }
        else if((a=='T'||a=='B') && event->text() == "D")
        {
            if(a=='B')
            {
                //QMessageBox::information(this, "o.o", "Touche haut pressée! ok okokok B");
                info.setbase(-10);
                tcp->CLSend(&a,info.getbase(),i);
            }else{
                info.settangage(-10);
                tcp->CLSend(&a,info.gettangage(),i);
            }
        }
        else if((a=='T'||a=='B') && event->text() == "Q")
        {
            if(a=='B')
            {

                info.setbase(+10);
                tcp->CLSend(&a,info.getbase(),i);
            }else{
                info.settangage(+10);
                tcp->CLSend(&a,info.gettangage(),i);
            }
        }
        else if((a=='C'||a=='R'||a=='E')&& event->text() == "Z")
        {
            if(a=='C')
            {
                //QMessageBox::information(this, "o.o", "Touche haut pressée! ok okokok B");
               //printf("C+ haut");
                info.setcoude(+10);
                tcp->CLSend(&a,info.getcoude(),i);
            }else if(a=='R'){
                info.setroulis(+10);
                tcp->CLSend(&a,info.getroulis(),i);
            }else{info.setepaule(+10);
                tcp->CLSend(&a,info.getepaule(),i); }

        }
        else if(a=='C'||a=='R'||a=='E' && event->text() == "S")
        {
            if(a=='C')
            {
               // QMessageBox::information(this, "o.o", "Touche haut pressée! ok okokok B");
                info.setcoude(-10);
                tcp->CLSend(&a,info.getcoude(),i);
            }else if(a=='R'){
                info.setroulis(-10);
                tcp->CLSend(&a,info.getroulis(),i);
            }else{info.setepaule(-10);
                tcp->CLSend(&a,info.getepaule(),i); }
        }
        else if(event->key()==Qt::Key_Space)
        {
            if(info.getpince()==true)
            {
                info.setpince(false);
                tcp->CLSend(&a,0,i);
            }else{
                info.setpince(true);
                tcp->CLSend(&a,180,i);
            }
        }
       }
    /*

    if(event->key() == Qt::Key_Up)
        QMessageBox::information(this, "o.o", "Touche haut pressée!");
    if(event->key() == Qt::Key_Down)
        QMessageBox::information(this, "o.o", "Touche bas pressée!");*/
}


void MainWindow::on_radioButton_clicked()
{
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

}

void MainWindow::on_PiF_clicked()
{

}

void MainWindow::on_PiO_clicked()
{

}

void MainWindow::on_Camera_clicked()
{
    v=new CvCam();
}
