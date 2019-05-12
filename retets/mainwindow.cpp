#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <QMessageBox>
#include <QObject>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
 //F.show();
    j=new joystick();
    j->start();
    connect(j, SIGNAL(connection(QString)),this, SLOT(showResponse(QString)));
    connect(j, SIGNAL(ok(QString)),this, SLOT(showResponse2(QString)));
}

void MainWindow::on_pushButton_2_clicked()
{
  //  F.destroyed();
    j->~joystick();
}

void MainWindow::showResponse(const QString &a)
{
    QMessageBox::information(this, "Titre de la fenêtre", "Bonjour et bienvenueà tous les Zéros !");


    ui->label->setText(a);
}
void MainWindow::showResponse2(const QString &a)
{

 ui->label->setText(a);
}
