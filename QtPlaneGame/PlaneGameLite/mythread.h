#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QWidget>
#include <QThread>

class MyThread : public QWidget
{
    Q_OBJECT
public:
    explicit MyThread(QWidget *parent = nullptr);
    void dicked();
protected:
    void run();
signals:
    void isDone();
};

#endif // MYTHREAD_H
