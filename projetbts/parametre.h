#ifndef PARAMETRE_H
#define PARAMETRE_H
#include <QTcpSocket>
#include <QWidget>
#include <QMainWindow>
#include <QMessageBox>
#include <QHostAddress>
namespace Ui {
class parametre;
}

class parametre : public QWidget
{
    Q_OBJECT

public:
    explicit parametre(QWidget *parent = 0);
    ~parametre();


private slots:
    void on_pushButton_clicked();
    void on_pushButton_5_clicked();

signals:
    void Host(QHostAddress);
    void Came(const QString);
    void Port(quint16);
private:
    QMessageBox *bo;
    bool v1,v2,v3;
    QString Ac;
    QHostAddress as;
    quint16 po;
    Ui::parametre *ui;
};

#endif // PARAMETRE_H
