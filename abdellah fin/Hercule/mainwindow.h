#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "../Hercule200/serveur.h"
#include "../Hercule200/thread.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Serveur* s;
};

#endif // MAINWINDOW_H
