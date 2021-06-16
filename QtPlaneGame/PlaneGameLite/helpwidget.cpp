#include "helpwidget.h"
#include "config.h"
helpWidget::helpWidget(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(GAME_WIDTH,GAME_HEIGHT);//设置窗口大小
    this->setWindowTitle("PlaneGame");//设置窗口标题
    this->setAutoFillBackground(true);//让屏幕显示时能盖过另一个窗体
    this->setWindowIcon(QIcon(GAME_ICON));//设置窗口图标

    QPalette palette;//调色板
    palette.setBrush(QPalette::Background,QBrush(QPixmap(HELP_PAGE)));
    this->setPalette(palette);
    //标签初始化
    this->label=new QLabel(this);
    label->setPixmap(QPixmap(GAME_INTRO1));

    this->label1=new QLabel(this);
    label1->setPixmap(QPixmap(GAME_INTRO2));

    this->label2=new QLabel(this);
     label2->setPixmap(QPixmap(GAME_INTRO3));

    this->label3=new QLabel(this);
     label3->setPixmap(QPixmap(GAME_INTRO4));


    //添加按钮
    this->returnbtn = new QPushButton(this);
    returnbtn->setIcon(QIcon(RETURN_BTN));
    returnbtn->setIconSize(QSize(600,200));
    returnbtn->setFlat(true);
    returnbtn->setFocusPolicy(Qt::NoFocus);
    //创建垂直布局对象
    vboxlayout=new QVBoxLayout(this);
    vboxlayout->addWidget(label);
     vboxlayout->addWidget(label1);
    vboxlayout->addWidget(label2);
    vboxlayout->addWidget(label3);
    vboxlayout->addWidget(returnbtn);
    vboxlayout->setAlignment(Qt::AlignCenter);//设置对齐方式

    //信号和槽的一个关联（用来做页面切换）
    this->connect(returnbtn,SIGNAL(clicked()),this,SLOT(returnbtnclick()));
}

void helpWidget::returnbtnclick()
{
    this->hide();
}
