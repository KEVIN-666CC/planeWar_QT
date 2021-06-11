#include "mythread.h"
#include"QMessageBox"
#include"dickmenu.h"

MyThread::MyThread(QObject *parent) : QThread(parent)
{
    connect(this,&MyThread::isDone,this,&MyThread::dicked);
}

void MyThread::run()
{
    sleep(2);
    emit isDone();
}

void MyThread::dicked()
{
    DickMenu *dick;
    dick=new DickMenu;
    dick->show();
}
