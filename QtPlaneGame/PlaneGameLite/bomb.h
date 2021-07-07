#ifndef BOMB_H
#define BOMB_H
#include "config.h"
#include <QPixmap>

class Bomb
{
public:
    Bomb();
    //更新信息（播放图片下标、播放间隔）
    void updateInfo();
    //放爆炸资源数组
    QVector<QPixmap> pixArr;
    //爆炸位置
    int X;
    int Y;
    //爆炸状态
    bool Free;
    //爆炸切图的时间间隔
    int Recoder;
    //爆炸时加载的图片下标
    int index;
};

#endif // BOMB_H
