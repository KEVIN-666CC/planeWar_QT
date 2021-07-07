#include "mythread.h"

MyThread::MyThread(QWidget *parent) : QWidget(parent)
{
    connect(this,&MyThread::isDone,this,&MyThread::dicked);
}

void MyThread::run()
{
    QThread::sleep(2);
    emit isDone();
}
