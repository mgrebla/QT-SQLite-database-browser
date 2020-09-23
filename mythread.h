#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QDialog>

#include <QDebug>

#include <QObject>
#include <QThread>

class MyThread : public QThread
{
    Q_OBJECT
    int startProgressBar;

signals:
    void progress(int prog);
    void nextStep();
private slots:
    void step();
public:
    MyThread(QObject* parent = 0);
private:
    void run();
};

#endif // MYTHREAD_H

