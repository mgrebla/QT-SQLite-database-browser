#include "mythread.h"

MyThread::MyThread(QObject* parent) : QThread(parent)
{
    connect(this, SIGNAL(nextStep()),SLOT(step()),Qt::QueuedConnection);
}
void MyThread::run(){
    emit nextStep();
    exec();
}

void MyThread::step()
{
    startProgressBar += 1;
    emit progress(startProgressBar);
    qDebug() << startProgressBar;
    QThread::msleep(100);
    if (startProgressBar < 100) {
        emit nextStep();
    }
}
