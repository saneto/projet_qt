#include "parametre.h"
#include "ui_parametre.h"
#include <QDebug>
parametre::parametre(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::parametre)
{
    ui->setupUi(this);
    bo=new QMessageBox(this);
    ui->lineEdit->setInputMask("000.000.000.000;");
    ui->lineEdit_2->setInputMask("00000;");
    ui->lineEdit_3->setInputMask("000.000.000.000;");

}


parametre::~parametre()
{
    delete ui;
}

void parametre::on_pushButton_clicked()
{
    if(ui->lineEdit->isModified())
    {
        as.setAddress(ui->lineEdit->displayText());
        qDebug()<<as;
        emit this->Host(as);
    }if(ui->lineEdit_2->isModified())
    {
        po=ui->lineEdit_2->displayText().toUInt();
        qDebug()<<po;
        emit this->Port(po);
    }if(ui->lineEdit_3->isModified())
    {
        as.setAddress(ui->lineEdit->displayText());
        qDebug()<<as;
        emit this->Host(as);
    }
}

void parametre::on_pushButton_5_clicked()
{
    this->hide();
}
