#ifndef ENEMYPLANE_H
#define ENEMYPLANE_H
#include <QPixmap>
#include"config.h"

class EnemyPlane
{
public:
    EnemyPlane();
    //更新坐标
    void updatePosition();
    //敌机资源对象
    QPixmap enemy;
    //位置
    int X;
    int Y;
    //敌机的矩形边框（碰撞检测）
    QRect Rect;
    //状态
    bool Free;
    //速度
    int Speed;

};

#endif // ENEMYPLANE_H
