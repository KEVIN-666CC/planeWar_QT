#ifndef HELPWIDGET_H
#define HELPWIDGET_H

#include <QWidget>
#include <QIcon>
#include <QBrush>
#include <QLabel>
#include <QPushButton>
#include <QFont>
#include <QVBoxLayout>

class helpWidget : public QWidget
{
    Q_OBJECT
public:
    explicit helpWidget(QWidget *parent = nullptr);
private:
     QLabel *label;
     QLabel *label1;
     QLabel *label2;
     QLabel *label3;
     QPushButton *returnbtn;
     QVBoxLayout *vboxlayout;


public slots:
    void returnbtnclick();//槽函数

};

#endif // HELPWIDGET_H
