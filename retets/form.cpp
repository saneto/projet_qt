#include "form.h"
#include "ui_form.h"

Form::Form(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    this->setFixedSize(300,250);
}

Form::~Form()
{
    delete ui;
}
void Form::showResponse(const QString &s)
{
    ui->label->setText(s);
}
void Form::on_pushButton_clicked()
{

}
