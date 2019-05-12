#include "hercule.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Hercule w;
    w.show();

    return a.exec();
}
