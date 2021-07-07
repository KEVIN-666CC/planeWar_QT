#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include "config.h"
#include "map.h"
#include <QIcon>
#include <QTimer>
#include <QPainter>
#include "heroplane.h"
#include <QMouseEvent>
#include "enemyplane.h"
#include "bomb.h"
#include "endgame.h"



class MainScene : public QWidget
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = nullptr);
    ~MainScene();
    void initScene();
    //启动游戏 用于启动定时器对象
    QTimer Timer;
   // 开始游戏
    void playGame();
    //更新游戏里所有元素的坐标
    void updatePosition();
    //绘图事件
    void paintEvent(QPaintEvent *event);
    //地图对象
    Map map;
    //飞机对象
    HeroPlane hero;
    //鼠标移动事件
    void mouseMoveEvent(QMouseEvent *event);
    //敌机出场
    void enemyToScene();
    //敌机数组
    EnemyPlane enemies[ENEMY_NUM];
    //敌机出场间隔记录
    int recorder;
    void collisionDetection();
    //爆炸数组
    Bomb bombs[BOMB_NUM];
    //游戏结束
   void endGame();
   //游戏分数改变
   void updateScore();
   QLabel *score;
   //分数
   int heroScore=0;
   //生命值
   int life=1;
};
#endif // MAINSCENE_H
