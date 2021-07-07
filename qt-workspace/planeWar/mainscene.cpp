#include "mainscene.h"
#include<ctime>
#include<QSound>
#include<QApplication>
mainScene::mainScene(QWidget *parent)
    : QWidget(parent)
{

    InitScene();//初始化

    playGame();//开始

//    DickMenu *dick;
//    dick=new DickMenu;
    thread=new MyThread();
    connect(thread,&MyThread::isDone,[=]()
    {
        this->close();
    });


}

mainScene::~mainScene()
{
}

void mainScene::InitScene()
{
    //设置窗口固定
    setFixedSize(GAME_Width,GAME_Heigth);
    //设置标题
    setWindowTitle(GAME_Title);
    //设置窗口图标
    setWindowIcon(QIcon(GAME_ICON));

    //定时器
    m_timer.setInterval(GAME_Rate);

    enemy_recorder=0;//敌机出场时间间隔记录

    //随机数种子
    srand((unsigned int)time(NULL));
}

void mainScene::playGame()
{
    m_timer.start(); //启动定时器

    //背景音乐
    QSound::play("D:/qt/PlaneWar/res/bg.wav");

    //监听定时器发出信号
    connect(&m_timer,&QTimer::timeout,[=](){
        //敌机出场
        enemyToscreen();
            //更新坐标
            updatePosition();
            //刷新绘制到屏幕中)
            update();
            //碰撞检测
            collisionDetection();
    });

//    connect(this,&mainScene::stoptime,this,&mainScene::Done);
}

void mainScene::updatePosition()
{
    //更新地图坐标
    M_map.mapPosition();

    //发射子弹
    hero_plane.shoot();

    //计算所有非空闲子弹坐标
    for(int i=0;i<bullet_num;i++)
    {
        //如果非空闲 计算发射位置
        if(hero_plane.m_bullets[i].bullet_free==false)
        {
            hero_plane.m_bullets[i].updateBulletPosition();
        }
    }

    //敌机
    for(int i=0;i<ENEMY_NUM;i++)
    {
        if(m_enemies[i].enemy_free==false)
        {
            m_enemies[i].updateEnemyPosition();
        }
    }

    //计算爆炸的播放图片
    for(int i=0;i<Bomb_NUM;i++)
    {
        if(m_bombs[i].Bomb_free==false)
        {
            m_bombs[i].updateInfo();
        }
    }
}

void mainScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    //绘制地图
    painter.drawPixmap(0,M_map.m_map1_posY,M_map.m_map1);
    painter.drawPixmap(0,M_map.m_map2_posY,M_map.m_map2);

    //绘制飞机
    if(hero_plane.hero_free==false)
    {
        painter.drawPixmap(hero_plane.plane_x,hero_plane.plane_y,hero_plane.m_Plane);
    }



    //绘制子弹
    if(StartPaintBullet==true)
    {
        for(int i=0;i<bullet_num;i++)
        {
            //如果非空闲 绘制
            if(hero_plane.m_bullets[i].bullet_free==false)
            {
                painter.drawPixmap(hero_plane.m_bullets[i].bullet_x,hero_plane.m_bullets[i].bullet_y,
                                   hero_plane.m_bullets[i].m_bullet);
            }
        }
    }



    //绘制敌机
    for(int i=0;i<ENEMY_NUM;i++)
    {
        //如果非空闲 绘制
        if(m_enemies[i].enemy_free==false)
        {
            painter.drawPixmap(m_enemies[i].enemy_x,
                               m_enemies[i].enemy_y,
                               m_enemies[i].m_enemy);
        }
    }

    //绘制爆炸
    for(int i=0;i<Bomb_NUM;i++)
    {
        if(m_bombs[i].Bomb_free==false)
        {
            painter.drawPixmap(m_bombs[i].Bomb_x,m_bombs[i].Bomb_y,
                               m_bombs[i].m_pixArr[m_bombs[i].bombing_index]);
        }
    }

}

void mainScene::mouseMoveEvent(QMouseEvent *event) //鼠标拖拽 飞机随之移动
{
    int x=event->x()-hero_plane.plane_rect.width()*0.5;
    int y=event->y()-hero_plane.plane_rect.height()*0.5;

    //边界检测
    if(x<=0)
    {
        x=0;
    }
    if(x>GAME_Width-hero_plane.plane_rect.width())
    {
        x=GAME_Width-hero_plane.plane_rect.width();
    }
    if(y<=0)
    {
        y=0;
    }
    if(y>=GAME_Heigth-hero_plane.plane_rect.height())
    {
        y=GAME_Heigth-hero_plane.plane_rect.height();
    }
    hero_plane.setPlanePosition(x,y);
}

void mainScene::enemyToscreen()   //敌机出场
{
    enemy_recorder++;
    if(enemy_recorder<ENEMY_INTERVAL)
    {
        return;
    }
    enemy_recorder=0;
    for(int i=0;i<ENEMY_NUM;i++)
    {
        if(m_enemies[i].enemy_free)
        {
            m_enemies[i].enemy_free=false;

            //坐标
            m_enemies[i].enemy_x=rand()%(GAME_Width-m_enemies[i].enemy_rect.width());
            m_enemies[i].enemy_y=-m_enemies[i].enemy_rect.height();
            break;
        }
    }
}

void mainScene::collisionDetection()
{
    //遍历所有非空闲的敌机
    for(int i=0;i<ENEMY_NUM;i++)
    {
        if(m_enemies[i].enemy_free)
        {
            continue;//空闲飞机 跳转到下一次循环
        }

        if(hero_plane.plane_rect.intersects(m_enemies[i].enemy_rect))//本方飞机爆炸
        {
            hero_plane.hero_free=true;
            StartPaintBullet=false;  //不绘制子弹
            StartCheckEnemy=false;  //不检测子弹与敌机碰撞
            hero_plane.plane_rect.setHeight(0);
            hero_plane.plane_rect.setWidth(0);
            for(int k=0;k<Bomb_NUM;k++)
            {
                if(m_bombs[k].Bomb_free)
                {
                    //QSound::play(Sound_bomb); //爆炸音效

                    //空闲的爆炸 可以播放爆炸了
                    m_bombs[k].Bomb_free=false;
                    //更新爆炸坐标
                    m_bombs[k].Bomb_x=hero_plane.plane_x;
                    m_bombs[k].Bomb_y=hero_plane.plane_y;

                    //emit stoptime();
                    break;
                }
            }
            thread->start();

        }


        if(StartCheckEnemy==true)
        {
            for(int j=0;j<bullet_num;j++) //遍历子弹
            {
                if(hero_plane.m_bullets[j].bullet_free)
                {
                    continue;
                }

                //如果子弹框和敌机框相交
                if(m_enemies[i].enemy_rect.intersects(hero_plane.m_bullets[j].bullet_rect))
                {
                    m_enemies[i].enemy_free=true;
                    hero_plane.m_bullets[j].bullet_free=true;

                    //爆炸效果播放
                    for(int k=0;k<Bomb_NUM;k++)
                    {
                        if(m_bombs[k].Bomb_free)
                        {
                            //QSound::play(Sound_bomb); //爆炸音效

                            //空闲的爆炸 可以播放爆炸了
                            m_bombs[k].Bomb_free=false;
                            //更新爆炸坐标
                            m_bombs[k].Bomb_x=m_enemies[i].enemy_x;
                            m_bombs[k].Bomb_y=m_enemies[i].enemy_y;
                            break;
                        }
                    }
                }
            }
        }
    }
}

//void mainScene::Done()
//{
//    QMessageBox::information(this,"defeat","游戏失败");
//    exit(0);
//}


//void mainScene::keyPressEvent(QKeyEvent *event)
//{
//    setFocusPolicy(Qt::StrongFocus);
//    installEventFilter(this);


//    if(event->type()==QEvent::KeyPress)
//    {
//        QKeyEvent *keyEvent=static_cast<QKeyEvent*>(event);
//        if(keyEvent->key()==Qt::Key_Space)
//        {
//            qDebug()<<1;
//            this->m_mutex.lock();
//            return;
//        }
//        if(keyEvent->key()==Qt::Key_0)
//        {
//            qDebug()<<0;
//            this->m_mutex.unlock();
//            return;
//        }
//    }
//}
