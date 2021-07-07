#ifndef ENDGAME_H
#define ENDGAME_H

#include <QWidget>
#include <QIcon>
#include <QBrush>
#include <QLabel>
#include <QPushButton>
#include <QFont>
#include <QVBoxLayout>
#include <QMessageBox>
#include "widget.h"
#include "mainscene.h"


class EndGame : public QWidget
{
    Q_OBJECT
public:
    explicit EndGame(QWidget *parent = nullptr);
private:
    QLabel *label1;
    QLabel *label2;
    QPushButton *rtnMenubtn;
    QPushButton *exitbtn;
    QVBoxLayout *vboxlayout;
    QWidget *parent;
    //Widget *w;
public slots:
    void rtnMenubtnclick();//槽函数
    void exitbtnclick();
};

#endif // ENDGAME_H
