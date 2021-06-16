#include "widget.h"
#include"config.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setAttribute(Qt::WA_DeleteOnClose,true);//当窗口关闭时，销毁窗口对象，释放内存
    this->setFixedSize(GAME_WIDTH,GAME_HEIGHT);//设置窗口大小
    this->setWindowTitle(GAME_TITLE);//设置窗口标题
    this->setWindowIcon(QIcon(GAME_ICON));//设置窗口图标

    QPalette palette;//调色板
    palette.setBrush(QPalette::Background,QBrush(QPixmap(START_PAGE)));
    this->setPalette(palette);

    //标签初始化
    this->label=new QLabel(this);
    label->setPixmap(QPixmap(GAME_BIG_NAME));
    //添加按钮
    this->startbtn = new QPushButton(this);
    startbtn->setIcon(QIcon(START_BTN));
    startbtn->setIconSize(QSize(600,200));
    startbtn->setFlat(true);
    startbtn->setFocusPolicy(Qt::NoFocus);

    this->helpbtn = new QPushButton(this);
    helpbtn->setIcon(QIcon(HELP_BTN));
    helpbtn->setIconSize(QSize(600,200));
    helpbtn->setFlat(true);
    helpbtn->setFocusPolicy(Qt::NoFocus);


    this->quitbtn = new QPushButton(this);
    quitbtn->setIcon(QIcon(QUIT_BTN));
    quitbtn->setIconSize(QSize(600,200));
    quitbtn->setFlat(true);
    quitbtn->setFocusPolicy(Qt::NoFocus);


    //创建垂直布局对象
    vboxlayout=new QVBoxLayout(this);
    vboxlayout->addWidget(label);
    vboxlayout->addWidget(startbtn);
    vboxlayout->addWidget(helpbtn);
    vboxlayout->addWidget(quitbtn);
    vboxlayout->setAlignment(Qt::AlignCenter);//设置对齐方式
    this->connect(startbtn,SIGNAL(clicked()),this,SLOT(startbtnclick()));
    this->connect(helpbtn,SIGNAL(clicked()),this,SLOT(helpbtnclick()));
    this->connect(quitbtn,SIGNAL(clicked()),this,SLOT(quitbtnclick()));


}

Widget::~Widget()
{
}

void Widget::startbtnclick()
{

     MainScene *m= new MainScene(this);
     m->show();
}

void Widget::helpbtnclick()
{
    helpWidget *h=new helpWidget(this);
    h->show();
}

void Widget::quitbtnclick()
{
   if( QMessageBox::Yes==QMessageBox::question(this,"提示","是否确定要退出？",QMessageBox::Yes|QMessageBox::No)){

    this->close();
    }
}

