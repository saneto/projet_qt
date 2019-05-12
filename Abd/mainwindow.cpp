#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    val[0]=0;
    val[1]=0;
    val[2]=0;
    val[3]=0;
    val[4]=0;
    vitesse=0;
    ui->setupUi(this);
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_7->setEnabled(false);
    ui->pushButton_8->setEnabled(false);
    ui->pushButton_9->setEnabled(false);
    ui->pushButton_10->setEnabled(false);
    ui->pushButton_11->setEnabled(false);
    ui->pushButton_12->setEnabled(false);
    ui->horizontalSlider->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    vitesse=position;
    ui->lcdNumber->display(position);
}

void MainWindow::on_pushButton_13_clicked()
{
    int t =c.lancement();
    if(t<0)
    {
        switch(t)
        {
            case -1:QMessageBox::information(this,"Alerte","Erreur de connection ");
                break;
            case -2:QMessageBox::information(this,"Alerte","Erreur de port ");
                break;
            case -3:QMessageBox::information(this,"Alerte","Erreur de création du port ");
                break;
        }
     }else{
        ui->pushButton->setEnabled(true);
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_3->setEnabled(true);
        ui->pushButton_4->setEnabled(true);
        ui->pushButton_5->setEnabled(true);
        ui->pushButton_6->setEnabled(true);
        ui->pushButton_7->setEnabled(true);
        ui->pushButton_8->setEnabled(true);
        ui->pushButton_9->setEnabled(true);
        ui->pushButton_10->setEnabled(true);
        ui->pushButton_11->setEnabled(true);
        ui->pushButton_12->setEnabled(true);
        ui->horizontalSlider->setEnabled(true);
    }

}

void MainWindow::on_pushButton_14_clicked()
{
    c.~coS();
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_7->setEnabled(false);
    ui->pushButton_8->setEnabled(false);
    ui->pushButton_9->setEnabled(false);
    ui->pushButton_10->setEnabled(false);
    ui->pushButton_11->setEnabled(false);
    ui->pushButton_12->setEnabled(false);
    ui->horizontalSlider->setEnabled(false);
}

void MainWindow::on_pushButton_2_clicked()
{
    M='B';
    this->val[0]-=10;
    c.ecriture(&M,val[0], vitesse);
    ui->lineEdit->setText(QString::number(val[0]));
}

void MainWindow::on_pushButton_clicked()
{
    M='B';
    this->val[0]+=10;
    c.ecriture(&M,val[0], vitesse);
    ui->lineEdit->setText(QString::number(val[0]));
}

void MainWindow::on_pushButton_6_clicked()
{
    M='T';
    this->val[1]-=10;
    c.ecriture(&M,val[0], vitesse);
    ui->lineEdit_2->setText(QString::number(val[1]));
}

void MainWindow::on_pushButton_5_clicked()
{
    M='T';
    this->val[1]+=10;
    c.ecriture(&M,val[0], vitesse);
    ui->lineEdit_2->setText(QString::number(val[1]));
}

void MainWindow::on_pushButton_8_clicked()
{
    M='C';
    this->val[2]-=10;
    c.ecriture(&M,val[0], vitesse);
    ui->lineEdit_3->setText(QString::number(val[2]));
}

void MainWindow::on_pushButton_7_clicked()
{
    M='C';
    this->val[2]+=10;
    c.ecriture(&M,val[0], vitesse);
    ui->lineEdit_3->setText(QString::number(val[2]));
}

void MainWindow::on_pushButton_10_clicked()
{
    M='E';
    this->val[3]-=10;
    c.ecriture(&M,val[3], vitesse);
    ui->lineEdit_4->setText(QString::number(val[3]));
}

void MainWindow::on_pushButton_9_clicked()
{
    M='E';
    this->val[3]+=10;
    c.ecriture(&M,val[3], vitesse);
    ui->lineEdit_4->setText(QString::number(val[3]));
}

void MainWindow::on_pushButton_4_clicked()
{
    M='R';
    this->val[4]-=10;
    c.ecriture(&M,val[3], vitesse);
    ui->lineEdit_5->setText(QString::number(val[4]));
}

void MainWindow::on_pushButton_3_clicked()
{
    M='R';
    this->val[4]+=10;
    c.ecriture(&M,val[3], vitesse);
    ui->lineEdit_5->setText(QString::number(val[4]));
}

void MainWindow::on_pushButton_11_clicked()
{
    M='P';
     c.ecriture(&M,180, 15);
}

void MainWindow::on_pushButton_12_clicked()
{
    M='P';
     c.ecriture(&M,-180, 15);
}
