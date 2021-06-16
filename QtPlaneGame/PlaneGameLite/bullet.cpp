#include "bullet.h"

Bullet::Bullet()
{
    //加载子弹资源
    heroBullet.load(BULLET_PATH);
    //子弹坐标
    X = GAME_WIDTH*0.5 - heroBullet.width()*0.5;
    Y = GAME_HEIGHT;
    //子弹状态
    Free = true;
    //子弹速度
    Speed = BULLET_SPEED;
    //子弹矩形框
    Rect.setWidth(heroBullet.width());
    Rect.setHeight(heroBullet.height());
    Rect.moveTo(X,Y);
}

void Bullet::updatePosition()
{
    //如果子弹是空闲状态，不需要坐标计算
    //玩家飞机可以控制子弹的空闲状态为false
    if(Free)
    {
    return;
    }
    //子弹向上移动
    Y -= Speed;
    //子弹位置超出屏幕，变空闲状态
    Rect.moveTo(X,Y);
    if(Y <= -Rect.height())
    {
    Free = true;
    }
}
