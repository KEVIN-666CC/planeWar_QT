#include "gameoverwidget.h"
#include <QDebug>
GameOverWidget::GameOverWidget(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(GAME_WIDTH,GAME_HEIGHT);//设置窗口大小
    this->setWindowTitle("游戏失败");//设置窗口标题
    this->setWindowIcon(QIcon(GAME_ICON));//设置窗口图标

        QPalette palette;//调色板
        palette.setColor(QPalette::Background,Qt::white);
        //palette.setBrush(QPalette::Background,QBrush(QPixmap(GAMEOVER_PAGE)));
        this->setPalette(palette);

        //标签初始化
        this->label=new QLabel(this);
        label->setText("G A M E  O V E R ");

        //添加按钮
        this->returnbtn = new QPushButton(this);
        returnbtn->setIcon(QIcon(RETURN_MENU_BTN));
        returnbtn->setIconSize(QSize(400,200));
        returnbtn->setFlat(true);
        returnbtn->setFocusPolicy(Qt::NoFocus);
        this->quitbtn = new QPushButton(this);
           quitbtn->setIcon(QIcon(EXIT_BTN));
           quitbtn->setIconSize(QSize(400,200));
           quitbtn->setFlat(true);
           quitbtn->setFocusPolicy(Qt::NoFocus);
           //创建垂直布局对象
              vboxlayout=new QVBoxLayout(this);
              vboxlayout->addWidget(label);
              vboxlayout->addWidget(returnbtn);

              vboxlayout->addWidget(quitbtn);
              vboxlayout->setAlignment(Qt::AlignCenter);//设置对齐方式

}
