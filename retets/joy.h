#ifndef JOY_H
#define JOY_H
#include <QDialog>
#include <QThread>
class joy:public QThread
{
    Q_OBJECT
public:
    joy();
    ~joy();
signals:
    void response(const QString &s);
   public:
        void run();

};

#endif // JOY_H
