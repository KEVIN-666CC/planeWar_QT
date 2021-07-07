#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QIcon>
#include <QBrush>
#include <QLabel>
#include <QPushButton>
#include <QFont>
#include <QVBoxLayout>
#include "mainscene.h"
#include "helpwidget.h"
#include <QMessageBox>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    QLabel *label;
    QPushButton *startbtn;
    QPushButton *helpbtn;
    QPushButton *quitbtn;
    QVBoxLayout *vboxlayout;
public slots:
    void startbtnclick();//槽函数
    void helpbtnclick();
    void quitbtnclick();

};
#endif // WIDGET_H
