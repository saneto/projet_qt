#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <joystick.h>
#include <QMainWindow>
#include <QObject>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
void popup(const QString &a);
private slots:
    void on_pushButton_clicked();
    void showResponse(const QString &s);
    void showResponse2(const QString &s);
    void on_pushButton_2_clicked();



private:
    Ui::MainWindow *ui;
   joystick *j;
    QDialog*d;
signals:
    void desac();

};

#endif // MAINWINDOW_H
