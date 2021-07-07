#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QPainter>
#include <QPixmap>
#include <QImage>
#include <Qpaintevent>
#include <choose.h>
#include <QLabel>
#include <helpwidget.h>
class Widget : public QWidget
{
    Q_OBJECT
    QPushButton *startGame;
    QPushButton *quit;
    QImage* background;
    QLabel* label;
    QPushButton* Help;
    //paintEvent(QPaintEvent *event);
public slots:
    void startClick();
    void quitClick();
    void HelpClick();

public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
