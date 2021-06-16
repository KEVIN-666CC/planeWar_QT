#include "mainscene.h"
#include <ctime>
#include <QSound>
//#include <iostream>
//#include <QMediaPlayer>
//#include <QMediaPlaylist>
using namespace std;

MainScene::MainScene(QWidget *parent)
    : QWidget(parent)
{
    //初始化场景
    initScene();
    playGame();
}

MainScene::~MainScene()
{
}

void MainScene::initScene()
{
    setAttribute(Qt::WA_DeleteOnClose,true);//当窗口关闭时，销毁窗口对象，释放内存
    //初始化窗口大小
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);
    //设置窗口标题
    setWindowTitle(GAME_TITLE);
    //设置图标资源
    setWindowIcon(QIcon( GAME_ICON));
    //显示分数的标签
    setAutoFillBackground(true);
    this->score = new QLabel("分数: ",this);
    score->setText(QString("分数:%1  ").arg(heroScore));
    score->setStyleSheet("QLabel{background:transparent;color:white;}");
    //定时器设置
    Timer.setInterval(GAME_RATE);
    //初始化间隔记录属性
    recorder = 0;
    //随机数种子
    srand((unsigned int)time(NULL));

}
void MainScene::playGame()
{
    //启动定时器
    Timer.start();
    //监听定时器
    connect(&Timer,&QTimer::timeout,[=]()
    {
    //敌机出场
    enemyToScene();
    //更新游戏中所有元素的坐标
    updatePosition();

    collisionDetection();
    endGame();
    //重新绘制图片
    update();
    }
    );
}
void MainScene::updatePosition()
{
    //更新地图坐标
    map.mapPosition();
    //发射子弹
    hero.shoot();
    //计算子弹坐标
    for(int i = 0 ;i < BULLET_NUM;i++)
    {
    //如果子弹状态为非空闲，计算发射位置
        if(hero.bullets[i].Free==false)
        {
            hero.bullets[i].updatePosition();
        }
}
    //敌机坐标计算
    for(int i = 0 ; i< ENEMY_NUM;i++)
    {
        //非空闲敌机 更新坐标
        if(enemies[i].Free == false)
        {
            enemies[i].updatePosition();
        }
    }
    //计算爆炸播放的图片
    for(int i = 0 ; i < BOMB_NUM;i++)
    {
        if(bombs[i].Free == false)
        {
            bombs[i].updateInfo();
        }
    }
    }
    void MainScene::paintEvent(QPaintEvent *event)
    {
        QPainter painter(this);
        //绘制地图
        painter.drawPixmap(0,map.map1_posY , map.map1);
        painter.drawPixmap(0,map.map2_posY , map.map2);
        //绘制英雄
        painter.drawPixmap(hero.X,hero.Y,hero.Plane);
        //绘制子弹
        for(int i = 0 ;i < BULLET_NUM;i++)
        {
            //如果子弹状态为非空闲，计算发射位置
            if(hero.bullets[i].Free==false)
            {
                painter.drawPixmap(hero.bullets[i].X,hero.bullets[i].Y,hero.bullets[i].heroBullet);
            }
        }
        //绘制敌机
        for(int i = 0 ; i< ENEMY_NUM;i++)
        {
            if(enemies[i].Free == false)
            {
                painter.drawPixmap(enemies[i].X,enemies[i].Y,enemies[i].enemy);
            }
        }
        //绘制爆炸图片
        for(int i = 0 ; i < BOMB_NUM;i++)
        {
            if(bombs[i].Free == false)
            {
                painter.drawPixmap(bombs[i].X,bombs[i].Y,bombs[i].pixArr[bombs[i].index]);
            }
        }
    }

void MainScene::mouseMoveEvent(QMouseEvent *event)
{
    int x = event->x() - hero.Rect.width()*0.5; //鼠标位置 - 飞机矩形的一半
    int y = event->y() - hero.Rect.height()*0.5;
    //边界检测
    if(x <= 0 )
    {
    x = 0;
    }
    if(x >= GAME_WIDTH - hero.Rect.width())
    {
    x = GAME_WIDTH - hero.Rect.width();
    }
    if(y <= 0)
    {
    y = 0;
    }
    if(y >= GAME_HEIGHT - hero.Rect.height())
    {
    y = GAME_HEIGHT - hero.Rect.height();
    }
    hero.setPosition(x,y);
}

void MainScene::enemyToScene()
{
    recorder++;
    if(recorder < ENEMY_INTERVAL)
    {
    return;
    }
    recorder = 0;
    for(int i = 0 ; i< ENEMY_NUM;i++)
    {
    if(enemies[i].Free)
    {
    //敌机空闲状态改为false
    enemies[i].Free = false;
    //设置坐标
    enemies[i].X = rand() % (GAME_WIDTH - enemies[i].Rect.width());
    enemies[i].Y = -enemies[i].Rect.height();
    break;
    }
    }

}

void MainScene::collisionDetection()//碰撞检测
{
    //遍历所有非空闲的敌机
    for(int i = 0 ;i < ENEMY_NUM;i++)
    {
    if(enemies[i].Free)
    {
    //空闲飞机 跳转下一次循环
    continue;
    }
    if(hero.Rect.intersects((enemies[i].Rect)))//hero飞机爆炸
    {
        updateScore();
        for(int k = 0 ; k < BOMB_NUM;k++)
        {
        if(bombs[k].Free)
        {
        //爆炸状态设置为非空闲
        bombs[k].Free = false;
        //更新坐标
        bombs[k].X = hero.X;
        bombs[k].Y = hero.Y;
        break;
        }
        }
        life--;
    }

    //遍历所有 非空闲的子弹
    for(int j = 0 ; j < BULLET_NUM;j++)
    {
    if(hero.bullets[j].Free)
    {
    //空闲子弹 跳转下一次循环
    continue;
    }
    //如果子弹矩形框和敌机矩形框相交，发生碰撞，同时变为空闲状态即可
    if(enemies[i].Rect.intersects(hero.bullets[j].Rect))
    {
    enemies[i].Free = true;
    hero.bullets[j].Free = true;
    updateScore();
    //heroScore +=1;
    //播放爆炸效果
    for(int k = 0 ; k < BOMB_NUM;k++)
    {
    if(bombs[k].Free)
    {
    //播放音效
     QSound::play(SOUND_BOMB);
    //爆炸状态设置为非空闲
    bombs[k].Free = false;
    //更新坐标
    bombs[k].X = enemies[i].X;
    bombs[k].Y = enemies[i].Y;
    break;
    }
    }
    }
    }
    }
}

void MainScene::endGame()
{
    if(life==0)
    {
        EndGame *e= new EndGame();
        if( QMessageBox::Ok==QMessageBox::information(this,"你输了",QString("得分:%1  ").arg(heroScore),QMessageBox::Ok)){
        e->show();
        this->close();
        }
    }
}

void MainScene::updateScore()
{
    heroScore++;
    score->setText(QString("分数:%1").arg(heroScore));
}

