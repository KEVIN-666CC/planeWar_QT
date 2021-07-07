#include "bullet.h"
#include<QDebug>

bullet::bullet()
{

    //加载资源
    m_bullet.load(bullet_model);

    //子弹坐标
    bullet_x=(GAME_Width-m_bullet.width())*0.5;
    bullet_y=GAME_Heigth;

    //子弹状态
    bullet_free=true;
    //子弹速度
    bullet_speed=BULLET_SPEED;
    //子弹矩形边框
    bullet_rect.setWidth(m_bullet.width());
    bullet_rect.setHeight(m_bullet.height());
    bullet_rect.moveTo(bullet_x,bullet_y);

}

void bullet::updateBulletPosition()
{

    //空闲状态下的子弹无需计算坐标
    if(bullet_free)
    {
        return;
    }
    bullet_y-=bullet_speed;//子弹向上移动
    bullet_rect.moveTo(bullet_x,bullet_y);

    if(bullet_y<=0)//子弹位置超出屏幕状态为为空闲
    {
        bullet_free=true;
    }

}

