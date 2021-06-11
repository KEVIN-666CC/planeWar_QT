#ifndef BULLET_H
#define BULLET_H
#include"config.h"
#include<QPixmap>


class bullet
{
public:
    bullet();

    //更新子弹坐标
    void updateBulletPosition();

    //子弹资源对象
    QPixmap m_bullet;
    //子弹坐标
    int bullet_x;
    int bullet_y;

    //子弹移动速度
    int bullet_speed;

    //子弹是否闲置
    bool bullet_free;

    //子弹矩形边框
    QRect bullet_rect;


};

#endif // BULLET_H

