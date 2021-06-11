#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include"config.h"
#include<QIcon>
#include<QTimer>
#include<QPaintEvent>
#include"map.h"
#include<QPainter>
#include"heroplane.h"
#include<QMouseEvent>
#include"bullet.h"
#include"enemyplane.h"
#include"bomb.h"
#include<QMessageBox>
#include<QMutex>  //暂停
#include<QThread>
#include"mythread.h"
#include"dickmenu.h"
#include<QDebug>

class mainScene : public QWidget
{
    Q_OBJECT

public:
    mainScene(QWidget *parent = nullptr);
    ~mainScene();
    void InitScene();

    QMutex m_mutex; //互斥量

    QTimer m_timer;

    bool StartPaintBullet=true; //是否绘制子弹 本机撞毁后
    bool StartCheckEnemy=true; //是否检测子弹与敌机碰撞 本机撞毁后

    //启动游戏
    void playGame();

    //更新游戏坐标
    void updatePosition();

    //绘制到屏幕中  函数名不可更改
    void paintEvent(QPaintEvent *);

    //地图对象
    map M_map;

    //飞机对象
    HeroPlane hero_plane;

    //重写鼠标移动事件  函数名不可更改
    void mouseMoveEvent(QMouseEvent *);

    //捕捉键盘事件
    //void keyPressEvent(QKeyEvent *event);

    //敌机出场
    void enemyToscreen();
    //敌机数组
    EnemyPlane m_enemyplanes[7];

    EnemyPlane m_enemies[ENEMY_NUM];
    int enemy_recorder;

    //碰撞检测
    void collisionDetection();

    //爆炸数组
    Bomb m_bombs[Bomb_NUM];

    MyThread *thread;


//    void Done();
signals:
    void ReturnMenu();

};
#endif // MAINSCENE_H
