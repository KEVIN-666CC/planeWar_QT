#ifndef HEROPLANE_H
#define HEROPLANE_H
#include<QPixmap>
#include<QRect>
#include"bullet.h"

class HeroPlane
{
public:
    HeroPlane();

    //发射子弹
    void shoot();

    //设置飞机位置
    void setPlanePosition(int x,int y);

    bool hero_free;


    //飞机资源 对象
    QPixmap m_Plane;

    //飞机坐标
    int plane_x;
    int plane_y;

    //飞机矩形边框
    QRect plane_rect;

    bullet m_bullets[bullet_num];//弹夹
    int m_recorder; //发射间隔记录
};

#endif // HEROPLANE_H

