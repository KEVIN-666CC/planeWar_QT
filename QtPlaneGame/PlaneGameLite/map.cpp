#include "map.h"
#include "config.h"


Map::Map()
{
    //初始化加载地图对象
    map1.load(MAP_PATH);
    map2.load(MAP_PATH);
    //设置地图y轴坐标
    map1_posY = -GAME_HEIGHT;
    map2_posY = 0;
    //设置地图滚动速度
    scroll_speed = MAP_SCROLL_SPEED;
}

void Map::mapPosition()
{
    //处理第一张图片滚动
    map1_posY += MAP_SCROLL_SPEED;
    if(map1_posY >= 0)
    {
    map1_posY =-GAME_HEIGHT;
    }
    //处理第二张图片滚动
    map2_posY += MAP_SCROLL_SPEED;
    if(map2_posY >= GAME_HEIGHT )
    {
    map2_posY =0;
    }
}
