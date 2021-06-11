#include "heroplane.h"
#include"config.h"
#include"map.h"

HeroPlane::HeroPlane()
{
    m_Plane.load(Plane_Model);//设置飞机模型

    //初始化飞机坐标
    plane_x=(GAME_Width-m_Plane.width())*0.5;
    plane_y=GAME_Heigth-m_Plane.height();

    //初始化矩形边框
    plane_rect.setWidth(m_Plane.width());
    plane_rect.setHeight(m_Plane.height());

    plane_rect.moveTo(plane_x,plane_y);

    hero_free=false;

    m_recorder=0;
}

void HeroPlane::shoot()
{
    //累加时间间隔记录变量
    m_recorder++;
    //如果记录的数字未达到子弹发射的间隔
    if(m_recorder<bullet_interval)
    {
        return;//不发射
    }
    m_recorder=0;
    //发射子弹
    for(int i=0;i<bullet_num;i++)
    {
        //如果子弹空闲 则发射
        if(m_bullets[i].bullet_free)
        {
            //将空闲状态改为假
            m_bullets[i].bullet_free=false;
            //设置子弹坐标
            m_bullets[i].bullet_x=plane_x+plane_rect.width()*0.5-10;
            m_bullets[i].bullet_y=plane_y-25;
            break;
        }
    }
}

void HeroPlane::setPlanePosition(int x, int y)
{
    plane_x=x;
    plane_y=y;
    plane_rect.moveTo(plane_x,plane_y);
}
