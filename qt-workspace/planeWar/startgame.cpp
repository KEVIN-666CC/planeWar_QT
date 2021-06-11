#include "startgame.h"
#include "ui_startgame.h"
#include"QDebug"

static int  Map=1;  //静态全局变量 程序退出前一直保持最新值

StartGame::StartGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartGame)
{
    ui->setupUi(this);
    this->setWindowTitle("飞机大战");
    //ui->pushButtonStart->setStyleSheet("font-size:15px;color:rgb(0,255,0,255)");

    ui->stackedWidget->setCurrentWidget(ui->pageStart);
    ui->spinBox->setMaximum(5);
    ui->spinBox->setValue(5);


//    mainScene *m;

//    //m=new mainScene();

//    connect(m,&mainScene::ReturnMenu,[=]()
//    {
//        this->show();
//        m->close();
//    });
}

StartGame::~StartGame()
{
    delete ui;

}

void StartGame::on_pushButtonStart_clicked()
{
    this->close();
    mainScene *m;
    m=new mainScene();
    m->show();
}



    // 下列方法会导致窗口一闪而过mainScene创建在stack上，生命期是大括号内
    //    mainScene *m;
    //  m=new mainScene();
    // mainScene 通过new创建在heap上， 在程序退出时才会被析构

//    this->hide();
//    mainScene m;
//    m->show();

void StartGame::on_pushButtonStart_Design_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_2);
}

void StartGame::on_pushButtonStart_Exit_clicked()
{
    exit(0);
}

void StartGame::on_pushButtonSureDeSign_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pageStart);
    Map=ui->spinBox->text().toInt();   //Map的值为spinBox的当前值并保持不变直到下次在此页面修改spinBox的值并确定

    //MapStyle=QString(":/res/img_bg_level_%1.jpg").arg(Map);
}

void StartGame::changeMap()
{
    MapStyle=QString(":/res/img_bg_level_%1.jpg").arg(Map);
}
