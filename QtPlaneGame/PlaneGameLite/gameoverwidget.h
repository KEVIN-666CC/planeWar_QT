#ifndef GAMEOVERWIDGET_H
#define GAMEOVERWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include "config.h"
#include <QIcon>
#include <QBrush>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>
class GameOverWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GameOverWidget(QWidget *parent = nullptr);
private:
    QLabel *label;
    QPushButton *returnbtn;
    QPushButton *quitbtn;
    QVBoxLayout *vboxlayout;
public slots:
    void returnbtnclick();//槽函数
    void quitbtnclick();

signals:
    void returnWindow();


};

#endif // GAMEOVERWIDGET_H
