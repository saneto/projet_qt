#ifndef HERCULE_H
#define HERCULE_H

#include <QMainWindow>

namespace Ui {
class Hercule;
}

class Hercule : public QMainWindow
{
    Q_OBJECT

public:
    explicit Hercule(QWidget *parent = 0);
    ~Hercule();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::Hercule *ui;
    char envoi[50]="L";
};

#endif // HERCULE_H
