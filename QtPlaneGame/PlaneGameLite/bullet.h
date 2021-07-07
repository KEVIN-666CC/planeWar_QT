#ifndef BULLET_H
#define BULLET_H
#include "config.h"
#include <QPixmap>

class Bullet
{
public:
    Bullet();
    //更新子弹坐标
    void updatePosition();
    //子弹资源对象
    QPixmap heroBullet;
    //子弹坐标
    int X;
    int Y;
    //子弹移动速度
    int Speed;
    //子弹是否闲置
    bool Free;
    //子弹的矩形边框
    QRect Rect;
};

#endif // BULLET_H
