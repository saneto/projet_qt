#include "hercule.h"
#include "ui_hercule.h"

Hercule::Hercule(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Hercule)
{
    ui->setupUi(this);
}

Hercule::~Hercule()
{
    delete ui;
}

void Hercule::on_pushButton_clicked()
{
    strcpy(envoi," B");
}

void Hercule::on_pushButton_9_clicked()
{

    //char envoi[50]="L B+0:20 C-200:25 \x0A";
    strcpy();
            if((res =WriteFile(desc, txt , nb , (LPDWORD)&nbecr , NULL))==false)
}
