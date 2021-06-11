#include "bomb.h"
#include<QDebug>
Bomb::Bomb()
{
    //将所有爆炸pixmap放入数组中
    for(int i=1;i<=Bomb_max;i++)
    {
        QString str=QString(Bomb_model).arg(i);
        m_pixArr.push_back(QPixmap(str));
    }

    //坐标
    Bomb_x=0;
    Bomb_y=0;

    Bomb_free=true;
    bombing_index=0;
    Bomb_recorder=0;
}

void Bomb::updateInfo()
{
    //空闲状态下的爆炸效果直接return
    if(Bomb_free)
    {
        return;
    }
    Bomb_recorder++;
    if(Bomb_recorder<Bomb_Interval)
    {
        return;
    }
    Bomb_recorder=0;

    bombing_index++;//切换爆炸显示图片下标
    if(bombing_index>Bomb_max-1)//数组下标从0开始计算
    {
        bombing_index=0;
        Bomb_free=true;
    }
}
