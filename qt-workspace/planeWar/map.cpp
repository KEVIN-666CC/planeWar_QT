#include "map.h"
#include"config.h"
#include"startgame.h"
#include<QDebug>
map::map()
{
    //初始化加载地图对象
    StartGame *str;
    str=new StartGame();
    str->changeMap();
    m_map1.load(str->MapStyle);
    m_map2.load(str->MapStyle);


//    m_map1.load(Map_Path);
//    m_map2.load(Map_Path);

    //初始化Y轴坐标
    m_map1_posY=-GAME_Heigth;
    m_map2_posY=0;

    //地图滚动速度
    m_scroll_speed=Map_Scroll_Speed;
}


void map::mapPosition()
{
    //处理第一张图片滚动位置
    m_map1_posY+=m_scroll_speed;
    if(m_map1_posY>=0)
    {
        m_map1_posY=-GAME_Heigth;
    }
    //处理第二张图片滚动位置
    m_map2_posY+=m_scroll_speed;
    if(m_map2_posY>=GAME_Heigth)
    {
        m_map2_posY=0;
    }
}

