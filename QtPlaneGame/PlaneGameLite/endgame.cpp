#include "endgame.h"
#include "config.h"
#include "mainscene.h"
#include "heroplane.h"
#include <iostream>
EndGame::EndGame(QWidget *parent) : QWidget(parent)
{
    this->parent=parent;
    this->setAttribute(Qt::WA_DeleteOnClose,true);//当窗口关闭时，销毁窗口对象，释放内存
    this->setFixedSize(GAME_WIDTH,GAME_HEIGHT);//设置窗口大小
    this->setWindowTitle("GAME OVER");//设置窗口标题
    this->setWindowIcon(QIcon(GAME_ICON));//设置窗口图标

    QPalette palette;//调色板
    palette.setColor(QPalette::Background,Qt::black);
    this->setPalette(palette);

    //标签初始化
    this->label1=new QLabel(this);
    label1->setText("G A M E   O V E R");
    label1->setFont(QFont("Algerian",24));
    label1->setStyleSheet("QLabel{background:transparent;color:white}");
    this->label2=new QLabel(this);
    label2->setText("游     戏       结      束");
    label2->setFont(QFont("Algerian",20));
    label2->setStyleSheet("QLabel{background:transparent;color:white}");

    //添加按钮
    this->rtnMenubtn = new QPushButton(this);
    rtnMenubtn->setIcon(QIcon(RETURN_MENU_BTN));
    rtnMenubtn->setIconSize(QSize(600,200));
    rtnMenubtn->setFlat(true);
    rtnMenubtn->setFocusPolicy(Qt::NoFocus);


    this->exitbtn = new QPushButton(this);
    exitbtn->setIcon(QIcon(EXIT_BTN));
    exitbtn->setIconSize(QSize(600,200));
    exitbtn->setFlat(true);
    exitbtn->setFocusPolicy(Qt::NoFocus);


    //创建垂直布局对象
    vboxlayout=new QVBoxLayout(this);
    vboxlayout->addWidget(label1);
    vboxlayout->addWidget(label2);
    vboxlayout->addWidget( rtnMenubtn);
    vboxlayout->addWidget(exitbtn);
    vboxlayout->setAlignment(Qt::AlignCenter);//设置对齐方式
    this->connect(rtnMenubtn,SIGNAL(clicked()),this,SLOT(rtnMenubtnclick()));
    this->connect(exitbtn,SIGNAL(clicked()),this,SLOT(exitbtnclick()));
}

void EndGame::rtnMenubtnclick()
{
    this->close();
}

void EndGame::exitbtnclick()
{

    if( QMessageBox::Yes==QMessageBox::question(this,"提示","是否确定要退出？",QMessageBox::Yes|QMessageBox::No)){
     this->parent->close();
     }
}
