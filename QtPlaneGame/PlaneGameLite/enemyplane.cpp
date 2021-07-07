#include "enemyplane.h"

EnemyPlane::EnemyPlane()
{
    //敌机资源加载
    enemy.load(ENEMY_PATH);
    //敌机位置
    X = 0;
    Y = 0;
    //敌机状态
    Free = true;
    //敌机速度
    Speed = ENEMY_SPEED;
    //敌机矩形
    Rect.setWidth(enemy.width());
    Rect.setHeight(enemy.height());
    Rect.moveTo(X,Y);

}

void EnemyPlane::updatePosition()
{
    //空闲状态，不计算坐标
    if(Free)
    {
    return;
    }
    Y += Speed;
    Rect.moveTo(X,Y);
    if(Y >= GAME_HEIGHT)
    {
    Free = true;
    }
}
