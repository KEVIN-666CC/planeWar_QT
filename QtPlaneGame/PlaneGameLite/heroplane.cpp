#include "heroplane.h"

HeroPlane::HeroPlane()
{
    //初始化加载飞机图片资源
    Plane.load(HERO_PATH);
    //初始化坐标
    X = GAME_WIDTH * 0.5 - Plane.width()*0.5;
    Y = GAME_HEIGHT - Plane.height();
    //初始化矩形框
    Rect.setWidth(Plane.width());
    Rect.setHeight(Plane.height());
    Rect.moveTo(X,Y);
    //初始化发射间隔记录
    recorder = 0;

}

void HeroPlane::shoot()
{
    //累加时间间隔记录变量
    recorder++;
    //判断如果记录数字 未达到发射间隔，直接return
    if(recorder < BULLET_INTERVAL)
    {
    return;
    }
    //到达发射时间处理
    //重置发射时间间隔记录
    recorder = 0;
    //发射子弹
    for(int i = 0 ; i < BULLET_NUM;i++)
    {
    //如果是空闲的子弹进行发射
    if(bullets[i].Free)
    {
    //将改子弹空闲状态改为假
    bullets[i].Free = false;
    //设置发射的子弹坐标
    bullets[i].X = X + Rect.width()*0.5 - 10;
    bullets[i].Y = Y - 25 ;
    break;
    }
    }
}

void HeroPlane::setPosition(int x, int y)
{
    X = x;
    Y = y;
    Rect.moveTo(X,Y);
}
