#ifndef HEROPLANE_H
#define HEROPLANE_H
#include <QPixmap>
#include <QRect>
#include "config.h"
#include "bullet.h"
class HeroPlane
{
public:
    HeroPlane();
    //发射子弹
    void shoot();
    //设置飞机位置
    void setPosition(int x, int y);
    //飞机资源 对象
    QPixmap Plane;
    //飞机坐标
    int X;
    int Y;
    //飞机的矩形边框
    QRect Rect;
    //弹匣
    Bullet bullets[BULLET_NUM];
    //发射间隔记录
    int recorder;

};

#endif // HEROPLANE_H
