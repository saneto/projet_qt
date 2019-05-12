#ifndef FORM_H
#define FORM_H
#include "joy.h"
#include <QWidget>

namespace Ui {
class Form;
}

class Form : public QDialog
{
    Q_OBJECT

public:
    explicit Form(QDialog *parent = 0);
    ~Form();
private slots:
     void showResponse(const QString &s);
     void on_pushButton_clicked();

private:
    Ui::Form *ui;
     joy*j;
};

#endif // FORM_H
