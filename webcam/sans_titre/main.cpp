#include "mycamerawindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyCameraWindow w;
    w.show();

    return a.exec();
}
